#######################################################################
# Begin perl code
#######################################################################
#
# MEX builds MEX-files.
#
# Copyright (c) 1996-2000 The MathWorks, Inc. All Rights Reserved.
# $Revision: 1.140 $  $Date: 2000/08/29 18:32:21 $
#
#   Functional overview:
#   1. Define subroutines
#   2. Initialize variables
#   3. Parse input arguments & determine MEX-file name
#   4. Source options file
#   5. Determine final values
#   6. Compile source files
#   7. Perform prelink tasks
#   8. Link files
#
# Globals used: $main::mbuild => {"yes", "no"} is the mbuild or mex?
#               $main::script_directory => string with $MATLAB\bin in it
#               $main::cmd_name => {"MBUILD.BAT", "MEX.BAT"}
#               $main::no_execute => {0, 1} RunCmd execute command? (used by -n switch)
#######################################################################
# Set the Perl path and $cmd_name variable
#######################################################################

#use strict; # big time nostrict

#######################################################################
# Set @INC for 5.00503 perl.
# If perl gets upgraded, this may have to be changed.
#######################################################################
BEGIN {
    if ( $] < 5.00503 ) {
	die "ERROR: This script requires perl 5.00503 or higher.
You have perl $] installed on your machine and you did not set MATLAB variable,
so the correct version of perl could not be found";
    }
    if ( ! $ENV{"MATLAB"} ) {
	my($f) = $0;
	$f =~ s%[\\/][\w\.]+[\\/]\.\.[\\/]%\\%g;
	$f =~ s%^[^\.][^\\/]+[\\/]\.\.[\\/]%%g;
	# print "$0 -> $f ";
	$0 = $f;
	if ($f =~ s%^bin[\\/]win32[\\/].*%% ) {
	    $f = '.';
	} elsif ($f =~ s%[\\/]bin[\\/]win32[\\/].*%% ) {
	    # fine
	} else {
	    $f .= "\\..\\..\\..";
	    $f =~ s%\\[^\.][^\\]+\\\.\.\\%\\%g;
	    $f =~ s%^[^\.][^\\]+\\\.\.\\%%g;
	}
	# print "-> $f\n";
	$ENV{'MATLAB'} = $f;
    }
    if ( $ENV{'MATLAB'} ) {
	unshift (@INC, map { "$ENV{MATLAB}/sys/perl/win32/$_" }
		 ("lib", "site/lib"));
        push(@INC, "$ENV{MATLAB}/bin/win32");
    } else {
	warn "WARNING: MATLAB variable is not set.";
    }
}

use Cwd;
use mexsetup;
use getprofiledir;
use File::DosGlob 'glob';
require "shellwords.pl";

if ( $ENV{'MATLAB'} =~ /^\.\\?$/ ) {
    ($ENV{'MATLAB'} = getcwd()) =~ s%/%\\%g;
}

#######################################################################
# Define subroutines
#######################################################################

# smart_quote adds quotes (") at the beginning and end of  its input
# if the input contains a space. The quoted string is returned as the
# output. If the input contains no spaces, the input is returned as the
# output.
sub smart_quote
{
    my ($str) = @_;	# input

    $str = "\"$str\"" if ($str =~ / /);
    $str;		# output
} # smart_quote

sub describe {
# Describe:  Issues messages.  This way lengthy messages do not clutter
#            up the main body of code.
    local($_) = $_[0];
 DESCRIPTION: {
     /^help$/ && print(<<'end_help') && last DESCRIPTION;
MEX [option1 ... optionN] sourcefile1 [... sourcefileN]
    [objectfile1 ... objectfileN] [libraryfile1 ... libraryfileN]

Description:
  MEX compiles and links source files into a shared library called a
  MEX-file, executable from within MATLAB. The resulting file has a
  platform-dependent extension, as shown in the table below:

    sol2, SunOS 5.x - .mexsol
    hpux            - .mexhpux
    hp700           - .mexhp7
    ibm_rs          - .mexrs6
    sgi             - .mexsg
    alpha           - .mexaxp
    glnx86          - .mexglx
    Windows         - .dll

  The first file name given (less any file name extension) will be the name
  of the resulting MEX-file. Additional source, object, or library files can
  be given to satisfy external references. On Windows, either C or Fortran,
  but not both, may be specified. On UNIX, both C and Fortran source files
  can be specified when building a MEX-file. If C and Fortran are mixed, the
  first source file given determines the entry point exported from the
  MEX-file (MATLAB loads and runs a different entry point symbol for C or
  Fortran MEX-files).

  Both an options file and command line options affect the behavior of MEX.
  The options file contains a list of variables that are passed as arguments
  to various tools such as the compiler, linker, and other platform-
  dependent tools (such as the resource linker on Windows). Command line
  options to MEX may also affect what arguments are passed to these tools,
  or may control other aspects of MEX's behavior.

Command Line Options:
  Options available on all platforms:

  -ada <sfcn.ads>
      Use this option to compile a Simulink S-function written in Ada, where
      <sfcn.ads> is the Package Specification for the S-function. When this
      option is specified, only the -v (verbose) and -g (debug) options are
      relevant. All other options are ignored. See
      $MATLAB/simulink/ada/examples/README for examples and info on
      supported compilers and other requirements.
  -argcheck
      Add argument checking. This adds code so that arguments passed
      incorrectly to MATLAB API functions will cause assertion failures.
      Adds -DARGCHECK to the C compiler flags, and adds
      $MATLAB/extern/src/mwdebug.c to the list of source files. (C functions
      only).
  -c
      Compile only. Creates an object file but not a MEX-file.
  -D<name>
      Define a symbol name to the C preprocessor. Equivalent to a
      "#define <name>" directive in the source.
  -D<name>#<value>
      Define a symbol name and value to the C preprocessor. Equivalent to a
      "#define <name> <value>" directive in the source.
  -f <optionsfile>
      Specify location and name of options file to use. Overrides MEX's
      default options file search mechanism.
  -g
      Create a debuggable MEX-file. If this option is specified, MEX appends
      the value of options file variables ending in DEBUGFLAGS with their
      corresponding base variable. (For example, the value of LINKDEBUGFLAGS
      would be appended to the LINKFLAGS variable before calling the
      linker.) This option also disables MEX's default behavior of
      optimizing built object code.
  -h[elp]
      Print this message.
  -I<pathname>
      Add <pathname> to the list of directories to search for #include
      files.
  -inline
      Inline matrix accessor functions (mx*). The MEX-function generated
      may not be compatible with future versions of MATLAB.
  -n
      No execute mode. Print out any commands that MEX would otherwise have
      executed, but do not actually execute any of them.
  -O
      Optimize the object code by including the optimization flags listed in
      the options file. If this option is specified, MEX appends the value
      of options file variables ending in OPTIMFLAGS with their
      corresponding base variable. (For example, the value of LINKOPTIMFLAGS
      would be appended to the LINKFLAGS variable before calling the
      linker.) Note that optimizations are enabled by default, are disabled
      by the -g option, but are reenabled by -O.
  -outdir <dirname>
      Place all output files in directory <dirname>.
  -output <resultname>
      Create MEX-file named <resultname> (an appropriate MEX-file extension
      is automatically appended). Overrides MEX's default MEX-file naming
      mechanism.
  -setup
      Interactively specify the compiler options file to use as default for
      future invocations of MEX by placing it in "<UserProfile>\Application
      Data\MathWorks\MATLAB\R12" (for Windows) or $HOME/.matlab/R12 (for
      UNIX). When this option is specified, no other command line input is
      accepted.
  -U<name>
      Remove any initial definition of the C preprocessor symbol <name>.
      (Inverse of the -D option.)
  -v
      Print the values for important internal variables after the options
      file is processed and all command line arguments are considered.
      Prints each compile step and final link step fully evaluated to see
      which options and files were used. Very useful for debugging.
  -V4
      Compile a MATLAB 4-style MEX-file. This option is intended as an aid
      to migration, and is not recommended as a permanent solution.
  <name>#<value>
      Override an options file variable for variable <name>. See the
      platform-dependent discussion of options files below for more details.
      This option is processed after the options file is processed and all
      command line arguments are considered.

Additional options available on Windows platforms:

  @<rspfile>
      Include contents of the text file <rspfile> as command line arguments
      to MEX.

Additional options available on Unix platforms:

  -<arch>
      Assume local host has architecture <arch>. Possible values for <arch>
      include sol2, hpux, hp700, alpha, ibm_rs, sgi, and glnx86.
  -D<name>=<value>
      Define a symbol name and value to the C preprocessor. Equivalent to a
      "#define <name> <value>" directive in the source.
  -fortran
      Specify that the gateway routine is in Fortran. This will override
      what the script normally assumes, which is that the first source file
      in the list is the gateway routine.
  -l<name>
      Link with object library "lib<name>" (for "ld(1)").
  -L<directory>
      Add <directory> to the list of directories containing object-library
      routines (for linking using "ld(1)").
  <name>=<value>
      Override an options file variable for variable <name>. See the
      platform-dependent discussion of options files below for more details.

Options File Details:
  On Windows:
    The options file is written as a DOS batch file. If the -f option is not
    used to specify the options file name and location, then MEX searches
    for an options file named mexopts.bat in the following directories: the
    current directory, then the directory "<UserProfile>\Application
    Data\MathWorks\MATLAB\R12". Any variable specified in the options file
    can be overridden at the command line by use of the <name>#<value>
    command line argument. If <value> has spaces in it, then it should be
    wrapped in double quotes (e.g., COMPFLAGS#"opt1 opt2"). The definition
    can rely on other variables defined in the options file; in this case
    the variable referenced should have a prepended "$" (e.g.,
    COMPFLAGS#"$COMPFLAGS opt2").

    Note: The options files in $MATLAB\bin\mexopts named *engmatopts.bat are
    special case options files that can be used with MEX (via the -f option)
    to generate stand-alone MATLAB Engine and MATLAB MAT-API executables.
    Such executables are given a ".exe" extension.

  On UNIX:
    The options file is written as a UNIX shell script. If the -f option is
    not used to specify the options file name and location, then MEX
    searches for an options file named mexopts.sh in the following
    directories: the current directory (.), then $HOME/.matlab/R12, then
    $MATLAB/bin. Any variable specified in the options file can be
    overridden at the command line by use of the <name>=<def> command line
    argument. If <def> has spaces in it, then it should be wrapped in single
    quotes (e.g., CFLAGS='opt1 opt2'). The definition can rely on other
    variables defined in the options file; in this case the variable
    referenced should have a prepended "$" (e.g., CFLAGS='$CFLAGS opt2').

    Note: The options files in $MATLAB/bin named engopts.sh and matopts.sh
    are special case options files that can be used with MEX (via the -f
    option) to generate stand-alone MATLAB Engine and MATLAB MAT-API
    executables. Such executables are not given any default extension.

Examples:
    The following command will compile "myprog.c" into "myprog.mexsol" (when
    run under Solaris):

      mex myprog.c

    When debugging, it is often useful to use "verbose" mode as well
    as include symbolic debugging information:

      mex -v -g myprog.c

end_help
     /^usage$/ && print(<<'end_usage') && last DESCRIPTION;
    Usage:
        MEX [option1 ... optionN] sourcefile1 [... sourcefileN]
            [objectfile1 ... objectfileN] [libraryfile1 ... libraryfileN]

      or (to build an Ada S-function):
        MEX [-v] [-g] -ada <sfcn>.ads

    Use the -help option for more information, or consult the MATLAB API Guide.

end_usage
     /^general_info$/ && print(<<"end_general_info") && last DESCRIPTION;
 This is mex, (c) 1996 - 2000 The MathWorks, Inc.

end_general_info
     /^invalid_options_file$/ && print(<<"end_invalid_options_file") && last DESCRIPTION;
    Warning: An options file for MEX.BAT was found and sourced, but the
             value for 'COMPILER' was not set.  This could mean that the
             value is not specified within the options file, or it could
             mean that there is a syntax error within the file.

end_invalid_options_file
     /^final_options$/ && print(<<"end_final_options") && last DESCRIPTION;
$sourced_msg
----------------------------------------------------------------
->    Options file           = $OPTFILE_NAME
      MATLAB                 = $MATLAB
->    COMPILER               = $COMPILER
->    Compiler flags:
         COMPFLAGS           = $COMPFLAGS
         OPTIMFLAGS          = $OPTIMFLAGS
         DEBUGFLAGS          = $DEBUGFLAGS
         arguments           = $ARG_FLAGS
         Name switch         = $NAME_OBJECT
->    Pre-linking commands   = $PRELINK_CMDS
->    LINKER                 = $LINKER
->    Link directives:
         LINKFLAGS           = $LINKFLAGS
         Name directive      = $NAME_OUTPUT
         File link directive = $LINK_FILE
         Lib. link directive = $LINK_LIB
         Rsp file indicator  = $RSP_FILE_INDICATOR
->    Resource Compiler      = $RC_COMPILER
->    Resource Linker        = $RC_LINKER
----------------------------------------------------------------

end_final_options
     /^file_not_found$/ && print(<<"end_file_not_found") && last DESCRIPTION;
  $main::cmd_name:  $filename not a normal file or does not exist.

end_file_not_found
     /^meaningless_output_flag$/ && print(<<"end_meaningless_output_flag")  && last DESCRIPTION;
  Warning: -output ignored (no MEX-file is being created).

end_meaningless_output_flag

    /^compiler_not_found$/ && print(<<"end_compiler_not_found") && last DESCRIPTION;
  Could not find the compiler "$COMPILER" on the DOS path.
  Use mex -setup to configure your environment properly.

end_compiler_not_found

    /^outdir_missing_name_object$/ && print(<<"end_outdir_missing_name_object") && last DESCRIPTION;
  Warning: The -outdir switch requires the mex options file to define
           NAME_OBJECT. Make sure you are using the latest version of
           your compiler's mexopts file.

end_outdir_missing_name_object

    /^fortran_cannot_change_entrypt$/ && print(<<"end_fortran_cannot_change_entrypt") && last DESCRIPTION;
  Warning: -entrypt ignored (FORTRAN entry point cannot be overridden).

end_fortran_cannot_change_entrypt

    do {
        print "Internal error: Description for $_[0] not implemented\n";
        last DESCRIPTION;
    };
 }
}

sub describe_mb {
# Describe:  Issues messages.  This way lengthy messages do not clutter
#            up the main body of code.
    local($_) = $_[0];
 DESCRIPTION: {
     /^help$/ && print(<<'end_help_mb') && last DESCRIPTION;
MBUILD [option1 ... optionN] sourcefile1 [... sourcefileN]
       [objectfile1 ... objectfileN] [libraryfile1 ... libraryfileN]
       [exportfile1 ... exportfileN]

Description:
  MBUILD compiles and links source files that call functions in the MATLAB
  C/C++ Math Library or MATLAB C/C++ Graphics Library into a stand-alone
  executable or shared library.

  The first file name given (less any file name extension) will be the name
  of the resulting executable. Additional source, object, or library files
  can be given to satisfy external references. Either C or C++ source files
  can be specified when building executables. In addition, both C and C++
  source files can be specified at the same time as long as the C files are
  C++ compatible, and the -lang cpp option is specified (see -lang below).

  Both an options file and command line options affect the behavior of
  MBUILD. The options file contains a list of variables that are passed as
  arguments to various tools such as the compiler, linker, and other
  platform-dependent tools (such as the resource linker on Windows). Command
  line options to MBUILD may also affect what arguments are passed to these
  tools, or may control other aspects of MBUILD's behavior.

Command Line Options:
  Options available on all platforms:

  -c
      Compile only. Creates an object file but not an executable.
  -D<name>
      Define a symbol name to the C/C++ preprocessor. Equivalent to a
      "#define <name>" directive in the source.
  -D<name>#<value>
      Define a symbol name and value to the C/C++ preprocessor. Equivalent
      to a "#define <name> <value>" directive in the source.
  -f <optionsfile>
      Specify location and name of options file to use. Overrides MBUILD's
      default options file search mechanism.
  -g
      Create a debuggable executable. If this option is specified, MBUILD
      appends the value of options file variables ending in DEBUGFLAGS with
      their corresponding base variable. (For example, the value of
      LINKDEBUGFLAGS would be appended to the LINKFLAGS variable before
      calling the linker.) This option also disables MBUILD's default
      behavior of optimizing built object code.
  -h[elp]
      Print this message.
  -I<pathname>
      Add <pathname> to the list of directories to search for #include
      files.
  -inline
      Inline matrix accessor functions (mx*). The executable generated may
      not be compatible with future versions of the MATLAB C/C++ Math
      Library or MATLAB C/C++ Graphics Library.
  -lang <language>
      Specify compiler language. <language> can be c or cpp. By
      default, MBUILD determines which compiler (C or C++) to use by
      inspection of the source file's extension. This option overrides that
      mechanism.
  -n
      No execute mode. Print out any commands that MBUILD would otherwise
      have executed, but do not actually execute any of them.
  -O
      Optimize the object code by including the optimization flags listed in
      the options file. If this option is specified, MBUILD appends the
      value of options file variables ending in OPTIMFLAGS with their
      corresponding base variable. (For example, the value of LINKOPTIMFLAGS
      would be appended to the LINKFLAGS variable before calling the
      linker.) Note that optimizations are enabled by default, are disabled
      by the -g option, but are reenabled by -O.
  -outdir <dirname>
      Place all output files in directory <dirname>.
  -output <resultname>
      Create executable named <resultname> (an appropriate executable
      extension is automatically appended). Overrides MBUILD's default
      executable naming mechanism.
  -setup
      Interactively specify the compiler options file to use as default for
      future invocations of MBUILD by placing it in
      "<UserProfile>\Application Data\MathWorks\MATLAB\R12" (for Windows) or
      $HOME/.matlab/R12 (for UNIX). When this option is specified, no other
      command line input is accepted.
  -U<name>
      Remove any initial definition of the C preprocessor symbol <name>.
      (Inverse of the -D option.)
  -v
      Print the values for important internal variables after the options
      file is processed and all command line arguments are considered.
      Prints each compile step and final link step fully evaluated to see
      which options and files were used. Very useful for debugging.
  <name>#<value>
      Override an options file variable for variable <name>. See the
      platform-dependent discussion of options files below for more details.
      This option is processed after the options file is processed and all
      command line arguments are considered.

Additional options available on Windows platforms:

  @<rspfile>
      Include contents of the text file <rspfile> as command line arguments
      to MBUILD.

Additional options available on Unix platforms:

  -<arch>
      Assume local host has architecture <arch>. Possible values for <arch>
      include sol2, hpux, hp700, alpha, ibm_rs, sgi, and glnx86.
  -D<name>=<value>
      Define a symbol name and value to the C preprocessor. Equivalent to a
      "#define <name> <value>" directive in the source.
  -l<name>
      Link with object library "lib<name>" (for "ld(1)").
  -L<directory>
      Add <directory> to the list of directories containing object-library
      routines (for linking using "ld(1)").
  <name>=<value>
      Override an options file variable for variable <name>. See the
      platform-dependent discussion of options files below for more details.

Shared Libraries and Exports Files:
  MBUILD can also create shared libraries from C source code. If a file or
  files with the extension ".exports" is passed to MBUILD, then it builds a
  shared library. The .exports file must be a flat text file, with each line
  containing either an exported symbol name, or starting with a # or * in
  the first column (in which case it is treated as a comment line). If
  multiple .exports files are specified, then all symbol names in all
  specified .exports files are exported.

Options File Details:
  On Windows:
    The options file is written as a DOS batch file. If the -f option is not
    used to specify the options file name and location, then MBUILD searches
    for an options file named compopts.bat in the following directories: the
    current directory, then the directory "<UserProfile>\Application
    Data\MathWorks\MATLAB\R12". Any variable specified in the options file
    can be overridden at the command line by use of the <name>#<value>
    command line argument. If <value> has spaces in it, then it should be
    wrapped in double quotes (e.g., COMPFLAGS#"opt1 opt2"). The definition
    can rely on other variables defined in the options file; in this case
    the variable referenced should have a prepended "$" (e.g.,
    COMPFLAGS#"$COMPFLAGS opt2").

  On UNIX:
    The options file is written as a UNIX shell script. If the -f option is
    not used to specify the options file name and location, then MBUILD
    searches for an options file named mbuildopts.sh in the following
    directories: the current directory (.), then $HOME/.matlab/R12, then
    $MATLAB/bin. Any variable specified in the options file can be
    overridden at the command line by use of the <name>=<def> command line
    argument. If <def> has spaces in it, then it should be wrapped in single
    quotes (e.g., CFLAGS='opt1 opt2'). The definition can rely on other
    variables defined in the options file; in this case the variable
    referenced should have a prepended "$" (e.g., CFLAGS='$CFLAGS opt2').

Examples:
    The following command will compile "myprog.c" into "myprog.exe" (when
    run under Windows):

      mbuild myprog.c

    When debugging, it is often useful to use "verbose" mode as well
    as include symbolic debugging information:

      mbuild -v -g myprog.c

    The following command will compile "mylib.c" into "mylib.dll" (when run
    under Windows). "mylib.dll" will export the symbols listed in
    "mylib.exports":

      mbuild mylib.c mylib.exports

end_help_mb
     /^usage$/ && print(<<'end_usage_mb') && last DESCRIPTION;
    Usage:
      MBUILD [option1 ... optionN] sourcefile1 [... sourcefileN]
             [objectfile1 ... objectfileN] [libraryfile1 ... libraryfileN]
             [exportfile1 ... exportfileN]

    Use the -help option for more information, or consult the MATLAB C/C++ Math
    Library User's Guide.

end_usage_mb
     /^general_info$/ && print(<<"end_general_info_mb") && last DESCRIPTION;
 This is mbuild (c) 1996 - 2000 The MathWorks, Inc.

end_general_info_mb
     /^invalid_options_file$/ && print(<<"end_invalid_options_file_mb") && last DESCRIPTION;
    Warning: An options file for MBUILD.BAT was found but the
             value for 'COMPILER' was not set.  This could mean that the
             value is not specified within the options file, or it could
             mean that there is a syntax error within the file.


end_invalid_options_file_mb
     /^final_options$/ && print(<<"end_final_options_mb") && last DESCRIPTION;
$sourced_msg
----------------------------------------------------------------
->    Options file           = $OPTFILE_NAME
->    COMPILER               = $COMPILER
->    Compiler flags:
         COMPFLAGS           = $COMPFLAGS
         OPTIMFLAGS          = $OPTIMFLAGS
         DEBUGFLAGS          = $DEBUGFLAGS
         arguments           = $ARG_FLAGS
         Name switch         = $NAME_OBJECT
->    Pre-linking commands   = $PRELINK_CMDS
->    LINKER                 = $LINKER
->    Link directives:
         LINKFLAGS           = $LINKFLAGS
         Name directive      = $NAME_OUTPUT
         File link directive = $LINK_FILE
         Lib. link directive = $LINK_LIB
         Rsp file indicator  = $RSP_FILE_INDICATOR
----------------------------------------------------------------

end_final_options_mb
     /^file_not_found$/ && print(<<"end_file_not_found_mb") && last DESCRIPTION;
  $main::cmd_name:  $filename not a normal file or does not exist.

end_file_not_found_mb
     /^meaningless_output_flag$/ && print(<<"end_meaningless_output_flag_mb")  && last DESCRIPTION;
  Warning: -output ignored (no MBUILD application is being created).

end_meaningless_output_flag_mb

    /^compiler_not_found$/ && print(<<"end_compiler_not_found_mb") && last DESCRIPTION;
  Could not find the compiler "$COMPILER" on the DOS path.
  Use mbuild -setup to configure your environment properly.

end_compiler_not_found_mb

    /^outdir_missing_name_object$/ && print(<<"end_outdir_missing_name_object_mb") && last DESCRIPTION;
  Warning: The -outdir switch requires the mbuild options file to define
           NAME_OBJECT. Make sure you are using the latest version of
           your compiler's mbuildopts file.

end_outdir_missing_name_object_mb

    /^bad_lang_option$/ && print(<<"end_bad_lang_option_mb") && last DESCRIPTION;
  Unrecognized language specified. Please use -lang cpp (for C++) or
  -lang c (for C).

end_bad_lang_option_mb

    /^bad_link_option$/ && print(<<"end_bad_link_option_mb") && last DESCRIPTION;
  Unrecognized link target specified. Please use -link exe (for an executable)
  or -link shared (for a shared/dynamically linked library).

end_bad_link_option_mb

     do {
         print "Internal error: Description for $_[0] not implemented\n";
         last DESCRIPTION;
     };
 }
}

sub tool_name
{
    if ($main::mbuild eq "yes")
    {
        "mbuild";
    }
    else
    {
        "mex";
    }
}

sub find_options_file
{
# inputs:
    my ($OPTFILE_NAME, $language, $no_setup) = @_;

# outputs:
    # $OPTFILE_NAME
    my ($source_dir, $sourced_msg);

# locals:
    my ($REGISTERED_COMPILER, @JUNK);

    if (-e ".\\$OPTFILE_NAME")
    {
	chop($source_dir = `cd`);
    }
    elsif (-e &get_user_profile_dir . "\\$OPTFILE_NAME")
    {
        $source_dir = &get_user_profile_dir;
    }
    elsif (-e "$main::script_directory\\$OPTFILE_NAME")
    {
	$source_dir = "$main::script_directory";
    }
    else
    {
        if (!$no_setup)
        {
            # No options file found, so try to detect the compiler
            &setup(&tool_name, $main::script_directory, [uc($lang)], 1); # 1 == automode
        }

        if (-e &get_user_profile_dir . "\\$OPTFILE_NAME")
        {
            $source_dir = &get_user_profile_dir;
        }
        else
        {
            &expire("Error: No compiler options file could be found to compile source code. Please run \"" . &tool_name . " -setup\" to rectify.");
        }
    }
    $OPTFILE_NAME = "$source_dir\\$OPTFILE_NAME";
    $sourced_msg = "-> Default options filename found in $source_dir";

    ($OPTFILE_NAME, $source_dir, $sourced_msg);
} # find_options_file

#######################################################################
# Run a single command
#######################################################################
sub RunCmd {
    my ($cmd) = @_;
    my ($rc, $messages);
    $cmd = "\"$cmd\"" if ( $] >= 5.00503 && $ENV{OS} eq 'Windows_NT' );
    print "\n--> $cmd\n\n" if ($verbose || $main::no_execute);
    if (! $main::no_execute)
    {
        $messages = `$cmd`;
        $rc = $?;
        print $messages if $verbose;
        $rc = $rc >> 8 if $rc;
    }
    else
    {
        $messages = "";
        $rc = 0;
    }
    wantarray ? ($messages, $rc) : $messages;
} # RunCmd

# Search DOS PATH environment variable for $binary_name.  Return
# the directory containing the binary if found on the path, or an
# empty path otherwise.
sub search_path {
    my ($binary_name) = @_;
    my (@path, $path_entry, $found);

    foreach ( split(/;/,$ENV{'PATH'}) ) {
	if ( -e "$_\\$binary_name" ) {
	    print "search_path found: $_\\$binary_name\n" if $ENV{MEX_DEBUG};
	    return $_;
	}
    }
    '';
} # search_path

sub expire {
# Expire: Issue message and exit.  This is like "die" except that
#         it cleans up intermediate files before exiting.
#         &expire("normally") exits normally (doesn't die).

# Clean up compiled files, unless we're only compiling
    unlink @FILES_TO_REMOVE;

# clean up _lib? files in any case.
    $outdir = $ENV{'OUTDIR'};
    if ($outdir eq "")
    {
        $outdir = ".";
    }
    else
    {
        # strip trailing backslash:
        $outdir = substr($outdir, 0, length($outdir) - 1);
    }

    opendir(DIR,$outdir) || die " Can't open dir '$outdir': $!\n";
    while ($file = readdir(DIR)) {
        if ($file =~ /^_lib*.*/) {
            unlink("$outdir\\$file");
        }
    }
    closedir(DIR);

    if ($makefilename)
    {
        close(MAKEFILE);
        if ($_[0] ne "normally")
        {
            unlink $makefilename;
        }
    }

    die "\n  $main::cmd_name: $_[0]\n\n" unless ($_[0] eq "normally");
    exit(0);
}

sub process_response_file
{
# inputs:
    my ($filename) = @_;

# locals:
    my ($rspfile);

    open(RSPFILE, "$filename") || &expire("Error: Can't open response file '$filename': $!");
    while (<RSPFILE>)
    {
        $rspfile .= $_;
    }
    close(RSPFILE);

    # shellwords strips out backslashes thinking they are escape sequences.
    # In DOS we'd rather treat them as DOS path seperators.
    $rspfile =~ s/\\/\\\\/g;
    # return output of shellwords
    &shellwords($rspfile);
}


################################################################################
# Ada S-Functions
#
#
sub build_ada_s_function
{
    my ($ada_sfunction, $ada_include_dirs) = @_;
    $ada_sfunction =~ s/\//\\/g;
    if ($ada_sfunction eq "") {
	&expire("Error: Invalid use of -ada option");
    }
    
    # get the directorires
    my $mlroot = $main::script_directory;
    $mlroot =~ s/(.*)\\bin.*/$1/i;
    my $sl_ada_dir = $mlroot . "\\simulink\\ada";
    my $cwd = getcwd(); $cwd =~ s/\//\\/g;

    my $sfcn_base = $ada_sfunction;
    $sfcn_base =~ s/(.+\\)*(\w+).ad[bs]/$2/;

    my $sfcn_dir = $ada_sfunction;
    $sfcn_dir =~ s/(.*)$sfcn_base\.ad[sb]/$1/;
    if ($sfcn_dir eq "") {
        $sfcn_dir = $cwd;
    } else {
        # strip trailing backslash:
        $sfcn_dir = substr($sfcn_dir, 0, length($sfcn_dir) - 1);
    }

    my $sfcn_ads = $sfcn_dir . "\\" . $sfcn_base . ".ads";
    my $sfcn_adb = $sfcn_dir . "\\" . $sfcn_base . ".adb";

    # get s-function name
    my $cmd= "$sl_ada_dir\\bin\\win32\\get_defines $ada_sfunction 0";
    my $sfcn_name = RunCmd($cmd);
    if ($? != 0) {
	print "$sfcn_name" unless $verbose;
	&expire("Error: Unable to determine S-Function name - $!");
    }
    chomp($sfcn_name);

    # get s-function defines
    $cmd= "$sl_ada_dir\\bin\\win32\\get_defines $ada_sfunction";
    my $sfcn_defs = RunCmd($cmd);
    if ($? != 0) {
	print "$sfcn_defs" unless $verbose;
	&expire("Error: Unable to determine S-Function methods - $!");
    }
    chomp($sfcn_defs);

    # Make sure that the GNAT Ada Compiler is available.
    my $gnat_check = `gnatdll -v`;
    if ($? != 0) {
	&expire("Error: Unable to find the GNAT Ada compiler.  To use mex to " .
		"build Ada S-function '$ada_sfunction', you need to have the " .
		"GNAT Ada compiler (version 3.12 or higher), correctly " .
		"installed and available on the path.");
    }

    # create obj dir, and cd to it.
    my $obj_dir = $cwd . "\\" . $sfcn_base . "_ada_sfcn_win32";
    if ( !(-e $obj_dir) ) {
	mkdir($obj_dir, 777);
	if ($? != 0) {
	    &expire("Error: Unable to create $obj_dir -> $!");
	}
    }
    chdir($obj_dir);
    if ($? != 0) {
	&expire("Error: Unable to cd to $obj_dir -> $!");
    }

    # compiler flags for gcc
    my $gcc_flags = "-Wall -malign-double";
    if ($debug eq "yes") {
	$gcc_flags = $gcc_flags . " -g";
    } else {
	$gcc_flags = $gcc_flags . " -O2";
    }

    # invoke gnatmake to compile the ada sources (creates .ali file)
    my $sfcn_ali = $sfcn_base . ".ali";
    my $cmd  = "gnatmake -q -c -aI$sl_ada_dir\\interface -aI$sfcn_dir " . 
	       "$ada_include_dirs $sfcn_adb -cargs $gcc_flags";
    my $messages = RunCmd($cmd);
    if ($? != 0 || !(-e "$sfcn_ali" || $main::no_execute)) {
	print "$messages" unless $verbose;
	&expire("Error: Unable to compile $sfcn_adb -> $!");
    }
    
    # Compile the Ada S-Function's entry point
    my $sl_ada_entry = "$sl_ada_dir\\interface\\sl_ada_entry.c";
    my $cmd  = "gcc -I$sl_ada_dir\\interface -I$mlroot\\extern\\include " .
	       "-I$mlroot\\simulink\\include $gcc_flags -DMATLAB_MEX_FILE " .
	       "$sfcn_defs -c $sl_ada_entry";
    my $messages = RunCmd($cmd);
    if ($? != 0 || !(-e "sl_ada_entry.o" || $main::no_execute)) {
	print "$messages" unless $verbose;
	&expire("Error: Unable to compile $sl_ada_entry -> $!");
    }
    
    # Invoke gnatdll to build the dll (mex file)
    my $mex_file = $sfcn_name . ".dll"; 
    my $cmd = "gnatdll -q -n -e $sl_ada_dir\\interface\\mex.def " .
	      "-d $sfcn_name.dll $sfcn_ali sl_ada_entry.o " .
	      "-largs $sl_ada_dir\\lib\\\win32\\libmx.lib " .
	      "$sl_ada_dir\\lib\\win32\\libmex.lib";
    my $messages = RunCmd($cmd);
    if ( $? != 0 || !(-e "$mex_file" || $main::no_execute) ) {
	print "$messages" unless $verbose;
	&expire("Error: Unable to build mex-file $mex_file - $!");
    }
    # move it to the 
    rename($mex_file, $cwd . "\\" . $mex_file);
    if ($? != 0) {
	print "$messages" unless $verbose;
	&expire("Error: Unable to move $mex_file to $cwd\\$mex_file - $!");
    }
    &expire("normally");
}


#######################################################################
# Expand possible wildcards in the arguments for perl >= 5.00503
#######################################################################
if ($] >= 5.00503) {
    my (@a) = map { /\*/ ? glob($_) : $_ } @ARGV;
    if ( "@a" ne "@ARGV" ) {
	#my ($n) = 0;
	#print join("\n\t", "Old arguments:",
	#	   map { $n++; "$n. $_" } @ARGV), "\n";
	#$n = 0;
	#print join("\n\t", "New arguments:",
	#	   map { $n++; "$n. $_" } @a), "\n";
	@ARGV = @a;
    }
}

#######################################################################
# Initialize variables
#######################################################################

# Correct how the $cmd_name variable looks so that it is presentable
# to DOS users (i.e., trade / with \).
($main::cmd_name = $0) =~ s/\//\\/g;
$main::cmd_name =~ tr/a-z/A-Z/;
($main::script_directory) = ($main::cmd_name =~ /(.*)\\.*/);

if ($main::script_directory) {
    ($main::script_directory) .= "\\mexopts";
} else {
    ($main::script_directory) = ".\\mexopts";
}

$| = 1;                         # Force immediate output flushing
open(STDERR,">&STDOUT");		# redirect stderr to stdout for matlab
select((select(STDERR), $|=1 )[0]);  # force immediate flushing for STDERR

$OPTFILE_NAME = "mexopts.bat";
$sourced_msg = 'none';
$mex_include_dir = "extern\\include";
$main::mbuild = "no";

# Trap case where an invalid options file is used, by checking the
# value of the compiler
$COMPILER = "none";

# $$ should be the pid, but this is not defined for Windows perl
# We'll use a random integer instead.  This is only an issue
# if you build more than one mex file in the same directory at
# the same time, and this way there's a pretty low chance of
# failure.
srand;
$$ = int(rand(10000));

#
# Ada S-Functions: mex [-v] [-g] [-aI<dir1>] ... [-aI<dirN>] -ada sfcn.ads
#
#
$ada_sfunction    = "";
$ada_include_dirs = "";

#######################################################################
# Parse input arguments & determine MEX-file name from 1st source file
#######################################################################

$lang = "c"; # Should always be one of {"c", "cpp", "fortran", "all", "ada"}
$link = "unspecified";
$ENV{'ENTRYPOINT'} = "mexFunction";

for (;$_=shift(@ARGV);) {
    # Perl-style case construct
    # print "DEBUG input argument is $_\n";
  ARGTYPE: {
      /^-argcheck$/ && do {
          $ARG_FLAGS = "$ARG_FLAGS -DARGCHECK";
          $argcheck = "yes";
          last ARGTYPE;
      };
      /^-c$/ && do {
          $compile_only = "yes";
          last ARGTYPE;
      };
      /^-D\S*$/ && do {
          if ($_ eq "-DV4_COMPAT") {
              &expire("Please use -V4 rather than directly passing in -DV4_COMPAT.");
          } elsif ($_ eq "-DARRAY_ACCESS_INLINING") {
              &expire("Please use -inline rather than directly passing in -DARRAY_ACCESS_INLINING.");
          } else {
              $_ =~ s/[=\#]/=/;
              $ARG_FLAGS = "$ARG_FLAGS $_";
              last ARGTYPE;
          }
      };
      /^-U\S*$/ && do {
          $ARG_FLAGS = "$ARG_FLAGS $_";
          last ARGTYPE;
      };
      /^-I.*$/ && do {
          $ARG_FLAGS .= " " . &smart_quote($_);
          last ARGTYPE;
      };
      /^-f$/ && do {
          $filename = shift(@ARGV);
          if (-e $filename) {
              $OPTFILE_NAME =  "$filename";
          } elsif (-e "$main::script_directory\\$filename") {
              $OPTFILE_NAME = "$main::script_directory\\$filename";
          }
          else { 
              &expire("Error: Could not find specified options file\n    '$filename'.");
          }
          $sourced_msg = '-> Options file specified on command line';
          last ARGTYPE;
      };
      /^-g$/ && do {
          $debug = "yes";
          last ARGTYPE;
      };
      /^[-\/](h(elp)?)|\?$/ && do {
	  if ($main::mbuild eq "no") {
	      &describe("help");
	  } else {
	      &describe_mb("help");
	  }
	  # &describe("help");
          &expire("normally");
          last ARGTYPE;
      };
      /^-inline$/ && do {
          $inline = "yes";
          last ARGTYPE;
      };

      /^-k$/ && do { # This is an undocumented feature which is subject to change
          $makefilename = shift(@ARGV);
          last ARGTYPE;
      };

      /^-lang$/ && ($main::mbuild eq "yes") && do {
          $lang_override = shift(@ARGV);
          if (!($lang_override =~ /(cpp|c)/)) { &describe_mb("bad_lang_option"); }

          last ARGTYPE;
      };

      /^-link$/ && ($main::mbuild eq "yes") && do {
          # This is an undocumented feature which is subject to change
          $link = shift(@ARGV);

          if (!($link =~ /^(shared|exe)$/)) { &describe_mb("bad_link_option"); }

          last ARGTYPE;
      };

      /^-setup$/ && do {
          $setup = "yes";
          last ARGTYPE;
      };
      /^-called_from_matlab$/ && do {
          $called_from_matlab = "yes";
          last ARGTYPE;
      };
      /^-output$/ && do {
          $output_flag = "yes";
          $ENV{'MEX_NAME'}=shift(@ARGV);
          last ARGTYPE;
      };
      /^-O$/ && do {
          $optimize = "yes";
          last ARGTYPE;
      };
      /^-outdir$/ && do {
          $outdir_flag = "yes";
          $ENV{'OUTDIR'}=shift(@ARGV) . "\\";
          last ARGTYPE;
      };
      /^-v$/ && do {
	  if ($main::mbuild eq "no") {
	      &describe("general_info");
	  } else {
	      &describe_mb("general_info");
	  }
	  #  &describe("general_info");
          $verbose = "yes";
          last ARGTYPE;
      };
      /^-V4$/ && do {
          $v4 = "yes";
          $ARG_FLAGS = "$ARG_FLAGS -DV4_COMPAT";
          last ARGTYPE;
      };
      /^-matlab$/ && do {
          $matlab = shift(@ARGV);
          $matlab =~ tr/"//d;
          $ENV{'MATLAB'} = $matlab;
          last ARGTYPE;
      };
      /^-mb$/ && do {
          $main::mbuild = "yes";
	  $OPTFILE_NAME = "compopts.bat";
	  $main::script_directory =~ s/mexopts/mbuildopts/g;
	  $main::cmd_name = "MBUILD.BAT";
          last ARGTYPE;
      };
      /^-n$/ && do {
          $main::no_execute = 1; # global used by RunCmd
          last ARGTYPE;
      };
      /^-nohg$/ && do {
          # This is an undocumented feature which is subject to change
          $nohg = 1;
          last ARGTYPE;
      };
      /^-no_mmfile$/ && do {
          # This is an undocumented feature which is subject to change
          $no_mmfile = 1;
          last ARGTYPE;
      };
      /^-no_mwsglm$/ && do {
          # This is an undocumented feature which is subject to change
          $no_mwsglm = 1;
          last ARGTYPE;
      };
      /^-no_setup$/ && do {
          # This is an undocumented feature which is subject to change
          $no_setup = 1;
          last ARGTYPE;
      };
      /^[A-Za-z0-9_]+\#.*$/ && do {
          push(@CMD_LINE_OVERRIDES, $_);
          last ARGTYPE;
      };
      /^-ada$/ && ($main::mbuild eq "no") && do {
          if ($ada_sfunction ne "" || $#ARGV == -1) {
              &expire("Error: Invalid use of -ada option");
          }
          $ada_sfunction = shift(@ARGV);
          if ( !(-e $ada_sfunction) ) {
              &expire("Error: File '$ada_sfunction' not found");
          }
          $lang_override = "ada";
          last ARGTYPE;
      };
      /^-aI.*$/ && ($main::mbuild eq "no") && do {
          $ada_include_dirs .= " " . $_;
          last ARGTYPE;
      };
      /^-entrypt$/ && ($mbuild eq "no") && do {
          $ENV{'ENTRYPOINT'} = shift(@ARGV);
          if ($ENV{'ENTRYPOINT'} ne "mexFunction" &&
              $ENV{'ENTRYPOINT'} ne "mexLibrary")
          {
              &expire("Error: -entrypt argument must be either 'mexFunction'\n  or 'mexLibrary'");
          }
          last ARGTYPE;
      };
      /^-.*$/ && do {
	  if ($main::mbuild eq "no") {
	      &describe("usage");
	  } else {
	      &describe_mb("usage");
	  }
          &expire("Error: Unrecognized switch: $_.");
          last ARGTYPE;
      };
      /^@(.*)$/ && do {
          @NEW_ARGS = &process_response_file($1);
          unshift(@ARGV, @NEW_ARGS);
          last ARGTYPE;
      };
      /^.*\.exports$/ && ($main::mbuild eq "yes") && do {
          push(@EXPORT_FILES, $_);
          last ARGTYPE;
      };
      do {
          # Remove quotes put there by mex.m
          tr/"//d;

          if (/(.*)\.dll$/)
          {
              &expire("Error: " . &tool_name() . " cannot link to '$_' directly.\n" .
                      "  Instead, you must link to the file '$1.lib' which corresponds " .
                      "to '$_'.");
          }

          if (!/\.lib$/ && !-e $_) {
	      &expire("Error: '$_' not found.");
          }
          # Put file in list of files to compile
	  push(@FILES, $_);

	  # Try to determine compiler (C or C++) to use from file extension.
          if (/\.(cpp|cxx|cc)$/i)
          {
              $lang = "cpp";
          }
          if (/\.c$/i)
          {
              $lang = "c";
          }
          if (/\.(f|for)$/i)
          {
              $lang = "fortran";
          }

          last ARGTYPE;
      };
  };
}

if ($lang_override) { $lang = $lang_override; }

#
# Fix for Windows NT/2000 systemroot bug
#
$ENV{'PATH'} =~ s/\%systemroot\%/$ENV{'systemroot'}/ig;

if ($lang eq "fortran" && $ENV{'ENTRYPOINT'} ne "mexFunction")
{
    &describe("fortran_cannot_change_entrypt");
    $ENV{'ENTRYPOINT'} = "mexFunction";
}

################################################################################
# Ada S-Functions
#
if ($lang eq "ada")
{
    build_ada_s_function($ada_sfunction, $ada_include_dirs);
    # we expire from the above function 
}
################################################################################


if ($link eq "unspecified" && $main::mbuild eq "yes")
{
    if (@EXPORT_FILES > 0)
    {
        $link = "shared";
    }
    else
    {
        $link = "exe";
    }
}

# it doesn't mean anything to redirect the output if we aren't creating a MEX-file
if ($compile_only && $output_flag){
    if ($main::mbuild eq "no") {
	&describe("meaningless_output_flag");
    } else {
	&describe_mb("meaningless_output_flag");
    }
}
#&describe("meaningless_output_flag") if ($compile_only && $output_flag);

# check to see if we're only setting up the compiler locations
if ($setup)
{
    &setup(&tool_name, $main::script_directory, ['ANY'], 0); # 0 == no automode
    exit(0);
}

# get mex-file name and source file type from 1st file argument
($derived_name, $EXTENSION) = ($FILES[0] =~ /([ \w]*)\.(\w*)$/);
$ENV{'MEX_NAME'} = $derived_name if (!($ENV{'MEX_NAME'}));
my $fortran = "yes"
    if ($EXTENSION eq 'f' || $EXTENSION eq 'F' || $EXTENSION eq 'for');

# Set up the DLL_NAME environment variable, so it can be filled in
# later when it is known.

$ENV{'DLL_NAME'}  = "none";

$RC_LINKER = " ";
$RC_COMPILER = " ";

#
# Create a unique name for the created import library
#
$ENV{'LIB_NAME'} = &smart_quote("$ENV{'OUTDIR'}\_lib$$");

#
# Create the name of the master exports file which mex will generate.
# This is an "input" to the options file so it needs to be set before we
# process the options file.
#
if ($makefilename)
{
    # _nq => not quoted
    $base_exports_file_nq     = "$ENV{'OUTDIR'}$ENV{'MEX_NAME'}_master.exports"; 
    $ENV{'BASE_EXPORTS_FILE'} = &smart_quote($base_exports_file_nq);
    $ENV{'DEF_FILE'}          = &smart_quote("$ENV{'OUTDIR'}$ENV{'MEX_NAME'}_master.def");
}
else
{
    $base_exports_file_nq     = "$ENV{'OUTDIR'}$$\_tmp.exports";
    $ENV{'BASE_EXPORTS_FILE'} = &smart_quote($base_exports_file_nq);
    $ENV{'DEF_FILE'}          = "$ENV{'LIB_NAME'}.def";
}
$BASE_EXPORTS_FILE = $ENV{'BASE_EXPORTS_FILE'};
$DEF_FILE          = $ENV{'DEF_FILE'};

#######################################################################
# Source options file
#######################################################################

# If VISUAL_STUDIO is set and MSVCDir is not, set MSVCDir based on
# VISUAL_STUDIO.  If DevStudio is set and MSVCDir is not, set MSVCDir
#  based on DevStudio.
#
# NOTE:  VISUAL_STUDIO and DevStudio are MathWorks specific environment
#        variables and are not set by Microsoft's compiler(s).
#
if ($ENV{'VISUAL_STUDIO'} ne "" && $ENV{'MSVCDir'} eq "" &&
    ! grep /msvc50/, $OPTFILE_NAME) {
    print("Setting MSVCDir for use with MSVC 6.0 (MathWorks-only diagnostic - do not geck)\n");
    $ENV{'MSVCDir'} = $ENV{'VISUAL_STUDIO'} . "\\VC98";
} elsif ($ENV{'DevStudio'} ne "" && $ENV{'MSVCDir'} eq "") {
    print("Setting MSVCDir for use with MSVC 5.0(MathWorks-only diagnostic - do not geck)\n");
    $ENV{'MSVCDir'} = $ENV{'DevStudio'} . "\\VC";
}

# If we don't already know what to use as the options file, search
# default locations.
if ($sourced_msg eq 'none')
{
    ($OPTFILE_NAME, $source_dir, $sourced_msg) = &find_options_file($OPTFILE_NAME, $lang, $no_setup);
}

# The DOS batch language is too limited for our purposes.
# Instead, we will parse the batch files on our own.
open (OPTIONSFILE, $OPTFILE_NAME) || &expire("Error: Can't open file '$OPTFILE_NAME': $!");
while ($_ = <OPTIONSFILE>) {
    chomp;
    next if (!(/^\s*set /));      # Ignore everything but set commands
    s/^\s*set //;                 # Remove "set " command itself
    s/\s+$//;                     # Remove trailing whitespace
    s/\\$//g;                     # Remove trailing \'s
    s/\\/\\\\/g;                  # Escape all other \'s with another \
    s/%(\w+)%/'.\$ENV{'$1'}.'/g;  # Replace %VAR% with $ENV{'VAR'}
    s/%%/%/g;                     # Replace %%s with %s
    my $perlvar = '$' . $_ . "\';";
    $perlvar =~ s/=/='/;
    my $dosvar = '$ENV{'."'".$_."';";
    $dosvar =~ s/=/'}='/;
    eval($perlvar);
    eval($dosvar);

    # We need a special case for the WATCOM compiler because it can't handle
    # directories with spaces or quotes in their names. So only put the quotes
    # around the MATLAB directory name if it has spaces in it.
    $ML_DIR = &smart_quote($MATLAB);

    # Set the special MATLAB_BIN environment variable
    if ( (! $ENV{'MATLAB'} eq "") && $ENV{'MATLAB_BIN'} eq "" )
    {
	$ENV{'MATLAB_BIN'} = "$ML_DIR\\bin\\win32";
    }

    # Set the special MATLAB_EXTLIB environment variable
    if ( (! $ENV{'MATLAB'} eq "") && $ENV{'MATLAB_EXT'} eq "" )
    {
	$ENV{'MATLAB_EXTLIB'} = "$ML_DIR\\extern\\lib\\win32";
    }
}

# This tells mbuild how to handle the options file variable USE_HG
#  1 : Link against the Graphics Library
#  0 : Don't link against the Graphics Library
# -1 : Link against the Graphics Library iff sgl.dll exists on disk
if ($main::mbuild eq "yes" && !$nohg) {
   $usehg = $ENV{'USE_HG'};

   if ($usehg eq -1) {
       if (-e "$main::script_directory\\..\\sgl.dll") {
           $usehg = 1;
       } else {
           $usehg = 0;
       }
   }
} else {
    $usehg = 0;
}

# Based on the language we're using, possibly adjust the flags
if ($lang eq "cpp" && $CPPCOMPFLAGS ne "")
{
    $COMPFLAGS = $CPPCOMPFLAGS;
    $LINKFLAGS = $CPPLINKFLAGS;
    if ($usehg) {
        $LINKFLAGS = $HGCPPLINKFLAGS;
    }
    $DEBUGFLAGS = $CPPDEBUGFLAGS;
    $OPTIMFLAGS = $CPPOPTIMFLAGS;
}
elsif ($link eq "shared")
{
    if ($DLLCOMPFLAGS eq "")
    {
        &expire("Error: The current options file is not configured to create DLLs. "
                . "You can use\n" . &tool_name() . " -setup to set up an options file "
                . "which is configured to create DLLs.");
    }

    $COMPFLAGS = $DLLCOMPFLAGS;
    $LINKFLAGS = $DLLLINKFLAGS;
    $LINKFLAGSPOST = $DLLLINKFLAGSPOST;
    if ($usehg) {
        $LINKFLAGS = $HGDLLLINKFLAGS;
        $LINKFLAGSPOST = $HGDLLLINKFLAGSPOST;
    }
    $NAME_OUTPUT = $DLL_NAME_OUTPUT;

    # copy all exported symbols into one master export file
    open(EXPORT_FILE, ">$base_exports_file_nq") ||
	&expire("Could not open file '$base_exports_file_nq': $!");
    push(@FILES_TO_REMOVE, "$base_exports_file_nq") if (!$makefilename);
    foreach my $an_export_file (@EXPORT_FILES)
    {
        open(AN_EXPORT_FILE, "$an_export_file") ||
            &expire("Could not open file '$an_export_file': $!");
        while (<AN_EXPORT_FILE>)
        {
            # Strip out lines that only contain whitespace and
            # lines that start with '#' or '*' (comments)
            if (/\S/ && !/^[\#*]/)
            {
                print EXPORT_FILE $_;
            }
        }
        close(AN_EXPORT_FILE);
    }
    close(EXPORT_FILE);
} else {
    if ($usehg) {
        $LINKFLAGS = $HGLINKFLAGS;
        $LINKFLAGSPOST = $HGLINKFLAGSPOST;
    }
}

if ($no_mmfile)
{
    $LINKFLAGS =~ s/$ENV{'LINK_LIB'} +libmmfile.lib//g;
    $LINKFLAGSPOST =~ s/$ENV{'LINK_LIB'} +libmmfile.lib//g;
}
if ($no_mwsglm)
{
    $LINKFLAGS =~ s/$ENV{'LINK_LIB'} +libmwsglm.lib//g;
    $LINKFLAGSPOST  =~ s/$ENV{'LINK_LIB'} +libmwsglm.lib//g;
}


# Process command line overrides
foreach $override (@CMD_LINE_OVERRIDES)
{
    $override =~ /^([A-Za-z0-9_]+)[\#](.*)$/;
    $lhs = $1;
    $rhs = $2;

    $rhs =~ s/\\/\\\\/g;              # Escape all other \'s with another \
    $rhs =~ s/"/\\"/g;
    $rhs =~ s/\$([A-Za-z0-9_]+)/\$ENV{'$1'}/g;  # Replace $VAR with $ENV{'VAR'}

    my $perlvar = '$' . $lhs . " = \"" . $rhs . "\";";
    my $dosvar = "\$ENV{\'" . $lhs . "\'} = \"" . $rhs . "\";";

    eval($perlvar);
    eval($dosvar);
}

$bin_extension = $NAME_OUTPUT;
$bin_extension =~ s/\"//g;
$bin_extension =~ s/.*\.([^.]*)$/\1/;

if ($verbose) {
    if ($main::mbuild eq "no") {
	&describe("final_options");
    } else {
	&describe_mb("final_options");
    }
}

if ($COMPILER eq "none") {
  if ($main::mbuild eq "no") {
      &describe("invalid_options_file");
  } else {
      &describe_mb("invalid_options_file");
  }
}

# WATCOM Compiler can't handle MATLAB installations with spaces in
# path names.

if ($COMPILER =~ /(wpp)|(wcc)|(wcl)/ && $MATLAB =~ " ")
{
    &expire("You have installed MATLAB into a directory whose name contains spaces. " .
            "The WATCOM compiler cannot handle that. Either rename your MATLAB " .
            "directory (currently $MATLAB) or run mex -setup and select a " .
            "different compiler.");
}

if ($outdir_flag && $NAME_OBJECT eq "") {
    if ($main::mbuild eq "no") {
        &describe("outdir_missing_name_object");
    } else {
        &describe_mb("outdir_missing_name_object");
    }
}

# check that MATLAB or the C/C++ Math Library is where it is expected to be

if ( ! -e "$MATLAB\\extern\\include\\matrix.h" ) {
  if ($main::mbuild eq "no") {
      &expire("Error: The variable MATLAB in \"mex.bat\" was not set properly.\n" .
              "           Please modify this variable at the top of the file " .
              "\"mex.bat\".\n\n           MATLAB is currently set to $MATLAB");
  } else {
      &expire("Error: Cannot find the MATLAB C/C++ Math Library on your path.  " .
              "Please check your path or re-install the C/C++ Math Library.");
  }
}

#######################################################################
# Determine final values
#######################################################################

# Decide how to optimize or debug
if (! $debug) {                                  # Normal case
   $FLAGS = "$OPTIMFLAGS";
   $LINKFLAGS = "$LINKFLAGS $LINKOPTIMFLAGS";
} elsif (! $optimize) {                          # Debug; don't optimize
   $FLAGS = "$DEBUGFLAGS";
   $LINKFLAGS = "$LINKDEBUGFLAGS $LINKFLAGS ";
} else {                                         # Debug and optimize
   $FLAGS = "$DEBUGFLAGS $OPTIMFLAGS";
   $LINKFLAGS = "$LINKDEBUGFLAGS $LINKFLAGS $LINKOPTIMFLAGS ";
}

# Include the simulink include directory if it exists
#
my ($simulink_inc_dir) = '';
$simulink_inc_dir = "-I$ML_DIR\\simulink\\include"
    if (-e "$MATLAB\\simulink\\include");

# Add extern/include to the path (it always exists)
$FLAGS = "-I$ML_DIR\\$mex_include_dir $simulink_inc_dir $FLAGS"
    unless ($fortran);

# Add inlining if switch was set
$FLAGS = "$FLAGS -DARRAY_ACCESS_INLINING" if ( $inline );

# If there are no files, then exit.
#
if ( ! @FILES ) {
    if ($main::mbuild eq "no"){
	&describe("usage");
    } else {
	&describe_mb("usage");
    }
    &expire("Error: No file names given.");
}

# If we are checking arguments, add $MATLAB/extern/src/mwdebug.c
# to source file list.
push(@FILES, "$MATLAB\\extern\\src\\mwdebug.c") if ($argcheck eq "yes");

#######################################################################
# Verify that compiler binary exists
#######################################################################
$COMPILER_DIR = &search_path("$COMPILER.exe");
if ( ! $COMPILER_DIR ) {
    if ($main::mbuild eq "no") {
	&describe("compiler_not_found");
    } else {
	&describe_mb("compiler_not_found");
    }

    &expire("Error: Unable to locate compiler.");
}

#######################################################################
# Prepare makefile
#######################################################################
if ($makefilename)
{
    open(MAKEFILE, ">>$makefilename")
        || &expire("Error: Cannot append to file '$makefilename': $!");

    # Emit main dependency rule
    print MAKEFILE "bin_target : $ENV{'OUTDIR'}$ENV{'MEX_NAME'}.$bin_extension\n\n";
}

#######################################################################
# Compile source files
#######################################################################

# Loop over @FILES to compile each file.  Keep files we actually
# compile separate from the ones we don't compile but need to link.
# This way, we can later clean up all .obj files we created.
for (;$_=shift(@FILES);) {
    ($FILENAME, $EXTENSION) = (/([ \w]+)\.(\w*)$/);
    if ($EXTENSION =~ /(c|f|cc|cxx|cpp|for)$/i ) {
	my ($target_name, $name_arg);
        if ($NAME_OBJECT) {
            $target_name = "$ENV{'OUTDIR'}$FILENAME.obj";
            $name_arg = $NAME_OBJECT . &smart_quote($target_name);
        }
        else {
            $target_name = "$FILENAME.obj";
            $name_arg = "";
        }

	my ($args) =
	    "$ARG_FLAGS $COMPFLAGS $name_arg $FLAGS " . &smart_quote($_);

        if (!$makefilename)
        {
            my $messages = RunCmd("$COMPILER $args");
            # Check for error; $? might not work, so also check for resulting file
            if ($? != 0 || !(-e "$target_name" || $main::no_execute)) {
                print "$messages" unless $verbose; # verbose => printed in RunCmd
                &expire("Error: Compile of '$_' failed.");
            }
            if (!$compile_only)
            {
                push(@FILES_TO_REMOVE, "$target_name");
            }
        }
        else
        {
            # Emit compile dependency rule
            print MAKEFILE &smart_quote($target_name) . " : " . &smart_quote($_);
            print MAKEFILE "\n\t$COMPILER $args\n\n";
        }

        push(@FILES_TO_LINK, "$LINK_FILE " . &smart_quote($target_name));
        push(@FILES_TO_LINK_BASE, &smart_quote($target_name));
    }
    elsif ($EXTENSION =~ /lib$/i)
    {
          push(@FILES_TO_LINK, "$LINK_LIB " . &smart_quote($_));
          push(@FILES_TO_LINK_BASE, &smart_quote($_));
    }
    else
    {
          push(@FILES_TO_LINK, "$LINK_FILE " . &smart_quote($_));
          push(@FILES_TO_LINK_BASE, &smart_quote($_));
    }
}

&expire("normally") if ($compile_only);

#######################################################################
# Perform prelink tasks
#######################################################################
if ($makefilename)
{
    # Emit link dependency rule
    print MAKEFILE "$ENV{'OUTDIR'}$ENV{'MEX_NAME'}.$bin_extension";
    print MAKEFILE " : @FILES_TO_LINK_BASE\n";
}

#
# Note that error checking is not possible; we don't get a return
# status, and there's no way of knowing a priori what each task is
# supposed to do.
(@PRELINK_CMDS) = split(/;/,$PRELINK_CMDS);
while ($PRELINK_CMDS = shift(@PRELINK_CMDS)) {
    # Skip if $PRELINK_CMDS is only whitespace
    next if (!($PRELINK_CMDS =~ /\S/));

    if (!$makefilename)
    {
        RunCmd($PRELINK_CMDS);
    }
    else
    {
        print MAKEFILE "\t$PRELINK_CMDS\n";
    }
}

# There can be multiple prelink command lines called, PRELINK_CMDS1, 2 etc.
# so loop through dealing with each.

my $i = 1;
while ( my $prelink = $ENV{"PRELINK_CMDS$i"} ) {
    if (!$makefilename)
    {
        RunCmd($prelink);
    }
    else
    {
        print MAKEFILE "\t$prelink\n";
    }
    $i++;
    $prelink =$ENV{"PRELINK_CMDS".$i};
}

my $i = 1;
while ( my $prelink = $ENV{"PRELINK_CMDS_HG$i"} ) {
    if (!$makefilename)
    {
        RunCmd($prelink);
    }
    else
    {
        print MAKEFILE "\t$prelink\n";
    }
    $i++;
    $prelink =$ENV{"PRELINK_CMDS_HG".$i};
}

# If DLL_MAKEDEF is set, and we are targeting a DLL, execute it
if ($link eq "shared")
{
    $i = 0;
    my $makedef = $ENV{"DLL_MAKEDEF"};
    while ($makedef =~ /\S/)
    {
        if ($makefilename)
        {
            print MAKEFILE "\t$makedef\n";
        }
        RunCmd($makedef);
        $i++;
        $makedef = $ENV{"DLL_MAKEDEF" . $i};
    }
}

push(@FILES_TO_REMOVE,
     ("$ENV{'MEX_NAME'}lib.exp"), ("$ENV{'MEX_NAME'}lib.lib"));
push(@FILES_TO_REMOVE, ("$ENV{'MEX_NAME'}.bak"));

#######################################################################
# If there is a resource compiler, compile resource now

if ($RC_COMPILER =~ /\S/) {
    my ($rc_line) = '';
    $rc_line .= " -DARRAY_ACCESS_INLINING" if ($inline);
    $rc_line .= " -DV4_COMPAT" if ($v4);
    $rc_line .= " \"$ENV{'MATLAB'}\\extern\\include\\mexversion.rc\"";

    if (!$makefilename)
    {
        my $messages = RunCmd("$RC_COMPILER $rc_line");
        # Check for error; $? might not work, so also check for string "error"
        if ($? != 0 || $messages =~ /\b(error|fatal)\b/i) {
            print "$messages" unless $verbose; # verbose => printed out in RunCmd
            &expire("Error: Resource compile of 'mexversion.rc' failed.");
        }
        push(@FILES_TO_REMOVE, "$ENV{'OUTDIR'}mexversion.res");
    }
    else
    {
        print MAKEFILE "\t$RC_COMPILER $rc_line\n";
    }

    push(@FILES_TO_LINK, &smart_quote("$ENV{'OUTDIR'}mexversion.res"));
}

#######################################################################
# Link files
#######################################################################
#
# NAME_OUTPUT always goes in the list, but it may be blank (in which
# case it's harmless to put it in).  Leaving the variable blank is
# equivalent to assuming that the output will be named after the
# first object file in the list.
my ($ARGS);
if ( $ENV{'RSP_FILE_INDICATOR'} )
{
    my $response_file;
    if ($makefilename)
    {
        $response_file = "$ENV{'OUTDIR'}$ENV{'MEX_NAME'}_master.rsp";
    }
    else
    {
        $response_file = "$ENV{'OUTDIR'}$$\_tmp.rsp";
    }
    open(RSPFILE, ">$response_file") || &expire("Error: Can't open file '$response_file': $!");
    push(@FILES_TO_REMOVE, "$response_file") if (!$makefilename);
    print RSPFILE " @FILES_TO_LINK";
    close(RSPFILE);

    $ARGS = "$NAME_OUTPUT $LINKFLAGS " .
        &smart_quote("$ENV{'RSP_FILE_INDICATOR'}$response_file") .
	    " $LINKFLAGSPOST";

    if ($verbose && !$makefilename)
    {
        print "    Contents of $response_file:\n";
        print " @FILES_TO_LINK\n\n";
    }
}
else
{
    $ARGS = "$NAME_OUTPUT $LINKFLAGS @FILES_TO_LINK $LINKFLAGSPOST";
}

if (!$makefilename)
{
    my $messages = RunCmd("$LINKER $ARGS");

    # Check for error; $? might not work, so also check for resulting file
    if ($? != 0 || !(-e "$ENV{'OUTDIR'}$ENV{'MEX_NAME'}.$bin_extension" || $main::no_execute ))
    {
        print "$messages" unless $verbose; # verbose => printed in RunCmd
        &expire("Error: Link of '$ENV{'OUTDIR'}$ENV{'MEX_NAME'}.$bin_extension' failed.");
    }
    # If we got a file, make sure there were no errors
    if ($messages =~ /\b(error|fatal)\b/i) {
        print "$messages" unless $verbose; # verbose => printed in RunCmd
        &expire("Error: Link of '$ENV{'OUTDIR'}$ENV{'MEX_NAME'}.$bin_extension' failed.");
    }

    if ($COMPILER =~ /bcc/ && $debug ne "yes")
    {
        push(@FILES_TO_REMOVE, "$ENV{'OUTDIR'}$ENV{'MEX_NAME'}.tds");
    }
}
else
{
    print MAKEFILE "\t$LINKER $ARGS\n";
}

#
# If a resource linker has been defined, use it
#
if ($RC_LINKER =~ /\S/) {
    my $rc_line = "$ENV{'MATLAB'}\\extern\\include\\mexversion.rc " .
        &smart_quote("$ENV{'OUTDIR'}$ENV{'MEX_NAME'}.$bin_extension");

    $rc_line = "$rc_line -DARRAY_ACCESS_INLINING" if ($inline);
    $rc_line = "$rc_line -DV4_COMPAT" if ($v4);

    if (!$makefilename)
    {
        my $messages = RunCmd("$RC_LINKER $rc_line");
        # Check for error; $? might not work, so also check for string "error"
        if ($? != 0 || $messages =~ /\b(error|fatal)\b/i) {
            print "$messages" unless $verbose; # verbose => printed in RunCmd
            &expire("Error: Resource link of 'mexversion.rc' failed.");
        }

        push(@FILES_TO_REMOVE,"$ENV{'OUTDIR'}mexversion.res");
    }
    else
    {
        print MAKEFILE "\t$RC_LINKER $rc_line\n";
    }
}

#
# If graphics lib app, copy the fig files if necessary
#
if ($main::mbuild eq "yes")
{
   if ($usehg)
   {
      if (!(-e "$ENV{'OUTDIR'}bin"))
      {
	 mkdir("$ENV{'OUTDIR'}bin", 777);
      }
      if (!(-e "$ENV{'OUTDIR'}bin\\FigureMenuBar.fig"))
      {
          &RunCmd("copy \"$MATLAB\\extern\\include\\FigureMenuBar.fig\" " . 
                  &smart_quote("$ENV{'OUTDIR'}bin\\FigureMenuBar.fig"));
      }
      if (!(-e "$ENV{'OUTDIR'}bin\\FigureToolBar.fig"))
      {
          &RunCmd("copy \"$MATLAB\\extern\\include\\FigureToolBar.fig\" " .
                  &smart_quote("$ENV{'OUTDIR'}bin\\FigureToolBar.fig"));
      }
   }
}

#
# Call any postlink commands that may exist
#
my $postlink;
my @postlink = split(/;/, $ENV{"POSTLINK_CMDS"});
while ($postlink = shift(@postlink)) {
    next if (!($postlink =~ /\S/));
    if (!$makefilename)
    {
        RunCmd($postlink);
    }
    else
    {
        print MAKEFILE "\t$postlink\n";
    }
}
$i = 1;
$postlink = $ENV{"POSTLINK_CMDS" . $i};
while ($postlink =~ /\S/)
{
    if (!$makefilename)
    {
        RunCmd($postlink);
    }
    else
    {
        print MAKEFILE "\t$postlink\n";
    }
    $i++;
    $postlink = $ENV{"POSTLINK_CMDS" . $i};
}

if ($makefilename) {
    print MAKEFILE "\tif exist \"$ENV{'OUTDIR'}mexversion.res\" del \"$ENV{'OUTDIR'}mexversion.res\"\n";
    print MAKEFILE "\n";
}

#######################################################################
# Clean up files and exit
#######################################################################

&expire("normally"); # This also closes MAKEFILE

#######################################################################
# End perl code
#######################################################################

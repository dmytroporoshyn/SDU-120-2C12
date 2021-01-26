package mexsetup;

=head1 NAME

mexsetup - Handle setting up a default options file for mex or mbuild

=head1 SYNOPSIS

 use mexsetup;
 &setup($tool_name, # "mex" or "mbuild"
        $opts_dir,  # The directory containing the .stp setup files and .bat opts files
        $desired_languages, # An array reference containing uppercase strings of the 
                            # desired programming language for which to set up. All 
                            # compilers are listed if any of these strings are 'ANY'.
        $automode   # if true, automatically search for compilers, and if only one is 
                    # found, install it without bothering the user
        );

=head1 DESCRIPTION

Scans the directory $opts_dir for files with the .stp extension. Dynamically runs the 
perl code in those files to gather information about supported compilers. Uses this 
information to present a list to the user of supported compilers. Copies the template 
options file (also in $opts_dir) corresponding to the user selected compiler to the 
user's Profile directory.

A .stp file should contain one function, whose name is the same as the .stp file, minus
the ".stp". The function will be passed one input, a hash reference with at least the 
following fields:

    matlab_bin      => a string containing the location <MATLAB>\bin\win32.
    registry_lookup => a reference to a function which takes two input strings, 
                       a key and a name, and looks them up in the HKEY_LOCAL_MACHINE
                       portion of the Windows Registry. The function returns a string
                       containing the queried data, or an empty string if the data could
                       not be found.
    search_path     => a reference to a function which takes one input string, a 
                       filename, and searches for it on the DOS path. The function 
                       returns a string containing the directory in which the filename 
                       was found, or an empty string if the file could not be found.

The function returns a second hash reference, containing at least the following fields:

    vendor_name      => The full (vendored) name of the compiler 
                        (e.g. "Microsoft Visual C/C++").
    version          => The version of the compiler, as a string (e.g. "6.0")
    group_id         => A string containing the group to which this setup file belongs.
                        Usually, each vendor has its own group id. If the vendor changes
                        the name of the compiler (e.g. Borland C++ changed to Borland 
                        C++Builder), one can have mexsetup treat the two differently
                        named compilers as just different versions of the same compiler 
                        by having their .stp files contain the same group_id. The user
                        never sees the group_id.
    serial           => A serial number. Each .stp file with a given group_id must 
                        have a unique serial number. The serial number should increase
                        with each new version of the compiler. (e.g. MSVC 4.2 has a
                        serial number of 1.0, MSVC 5.0 has a serial number of 2.0, and
                        MSVC 6.0 has a serial number of 3.0.)
    optfile_name     => The base name of the template options file to copy to the 
                        user's Profile directory. This file must reside in $opts_dir as
                        well. (e.g. "msvc60opts.bat".)
    default_location => A string containing the location where the compiler's installer
                        installs the compiler by default.         
    language_handled => A reference to a function which accepts a string containing a
                        language and returns true if the language is handled by the 
                        compiler and false if it isn't. Current inputs can be "C", 
                        "CPP", and "FORTRAN".
    locate           => A reference to a function with no inputs, which returns a 
                        reference to an array of strings, each of which represents a 
                        directory where the compiler is located. The array can legally
                        have zero, one, or more entries. Setup() considers the leftmost
                        entry which has not also been returned by a locate function from
                        a .stp file with a higher serial number to be the directory 
                        where the compiler is located. This allows setup() to locate
                        multiple versions of the same compiler.
    root_var         => The name of the environment variable in the template options 
                        file which setup() will burn with the location of the compiler. 
                        When setup() copies the template options file from $opts_dir to
                        the user's Profile directory, it will search for a line of the 
                        form:
                         
                        set <root_var>=%<anystring>%
                      
                        It will replace %<anystring>% with the output of the root_val 
                        entry actual (see below), which usually is the location of the 
                        compiler.
    root_val         => A reference to a function which takes one string input, 
                        containing the base location of the compiler, and returns a 
                        string, containing the value to burn into the options file 
                        copied to the user's Profile directory. Under most circumstances
                        this function can simply return its input as its output. 
                        However, see msvc60opts.stp for an example of a .stp file where
                        it does not.
    post_setup_fcn   => (optional) A reference to a function with no inputs or outputs. 
                        If this entry exists, it is called by setup() after copying the 
                        template options file to the user's Profile directory.

Many .stp files are provided in <MATLAB>/bin/win32/mexopts and 
<MATLAB>/bin/win32/mbuildopts. These can be used as examples for creating .stp files 
for other (non-MathWorks supported) compilers.

=head1 COPYRIGHT

Copyright (c) 1999-2000 The MathWorks, Inc. All rights reserved.

=cut

# $Revision: 1.5 $

use Exporter ();
@ISA = qw(Exporter);

@EXPORT = qw(setup);

use Win32::Registry;
use strict;
use getprofiledir;

# Sort routine to sort compiler setup records by vendor name,
# with serial number as a secondary key.
sub by_vendor_and_serial
{
    if ($a->{"vendor_name"} lt $b->{"vendor_name"})
    {
        return -1;
    } 
    elsif ($a->{"vendor_name"} eq $b->{"vendor_name"})
    {
        return $b->{"serial"} <=> $a->{"serial"};
    }
    else
    {
        return 1;
    }
}

# Sort routine to sort compiler setup records by group id,
# with serial number as a secondary key.
sub by_group_and_serial
{
    if ($a->{"group_id"} lt $b->{"group_id"})
    {
        return -1;
    } 
    elsif ($a->{"group_id"} eq $b->{"group_id"})
    {
        return $b->{"serial"} <=> $a->{"serial"};
    }
    else
    {
        return 1;
    }
}

# Given a string S and a reference to an array of strings A, return
# true if any element of A equals S.
sub is_in
{
    my ($elem, $set_ref) = @_;
    my $set_elem;

    foreach $set_elem (@$set_ref)
    {
        if ($set_elem eq $elem)
        {
            return 1;
        }
    }
    
    return 0;
}    

sub query_info 
{
# queries and verifies that the 'var_value' is between the
# 'lower_limit' and the 'upper_limit'.  if not, then query for the
# 'request', citing the 'problem' as the reason.
# (this is used by 'setup')
    my ($lower_limit, $upper_limit, $problem, $request) = @_;
    my $var_value;

    chop($var_value=<STDIN>);
    # Verify that the value is with in the boundaries. It must be an integer.
    while (!($var_value =~ /[0-9]+/) ||
           $var_value<$lower_limit|$var_value>$upper_limit) {
	print "$problem\n";
	print "$request";
	chop($var_value=<STDIN>);
    }

    $var_value;
}

# This function looks up a string in the Windows registry. The first
# argument is a Registry key, and the second is a value name to
# look up under that key. The return argument is the corresponding
# value data, or an empty string if the key of value name are not
# found.
sub registry_lookup
{
    my ($key, $name) = @_;
    my ($value, %values, $hkey, $RegKey, $RegValue);
    my $data = "";

    if ($main::HKEY_LOCAL_MACHINE->Open($key, $hkey))
    {
        $hkey->GetValues(\%values);
        foreach $value (keys(%values))
        {
            $RegKey = $values{$value}->[0];
            $RegValue = $values{$value}->[2];
            if ($RegKey eq $name) {
                $data = $RegValue;
            }
        }
        $hkey->Close();
    }

    return($data);
} # registry_lookup

# Check for existence of a directory. If it doesn't exist, make it.
sub ensure_dir
{
    my ($dir) = @_;

    if (!(-d $dir))
    {
        my $parent_dir = $dir;
        $parent_dir =~ s/\\[^\\]+$//;
        &ensure_dir($parent_dir);
        if (mkdir($dir, 777) == 0)
        {
            die "Error: Cannot create directory \"$dir\"";
        }
    }
}

# Search DOS PATH environment variable for $binary_name.  Return
# the directory containing the binary if found on the path, or an
# empty path otherwise.
sub search_path 
{
    my ($binary_name) = @_;
    my (@path, $path_entry, $found);

    foreach ( split(/;/,$ENV{'PATH'}) ) 
    {
	if ( -e "$_\\$binary_name" ) 
        {
	    return $_;
	}
    }
    '';
} # search_path

# Copy a template mex or mbuild options file to the user's profile directory,
# "burning" into it the location of the selected compiler.
# If $ask_no_questions is true, no confirmation notice will be given.
sub install_options_file 
{
    my ($tool_name,       # "mex" or "mbuild"
        $record,          # Compiler setup record for selected compiler
        $opts_dir,        # Directory containing the .stp setup files and .bat opts files
        $chosen_location, # Directory containing the selected compiler
        $ask_no_questions,# Don't confirm setup if true
        $usehg            # Link against Graphics Library
        ) = @_;
    
    my $status;

    if (!$ask_no_questions)
    {
        # before making the edits, verify from the user all the information is correct
        print "\nPlease verify your choices:\n\n";
        print "Compiler: " . $record->{"vendor_name"} . " " . $record->{"version"} . "\n";
        print "Location: $chosen_location\n";
	if ($usehg == 1) {
	    print "Linking against the C/C++ Graphics Library\n";
	}
        print "\nAre these correct?([y]/n): ";
        chop($status=<STDIN>);
        if ($status eq "n" || $status eq "no")
        {
            print "\n  $tool_name: No compiler selected. No action taken.\n\n";
            return 1;
        }
    }
    my $root_val_fcn = $record->{"root_val"};
    my $root_val = &$root_val_fcn($chosen_location);

    # Get the target directory and make sure it exists:
    my $destOptsDir = &get_user_profile_dir;
    &ensure_dir($destOptsDir);

    my $destOptsFile;
    if ($tool_name eq "mex")
    {
	$destOptsFile="$destOptsDir\\mexopts.bat";
    }
    else
    {
    	$destOptsFile="$destOptsDir\\compopts.bat";
    }

    my $srcOptsFile = $opts_dir . "\\" . $record->{"optfile_name"};

    print "\nThe default options file:\n\"$destOptsFile\"\nis being updated " .
        "from $srcOptsFile...\n\n";

    # Open and read in the template options file.
    open (OPTIONSFILE, "<$srcOptsFile") || die "Error: Can't open $srcOptsFile";
    my @OptionsFile = <OPTIONSFILE>;
    close(OPTIONSFILE);

    # If the options file is read-only, ask if they want to overwrite it.
    if (-e $destOptsFile && ! -W $destOptsFile)
    {
        print "The options file $destOptsFile\nis read-only. Overwrite y/[n]? ";
	chop($status=<STDIN>);
	if ($status eq "y")
        {
            printf "Saving old options file in $destOptsFile.old\n";
            unlink("$destOptsFile.old");
            rename($destOptsFile,"$destOptsFile.old");
            unlink($destOptsFile);
        }
	else 
        { 
            printf "\nOptions file not changed.\n"; 
            return 1; 
        }
    }

    # Open the target output file, and write the template file into it.
    # when the Root Environment Variable (root_var) is assigned to, burn in
    # the compiler location.
    open (OPTIONSFILE, ">$destOptsFile") || die "Error: Can't open $destOptsFile";
    my $done=0;
    foreach (@OptionsFile) 
    {
	if (!$done && /^\s*set $record->{"root_var"}=/) {
            s/%\w+%/$root_val/;
	    $done=1;
	}

	if (/^\s*set USE_HG=-1/) {
            s/-1/$usehg/;
	}

        print OPTIONSFILE "$_";
    }

    close(OPTIONSFILE);
    return 0;
}

# This is the main routine for mexsetup. Only &setup can be called from outside of 
# this module. This routine queries the user for the default compiler to be used with mex
# or mbuild and installs the appropriate options file into the user's user profile 
# directory.
sub setup
{
    my ($tool_name, # "mex" or "mbuild"
        $opts_dir,  # The directory containing the .stp setup files and .bat opts files
        $desired_languages, # An array reference containing uppercase strings of the 
                            # desired programming language for which to set up. All 
                            # compilers are listed if any of these strings are 'ANY'.
        $automode   # if true, automatically search for compilers, and if only one is 
                    # found, install it without bothering the user
        ) = @_;

    my @filenames;
    my $filename;
    my $i;
    my $record;
    my @optfile_records;
    my $compiler_location;
    my $ask_no_questions;
    my $usehg;

    # Turn off buffered output.
    my $old_pipe = $|;
    $| = 1;

    if (!$automode)
    {
        print "Please choose your compiler ";
        if ($tool_name eq "mex") {
            print "for building external interface (MEX) files:\n\n";
        } else {
            print "for building standalone MATLAB applications:\n\n";
        }
    }

    my $matlab_bin = $opts_dir . "\\..";
    while ($matlab_bin =~ s/\\[^\\.]+\\\.\.//) {}

    # This structure is passed to the compiler setup function at initialization.
    my $optfile_inputs = {
        'matlab_bin'      => $matlab_bin,
        'registry_lookup' => \&registry_lookup,
        'search_path'     => \&search_path
    };

    # Get a list of all the *.stp files in $opts_dir.
    opendir OPTSDIR, "$opts_dir" || die "Error: Couldn't find $opts_dir";
    @filenames = grep /^*.stp$/, readdir OPTSDIR;
    closedir OPTSDIR;

    # For each .stp file, dynamically include it and call its initialization
    # routine (whose name must be the same as the .stp file minus the ".stp".
    foreach $filename (@filenames)
    {
        require "$opts_dir\\$filename";
        $filename =~ s/.stp//; # remove .stp extension

        # $filename is a string containing the name of a function to call,
        # a so-called "symbolic reference". 'Use strict' disallows this normally,
        # so the no strict/use strict stuff below temporarily allows it.
        no strict 'refs';
        $record = &$filename($optfile_inputs);
        use strict 'refs';

        my $language_handled_fcn = $record->{"language_handled"};
        my $language;

        # Only add the record to the master list (optfile_records) if it
        # can handle at least one of the requested language.
        foreach $language (@$desired_languages)
        {
            if ($language eq "ANY" || &$language_handled_fcn($language))
            {
                push(@optfile_records, $record);
                last;
            }
        }
    }
    
    if ($#optfile_records == -1)
    {
        my $errmsg = "Error: Could not detect a compiler on local system";

        if ($automode)
        {
            $errmsg .= "\nwhich can compile the specified input file(s)";
        }
        
        die $errmsg;
    }

    my $status;
    if ($automode)
    {
        $status eq "yes";
    }
    else
    {
        print "Would you like $tool_name to locate installed compilers [y]/n? ";
        chop($status=<STDIN>);
    }

    $status = lc(substr($status, 0, 1));
    if ($status ne "n")
    { # User wants us to try to find local compilers.
        my @found_compiler_locations = ();
        my @found_compilers=();
        my $group_id;
        my @curr_group_found_compiler_locations = ();
        my @curr_group_found_compilers = ();
        
        @optfile_records = sort by_group_and_serial @optfile_records;
    
        $group_id = "";
        foreach $record (@optfile_records)
        {
            if ($record->{"group_id"} ne $group_id)
            {
                # Processing a new group; push all info from old group onto main
                # "found" lists, and clear out "curr_group" lists.
                push(@found_compiler_locations, @curr_group_found_compiler_locations);
                push(@found_compilers, @curr_group_found_compilers);
                @curr_group_found_compiler_locations = ();
                @curr_group_found_compilers = ();
                $group_id = $record->{"group_id"};
            }

            # Call the locate function for the current record:
            my $locate_fcn = $record->{"locate"};
            my @locations = &$locate_fcn;
            my $location;
            
            # The locate function can return an array of directories. Check each 
            # directory against the list of directories already identified by 
            # later records for the same group (remember, the list was sorted 
            # by group and then by serial number.) As soon as we find a directory
            # not already "claimed" by a newer/later compiler record, remember it
            # as the directory where a compiler for $record was found.
            foreach $location (@locations)
            {
                if (!is_in($location, \@curr_group_found_compiler_locations))
                {
                    push(@curr_group_found_compiler_locations, $location);
                    push(@curr_group_found_compilers, $record);
                    last;
                }
            }
        }
                
        # Push the info from the last group on the master list onto main "found" lists.
        push(@found_compiler_locations, @curr_group_found_compiler_locations);
        push(@found_compilers, @curr_group_found_compilers);
        
        my $compiler;
        if ($automode && $#found_compilers == 0)
        {
            # only one compiler found and we're in automode, so just choose it.
            $compiler = 1;
        }
        else
        {
            if ($automode)
            {
                print "Please choose your compiler ";
                if ($tool_name eq "mex") {
                    print "for building external interface (MEX) files:\n\n";
                } else {
                    print "for building standalone MATLAB applications:\n\n";
                }
            }

            print "\nSelect a compiler:\n";
            my $count = 1;
            foreach $record (@found_compilers)
            {
                print "[$count] " . $record->{"vendor_name"} . " version " . 
                    $record->{"version"} . " in $found_compiler_locations[$count-1]\n";
                $count++;
            }
            
            print "\n[0] None\n\n";
            print "Compiler: ";
            
            $compiler=&query_info(0, $count - 1, "Please select from 0-" . ($count-1), 
                                  "Compiler: ");
        
            if ($compiler == 0)
            {
                print "\n  $tool_name: No compiler selected. No action taken.\n\n";
                return;
            }
        }

        $record = $found_compilers[$compiler-1];
        $compiler_location = $found_compiler_locations[$compiler-1];
        $ask_no_questions = $automode && $#found_compilers == 0;
    }
    else
    { # User wants a list of all the compilers we know about.
        @optfile_records = sort by_vendor_and_serial @optfile_records;
    
        print "\nSelect a compiler:\n";
        my $count = 1;
        foreach $record (@optfile_records)
        {
            print "[$count] " . $record->{"vendor_name"} . " version " . 
                $record->{"version"} . "\n";
            $count++;
        }

        print "\n[0] None\n\n";
        print "Compiler: ";
        
        my $compiler=&query_info(0, $count - 1,
                                 "Please select from 0-" . ($count-1), "Compiler: ");
        
        if ($compiler == 0)
        {
            print "\n  $tool_name: No compiler selected. No action taken.\n\n";
            return;
        }
        
        $record = $optfile_records[$compiler - 1];

        # Try to be helpful by "locating" a compiler of the type selected by the user.
        # This makes an ideal default setting.
        my $locate_fcn = $record->{"locate"};
        my @locations = &$locate_fcn;
        my $chosen_location = "";

        if ($locations[0] ne "" && -e $locations[0])
        {
            print "\nYour machine has a ". $record->{"vendor_name"} .
                " compiler located at\n$locations[0]. ";
            print "Do you want to use this compiler [y]/n? ";
            chop($status=<STDIN>);
            
            if (!($status eq "n") && !($status eq "no"))
            {
                $chosen_location = $locations[0];
            }
	}
        else
        {
            print "\nThe default location for " . $record->{"vendor_name"} . 
                " compilers is " . $record->{"default_location"} .
                ",\nbut that directory does not exist on this machine. \n\n" .
                "Use " . $record->{"default_location"} ." anyway [y]/n? ";
	    chop($status=<STDIN>);
            
            $status = lc(substr($status, 0, 1));
            if ($status ne "n")
            {
                $chosen_location = $record->{"default_location"};
            }
	}
        
        if ($chosen_location eq "")
        {
            print "Please enter the location of your compiler: " .
                "[" . $record->{"default_location"} . "] ";
            chop($chosen_location = <STDIN>);
        }
        if ($chosen_location eq "")
        {
            $chosen_location = $record->{"default_location"};
        }
        $compiler_location = $chosen_location;
        $ask_no_questions = 0;
    }

    $usehg = -1;
    if ($tool_name eq "mbuild") {
	if (-e "$opts_dir\\..\\sgl.dll") {
	    if (!$automode) {
		print "Would you like to link with the C/C++ Graphics Library?([y]/n): ";
		$status=<STDIN>;
		chop $status;
		
		if ($status eq "n") {
		    $usehg = 0;
		} else {
		    $usehg = 1;
		}
	    }
	}
    } else {
	$usehg = 0;
    }

    # Now that we have a compiler selected by the user and a 
    # setup record for it, call install_options_file to copy the 
    # template options file to the correct location.
    if (!&install_options_file($tool_name, $record, $opts_dir, 
                               $compiler_location, $ask_no_questions, $usehg))
    {
        # If the record for the installed compiler has a post_setup_hook
        # entry, call it (but only if install was successful).
        my $post_setup_fcn = $record->{"post_setup_hook"};
        if ($post_setup_fcn)
        {
            &$post_setup_fcn();
        }
    }

    # Restore old $| (buffered output) setting:
    $| = $old_pipe;
}

1;

/*
 * @(#)mwutil.h    generated by: makeheader    Mon Aug 14 12:07:39 2000
 *
 *		built from:	cputime.c
 *				dconvert.c
 *				dynload.c
 *				emptystr.c
 *				enum_str.c
 *				exception.c
 *				expmatch.c
 *				f2cstr.c
 *				fgets.c
 *				filelink.c
 *				format.c
 *				fp_conv.c
 *				fpu.c
 *				getcwd.c
 *				hash.c
 *				incrfcn.c
 *				int_conv.c
 *				libm_ext.c
 *				lower.c
 *				memalloc.c
 *				memdebug.c
 *				multibyte.c
 *				mwclasses.c
 *				mwmem.c
 *				printf.c
 *				purifytools.c
 *				regexp.c
 *				set.c
 *				stacktrc.c
 *				strcat.c
 *				strcmp.c
 *				strcmpi.c
 *				strcpy.c
 *				strdup.c
 *				strlen.c
 *				strrstr.c
 *				tolower.c
 *				upper.c
 *				ut_alloca.c
 *				utassert.c
 *				utsignal.c
 *				wallclok.c
 *				array/array.c
 *				array/qa_array.c
 *				basic/basic_contexts.c
 *				basic/qa_basic.c
 *				dsbuffer/dsbuffer.c
 *				dsbuffer/qa_dsbuffer.c
 *				dtoa/bigint.c
 *				dtoa/dtoa.c
 *				dtoa/except.c
 *				dtoa/fpc.c
 *				dtoa/g_fmt.c
 *				dtoa/gen.c
 *				dtoa/ieee_dp.c
 *				dtoa/intr.c
 *				dtoa/modmin.c
 *				dtoa/os.c
 *				dtoa/pack.c
 *				dtoa/precision.c
 *				dtoa/qa_dtoa.c
 *				dtoa/qa_fpc.c
 *				dtoa/random.c
 *				dtoa/round.c
 *				dtoa/spdp.c
 *				dtoa/stress.c
 *				dtoa/testrec.c
 *				dtoa/tests.c
 *				dtoa/ulp.c
 *				err/error_context.c
 *				err/qa_error_context.c
 *				gtable/gtable.c
 *				gtable/qa_gtable.c
 *				hashtool/hashtool.c
 *				hashtool/qa_hashtools.c
 *				interval/fsi.c
 *				interval/qa_fsi.c
 *				keydata/keydata.c
 *				keydata/qa_keydata.c
 *				linebuf/linebuf.c
 *				linebuf/qa_linebuf.c
 *				mem/memory_context.c
 *				mem/qa_memory_context.c
 *				msg/message_context.c
 *				msg/qa_message_context.c
 *				nh/namehash.c
 *				nh/qa_namehash.c
 *				platform/unix.c
 *				profile/profile.c
 *				profile/qa_profile.c
 *				qa/qa_format.c
 *				qa/qa_hash.c
 *				qa/qa_memdebug.c
 *				qa/qa_mwmem.c
 *				strbuf/qa_string_buffer.c
 *				strbuf/string_buffer.c
 *				tse/qa_tse.c
 *				tse/tse.c
 *				uhash/qa_uhash.c
 *				uhash/uhash.c
 *				warn/qa_warning_context.c
 *				warn/warning_context.c
 *				modver/modver.c
 *				include/msg_typedefs.h
 *				include/err_typedefs.h
 */

#ifndef mwutil_h
#define mwutil_h

#ifdef __cplusplus
    extern "C" {
#endif


/* $Revision: 1.11 $ */
/*********************************************************************/
/*                        R C S  information                         */
/*********************************************************************/

/* $Log: msg_typedefs.h,v $
 * Revision 1.11  2000/05/31 20:52:46  pax
 * A structure named _primary_table had its first two
 * fields defined to be const int's.  C++ compilers spew warnings
 * when they see that presumably because the structure is not initalized
 * right then and there.  I don't see the purpose of these const's do I am
 * removing them.
 * Code Reviewer: RickS
 *
 * Revision 1.10  2000/03/24 15:25:56  howie
 * Backed out last submission.  Warning shows up on sbcc, but
 * not apparently in BAT.
 * Code Reviewer: BAT
 *
 * Revision 1.9  2000/03/20  14:06:15  howie
 * Fixed compiler warning for compiling with c++.
 * Code Reviewer: pax
 *
 * Revision 1.8  1999/11/12 18:31:20  mkarr
 * Enclosed all definitions in extern "C" {...}, because of function prototypes.
 *
 * Code Reviewer: Brett Baker
 *
 * Revision 1.7  1999/10/12  15:17:29  ricks
 * When implementing the code strings, I made the assumption that a
 * message context could only support one primary table.  I have since
 * been enlightened and fixed the code strings implementation such that
 * each primary table has storage for a code strings table in the
 * message context.
 * Related Records: 66856
 * Code Reviewer: John Micco
 *
 * Revision 1.6  1999/09/10  20:39:49  ricks
 * fix the macros so that the message mnemonic strings aren't defined for
 * secondary language tables
 * Code Reviewer: mike karr
 *
 * Revision 1.5  1999/08/25 13:38:04  ricks
 * Add ability to get the message mnemonic as a string.  Added new function
 * ut_get_message_mnemonic.
 * Code Reviewer: micco
 *
 * Revision 1.4  1999/08/12 21:39:19  bbaker
 * Added ut_puts_to_putsn.
 *
 * Code Reviewer: John Micco
 *
 * Revision 1.3  1999/08/05  20:00:38  ricks
 * added support for custom format specifiers %U
 *
 * Related Records: 65167
 * Code Reviewer: Mike Karr
 *
 * Revision 1.2  1999/03/31  21:25:39  scott
 * Remove MSG_END_OF_ERROR code.
 *
 * Code Reviewer: jmicco
 *
 * Revision 1.1  1999/02/25  02:01:48  jmicco
 * Initial revision
 *
 */

#ifndef msg_typedefs_h
#define msg_typedefs_h

/*
 * NOTE: In order to add a new module for error messages, please assign a new index 
 * and add to the bottom of .../src/util/include/msg_table.h
 */

/*
 * The following Macros and type definitions are for handling localized 
 * error messages.  The full details of how to use this package can
 * be found in:
 * http://www-internal.mathworks.com/devel/R12/perfect/src/util/documentation/message_context.pdf
 *
 * Please do not modify this file without making changes to the specification
 * and seeing Michael Karr or John Micco
 */ 

#ifdef __cplusplus
    extern "C" {
#endif

typedef int (*fn_puts)(const char *s, void *x);

#define _element(X) X,

#define ut_define_module_mnemonics(m) \
  enum { m##_START=m##_INDEX<<16, m##_message_mnemonics(_element) m##_END}

#define _message_mnemonic(mnemonic, string) mnemonic,
#define _message_string(mnemonic, string) string,
#define _message_mnemonic_string(mnemonic, string) #mnemonic,

#define _concat(X, Y, Z) X##Y##Z

#define _define_module_tables_(language, table, m) \
static int const _concat(table,_codes_,m)[] \
  = {  _concat(m,language,messages)(_message_mnemonic) -1}; \
static _string const _concat(table,_strings_,m)[] \
  = {  _concat(m,language,messages)(_message_string) };

#define _define_module_code_strings_(language, table, m) \
static _string const _concat(table,_code_strings_,m)[] \
  = {  _concat(m,language,messages)(_message_mnemonic_string) }; \

#define _first(X, Y) X
#define _second(X, Y) Y

#define _define_module_tables(language_and_table, m) \
  _define_module_tables_(_first language_and_table, _second language_and_table, m)
#define _define_module_code_strings(language_and_table, m) \
  _define_module_code_strings_(_first language_and_table, _second language_and_table, m)

#define _table_element_(language, table, m) _concat(table,_strings_,m),

#define _table_element(language_and_table, m) \
  _table_element_(_first language_and_table, _second language_and_table, m)

#define _values_element_(language, table, m) _concat(table,_codes_,m),

#define _values_element(language_and_table, m) \
  _values_element_(_first language_and_table, _second language_and_table, m)

#define _values_string_element_(language, table, m) _concat(table,_code_strings_,m),

#define _values_string_element(language_and_table, m) \
  _values_string_element_(_first language_and_table, _second language_and_table, m)

#define _max_code_element(table, m) m##_END - m##_START - 1,


#define _module_element(Y,X) X##_INDEX,

#define ut_define_language_tables(language, table) \
  message_modules(_define_module_tables, (language, table)) \
  static int const table##_modules[] \
    = { message_modules(_module_element, table) -1 }; \
  static _int_table const table##_codes[] \
    = { message_modules(_values_element, (language, table)) }; \
  static _string_table const table##_strings[] \
    = { message_modules(_table_element, (language, table)) }; \
  static int const table##_code_count[] \
    = { message_modules(_max_code_element, table) }

#define ut_define_primary_messages(table) \
  message_module(_define_module_tables,(_,table)) \
  message_module(_define_module_code_strings,(_,table)) \
  static _primary_table const table \
    = { message_module(_max_code_element, table) \
        message_module(_module_element, table) \
        message_module(_values_element,(_,table)) \
        message_module(_values_string_element,(_,table)) \
        message_module(_table_element,(_,table)) }

#define ut_define_secondary_messages(language, table) \
  ut_define_language_tables(_##language##_, table); \
  static _language_table const table \
    = { table##_modules, \
        table##_codes, \
        table##_strings, \
        table##_code_count }

#define msg_INDEX 0
#define msg_message_mnemonics(X) X(NO_MEMORY_FOR_MESSAGE_CONTEXT) \
X(MSG_MODULE_COUNT_MISMATCH) X(TOO_FEW_STRINGS)      X(TOO_MANY_STRINGS) X(WRONG_CODE) \
X(STRANDED_PER_CENT)     X(NON_TRIVIAL_PER_CENT) X(NON_TRIVIAL_S)    X(HOLE_NOT_PRESENT) \
X(DUPLICATE_REFERENCE)   X(ILLEGAL_PER_CENT)     X(OMITTED_HOLE)     X(BAD_MSG_CODE) \
X(MSG_MODULE_TABLE_MISMATCH) X(INVALID_PERCENT_U)

ut_define_module_mnemonics(msg);

typedef const char *_string;
typedef _string const *_string_table;
typedef int const *_int_table;

typedef struct {
  int const *modules;
  _int_table const *codes;
  _string_table const *strings;
  _int_table code_count;
} _language_table;

typedef struct {
  int code_count;
  int module;
  _int_table codes;
  _string_table code_strings;
  _string_table strings;
} _primary_table;

typedef const _language_table *language_table;
typedef const _primary_table *primary_table;

#include <stddef.h>  /* This has size_t */
#include <stdio.h>   /* required for FILE */
#include <stdarg.h>  /* required for va_list, etc. */

/*
 * _hole_type enumerator identifies the hole type (%s and %U)
 */
typedef enum {
    STANDARD_HOLE_TYPE,          /* ID for the standard hole types */
    STRING_HOLE_TYPE,            /* ID for %s string holes */
    FUNCTION_HOLE_TYPE           /* ID for %U holes */
} _hole_type;

/*
 * _hole_seen enumerator identifes the 'seen' status of a hole
 */
typedef enum {
    HOLE_NOT_SEEN,
    HOLE_SEEN
} _hole_seen;

/*
 * _hole_info - information associated with a hole - char * for a
 * string hole, a va_list for a function hole
 */
typedef struct __hole_info {
    _hole_type   hole_type;      /* the type of this hole */
    union {
	/*
	 * fields used only when adding secondary strings
	 */
        _hole_seen hole_seen;    /* seen status, used to mark this hole as visited */
	
	/*
	 * fields used only when processing messages
	 */
	char    *hole_string;    /* string for %s fields */
	va_list  hole_ap;        /* arglist for %U fields */
    } hole;
} _hole_info;

typedef struct _message_context {
  int highest_module;          /* The maximum used module index for the items in the strings_list */
  int max_module;              /* The current allocation for items in the strings_list */
  int *code_count;
  _string_table *code_strings; /* table with mneumonic code strings */
  int current_language;        /* The currently active language index */
  int max_holes;
  int max_specification;
  int max_hole_text;
  char *specification;         /* specifications for non-%s fields */
  _hole_info *hole_infos;      /* information for hole fields */
  char *hole_text;             /* text for non-%s fields */
  int secondary_count;
  const char **keys;
                               /* The 0 index is the primary table,
                                * 1..secondary_count are for secondary languages
                                */
  _string_table **strings_list;
} _message_context, *message_context;

typedef unsigned long message_code;

/* function types */
typedef void *(*fn_malloc)(size_t);
typedef void *(*fn_realloc)(void *p, size_t);
typedef void (*fn_free)(void *p);

/*
 * This is the type of a functional argument to printm.
 * Its job is to "print" a string of n characters (in practice,
 * either to a file or to message buffer).
 * Characters to print _may_ include null bytes!
 */
typedef
int (*fn_putsn)(  /* Returns number of characters printed >= 0, else some error */
  void *x,        /* "Destination" info, e.g., FILE *, or &buffer */
  const char *s,  /* Source string (ptr to chars to print) */ 
  int n           /* Number of chars to print from s */
  );

/*
 * typedef for the custom format specifier formatting function
 */
typedef
int (*fn_fmtfcn)(      /* returns the number of chars putsn'd after processing*/
  fn_putsn putsn,
  void *x,             /* destination info, e.g., FILE *, or &buffer */
  va_list *ap);        /* var args list to custom format specifier, on return
                          this is advanced past the custom format varargs */

/*
 * Below are a typedef and a function conforming to the fn_puts typedef that 
 * in turn calls a fn_putsn function, stored in the putsn_to_puts_args structure.
 */
typedef struct _putsn_to_puts_args
{
  fn_putsn putsn;
  void *   x;
} _putsn_to_puts_args, * putsn_to_puts_args;

typedef struct _puts_to_putsn_args
{
  fn_puts puts;
  void *   x;
} _puts_to_putsn_args, * puts_to_putsn_args;


typedef void (*fn_handler)( void *x, message_code code, ... );

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif


/* $Revision: 1.12 $ */
/*********************************************************************/
/*                        R C S  information                         */
/*********************************************************************/

/* $Log: err_typedefs.h,v $
 * Revision 1.12  2000/05/11  16:02:34  jmicco
 * Added an assertion that the size of the value being protected
 * was the same as a void *.  This does not work properly unless it is
 * the same size.
 * Code Reviewer: Brett Baker
 *
 * Revision 1.11  1999/12/02  21:35:37  jmicco
 * Changed the type of the callback function to call when an
 * error is detected and not caught to include an X factor.
 *
 * Code Reviewer: Michael Karr
 *
 * Revision 1.10  1999/11/16 15:38:51  jmicco
 * Made the ut_assert() macro variants reference their first
 * argument when asserts are off to avoid "unreferenced" warnings about
 * arguments in functions that only use the argument to assert.  Also,
 * this fixes the problem with (ut_errassert(...), x) used for
 * initialzation
 *
 * Code Reviewer: Michael Karr
 *
 * Revision 1.9  1999/11/12 18:31:26  mkarr
 * Move the common typedef to _protect_value_common.
 *
 * Code Reviewer: Brett Baker
 *
 * Revision 1.8  1999/07/30  22:02:52  jmicco
 * Made the -check_malloc memory allocator align pointers on 8-byte boundaries
 *
 * Code Reviewer: TBRB Scott
 *
 * Revision 1.7  1999/07/30 20:11:59  jmicco
 * Added ut_errassertalways()
 *
 * Code Reviewer: Scott French
 *
 * Revision 1.6  1999/06/25 12:22:43  pfry
 * Sol2 C++ wants typedefs outside of casts. Create a temp typedef in the
 * protecxt macros to make it happy.
 * Code Reviewer: jmicco,bbaker
 *
 * Revision 1.5  1999/04/01  03:02:58  scott
 * Change catch field in try_catch_list to catch_fcn, as catch
 * is reserved in C++ and some of our source code is implemented
 * as .cpp files.
 *
 * Revision 1.4  1999/03/31  21:25:38  scott
 * Remove END_OF_ERROR code, add ERR_RETHROW and ERR_SIGNAL_INTERRUPT.
 * Add fn_error_handler typedef.
 * Add an fn_error_handler to error_context typedef.
 *
 * Code Reviewer: jmicco
 *
 * Revision 1.3  1999/03/11  13:14:17  jmicco
 * Fixed the use of ut_unprotect to include the tag so that we can use -Wshadow
 * with the gcc compiler.
 * Code Reviewer: Brett Baker
 *
 * Revision 1.2  1999/03/10  19:04:33  jmicco
 * Removed warnings about _error_context_link being multiply-defined
 *
 * Code Reviewer: Brett Baker
 *
 * Revision 1.1  1999/02/25 02:01:49  jmicco
 * Initial revision
 *
 */

#ifndef err_typedefs_h
#define err_typedefs_h
#include <setjmp.h>

/*
 * The following Macros and type definitions are for handling 
 * errors.  The full details of how to use this package can
 * be found in:
 * http://www-internal.mathworks.com/devel/R12/perfect/src/util/documentation/error_context.pdf
 *
 * Please do not modify this file without making changes to the specification
 * and seeing Michael Karr or John Micco
 */ 

#define err_INDEX 1
#define err_message_mnemonics(X) X(ASSERTION_FAULT) X(INCORRECT_MAGIC) \
X(ERR_RETHROW) X(ERR_SIGNAL_INTERRUPT)
ut_define_module_mnemonics(err);
#define ERR_NO_ERROR 0

/* types */
typedef void (*fn_protectv)(void *);
typedef void (*fn_protectxv)( void *, void *);

#define ut_declare_protect_function(f, t) void (*f)(t)
#define ut_declare_protectx_function(f, t1, t2) void (*f)(t1, t2)

#define _protect_list_common_fields(t) \
  struct _generic_protect_list *next; /* should come first for more efficient reference */ \
  t *p;

#define _protect_list_common( t, t1)  { \
  _protect_list_common_fields(t) \
  ut_declare_protect_function(f, t1); \
}

typedef struct _generic_protect_list _protect_list_common( void *, void *)
  *generic_protect_list;

#define _protect_list(t, t1) struct _protect_list_common( t, t1)

/* The f field is deliberately put in a different position in the the following type,
   to maximize catastrophe if the wrong type is used.  */
#define _protectx_list(t, t1, t2) struct { \
  _protect_list_common_fields(t) \
  t1 x; /* the first argument to f */ \
  ut_declare_protectx_function(f, t1, t2); \
}

typedef _protectx_list(void *, void *, void *) *generic_protectx_list;

typedef void (*fn_error_handler)(void *x, int status);

typedef struct _error_context {
  generic_protect_list top; /* should come first for more efficient reference */
  struct _try_catch_list *try_catch_top;
  struct _try_catch_list *active_catch;
  message_context msg;
  fn_putsn putsn;
  void *x; /* the first argument to putsn */
  fn_error_handler error_handler;
  void *xerr; /* The first argument to error_handler */
} _error_context, *error_context;

typedef void (*try_function)(error_context err, void *p);
typedef int (*catch_function)(error_context err, void *p, message_code code, va_list ap);

typedef struct _try_catch_list {
  struct _try_catch_list *next;
  generic_protect_list top;
  void *p;
  catch_function catch_fcn;
  message_code code;
  jmp_buf label;
} _try_catch_list, *try_catch_list;

/* macros */

#define ut_errassertalways(err, condition) (condition) ? (void)0 : ut_fault(err, #condition, __FILE__, __LINE__) 

#ifndef NDEBUG
#define ut_assert_fault(err, condition) ut_fault(err, condition, __FILE__, __LINE__)
#define ut_errassert(err, condition) (condition) ? (void)0 : ut_assert_fault(err, #condition)
#define NNDEBUGC(X) X,
#define NNDEBUG(X) X
#define YNDEBUG(X)
#define YNNDEBUG(X) 
#else
#define ut_assert_fault(err, condition) ((void) err)
#define ut_errassert( err, condition ) ((void) err)
#define NNDEBUGC(X)
#define NNDEBUG(X)
#define YNDEBUG(X) X
#define YNNDEBUG(X) X, 
#endif


#if (defined(DEBUG) || (defined(DEBUG_ERROR_CONTEXT) && DEBUG_ERROR_CONTEXT != 0))
#undef DEBUG_ERROR_CONTEXT
#define DEBUG_ERROR_CONTEXT(X) X
#else
#undef DEBUG_ERROR_CONTEXT
#define DEBUG_ERROR_CONTEXT(X)
#endif

#define _protect_value_common(err, type, value, protectfn, _list, tag)  \
  typedef void (*ut_fn_protect_##tag)(type);                            \
  DEBUG_ERROR_CONTEXT(generic_protect_list _local_top##tag;)            \
  _list _error_context_link##tag;                                       \
  _error_context_link##tag.next = (err)->top;                           \
  _error_context_link##tag.p = value;                                   \
  ut_errassert(err, sizeof(type)==sizeof(void *));                      \
  _error_context_link##tag.f = protectfn;

#define _protect_common(err, type, name, value, protectfn, _list, tag)  \
  type name = value;                                                    \
  _protect_value_common(err, type, &name, protectfn, _list, tag)

#define LOCAL_TOP(tag) DEBUG_ERROR_CONTEXT(_local_top##tag =)

#define ut_protect(err, type, name, value, protectfn) {                                 \
  _protect_common(err, type, name, value, protectfn, _protect_list(type, type), name )  \
  (err)->top = LOCAL_TOP(name) (generic_protect_list)&_error_context_link##name;

#define ut_protectv(err, type, name, value, protectfn) {                                 \
  _protect_common(err, type, name, value, protectfn, _protect_list(type, void *), name ) \
  (err)->top = LOCAL_TOP(name) (generic_protect_list)&_error_context_link##name;

#define ut_protectx(err, type, name, value, protectfn, typex, protectx) {                  \
  _protect_common(err, type, name, value,                                                  \
                  protectfn, _protectx_list(type, typex, type),name)                       \
  _error_context_link##name.x = protectx;                                                  \
  (err)->top                                                                               \
    = LOCAL_TOP(name) (generic_protect_list)((unsigned long)&_error_context_link##name | 1);

#define ut_protectxv(err, type, name, value, protectfn, typex, protectx) {              \
  _protect_common(err, type, name, value,                                               \
                  protectfn, _protectx_list(type, typex, void *), name)                 \
  _error_context_link##name.x = protectx;                                               \
  (err)->top = LOCAL_TOP(name)                                                          \
                 (generic_protect_list)((unsigned long)&_error_context_link##name | 1);

#define ut_protect_value(err, type, value, protectfn) {                                    \
  _protect_value_common(err, type, &(value), protectfn, _protect_list(type, type), value ) \
  (err)->top = LOCAL_TOP(value) (generic_protect_list)&_error_context_link##value;

#define ut_protectv_value(err, type, value, protectfn) {                                \
  _protect_value_common(err, type, &(value),                                            \
                        protectfn, _protect_list(type, void *), value )                 \
  (err)->top = LOCAL_TOP(value) (generic_protect_list)&_error_context_link##value;

#define ut_protectx_value(err, type, value, protectfn, typex, protectx) {                \
  _protect_value_common(err, type, &(value), protectfn,                                  \
                        _protectx_list(type, typex, type), value)                        \
  _error_context_link##value.x = protectx;                                               \
  (err)->top = LOCAL_TOP(value)                                                          \
                 (generic_protect_list)((unsigned long)&_error_context_link##value | 1);

#define ut_protectxv_value(err, type, value, protectfn, typex, protectx) {               \
  _protect_value_common(err, type, &(value),                                             \
                        protectfn, _protectx_list(type, typex, void *), value)           \
  _error_context_link##value.x = protectx;                                               \
  (err)->top = LOCAL_TOP(value)                                                          \
                 (generic_protect_list)((unsigned long)&_error_context_link##value | 1);

#define ut_protect_value_tag(err, type, value, protectfn, tag) {                         \
  _protect_value_common(err, type, &(value), protectfn, _protect_list(type, type), tag ) \
 (err)->top = LOCAL_TOP(tag) (generic_protect_list)&_error_context_link##tag;

#define ut_protectv_value_tag(err, type, value, protectfn, tag) {                          \
  _protect_value_common(err, type, &(value), protectfn, _protect_list(type, void *), tag ) \
  (err)->top = LOCAL_TOP(tag) (generic_protect_list)&_error_context_link##tag;

#define ut_protectx_value_tag(err, type, value, protectfn, typex, protectx, tag) {        \
  _protect_value_common(err, type, &(value),                                              \
                        protectfn, _protectx_list(type, typex, type), tag)                \
  _error_context_link##tag.x = protectx;                                                  \
 (err)->top                                                                               \
   = LOCAL_TOP(tag) (generic_protect_list)((unsigned long)&_error_context_link##tag | 1);

#define ut_protectxv_value_tag(err, type, value, protectfn, typex, protectx, tag) {       \
 _protect_value_common(err, type, &(value),                                               \
                       protectfn, _protectx_list(type, typex, void *), tag)               \
 _error_context_link##tag.x = protectx;                                                   \
 (err)->top                                                                               \
   = LOCAL_TOP(tag) (generic_protect_list)((unsigned long)&_error_context_link##tag | 1);

#define ut_cast_to_generic_protectx_list(p) (generic_protectx_list)((unsigned long)(p) ^ 1)

#define ut_preserve(err,tag) (err)->top = (err)->top->next
#define ut_destroy(err,tag) { \
  register error_context err_ = err; \
  err_->top->f(*(err_->top->p)); \
  ut_preserve(err_,tag); \
  } (void)0
#define ut_preservex(err,tag) (err)->top = (ut_cast_to_generic_protectx_list((err)->top))->next
#define ut_destroyx(err,tag) { \
  register generic_protectx_list px = ut_cast_to_generic_protectx_list((err)->top); \
  (err)->top = px->next; \
  px->f(px->x, *(px->p)); \
  } (void)0

#define _fast_ut_preserve(err,tag)
#define _fast_ut_destroy(err,tag) _error_context_link##tag.f(*_error_context_link##tag.p);
#define _fast_ut_preservex(err,tag)
#define _fast_ut_destroyx(err,tag) \
  _error_context_link##tag.f(_error_context_link##tag.x, *(_error_context_link##tag.p));
#define _incorrect_magic(err,tag) \
  if (_local_top##tag != (err)->top) { \
    (err)->top = _local_top##tag; \
    ut_error(err, INCORRECT_MAGIC, __FILE__, __LINE__); \
  }

#define ut_unprotect_unreachable } 

#define ut_unprotect(err, tag, magic) \
  DEBUG_ERROR_CONTEXT(_incorrect_magic(err,tag)) \
  (err)->top = _error_context_link##tag.next; \
  _fast_##magic(err,tag) \
}

#define ut_unprotect_and_return(err, tag, magic, expr) \
  DEBUG_ERROR_CONTEXT(_incorrect_magic(err,tag)) \
  (err)->top = _error_context_link##tag.next; \
  _fast_##magic(err,tag) \
  return expr; \
}

#define ut_protect_f _error_context_link.f

#define ut_prevent_further_cleanup(err) { \
  _try_catch_list _link; \
  ut_prevent_further_cleanup_fcn(err, &_link);

#define ut_allow_further_cleanup(err) \
  ut_allow_further_cleanup_fcn(err, &_link); \
}
 
#endif

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* mwutil_h */

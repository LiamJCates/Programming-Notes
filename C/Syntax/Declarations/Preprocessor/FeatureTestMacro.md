The exact set of features available when you compile a source file is controlled by which
feature test macros you define.
If you compile your programs using ‘gcc -ansi’, you get only the ISO C library features,
unless you explicitly request additional features by defining one or more of the feature
macros. See Section “GNU CC Command Options” in The GNU CC Manual, for more
information about GCC options.
Chapter 1: Introduction 16
You should define these macros by using ‘#define’ preprocessor directives at the top of
your source code files. These directives must come before any #include of a system header
file. It is best to make them the very first thing in the file, preceded only by comments. You
could also use the ‘-D’ option to GCC, but it’s better if you make the source files indicate
their own meaning in a self-contained way.
This system exists to allow the library to conform to multiple standards. Although the
different standards are often described as supersets of each other, they are usually incompatible because larger standards require functions with names that smaller ones reserve to
the user program. This is not mere pedantry — it has been a problem in practice. For
instance, some non-GNU programs define functions named getline that have nothing to
do with this library’s getline. They would not be compilable if all features were enabled
indiscriminately.
This should not be used to verify that a program conforms to a limited standard. It is
insufficient for this purpose, as it will not protect you from including header files outside
the standard, or relying on semantics undefined within the standard.
_POSIX_SOURCE [Macro]
If you define this macro, then the functionality from the POSIX.1 standard (IEEE
Standard 1003.1) is available, as well as all of the ISO C facilities.
The state of _POSIX_SOURCE is irrelevant if you define the macro _POSIX_C_SOURCE
to a positive integer.
_POSIX_C_SOURCE [Macro]
Define this macro to a positive integer to control which POSIX functionality is made
available. The greater the value of this macro, the more functionality is made available.
If you define this macro to a value greater than or equal to 1, then the functionality
from the 1990 edition of the POSIX.1 standard (IEEE Standard 1003.1-1990) is made
available.
If you define this macro to a value greater than or equal to 2, then the functionality
from the 1992 edition of the POSIX.2 standard (IEEE Standard 1003.2-1992) is made
available.
If you define this macro to a value greater than or equal to 199309L, then the functionality from the 1993 edition of the POSIX.1b standard (IEEE Standard 1003.1b-1993)
is made available.
If you define this macro to a value greater than or equal to 199506L, then the functionality from the 1995 edition of the POSIX.1c standard (IEEE Standard 1003.1c-1995)
is made available.
If you define this macro to a value greater than or equal to 200112L, then the functionality from the 2001 edition of the POSIX standard (IEEE Standard 1003.1-2001)
is made available.
If you define this macro to a value greater than or equal to 200809L, then the functionality from the 2008 edition of the POSIX standard (IEEE Standard 1003.1-2008)
is made available.
Chapter 1: Introduction 17
Greater values for _POSIX_C_SOURCE will enable future extensions. The POSIX standards process will define these values as necessary, and the GNU C Library should support them some time after they become standardized. The 1996 edition of POSIX.1
(ISO/IEC 9945-1: 1996) states that if you define _POSIX_C_SOURCE to a value greater
than or equal to 199506L, then the functionality from the 1996 edition is made available. In general, in the GNU C Library, bugfixes to the standards are included when
specifying the base version; e.g., POSIX.1-2004 will always be included with a value
of 200112L.
_XOPEN_SOURCE [Macro]
_XOPEN_SOURCE_EXTENDED [Macro]
If you define this macro, functionality described in the X/Open Portability Guide is
included. This is a superset of the POSIX.1 and POSIX.2 functionality and in fact
_POSIX_SOURCE and _POSIX_C_SOURCE are automatically defined.
As the unification of all Unices, functionality only available in BSD and SVID is also
included.
If the macro _XOPEN_SOURCE_EXTENDED is also defined, even more functionality is
available. The extra functions will make all functions available which are necessary
for the X/Open Unix brand.
If the macro _XOPEN_SOURCE has the value 500 this includes all functionality described
so far plus some new definitions from the Single Unix Specification, version 2. The
value 600 (corresponding to the sixth revision) includes definitions from SUSv3, and
using 700 (the seventh revision) includes definitions from SUSv4.
_LARGEFILE_SOURCE [Macro]
If this macro is defined some extra functions are available which rectify a few shortcomings in all previous standards. Specifically, the functions fseeko and ftello are
available. Without these functions the difference between the ISO C interface (fseek,
ftell) and the low-level POSIX interface (lseek) would lead to problems.
This macro was introduced as part of the Large File Support extension (LFS).
_LARGEFILE64_SOURCE [Macro]
If you define this macro an additional set of functions is made available which enables
32 bit systems to use files of sizes beyond the usual limit of 2GB. This interface is
not available if the system does not support files that large. On systems where the
natural file size limit is greater than 2GB (i.e., on 64 bit systems) the new functions
are identical to the replaced functions.
The new functionality is made available by a new set of types and functions which
replace the existing ones. The names of these new objects contain 64 to indicate the
intention, e.g., off_t vs. off64_t and fseeko vs. fseeko64.
This macro was introduced as part of the Large File Support extension (LFS). It is
a transition interface for the period when 64 bit offsets are not generally used (see
_FILE_OFFSET_BITS).
_FILE_OFFSET_BITS [Macro]
This macro determines which file system interface shall be used, one replacing the
other. Whereas _LARGEFILE64_SOURCE makes the 64 bit interface available as an
Chapter 1: Introduction 18
additional interface, _FILE_OFFSET_BITS allows the 64 bit interface to replace the
old interface.
If _FILE_OFFSET_BITS is undefined, or if it is defined to the value 32, nothing changes.
The 32 bit interface is used and types like off_t have a size of 32 bits on 32 bit
systems.
If the macro is defined to the value 64, the large file interface replaces the old interface. I.e., the functions are not made available under different names (as they are
with _LARGEFILE64_SOURCE). Instead the old function names now reference the new
functions, e.g., a call to fseeko now indeed calls fseeko64.
This macro should only be selected if the system provides mechanisms for handling
large files. On 64 bit systems this macro has no effect since the *64 functions are
identical to the normal functions.
This macro was introduced as part of the Large File Support extension (LFS).
_ISOC99_SOURCE [Macro]
If this macro is defined, features from ISO C99 are included. Since these features are
included by default, this macro is mostly relevant when the compiler uses an earlier
language version.
_ISOC11_SOURCE [Macro]
If this macro is defined, ISO C11 extensions to ISO C99 are included.
_ISOC2X_SOURCE [Macro]
If this macro is defined, ISO C2X extensions to ISO C11 are included. Only some
features from this draft standard are supported by the GNU C Library.
__STDC_WANT_LIB_EXT2__ [Macro]
If you define this macro to the value 1, features from ISO/IEC TR 24731-2:2010
(Dynamic Allocation Functions) are enabled. Only some of the features from this TR
are supported by the GNU C Library.
__STDC_WANT_IEC_60559_BFP_EXT__ [Macro]
If you define this macro, features from ISO/IEC TS 18661-1:2014 (Floating-point
extensions for C: Binary floating-point arithmetic) are enabled. Only some of the
features from this TS are supported by the GNU C Library.
__STDC_WANT_IEC_60559_FUNCS_EXT__ [Macro]
If you define this macro, features from ISO/IEC TS 18661-4:2015 (Floating-point
extensions for C: Supplementary functions) are enabled. Only some of the features
from this TS are supported by the GNU C Library.
__STDC_WANT_IEC_60559_TYPES_EXT__ [Macro]
If you define this macro, features from ISO/IEC TS 18661-3:2015 (Floating-point
extensions for C: Interchange and extended types) are enabled. Only some of the
features from this TS are supported by the GNU C Library.
_GNU_SOURCE [Macro]
If you define this macro, everything is included: ISO C89, ISO C99, POSIX.1,
POSIX.2, BSD, SVID, X/Open, LFS, and GNU extensions. In the cases where
POSIX.1 conflicts with BSD, the POSIX definitions take precedence.
Chapter 1: Introduction 19
_DEFAULT_SOURCE [Macro]
If you define this macro, most features are included apart from X/Open, LFS and
GNU extensions: the effect is to enable features from the 2008 edition of POSIX,
as well as certain BSD and SVID features without a separate feature test macro to
control them.
Be aware that compiler options also affect included features:
• If you use a strict conformance option, features beyond those from the compiler’s
language version will be disabled, though feature test macros may be used to
enable them.
• Features enabled by compiler options are not overridden by feature test macros.
_ATFILE_SOURCE [Macro]
If this macro is defined, additional *at interfaces are included.
_FORTIFY_SOURCE [Macro]
If this macro is defined to 1, security hardening is added to various library functions.
If defined to 2, even stricter checks are applied.
_REENTRANT [Macro]
_THREAD_SAFE [Macro]
These macros are obsolete. They have the same effect as defining _POSIX_C_SOURCE
with the value 199506L.
Some very old C libraries required one of these macros to be defined for basic functionality (e.g. getchar) to be thread-safe.
We recommend you use _GNU_SOURCE in new programs. If you don’t specify the ‘-ansi’
option to GCC, or other conformance options such as -std=c99, and don’t define any of
these macros explicitly, the effect is the same as defining _DEFAULT_SOURCE to 1.
When you define a feature test macro to request a larger class of features, it is harmless
to define in addition a feature test macro for a subset of those features. For example, if you
define _POSIX_C_SOURCE, then defining _POSIX_SOURCE as well has no effect. Likewise, if
you define _GNU_SOURCE, then defining either _POSIX_SOURCE or _POSIX_C_SOURCE as well
has no effect.

The GNU C Library includes severalheader files, each of which provides definitions anddeclarations for a group of related facilities; this information is used by the C compilerwhen processing your program. For example, the header filestdio.hdeclares facilitiesfor performing input and output, and the header filestring.h declares string processing utilities.



Libraries for use by C programs really consist of two parts: header files that define types and macros and declare variables and functions; and the actual library or archive that contains the definitions of the variables and functions.

(Recall that in C, a declaration merely provides information that a function or variable exists and gives its type. For a function declaration, information about the types of its arguments might be provided as well.

The purpose of declarations is to allow the compiler to correctly process references to the declared variables and functions. A definition, on the
other hand, actually allocates storage for a variable or says what a function does.)

In order to use the facilities in the GNU C Library, you should be sure that your program source files include the appropriate header files. This is so that the compiler has declarations of these facilities available and can correctly process references to them. Once your program has been compiled, the linker resolves these references to the actual definitions provided in the archive file.

Header files are included into a program source file by the ‘#include’ preprocessor directive. The C language supports two forms of this directive; the first,

#include "header"

is typically used to include a header file header that you write yourself; this would contain definitions and declarations describing the interfaces between the different parts of your particular application. By contrast,

#include <file.h>

is typically used to include a header file file.h that contains definitions and declarations for a standard library. This file would normally be installed in a standard place by your system administrator. You should use this second form for the C library header files. Typically, ‘#include’ directives are placed at the top of the C source file, before any other code. If you begin your source files with some comments explaining what the code in the file does (a good idea), put the ‘#include’ directives immediately afterwards, following the feature test macro definition.

For more information about the use of header files and ‘#include’ directives, see Section “Header Files” in The GNU C Preprocessor Manual. The GNU C Library provides several header files, each of which contains the type and macro definitions and variable and function declarations for a group of related facilities. This means that your programs may need to include several header files, depending on exactly which facilities you are using. Some library header files include other library header files automatically. However, as a matter of programming style, you should not rely on this; it is better to explicitly include all the header files required for the library facilities you are using. The GNU C Library header files have been written in such a way that it doesn’t matter if a header file is accidentally included more than once; including a header file a second time has no effect. Likewise, if your program needs to include multiple header files, the order in which they are included doesn’t matter.

Compatibility Note:
Inclusion of standard header files in any order and any number of times works in any ISO C implementation. However, this has traditionally not been the case in many older C implementations. Strictly speaking, you don’t have to include a header file to use a function it declares; you could declare the function explicitly yourself, according to the specifications in this manual. But it is usually better to include the header file because it may define types and macros that are not otherwise available and because it may define more efficient macro replacements for some functions. It is also a sure way to have the correct declaration.













The standard headers <limits.h> and <float.h> contain
symbolic constants for float, double and long double of all three sizes.








The standard header <ctype. h>, described in Appendix B, defines a family
of functions that provide tests and conversionsthat are independent of character
set.



In general, mathematical functions like those in <math.h> will use the double precision type

The names of all library types, macros, variables and functions that come from the ISO C standard are reserved unconditionally; your program may not redefine these names.

All other library names are reserved if your program explicitly includes the header file that defines or declares them.

There are several reasons for these restrictions:
• Other people reading your code could get very confused if you were using a function named exit to do something completely different from what the standard exit function does, for example. Preventing this situation helps to make your programs easier to understand and contributes to modularity and maintainability.

• It avoids the possibility of a user accidentally redefining a library function that is called by other library functions. If redefinition were allowed, those other functions would not work properly.

• It allows the compiler to do whatever special optimizations it pleases on calls to these functions, without the possibility that they may have been redefined by the user. Some library facilities, such as those for dealing with variadic arguments and non-local exits, actually require a considerable amount of cooperation on the part of the C compiler, and with respect to the implementation, it might be easier for the compiler to treat these as built-in parts of the language.

In addition to the names documented in this manual, reserved names include all external identifiers (global functions and variables) that begin with an underscore (‘_’) and all identifiers regardless of use that begin with either two underscores or an underscore followed by a capital letter are reserved names. This is so that the library and header files can define
functions, variables, and macros for internal purposes without risk of conflict with names in user programs.


Some additional classes of identifier names are reserved for future extensions to the C language or the POSIX.1 environment. While using these names for your own purposes right now might not cause a problem, they do raise the possibility of conflict with future versions of the C or POSIX standards, so you should avoid these names.

• Names beginning with a capital ‘E’ followed a digit or uppercase letter may be used for additional error code names.

• Names that begin with either ‘is’ or ‘to’ followed by a lowercase letter may be used for additional character testing and conversion functions.

• Names that begin with ‘LC_’ followed by an uppercase letter may be used for additional macros specifying locale attributes.

• Names of all existing mathematics functions, suffixed with ‘f’ or ‘l’ are reserved for corresponding functions that operate on float and long double arguments, respectively.

• Names that begin with ‘SIG’ followed by an uppercase letter are reserved for additional signal names.

• Names that begin with ‘SIG_’ followed by an uppercase letter are reserved for additional signal actions.

• Names beginning with ‘str’, ‘mem’, or ‘wcs’ followed by a lowercase letter are reserved for additional string and array functions.

• Names that end with ‘_t’ are reserved for additional type names.

In addition, some individual header files reserve names beyond those that they actually define. You only need to worry about these restrictions if your program includes that particular header file.

• The header file dirent.h reserves names prefixed with ‘d_’.

• The header file fcntl.h reserves names prefixed with ‘l_’, ‘F_’, ‘O_’, and ‘S_’.

• The header file grp.h reserves names prefixed with ‘gr_’.

• The header file limits.h reserves names suffixed with ‘_MAX’.

• The header file pwd.h reserves names prefixed with ‘pw_’.

• The header file signal.h reserves names prefixed with ‘sa_’ and ‘SA_’.

• The header file sys/stat.h reserves names prefixed with ‘st_’ and ‘S_’.

• The header file sys/times.h reserves names prefixed with ‘tms_’.

• The header file termios.h reserves names prefixed with ‘c_’, ‘V’, ‘I’, ‘O’, and ‘TC’; and names prefixed with ‘B’ followed by a digit.

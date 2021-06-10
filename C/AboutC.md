This section discusses the various standards and other sources that the GNU C Library isbased upon. These sources include the ISO C and POSIX standards, and the System Vand Berkeley Unix implementations.


The GNU C Library is compatible with the C standard adopted by the American Na-tional Standards Institute (ANSI):American National Standard X3.159-1989—“ANSI C”and later by the International Standardization Organization (ISO):ISO/IEC 9899:1990,“Programming languages—C”. We here refer to the standard as ISO C since this is themore general standard in respect of ratification. The header files and library facilities thatmake up the GNU C Library are a superset of those specified by the ISO C standard.If you are concerned about strict adherence to the ISO C standard, you should use the‘-ansi’ option when you compile your programs with the GNU C compiler. This tells the compiler to define only ISO standard features from the library header files, unless you explicitly ask for additional features.


The GNU C Library is also compatible with the ISOPOSIX family of standards, knownmore formally as thePortable Operating System Interface for Computer Environments(ISO/IEC 9945). They were also published as ANSI/IEEE Std 1003. POSIX is derived mostly from various versions of the Unix operating system. The library facilities specified by the POSIX standards are a superset of those requiredby ISO C; POSIX specifies additional features for ISO C functions, as well as specifying new additional functions. In general, the additional requirements and functionality definedby the POSIX standards are aimed at providing lower-level support for a particular kind of operating system environment, rather than general programming language support which can run in many diverse operating system environments. The GNU C Library implements all of the functions specified in ISO/IEC 9945-1:1996, the POSIX System Application Program Interface, commonly referred to as POSIX.1. The primary extensions to the ISO C facilities specified by this standard include file system interface primitives, device-specific ter-minal control functions, and process control functions. Some facilities from ISO/IEC 9945-2:1993, the POSIX Shell and Utilities standard (POSIX.2) are also implemented in the GNU C Library. These include utilities for deal-ing with regular expressions and other pattern matching facilities.



Features of C Programming Language:

    Procedural Language
    Fast and Efficient
    Modularity
    Statically Type
    General Purpose Language
    Rich set of built in Operators
    Libraries with rich Functions
    Middle Level Language
    Portability
    Easy to Extend

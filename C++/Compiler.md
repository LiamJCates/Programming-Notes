The Compiler Tool Chain
After writing the source code for a C++ program, the next step is to turn
your source code into an executable program. The compiler tool chain (or
tool chain) is a collection of three elements that run one after the other to
convert source code into a program:

1. The preprocessor performs basic source code manipulation. For
example, #include <cstdio> u is a directive that instructs the preprocessor to include information about the cstdio library directly into
your program’s source code. When the preprocessor finishes processing a source file, it produces a single translation unit. Each translation
unit is then passed to the compiler for further processing.

2. The compiler reads a translation unit and generates an object file. Object
files contain an intermediate format called object code. These files contain data and instructions in an intermediate format that most humans
wouldn’t understand. Compilers work on one translation unit at a time,
so each translation unit corresponds to a single object file.

3. The linker generates programs from object files. Linkers are also
responsible for finding the libraries you’ve included within your
source code. When you compile Listing 1-1, for example, the linker
will find the cstdio library and include everything your program
needs to use the printf function. Note that the cstdio header is distinct from the cstdio library. The header contains information about
how to use the library.

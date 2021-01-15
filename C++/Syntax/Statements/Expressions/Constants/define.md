## Defining Constants Using #define

First and foremost, don’t use this if you are writing a program anew. The only reason we analyze the definition of constants using #define is to help you understand certain legacy programs that do define constants such as pi using this syntax:

  #define pi 3.14286

This is a preprocessor macro, and what is done here is that all mentions of pi
henceforth are replaced by 3.14286 for the compiler to process. Note that this is a text replacement (read: non-intelligent replacement) done by the preprocessor. The compiler neither knows nor cares about the actual type of the constant in question.

Defining constants using the preprocessor via #define is deprecated and should not be used.

For more information regarding the preprocessor, see:
[C++\Syntax\Statements\Declarations\PreprocessorDirectives.md]

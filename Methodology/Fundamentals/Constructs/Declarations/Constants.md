Constants
Generally, a constant is a named piece of memory with a value that cannot be changed during normal execution, i.e., while a program runs.

When associated with an identifier, a constant is said to be "named," although the terms "constant" and "named constant" are often used interchangeably. This is contrasted with a variable, which is an identifier with a value that can be changed during normal execution, i.e., the value is variable

Constants are used for values that are unlikely to change, for example:
PI ← 3.142

Constants are useful because they are declared and assigned once, but can be referred to over and over again throughout the program. This means that if the programmer needs to change the value throughout the program code, they only need to make one change. This can help make a program easier to maintain.

Constants follow the same naming conventions as variables, except that they are often written in uppercase.

Some programming languages, such as Python, do not support constants.







There are several common ways to express a data value that doesn't change during program execution that are consistent across a wide variety of programming languages:
  Literals
  Macros
  Constant Variable

Literals
One very basic way is by simply writing a literal number, character, or string into the program code

a literal is a notation for representing a fixed value in source code.

Literals come with a cost, however this can



Another way is by defining a symbolic macro. Many high-level programming languages, and many assemblers, offer a macro facility where the programmer can define, generally at the beginning of a source file or in a separate definition file, names for different values. A preprocessor then replaces these names with the appropriate values before compiling, resulting in something functionally identical to using literals, with the speed advantages of immediate mode. Because it can be difficult to maintain code where all values are written literally, if a value is used in any repetitive or non-obvious way, it is often done as a macro.

A third way is by declaring and defining a variable as being "constant". A global or static variable can be declared (or a symbol defined in assembly) with a keyword qualifier such as const, constant, or final, meaning that its value will be set at compile time and should not be changeable at runtime. Compilers generally put static constants in the text section of an object file along with the code itself, as opposed to the data section where non-const initialized data is kept. Some compilers can produce a section specifically dedicated to constants. Memory protection can be applied to this area to prevent overwriting of such constants by errant pointers.

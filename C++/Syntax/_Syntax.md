Programming language: A set of tokens and their rules which enable you to write programs to solve problems.

To write meaningful programs, you must learn the programming language’s tokens and their syntax and semantic rules.
  syntax rules determine which statements (instructions) are legal or valid.
  semantic rules determine the meaning of the instructions.





## Tokens
The smallest individual unit of a program written in any language is called a token.

C++’s tokens are divided into special symbols, reserved word symbols, and identifiers.



### Special Symbols
The symbols that are used in C/C++ with some special meaning and for some specific function are called as Special Symbols.

The special symbols being used with context to programming language are illustrated below as:

Brackets []: These opening and closing brackets are used as array element reference. These are used to indicate single & multidimensional subscripts.
Braces {}: Opening and closing curly braces are used to mark start and end of a block of code containing more than one statement.
Comma , : To separate more than one statement, Comma is used for example in for loop comma separates initialization, condition & increment.
Semicolon ; : Used at the end of statements for termination.
Parenthesis () : Are used to indicate function parameters & function calls.
Asterisk * : This special symbol is used to create a pointer variable.
Preprocessor ( # ): This you must have seen attached with the header files. This is automatically used by the compiler to transform your program before actual compilation.
Tilde ~ : We use the tilde symbol as a destructor to free memory
Operators: tools or symbols which are used to perform a specific operation on data. Operations are performed on operands.



### Reserved Words (Keywords)
The keywords are the reserved terms in any programming language. Every keyword in the language is expected to provide an intended functionality to the program. We cannot use the keywords  as variable names because this practice tries to assign a new meaning to the keyword which is not appreciated nor allowed in any programming language. However, the C/C++ pre-processor directives (so-called header files) can be used to specify text to be exchanged for keywords before compilation.

Reserved word symbols include the following:
asm, else, new, this, auto, enum, operator, throw, bool, explicit, private, true, break, export, protected, try, case, extern, public, typedef, catch, false, register, typeid, char, float, reinterpret_cast, typename, class, for, return, union, const, friend, short, unsigned, constexpr, goto, signed, using, continue, if, sizeof, virtual, default, inline, static, void, delete, int, static_cast, volatile, do, long, struct, wchar_t, double, mutable, switch, while, dynamic_cast, namespace, template, and, bitor, not_eq, xor, and_eq, compl, or, xor_eq, bitand, not, or_eq

The letters that make up a reserved word are always lowercase. Like the special symbols, each is considered to be a single symbol. Furthermore, reserved words cannot be redefined within any program; that is, they cannot be used for anything other than their intended use.



### Identifiers
Identifiers are names of things that appear in programs, such as variables, constants, and functions.

All identifiers must obey C++’s rules for identifiers.

A C++ identifier consists of letters, digits, and the underscore character (_) and must begin with a letter or underscore.

Some identifiers are predefined; others are defined by the user.

C++ is case sensitive—uppercase and lowercase letters are considered different. Thus, the identifier NUMBER is not the same as the identifier number. Similarly, the identifiers X and x are different.

In C++, identifiers can be of any length.





## Whitespace
Every C++ program contains whitespaces. Whitespaces include blanks, tabs, and
newline characters. In a C++ program, whitespaces are used to separate special
symbols, reserved words, and identifiers. Whitespaces are nonprintable in the sense
that when they are printed on a white sheet of paper, the space between special symbols, reserved words, and identifiers is white. Proper utilization of whitespaces in a
program is important. They can be used to make the program more readable.


Whitespaces typically are not visible to the compiler. This includes spaces, tabs, line feeds, carriage returns, and so on. Whitespaces within string literals, though, make a difference to the output.





## Comments
The program that you write should be clear not only to you, but also to the reader of your program. Part of good programming is the inclusion of comments in the program. Typically, comments can be used to identify the authors of the program, give the date when the program is written or modified, give a brief explanation of the program, and explain the meaning of key statements in a program.

There are two common types of comments in a C++ program—single-line comments and multiple-line comments.

Single-line comments begin with // and can be placed anywhere in the line. Everything encountered in that line after // is ignored by the compiler:

//single line

Multiple-line comments are enclosed between /* and */.
The compiler ignores anything that appears between /* and */ :
/*
Multiple
Line
Comment
*/





## Statements
C++ programs are composed of statements:
[C++\Syntax\Statements\_Statements.md]

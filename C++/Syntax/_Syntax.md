Programming language: A set of tokens and their rules which enable you to write programs to solve problems.



## Tokens
A C++ token is the smallest element of a program that is meaningful to the compiler.

C++’s tokens are divided into special symbols, keywords, identifiers, and constants.



### Special Symbols
The symbols that are used in C/C++ with some special meaning and for some specific function are called as Special Symbols.

The special symbols being used with context to programming language are illustrated below as:

Brackets [] : used as array element references and indicate single & multidimensional subscripts.
[C++\Types&Values\Arrays.md]

Braces {} : used to delimit compound statements.
[C++\Syntax\Statements\_Statements.md]

Semicolon ; : used to terminate statements.
[C++\Syntax\Statements\_Statements.md]

Parenthesis () : used to indicate function parameters & function calls.
[C++\Syntax\Functions\_Functions.md]

Asterisk * : used to create and dereference pointer variables
[C++\Types&Values\Pointers\PointersAndReferences.md]

Hash # : used to indicate preprocessor directives.
[C++\Syntax\Declaration+Definition\PreprocessorDirectives.md]

Tilde ~ : used to declare a destructor to free memory
[C++\Types&Values\Classes\Methods\Destructor.md]

Quotation "" : used to delimit string literals.
[C++\Types&Values\Literals\String.md]

Operators : used to perform a specific operation on data.
[C++\Syntax\Operators\_Operators.md]



### Identifiers
[C++\Syntax\Statements\Declarations\Identifiers.md]



### Reserved Words (Keywords)
C++ uses a number of keywords to identify operations and data descriptions.

The keywords are the reserved terms in any programming language. Every keyword in the language is expected to provide an intended functionality to the program. We cannot use the keywords as identifiers because this practice tries to assign a new meaning to the keyword which is not allowed. However, the C/C++ pre-processor directives (so-called header files) can be used to specify text to be exchanged for keywords before compilation.

Reserved word symbols include the following:
asm, else, new, this, auto, enum, operator, throw, bool, explicit, private, true, break, export, protected, try, case, extern, public, typedef, catch, false, register, typeid, char, float, reinterpret_cast, typename, class, for, return, union, const, friend, short, unsigned, constexpr, goto, signed, using, continue, if, sizeof, virtual, default, inline, static, void, delete, int, static_cast, volatile, do, long, struct, wchar_t, double, mutable, switch, while, dynamic_cast, namespace, template, and, bitor, not_eq, xor, and_eq, compl, or, xor_eq, bitand, not, or_eq

The letters that make up a reserved word are always lowercase. Each is considered to be a single symbol. Furthermore, reserved words cannot be redefined within any program; that is, they cannot be used for anything other than their intended use.




## Whitespace
C++ whitespaces include spaces, tabs, and newline characters. In a C++ program, whitespaces are used to separate special symbols, reserved words, and identifiers as well as make the structure of programs more readable. Whitespaces typically are not visible to the compiler. Whitespaces within string literals, though, make a difference to the output.

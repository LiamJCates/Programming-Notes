For general information related to programming language syntax, see:
[Programming Methods\Fundamentals\Constructs\Syntax.md]

When you compile a C++ program, the compiler is responsible for making sure your program follows the syntax rules of the language. Violation of syntax rules results in a syntax error during compilation.

Thus, a syntax error is a compiler error that occurs at compile-time when your program violates the grammar rules of the C++ language.

### Tokens
A C++ token is the smallest element of a program that is meaningful to the compiler. C++’s tokens are divided into special symbols, keywords, identifiers, and literals.

### Special Symbols
The symbols that are used in C/C++ with some special meaning and for some specific function are called as Special Symbols.

The special symbols being used with context to programming language are illustrated below as:

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



### Reserved Words (Keywords)
C++ uses a number of keywords to identify operations and data descriptions.

The keywords are the reserved terms in any programming language. Every keyword in the language is expected to provide an intended functionality to the program. We cannot use the keywords as identifiers because this practice tries to assign a new meaning to the keyword which is not allowed. However, the C/C++ pre-processor directives (so-called header files) can be used to specify text to be exchanged for keywords before compilation.

C++ reserves a set of 92 words (as of C++20) for its own use. These words are called keywords (or reserved words), and each of these keywords has a special meaning within the C++ language.

Here is a list of all the C++ keywords:

alignas, alignof, and, and_eq, asm, auto, bitand, bitor, bool, break, case, catch, char, char8_t (C++20), char16_t, char32_t, class, compl, concept (C++20), const, consteval (C++20), constexpr, constinit (C++20), const_cast, continue, co_await (C++20), co_return (C++20), co_yield (C++20), decltype, default, delete, do, double, dynamic_cast, else, enum, explicit, export, extern, false, float, for, friend, goto, if, inline, int, long, mutable, namespace, new, noexcept, not, not_eq, nullptr, operator, or, or_eq, private, protected, public, register, reinterpret_cast, requires (C++20), return, short, signed, sizeof, static, static_assert, static_cast, struct, switch, template, this, thread_local, throw, true, try, typedef, typeid, typename, union, unsigned, using, virtual, void, volatile, wchar_t, while, xor, xor_eq

The keywords marked (C++20) were added in C++20. If your compiler is not C++20 compliant (or does have C++20 functionality, but it’s turned off by default), these keywords may not be functional.

C++ also defines special identifiers: override, final, import, and module. These have a specific meaning when used in certain contexts but are not reserved.

Some of these keywords, including int and return have a set of operators, these keywords and special identifiers define the entire language of C++ (preprocessor commands excluded).

The letters that make up a reserved word are always lowercase. Each is considered to be a single symbol. Furthermore, reserved words cannot be redefined within any program; that is, they cannot be used for anything other than their intended use.



### Identifiers
[C++\Syntax\Statements\Declarations\Identifiers.md]

### Literals
[C++\Syntax\Statements\Expressions\Primary\Literals]



## Whitespace
Whitespace is a term that refers to characters that are used for formatting purposes.

C++ whitespaces include spaces, tabs, and newline characters. In a C++ program, whitespaces are used to separate tokens as well as make the structure of programs more readable. Whitespaces typically are not visible to the compiler. Whitespaces within string literals, though, make a difference to the output.

The C++ compiler generally ignores whitespace, with a few minor exceptions (when processing text literals). For this reason, we say that C++ is a whitespace-independent language.

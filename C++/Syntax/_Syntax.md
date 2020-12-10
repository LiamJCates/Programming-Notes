Programming language: A set of rules, symbols, and special words.

The programming language’s rules, symbols, and special words enable you to write programs to solve problems.

To make meaningful sentences in any language, you must learn its alphabet, words, and grammar.

To write meaningful programs, you must learn the programming language’s special symbols, words, and syntax rules.

The syntax rules determine which statements (instructions) are legal or valid, that is, which are accepted by the programming language and which are not.

The semantic rules determine the meaning of the instructions.

Special Symbols
The smallest individual unit of a program written in any language is called a token.
C++’s tokens are divided into special symbols, word symbols, and identifiers.


Reserved Words (Keywords)
A second category of tokens is reserved word symbols. Some of the reserved word
symbols include the following:
int, float, double, char, const, void, return

Reserved words are also called keywords. The letters that make up a reserved word
are always lowercase. Like the special symbols, each is considered to be a single symbol. Furthermore, reserved words cannot be redefined within any program; that is,
they cannot be used for anything other than their intended use.


Identifiers
A third category of tokens is identifiers. Identifiers are names of things that appear
in programs, such as variables, constants, and functions. All identifiers must obey
C++’s rules for identifiers.
Identifier: A C++ identifier consists of letters, digits, and the underscore character
(_) and must begin with a letter or underscore.
Some identifiers are predefined; others are defined by the user.

Identifiers can be made of only letters, digits, and the underscore character; no other
symbols are permitted to form an identifier.

C++ is case sensitive—uppercase and lowercase letters are considered different. Thus,
the identifier NUMBER is not the same as the identifier number. Similarly, the identifiers
X and x are different.

In C++, identifiers can be of any length.


Whitespaces
Every C++ program contains whitespaces. Whitespaces include blanks, tabs, and
newline characters. In a C++ program, whitespaces are used to separate special
symbols, reserved words, and identifiers. Whitespaces are nonprintable in the sense
that when they are printed on a white sheet of paper, the space between special symbols, reserved words, and identifiers is white. Proper utilization of whitespaces in a
program is important. They can be used to make the program more readable.


Comments
The program that you write should be clear not only to you, but also to the reader of
your program. Part of good programming is the inclusion of comments in the program. Typically, comments can be used to identify the authors of the program, give
the date when the program is written or modified, give a brief explanation of the
program, and explain the meaning of key statements in a program.

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
C++ programs are composed of statements.
All statements in C++ end with a semicolon (;)

The next statement can start immediately after the semicolon, but for convenience and readability you often program successive statements on successive lines.

Whitespaces typically are not visible to the compiler. This includes spaces, tabs, line feeds, carriage returns, and so on. Whitespaces within string literals, though, make a difference to the output.

If you need to spread a statement over two lines by inserting a backslash (\) at the end:
cout << "Hello \
World" << endl; // split to two lines is OK

The preceding statement can be written as two string literals:
cout << "Hello "
"World" << endl; // two string literals is also OK

The compiler notices two adjacent string literals and concatenates them.

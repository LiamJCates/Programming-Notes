

Variables
a variable or scalar is a storage location paired with an associated symbolic name (an identifier), which contains some known or unknown quantity of information referred to as a value. Programs use the variable's identifier to reference and manipulate values during computation.

Variable Types
Each variable in C has a specific type, which determines the size and layout of the variable's memory; the range of values that can be stored within that memory; and the set of operations that can be applied to the variable.

Naming Variables
The name of a variable can be composed of letters, digits, and the underscore character. It must begin with either a letter or an underscore. Don't begin variable names with underscore, while the name would be legal, library routines often use such names. Upper and lowercase letters are distinct because C is case-sensitive. Traditional C practice is to use lower case for
variable names, and all upper case for symbolic constants.

There are 32 keywords in C, like "if, else, int, float", that are reserved words and cannot be used as variable names.

We tend to use short names for local variables, especially loops, and longer names for external variables.


Variable Definition
A variable definition tells the compiler where and how much storage to create for the variable. A variable definition specifies a data type and contains a list of one or more variables of that type:

type variable_list;

type must be a valid C data type
variable_list identifiers are separated by commas

int    i, j, k;

Variables can be initialized (assigned an initial value) in their declaration. The initializer consists of an equal sign followed by a constant expression. It is good practice to always initialize variables.

type variable_name = value;


Some examples are −

extern int d = 3, f = 5;    // declaration of d and f.
int d = 3, f = 5;           // definition and initializing d and f.
byte z = 22;                // definition and initializes z.
char x = 'x';               // the variable x has the value 'x'.

More rules on initialization can be found here [Initialization.md]










Variable Declaration
A variable declaration provides assurance to the compiler that there exists a variable with the given type and name so that the compiler can proceed for further compilation without requiring the complete detail about the variable. A variable definition has its meaning at the time of compilation only, the compiler needs actual variable definition at the time of linking the program.

Variable declaration is useful when the programmer uses multiple files and defines the variables in one of the files. They are available when linking the program. We use the “extern” keyword to declare a variable in any place. Even though it is possible to declare a variable multiple times in a C program, it is only possible to define it only once such as in a file or a function.

"Declaration" refers to places where the nature of the variable is stated but no storage is allocated.
"Definition" refers to the place where the variable is created or assigned storage;

More information on the extern keyword can be found here [extern.md]











Lvalues and Rvalues in C

There are two kinds of expressions in C −

    lvalue − Expressions that refer to a memory location are called "lvalue" expressions. An lvalue may appear as either the left-hand or right-hand side of an assignment.

    rvalue − The term rvalue refers to a data value that is stored at some address in memory. An rvalue is an expression that cannot have a value assigned to it which means an rvalue may appear on the right-hand side but not on the left-hand side of an assignment.

Variables are lvalues and so they may appear on the left-hand side of an assignment. Numeric literals are rvalues and so they may not be assigned and cannot appear on the left-hand side. Take a look at the following valid and invalid statements −

int g = 20; // valid statement

10 = 20; // invalid statement; would generate compile-time error














Literals
Literals are data used for representing fixed values. They can be used directly in the code. For example: 1, 2.5, 'c' etc.

Here, 1, 2.5 and 'c' are literals. Why? You cannot assign different values to these terms.

Integer Literals
An integer literal can be a decimal, octal, or hexadecimal constant. A prefix specifies the base or radix: 0x or 0X for hexadecimal, 0 for octal, and nothing for decimal.

An integer literal can also have a suffix that is a combination of U and L, for unsigned and long, respectively. The suffix can be uppercase or lowercase and can be in any order.

An integer literal with no suffix is an int.
  1234
the suffix l or L as well as an integer too big to fit into an int indicates a long literal.
  1L
  1234567890
the suffix u or U indicates an unsigned literal.
the suffix ul or UL indicates unsigned long literal.

A integer literal can be specified in octal or hexadecimal with a prefix
A 0 (zero) prefix means octal;
a 0x or 0X prefix means hexadecimal.

Octal and hexadecimal literals may also be suffixed to make them long and unsigned



85         /* decimal */
0213       /* octal */
0x4b       /* hexadecimal */
30         /* int */
30u        /* unsigned int */
30l        /* long */
30ul       /* unsigned long */
0xFUL      /* unsigned long hexadecimal */



Floating-Point Literals
Floating-point literals has an integer part, a decimal point and either a fractional part, an exponent part, or both.

While representing decimal form, you must include the decimal point, the exponent, or both;

While representing exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced by e or E.

3.14159       /* Legal */
314159E-5L    /* Legal */
510E          /* Illegal: incomplete exponent */
210f          /* Illegal: no decimal or exponent */
.e55          /* Illegal: missing integer or fraction */

their type is double, unless suffixed:
f or F indicate a float.
l or L indicate a long double.



Character Literal
A character literal is an integer, written as one character within single quotes, such as 'x'.

The value of a character literal is the numeric value of the character in the machine's character set. For example, in the ASCII character set the character constant '0' has the value 48, which is unrelated to the numeric value 0. If we write '0' instead of a numeric value like 48 that depends on character set, the program is independent of the particular value and easier to read.

Character literals are enclosed in single quotes, e.g., 'x' can be stored in a simple variable of char type.

A character literal can be a plain character (e.g., 'x'), an escape sequence (e.g., '\t'), or a universal character (e.g., '\u02C0').

There are certain characters in C that represent special meaning when preceded by a backslash for example, newline (\n) or tab (\t) called escape sequences

Escape Sequences
Certain characters can be represented in character and string constants by escape sequences like \n (newline); these sequences look like two characters, but represent only one. In addition, an arbitrary byte-sized bit pattern can be specified by

\000

where 000 is one to three octal digits (0...7) or

\xhh

where hh is one or more hexadecimal digits (0 ...9, a ...f, A ..F).

So we might write

 #define VTAB '\013'  /* ASCII vertical tab */
 #define BELL '\007   /* ASCII bell character */

or, in hexadecimal,

  #define VTAB '\xb'
  #define BELL '\x7'

The complete set of escape sequences is
\a alert (bell) character
\\ backslash
\b backspace
\? question mark
\f formfeed
\' single quote
\n newline
\" double ,quote
\r carriage return
\000 octal number
\t horizontal tab
\xhh hexadecimal number
\v vertical tab


Null Character
The character literal '\0' represents the character with value zero, the null character. '\0' is often written instead of 0 to emphasize the character nature of some expression, but the numeric value is just O.










String Literals
A string literal is a sequence of zero or more characters surrounded by double quotes:

"I am a string"

or

""  /* the empty string */

The quotes are not part of the string, but serve only to delimit it.

Escape sequences apply in strings; \" represents the double-quote character.

A string contains characters that are similar to character literals: plain characters, escape sequences, and universal characters.

You can break a long line into multiple lines using string literals and separating them using white spaces as string literal can be concatenated at compile time:


"hello, world"

"hello, \

world"

"hello, " "w" "orld"

All the three forms are identical strings.

This is useful for splitting long strings across several source lines.

Careful
Be careful to distinguish between a character constant and a string that contains a single character: ' x' is not the same as "x". The former is an integer,
used to produce the numeric value of the letter x in the machine's character set.
The latter is an array of characters that contains one character (the letter x)
and a '\0'.


A string literal represents a one-dimensional array of characters terminated by a null character '\0'. Thus a null-terminated string contains the characters that comprise the string followed by a null. Thus the physical storage required is one more than the number of characters written between the quotes. This representation means that there is no limit to how long a string can be, but programs must scan a string completely to determine its length.

The standard library function strlen(s) returns the length of its character string arguments, excluding the terminal '\0'.

















Constants
Constants refer to fixed values that the program may not alter during its execution. Constants can be of any of the basic data types. Constants are treated just like regular variables except that their values cannot be modified after their definition.



Defining Constants

There are two simple ways in C to define constants −

    Using #define preprocessor.

    Using const keyword.





The #define Preprocessor

Form #define preprocessor to define a constant −
#define identifier value

Example
#include <stdio.h>

#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'

int main() {
   int area;  

   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);

   return 0;
}

Result
value of area : 50





The const Keyword
The qualifier const can be prefixed to the declaration of any variable to specify that its value will not be changed.

For an array, the const qualifier says that the elements will not be altered.

const type variable = value;

Example

#include <stdio.h>

int main() {
   const int  LENGTH = 10;
   const int  WIDTH = 5;
   const char NEWLINE = '\n';
   int area;  

   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);

   return 0;
}

result

value of area : 50

Note that it is a good programming practice to define constants in CAPITALS.



Constant Expression
A constant expression is an expression that involves only constants. Such expressions may be evaluated during compilation rather than run-time, and accordingly may be used in any place that a constant can occur, as in

#define MAXLINE 1000
char line[MAXLINE+1];

or

#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];









Enumeration Constant
There is one other kind of constant, the enumeration constant. An
enumeration is a list of constant integer values, as in

enum boolean { NO, YES };

The first name in an enum has value 0, the next 1, and so on, unless explicit values are specified:

enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

If not all values are specified, unspecified values continue
the progression from the last specified value

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
JUL, AUG, SEP, OCT, NOV, DEC };
/* FEB is 2, MAR is 3, etc. */


Names in different enumerations must be distinct.
Values need not be distinct in the same enumeration.
Enumerations provide a convenient way to associate constant values with names, an alternative to #define with the advantage that the values can be generated for you. Although variables of enum types may be declared, compilers need not check that what you store in such a variable is a valid value for the enumeration. Nevertheless, enumeration variables offer the chance of checking and so are often better than #defines. In addition, a debugger may be able to print values of enumeration variables in their symbolic form










Declaring Arrays

An array declaration specifies the type and number of the elements:

type arrayName [ arraySize ];

This is called a single-dimensional array. The arraySize must be an integer constant greater than zero and type can be any valid C data type.

Accessing Array Elements

An element is accessed by indexing the array name. This is done by placing the index of the element within square brackets after the name of the array. For example −

double salary = balance[9];

As arrays are start there indexes at zero, the above statement will take the 10th element from the array and assign the value to salary variable.

we assign a value to array elements in much the same way.

balance[9] = 10.0;


Multidimensional Arrays
C programming language allows multidimensional arrays of the form:

type name[size1][size2]...[sizeN];

Where type is any valid C data type, name is a valid C identifier, and size must be an integer constant greater than zero




Accessing Two-Dimensional Array Elements

An element in a two-dimensional array is accessed by using the subscripts, i.e., row index and column index of the array. For example −

int val = a[2][3];

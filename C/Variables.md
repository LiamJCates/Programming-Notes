A variable is nothing but a name given to a storage area that our programs can manipulate. Each variable in C has a specific type, which determines the size and layout of the variable's memory; the range of values that can be stored within that memory; and the set of operations that can be applied to the variable.

The name of a variable can be composed of letters, digits, and the underscore character. It must begin with either a letter or an underscore. Don't begin variable names with underscore, while the name would be legal, library routines often use such names. Upper and lowercase letters are distinct because C is case-sensitive. Traditional C practice is to use lower case for
variable names, and all upper case for symbolic constants.

A variable definition tells the compiler where and how much storage to create for the variable. A variable definition specifies a data type and contains a list of one or more variables of that type

type variable_list;

Here, type must be a valid C data type
A variable_list may consist of one or more identifier names separated by commas

int    i, j, k;

Variables can be initialized (assigned an initial value) in their declaration. The initializer consists of an equal sign followed by a constant expression

type variable_name = value;


Some examples are −

extern int d = 3, f = 5;    // declaration of d and f.
int d = 3, f = 5;           // definition and initializing d and f.
byte z = 22;                // definition and initializes z.
char x = 'x';               // the variable x has the value 'x'.

For definition without an initializer: variables with static storage duration are implicitly initialized with NULL (all bytes have the value 0); the initial value of all other variables are undefined.


Variable Declaration in C

A variable declaration provides assurance to the compiler that there exists a variable with the given type and name so that the compiler can proceed for further compilation without requiring the complete detail about the variable. A variable definition has its meaning at the time of compilation only, the compiler needs actual variable definition at the time of linking the program.



"Definition" refers to the place where the variable is created or assigned storage;
"declaration" refers to places where the nature of the variable is stated but no storage is allocated.









Lvalues and Rvalues in C

There are two kinds of expressions in C −

    lvalue − Expressions that refer to a memory location are called "lvalue" expressions. An lvalue may appear as either the left-hand or right-hand side of an assignment.

    rvalue − The term rvalue refers to a data value that is stored at some address in memory. An rvalue is an expression that cannot have a value assigned to it which means an rvalue may appear on the right-hand side but not on the left-hand side of an assignment.

Variables are lvalues and so they may appear on the left-hand side of an assignment. Numeric literals are rvalues and so they may not be assigned and cannot appear on the left-hand side. Take a look at the following valid and invalid statements −

int g = 20; // valid statement

10 = 20; // invalid statement; would generate compile-time error












Constants
An integer constant like 1234 is an int.
A long constant is written with a terminal l or L, as in 123456789L; an integer too big to fit into an int will also be taken as a long.
Unsigned constants are written with a terminal u or U,and the suffix ul or UL indicates unsigned long.


Floating-point constants contain a decimal point (123. 4) or an exponent (1e-2) or both; their type is double, unless suffixed:
f or F indicate a float constant;
l or L indicate a long double.

The value of an integer can be specified in octal or hexadecimal instead of decimal.
A leading 0 (zero) on an integer constant means octal;
a leading 0x or 0X means hexadecimal.

Octal and hexadecimal constants may also be followed by L to make them long and U to make them unsigned: 0xFUL is an unsigned long constant with value 15 decimal.

A character constant is an integer, written as one character within single
quotes, such as ' x '. The value of a character constant is the numeric value of
the character in the machine's character set. For example, in the ASCII character set the character constant ' 0' has the value 48, which is unrelated to the
numeric value O. If we write ' 0' instead of a numeric value like 48 that
depends on character set, the program is independent of the particular value and
easier to read.

Certain characters can be represented in character and string constants by
escape sequences like \n (newline); these sequences look like two characters,
but represent only one. In addition, an arbitrary byte-sized bit pattern can be
specified by

'\000

where 000 is one to three octal digits (0...7) or by

'\xhh'

where hh is one or more hexadecimal digits (0 ...9, a ...f, A ..F). So we might write

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


The character constant ' \0' represents the character with value zero, the
null character. ' \ 0' is often written instead of 0 to emphasize the character
nature of some expression, but the numeric value is just O

A constant expression is an expression that involves only constants. Such
expressions may be evaluated during compilation rather than run-time, and
accordingly may be used in any place that a constant can occur, as in
#define MAXLINE 1000
char line[MAXLINE+1];

or

#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];


A string constant, or string literal, is a sequence of zero or more characters
surrounded by double quotes, as in:

"I am a string"

or

""  /* the empty string */

The quotes are not part of the string, but serve only to delimit it. The same
escape sequences used in character constants apply in strings; \" represents the
double-quote character. String constants can be concatenated at compile time:

"hello," " world"

is equivalent to

"hello, world"

This is useful for splitting long strings across several source lines.
Technically, a string constant is an array of characters. The internal
representation of a string has a null character ' \0' at the end, so the physical
storage required is one more than the number of characters written between the
quotes. This representation means that there is no limit to how long a string
can be, but programs must scan a string completely to determine its length.
The standard library function strlen(s) returns the length of its character string argument s, excluding the terminal '\0'.

Be careful to distinguish between a character constant and a string that contains a single character: ' x' is not the same as "x". The former is an integer,
used to produce the numeric value of the letter x in the machine's character set.
The latter is an array of characters that contains one character (the letter x)
and a '\0'.

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


Names in different enumerations must be distinct. Values need not be distinct
in the same enumeration.
Enumerations provide a convenient way to associate constant values with
names, an alternative to #define with the advantage that the values can be
generated for you. Although variables of enum types may be declared, compilers need not check that what you store in such a variable is a valid value for
the enumeration. Nevertheless, enumeration variables offer the chance of
checking and so are often better than #defines. In addition, a debugger may
be able to print values of enumeration variables in their symbolic form









pointers

how do you declare a pointer
int    *ip;    /* pointer to an integer */
double *dp;    /* pointer to a double */
float  *fp;    /* pointer to a float */
char   *ch     /* pointer to a character */

How do you use a pointer
  int  var = 20;   /* actual variable declaration */
   int  *ip;        /* pointer variable declaration */

   ip = &var;  /* store address of var in pointer variable*/
Address of var variable: bffd8b3c
Address stored in ip variable: bffd8b3c
Value of *ip variable: 20


how do you declare an integer pointer as a function parameter
void funtion_name(int *x){
}

Always initialize pointer variables to
NULL

Typically, programs are not permitted to access memory at address 0 because
that memory is reserved by the operating system.

However, the memory address 0 has special significance; it signals that the pointer is not intended to point to an accessible memory location.

But by convention, if a pointer contains the null (zero) value, it is assumed to point to nothing.

To check for a null pointer, you can use an 'if' statement as follows −
if(ptr)     /* succeeds if p is not null */
if(!ptr)    /* succeeds if p is null */
Function prototype for a pointer parameter
void fUnction_name(type *parameter_name);

Pointers allow C, which is pass by value, to mutate data without
the use of global variables

#include <stdio.h>
#include <time.h>
 
void getSeconds(unsigned long *par);

int main () {
   unsigned long sec;
   getSeconds( &sec );
   /* print the actual value */
   printf("Number of seconds: %ld\n", sec );
   return 0;
}

void getSeconds(unsigned long *par) {
   /* get the current number of seconds */
   *par = time( NULL );
   return;
}

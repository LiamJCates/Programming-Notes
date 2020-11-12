

Variables

Programs use variables to reference and manipulate values during computation

A variable is nothing but a name given to a storage area that our programs can manipulate.

Variable Types
Each variable in C has a specific type, which determines the size and layout of the variable's memory; the range of values that can be stored within that memory; and the set of operations that can be applied to the variable.

Naming Variables
The name of a variable can be composed of letters, digits, and the underscore character. It must begin with either a letter or an underscore. Don't begin variable names with underscore, while the name would be legal, library routines often use such names. Upper and lowercase letters are distinct because C is case-sensitive. Traditional C practice is to use lower case for
variable names, and all upper case for symbolic constants.

Keywords like "if, else, int, float" are reserved words and cannot be used as variable names

We tend to use short names for local variables, especially loops, and longer names for external variables.


Defining Variables
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


An explicitly initialized automatic variable is initialized each time the function or block it is in is entered; the initializer may be any
expression. External and static variables are initialized to zero by default.
Automatic variables for which there is no explicit initializer have undefined
(i.e., garbage) values.


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
Constants refer to fixed values that the program may not alter during its execution. These fixed values are also called literals.

Constants can be of any of the basic data types like an integer constant, a floating constant, a character constant, or a string literal. There are enumeration constants as well.

Constants are treated just like regular variables except that their values cannot be modified after their definition.



Integer Constants
An integer literal can be a decimal, octal, or hexadecimal constant. A prefix specifies the base or radix: 0x or 0X for hexadecimal, 0 for octal, and nothing for decimal.

An integer literal can also have a suffix that is a combination of U and L, for unsigned and long, respectively. The suffix can be uppercase or lowercase and can be in any order.

An integer constant with no suffix is an int.
  1234
the suffix l or L as well as an integer too big to fit into an int indicates a long constant.
  1L
  1234567890
the suffix u or U indicates an unsigned constant.
the suffix ul or UL indicates unsigned long.

A constant integer value can be specified in octal or hexadecimal with a prefix
A 0 (zero) prefix on an integer constant means octal;
a 0x or 0X prefix means hexadecimal.

Octal and hexadecimal constants may also be suffixed to make them long and unsigned



85         /* decimal */
0213       /* octal */
0x4b       /* hexadecimal */
30         /* int */
30u        /* unsigned int */
30l        /* long */
30ul       /* unsigned long */
0xFUL      /* unsigned long hexadecimal */



Floating-Point Literals
Floating-point literals or constants has an integer part, a decimal point and either a fractional part, an exponent part, or both.

While representing decimal form, you must include the decimal point, the exponent, or both;

While representing exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced by e or E.

3.14159       /* Legal */
314159E-5L    /* Legal */
510E          /* Illegal: incomplete exponent */
210f          /* Illegal: no decimal or exponent */
.e55          /* Illegal: missing integer or fraction */

their type is double, unless suffixed:
f or F indicate a float constant;
l or L indicate a long double.



Character Literal
A character constant is an integer, written as one character within single quotes, such as 'x'.

The value of a character constant is the numeric value of the character in the machine's character set. For example, in the ASCII character set the character constant '0' has the value 48, which is unrelated to the numeric value 0. If we write '0' instead of a numeric value like 48 that depends on character set, the program is independent of the particular value and easier to read.

Character literals are enclosed in single quotes, e.g., 'x' can be stored in a simple variable of char type.

A character literal can be a plain character (e.g., 'x'), an escape sequence (e.g., '\t'), or a universal character (e.g., '\u02C0').

There are certain characters in C that represent special meaning when preceded by a backslash for example, newline (\n) or tab (\t) called escape sequences

Escape Sequences
Certain characters can be represented in character and string constants by
escape sequences like \n (newline); these sequences look like two characters,
but represent only one. In addition, an arbitrary byte-sized bit pattern can be
specified by

\000

where 000 is one to three octal digits (0...7) or by

\xhh

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


Null Character
The character constant ' \0' represents the character with value zero, the
null character. '\0' is often written instead of 0 to emphasize the character
nature of some expression, but the numeric value is just O




Constant Expression
A constant expression is an expression that involves only constants. Such expressions may be evaluated during compilation rather than run-time, and accordingly may be used in any place that a constant can occur, as in

#define MAXLINE 1000
char line[MAXLINE+1];

or

#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];





String Literals
A string constant, or string literal, is a sequence of zero or more characters surrounded by double quotes, as in:

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

A string contains characters that are similar to character literals: plain characters, escape sequences, and universal characters.

You can break a long line into multiple lines using string literals and separating them using white spaces.

Here are some examples of string literals. All the three forms are identical strings.

"hello, dear"

"hello, \

dear"

"hello, " "d" "ear"


Be careful to distinguish between a character constant and a string that contains a single character: ' x' is not the same as "x". The former is an integer,
used to produce the numeric value of the letter x in the machine's character set.
The latter is an array of characters that contains one character (the letter x)
and a '\0'.


Strings are actually one-dimensional array of characters terminated by a null character '\0'. Thus a null-terminated string contains the characters that comprise the string followed by a null.

The following declaration and initialization create a string consisting of the word "Hello". To hold the null character at the end of the array, the size of the character array containing the string is one more than the number of characters in the word "Hello."

char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

If you follow the rule of array initialization then you can write the above statement as follows −

char greeting[] = "Hello";

The C compiler automatically places the '\0' at the end of the string when it initializes the array. 








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


Names in different enumerations must be distinct. Values need not be distinct
in the same enumeration.
Enumerations provide a convenient way to associate constant values with
names, an alternative to #define with the advantage that the values can be
generated for you. Although variables of enum types may be declared, compilers need not check that what you store in such a variable is a valid value for
the enumeration. Nevertheless, enumeration variables offer the chance of
checking and so are often better than #defines. In addition, a debugger may
be able to print values of enumeration variables in their symbolic form










Declaring Arrays

To declare an array in C, a programmer specifies the type of the elements and the number of elements required by an array as follows −

type arrayName [ arraySize ];

This is called a single-dimensional array. The arraySize must be an integer constant greater than zero and type can be any valid C data type.

Initializing Arrays

You can initialize an array in C either one by one or using a single statement as follows −

double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};

The number of values between braces { } cannot be larger than the number of elements that we declare for the array between square brackets [ ].

If you omit the size of the array, an array just big enough to hold the initialization is created. Therefore, if you write −

double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};

You will create exactly the same array as you did in the previous example.

Accessing Array Elements

An element is accessed by indexing the array name. This is done by placing the index of the element within square brackets after the name of the array. For example −

double salary = balance[9];

The above statement will take the 10th element from the array and assign the value to salary variable.

likewise, we can assign a value to array elements in much the same way.

balance[9] = 10.0;


Multidimensional Arrays
C programming language allows multidimensional arrays. Here is the general form of a multidimensional array declaration −

type name[size1][size2]...[sizeN];

Where type can be any valid C data type and arrayName will be a valid C identifier.


Initializing Two-Dimensional Arrays

Multidimensional arrays may be initialized by specifying bracketed values for each row. Following is an array with 3 rows and each row has 4 columns.

int a[3][4] = {  
   {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
   {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
   {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
};

The nested braces, which indicate the intended row, are optional. The following initialization is equivalent to the previous example −

int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

Accessing Two-Dimensional Array Elements

An element in a two-dimensional array is accessed by using the subscripts, i.e., row index and column index of the array. For example −

int val = a[2][3];



Pointers to an Array in C
An array name is a constant pointer to the first element of the array. Therefore, in the declaration −

double balance[50];

balance is a pointer to &balance[0], which is the address of the first element of the array balance. Thus, the following program fragment assigns p as the address of the first element of balance −

double *p;
double balance[10];

p = balance;

It is legal to use array names as constant pointers, and vice versa. Therefore, *(balance + 4) is a legitimate way of accessing the data at balance[4].

Once you store the address of the first element in 'p', you can access the array elements using *p, *(p+1), *(p+2) and so on.















Defining Constants

There are two simple ways in C to define constants −

    Using #define preprocessor.

    Using const keyword.

The #define Preprocessor

Given below is the form to use #define preprocessor to define a constant −

#define identifier value

The following example explains it in detail −
Live Demo

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

When the above code is compiled and executed, it produces the following result −

value of area : 50

The const Keyword

const
The qualifier const can be applied to the declaration of any variable to specify that its value will not be changed.

For an array, the const qualifier says that the elements will not be altered.

You can use const prefix to declare constants with a specific type as follows −

const type variable = value;

The following example explains it in detail −
Live Demo

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

When the above code is compiled and executed, it produces the following result −

value of area : 50

Note that it is a good programming practice to define constants in CAPITALS.


















Pointers
Some C programming tasks are performed more easily with pointers, and other tasks, such as dynamic memory allocation, cannot be performed without using pointers.


every variable is a memory location and every memory location has its address defined which can be accessed using ampersand (&) operator, which denotes an address in memory.

A pointer is a variable whose value is the address of another variable, i.e., direct address of the memory location. Like any variable or constant, you must declare a pointer before using it to store any variable address. The general form of a pointer variable declaration is −

type *var-name;

Here, type is the pointer's base type; it must be a valid C data type and var-name is the name of the pointer variable.

how do you declare a pointer
int    *ip;    /* pointer to an integer */
double *dp;    /* pointer to a double */
float  *fp;    /* pointer to a float */
char   *ch     /* pointer to a character */


The actual data type of the value of all pointers, whether integer, float, character, or otherwise, is the same, a long hexadecimal number that represents a memory address. The only difference between pointers of different data types is the data type of the variable or constant that the pointer points to.


How do you use a pointer
To use pointer we must (a) define a pointer variable, (b) assign the address of a variable to a pointer and (c) finally access the value at the address available in the pointer variable.

This is done by using unary operator * that returns the value of the variable located at the address specified by its operand.


  int  var = 20;   /* actual variable declaration */
   int  *ip;        /* pointer variable declaration */

   ip = &var;  /* store address of var in pointer variable*/
Address of var variable: bffd8b3c
Address stored in ip variable: bffd8b3c
Value of *ip variable: 20


how do you declare an integer pointer as a function parameter
void funtion_name(int *x){
}


NULL Pointers

It is always a good practice to assign a NULL value to a pointer variable if it cannot otherwise be initialized. This is done at the time of variable declaration. A pointer that is assigned NULL is called a null pointer.

The NULL pointer is a constant with a value of zero defined in several standard libraries.


Typically, programs are not permitted to access memory at address 0 because that memory is reserved by the operating system.

However, the memory address 0 has special significance; it signals that the pointer is not intended to point to an accessible memory location.

But by convention, if a pointer contains the null (zero) value, it is assumed to point to nothing.

To check for a null pointer, you can use an 'if' statement as follows −
if(ptr)     /* succeeds if p is not null */
if(!ptr)    /* succeeds if p is null */


Function prototype for a pointer parameter
void function_name(type *parameter_name);

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


Pointer Arithmetic

A pointer in c is an address, which is a numeric value. Therefore, you can perform arithmetic operations on a pointer just as you can on a numeric value. There are four arithmetic operators that can be used on pointers: ++, --, +, and -

To understand pointer arithmetic, let us consider that ptr is an integer pointer which points to the address 1000. Assuming 32-bit integers, let us perform the following arithmetic operation on the pointer −

ptr++

After the above operation, the ptr will point to the location 1004 because each time ptr is incremented, it will point to the next integer location which is 4 bytes next to the current location. This operation will move the pointer to the next memory location without impacting the actual value at the memory location. If ptr points to a character whose address is 1000, then the above operation will point to the location 1001 because the next character will be available at 1001.


Incrementing a Pointer
We may use a pointer in our program instead of an array because the variable pointer can be incremented, unlike the array name which cannot be incremented because it is a constant pointer.

Decrementing a Pointer

The same considerations apply to decrementing a pointer, which decreases its value by the number of bytes of its data type



The following program increments the variable pointer to access each succeeding element of the array −
#include <stdio.h>

const int MAX = 3;

int main () {

   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* let us have array address in pointer */
   ptr = var;

   for ( i = 0; i < MAX; i++) {

      printf("Address of var[%d] = %x\n", i, ptr );
      printf("Value of var[%d] = %d\n", i, *ptr );

      /* move to the next location */
      ptr++;
   }

   return 0;
}


Pointer Comparisons

Pointers may be compared by using relational operators, such as ==, <, and >. If p1 and p2 point to variables that are related to each other, such as elements of the same array, then p1 and p2 can be meaningfully compared.

The following program modifies the previous example − one by incrementing the variable pointer so long as the address to which it points is either less than or equal to the address of the last element of the array, which is &var[MAX - 1] −


#include <stdio.h>

const int MAX = 3;

int main () {

   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* let us have address of the first element in pointer */
   ptr = var;
   i = 0;

   while ( ptr <= &var[MAX - 1] ) {

      printf("Address of var[%d] = %x\n", i, ptr );
      printf("Value of var[%d] = %d\n", i, *ptr );

      /* point to the next location */
      ptr++;
      i++;
   }

   return 0;
}


Pointer to a Pointer
A pointer to a pointer is a form of multiple indirection, or a chain of pointers. Normally, a pointer contains the address of a variable. When we define a pointer to a pointer, the first pointer contains the address of the second pointer, which points to the location that contains the actual value

A variable that is a pointer to a pointer must be declared as such. This is done by placing an additional asterisk in front of its name. For example, the following declaration declares a pointer to a pointer of type int −

int **var;

When a target value is indirectly pointed to by a pointer to a pointer, accessing that value requires that the asterisk operator be applied twice

Passing pointers
C programming allows passing a pointer to a function. To do so, simply declare the function parameter as a pointer type.


Returning a Pointer
C also allows to return a pointer from a function. To do so, you would have to declare a function returning a pointer as in the following example −

int * myFunction() {
   .
   .
   .
}

Second point to remember is that, it is not a good idea to return the address of a local variable outside the function, so you would have to define the local variable as static variable.






Type Conversions
When an operator has operands of different types, they are converted to a
common type according to a small number of rules.

In general, the only automatic conversions are those that convert a "narrower" operand into a "wider" one without losing information, such as converting an integer to floating point

Expressions that might lose information, like assigning a longer integer type to a shorter, or a floating-point type
to an integer, may draw a warning, but they are not illegal

float to int causes truncation of the fractional part.

when binary operators manipulate operands of different types, the "lower" type is promoted to the "higher" type before the operation proceeds.

long double > double > float > long > int > (char/short)
Type promotion hierarchy


There is one subtle point about the conversion of characters to integers. The
language does not specify whether variables of type char are signed or
unsigned quantities. When a char is converted to an int, can it ever produce
a negative integer? The answer varies from machine to machine, reflecting differences in architecture. On some machines a char whose leftmost bit is 1
will be converted to a negative integer ("sign extension"). On others, a char is
promoted to an int by adding zeros at the left end, and thus is always positive

The definition of C guarantees that any character in the machine's standard
printing character set will never be negative, so these characters will always be
positive quantities in expressions. But arbitrary bit patterns stored in 'character
variables may appear to be negative on some machines, yet positive on others.
For portability, specify signed or unsigned if non-character data is to be
stored in char variables.


A reason for using float over double in large arrays save storage and are more efficient
Floats save time on machines where double-precision arithmetic is particularly expensive

Conversion rules are more complicated when unsigned operands are involved.

Comparisons between signed and unsigned values are' machine-dependent" they depend on
sizes of a given machines integer types

Conversions take place across assignments; the type of the right side is converted to
the left which is also the type of the result.





If there are no unsigned operands, however, the followinginformal set of rules will suffice:
If either operand is long double, convert the other to long double.
Otherwise, if either operand is double, convert the other to double.
Otherwise, if either operand is float, convert the other to float.
Otherwise, convert char and short to into
Then, if either operand is long, convert the other to long


A character is converted to an integer, either by sign extension or not, as
described above.
Longer integers are converted to shorter ones or to chars by dropping the
excess high-order bits. Thus in

int i;
char c;

i = c;
c = i;

the value of c is unchanged. This is true whether or not sign extension is
involved. Reversing the order of assignments might lose information, however

If x is float and i is int, then x = i and i = x both cause conversions;
float to int causes truncation of any fractional part. When double is converted to float, whether the value is rounded or truncated is implementation dependent.




Since an argument of a function call is an expression, type conversions also take place when
arguments are passed to functions.

If arguments are declared by a function prototype, as they normally should
be, the declaration causes automatic coercion of any arguments when the function is called. Thus, given a function prototype for sqrt:
double sqrt(double);
the call
root2 = sqrt(2);
coerces the integer 2 into the double value 2.0 without any need for a cast

In the absence of a function prototype, char and short become int, and float becomes double.
This is why we have declared function arguments to be int and double even
when the function is called with char and float.




Type Cast
Explicit type conversions can be forced ("coerced") in any expression, with a
unary operator "cast".
(type-name) expression

the expression is converted to the named type by the conversion rules above.
The precise meaning of a cast is as if the expression were assigned to a variable
of the specified type, which is then used in place of the whole construction.

Note that when casting a variable, n, the cast produces the value of n in the proper type; n itself is not altered. The cast
operator has the same high precedence as other unary operators

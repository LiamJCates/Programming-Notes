C is a statically typed language that is every variable has a type associated with it. Types are discussed in specification in great length in §(iso.6.2.5) to §(iso.6.2.8). These types determine what kind of values these variables can hold and how they will be interpreted. For example, say you are given a sequence of 0s and 1s how much can you work with them. We as humans are not very versed with 0s and 1s. Also, say we encode character ‘A’ for 10101 will it be easy for you to see A or numbers. Also, numbers range from −∞ to ∞. Also, since C is statically typed the sizes of data types have to be known at compile time.

The types in C can be classified as follows −

Basic Types

They are arithmetic types and are further classified into:
(a) integer types
(b) floating-point types.

Enumerated types

They are again arithmetic types and they are used to define variables that can only assign certain discrete integer values throughout the program.

The type void

The type specifier void indicates that no value is available.


Derived types

They include
(a) Pointer types
(b) Array types
(c) Structure types
(d) Union types
(e) Function types.




The integral types are char, short int, int, long and long long
floating-point types are float, double and long double.
signed and unsigned are sign modifiers which also modified the range of data types but do not affect their memory requirements. By default all basic data types are signed in nature and you must qualify you variables with unsigned if you want that behavior. short and long are modifiers for size which the data type occupies but I consider them as different types because memory requirements are different. The ranges of integral data types directly reflect their memory requirements and if you know how much memory they are going to occupy you can easily compute their ranges. The range of floating-point comes from IEEE specification.





The range of data types is given in Numerical limits §(iso.5.2.4.2)

. For example, in the range program given below size of int is 4 bytes which is double than what is specified by specification i.e. 2 bytes. Given below is the table for numerical limits for reference from specification. Note that these are in 1’s complement form thus you have to adjust for 2’s complement. Note that these limits are minimum limits imposed by specification and actual limits of data types may be different on your particular platform. The actual values of these limits can be found in headers <limits.h>, <float.h> and <stdint.h>. The values given below are replaced by constant expressions suitable for use in #if preprocessing directives. Moreover, except for CHAR_BIT and MB_LEN_MAX, the following are replaced by expressions that have the same type as an expression that is an object of the corresponding type converted according to the integer promotions. Their implementation-defined values are equal or greater in magnitude (absolute value) to those shown, with the same sign. Note that these ranges are for 1’s complement. While most probably your computer uses 2’s complement so you should add -1 to the negative range. Thus MINs are greater than MAXes.

    number of bits for smallest object that is not a bit-field (byte)

    CHAR_BIT 8

    minimum value for an object of type signed char

    SCHAR_MIN -127     −27−1

maximum value for an object of type signed char

SCHAR_MAX 127     27−1

maximum value for an object of type unsigned char

UCHAR_MAX 255 28−1

minimum value for an object of type char

CHAR_MIN see below

maximum value for an object of type char

CHAR_MAX see below

maximum number of bytes in a multibyte character, for any supported locale

MB_LEN_MAX 1

minimum value for an object of type short int

SHRT_MIN -32767 −215−1

Let us write a program to find out memory required for various data types:

// My range program
// Description: It gives ranges of integral data types
```c
#include <stdio.h>
#include <limits.h>

int main()
{
  printf("Size of char is..........%d\n", sizeof(char));
  printf("Size of short int is.....%d\n", sizeof(short int));
  printf("Size of int is...........%d\n", sizeof(int));
  printf("Size of long is..........%d\n", sizeof(long));
  printf("Size of long long is.....%d\n", sizeof(long long));
  printf("Size of float is.........%d\n", sizeof(float));
  printf("Size of double is........%d\n", sizeof(double));
  printf("Size of long double is...%d\n", sizeof(long double));c

  return 0;
}
```

and the output will be similar to:

```c
Size of char is..........1
Size of short int is.....2
Size of int is...........4
Size of long is..........4
Size of long long is.....8
Size of float is.........4
Size of double is........8
Size of long double is...12
```




























Floating-Point Types

The following table provide the details of standard floating-point types with storage sizes and value ranges and their precision −
Type 	Storage size 	Value range 	Precision
float 	4 byte 	1.2E-38 to 3.4E+38 	6 decimal places
double 	8 byte 	2.3E-308 to 1.7E+308 	15 decimal places
long double 	10 byte 	3.4E-4932 to 1.1E+4932 	19 decimal places

The header file float.h defines macros that allow you to use these values and other details about the binary representation of real numbers in your programs. The following example prints the storage space taken by a float type and its range values −


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(int argc, char** argv) {

    printf("Storage size for float : %d \n", sizeof(float));
    printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
    printf("-FLT_MAX    :   %g\n", (float) -FLT_MAX);
    printf("-FLT_MIN    :   %g\n", (float) -FLT_MIN);
    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
    printf("-DBL_MAX     :  %g\n", (double) -DBL_MAX);
    printf("Precision value: %d\n", FLT_DIG );

    return 0;
}

When you compile and execute the above program, it produces the following result on Linux −

Storage size for float : 4
FLT_MAX      :   3.40282e+38
FLT_MIN      :   1.17549e-38
-FLT_MAX     :   -3.40282e+38
-FLT_MIN     :   -1.17549e-38
DBL_MAX      :   1.79769e+308
DBL_MIN      :   2.22507e-308
-DBL_MAX     :  -1.79769e+308
Precision value: 6









Arrays



Arrays a kind of data structure that can store a fixed-size sequential collection of elements of the same type. An array is used to store a collection of data, but it is often more useful to think of an array as a collection of variables of the same type.

A specific element in an array is accessed by an index.

All arrays consist of contiguous memory locations. The lowest address corresponds to the first element and the highest address to the last element.

All arrays have 0 as the index of their first element which is also called the base index and the last index of an array will be total size of the array minus 1




The void Type

The void type specifies that no value is available. It is used in three kinds of situations −

Function returns as void

There are various functions in C which do not return any value or you can say they return void. A function with no return value has the return type as void. For example, void exit (int status);

Function arguments as void

There are various functions in C which do not accept any parameter. A function with no parameter can accept a void. For example, int rand(void);
The word void must be used for function prototypes with an explicitly empty list.

Pointers to void

A pointer of type void * represents the address of an object, but not its type. For example, a memory allocation function void *malloc( size_t size ); returns a pointer to void which can be casted to any data type.

















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






















Typedef

The C programming language provides a keyword called typedef, which you can use to give a type a new name. Following is an example to define a term BYTE for one-byte numbers −

typedef unsigned char BYTE;

After this type definition, the identifier BYTE can be used as an abbreviation for the type unsigned char, for example..

BYTE  b1, b2;

By convention, uppercase letters are used for these definitions to remind the user that the type name is really a symbolic abbreviation, but you can use lowercase, as follows −

typedef unsigned char byte;

You can use typedef to give a name to your user defined data types as well. For example, you can use typedef with structure to define a new data type and then use that data type to define structure variables directly as follows −
Live Demo

#include <stdio.h>
#include <string.h>

typedef struct Books {
   char title[50];
   char author[50];
   char subject[100];
   int book_id;
} Book;

int main( ) {

   Book book;

   strcpy( book.title, "C Programming");
   strcpy( book.author, "Nuha Ali");
   strcpy( book.subject, "C Programming Tutorial");
   book.book_id = 6495407;

   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);

   return 0;
}

When the above code is compiled and executed, it produces the following result −

Book  title : C Programming
Book  author : Nuha Ali
Book  subject : C Programming Tutorial
Book  book_id : 6495407

typedef vs #define

#define is a C-directive which is also used to define the aliases for various data types similar to typedef but with the following differences −

    typedef is limited to giving symbolic names to types only where as #define can be used to define alias for values as well, q., you can define 1 as ONE etc.

    typedef interpretation is performed by the compiler whereas #define statements are processed by the pre-processor.

The following example shows how to use #define in a program −
Live Demo

#include <stdio.h>

#define TRUE  1
#define FALSE 0

int main( ) {
   printf( "Value of TRUE : %d\n", TRUE);
   printf( "Value of FALSE : %d\n", FALSE);

   return 0;
}

When the above code is compiled and executed, it produces the following result −

Value of TRUE : 1
Value of FALSE : 0

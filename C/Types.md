The types in C can be classified as follows −

Basic Types

They are arithmetic types and are further classified into: (a) integer types and (b) floating-point types.

Enumerated types

They are again arithmetic types and they are used to define variables that can only assign certain discrete integer values throughout the program.

The type void

The type specifier void indicates that no value is available.


Derived types

They include (a) Pointer types, (b) Array types, (c) Structure types, (d) Union types and (e) Function types.








Integer Types
There are only a few basic data types in C:

char a single byte, capable of holding one character
in the local character set.

int an integer, typically reflecting the natural size
of integers on the host machine.

float single-precisionfloating point.

double double-precision floating point

Short and Long
there are a number of qualifiers that can be applied to these
basic types. short and long apply to integers:

short int sh;
long int counter;

The word int can be omitted in such declarations, and typically is.
The intent is that short and long should provide different lengths of
integers where practical; int will normally be the natural size for a particular
machine. short is often 16 bits, long 32 bits, and int either 16 or 32 bits.
Each compiler is free to choose appropriate sizes for its own hardware, subject
only to the restriction that shorts and ints are at least 16 bits, longs are at
least 32 bits, and short is no longer than int, which is no longer than long.

The type long double specifies extended-precision floating point. As with
integers, the sizes of floating-point objects are implementation-defined; float,
double and long double could represent one, two or three distinct sizes.
The standard headers <limits. h> and <float. h> contain symbolic constants for all of these sizes, along with other properties of the machine and compiler



Signed and Unsigned
The qualifier signed or unsigned may be applied to char or any integer.
unsiqned numbers are always positive or zero, and obey the laws of arithmetic
modulo 2, where n is the number of bits in the type.

Whether plain chars are signed or unsigned is machine-dependent,
but printable characters are always positive.



standard integer types with their storage sizes and value ranges −
Type 	          Bytes 	 Value range
char 	          1 byte  -128 to 127 or 0 to 255
unsigned char 	1 byte 	 0 to 255
signed char 	  1 byte  -128 to 127

int 	          2 or 4 	-32,768 to 32,767
                         or -2,147,483,648 to 2,147,483,647
unsigned int 	  2 or 4   0 to 65,535
                         or 0 to 4,294,967,295

short 	        2      	-32,768 to 32,767
unsigned short 	2     	 0 to 65,535

long 	          4/8 (32/64 bit OS) 	-9223372036854775808 to 9223372036854775807
unsigned long 	8 bytes 	0 to 18446744073709551615


To get the exact size of a type or a variable on a particular platform, you can use the sizeof operator. The expressions sizeof(type) yields the storage size of the object or type in bytes


Given below is an example to get the size of various type on a machine using different constant defined in limits.h header file −

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(int argc, char** argv) {

    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);

    return 0;
}

When you compile and execute the above program, it produces the following result on Linux −

CHAR_BIT    :   8
CHAR_MAX    :   127
CHAR_MIN    :   -128
INT_MAX     :   2147483647
INT_MIN     :   -2147483648
LONG_MAX    :   9223372036854775807
LONG_MIN    :   -9223372036854775808
SCHAR_MAX   :   127
SCHAR_MIN   :   -128
SHRT_MAX    :   32767
SHRT_MIN    :   -32768
UCHAR_MAX   :   255
UINT_MAX    :   4294967295
ULONG_MAX   :   18446744073709551615
USHRT_MAX   :   65535
















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

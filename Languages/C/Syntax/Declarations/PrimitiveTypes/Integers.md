Integers are probably simplest to understand of all data types in C so I am discussing them before any other type. As you have seen the keyword for declaring integer type is int. An integer can be 2 bytes or 4 bytes. A 16-bit compiler will have integer of 2 bytes while a 32-bit or 64-bit compiler will have a 4 byte integer. The specified minimum size of an integer is 2 bytes. Since most modern computers are either 32-bit with 64-bit becoming more dominant we will assume in this book that integer’s size is 4 bytes or 32-bit implicitly because 32-bit gcc gives a 32-bit integer. There is a keyword signed which when applied to a data type splits the range into two parts. Since integer is 32 bit so it will be split in the range from −231 to 231−1. By default integers, characters and long are signed. Floats and doubles are always signed and have no unsigned counterpart. When the integer will be texttt{unsigned} then the positive range doubles and it becomes $0$ to 232−1

. When the value of intger is more than its range then the values rotate in the using modulus with the largest value of the range which is also known as INT_MAX or INT_MIN. For unsigned types it is UINT_MAX. These are macros and are defined in limits.h which you can find in /usr/include or /usr/local/include by default.

There are four different types of integers based on their storage requirement. short int, int, long and long long. Short integers are always two bytes. Signed short integer has a range of -32768 to 32767 while unsigned of that has a range of 0 to 65535. Plain integers i.e. int have already been discussed. long are having a minimum storage requirement of 4 bytes. Usually it is large enough to represent all memory addresses of the system because size_t is unsigned long.

short, long and long long qualifiers decrease/increase the range of plain integers. On a 64-bit compiler short int will be 2 bytes while long int will be 8 bytes, which, will be equal to long longint. unsigned long int is chose in such a way that it should be capable of representing all memory addresses because it has a typedef to size_t which is the type of argument received by many functions including memory allocation functions.

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

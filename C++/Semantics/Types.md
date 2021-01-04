Data Types
The objective of a C++ program is to manipulate data. Different programs manipulate different data.

The C++ Type System

C++ is an object-oriented language.

The collection of behaviors and states describing an object is called its type.

C++ is a strongly typed language, meaning each object has a predefined
data type.

Reflecting these kinds of underlying differences, C++ categorizes data into different types, and only certain operations can be performed on particular types of data. Although at first it may seem confusing, by being so type conscious, C++ has built-in checks to guard against errors.

Data type: A set of values together with a set of allowed operations.

C++ data types fall into the following three categories:
Simple data type
Structured data type
Pointers

A data type is called simple if variables of that type can store only one value at a time. In contrast, in a structured data type, each data item is a collection of other data items. Simple data types are building blocks of structured data types.

Every name and every expression has a type that determines the operations that may be performed on it.

A declaration is a statement that introduces an entity into the program. It specifies a type for the entity:
• A type defines a set of possible values and a set of operations (for an object).
• An object is some memory that holds a value of some type.
• A value is a set of bits interpreted according to a type.
• A variable is a named object.





## Simple Data Types
Simple Data types are the most basic types of object.

Some refer to Simple Data types as primitive or built-in types because they’re part of the core language and almost always available to you.

These types include integer, floating-point, character, Boolean, byte, size_t, and void.

These types will work on any platform, but their features, such as size and memory layout, depend on implementation.

Simple Data types strike a balance. On one hand, they try to map a direct relationship from C++ construct to computer hardware; on the other hand, they simplify writing cross-platform code by allowing a programmer to write code once that works on many platforms.






Integer Types
Integral data types are further classified into the following categories: char, short, int, long, bool, unsigned char, unsigned short, unsigned int, unsigned long, long long, and unsigned long long.

Integer types store whole numbers: those that you can write without a fractional component.

The four sizes of integer types that represent numbers are short int, int, long int, and long long int.

Each can be either signed or unsigned. A signed variable can be positive, negative, or zero, and an unsigned variable must be non-negative.

Integer types are signed and int by default, which means you can use the following shorthand notations in your programs: short, long, and long long rather than short int, long int, and long long int.

Which data type you use depends on how big a number your program needs to deal with.


<table>
    <thead>
        <tr>
            <th rowspan="3">Type</th>
            <th colspan="4">Bytes</th>
        </tr>
        <tr>
          <th colspan="2">32-bit OS</th>
          <th colspan="2">64-bit OS</th>
        </tr>
        <tr>
          <th>Windows</th>
          <th>Linux/Mac</th>
          <th>Windows</th>
          <th>Linux/Mac</th>
        </tr>
    </thead>
    <tbody>
        <tr>
          <td>short</td>
          <td>2</td>
          <td>2</td>
          <td>2</td>
          <td>2</td>
        </tr>
        <tr>
          <td>unsigned short</td>
          <td>2</td>
          <td>2</td>
          <td>2</td>
          <td>2</td>
        </tr><tr>
          <td>int</td>
          <td>4</td>
          <td>4</td>
          <td>4</td>
          <td>4</td>
        </tr><tr>
          <td>unsigned int</td>
          <td>4</td>
          <td>4</td>
          <td>4</td>
          <td>4</td>
        </tr><tr>
          <td>long</td>
          <td>4</td>
          <td>4</td>
          <td>4</td>
          <td>8</td>
        </tr><tr>
          <td>unsigned long</td>
          <td>4</td>
          <td>4</td>
          <td>4</td>
          <td>8</td>
        </tr><tr>
          <td>long long</td>
          <td>8</td>
          <td>8</td>
          <td>8</td>
          <td>8</td>
        </tr><tr>
          <td>unsigned long long</td>
          <td>8</td>
          <td>8</td>
          <td>8</td>
          <td>8</td>
        </tr>
    </tbody>
</table>


Note:
If you want to enforce guaranteed integer sizes, you can use integer types in the
<cstdint> library. For example, if you need a signed integer with exactly 8, 16, 32,
or 64 bits, you could use int8_t, int16_t, int32_t, or int64_t. You’ll find options
for the fastest, smallest, maximum, signed, and unsigned integer types to meet your
requirements. But because this header is not always available in every platform,
you should only use cstdint types when there is no other alternative.


## Boolean Types

Boolean types have two states: true and false.
true and false are called the logical (Boolean) values. The central purpose of this data type is to manipulate logical (Boolean) expressions.

More recent versions of C++ contain a built-in data type, bool, that has the logical
(Boolean) values true and false. Therefore, you can manipulate logical (Boolean)
expressions using the bool data type. Recall that in C++, bool, true, and false
are reserved words. In addition, the identifier true has the value 1, and the identifier
false has the value 0.

Earlier versions of C++ did not provide built-in data types that had logical (or Boolean) values true and false. Because logical expressions evaluate to either 1 or 0, the value of a logical expression was stored in a variable of the data type int. Therefore, you can use the int data type to manipulate logical (Boolean) expressions.

Integer types and the bool types convert readily: the true state converts to 1, and false converts to 0. Any non-zero integer converts to true, and 0 converts to false.




## Character Types
The data type char is mainly used to represent single characters—that is, letters, digits, and special symbols.

Character types store human language data. The six character types are:
char The default type, always 1 byte. May or may not be signed.
(Example: ASCII.)Types 37
char16_t Used for 2-byte character sets. (Example: UTF-16.)
char32_t Used for 4-byte character sets. (Example: UTF-32.)
signed char Same as char but guaranteed to be signed.
unsigned char Same as char but guaranteed to be unsigned.
wchar_t Large enough to contain the largest character of the implementation’s locale. (Example: Unicode.)
The character types char, signed char, and unsigned char are called narrow
characters, whereas char16_t, char32_t, and wchar_t are called wide characters due
to their relative storage requirements.













## Floating-Point Types
To deal with decimal numbers, C++ provides the floating-point data type

Floating-point types store approximations of real numbers (which in our case can be defined as any number that has a decimal point and a fractional part, such as 0.33333 or 98.6).

Although it’s not possible to represent an arbitrary real number exactly in computer memory, it’s possible to store an approximation. If this seems hard to believe, just think of a number like π, which has infinitely many digits. With finite computer memory, how could you possibly represent infinitely many digits?

As with all types, floating-point types take up a finite amount of memory, which is called the type’s precision. The more precision a floating-point type has, the more accurate it will be at approximating a real number.

C++ offers three levels of precision for approximations:
float single precision
double double precision
long double extended precision

As with integer types, each floating-point representation depends on
implementation. This section won’t go into detail about floating-point types,
but note that there is substantial nuance involved in these implementations.
On major desktop operating systems, the float level usually has 4 bytes
of precision. The double and long double levels usually have 8 bytes of precision (double precision).
Most users not involved in scientific computing applications can safely
ignore the details of floating-point representation. In such cases, a good
general rule is to use a double.
N O T E For those who cannot safely ignore the details, look at the floating-point specification
relevant to your hardware platform. The predominant implementation of floatingpoint storage and arithmetic is outlined in The IEEE Standard for FloatingPoint Arithmetic, IEEE 754.



Comparing Floating-Point Numbers for Equality: A Precaution
Comparison of floating-point numbers for equality may not behave as you would
expect.


One way to check whether two floating-point
numbers are equal is to check whether the absolute value of their difference is less than
a certain tolerance. For example, suppose the tolerance is 0.000001. Then, x and y are
equal if the absolute value of (x – y) is less than 0.000001. To find the absolute value,
you can use the function fabs (find the absolute value of a floating-point number), of
the header file cmath, as shown in the program. Therefore, the expression fabs(x – y)
< 0.000001 determines whether the absolute value of (x – y) is less than 0.000001.





## Data Type Modifiers
C++ allows the char, int, and double data types to have modifiers preceding them. A modifier is used to alter the meaning of the base type so that it more precisely fits the needs of various situations.

The data type modifiers:

    signed
    unsigned
    long
    short

The modifiers signed, unsigned, long, and short can be applied to integer base types. In addition, signed and unsigned can be applied to char, and long can be applied to double.

The modifiers signed and unsigned can also be used as prefix to long or short modifiers. For example, unsigned long int.

C++ allows a shorthand notation for declaring unsigned, short, or long integers. You can simply use the word unsigned, short, or long, without int. It automatically implies int.









The std::byte Type
System programmers sometimes work directly with raw memory, which is a
collection of bits without a type. Employ the std::byte type, available in the
<cstddef> header, in such situations. The std::byte type permits bitwise logical operations (which you’ll meet in Chapter 7) and little else. Using this
type for raw data rather than an integral type can help to avoid common
sources of difficult-to-debug programming errors.
Note that unlike most other Simple Data types in <cstddef>, std::byte
doesn’t have an exact corollary type in the C language (a “C type”). Like
C++, C has char and unsigned char. These types are less safe to use because they support many operations that std::byte doesn’t. For example, you
can perform arithmetic, like addition (+), on a char but not a std::byte.


The size_t Type
You use the size_t type, also available in the <cstddef> header, to encode size
of objects. The size_t objects guarantee that their maximum values are sufficient to represent the maximum size in bytes of all objects. Technically,
this means a size_t could take 2 bytes or 200 bytes depending on the implementation. In practice, it’s usually identical to an unsigned long long on 64-bit
architectures.
The type size_t is a C type in the <stddef> header, but it’s identical to the C++ version, which resides in the std namespace. Occasionally, you’ll see the (technically correct) construction std::size_t instead.



void
The void type has an empty set of values. Because a void object cannot hold
a value, C++ disallows void objects. You use void in special situations, such as
the return type for functions that don’t return any value. For example, the
function taunt doesn’t return a value, so you declare its return type void:
#include <cstdio>
void taunt() {
printf("Hey, laser lips, your mama was a snow blower.");
}









## Type Sizes
Each Simple Data type corresponds directly to hardware facilities and has a fixed size that determines the range of values that can be stored in it.

A char variable is of the natural size to hold a character on a given machine (typically an 8-bit byte), and the sizes of other types are multiples of the size of a char.

The size of a type is implementation-defined (i.e., it can vary among different machines) and can be obtained by the sizeof operator; for example, sizeof(char) equals 1 and sizeof(int) is often 4.

C++11 introduced fixed-width integer types that allow you to
specify the exact width of the integer in bits. These are int8_t
or uint8_t for 8-bit signed and unsigned integers, respectively.
You may also use 16-bit (int16_t, uint16_t), 32-bit (int32_t,
uint32_t), and 64-bit (int64_t, uint64_t) integer types. To use
these types, remember to include header
<cstdint>.

bool                    true or false

char                    256 character values
signed char            -127 to 127
unsigned char          	0 to 255
wchar_t 	2 or 4 bytes 	1 wide character

short int              –32,768 to 32,767
unsigned short int      0 to 65,535
signed short int 	     -32768 to 32767

int (16 bit)           –32,768 to 32,767
int (32 bit)           –2,147,483,648 to 2,147,483,647
unsigned int (16 bit)   0 to 65,535
unsigned int (32 bit)   0 to 4,294,967,295

long int               –2,147,483,648 to 2,147,483,647
signed long int 	      same as long int
unsigned long int       0 to 4,294,967,295


long long              –9,223,372,036,854,775,808 to
                        9,223,372,036,854,775,807
unsigned long long      0 to 18,446,744,073,709,551,615
unsigned long long int  0 to 18,446,744,073,709,551,615

float                   1.2e–38 to 3.4e38
double                  2.2e–308 to 1.8e308
long double


Data types such as short, int, long, etc... have a finite capacity for containing numbers. When you exceed the limit imposed by the type chosen in an arithmetic operation, you create an overflow.







The data types mentioned thus far are often referred to as POD (Plain Old Data). The category POD contains these as well as aggregations (structs, enums, unions, or classes) thereof.

We call the types that can be built from the Simple Data types, the const modifier, and the declarator operators built-in types

Types built out of other types using C++’s abstraction mechanisms
are called user-defined types. They are referred to as classes and enumerations. User defined types
can be built out of both built-in types and other user-defined types.

The type qualifiers provide additional information about the variables they precede.

const Objects of type const cannot be changed by your program during execution.


volatile tells the compiler that a variable's value may be changed in ways not explicitly specified by the program.













## Reference Types
Reference types store the memory addresses of objects.

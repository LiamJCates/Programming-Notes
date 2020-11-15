The C++ Type System
C++ is an object-oriented language.

The collection of behaviors and states describing an object is called its
type. C++ is a strongly typed language, meaning each object has a predefined
data type.



Every name and every expression has a type that determines the operations that may be performed on it.

A declaration is a statement that introduces an entity into the program. It specifies a type for the entity:
• A type defines a set of possible values and a set of operations (for an object).
• An object is some memory that holds a value of some type.
• A value is a set of bits interpreted according to a type.
• A variable is a named object.





## Fundamental Types
Fundamental types are the most basic types of object and include integer,
floating-point, character, Boolean, byte, size_t, and void. Some refer to fundamental types as primitive or built-in types because they’re part of the core
language and almost always available to you. These types will work on any
platform, but their features, such as size and memory layout, depend on
implementation.

Fundamental types strike a balance. On one hand, they try to map a
direct relationship from C++ construct to computer hardware; on the other
hand, they simplify writing cross-platform code by allowing a programmer
to write code once that works on many platforms.




Integer Types
Integer types store whole numbers: those that you can write without a fractional component. The four sizes of integer types are short int, int, long int,
and long long int. Each can be either signed or unsigned. A signed variable can
be positive, negative, or zero, and an unsigned variable must be non-negative.
Integer types are signed and int by default, which means you can use the
following shorthand notations in your programs: short, long, and long long
rather than short int, long int, and long long int.

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

If you want to enforce guaranteed integer sizes, you can use integer types in the
<cstdint> library. For example, if you need a signed integer with exactly 8, 16, 32,
or 64 bits, you could use int8_t, int16_t, int32_t, or int64_t. You’ll find options
for the fastest, smallest, maximum, signed, and unsigned integer types to meet your
requirements. But because this header is not always available in every platform,
you should only use cstdint types when there is no other alternative.

bool // Boolean, possible values are true and false
char // character, for example, 'a', 'z', and '9'
int // integer, for example, -273, 42, and 1066
double // double-precision floating-point number, for example, -273.15, 3.14, and 6.626e-34
unsigned // non-negative integer, for example, 0, 1, and 999 (use for bitwise logical operations)


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





## Type Sizes
Each fundamental type corresponds directly to hardware facilities and has a fixed size that determines the range of values that can be stored in it.

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

We call the types that can be built from the fundamental types (§1.4), the const modifier (§1.6), and the declarator operators (§1.7) built-in types

Types built out of other types using C++’s abstraction mechanisms
are called user-defined types. They are referred to as classes and enumerations. User defined types
can be built out of both built-in types and other user-defined types.

The type qualifiers provide additional information about the variables they precede.

const Objects of type const cannot be changed by your program during execution.


volatile tells the compiler that a variable's value may be changed in ways not explicitly specified by the program.


restrict  A pointer qualified by restrict is initially the only means by which the object it points to can be accessed. Only C99 adds a new type qualifier called restrict.

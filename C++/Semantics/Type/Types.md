## Data Types

The objective of a C++ program is to manipulate binary data to achieve a desired result.

The underlying binary representation of various data entities is given semantic meaning according to the C++ type system.

C++ is a strongly typed object-oriented language meaning that all data values manipulated are of a predefined object type.

The operations that manipulate data objects and the legal states that a data object of a given type can assume are determined by it's data type.

By being so type conscious, C++ has built-in checks to guard against errors.




C++ data types fall into the following three categories:
  Simple data type
  Structured data type
  Pointers

A data type is called simple if variables of that type can store only one value at a time. In contrast, in a structured data type, each data item is a collection of other data items. Simple data types are building blocks of structured data types.

Every name and every expression has a type that determines the operations that may be performed on it.

A declaration is a statement that introduces an entity into the program. It specifies a type for the entity:
  A type defines an object's set of possible domain values and operations
  An object is some memory that holds a value of some type.
  A value is a set of bits interpreted according to a type.
  A variable is a named object.





## Simple Data Types
Simple Data types are the most basic types of object.

Some refer to Simple Data types as primitive or built-in types because they’re part of the core language and almost always available to you.

For more information on primitive types see:
[C++\Syntax\Statements\Declarations\PrimitiveTypes\_Primitives.md]

These types will work on any platform, but their features, such as size and memory layout, depend on implementation.

Simple Data types strike a balance. On one hand, they try to map a direct relationship from C++ construct to computer hardware; on the other hand, they simplify writing cross-platform code by allowing a programmer to write code once that works on many platforms.



The _t suffix

Many of the types defined in newer versions of C++ (e.g. std::nullptr_t) use a _t suffix. This suffix means “type”, and it’s a common nomenclature applied to modern types.

If you see something with a _t suffix, it’s probably a type. But many types don’t have a _t suffix, so this isn’t consistently applied.

































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
void means “no type”
The void type has an empty set of values.
Consequentially, variables can not be defined with a type of void:

  void value; // won't work, variables can't be defined with a void type

Because a void object cannot hold a value, C++ disallows void objects. You use void in special situations, such as the return type for functions that don’t return any value. For example, the function taunt doesn’t return a value, so you declare its return type void:

  #include <cstdio>

  void taunt()
  {
    printf("Hey, laser lips, your mama was a snow blower.");
  }


Deprecated: Functions that do not take parameters

In C, void is used as a way to indicate that a function does not take any parameters:

  int getValue(void) // void here means no parameters
  {
    int x;
    std::cin >> x;
    return x;
  }

Although this will compile in C++ (for backwards compatibility reasons), this use of keyword void is considered deprecated in C++. The following code is equivalent, and preferred in C++:

  int getValue() // empty function parameters is an implicit void
  {
    int x;
    std::cin >> x;
    return x;
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
wchar_t 2 or 4 bytes 	1 wide character

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

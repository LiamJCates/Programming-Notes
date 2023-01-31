Bitfields declare a class data member with explicit size, in bits. Adjacent bit field members may be packed to share and straddle the individual bytes.

A bit field declaration is a class data member declaration which uses the following declarator:

```
identifier(*) attr(*) : size 	(1) 	
identifier(*) attr(*) : size brace-or-equal-initializer 	(2) 	(since C++20)

(*) optional
```

The type of the bit field is introduced by the decl-specifier-seq of the declaration syntax.

#### attr(C++11)
optional sequence of any number of attributes

#### identifier
the name of the bit field that is being declared. The name is optional: nameless bitfields introduce the specified number of bits of padding

#### size
an integral constant expression with a value greater or equal to zero. When greater than zero, this is the number of bits that this bit field will occupy. The value zero is only allowed for nameless bitfields and has special meaning: it specifies that the next bit field in the class definition will begin at an allocation unit's boundary.

#### brace-or-equal-initializer
default member initializer to be used with this bit field

Explanation

The number of bits in a bit field sets the limit to the range of values it can hold:
```cpp
#include <iostream>
struct S {
 // three-bit unsigned field,
 // allowed values are 0...7
 unsigned int b : 3;

 //Memory Layout
 //[00000bbb]
 //where
 //b is the b bits
 //0 is padded bits
};

int main()
{
    S s = {6};
    ++s.b; // store the value 7 in the bit field
    std::cout << s.b << '\n';
    ++s.b; // the value 8 does not fit in this bit field
    std::cout << s.b << '\n'; // formally implementation-defined, typically 0
}
```

Multiple adjacent bit fields are usually packed together (although this behavior is implementation-defined):

```cpp
#include <iostream>
struct S {
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 2 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    // 3 bits: unused
    unsigned char b1 : 3, : 2, b2 : 6, b3 : 2;

		//Memory Layout
		//[00033222|22200111]
		//where
		//1 is the b1 bits
		//0 is padded bits
		//2 is the b2 bits
		//3 is the b3 bits
};
int main()
{
    std::cout << sizeof(S) << '\n'; // usually prints 2
}
```


The special unnamed bit field of size zero can be forced to break up padding. It specifies that the next bit field begins at the beginning of its allocation unit:

```cpp
#include <iostream>

struct S {
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 5 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3  
    unsigned char b1 : 3;
    unsigned char :0; // start a new byte
    unsigned char b2 : 6;
    unsigned char b3 : 2;

		//Memory Layout
		//[33222222|00000111]
		//where
		//1 is the b1 bits
		//0 is padded bits
		//2 is the b2 bits
		//3 is the b3 bits
};

int main()
{
    std::cout << sizeof(S) << '\n'; // usually prints 2
}
```




NOTE
The C++ language doesn't guarantee any particular bit packing or any particular bit ordering. So how data is actually stored in memory is highly dependent upon the target architecture.


If the specified size of the bit field is greater than the size of its type, the value is limited by the type:

std::uint8_t b : 1000;

would still hold values between 0 and 255. the extra bits become unused padding.

Because bit fields do not necessarily begin at the beginning of a byte, address of a bit field cannot be taken. Pointers and non-const references to bit fields are not possible. When initializing a const reference from a bit field, a temporary is created (its type is the type of the bit field), copy initialized with the value of the bit field, and the reference is bound to that temporary.

The type of a bit field can only be integral or enumeration type.

A bit field cannot be a static data member.

There are no default member initializers for bit fields:

int b : 1 = 0;
int b : 1 {0}

are ill-formed 	(until C++20)


In case of ambiguity between the size of the bit field and the default member initializer, the longest sequence of tokens that forms a valid size is chosen:

```cpp
int a;
const int b = 0;
struct S {
    // simple cases
    int x1 : 8 = 42;               // OK; "= 42" is brace-or-equal-initializer
    int x2 : 8 { 42 };             // OK; "{ 42 }" is brace-or-equal-initializer
    // ambiguities
    int y1 : true ? 8 : a = 42;    // OK; brace-or-equal-initializer is absent
    int y2 : true ? 8 : b = 42;    // error: cannot assign to const int
    int y3 : (true ? 8 : b) = 42;  // OK; "= 42" is brace-or-equal-initializer
    int z : 1 || new int { 0 };    // OK; brace-or-equal-initializer is absent
};
```

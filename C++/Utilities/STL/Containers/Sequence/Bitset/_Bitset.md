On modern computer architectures, the smallest addressable unit of memory is a byte. Since all objects need to have unique memory addresses, this means objects must be at least one byte in size. For most variable types, this is fine. However, for Boolean values, this is a bit wasteful. Boolean types only have two states: true (1), or false (0). This set of states only requires one bit to store. However, if a variable must be at least a byte, and a byte is 8 bits, that means a Boolean is using 1 bit and leaving the other 7 unused.

In the majority of cases, this is fine -- we’re usually not so hard-up for memory that we need to care about 7 wasted bits (we’re better off optimizing for understandability and maintainability). However, in some storage-intensive cases, it can be useful to “pack” 8 individual Boolean values into a single byte for storage efficiency purposes.

Doing these things requires that we can manipulate objects at the bit level. Fortunately, C++ gives us tools to do precisely this. Modifying individual bits within an object is called bit manipulation.

Bit manipulation is also useful in encryption and compression algorithms.

Instead of viewing objects as holding a single value, we can instead view them as a collection of individual bits. When individual bits of an object are used as Boolean values, the bits are called bit flags.

To define a set of bit flags, we’ll typically use an unsigned integer of the appropriate size (8 bits, 16 bits, 32 bits, etc… depending on how many flags we have), or std::bitset.


Bitsets

A bitset is a data structure that stores a fixed­size bit sequence. You can
manipulate each bit.

The STL offers the std::bitset in the <bitset> header.

  #include <bitset>

The class template bitset takes a single template parameter corresponding to the desired size. You could achieve similar functionality using a bool array, but bitset is optimized for space efficiency and provides some special convenience operations.


NOTE
The STL specializes std::vector<bool>, so it might benefit from the same space efficiencies as bitset.

  #include <bitset> // for std::bitset

  std::bitset<8> mybitset {}; // 8 bits in size means room for 8 flags

Bit manipulation is one of the few times when you should unambiguously use unsigned integers (or std::bitset).

A default constructed bitset contains all zero (false) bits. To initialize
bitsets with other contents, you can provide an unsigned long long value. This
integer’s bitwise representation sets the value of bitset. You can access individual bits in the bitset using operator[].


Bit numbering and bit positions

Given a sequence of bits, we typically number the bits from right to left, starting with 0 (not 1). Each number denotes a bit position.

76543210  Bit position
00000101  Bit sequence

Given the bit sequence 0000 0101, the bits that are in position 0 and 2 have value 1, and the other bits have value 0.


Printing in binary is a little harder, as std::cout doesn’t come with this capability built-in. Fortunately, the C++ standard library includes a type called std::bitset that will do this for us (in the <bitset> header). To use std::bitset, we can define a std::bitset variable and tell std::bitset how many bits we want to store. The number of bits must be a compile time constant. std::bitset can be initialized with an unsigned integral value (in any format, including decimal, octal, hex, or binary).

  #include <bitset> // for std::bitset
  #include <iostream>

  int main()
  {
  	// std::bitset<8> means we want to store 8 bits
  	std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
  	std::bitset<8> bin2{ 0xC5 }; // hexadecimal literal for binary 1100 0101

  	std::cout << bin1 << ' ' << bin2 << '\n';
  	std::cout << std::bitset<4>{ 0b1010 } << '\n'; // we can also print from std::bitset directly

  	return 0;
  }

Output:

11000101 11000101
1010


We can also create a temporary (anonymous) std::bitset to print a single value. In the above code, this line:

  std::cout << std::bitset<4>{ 0b1010 } << '\n'; // print std::bitset directly

creates a temporary std::bitset object with 4 bits, initializes it with 0b1010, prints the value in binary, and then discards the temporary std::bitset.




Bitset Operators

C++ provides 6 bit manipulation operators, often called bitwise operators:
[C++\Syntax\Statements\Expressions\Operators\Bitwise.md]

| Operation | Notes |
|-----------|-------| |
| bitset<N>([val]) | Constructs a bitset with initial value val, which can be either a string of 0s and 1s or an unsigned long long. Default constructor initializes all bits to zero. |
| bs[i] | Returns the value of the i-th bit: 1 returns true; 0 returns false. |
| bs.test(i) | Returns the value of the i-th bit: 1 returns true; 0 returns false. Performs bounds checking; throws std::out_of_range. |
| bs.set() | Sets all bits to 1. |
| bs.set(i, val) | Sets the i-th bit to val. Performs bounds checking; throws |
| std::out_of_range. |
| bs.reset() | Sets all bits to 0. |
| bs.reset(i) | Sets the i-th bit to zero. Performs bounds checking; throws std::out_of_range. |
| bs.flip() | Flips all the bits: (0 becomes 1; 1 becomes 0). |
| bs.flip(i) | Flips the i-th bit to zero. Performs bounds checking; throws std::out_of_range. |
| bs.count() | Returns the number of bits set to 1. |
| bs.size() | Returns the size N of the bitset. |
| bs.any() | Returns true if any bits are set to 1. |
| bs.none() | Returns true if all bits are set to 0. |
| bs.all() | Returns true if all bits are set to 1. |
| bs.to_string() | Returns the string representation of the bitset. |
| bs.to_ulong() | Returns the unsigned long representation of the bitset. |
| bs.to_ullong() | Returns the unsigned long long representation of the bitset |
|


When are bit flags most useful?

Astute readers may note that the above examples don’t actually save any memory. 8 booleans would normally take 8 bytes. But the above examples use 9 bytes (8 bytes to define the bit masks, and 1 bytes for the flag variable)!

Bit flags make the most sense when you have many identical flag variables. For example, in the example above, imagine that instead of having one person (me), you had 100. If you used 8 Booleans per person (one for each possible state), you’d use 800 bytes of memory. With bit flags, you’d use 8 bytes for the bit masks, and 100 bytes for the bit flag variables, for a total of 108 bytes of memory -- approximately 8 times less memory.

For most programs, the amount of memory using bit flags saved is not worth the added complexity. But in programs where there are tens of thousands or even millions of similar objects, using bit flags can reduce memory use substantially. It’s a useful optimization to have in your toolkit if you need it.

There’s another case where bit flags and bit masks can make sense. Imagine you had a function that could take any combination of 32 different options. One way to write that function would be to use 32 individual Boolean parameters:

  void someFunction(bool option1, bool option2, bool option3, bool option4, bool option5, bool option6, bool option7, bool option8, bool option9, bool option10, bool option11, bool option12, bool option13, bool option14, bool option15, bool option16, bool option17, bool option18, bool option19, bool option20, bool option21, bool option22, bool option23, bool option24, bool option25, bool option26, bool option27, bool option28, bool option29, bool option30, bool option31, bool option32);

Hopefully you’d give your parameters more descriptive names, but the point here is to show you how obnoxiously long the parameter list is.

Then when you wanted to call the function with options 10 and 32 set to true, you’d have to do so like this:

  someFunction(false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true);

This is ridiculously difficult to read (is that option 9, 10, or 11 that’s set to true?), and also means you have to remember which argument corresponds to which option (is setting the “edit flag” the 9th, 10th, or 11th parameter?) It may also not be very performant, as every function call has to copy 32 booleans from the caller to the function.

Instead, if you defined the function using bit flags like this:

  void someFunction(std::bitset<32> options);

Then you could use bit flags to pass in only the options you wanted:

  someFunction(option10 | option32);

Not only is this much more readable, it’s likely to be more performant as well, since it only involves 2 operations (one Bitwise OR and one parameter copy).

This is one of the reasons OpenGL, a well regarded 3d graphic library, opted to use bit flag parameters instead of many consecutive Boolean parameters.

Here’s a sample function call from OpenGL:
1

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the color and the depth buffer

GL_COLOR_BUFFER_BIT and GL_DEPTH_BUFFER_BIT are bit masks defined as follows (in gl2.h):

  #define GL_DEPTH_BUFFER_BIT               0x00000100
  #define GL_STENCIL_BUFFER_BIT             0x00000400
  #define GL_COLOR_BUFFER_BIT               0x00004000

Integer Types

Integer types store whole numbers, those that are specified without a fractional component.

The four sizes of integer types that represent numbers are
	short int
	int
	long int
	long long int

Each can be either signed or unsigned:
	A signed variable can be positive, negative, or zero
	An unsigned variable must be non-negative.

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


Why isn’t the size of the integer variables fixed?

The short answer is that this goes back to C, when computers were slow and performance was of the utmost concern. C opted to intentionally leave the size of an integer open so that the compiler implementors could pick a size for int that performs best on the target computer architecture.


### Fixed-width integers (C++11)

If you want to enforce guaranteed integer widths, you can use integer types specified in the <cstdint> library.

These types include:
	signed integers with exactly 8, 16, 32, or 64 bits
	int8_t, int16_t, int32_t, or int64_t.
	unsigned integers with exactly 8, 16, 32, or 64 bits
	uint8_t, uint16_t, uint32_t, or uint64_t.

C++ officially adopted these fixed-width integers as part of C++11. They can be accessed by including the cstdint header, where they are defined inside the std namespace.

	#include <cstdint>

If the using namespace std statement is not specified each typename must be prepended by the std namespace name and the scope resolution operator:

	std::type-name

You’ll find options for the fastest, smallest, maximum, signed, and unsigned integer types to meet your requirements. But because this header is not always available in every platform, you should only use cstdint types when there is no other alternative.

To help with cross-platform portability, C99 defined a set of fixed-width integers (in the stdint.h header) that are guaranteed to have the same size on any architecture.

These are defined as follows:
| Name | Type | Range | Notes |
|------|------|-------|-------|
| int8_t | 1 byte signed | -128 to 127 | Treated like a signed char on many systems. See note below. |
| std::uint8_t | 1 byte unsigned | 0 to 255 | Treated like an unsigned char on many systems. See note below. |
| std::int16_t | 2 byte signed | -32,768 to 32,767 |
| std::uint16_t | 2 byte unsigned | 0 to 65,535 |
| std::int32_t | 4 byte signed | -2,147,483,648 to 2,147,483,647 |
| std::uint32_t | 4 byte unsigned | 0 to 4,294,967,295 |
| std::int64_t | 8 byte signed | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| std::uint64_t | 8 byte unsigned | 0 to 18,446,744,073,709,551,615 |




The fixed-width integers have two downsides:
	They are optional and only exist if there are fundamental types matching their widths and following a certain binary representation. Using a fixed-width integer makes your code less portable, it might not compile on other systems.
	If you use a fixed-width integer, it may also be slower than a wider type on some architectures. If you need an integer to hold values from -10 to 20, you might be tempted to use std::int8_t. But your CPU might be better at processing 32 bit wide integers, so you just lost speed by making a restriction that wasn’t necessary.

Warning

The above fixed-width integers should be avoided, as they may not be defined on all target architectures.


### Fast and least integers

To help address the above downsides, C++ also defines two alternative sets of integers.

The fast type (std::int_fast#_t) provides the fastest signed integer type with a width of at least # bits (where # = 8, 16, 32, or 64). For example, std::int_fast32_t will give you the fastest signed integer type that’s at least 32 bits.

The least type (std::int_least#_t) provides the smallest signed integer type with a width of at least # bits (where # = 8, 16, 32, or 64). For example, std::int_least32_t will give you the smallest signed integer type that’s at least 32 bits.

Example using Visual Studio 32-bit console application:

  #include <cstdint>
  #include <iostream>

  int main()
  {
  	std::cout << "fast 8: " << sizeof(std::int_fast8_t) * 8 << " bits\n";
  	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
  	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";

  	std::cout << "least 8: " << sizeof(std::int_least8_t) * 8 << " bits\n";
  	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
  	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";

  	return 0;
  }

This produced the result:

	fast 8: 8 bits
	fast 16: 32 bits
	fast 32: 32 bits
	least 8: 8 bits
	least 16: 16 bits
	least 32: 32 bits

You can see that std::int_fast16_t was 32 bits, whereas std::int_least16_t was 16 bits.

There is also an unsigned set of fast and least types (std::uint_fast#_t and std::uint_least#_t).

These fast and least types are guaranteed to be defined, and are safe to use.

Best practice

Favor the std::int_fast#_t and std::int_least#_t integers when you need an integer guaranteed to be at least a certain minimum size.

Warning: std::int8_t and std::uint8_t may behave like chars instead of integers

Due to an oversight in the C++ specification, most compilers define and treat std::int8_t and std::uint8_t (and the corresponding fast and least fixed-width types) identically to types signed char and unsigned char respectively. Consequently, std::cin and std::cout may work differently than you’re expecting. Here’s a sample program showing this:

  #include <cstdint>
  #include <iostream>

  int main()
  {
      std::int8_t myint{65};
      std::cout << myint;

      return 0;
  }

On most systems, this program will print ‘A’ (treating myint as a char). However, on some systems, this may print 65 as expected.

For simplicity, it’s best to avoid std::int8_t and std::uint8_t (and the related fast and least types) altogether (use std::int16_t or std::uint16_t instead). However, if you do use std::int8_t or std::uint8_t, you should be careful of anything that would interpret std::int8_t or std::uint8_t as a char instead of an integer (this includes std::cout and std::cin).

Hopefully this will be clarified by a future draft of C++.

Warning

Avoid the 8-bit fixed-width integer types. If you do use them, note that they are often treated like chars.

Integer best practices

Now that fixed-width integers have been added to C++, the best practice for integers in C++ is as follows:

    int should be preferred when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2 byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
    If you need a variable guaranteed to be a particular size and want to favor performance, use std::int_fast#_t.
    If you need a variable guaranteed to be a particular size and want to favor memory conservation over performance, use std::int_least#_t. This is used most often when allocating lots of variables.

Avoid the following if possible:

    Unsigned types, unless you have a compelling reason.
    The 8-bit fixed-width integer types.
    Any compiler-specific fixed-width integers -- for example, Visual Studio defines __int8, __int16, etc…

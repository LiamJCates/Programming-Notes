Bit masks

In order to manipulate individual bits (e.g. turn them on or off), we need some way to identify the specific bits we want to manipulate. Unfortunately, the bitwise operators don’t know how to work with bit positions. Instead they work with bit masks.

A bit mask is a predefined set of bits that is used to select which specific bits will be modified by subsequent operations.

Consider a real-life case where you want to paint a window frame. If you’re not careful, you risk painting not only the window frame, but also the glass itself. You might buy some masking tape and apply it to the glass and any other parts you don’t want painted. Then when you paint, the masking tape blocks the paint from reaching anything you don’t want painted. In the end, only the non-masked parts (the parts you want painted) get painted.

A bit mask essentially performs the same function for bits -- the bit mask blocks the bitwise operators from touching bits we don’t want modified, and allows access to the ones we do want modified.

Let’s first explore how to define some simple bit masks, and then we’ll show you how to use them.

Defining bit masks in C++14

The simplest set of bit masks is to define one bit mask for each bit position. We use 0s to mask out the bits we don’t care about, and 1s to denote the bits we want modified.

Although bit masks can be literals, they’re often defined as symbolic constants so they can be given a meaningful name and easily reused.

Because C++14 supports binary literals, defining these bit masks is easy:

  #include <cstdint>

  constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
  constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
  constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2
  constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
  constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
  constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
  constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
  constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

Now we have a set of symbolic constants that represents each bit position. We can use these to manipulate the bits (which we’ll show how to do in just a moment).

Defining bit masks in C++11 or earlier

Because C++11 doesn’t support binary literals, we have to use other methods to set the symbolic constants. There are two good methods for doing this. Less comprehensible, but more common, is to use hexadecimal. If you need a refresher on hexadecimal, please revisit lesson 4.12 -- Literals.

  constexpr std::uint_fast8_t mask0{ 0x1 }; // hex for 0000 0001
  constexpr std::uint_fast8_t mask1{ 0x2 }; // hex for 0000 0010
  constexpr std::uint_fast8_t mask2{ 0x4 }; // hex for 0000 0100
  constexpr std::uint_fast8_t mask3{ 0x8 }; // hex for 0000 1000
  constexpr std::uint_fast8_t mask4{ 0x10 }; // hex for 0001 0000
  constexpr std::uint_fast8_t mask5{ 0x20 }; // hex for 0010 0000
  constexpr std::uint_fast8_t mask6{ 0x40 }; // hex for 0100 0000
  constexpr std::uint_fast8_t mask7{ 0x80 }; // hex for 1000 0000

This can be a little hard to read. One way to make it easier is to use the left-shift operator to shift a bit into the proper location:

  constexpr std::uint_fast8_t mask0{ 1 << 0 }; // 0000 0001
  constexpr std::uint_fast8_t mask1{ 1 << 1 }; // 0000 0010
  constexpr std::uint_fast8_t mask2{ 1 << 2 }; // 0000 0100
  constexpr std::uint_fast8_t mask3{ 1 << 3 }; // 0000 1000
  constexpr std::uint_fast8_t mask4{ 1 << 4 }; // 0001 0000
  constexpr std::uint_fast8_t mask5{ 1 << 5 }; // 0010 0000
  constexpr std::uint_fast8_t mask6{ 1 << 6 }; // 0100 0000
  constexpr std::uint_fast8_t mask7{ 1 << 7 }; // 1000 0000

Testing a bit (to see if it is on or off)

Now that we have a set of bit masks, we can use these in conjunction with a bit flag variable to manipulate our bit flags.

To determine if a bit is on or off, we use bitwise AND in conjunction with the bit mask for the appropriate bit:

  #include <cstdint>
  #include <iostream>

  int main()
  {
  	constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
  	constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
  	constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2
  	constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
  	constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
  	constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
  	constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
  	constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

  	std::uint_fast8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

  	std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
  	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

  	return 0;
  }

This prints:

bit 0 is on
bit 1 is off

Setting a bit

To set (turn on) a bit, we use bitwise OR equals (operator |=) in conjunction with the bit mask for the appropriate bit:

  #include <cstdint>
  #include <iostream>

  int main()
  {
    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2
    constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

    std::uint_fast8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= mask1; // turn on bit 1

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    return 0;
  }

This prints:

bit 1 is off
bit 1 is on

We can also turn on multiple bits at the same time using Bitwise OR:

1

flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time

Resetting a bit

To clear a bit (turn off), we use Bitwise AND and Bitwise NOT together:

  #include <cstdint>
  #include <iostream>

  int main()
  {
      constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
      constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
      constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2
      constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
      constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
      constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
      constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
      constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

      std::uint_fast8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

      std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

      flags &= ~mask2; // turn off bit 2

      std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

      return 0;
  }

This prints:

bit 2 is on
bit 2 is off

We can turn off multiple bits at the same time:

1

flags &= ~(mask4 | mask5); // turn bits 4 and 5 off at the same time

Flipping a bit

To toggle a bit state, we use Bitwise XOR:

  #include <cstdint>
  #include <iostream>

  int main()
  {
      constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
      constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
      constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2
      constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
      constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
      constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
      constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
      constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

      std::uint_fast8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

      std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
      flags ^= mask2; // flip bit 2
      std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
      flags ^= mask2; // flip bit 2
      std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

      return 0;
  }

This prints:

bit 2 is on
bit 2 is off
bit 2 is on

We can flip multiple bits simultaneously:

1

flags ^= (mask4 | mask5); // flip bits 4 and 5 at the same time

Bit masks and std::bitset

std::bitset supports the full set of bitwise operators. So even though it’s easier to use the functions (test, set, reset, and flip) to modify individual bits, you can use bitwise operators and bit masks if you want.

Why would you want to? The functions only allow you to modify individual bits. The bitwise operators allow you to modify multiple bits at once.

  #include <cstdint>
  #include <iostream>
  #include <bitset>

  int main()
  {
  	constexpr std::bitset<8> mask0{ 0b0000'0001 }; // represents bit 0
  	constexpr std::bitset<8> mask1{ 0b0000'0010 }; // represents bit 1
  	constexpr std::bitset<8> mask2{ 0b0000'0100 }; // represents bit 2
  	constexpr std::bitset<8> mask3{ 0b0000'1000 }; // represents bit 3
  	constexpr std::bitset<8> mask4{ 0b0001'0000 }; // represents bit 4
  	constexpr std::bitset<8> mask5{ 0b0010'0000 }; // represents bit 5
  	constexpr std::bitset<8> mask6{ 0b0100'0000 }; // represents bit 6
  	constexpr std::bitset<8> mask7{ 0b1000'0000 }; // represents bit 7

  	std::bitset<8> flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

  	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
  	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
  	flags ^= (mask1 | mask2); // flip bits 1 and 2

  	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
  	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
  	flags |= (mask1 | mask2); // turn bits 1 and 2 on

  	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
  	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
  	flags &= ~(mask1 | mask2); // turn bits 1 and 2 off

  	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
  	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

  	return 0;
  }

This prints:

bit 1 is off
bit 2 is on
bit 1 is on
bit 2 is off
bit 1 is on
bit 2 is on
bit 1 is off
bit 2 is off

Making bit masks meaningful

Naming our bit masks “mask1” or “mask2” tells us what bit is being manipulated, but doesn’t give us any indication of what that bit flag is actually being used for.

A best practice is to give your bit masks useful names as a way to document the meaning of your bit flags. Here’s an example from a game we might write:

  #include <cstdint>
  #include <iostream>

  int main()
  {
          // Define a bunch of physical/emotional states
  	constexpr std::uint_fast8_t isHungry{	1 << 0 }; // 0000 0001
  	constexpr std::uint_fast8_t isSad{		1 << 1 }; // 0000 0010
  	constexpr std::uint_fast8_t isMad{		1 << 2 }; // 0000 0100
  	constexpr std::uint_fast8_t isHappy{	1 << 3 }; // 0000 1000
  	constexpr std::uint_fast8_t isLaughing{ 1 << 4 }; // 0001 0000
  	constexpr std::uint_fast8_t isAsleep{	1 << 5 }; // 0010 0000
  	constexpr std::uint_fast8_t isDead{		1 << 6 }; // 0100 0000
  	constexpr std::uint_fast8_t isCrying{	1 << 7 }; // 1000 0000

  	std::uint_fast8_t me{}; // all flags/options turned off to start
  	me |= (isHappy | isLaughing); // I am happy and laughing
  	me &= ~isLaughing; // I am no longer laughing

  	// Query a few states
  	// (we'll use static_cast<bool> to interpret the results as a boolean value)
  	std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
  	std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';

  	return 0;
  }

Here’s the same example implemented using std::bitset:

  #include <iostream>
  #include <bitset>

  int main()
  {
          // Define a bunch of physical/emotional states
  	std::bitset<8> isHungry{	0b0000'0001 };
  	std::bitset<8> isSad{		0b0000'0010 };
  	std::bitset<8> isMad{		0b0000'0100 };
  	std::bitset<8> isHappy{		0b0000'1000 };
  	std::bitset<8> isLaughing{	0b0001'0000 };
  	std::bitset<8> isAsleep{	0b0010'0000 };
  	std::bitset<8> isDead{		0b0100'0000 };
  	std::bitset<8> isCrying{	0b1000'0000 };


  	std::bitset<8> me{}; // all flags/options turned off to start
  	me |= (isHappy | isLaughing); // I am happy and laughing
  	me &= ~isLaughing; // I am no longer laughing

  	// Query a few states (we use the any() function to see if any bits remain set)
  	std::cout << "I am happy? " << (me & isHappy).any() << '\n';
  	std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';

  	return 0;
  }

Two notes here: First, std::bitset doesn’t have a nice function that allows you to query bits using a bit mask. So if you want to use bit masks rather than positional indexes, you’ll have to use Bitwise AND to query bits. Second, we make use of the any() function, which returns true if any bits are set, and false otherwise to see if the bit we queried remains on or off.


Bit masks involving multiple bits

Although bit masks often are used to select a single bit, they can also be used to select multiple bits. Lets take a look at a slightly more complicated example where we do this.

Color display devices such as TVs and monitors are composed of millions of pixels, each of which can display a dot of color. The dot of color is composed from three beams of light: one red, one green, and one blue (RGB). By varying the intensity of the colors, any color on the color spectrum can be made. Typically, the amount of R, G, and B for a given pixel is represented by an 8-bit unsigned integer. For example, a red pixel would have R=255, G=0, B=0. A purple pixel would have R=255, G=0, B=255. A medium-grey pixel would have R=127, G=127, B=127.

When assigning color values to a pixel, in addition to R, G, and B, a 4th value called A is often used. “A” stands for “alpha”, and it controls how transparent the color is. If A=0, the color is fully transparent. If A=255, the color is opaque.

R, G, B, and A are normally stored as a single 32-bit integer, with 8 bits used for each component:
32-bit RGBA value
bits 31-24 	bits 23-16 	bits 15-8 	bits 7-0
RRRRRRRR 	GGGGGGGG 	BBBBBBBB 	AAAAAAAA
red 	green 	blue 	alpha

The following program asks the user to enter a 32-bit hexadecimal value, and then extracts the 8-bit color values for R, G, B, and A.

  #include <cstdint>
  #include <iostream>

  int main()
  {
  	constexpr std::uint_fast32_t redBits{ 0xFF000000 };
  	constexpr std::uint_fast32_t greenBits{ 0x00FF0000 };
  	constexpr std::uint_fast32_t blueBits{ 0x0000FF00 };
  	constexpr std::uint_fast32_t alphaBits{ 0x000000FF };

  	std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
  	std::uint_fast32_t pixel{};
  	std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

  	// use Bitwise AND to isolate red pixels,
  	// then right shift the value into the lower 8 bits
  	std::uint_fast8_t red{ static_cast<std::uint_fast8_t>((pixel & redBits) >> 24) };
  	std::uint_fast8_t green{ static_cast<std::uint_fast8_t>((pixel & greenBits) >> 16) };
  	std::uint_fast8_t blue{ static_cast<std::uint_fast8_t>((pixel & blueBits) >> 8) };
  	std::uint_fast8_t alpha{ static_cast<std::uint_fast8_t>(pixel & alphaBits) };

  	std::cout << "Your color contains:\n";
  	std::cout << std::hex; // print the following values in hex
  	std::cout << static_cast<int>(red) << " red\n";
  	std::cout << static_cast<int>(green) << " green\n";
  	std::cout << static_cast<int>(blue) << " blue\n";
  	std::cout << static_cast<int>(alpha) << " alpha\n";

  	return 0;
  }

This produces the output:

Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): FF7F3300
Your color contains:
ff red
7f green
33 blue
0 alpha

In the above program, we use a bitwise AND to query the set of 8 bits we’re interested in, and then we right shift them into an 8-bit value so we can print them back as hex values.

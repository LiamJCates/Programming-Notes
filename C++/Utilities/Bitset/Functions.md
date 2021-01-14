Bitset Functions

std::bitset provides 4 key functions that are useful for doing bit manipulation:

    test() allows us to query whether a bit is a 0 or 1
    set() allows us to turn a bit on (this will do nothing if the bit is already on)
    reset() allows us to turn a bit off (this will do nothing if the bit is already off)
    flip() allows us to flip a bit value from a 0 to a 1 or vice versa

Each of these functions takes the position of the bit we want to operate on as their only argument.

  #include <bitset>
  #include <iostream>

  int main()
  {
      std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
      bits.set(3); // set bit position 3 to 1 (now we have 0000 1101)
      bits.flip(4); // flip bit 4 (now we have 0001 1101)
      bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

      std::cout << "All the bits: " << bits << '\n';
      std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
      std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

      return 0;
  }

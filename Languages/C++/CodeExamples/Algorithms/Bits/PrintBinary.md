Print the binary representation of an unsigned int

Solution

An easy solution is to AND the ith bit with the number 2^i

Code

	#include <iostream>

	void bin(unsigned n)
	{
		for (unsigned i = 1 << 31; i > 0; i >>= 1)
			std::cout << ((n & i) ? 1 : 0);
	}




  #include <iostream>

  int main() {
    int decimal, binary = 0, remainder, product = 1;
    // Since the data type is int, it can only accept values up to 1023
    std::cin >> decimal;
    while (decimal != 0) {
      remainder = decimal % 2;
      binary = binary + (remainder * product);
      decimal = decimal / 2;
      product *= 10;
    }
    std::cout << "The number in the binary form is: " << binary ;
    return 0;
  }

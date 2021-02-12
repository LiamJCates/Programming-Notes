/*
Count the number of a given type of bits
*/

#include <bitset>
#include <string>
#include <algorithm>

std::string parity(int n)
{
  std::string bits = std::bitset< 64 >( n ).to_string();
  return std::count(begin(bits), end(bits), '1') % 2 ? "Odd" : "Even";
}


std::string parity(int n)
{
  std::bitset<32> bits(n);
  return (bits.count() & 1) ? "Odd" : "Even";
}

std::string evil(int n)
{
  return std::bitset<32>(n).count() & 1 ? "It's Odious!" : "It's Evil!";
}

std::string parity(int n)
{
	int ones = 0;

  for(; n; n /= 2)
    if (n % 2)
      ones++;

  return ((ones % 2) == 0 ? "Odd" : "Even";
}

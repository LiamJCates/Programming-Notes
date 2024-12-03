/*
To discover the number of bits in an integer, use std::numeric_limits

Most likely, you got 31, although some of you may have seen 15 or 63. The reason for this is that digits does not count the sign bit. Signed integers use a representation called two’s complement, which sets the most significant bit to 1 if the number is negative. Thus, for a type that represents a signed quantity, such as int, you must add one to digits, and for a type with no sign, such as bool, use digits without further modification. Fortunately, std::numeric_limits offers is_signed, which is true for a signed type and false for a type without a sign bit.
*/

#include <iostream>
#include <limits>

int main()
{
  std::cout << "bits per int = ";
  if (std::numeric_limits<int>::is_signed)
    std::cout << std::numeric_limits<int>::digits + 1 << '\n';
  else
    std::cout << std::numeric_limits<int>::digits << '\n';

  std::cout << "bits per bool = ";
  if (std::numeric_limits<bool>::is_signed)
    std::cout << std::numeric_limits<bool>::digits + 1 << '\n';
  else
    std::cout << std::numeric_limits<bool>::digits << '\n';
}

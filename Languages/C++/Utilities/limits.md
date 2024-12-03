


<limits>
int min{std::numeric_limits<int>::max()};
int max{std::numeric_limits<int>::min()};


The name std::numeric_limits is part of the C++ standard library and lets you query the attributes  of the built-in arithmetic types. You can determine the number of bits a type requires, the number of decimal digits, the minimum and maximum values, and more. Put the type that you are curious about in
angle brackets. (You’ll see this approach to using types quite often in C++.) Thus, you could also query
std::numeric_limits<bool>::min() and get false as the result.




### Bits

/*
To discover the number of bits in an integer, use std::numeric_limits

You may have gotten 31, although some of you may have seen 15 or 63. The reason for this is that digits does not count the sign bit. Signed integers use a representation called two’s complement, which sets the most significant bit to 1 if the number is negative. Thus, for a type that represents a signed quantity, such as int, you must add one to digits, and for a type with no sign, such as bool, use digits without further modification. Fortunately, std::numeric_limits offers is_signed, which is true for a signed type and false for a type without a sign bit.
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

  std::cout << "bits per long = ";
  if (std::numeric_limits<long>::is_signed)
    std::cout << std::numeric_limits<long>::digits + 1 << '\n';
  else
    std::cout << std::numeric_limits<long>::digits << '\n';

  std::cout << "bits per long long = ";
  if (std::numeric_limits<long long>::is_signed)
    std::cout << std::numeric_limits<long long>::digits + 1 << '\n';
  else
    std::cout << std::numeric_limits<long long>::digits << '\n';
}


You can query numeric_limits to reveal the size and limits of a floating-point type. You can also determine
whether the type allows infinity or NaN.


/** @file list2702.cpp */
/** Listing 27-2. Discovering the Attributes of a Floating-Point Type */
#include <cmath>
#include <iostream>
#include <limits>
#include <locale>

int main()
{
  std::cout.imbue(std::locale{""});
  std::cout << std::boolalpha;
  // Change float to double or long double to learn about those types.
  using T = float;
  std::cout << "min=" << std::numeric_limits<T>::min() << '\n'
       << "max=" << std::numeric_limits<T>::max() << '\n'
       << "IEC 60559? " << std::numeric_limits<T>::is_iec559 << '\n'
       << "max exponent=" << std::numeric_limits<T>::max_exponent << '\n'
       << "min exponent=" << std::numeric_limits<T>::min_exponent << '\n'
       << "mantissa places=" << std::numeric_limits<T>::digits << '\n'
       << "radix=" << std::numeric_limits<T>::radix << '\n'
       << "has infinity? " << std::numeric_limits<T>::has_infinity << '\n'
       << "has quiet NaN? " << std::numeric_limits<T>::has_quiet_NaN << '\n'
       << "has signaling NaN? " << std::numeric_limits<T>::has_signaling_NaN << '\n';

  if (std::numeric_limits<T>::has_infinity)
  {
    T zero{0};
    T one{1};
    T inf{std::numeric_limits<T>::infinity()};
    if (std::isinf(one/zero))
      std::cout << "1.0/0.0 = infinity\n";
    if (inf + inf == inf)
      std::cout << "infinity + infinity = infinity\n";
  }
  if (std::numeric_limits<T>::has_quiet_NaN)
  {
    // There's no guarantee that your environment produces quiet NaNs for
    // these illegal arithmetic operations. It's possible that your compiler's
    // default is to produce signaling NaNs, or to terminate the program
    // in some other way.
    T zero{};
    T inf{std::numeric_limits<T>::infinity()};
    std::cout << "zero/zero = " << zero/zero << '\n';
    std::cout << "inf/inf = " << inf/inf << '\n';
  }
}

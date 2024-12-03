## narrow_cast
a custom static_cast that performs a runtime check for narrowing. Narrowing is a loss in information. Think about converting from an int to a short. As long as the value of int fits into a short, the conversion is reversible and no narrowing occurs. If the value of int is too big for
the short, the conversion isn’t reversible and results in narrowing.


Let’s implement a named conversion called narrow_cast that checks for
narrowing and throws a runtime_error if it’s detected.

#include <stdexcept>
template <typename To, typename From>
To narrow_cast(From value)
{
  const auto converted = static_cast<To>(value);
  const auto backwards = static_cast<From>(converted);
  if (value != backwards) throw std::runtime_error{ "Narrowed!" };
  return converted;
}

The narrow_cast function template takes two template parameters: the type you’re casting To and the type you’re casting From. You can see these template parameters in action as the return type of the function and the type of the parameter value.
First, you perform the requested conversion using static_cast to yield converted. Next, you perform the conversion in the opposite direction (from converted to type From) to yield backwards. If value doesn’t equal backwards, you’ve narrowed, so you throw an exception.
Otherwise, you return converted.

#include <cstdio>
#include <stdexcept>
template <typename To, typename From>
To narrow_cast(From value)
{
  --snip--
}

int main()
{
  int perfect{ 496 };
  const auto perfect_short = narrow_cast<short>(perfect);
  printf("perfect_short: %d\n", perfect_short);
  try {
    int cyclic{ 142857 };
    const auto cyclic_short = narrow_cast<short>(cyclic);
    printf("cyclic_short: %d\n", cyclic_short);
  } catch (const std::runtime_error& e) {
    printf("Exception: %s\n", e.what());
  }
}

You first initialize perfect to 496 and then narrow_cast it to the short
perfect_short. This proceeds without exception because the value 496 fits
easily into a 2-byte short on Windows 10 x64 (maximum value 32767). You see
the output as expected. Next, you initialize cyclic to 142857 x and attempt
to narrow_cast to the short cyclic_short. This throws a runtime_error because
142857 is greater than the short’s maximum value of 32767. The check within
narrow_cast will fail. You see the exception printed in the output.
Notice that you need to provide only a single template parameter, the
return type, upon instantiation. The compiler can deduce the From
parameter based on usage.

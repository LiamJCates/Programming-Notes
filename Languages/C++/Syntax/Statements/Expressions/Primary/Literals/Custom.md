Make Up Your Own Literals
Although C++ does not offer a built-in way to create a short literal, you can define your own literal suffix.
Just as 42L has type long, you can invent a suffix, say, _S, to mean short, so 42_S is a compile-time constant
of type short. Listing 25-5 shows how you can define your own literal suffix.

#include <iostream>

short operator "" _S(unsigned long long value)
{
    return static_cast<short>(value);
}

void print(short s)
{
   std::cout << "short=" << s << '\n';
}

void print(int i)
{
   std::cout << "int=" << i << '\n';
}

int main()
{
   print(42);
   print(42_S);
}

When the user defines a literal, it is known as a user-defined literal, or UDL. The name of the literal must
begin with an underscore. This will let the C++ standard define additional literals that don’t start with an
underscore without fear of interfering with the literals you define. You can define a UDL for integer, floatingpoint, and string types.

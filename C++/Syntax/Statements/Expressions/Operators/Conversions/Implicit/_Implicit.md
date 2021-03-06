Implicit Type Conversion

The word “implicit” means ‘understood’ or ‘embedded’. In implicit C++ type casting, also called automatic type conversion or coercion, the data type in which the value is to be converted is not specified in the program. Implicit type conversion is a background transformation automatically handled by the C++ compiler.

Implicit type conversion is performed whenever one data type is expected by an expression, but a data of a different data type is specified by the source code. If the compiler can figure out how to do the conversion between the two types, it will do so without the need of any explicit operator. If it doesn’t know how, then it will fail with a compile error.


An example of this is arithmetic operations, where:
	shorter integral types are promoted to int types.
	Integral types can also be promoted to floating-point types





Implicit conversions are automatically performed when a value is copied to a compatible type. For example:

short a=2000;
int b;
b=a;

Here, as the type of b, the operand being assigned to, is of type int, and the type of a, the value being assigned, is short, a's value is implicitly promoted from short to int.

The result is that, in most situations, the type system simply gets out of your way so you can focus on programming logic.

Unfortunately, in some situations, C++ is a bit overzealous in silently
converting types via implicit conversion.

Consider the following implicit conversion from a double to a uint_8:

	#include <cstdint>

	int main()
	{
		auto x = 2.7182818284590452353602874713527L;
		uint8_t y = x; // Silent truncation
	}

You should hope that the compiler will generate a warning here, but technically this is valid C++. Because this conversion loses information, it’s a narrowing conversion that would be prevented by braced initialization {}:

	#include <cstdint>

	int main()
	{
		auto x = 2.7182818284590452353602874713527L;
		uint8_t y{ x }; // Bang!
	}

Recall that braced initialization doesn’t permit narrowing conversions.
Technically, the braced initializer is an explicit conversion

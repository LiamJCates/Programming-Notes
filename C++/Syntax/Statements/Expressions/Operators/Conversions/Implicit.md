Implicit Type Conversion

The word “implicit” means ‘understood’ or ‘embedded’. In implicit C++ type casting, also called automatic type conversion or coercion, the data type in which the value is to be converted is not specified in the program. Implicit type conversion is a background transformation automatically done by the C++ compiler.

Implicit type conversion is performed whenever one data type is expected by an expression, but a data of a different data type is specified by the source code. If the compiler can figure out how to do the conversion between the two types, it will do so without the need of any explicit operator. If it doesn’t know how, then it will fail with a compile error.


An example of this is arithmetic operations, where:
	shorter integral types are promoted to int types.
	Integral types can also be promoted to floating-point types


Implicit conversion
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










For non-fundamental types, arrays and functions implicitly convert to pointers, and pointers in general allow the following conversions:

    Null pointers can be converted to pointers of any type
    Pointers to any type can be converted to void pointers.
    Pointer upcast: pointers to a derived class can be converted to a pointer of an accessible and unambiguous base class, without modifying its const or volatile qualification.











Implicit conversions with classes
In the world of classes, implicit conversions can be controlled by means of three member functions:

    Single-argument constructors: allow implicit conversion from a particular type to initialize an object.
    Assignment operator: allow implicit conversion from a particular type on assignments.
    Type-cast operator: allow implicit conversion to a particular type.


For example:

// implicit conversion of classes:
#include <iostream>
using namespace std;

class A {};

class B {
public:
  // conversion from A (constructor):
  B (const A& x) {}
  // conversion from A (assignment):
  B& operator= (const A& x) {return *this;}
  // conversion to A (type-cast operator)
  operator A() {return A();}
};

int main ()
{
  A foo;
  B bar = foo;    // calls constructor
  bar = foo;      // calls assignment
  foo = bar;      // calls type-cast operator
  return 0;
}

The type-cast operator uses a particular syntax: it uses the operator keyword followed by the destination type and an empty set of parentheses. Notice that the return type is the destination type and thus is not specified before the operator keyword.

Keyword explicit
On a function call, C++ allows one implicit conversion to happen for each argument. This may be somewhat problematic for classes, because it is not always what is intended. For example, if we add the following function to the last example:

  void fn (B arg) {}

This function takes an argument of type B, but it could as well be called with an object of type A as argument:

  fn (foo);

This may or may not be what was intended. But, in any case, it can be prevented by marking the affected constructor with the explicit keyword:

// explicit:
#include <iostream>
using namespace std;

class A {};

class B {
public:
  explicit B (const A& x) {}
  B& operator= (const A& x) {return *this;}
  operator A() {return A();}
};

void fn (B x) {}

int main ()
{
  A foo;
  B bar (foo);
  bar = foo;
  foo = bar;

//  fn (foo);  // not allowed for explicit ctor.
  fn (bar);  

  return 0;
}


Edit & Run


Additionally, constructors marked with explicit cannot be called with the assignment-like syntax; In the above example, bar could not have been constructed with:

B bar = foo;

Type-cast member functions (those described in the previous section) can also be specified as explicit. This prevents implicit conversions in the same way as explicit-specified constructors do for the destination type.

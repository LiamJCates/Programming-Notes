Explicit Type Conversion

Explicit type conversions are also called casts.

There are many mechanisms that support



The first port of call for conducting an explicit type conversion is braced initialization {}. This approach has the major benefit of being fully type safe and non-narrowing. The use of braced initialization ensures at compile time that only safe, well-behaved, non-narrowing conversions are allowed.









Casting Operators
Casting is a mechanism by which the programmer can temporarily or permanently change the interpretation of an object by the compiler.

Operators that change the interpretation of an object are called casting operators.

| Name | Syntax | Overloadable |
|------|--------|--------------|
| C-Style Conversion | (type)a | Yes |
| Functional Conversion | type(a) | No |
| static_cast | static_cast<type>(a) | Yes |
| dynamic_cast | dynamic_cast<type>(a) | No |
| const_cast | const_cast<type>(a) | No |
| reinterpret_cast | reinterpret_cast<type>(a) | No |



Type casting operators allow to convert a value of a given type to another type. There are several ways to do this in C++.






### Explicit Type Conversion Operator: ()
Another way to do the same thing in C++ is to use the functional notation preceding the expression to be converted by the type and enclosing the expression between parentheses similar to the function-call syntax:

simple-type-name ( expression-list )

A simple-type-name followed by an expression-list enclosed in parentheses constructs an object of the specified type using the specified expressions.

Use the explicit type conversions with care, since they override the C++ compiler's built-in type checking.

The cast notation must be used for conversions to types that do not have a simple-type-name (pointer or reference types, for example). Conversion to types that can be expressed with a simple-type-name can be written in either form.

Type definition within casts is illegal.



The C++ language provides that if a class is derived from a base class containing virtual functions, a pointer to that base class type can be used to call the implementations of the virtual functions residing in the derived class object. A class containing virtual functions is sometimes called a "polymorphic class."

Since a derived class completely contains the definitions of all the base classes from which it is derived, it is safe to cast a pointer up the class hierarchy to any of these base classes. Given a pointer to a base class, it might be safe to cast the pointer down the hierarchy. It is safe if the object being pointed to is actually of a type derived from the base class. In this case, the actual object is said to be the "complete object." The pointer to the base class is said to point to a "subobject" of the complete object.





Legal Type Casts
| Destination Types | Potential Sources |
|-------------------|-------------------|
| Integral types | Any integer type or floating-point type, or pointer to an object |
| Floating-point | Any arithmetic type |
| A pointer to an object, or (void *) | Any integer type, (void *), a pointer to an object, or a function pointer |
| Function pointer | Any integral type, a pointer to an object, or a function pointer |
| A structure, union, or array | None |
| Void type | Any type |

Any identifier can be cast to void type. However, if the type specified in a type-cast expression is not void, then the identifier being cast to that type cannot be a void expression. Any expression can be cast to void, but an expression of type void cannot be cast to any other type. For example, a function with void return type cannot have its return cast to another type.

Note that a void * expression has a type pointer to void, not type void. If an object is cast to void type, the resulting expression cannot be assigned to any item. Similarly, a type-cast object is not an acceptable l-value, so no assignment can be made to a type-cast object.

Microsoft Specific

A type cast can be an l-value expression as long as the size of the identifier does not change. For information on l-value expressions, see L-Value and R-Value Expressions.

END Microsoft Specific

You can convert an expression to type void with a cast, but the resulting expression can be used only where a value is not required. An object pointer converted to void * and back to the original type will return to its original value.





Use const_cast and reinterpret_cast as a last resort, since these operators present the same dangers as old style casts. However, they are still necessary in order to completely replace old style casts.

For example, if you need to modify a const object, you would first need to cast away the const qualifier. The named conversion function const_cast allows you to perform this operation. Other named conversions help you to reverse implicit casts (static_cast) or reinterpret memory with a different type (reinterpret_cast).

Although named conversion functions aren’t technically template functions, they are conceptually very close to templates—a relationship reflected in their syntactic similarity.




static_cast






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

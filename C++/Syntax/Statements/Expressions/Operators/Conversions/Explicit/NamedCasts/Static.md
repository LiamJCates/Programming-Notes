## static_cast

static_cast can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), but also downcasts (from pointer-to-base to pointer-to-derived). No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. Therefore, it is up to the programmer to ensure that the conversion is safe. On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.

class Base {};
class Derived: public Base {};
Base * a = new Base;
Derived * b = static_cast<Derived*>(a);




This would be valid code, although b would point to an incomplete object of the class and could lead to runtime errors if dereferenced.

Therefore, static_cast is able to perform with pointers to classes not only the conversions allowed implicitly, but also their opposite conversions.

static_cast is also able to perform all conversions allowed implicitly (not only those with pointers to classes), and is also able to perform the opposite of these. It can:

    Convert from void* to any pointer type. In this case, it guarantees that if the void* value was obtained by converting from that same pointer type, the resulting pointer value is the same.
    Convert integers, floating-point values and enum types to enum types.


Additionally, static_cast can also perform the following:

    Explicitly call a single-argument constructor or a conversion operator.
    Convert to rvalue references.
    Convert enum class values into integers or floating-point values.
    Convert any type to void, evaluating and discarding the value.


static_cast

When a value of one data type is automatically
changed to another data type, an implicit type coercion is said to have occurred.
As the examples in the preceding section illustrate, if you are not careful about data
types, implicit type coercion can generate unexpected results.
To avoid implicit type coercion, C++ provides for explicit type conversion through
the use of a cast operator. The cast operator, also called type conversion or type
casting, takes the following form:
static_cast<dataTypeName>(expression)
First, the expression is evaluated. Its value is then converted to a value of the type
specified by dataTypeName. In C++, static_cast is a reserved word.

| Expression | Evaluates to |
|------------|--------------|
| static_cast<int>(7.9) | 7 |
| static_cast<double>(25) | 25.0 |
| static_cast<double>(5 + 3) | = static_cast<double>(8) = 8.0 |
| static_cast<double>(15) / 2 | = 15.0 / 2 = 7.5 |
| static_cast<double>(15/2) | = static_cast<double>(7) = 7.0 |
| static_cast<int>(7.8 + static_cast<double>(15)/2) | = static_cast<int>(7.8 + 7.5) = static_cast<int>(15.3) = 15 |
| static_cast<int>(7.8 + static_cast<double>(15/2)) | = static_cast<int>(7.8 + 7.0) = static_cast<int>(14.8) = 14 |
| static_cast<int>('A') | = 65 |
|  static_cast<char>(56) | = '8' |

NOTE
In C++, the cast operator can also take the form dataType(expression). This form is called C-like casting. For example, double(5) = 5.0 and int(17.6) = 17.

However, static_cast is more stable than C-like casting.



The static_cast reverses a well-defined implicit conversion, such as an integer type to another integer type. The object-to-cast is of some type that the
desired-type implicitly converts to. The reason you might need static_cast is
that, generally, implicit casts aren’t reversible.

The next program defines an increment_as_short function that takes a void pointer argument. It employs a static_cast to create a short pointer from this argument, increment the pointed-to short, and return the result. In some low-level applications, such as network programming or handling binary file formats, you might need to interpret raw bytes as an integer type.

#include <cstdio>

short increment_as_short(void* target)
{
  auto as_short = static_cast<short*>(target);
  *as_short = *as_short + 1;
  return *as_short;
}

int main() {
  short beast{ 665 };
  auto mark_of_the_beast = increment_as_short(&beast);
  printf("%d is the mark_of_the_beast.", mark_of_the_beast);
}

The target parameter is a void pointer. You employ static_cast to cast
target into a short*. The template parameter is the desired type, and
the function parameter is the object you want to cast into.

Notice that the implicit conversion of short* to void* is well defined.
Attempting ill-defined conversions with static_cast, such as converting a
char* to a float*, will result in a compiler error:
float on = 3.5166666666;
auto not_alright = static_cast<char*>(&on); // Bang!

To perform such chainsaw juggling, you need to use reinterpret_cast

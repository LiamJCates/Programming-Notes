Casting Operators
Casting is a mechanism by which the programmer can temporarily or permanently change the interpretation of an object by the compiler.

Operators that change the interpretation of an object are called casting operators.

| Name | Syntax | Overloadable |
|------|--------|--------------|
| C-Style Conversion | (type)a | Yes |
| Conversion | type(a) | No |
| static_cast | static_cast<type>(a) | Yes |
| dynamic_cast | dynamic_cast<type>(a) | No |
| const_cast | const_cast<type>(a) | No |
| reinterpret_cast | reinterpret_cast<type>(a) | No |



Type casting operators allow to convert a value of a given type to another type. There are several ways to do this in C++.


### C-style
The simplest one, inherited from the C language, is to precede the expression to be converted by the new type enclosed between parentheses (()):

unary-expression ( type-name ) cast-expression

The compiler treats cast-expression as type (type-name) after a type cast has been made. Casts can be used to convert objects of any scalar type to or from any other scalar type. Explicit type casts are constrained by the same rules that determine the effects of implicit conversions. Additional restraints on casts may result from the actual sizes or representation of specific types.



### Explicit Type Conversion Operator: ()
Another way to do the same thing in C++ is to use the functional notation preceding the expression to be converted by the type and enclosing the expression between parentheses similar to the function-call syntax:

simple-type-name ( expression-list )

A simple-type-name followed by an expression-list enclosed in parentheses constructs an object of the specified type using the specified expressions.

Use the explicit type conversions with care, since they override the C++ compiler's built-in type checking.

The cast notation must be used for conversions to types that do not have a simple-type-name (pointer or reference types, for example). Conversion to types that can be expressed with a simple-type-name can be written in either form.

Type definition within casts is illegal.



The C++ language provides that if a class is derived from a base class containing virtual functions, a pointer to that base class type can be used to call the implementations of the virtual functions residing in the derived class object. A class containing virtual functions is sometimes called a "polymorphic class."

Since a derived class completely contains the definitions of all the base classes from which it is derived, it is safe to cast a pointer up the class hierarchy to any of these base classes. Given a pointer to a base class, it might be safe to cast the pointer down the hierarchy. It is safe if the object being pointed to is actually of a type derived from the base class. In this case, the actual object is said to be the "complete object." The pointer to the base class is said to point to a "subobject" of the complete object.



### Named Conversion
Named conversions are language features that explicitly convert one type into
another type. You use named conversions sparingly in situations where you
cannot use implicit conversions or constructors to get the types you need.
All named conversions accept a single object parameter, which is the
object you want to cast object-to-cast, and a single type parameter, which is
the type you want to cast to desired-type:

named-conversion<desired-type>(object-to-cast)

There are casting operators specific to the C++ language, intended to remove some of the ambiguity and danger inherent in old style C language casts.

These operators are:
  dynamic_cast Used for conversion of polymorphic types.
  static_cast Used for conversion of nonpolymorphic types.
  const_cast Used to remove the const, volatile, and __unaligned attributes.
  reinterpret_cast Used for simple reinterpretation of bits.
  safe_cast Used in C++/CLI to produce verifiable MSIL.




You can use type casts to explicitly convert types.

Syntax

cast-expression:
    unary expression
    ( type-name ) cast-expression

type-name:
    specifier-qualifier-list abstract-declaratoropt

The type-name is a type and cast-expression is a value to be converted to that type. An expression with a type cast is not an l-value. The cast-expression is converted as though it had been assigned to a variable of type type-name. The conversion rules for assignments (outlined in Assignment Conversions) apply to type casts as well. The following table shows the types that can be cast to any given type.

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

const_cast
The const_cast function shucks away the const modifier, allowing the modification of const values. The object-to-cast is of some const type, and the
desired-type is that type minus the const qualifier.


void carbon_thaw(const int& encased_solo)
{
  //encased_solo++;     // Compiler error; modifying const
  auto& hibernation_sick_solo = const_cast<int&>(encased_solo);
  hibernation_sick_solo++;
}

The encased_solo parameter is const, so any attempt to modify it would result in a compiler error.

You use const_cast to obtain the non-const reference hibernation_sick_solo. The const_cast takes a single template parameter, the type you want to cast into. It also takes a function parameter, the object you want to remove const from.

You’re then free to modify the int pointed to by encased_solo via the new, non-const reference.

Only use const_cast to obtain write access to const objects. Any other
type conversion will result in a compiler error.

N O T E
Trivially, you can use const_cast to add const to an object’s type, but you shouldn’t because it’s verbose and unnecessary. Use an implicit cast instead. You can also use const_cast to remove the volatile modifier from an object.


static_cast

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

reinterpret_cast
Sometimes in low-level programming, you must perform type conversions that are not well defined. In system programming and especially in
embedded environments, you often need complete control over how to
interpret memory. The reinterpret_cast gives you such control, but ensuring the correctness of these conversions is entirely your responsibility.
Suppose your embedded device keeps an unsigned long timer at memory
address 0x1000. You could use reinterpret_cast to read from the timer, as
demonstrated in Listing 6-5.
#include <cstdio>
int main() {
auto timer = reinterpret_castu<const unsigned long*v>(0x1000w);
printf("Timer is %lu.", *timer);
}
Listing 6-5: A program using reinterpret_cast. This program will compile, but you should
expect a runtime crash unless 0x1000 is readable.

The reinterpret_cast u takes a type parameter corresponding to the
desired pointer type v and the memory address the result should point to w.
Of course, the compiler has no idea whether the memory at address
0x1000 contains an unsigned long. It’s entirely up to you to ensure correctness. Because you’re taking full responsibility for this very dangerous construction, the compiler forces you to employ reinterpret_cast. You couldn’t,
for example, replace the initialization of timer with the following line:
const unsigned long* timer{ 0x1000 };
The compiler will grumble about converting an int to a pointer.


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

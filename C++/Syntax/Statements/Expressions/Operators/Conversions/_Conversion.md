Type Conversions
You perform type conversions when you have one type but want to convert
it to another type. Depending on the situation, type conversions can be
explicit or implicit.

Implicit Type Conversions
Implicit type conversions can occur anywhere a particular type is called for
but you provide a different type.




Whenever an
arithmetic operation occurs, shorter integral types are promoted to int
types. Integral types can also be promoted to floating-point types during
arithmetic operation. All of this happens in the background. The result is
that, in most situations, the type system simply gets out of your way so you
can focus on programming logic.
Unfortunately, in some situations, C++ is a bit overzealous in silently
converting types. Consider the following implicit conversion from a double
to a uint_8:
#include <cstdint>
int main() {
auto x = 2.7182818284590452353602874713527L;
uint8_t y = x; // Silent truncation
}
You should hope that the compiler will generate a warning here, but
technically this is valid C++. Because this conversion loses information, it’s
a narrowing conversion that would be prevented by braced initialization {}:
#include <cstdint>
int main() {Expressions 199
auto x = 2.7182818284590452353602874713527L;
uint8_t y{ x }; // Bang!
}
Recall that braced initialization doesn’t permit narrowing conversions.
Technically, the braced initializer is an explicit conversion


Floating-Point-to-Integer Conversion
Floating-point and integral types can coexist peacefully within arithmetic
expressions. The reason is implicit type conversion: when the compiler
encounters mixed types, it performs the necessary promotions so arithmetic
proceeds as expected.

Integer-to-Integer Conversion
Integers can be converted into other integer types. If the destination type
is signed, all is well, as long as the value can be represented. If it cannot, the
behavior is implementation defined. If the destination type is unsigned, the
result is as many bits as can fit into the type. In other words, the high-order
bits are lost.

Floating-Point-to-Floating-Point Conversions
Floating-point numbers can be implicitly cast to and from other floatingpoint numbers. As long as the destination value can fit the source value,
all is well. When it cannot, you have undefined behavior. Again, braced200 Chapter 7
initialization can prevent potentially dangerous conversions.

Conversion to bool
Pointers, integers, and floating-point numbers can all be implicitly converted to bool objects. If the value is nonzero, the result of implicit conversion is true. Otherwise, the result is false. For example, the value int{ 1 }
converts to true, and the value int{} converts to false.

Pointer to void*
Pointers can always be implicitly converted to void*



Explicit Type Conversion
Explicit type conversions are also called casts. The first port of call for conducting an explicit type conversion is braced initialization {}. This approach
has the major benefit of being fully type safe and non-narrowing. The use
of braced initialization ensures at compile time that only safe, well-behaved,
non-narrowing conversions are allowed.



Casts








C-Style Casts
C-style casts, but this is done mainly to maintain some compatibility between the languages. Their usage is as follows:
(desired-type)object-to-cast

For each C-style cast, there exists some incantation of static_casts,
const_casts, and reinterpret_casts that would achieve the desired type conversion. C-style casts are far more dangerous than the named casts (and
this is saying quite a bit).
The syntax of the C++ explicit casts is intentionally ugly and verbose.
This calls attention to a point in the code where the rigid rules of the type
system are being bent or broken. The C-style cast doesn’t do this. In addition, it’s not clear from the cast what kind of conversion the programmer is
intending. When you use finer instruments like the named casts, the compiler can at least enforce some constraints. For example, it’s all too easy to
forget const correctness when using a C-style cast when you only intended a
reinterpret_cast.



User-Defined Type Conversions
In user-defined types, you can provide user-defined conversion functions.
These functions tell the compiler how your user-defined types behave during implicit and explicit type conversion. You can declare these conversion
functions using the following usage pattern:
struct MyType {
operator destination-type() const {
// return a destination-type from here.
--snip--
}
}
For example, the struct in Listing 7-15 can be used like a read-only int.
struct ReadOnlyInt {
ReadOnlyInt(int val) : val{ val } { }
operator int() const {
return val;
}
private:
const int val;
};
Listing 7-15: A ReadOnlyInt class containing a user-defined type conversion to an int

The operator int method at defines the user-defined type conversion
from a ReadOnlyInt to an int. You can now use ReadOnlyInt types just like regular int types thanks to implicit conversion:
struct ReadOnlyInt {
--snip--
};
int main() {
ReadOnlyInt the_answer{ 42 };
auto ten_answers = the_answer * 10; // int with value 420
}

Sometimes, implicit conversions can cause surprising behavior. You
should always try to use explicit conversions, especially with user-defined
types. You can achieve explicit conversions with the explicit keyword.
Explicit constructors instruct the compiler not to consider the constructor
as a means for implicit conversion. You can provide the same guidelines for
your user-defined conversion functions:
struct ReadOnlyInt {
ReadOnlyInt(int val) : val{ val } { }
explicit operator int() const {
return val;
}
private:
const int val;
};
Now, you must explicitly cast a ReadOnlyInt to an int using static_cast:
struct ReadOnlyInt {
--snip--
};
int main() {
ReadOnlyInt the_answer{ 42 };
auto ten_answers = static_cast<int>(the_answer) * 10;
}
Generally, this approach tends to promote less ambiguous code.

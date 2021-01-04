Move Semantics
Copying can be quite time-consuming at runtime when a large amount of data is involved. Often, you just want to transfer ownership of resources from one object to another. You could make a copy and destroy the original, but
this is often inefficient. Instead, you can move.

Move semantics is move’s corollary to copy semantics, and it requires that after an object y is moved into an object x, x is equivalent to the former value of y.

After the move, y is in a special state called the moved-from state. You can perform only two operations on moved-from objects: (re)assign them or destruct them.

Note that moving an object y into an object x isn’t just a renaming: these are separate objects with separate storage and potentially separate lifetimes.

Similar to how you specify copying behavior, you specify how objects move with move constructors and move assignment operators.


Value Categories
Every expression has two important characteristics: its type and its value category.

A value category describes what kinds of operations are valid for the expression. Thanks to the evolutionary nature of C++, value categories are complicated: an expression can be a “generalized lvalue” (glvalue), a “pure rvalue” (prvalue), an “expiring value” (xvalue), an lvalue (a glvalue that isn’t an xvalue), or an rvalue (a prvalue or an xvalue).

Fortunately for the newcomer, you don’t need to know much about most of these value categories.

We’ll consider a very simplified view of value categories. For now, you’ll just need a general understanding of lvalues and rvalues:

An lvalue is any value that has a name, and an rvalue is anything that isn’t an lvalue.

## lvalue and rvalue References
You can communicate to the compiler that a function accepts lvalues or rvalues using lvalue references and rvalue references. Up to this point, every reference parameter has been an lvalue reference, and these are denoted with a single &. You can also take a parameter by rvalue reference using &&.

Fortunately, the compiler does an excellent job of determining whether an object is an lvalue or an rvalue. In fact, you can define multiple functions with the same name but with different parameters, and the compiler will automatically call the correct version depending on what arguments you provide when you invoke the function.

#include <cstdio>
void ref_type(int &x)
{
  printf("lvalue reference %d\n", x);
}

void ref_type(int &&x)
{
  printf("rvalue reference %d\n", x);
}

int main() {
  auto x = 1;
  ref_type(x);
  ref_type(2);
  ref_type(x + 2);
}

Output:
lvalue reference 1
rvalue reference 2
rvalue reference 3

The int &x version takes an lvalue reference
The int &&x version takes an rvalue reference.

ref_type is invoked three times:
  First, you invoke the lvalue reference version, because x is an lvalue (it has a name).
  Second, you invoke the rvalue reference version because 2 is an integer literal without a name.
  Third, the result of adding 2 to x is not bound to a name, so it’s an rvalue.


The std::move Function
You can cast an lvalue reference to an rvalue reference using the std::move
function from the <utility> header.

#include <utility>
--snip--
int main() {
  auto x = 1;
  ref_type(std::move(x)); u
  ref_type(2);
  ref_type(x + 2);
}

As expected, std::move changes the lvalue into an rvalue. You never
call the lvalue ref_type overload.

The C++ committee probably should have named std::move as std::rvalue, but it’s
the name we’re stuck with. The std:move function doesn’t actually move anything—
it casts.

Be very careful when you’re using std::move, because you remove the
safeguards keeping you from interacting with a moved-from object. You can
perform two actions on a moved-from object: destroy it or reassign it.
How lvalue and rvalue semantics enable move semantics should now be
clear. If an lvalue is at hand, moving is suppressed. If an rvalue is at hand,
moving is enabled.

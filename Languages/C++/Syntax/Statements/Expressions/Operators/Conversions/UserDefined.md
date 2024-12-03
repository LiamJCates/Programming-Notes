User-Defined Type Conversions
In user-defined types, you can provide user-defined conversion functions.

These functions tell the compiler how your user-defined types behave during implicit and explicit type conversion.






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



















You can declare these conversion
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

Additionally, constructors marked with explicit cannot be called with the assignment-like syntax; In the above example, bar could not have been constructed with:

B bar = foo;

Type-cast member functions can also be specified as explicit. This prevents implicit conversions in the same way as explicit-specified constructors do for the destination type.

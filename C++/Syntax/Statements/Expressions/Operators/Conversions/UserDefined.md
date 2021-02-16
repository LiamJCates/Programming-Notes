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

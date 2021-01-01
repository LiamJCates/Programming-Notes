Generic Programming
The form of generic programming supported by C++ centers around the idea of abstracting from
concrete, efficient algorithms to obtain generic algorithms that can be combined with different data
representations to produce a wide variety of useful software [Stepanov,2009]. The abstractions representing the fundamental operations and data structures are called concepts; they appear as
requirements for template parameters.Section 7.3.1 Use of Concepts 99
7.3.1 Use of Concepts
Good, useful concepts are fundamental and are discovered more than they are designed. Examples
are integer and floating-point number (as defined even in Classic C), sequence, and more general
mathematical concepts, such as field and vector space. They represent the fundamental concepts of
a field of application. That is why they are called ‘‘concepts.’’ Identifying and formalizing concepts to the degree necessary for effective generic programming can be a challenge.
For basic use, consider the concept Regular (§12.7). A type is regular when it behaves much
like an int or a vector. An object of a regular type
• can be default constructed.
• can be copied (with the usual semantics of copy, yielding two objects that are independent
and compare equal) using a constructor or an assignment.
• can be compared using == and !=.
• doesn’t suffer technical problems from overly clever programming tricks.
A string is another example of a regular type. Like int, string is also StrictTotallyOrdered (§12.7).
That is, two strings can be compared using <, <=, >, and >= with the appropriate semantics.
A concept is not just a syntactic notion, it is fundamentally about semantics. For example,
don’t define + to divide; that would not match the requirements for any reasonable number. Unfortunately, we do not yet have any language support for expressing semantics, so we have to rely on
expert knowledge and common sense to get semantically meaningful concepts. Do not define
semantically meaningless concepts, such as Addable and Subtractable. Instead, rely on domain
knowledge to define concepts that match fundamental concepts in an application domain.
7.3.2 Abstraction Using Templates
Good abstractions are carefully grown from concrete examples. It is not a good idea to try to
‘‘abstract’’ by trying to prepare for every conceivable need and technique; in that direction lies ineleg ance and code bloat. Instead, start with one – and preferably more – concrete examples from real
use and try to eliminate inessential details. Consider:
double sum(const vector<int>& v)
{
double res = 0;
for (auto x : v)
res += x;
return res;
}
This is obviously one of many ways to compute the sum of a sequence of numbers.
Consider what makes this code less general than it needs to be:
• Why just ints?
• Why just vectors?
• Why accumulate in a double?
• Why start at 0?
• Why add?
Answering the first four questions by making the concrete types into template arguments, we get
the simplest form of the standard-library accumulate algorithm:100 Concepts and Generic Programming Chapter 7
template<typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val res)
{
for (auto p = first; p!=last; ++p)
res += ∗p;
return res;
}
Here, we have:
• The data structure to be traversed has been abstracted into a pair of iterators representing a
sequence (§12.1).
• The type of the accumulator has been made into a parameter.
• The initial value is now an input; the type of the accumulator is the type of this initial value.
A quick examination or – even better – measurement will show that the code generated for calls
with a variety of data structures is identical to what you get from the hand-coded original example.
For example:
void use(const vector<int>& vec, const list<double>& lst)
{
auto sum = accumulate(begin(vec),end(vec),0.0); // accumulate in a double
auto sum2 = accumulate(begin(lst),end(lst),sum);
//
}
The process of generalizing from a concrete piece of code (and preferably from several) while preserving performance is called lifting. Conversely, the best way to develop a template is often to
• first, write a concrete version
• then, debug, test, and measure it
• finally, replace the concrete types with template arguments.
Naturally, the repetition of begin() and end() is tedious, so we can simplify the user interface a bit:
template<Rang e R, Number Val> // a Range is something with begin() and end()
Val accumulate(const R& r, Val res = 0)
{
for (auto p = begin(r); p!=end(r); ++p)
res += ∗p;
return res;
}
For full generality, we can abstract the += operation also; see §14.3.
7.4 Variadic Templates
A template can be defined to accept an arbitrary number of arguments of arbitrary types. Such a
template is called a variadic template. Consider a simple function to write out values of any type
that has a << operator:Section 7.4 Variadic Templates 101
void user()
{
print("first: ", 1, 2.2, "hello\n"s); // first: 1 2.2 hello
print("\nsecond: ", 0.2, 'c', "yuck!"s, 0, 1, 2, '\n'); // second: 0.2 c yuck! 0 1 2
}
Traditionally, implementing a variadic template has been to separate the first argument from the rest
and then recursively call the variadic template for the tail of the arguments:
void print()
{
// what we do for no arguments: nothing
}
template<typename T, typename ... Tail>
void print(T head, Tail... tail)
{
// what we do for each argument, e.g.,
cout << head << ' ';
print(tail...);
}
The typename ... indicates that Tail is a sequence of types. The Tail... indicates that tail is a sequence
of values of the types in Tail. A parameter declared with a ... is called a parameter pack. Here, tail
is a (function argument) parameter pack where the elements are of the types found in the (template
argument) parameter pack Tail. So, print() can take any number of arguments of any types.
A call of print() separates the arguments into a head (the first) and a tail (the rest). The head is
printed and then print() is called for the tail. Eventually, of course, tail will become empty, so we
need the no-argument version of print() to deal with that. If we don’t want to allow the zero-argument case, we can eliminate that print() using a compile-time if:
template<typename T, typename ... Tail>
void print(T head, Tail... tail)
{
cout << head << ' ';
if constexpr(siz eof...(tail)> 0)
print(tail...);
}
I used a compile-time if (§6.4.3), rather than a plain run-time if to avoid a final, never called, call
print() from being generated.
The strength of variadic templates (sometimes just called variadics) is that they can accept any
arguments you care to give them. Weaknesses include
• The recursive implementations can be tricky to get right.
• The recursive implementations can be surprisingly expensive in compile time.
• The type checking of the interface is a possibly elaborate template program.
Because of their flexibility, variadic templates are widely used in the standard library, and occasionally wildly overused.102 Concepts and Generic Programming Chapter 7
7.4.1 Fold Expressions
To simplify the implementation of simple variadic templates, C++17 offers a limited form of iteration over elements of a parameter pack. For example:
template<Number... T>
int sum(T... v)
{
return (v + ... + 0); // add all elements of v starting with 0
}
Here, sum() can take any number of arguments of any types. Assuming that sum() really adds its
arguments, we get:
int x = sum(1, 2, 3, 4, 5); // x becomes 15
int y = sum('a', 2.4, x); // y becomes 114 (2.4 is truncated and the value of ’a’ is 97)
The body of sum uses a fold expression:
return (v + ... + 0); // add all elements of v to 0
Here, (v+...+0) means add all the elements of v starting with the initial value 0. The first element to
be added is the ‘‘rightmost’’ (the one with the highest index): (v[0]+(v[1]+(v[2]+(v[3]+(v[4]+0))))). That
is, starting from the right where the 0 is. It is called a right fold. Alternatively, we could have used
a left fold:
template<Number... T>
int sum2(T... v)
{
return (0 + ... + v); // add all elements of v to 0
}
Now, the first element to be added is the ‘‘leftmost’’ (the one with the lowest index):
(((((0+v[0])+v[1])+v[2])+v[3])+v[4]). That is, starting from the left where the 0 is.
Fold is a very powerful abstraction, clearly related to the standard-library accumulate(), with a
variety of names in different languages and communities. In C++, the fold expressions are currently restricted to simplify the implementation of variadic templates. A fold does not have to perform numeric computations. Consider a famous example:
template<typename ...T>
void print(T&&... args)
{
(std::cout << ... << args) << '\n'; // pr int all arguments
}
print("Hello!"s,' ',"World ",2017); // (((((std::cout << "Hello!"s) << ’ ’) << "Wor ld ") << 2017) << ’\n’);
Many use cases simply involve a set of values that can be converted to a common type. In such
cases, simply copying the arguments into a vector or the desired type often simplifies further use:Section 7.4.1 Fold Expressions 103
template<typename Res, typename... Ts>
vector<Res> to_vector(Ts&&... ts)
{
vector<Res> res;
(res.push_back(ts) ...); // no initial value needed
return res;
}
We can use to_vector like this:
auto x = to_vector<double>(1,2,4.5,'a');
template<typename ... Ts>
int fct(Ts&&... ts)
{
auto args = to_vector<string>(ts...); // args[i] is the ith argument
// ... use args here ...
}
int y = fct("foo", "bar", s);
7.4.2 Forwarding Arguments
Passing arguments unchanged through an interface is an important use of variadic templates. Consider a notion of a network input channel for which the actual method of moving values is a parameter. Different transport mechanisms have different sets of constructor parameters:
template<typename Transpor t>
requires concepts::InputTranspor t<Transpor t>
class InputChannel {
public:
// ...
InputChannel(Transpor tArgs&&... transportArgs)
: _transpor t(std::forward<Transpor tArgs>(transpor tArgs)...)
{}
// ...
Transpor t _transpor t;
};
The standard-library function forward() (§13.2.2) is used to move the arguments unchanged from
the InputChannel constructor to the Transpor t constructor.
The point here is that the writer of InputChannel can construct an object of type Transpor t without having to know what arguments are required to construct a particular Transpor t. The implementer of InputChannel needs only to know the common user interface for all Transpor t objects.
Forwarding is very common in foundational libraries where generality and low run-time overhead are necessary and very general interfaces are common.104 Concepts and Generic Programming Chapter 7
7.5 Template Compilation Model
Assuming concepts (§7.2), the arguments for a template are checked against its concepts. Errors
found here will be reported and the programmer has to fix the problems. What cannot be checked
at this point, such as arguments for unconstrained template arguments, is postponed until code is
generated for the template and a set of template arguments: ‘‘at template instantiation time.’’ For
pre-concept code, this is where all type checking happens. When using concepts, we get here only
after concept checking succeeded.
An unfortunate side effect of instantiation-time (late) type checking is that a type error can be
found uncomfortably late and can result in spectacularly bad error messages because the compiler
found the problem only after combining information from several places in the program.
The instantiation-time type checking provided for templates checks the use of arguments in the
template definition. This provides a compile-time variant of what is often called duck typing (‘‘If it
walks like a duck and it quacks like a duck, it’s a duck’’). Or – using more technical terminology –
we operate on values, and the presence and meaning of an operation depend solely on its operand
values. This differs from the alternative view that objects have types, which determine the presence
and meaning of operations. Values ‘‘live’’ in objects. This is the way objects (e.g., variables) work
in C++, and only values that meet an object’s requirements can be put into it. What is done at compile time using templates mostly does not involve objects, only values. The exception is local variables in a constexpr function (§1.6) that are used as objects inside the compiler.
To use an unconstrained template, its definition (not just its declaration) must be in scope at its
point of use. For example, the standard header <vector> holds the definition of vector. In practice,
this means that template definitions are typically found in header files, rather than .cpp files. This
changes when we start to use modules (§3.3). Using modules, the source code is organized in the
same way for ordinary functions and template functions. In both cases, definitions will be protected against the problems of textual inclusion.

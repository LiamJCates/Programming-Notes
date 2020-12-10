## Concepts
Concepts constrain template parameters, allowing for parameter checking at the point of instantiation rather than the point of first use.

By catching usage issues at the point of instantiation, the compiler can give you a friendly, informative error code:

“You tried to instantiate this template with a char*, but this template requires a type that supports multiplication.”

Concepts allow you to express requirements on template parameters directly in the language.

Unfortunately, concepts aren’t yet officially part of the C++ standard, although they’ve been voted into C++ 20. At press time, GCC 6.0 and later support the Concepts Technical Specification, and Microsoft is actively working toward implementing concepts in its C++ compiler, MSVC.


Regardless of its unofficial status, concepts are worth exploring for a few reasons:
•	 They’ll fundamentally change the way you achieve compile-time polymorphism. Familiarity with concepts will pay major dividends.

•	 They provide a conceptual framework for understanding some of the makeshift solutions that you can put in place to get better compiler errors when templates are misused.

•	 They provide an excellent conceptual bridge from compile-time templates to interfaces, the primary mechanism for runtime polymorphism.

•	 If you can use GCC 6.0 or later, concepts are available by turning on the
-fconcepts compiler flag.

WARNING
C++ 20’s final concept specification will almost certainly deviate from the Concepts Technical Specification. This section presents concepts as specified in the Concepts Technical Specification so you can follow along






## Constrained Template Arguments (C++20)

Most often, a template will make sense only for template arguments that meet certain criteria.

For example, a class that offers a copy operation must require that its elements be copyable. That is, we must require that the classes template argument is not just a typename but an Element where ‘‘Element’’ specifies the requirements of a type that can be an element:

template<Element T>
class Vector {
private:
  T∗ elem; // elem points to an array of sz elements of type T
  int sz;
  // ...
};

This template<Element T> prefix is C++’s version of mathematic’s ‘‘for all T such that Element(T)’’; that is, Element is a predicate that checks whether T has all the properties that it's template class requires.

Such a predicate is called a concept (§7.2). A template argument for which a concept is specified is called a constrained argument and a template for which an argument is constrained is called a constrained template.

It is a compile-time error to try to instantiate a template with a type that does not meet its requirements.

For example:
Vector<int> v1; // OK: we can copy an int
Vector<thread> v2; // error : we can’t copy a standard thread (§15.2)

Since C++ does not officially support concepts before C++20, older code uses unconstrained template arguments and leaves requirements to documentation.


Consider sum():

template<typename Seq, typename Num>
Num sum(Seq s, Num v)
{
  for (const auto& x : s)
    v+=x;
  return v;
}

It can be invoked for any data structure that supports begin() and end() so that the range-for will work. Such structures include the standard-library vector, list, and map.

Furthermore, the element type of the data structure is limited only by its use: it must be a type that we can add to the Value argument. Examples are ints, doubles, and Matrixes (for any reasonable definition of Matrix).

We could say that the sum() algorithm is generic in two dimensions:
  the type of the data structure used to store elements (‘‘the sequence’’)
  the type of elements.

So, sum() requires that its first template argument is some kind of sequence and its second template argument is some kind of number.

We call such requirements concepts.






## Use of Concepts
Most template arguments must meet specific requirements for the template to compile properly and for the generated code to work properly. That is, most templates must be constrained templates.


The type-name introducer typename is the least constraining, requiring only that the argument be a type.

Consider sum() again:

template<Sequence Seq, Number Num>
Num sum(Seq s, Num v)
{
  for (const auto& x : s)
    v+=x;
  return v;
}

We can define what the concepts Sequence and Number mean.
The compiler can then reject bad calls by looking at sum()’s interface only, rather than looking at its implementation. This improves error reporting.

However, the specification of sum()’s interface is not complete:
  we must be able to add elements of a Sequence to a Number, we define:

template<Sequence Seq, Number Num>
  requires Arithmetic<Value_type<Seq>,Num>
Num sum(Seq s, Num n);

The Value_type of a sequence is the type of the elements in the sequence.

Arithmetic<X,Y> is a concept specifying that we can do arithmetic with numbers of types X and Y.

This saves us from
  trying to calculate the sum() of a vector<string> or a vector<int∗>
  while accepting vector<int> and vector<complex<double>>.

In this example, we needed only +=, but for simplicity and flexibility, we should not constrain our template argument too tightly.

In particular, we might someday want to express sum() in terms of + and = rather than +=, and then we’d be happy that we used a general concept (here, Arithmetic) rather than a narrow requirement to ‘‘have +=.’’

Partial specifications, as in the first sum() using concepts, can be very useful.

Unless the specification is complete, some errors will not be found until instantiation time. However, partial specifications can help a lot, express intent, and are essential for smooth incremental development where we don’t initially recognize all the requirements we need. With mature libraries of concepts, initial specifications will be close to perfect.

Unsurprisingly, requires Arithmetic<Value_type<Seq>,Num> is called a requirements-clause.

The template<Sequence Seq> notation is simply a shorthand for an explicit use of requires Sequence<Seq>.

A verbose equivalent:

template<typename Seq, typename Num>
  requires Sequence<Seq> && Number<Num> && Arithmetic<Value_type<Seq>,Num>
Num sum(Seq s, Num n);


On the other hand, we could also use the equivalence between the two notations:

template<Sequence Seq, Arithmetic<Value_type<Seq>> Num>
Num sum(Seq s, Num n);

Where we cannot yet use concepts, we have to make do with naming conventions and comments, such as:

template<typename Sequence, typename Number>
// requires Arithmetic<Value_type<Sequence>,Number>
Numer sum(Sequence s, Number n);

Whatever notation we chose, it is important to design a template with semantically meaningful constraints on its arguments (§7.2.4).














## Defining a Concept
A concept is a template.

It’s a constant expression involving template arguments, evaluated at compile time.

Think of a concept as one big predicate: a function that evaluates to true or false.

If a set of template parameters meets the criteria for a given concept,
that concept evaluates to true when instantiated with those parameters;
otherwise, it will evaluate to false. When a concept evaluates to false,
template instantiation fails.
You declare concepts using the keyword concept on an otherwise familiar template function definition:

template<typename T1, typename T2, ...>
concept bool ConceptName() {
--snip--
}

Type Traits
Concepts validate type parameters. Within concepts, you manipulate types
to inspect their properties. You can hand roll these manipulations, or you
can use the type support library built into the stdlib. The library contains
utilities for inspecting type properties. These utilities are collectively called
type traits. They’re available in the <type_traits> header and are part of the
std namespace.
Each type trait is a template class that takes a single template parameter,
the type you want to inspect. You extract the results using the template’s static
member value. This member equals true if the type parameter meets the
criteria; otherwise, it’s false.

| Type | trait Checks if template argument is . . . |
|------|--------------------------------------------|
| is_void | void |
| is_null_pointer | nullptr |
| is_integral | bool, a char type, an int type, a short type, a long type, or a long long type |
| is_floating_point | float, double, or long double |
| is_fundamental | Any of is_void, is_null_pointer, is_integral, or is_floating_point |
| is_array | An array; that is, a type containing square brackets [] |
| is_enum | An enumeration type (enum) |
| is_class | A class type (but not a union type) |
| is_function | A function |
| is_pointer | A pointer; function pointers count, but pointers to class members and nullptr do not |
| is_reference | A reference (either lvalue or rvalue) |
| is_arithmetic | is_floating_point or is_integral
| is_pod | A plain-old-data type; that is, a type that can be represented as a data type in plain C |
| is_default_constructible | Default constructible; that is, it can be constructed without arguments or initialization values |
| is_constructible | Constructible with the given template parameters: this type trait allows the user to provide additional template parameters beyond the type under consideration |
| is_copy_constructible | Copy constructible |
| is_move_constructible | Move constructible |
| is_destructible | Destructible |
| is_same | The same type as the additional template parameter type (including const and volatile modifiers) |
| is_invocable | Invocable with the given template parameters: this type trait allows the user to provide additional template parameters beyond the type under consideration |

Type traits are often the building blocks for a concept, but sometimes
you need more flexibility. Type traits tell you what types are, but sometimes you must also specify how the template will use them. For this, you
use requirements.







## Requirements

Requirements are ad hoc constraints on template parameters.
Each concept can specify any number of requirements on its template parameters.
Requirements are encoded into requires expressions denoted by the requires
keyword followed by function arguments and a body.
A sequence of syntactic requirements comprises the requirements
expression’s body. Each syntactic requirement puts a constraint on the template parameters. Together, requires expressions have the following form:
requires (arg-1, arg-2, ..) {
{ expression1 } -> return-type1;
{ expression2 } -> return-type2;
--snip--
}
Requires expressions take arguments that you place after the requires
keyword . These arguments have types derived from template parameters.
The syntactic requirements follow, each denoted with { } ->. You put an
arbitrary expression within each of the braces. This expression can
involve any number of the arguments to the argument expression.
If an instantiation causes a syntactic expression not to compile, that
syntactic requirement fails. Supposing the expression evaluates without
error, the next check is whether the return type of that expression matches
the type given after the arrow ->. If the expression result’s evaluated type
can’t implicitly convert to the return type, the syntactic requirement fails.
If any of the syntactic requirements fail, the requires expression evaluates to false. If all of the syntactic requirements pass, the requires expression evaluates to true.

Example:
Suppose you have two types, T and U, and you want to know whether
you can compare objects of these types using the equality == and inequality
!= operators. One way to encode this requirement is to use the following
expression:

// T, U are types
requires (T t, U u) {
{ t == u } -> bool; // syntactic requirement 1
{ u == t } -> bool; // syntactic requirement 2
{ t != u } -> bool; // syntactic requirement 3
{ u != t } -> bool; // syntactic requirement 4
}

The requires expression takes two arguments, one each of types T and U.
Each of the syntactic requirements contained in the requires expression is an
expression using t and u with either == or !=. All four syntactic requirements
enforce a bool result. Any two types that satisfy this requires expression are
guaranteed to support comparison with == and !=.






## Building Concepts from Requires Expressions
Because requires expressions are evaluated at compile time, concepts can
contain any number of them. Try to construct a concept that guards against
the misuse of mean.

template<typename T>
T mean(T* values, size_t length) {
  T result{};
  for(size_t i{}; i<length; i++)
  {
    result v+= values[i];
  }
  return result / length;
}

You can see three requirements implied by this code:
•	 T must be default constructible.
•	 T supports operator+=.
•	 Dividing a T by a size_t yields a T.

From these requirements, you could create a concept called Averageable
template<typename T>
concept bool Averageable() {
return std::is_default_constructible<T>::value
  && requires (T a, T b)
  {
    { a += b } -> T;
    { a / size_t{ 1 } } -> T;
  };
}

You use the type trait is_default_constructible to ensure that T is default
constructible, that you can add two T types, and that you can divide a
T by a size_t and get a result of type T.
Recall that concepts are just predicates; you’re building a Boolean
expression that evaluates to true when the template parameters are supported and false when they’re not. The concept is composed of three
Boolean expressions AND-ed (&&) together: two type traits and a
requires expression. If any of the three returns false, the concept’s constraints are not met









## Using Concepts
Declaring concepts is a lot more work than using them. To use a concept,
just use the concept’s name in place of the typename keyword.

#include <cstddef>
#include <type_traits>
template<typename T>
concept bool Averageable()
{
--snip--
}

template<Averageable T>
T mean(const T* values, size_t length)
{
--snip--
}

int main()
{
  const double nums_d[] { 1.0f, 2.0f, 3.0f, 4.0f };
  const auto result1 = mean(nums_d, 4);
  printf("double: %f\n", result1);
  const float nums_f[] { 1.0, 2.0, 3.0, 4.0 };
  const auto result2 = mean(nums_f, 4);
  printf("float: %f\n", result2);
  const size_t nums_c[] { 1, 2, 3, 4 };
  const auto result3 = mean(nums_c, 4);
  printf("size_t: %d\n", result3);
}

After defining Averageable, you just use it in place of typename.

The payoff is when you get to try to use mean with a type that is not
Averageable: you get a compiler error at the point of instantiation. This produces much better compiler error messages than you would obtain from a
raw template.

When concepts incorporate into the C++ standard, it’s likely that the
stdlib will include many concepts. The design goal of concepts is that a programmer shouldn’t have to define very many concepts on their own; rather,
they should be able to combine concepts and ad hoc requirements within
a template prefix.

| Concept | A type that . . . |
|---------|-------------------|
| Conditional | Can be explicitly converted to bool |
| Boolean | Is Conditional and supports !, &&, and || Boolean operations |
| Equality_comparable | Supports == and != operations returning a Boolean |
| Destructible | Can be destroyed (compare is_destructible) |
| Default_constructible | Is default constructible (compare is_default_constructible) |
| Movable | Supports move semantics: it must be move assignable and move constructible (compare is_move_assignable, is_move_constructible) |
| Copyable | Supports copy semantics: it must be copy assignable and copy constructible (compare is_copy_assignable, is_copy_constructible) |
| Regular | Is default constructible, copyable, and Equality_comparable |
| Ordered | Is Regular and is totally ordered (essentially, it can be sorted) |
| Number | Is Ordered and supports math operations like +, -, /, and * |
| Function | Supports invocation; that is, you can call it (compare is_invocable) |
| Predicate | Is a Function and returns bool |
| Range | Can be iterated over in a range-based for loop |


There are several ways to build constraints into a template prefix. If a template parameter is only used to declare the type of a function parameter, you can omit the template prefix entirely:

return-type function-name(Concept1 arg-1, ...) {
--snip--
}

Because you use a concept rather than a typename to define an argument’s type, the compiler knows that the associated function is a template. You are even free to mix concepts and concrete types in the argument list. In other words, whenever you use a concept as part of a function definition, that function becomes a template.

This template function takes an array of Ordered elements and finds the minimum:

#include <origin/core/concepts.hpp>
size_t index_of_minimum(Ordered* x, size_t length) {
size_t min_index{};
for(size_t i{ 1 }; i<length; i++) {
if(x[i] < x[min_index]) min_index = i;
}
return min_index;
}

Even though there’s no template prefix, index_of_minimum is a template
because Ordered is a concept.


Ad Hoc Requires Expressions
Concepts are fairly heavyweight mechanisms for enforcing type safety.
Sometimes, you just want to enforce some requirement directly in the template prefix. You can embed requires expressions directly into the template
definition to accomplish this. Consider the get_copy function in Listing 6-27
that takes a pointer and safely returns a copy of the pointed-to object.
#include <stdexcept>
template<typename T>
requires is_copy_constructible<T>::value
T get_copy(T* pointer) {
  if (!pointer) throw std::runtime_error{ "Null-pointer dereference" };
  return *pointer;
}

A template function with an ad hoc requires expression
The template prefix contains the requires keyword, which begins the
requires expression. In this case, the type trait is_copy_constructible ensures
that T is copyable. This way, if a user accidentally tries to get_copy with a
pointer that points to an uncopyable object, they’ll be presented with a clear
explanation of why template instantiation failed.



static_assert: The Preconcepts Stopgap
As of C++17, concepts aren’t part of the standard, so they’re not guaranteed
to be available across compilers. There is a stopgap you can apply in the
interim: the static_assert expression. These assertions evaluate at compile
time. If an assertion fails, the compiler will issue an error and optionally
provide a diagnostic message. A static_assert has the following form:
static_assert(boolean-expression, optional-message);
In the absence of concepts, you can include one or more static_assert
expressions in the bodies of templates to assist users in diagnosing usage
errors.


Suppose you want to improve the error messages of mean without leaning on concepts. You can use type traits in combination with static_assert
to achieve a similar result, as demonstrated in Listing 6-29.
#include <type_traits>
template <typename T>
T mean(T* values, size_t length) {
static_assert(std::is_default_constructible<T>(),
"Type must be default constructible.");
static_assert(std::is_copy_constructible<T>(),
"Type must be copy constructible.");
static_assert(std::is_arithmetic<T>(),
"Type must support addition and division.");
static_assert(std::is_constructible<T, size_t>(),
"Type must be constructible from size_t.");
--snip--
}

You see the familiar type traits for checking that T is default and copy
constructible, and you provide error methods to help users diagnose issues
with template instantiation. You use is_arithmetic, which evaluates to true
if the type parameter supports arithmetic operations (+, -, /, and *), and
is_constructible, which determines whether you can construct a T from a
size_t.
Using static_assert as a proxy for concepts is a hack, but it’s widely
used. Using type traits, you can limp along until concepts are included in
the standard. You’ll often see static_assert if you use modern third-party
libraries; if you’re writing code for others (including future you), consider
using static_assert and type traits.
Compilers, and often programmers, don’t read documentation. By
baking requirements directly into the code, you can avoid stale documentation. In the absence of concepts, static_assert is a fine stopgap





















Concept-based Overloading

## Templates

C++ achieves compile-time polymorphism through templates.


### Idea
A template is a class or function with template parameters.
These parameters can stand in for any type, including fundamental and user-defined types. When the compiler sees a template used with a type, it stamps out a bespoke template instantiation.

Template instantiation is the process of creating a class or a function from a template. Somewhat confusingly, you can also refer to “a template instantiation” as the result of the template instantiation process. Template instantiations are sometimes called concrete classes and concrete types.

The big idea is that, rather than copying and pasting common code all over the place, you write a single template; the compiler generates new template instances when it encounters a new combination of types in the template parameters.

The template feature allows us to write a single code segment for:
a set of related functions, called a function template
a set of related classes, called a class template.



### Use of Templates
Templates are the C++ foundation of generic programming, which involves writing code in a way that is independent of any particular type. Thus, a template can be thought of as blueprint or formula for creating a generic class or a function.

The library containers like iterators and algorithms are examples of generic programming and have been developed using template concept.

There is a single definition of each container, such as vector, but we can define many different kinds of vectors for example, vector <int> or vector <string>.











## Declaring Templates
In C++, template is a reserved word.

You declare templates with a template prefix, which consists of the keyword
template followed by angle brackets < >.
Within the angle brackets is one or more template parameter declarations.

template parameters are declared using either the typename or class keywords followed by an identifier.

Similar to variables being parameters to functions, types (that is, data types) are parameters to templates. The type identifier is referred to as a formal parameter to the template.

Syntax:
template <class T>
//declaration
template <typename T>
//declaration

This template takes a template parameter T to be used in the declaration:
  T is the name of a data type, built-in or user-defined
  declaration is either a function declaration or a class declaration.

NOTE
The coexistence of the typename and class keywords is unfortunate and confusing. They mean the same thing. (They’re both supported for historical reasons.)







### Template Function Definitions
template <class T>
ret-type func-name(parameter list) {
   //function body
}

Here, T is a placeholder name for a data type used by the function. This name can be used within the function definition to specify the type of parameters to the function and the return type of the function and to declare variables within the function.

You can define more than one generic data type by using a comma-separated list.

Example:

template<typename X, typename Y, typename Z>
X my_template_function(Y& arg1, const Z* arg2) {
  --snip--
}

Within the body of my_template_function, you can use arg1 and arg2 however you’d like, as long as you return an object of type X.







### Template Class Definitions
Class templates are used to write a single code segment for a set of related classes. Using class templates, we create a generic class, and the compiler can generate the appropriate source code for a specific implementation.

Syntax:
template <class T>
class ClassName{
  //class body
}

Class templates are called parameterized types because, based on the parameter
T, a specific class is generated. Here, T is the placeholder type name, which will be specified when a class is instantiated.

You can define more than one generic data type by using a comma-separated list.

Example:
Consider MyTemplateClass which takes three template parameters: X, Y, and Z.

template<typename X, typename Y, typename Z>
struct MyTemplateClass
{
  X foo(Y&);
  private:
  Z* member;
};

The template keyword begins the template prefix, which contains the template parameters.

This template preamble leads to something special about the remaining declaration of MyTemplateClass. Within MyTemplateClass, you use X, Y, and Z as if they were any fully specified type, like an int or a user-defined class.

The foo method takes a Y reference and returns an X. You can declare
members with types that include template parameters, like a pointer to Z.







### Template Type Deduction

Generally, you don’t have to provide template function parameters when
invoking a template function. The process that the compiler uses to determine the correct template parameters is called template type deduction.

Template type deduction mostly works the way you might expect, but there is some
nuance you’ll want to become familiar with if you’re writing a lot of generic code. For
more information, see the ISO standard [temp]. Also, refer to Item 1 of Effective
Modern C++ by Scott Meyers and Section 23.5.1 of The C++ Programming
Language, 4th Edition, by Bjarne Stroustrup.
Sometimes, template arguments cannot be deduced. For example, if
a template function’s return type is a template argument, you must specify
template arguments explicitly.





### Type Checking in Templates
Templates are type safe. During template instantiation, the compiler pastes
in the template parameters. If the resulting code is incorrect, the compiler
will not generate the instantiation.

Consider this template function which squares an element and returns the result.
template<typename T>
T square(T value)
{
  return value * value;
}

The T has a silent requirement: it must support multiplication.
If you try to use square with, say, a char*, the compilation will fail:

template<typename T>
T square(T value)
{
  return value * value;
}
int main()
{
  char my_char{ 'Q' };
  auto result = square(&my_char); //Bang!
}
Pointers don’t support multiplication, so template initialization fails

Error messages emitted by template initialization failures are notoriously cryptic.

Although template instantiation ensures type safety, the checking happens very late in the compilation process. When the compiler instantiates a template, it pastes the template parameter types into the template. After type insertion, the compiler attempts to compile the result. If instantiation fails, the compiler emits the dying words inside the template instantiation.

C++ template programming shares similarities with duck-typed languages.

Duck-typed languages (like Python) defer type checking until runtime.

The underlying philosophy is that if an object looks like a duck and quacks like a duck, then it must be type duck. Unfortunately, this means you can’t generally know whether an object supports a particular operation until you execute the program.

With templates, you cannot know whether an instantiation will succeed until you try to compile it. Although duck-typed languages might blow up at runtime, templates might blow up at compile time.

This situation is widely regarded as unacceptable by right-thinking people
in the C++ community, so there is a splendid solution called concepts.


Concepts

Concepts constrain template parameters, allowing for parameter checking at the point of instantiation rather than the point of first use. By catching usage issues at the point of instantiation, the compiler can give you a friendly, informative error code—for example, “You tried to instantiate this template with a char*, but this template requires a type that supports multiplication.” Concepts allow you to express requirements on template parameters directly in the language.
Unfortunately, concepts aren’t yet officially part of the C++ standard,
although they’ve been voted into C++ 20. At press time, GCC 6.0 and later
support the Concepts Technical Specification, and Microsoft is actively working toward implementing concepts in its C++ compiler, MSVC.
Regardless of its unofficial status, it’s worth exploring concepts in some detail for a few reasons:

•	 They’ll fundamentally change the way you achieve compile-time polymorphism. Familiarity with concepts will pay major dividends.

•	 They provide a conceptual framework for understanding some of the
makeshift solutions that you can put in place to get better compiler
errors when templates are misused.

•	 They provide an excellent conceptual bridge from compile-time templates to interfaces, the primary mechanism for runtime polymorphism.

•	 If you can use GCC 6.0 or later, concepts are available by turning on the
-fconcepts compiler flag.

WARNING
C++ 20’s final concept specification will almost certainly deviate from the Concepts Technical Specification. This section presents concepts as specified in the Concepts Technical Specification so you can follow along


Defining a Concept
A concept is a template. It’s a constant expression involving template arguments, evaluated at compile time. Think of a concept as one big predicate: a
function that evaluates to true or false.
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

Requirements

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

Building Concepts from Requires Expressions
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


Using Concepts
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


Non-Type Template Parameters
A template parameter declared with the typename (or class) keyword is called
a type template parameter, which is a stand-in for some yet-to-be-specified type.
Alternatively, you can use non-type template parameters, which are stand-ins for
some yet-to-be-specified value. Non-type template parameters can be any of
the following:
•	 An integral type
•	 An lvalue reference type
•	 A pointer (or pointer-to-member) type
•	 A std::nullptr_t (the type of nullptr)
•	 An enum class

Using a non-type template parameter allows you to inject a value
into the generic code at compile time. For example, you can construct a
template function called get that checks for out-of-bounds array access at
compile time by taking the index you want to access as a non-type template
parameter.
Recall from Chapter 3 that if you pass an array to a function, it decays
into a pointer. You can instead pass an array reference with a particularly
off-putting syntax:
element-type(param-name&)[array-length]
For example, Listing 6-30 contains a get function that makes a first
attempt at performing bounds-checked array access.
#include <stdexcept>
int& get(int (&arr)[10], size_t indexv) {
if (index >= 10) throw std::out_of_range{ "Out of bounds" };
return arr[index];
}

The get function accepts a reference to an int array of length 10 and an
index to extract. If index is out of bounds, it throws an out_of_bounds exception; otherwise, it returns a reference to the corresponding element.
You can improve Listing 6-30 in three ways, which are all enabled by
non-type template parameters genericizing the values out of get.
First, you can relax the requirement that arr refer to an int array by
making get a template function, as in Listing 6-31.
#include <stdexcept>
template <typename T>
T& get(T (&arr)[10], size_t index) {
if (index >= 10) throw std::out_of_range{ "Out of bounds" };
return arr[index];
}

genericize the function by replacing a concrete type (here, int) with a template parameter.



Second, you can relax the requirement that arr refer to an array of
length 10 by introducing a non-type template parameter Length. Listing 6-32
shows how: simply declare a size_t Length template parameter and use it in
place of 10.

#include <stdexcept>
template <typename T, size_t Length>
T& get (T(&arr)[Length], size_t index) {
  if (index >= Length) throw std::out_of_range{ "Out of bounds" };
  return arr[index];
}

The idea is the same: rather than replacing a specific type (int), you’ve
replaced a specific integral value (10). Now you can use the function
with arrays of any size.

Third, you can perform compile time bounds checking by taking size_t
index as another non-type template parameter. This allows you to replace
the std::out_of_range with a static_assert, as in Listing 6-33.

#include <cstdio>
template <size_t Index, typename T, size_t Length>
T& get(T (&arr)[Length]) {
static_assert(Index < Length, "Out-of-bounds access");
return arr[Index];
}
int main() {
  int fib[]{ 1, 1, 2, 0 };
  printf("%d %d %d ", get<0>(fib), get<1>(fib), get<2>(fib));
  get<3>(fib) = get<1>(fib) + get<2>(fib);
  printf("%d", get<3>(fib));
  //printf("%d", get<4>(fib));
}


You’ve moved the size_t index parameter into a non-type template parameter and updated the array access with the correct name Index.

Because Index is now a compile time constant, you also replace the logic
_error with a static_assert, which prints the friendly message Out-of-bounds
access whenever you accidentally try to access an out-of-bounds element.
Listing 6-33 also contains example usage of get in main. You’ve first
declared an int array fib of length 4. You then print the first three elements of the array using get, set the fourth element, and print it. If
you uncomment the out-of-bounds access, the compiler will generate an
error thanks to the static_assert.


Variadic Templates
Sometimes, templates must take in an unknown number of arguments. The
compiler knows these arguments at template instantiation, but you want to
avoid having to write many different templates each for different numbers
of arguments. This is the raison d’être of variadic templates. Variadic templates take a variable number of arguments.
You denote variadic templates using a final template parameter that
has a special syntax, namely typename... arguments. The ellipsis indicates
that arguments is a parameter pack type, meaning you can declare parameter
packs within your template. A parameter pack is a template argument that
accepts zero or more function arguments. These definitions can seem a
bit abstruse, so consider the following sample variadic template that builds
upon SimpleUniquePointer.

template <typename T, typename... Arguments>
SimpleUniquePointer<T> make_simple_unique(Arguments... arguments) {
  return SimpleUniquePointer<T>{ new T{ arguments... } };
}

You define the parameter pack type Arguments, which declares make_simple_unique as a variadic template. This function passes arguments to
the constructor of template parameter T.

The upshot is you can now create SimpleUniquePointers very easily, even
when the pointed-to object has a non-default constructor.

NOTE
There is a slightly more efficient implementation of Listing 6-34. If arguments is an rvalue, you can move it directly into the constructor of T. The stdlib contains a function called std::forward in the <utility> header that will detect whether arguments is an lvalue or rvalue and perform a copy or move, respectively. See Item 23 in Effective Modern C++ by Scott Meyers.

Advanced Template Topics

For everyday polymorphic programming, templates are your go-to tool. It
turns out that templates are also used in a wide range of advanced settings,
especially in implementing libraries, high-performance programs, and
embedded system firmware. This section outlines some of the major terrain
features of this vast space.

Template Specialization
To understand advanced template usage, you must first understand template specialization. Templates can actually take more than just concept
and typename parameters (type parameters). They can also accept fundamental types, like char (value parameters), as well as other templates. Given
the tremendous flexibility of template parameters, you can make a lot of
compile-time decisions about their features. You could have different versions of templates depending on the characteristics of these parameters.
For example, if a type parameter is Ordered instead of Regular, you might be
able to make a generic program more efficient. Programming this way is
called template specialization. Refer to the ISO standard [temp.spec] for more
information about template specialization.

Name Binding
Another critical component of how templates get instantiated is name
binding. Name binding helps determine the rules for when the compiler
matches a named element within a template to a concrete implementation.
The named element could, for example, be part of the template definition, a local name, a global name, or from some named namespace. If you
want to write heavily templated code, you need to understand how this
binding occurs. If you’re in such a situation, refer to Chapter 9, “Names
in Templates,” in C++ Templates: The Complete Guide by David Vandevoorde
et al. and to [temp.res].

Type Function
A type function takes types as arguments and returns a type. The type traits
with which you build up concepts are closely related to type functions.
You can combine type functions with compile time control structures to
do general computation, such as programming control flow, at compile
time. Generally, programming using these techniques is called template
metaprogramming.

Template Metaprogramming
Template metaprogramming has a deserved reputation for resulting in
code that is exceedingly clever and absolutely inscrutable to all but the
mightiest of wizards. Fortunately, once concepts are part of the C++ standard, template metaprogramming should become more approachable to
us mere mortals. Until then, tread carefully. For those interested in further detail on this topic, refer to Modern C++ Design: Generic Programming
and Design Patterns Applied by Andrei Alexandrescu and C++ Templates: The
Complete Guide by David Vandevoorde et al.


Template Source Code Organization
Each time a template is instantiated, the compiler must be able to generate all the code necessary to use the template. This means all the information about how to instantiate a custom class or function must be available
within the same translation unit as the template instantiation. By far, the
most popular way to achieve this is to implement templates entirely within
header files.
There are some modest inconveniences associated with this approach.
Compile times can increase, because templates with the same parameters
might get instantiated multiple times. It also decreases your ability to hide
implementation details. Fortunately, the benefits of generic programming
far outweigh these inconveniences. (Major compilers will probably minimize the problems of compile times and code duplication anyway.)
There are even a few advantages to having header-only templates:
•	 It’s very easy for others to use your code: it’s a matter of applying
 #include to some headers (rather than compiling the library, ensuring the resulting object files are visible to the linker, and so on).
•	 It’s trivially easy for compilers to inline header-only templates, which
can lead to faster code at runtime.
•	 Compilers can generally do a better job of optimizing code when all of
the source is available.


Polymorphism at Runtime vs. Compile Time
When you want polymorphism, you should use templates. But sometimes
you can’t use templates because you won’t know the types used with your
code until runtime. Remember that template instantiation only occurs
when you pair a template’s parameters with types. At this point, the compiler can instantiate a custom class for you. In some situations, you might
not be able to perform such pairings until your program is executing (or,
at least, performing such pairing at compile time would be tedious).
In such cases, you can use runtime polymorphism. Whereas the template
is the mechanism for achieving compile-time polymorphism, the runtime
mechanism is the interface.

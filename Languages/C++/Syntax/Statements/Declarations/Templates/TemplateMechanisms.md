Template Mechanisms

To define good templates, we need some supporting language facilities:
• Values dependent on a type: variable templates (§6.4.1).
• Aliases for types and templates: alias templates (§6.4.2).
• A compile-time selection mechanism: if constexpr (§6.4.3).
• A compile-time mechanism to inquire about properties of types and expressions: requiresexpressions (§7.2.3).

In addition, constexpr functions (§1.6) and static_asser ts (§3.5.5) often take part in template design and use.

These basic mechanisms are primarily tools for building general, foundational abstractions.

### Variable Templates
When we use a type, we often want constants and values of that type. This is of course also the case when we use a class template: when we define a C<T>, we often want constants and variables of type T and other types depending on T.

Here is an example from a fluid dynamic simulation
[Garcia,2015]:
template <class T>
  constexpr T viscosity = 0.4;

template <class T>
  constexpr space_vector<T> external_acceleration = { T{}, T{−9.8}, T{} };

auto vis2 = 2∗viscosity<double>;
auto acc = external_acceleration<float>;

Here, space_vector is a three-dimensional vector.

Naturally, we can use arbitrary expressions of suitable type as initializers:

// is_assignable is a type trait (§13.9.1)
template<typename T, typename T2>
  constexpr bool Assignable = is_assignable<T&,T2>::value;



template<typename T>
void testing()
{
  static_assert(Assignable<T&,double>, "can't assign a double");
  static_assert(Assignable<T&,string>, "can't assign a string");
}

After some significant mutations, this idea becomes the heart of concept definitions (§7.2).



### Aliases
Surprisingly often, it is useful to introduce a synonym for a type or a template. For example, the standard header <cstddef> contains a definition of the alias size_t:
using size_t = unsigned int;

The actual type named size_t is implementation-dependent, so in another implementation size_t may be an unsigned long. Having the alias size_t allows the programmer to write portable code.

It is very common for a parameterized type to provide an alias for types related to their template arguments. For example:

template<typename T>
class Vector {
public:
  using value_type = T;
  // ...
};

In fact, every standard-library container provides value_type as the name of its value type (Chapter 11). This allows us to write code that will work for every container that follows this convention:

template<typename C>
using Value_type = typename C::value_type; // the type of C’s elements

template<typename Container>
void algo(Container& c)
{
  Vector<Value_type<Container>> vec; // keep results here
  // ...
}

The aliasing mechanism can be used to define a new template by binding some or all template arguments:

template<typename Key, typename Value>
class Map {
  // ...
};

template<typename Value>
using String_map = Map<string,Value>;

String_map<int> m; // m is a Map<str ing,int>



Compile-Time if
Consider writing an operation that can use one of two operations slow_and_safe(T) or simple_and_fast(T).

Such problems abound in foundational code where generality and optimal performance are essential. The traditional solution is to write a pair of overloaded functions and select the most appropriate based on a trait, such as the standard-library is_pod. If a class hierarchy is involved, a base class can provide the slow_and_safe general operation and a derived class can override with a simple_and_fast implementation.

In C++17, we can use a compile-time if:

template<typename T>
void update(T& target)
{
  // ...
  if constexpr(is_pod<T>::value)
    simple_and_fast(target); // for "plain old data"
  else
    slow_and_safe(target);
  // ...
}

The is_pod<T> is a type trait (§13.9.1) that tells us whether a type can be trivially copied.

Only the selected branch of an if constexpr is instantiated. This solution offers optimal performance and locality of the optimization.

Importantly, an if constexpr is not a text-manipulation mechanism and cannot be used to break the usual rules of grammar, type, and scope. For example:

template<typename T>
void bad(T arg)
{
  if constexpr(Something<T>::value)
    try { // syntax error
    g(arg);
    if constexpr(Something<T>::value)
    }
    catch(...) { /* ... */ } // syntax error
}

Allowing such text manipulation could seriously compromise readability of code and create problems for tools relying on modern program representation techniques (such as ‘‘abstract syntax trees’’)

## Template Type Deduction

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






## Example

Consider using the standard-library template pair:
pair<int,double> p = {1,5.2};

Many have found the need to specify the template argument types tedious, so the standard library offers a function, make_pair(), that deduces the template arguments of the pair it returns from its function arguments:

auto p = make_pair(1,5.2); // p is a pair<int,double>

This leads to the obvious question ‘‘Why can’t we just deduce template parameters from constructor arguments?’’ So, in C++17, we can:

pair p = {1,5.2}; // p is a pair<int,double>

This is not just a problem with pair; make_ functions are very common:

template<typename T>
class Vector {
public:
Vector(int);
Vector(initializer_list<T>); // initializer-list constructor
// ...
};

Vector v1 {1,2,3}; // deduce v1’s element type from the initializer element type
Vector v2 = v1; // deduce v2’s element type from v1’s element type
auto p = new Vector{1,2,3}; // p points to a Vector<int>
Vector<int> v3(1); // here we need to be explicit about the element type (no element type is mentioned)

Clearly, this simplifies notation and can eliminate annoyances caused by mistyping redundant template argument types. However, it is not a panacea. Deduction can cause surprises (both for make_functions and constructors).

Consider:
Vector<string> vs1 {"Hello", "World"}; // Vector<string>
Vector vs {"Hello", "World"}; // deduces to Vector<const char*> (Surprise?)
Vector vs2 {"Hello"s, "World"s}; // deduces to Vector<string>
Vector vs3 {"Hello"s, "World"}; // error : the initializer list is not homogenous

The type of a C-style string literal is const char∗ (§1.7.1). If that was not what was intended, use the s suffix to make it a proper string.

If elements of an initializer list have differing types, we cannot deduce a unique element type, so we get an error.

When a template argument cannot be deduced from the constructor arguments, we can help by providing a deduction guide:

template<typename T>
class Vector2 {
public:
  using value_type = T;
  // ...
  Vector2(initializ er_list<T>); // initializer-list constructor
  template<typename Iter>
  Vector2(Iter b, Iter e); // [b:e) range constructor
  // ...
};

Vector2 v1 {1,2,3,4,5}; // element type is int
Vector2 v2(v1.begin(),v1.begin()+2);

Obviously, v2 should be a Vector2<int>, but without help, the compiler cannot deduce that. The code only states that there is a constructor from a pair of values of the same type. Without language support for concepts (§7.2), the compiler cannot assume anything about that type. To allow deduction, we can add a deduction guide after the declaration of Vector2:

template<typename Iter>
Vector2(Iter,Iter) −> Vector2<typename Iter::value_type>;

That is, if we see a Vector2 initialized by a pair of iterators, we should deduce Vector2::value_type to be the iterator’s value type.

The effects of deduction guides are often subtle, so it is best to design class templates so that
deduction guides are not needed. However, the standard library is full of classes that don’t (yet) use
concepts (§7.2) and have such ambiguities, so it uses quite a few deduction guides.

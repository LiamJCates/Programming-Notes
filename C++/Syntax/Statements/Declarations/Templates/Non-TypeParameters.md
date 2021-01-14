## Non-Type Template Parameters
A template parameter declared with the typename (or class) keyword is called
a type template parameter, which is a stand-in for some yet-to-be-specified type.

Alternatively, you can use non-type template parameters, which are stand-ins for
some yet-to-be-specified value. A template non-type parameter is a special type of parameter that does not substitute for a type, but is instead replaced by a value.

Non-type template parameters can be any of the following:
  An integral type
  An lvalue reference type
    A pointer or reference to a class object
    A pointer or reference to a function
    A pointer or reference to a class member function
  A pointer (or pointer-to-member) type
  A std::nullptr_t (the type of nullptr)
  An enum class


Using a non-type template parameter, also called value arguments, allows you to inject a value into the generic code at compile time. For example, you can construct a template function called get that checks for out-of-bounds array access at compile time by taking the index you want to access as a non-type template parameter.









Value Template Arguments

In addition to type arguments, a template can take value arguments:

template<typename T, int N>
struct Buffer {
  using value_type = T;
  constexpr int size() { return N; }
  T[N];
  // ...
};

The alias (value_type) and the constexpr function are provided to allow users (read-only) access to the template arguments.

Value arguments are useful in many contexts. For example, Buffer allows us to create arbitrarily sized buffers with no use of the free store (dynamic memory):

Buffer<char,1024> glob; // global buffer of characters (statically allocated)
void fct()
{
  Buffer<int,10> buf; // local buffer of integers (on the stack)
  // ...
}

A template value argument must be a constant expression.












Recall that if you pass an array to a function, it decays into a pointer. You can instead pass an array reference with a particularly off-putting syntax:

element-type(param-name&)[array-length]

For example, a get function that makes a first attempt at performing bounds-checked array access.

#include <stdexcept>
int& get(int (&arr)[10], size_t indexv) {
  if (index >= 10) throw std::out_of_range{ "Out of bounds" };
  return arr[index];
}

The get function accepts a reference to an int array of length 10 and an index to extract. If index is out of bounds, it throws an out_of_bounds exception; otherwise, it returns a reference to the corresponding element.

You can improve this in three ways, which are all enabled by non-type template parameters genericizing the values out of get.

First, you can relax the requirement that arr refer to an int array by
making get a template function:

#include <stdexcept>
template <typename T>
T& get(T (&arr)[10], size_t index) {
  if (index >= 10) throw std::out_of_range{ "Out of bounds" };
  return arr[index];
}

genericize the function by replacing a concrete type (here, int) with a template parameter.



Second, you can relax the requirement that arr refer to an array of
length 10 by introducing a non-type template parameter Length.

Simply declare a size_t Length template parameter and use it in place of 10.

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

Because Index is now a compile time constant, you also replace the logic_error with a static_assert, which prints the friendly message Out-of-bounds access whenever you accidentally try to access an out-of-bounds element.

Listing 6-33 also contains example usage of get in main. You’ve first declared an int array fib of length 4. You then print the first three elements of the array using get, set the fourth element, and print it. If you uncomment the out-of-bounds access, the compiler will generate an error thanks to the static_assert.

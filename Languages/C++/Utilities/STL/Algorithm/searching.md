The standard algorithms include many flavors of searching, divided into two broad categories: linear
and binary. The linear searches examine every element in a range, starting from the first and proceeding
to subsequent elements until reaching the end (or the search ends because it is successful). The binary
searches require the elements be sorted in ascending order, using the < operator, or according to a custom
predicate, that is, a function, functor, or lambda that returns a Boolean result.

Every search algorithm comes in two forms. The first compares items using an operator (== for linear
searches and < for binary searches). The second form uses a caller-supplied functor instead of the operator.
For most algorithms, the functor is an additional argument to the algorithm, so the compiler can distinguish
the two forms. In a few cases, both forms take the same number of arguments, and the library uses distinct
names, because the compiler could not otherwise distinguish between the two forms. In these cases, the
functor form has _if added to the name, such as find and find_if.


### Linear Search Algorithms

The most basic linear search is the find function. It searches a range of read iterators for a value. It returns
an iterator that refers to the first matching element in the range. If find cannot find a match, it returns a
copy of the end iterator.
```cpp
#include <algorithm>
#include <iostream>

#include <iterator>
#include <vector>

using intvector = std::vector<int>;

void read_data(intvector& data)
{
  data.clear();
  data.insert(data.begin(), std::istream_iterator<int>(std::cin),
                            std::istream_iterator<int>());
}

void write_data(intvector const& data)
{
  std::cout << "{ ";
  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "}\n";
}

int main()
{
  intvector data{};
  read_data(data);
  write_data(data);
  if(auto iter{std::ranges::find(data, 42)}; iter == data.end())
    std::cout << "Value 42 not found\n";
  else
  {
    *iter = 0;
    std::cout << "Value 42 changed to 0:\n";
    write_data(data);
  }
}
```

The program reads integers into a vector, searches for the value 42, and if found, changes that element to 0.


### std::find

std::find searches for the first occurrence of a value in a container. std::find takes 3 parameters:
an iterator to the starting element in the sequence,
an iterator to the ending element in the sequence,
a value to search for.

It returns an iterator pointing to the element (if it is found) or the end of the container (if the element is not found).

For example:

```cpp
#include <algorithm>
#include <array>
#include <iostream>

int main()
{
  std::array arr{ 13, 90, 99, 5, 40, 80 };

  std::cout << "Enter a value to search for and replace with: ";  
  int search{};
  int replace{};
  std::cin >> search >> replace;

  // Input validation omitted

  // std::find returns an iterator pointing to the found element (or the end of the container)
  // we'll store it in a variable, using type inference to deduce the type of
  // the iterator (since we don't care)
  auto found{ std::find(arr.begin(), arr.end(), search) };

  // Algorithms that don't find what they were looking for return the end iterator.
  // We can access it by using the end() member function.
  if (found == arr.end())
  {
    std::cout << "Could not find " << search << '\n';
  }
  else
  {
    // Override the found element.
    *found = replace;
  }

  for (int i : arr)
  {
    std::cout << i << ' ';
  }

  std::cout << '\n';

  return 0;
}
```
Sample run when the element is found
```
Enter a value to search for and replace with: 5 234
13 90 99 234 40 80
```
Sample run when the element isn’t found
```
Enter a value to search for and replace with: 0 234
Could not find 0
13 90 99 5 40 80
```


### std::find_if

Sometimes we want to see if there is a value in a container that matches some condition (e.g. a string that contains a specific substring) rather than an exact value. In such cases, std::find_if is perfect. The std::find_if function works similarly to std::find, but instead of passing in a value to search for, we pass in a callable object, such as a function pointer (or a lambda) that checks to see if a match is found. std::find_if will call this function for every element until a matching element is found (or no more elements remain in the container to check). If the functor never returns true, find_if returns the end iterator.

Here’s an example where we use std::find_if to check if any elements contain the substring “nut”:

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
  // std::string_view::find returns std::string_view::npos if it doesn't find
  // the substring. Otherwise it returns the index where the substring occurs
  // in str.
  return (str.find("nut") != std::string_view::npos);
}

int main()
{
  std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

  // Scan our array to see if any elements contain the "nut" substring
  auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

  if (found == arr.end())
  {
    std::cout << "No nuts\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  return 0;
}
```

Output
```
Found walnut
```

If you were to write the above example by hand, you’d need at least three loops (one to loop through the array, and two to match the substring). The standard library functions allow us to do the same thing in just a few lines of code!



Suppose you want to search a vector of integers, not for a single value, but for any value that falls within
a certain range. You can write a custom predicate to test a hard-coded range, but a more useful solution is to
write a general-purpose functor that compares an integer against any range. Use this functor by supplying
the range limits as argument to the constructor. Is this best implemented as a free function, function
object, or lambda? ________________________ Because it must store state, I recommend writing a functor.
A lambda is good when you need to search for specific values, but a functor is easier if you want to
write a generic comparator that can store the limits. Write the intrange functor. The constructor takes two
int arguments. The function call operator takes a single int argument. It returns true, if the argument falls
within the inclusive range specified in the constructor, or false, if the argument lies outside the range.

This range is inclusive of the low and high ends,
which differs from the C++ convention of using a half-open range. But it is the simplest way to ensure that
a range can span the entire set of integers. In a half-open range, a range in which the low and high have
the same value is the typical way to represent an empty range. With intrange, an empty range occurs
when high < low.

```cpp
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using intvector = std::vector<int>;

void read_data(intvector& data)
{
  data.clear();
  data.insert(data.begin(), std::istream_iterator<int>(std::cin),
                            std::istream_iterator<int>());
}

void write_data(intvector const& data)
{
  std::cout << "{ ";
  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "}\n";
}

class intrange
{
public:
  inline intrange(int low, int high)
  : low_{low}, high_{high}
  {}

  /// Check whether a value lies within the inclusive range.
  /// @param test the value to test
  inline bool operator()(int test) const
  {
    return test >= low_ and test <= high_;
  }
private:
  int const low_;
  int const high_;
};


int main()
{
  intvector data{};
  read_data(data);
  write_data(data);
  if (auto iter{std::ranges::find_if(data, intrange{10, 20})}; iter == data.end())
    std::cout << "No values in [10,20] found\n";
  else
    std::cout << "Value " << *iter << " in range [10,20].\n";
}

```




A few of the following examples generate random data and apply algorithms to the data. The standard
library has a rich, complicated library for generating pseudo-random numbers.

The search function is similar to find, except it searches for a matching subrange. That is, you supply
a range in which to search and a range of values to find. The search algorithm looks for the first occurrence
of a sequence of elements that equals the entire match range and returns a subrange that is actually a pair
of iterators that point into the search range for where it found the first match. If not found, the subrange is
empty, which evaluates as false in an if statement. Listing 45-6 shows a silly program that generates a large
vector of random integers in the range 0 to 9 and then searches for a subrange that matches the first four
digits of π.

```cpp
#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>

using intvector = std::vector<int>;

void read_data(intvector& data)
{
  data.clear();
  data.insert(data.begin(), std::istream_iterator<int>(std::cin),
                            std::istream_iterator<int>());
}

void write_data(intvector const& data)
{
  std::cout << "{ ";
  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "}\n";
}

class randomint
{
public:
  using result_type = std::default_random_engine::result_type;

  /// Construct a random-number generator to produce numbers in the range [`low`, `high`].
  /// If @p low > @p high the values are reversed.
  randomint(result_type low, result_type high)
  : prng_{},
    distribution_{std::min(low, high), std::max(low, high)}
  {}

  /// Generate the next random number generator.
  result_type operator()()
  {
     return distribution_(prng_);
  }

private:
  // implementation-defined pseudo-random-number generator
  std::default_random_engine prng_;
  // Map random numbers to a uniform distribution.
  std::uniform_int_distribution<result_type> distribution_;
};

int main()
{
  intvector pi{ 3, 1, 4, 1 };
  intvector data(10000, 0);
  // The randomint functor generates random numbers in the range [0, 9].
  std::ranges::generate(data, randomint{0, 9});

  auto match{std::ranges::search(data, pi)};
  if (not match)
    std::cout << "The integer range does not contain the digits of pi.\n";
  else
  {
    std::cout << "Easy as pi: ";
    std::ranges::copy(match, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
  }
}
```


Other useful linear functions include count, which takes a range and value and returns the number of occurrences of the value in the range. Its counterpart count_if takes a predicate instead of a value and returns the number of times the predicate returns true.

Three more algorithms have a common pattern.
They apply a predicate to every element in a range and return a bool:

• all_of(range, predicate) returns true if predicate(element) returns true for every element in range.

• any_of(range, predicate) returns true if predicate(element) returns true for at least one element in range.

• none_of(range, predicate) returns true if predicate(element) returns false for
every element in range.

The min, max, and minmax algorithms live in the iterator world and are equally home on the range. Prior to C++ 20, the min() function compared two values and returned the smaller; the min_element algorithm took two iterators and found the position of the smallest value. Now, the std::ranges::min() function returns the minimum value of a range, and std::ranges::min_element() also returns the minimum value of a range. Ditto for max(). You can guess what minmax returns: a pair of iterators for the minimum and maximum values in the range. All three come in the usual overloaded forms: one uses the < operator, and the other takes an additional argument for a comparison predicate.



### Binary Search Algorithms

The map container stores its elements in sorted order, so you can use any of the binary search algorithms, but
map also has member functions that can take advantage of access to the internal structure of a map and, so,
offer improved performance. Thus, the binary search algorithms are typically used on sequential containers,
such as vector, when you know that they contain sorted data. If the input range is not properly sorted, the
results are undefined: you might get the wrong answer; the program might crash; or something even worse
might happen.

The binary_search function simply tests whether a sorted range contains a particular value. By default,
values are compared using only the < operator. Another form of binary_search takes a comparison functor
as an additional argument to perform the comparison.

the find function performs a linear search for a single item. the search function performs a linear
search for a matching series of items. so why isn’t binary_search called binary_find? on the other
hand, find_end searches for the match that is furthest right in a range of values, so why isn’t it called
search_end? the equal function is completely different from equal_range, in spite of the similarity in
their names.
the C++ standards committee did its best to apply uniform rules for algorithm names, such as
appending _if to functions that take a functor argument but cannot be overloaded, but it faced some
historical constraints with a number of names. What this means for you is that you have to keep a
reference close at hand. Don’t judge a function by its name, but read the description of what the
function does and how it does it, before you decide whether it’s the right function to use.

The lower_bound function is similar to binary_search, except it exists only in iterator form. It takes
two iterators to delimit an input range, and it returns an iterator that points somewhere in that range. The
returned iterator points to the first occurrence of the value, or it points to a position where the value belongs
if you want to insert the value into the range and keep the values in sorted order. The upper_bound function
is similar to lower_bound, except it returns an iterator that points to the last position where you can insert the
value and keep it in sorted order. If the value is found, that means upper_bound points to one position past
the last occurrence of the value in the range. To put it another way, the range [lower_bound, upper_bound)
is the subrange of every occurrence of the value in the sorted range. As with any range, if lower_bound ==
upper_bound, the result range is empty, which means the value is not in the search range.

```cpp
#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>

using intvector = std::vector<int>;

void write_data(intvector const& data)
{
  std::cout << "{ ";
  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "}\n";
}

int main()
{
  intvector data{};
  int value;
  while (std::cin >> value)
  {
    auto lb{std::lower_bound(data.begin(), data.end(), value)};
    auto ub{std::upper_bound(data.begin(), data.end(), value)};
    if (lb == ub)
        // Not in data, so insert.
        data.insert(ub, value);
    // else value is already in the vector
  }
  write_data(data);

	auto iter{std::lower_bound(data.begin(), data.end(), 42)};
	std::cout << "Index of 42 is " << std::distance(data.begin(), iter) << '\n';
}
```

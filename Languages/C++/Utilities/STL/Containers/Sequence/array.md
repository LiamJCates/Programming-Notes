Library arrays

The fixed and dynamic arrays are directly implemented as a language feature, inherited from the C language. Although both are built right into the C++ language, they both have downsides: Fixed arrays decay into pointers, losing the array length information when they do, and dynamic arrays have messy deallocation issues and are challenging to resize without error.

To overcome some of the issues with language built-in arrays, the STL provides std::array in the <array> header, an alternative array type as a standard container.



An std::array is a sequential container that holds a fixed­size, contiguous series of elements. It combines the sheer performance and efficiency of built­-in arrays with the modern conveniences of supporting copy/move construction/assignment, knowing its own size, providing bounds ­checked member access, and other advanced features.

std::array provides fixed array functionality that won’t decay when passed into a function.

You should use array instead of built­in arrays in virtually all situations.
It supports almost all the same usage patterns as operator[] to access elements, so there aren’t many situations in which you’ll need a built­in array
instead.

The std::array class requires the header declaration:

  #include <array>



### Construction
The array<T, S> class template takes two template parameters:
  T, the contained type T
  S, the fixed size of the array

An example of declaring an integer array with length 3:

  std::array<int, 3> myArray;

Just like the native implementation of fixed arrays, the length of a std::array must be known at compile time.



### Initialization

The preferred method is to use braced initialization to construct a std::array.

std::array can be initialized using initializer lists or list initialization:

  std::array<int, 5> myArray = { 9, 7, 5, 3, 1 }; // initializer list
  std::array<int, 5> myArray2 { 9, 7, 5, 3, 1 }; // list initializationd

Braced initialization fills the array with the values contained in the braces and fills the remaining elements with zeros. If you omit initialization braces, the array contains uninitialized values depending on its storage duration.

Unlike built-in fixed arrays, with std::array you can not omit the array length when providing an initializer:

  std::array<int, > myArray { 9, 7, 5, 3, 1 };  // illegal
  std::array<int> myArray { 9, 7, 5, 3, 1 };    // illegal

However, since C++17, it is allowed to omit the type and size. They can only be omitted together, but not one or the other, and only if the array is explicitly initialized.

std::array myArray { 9, 7, 5, 3, 1 }; // type deduced to std::array<int, 5>
std::array myArray { 9.7, 7.31 }; // type deduced to std::array<double, 2>

We favor this syntax rather than typing out the type and size at the declaration. If your compiler is not C++17 capable, you need to use the explicit syntax instead.

Since C++20, it is possible to specify the element type but omit the array length. This makes creation of std::array a little more like creation of C-style arrays. To create an array with a specific type and deduced size, we use the std::to_array function:


auto myArray1 { std::to_array<int, 5>({ 9, 7, 5, 3, 1 }) }; // Specify type and size
auto myArray2 { std::to_array<int>({ 9, 7, 5, 3, 1 }) }; // Specify type only, deduce size
auto myArray3 { std::to_array({ 9, 7, 5, 3, 1 }) }; // Deduce type and size

Unfortunately, std::to_array is more expensive than creating a std::array directly, because it actually copies all elements from a C-style array to a std::array. For this reason, std::to_array should be avoided when the array is created many times, eg. in a loop.

You can also assign values to the array using an initializer list

std::array<int, 5> myArray;
myArray = { 0, 1, 2, 3, 4 }; // okay
myArray = { 9, 8, 7 }; // okay, elements 3 and 4 are set to zero!
myArray = { 0, 1, 2, 3, 4, 5 }; // not allowed, too many elements in initializer list!



### Element Access

The three main methods by which you can access arbitrary array elements are:
•	 operator[]
•	 at
•	 get

The operator[] and at methods take a single size_t argument corresponding to the index of the desired element. The difference between these two
lies in bounds checking: if the index argument is out of bounds, at will
throw a std::out_of_range exception, whereas operator[] will cause undefined
behavior. The function template get takes a template parameter of the
same specification. Because it’s a template, the index must be known at
compile time.

Recall that a size_t object guarantees that its maximum value is sufficient to represent the maximum size in bytes of all objects. It is for this reason that operator[] and at take a size_t rather than an int, which makes no such guarantee.

Accessing std::array values using the subscript operator to get and set values works just like you would expect:

  std::cout << myArray[1] << '\n';
  myArray[2] = 6;

Just like built-in fixed arrays, the subscript operator does not do any bounds-checking. If an invalid index is provided this is undefined behavior.

std::array supports a second form of array element access, the at() function, that allows us to get and set array elements an provides bounds checking:

  std::array myArray { 9, 7, 5, 3, 1 };
  myArray.at(1) = 6; // index 1 is valid, sets array element 1 to value 6
  myArray.at(9) = 10; // index 9 is invalid, will throw an error

In the above example, the call to myArray.at(1) checks to ensure the index 1 is valid, and because it is, it returns a reference to array element 1. We then assign the value of 6 to this. However, the call to myArray.at(9) fails because array element 9 is out of bounds for the array. Instead of returning a reference, the at() function throws an error of type std::out_of_range . Because it does bounds checking, at() is slower (but safer) than operator[].

Finally, you can use std::get to set and get elements. The get element also performs bounds checking:

  std::array<int, 4> fib{ 1, 1, 0, 3};
  std::get<2>(fib) = 2;
  std::get<4>(fib);

A major bonus of using get is that you get compile-­time bounds checking
std::get<4>(fib); ~ will cause compilation failure.



#### Positional

You’ve also have a front and a back method, which return references to the first and last elements of the array.

You’ll get undefined behavior if you call one of these methods if the array has zero length:

TEST_CASE("std::array has convenience methods") {
  std::array<int, 4> fib{ 0, 1, 2, 0 };

  SECTION("front") {
    fib.front() = 1;
    REQUIRE(fib.front() == 1);
    REQUIRE(fib.front() == fib[0]);
  }
  SECTION("back") {
    fib.back() = 3;
    REQUIRE(fib.back() == 3);
    REQUIRE(fib.back() == fib[3]);
  }
}

You can use the front and back methods to set and get the first and last elements of an array. Of course, fib[0] is identical to
fib.front(), and fib[3] is identical to fib.back().
The front() and back() methods are simply convenience methods. Additionally, if you’re writing generic code, some containers will offer front and back but not
operator[], so it’s best to use the front and back methods.



### Size

The size() function can be used to retrieve the length of the std::array:

  std::array myArray { 9.0, 7.2, 5.4, 3.6, 1.8 };
  std::cout << "length: " << myArray.size() << '\n';

Output:

  length: 5



### Manually indexing std::array via size_type

What’s wrong with the following code?

  #include <iostream>
  #include <array>

  int main()
  {
    std::array myArray { 7, 3, 1, 9, 5 };

    for (int i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
  }

The answer is that there’s a likely signed/unsigned mismatch in this code! Due to a curious decision, the size() function and array index parameter to operator[] use a type called size_type, which is defined by the C++ standard as an unsigned integral type. Our loop counter/index (variable i) is a signed int. Therefore both the comparison i < myArray.size() and the array index myArray[i] have type mismatches.

Interestingly enough, size_type isn't a global type (like int or std::size_t). Rather, it's defined inside the definition of std::array (C++ allows nested types). This means when we want to use size_type, we have to prefix it with the full array type (think of std::array acting as a namespace in this regard). In our above example, the fully-prefixed type of "size_type" is std::array<int, 5>::size_type!

Therefore, the correct way to write the above code is as follows:

  #include <array>
  #include <iostream>

  int main()
  {
    std::array myArray { 7, 3, 1, 9, 5 };

    // std::array<int, 5>::size_type is the return type of size()!
    for (std::array<int, 5>::size_type i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
  }

That's not very readable. Fortunately, std::array::size_type is just an alias for std::size_t, so we can use that instead.

  #include <array>
  #include <cstddef> // std::size_t
  #include <iostream>

  int main()
  {
    std::array myArray { 7, 3, 1, 9, 5 };

    for (std::size_t i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
  }

A better solution is to avoid manual indexing of std::array in the first place. Instead, use range-based for-loops (or iterators) if possible.

Keep in mind that unsigned integers wrap around when you reach their limits. A common mistake is to decrement an index that is 0 already, causing a wrap-around to the maximum value. You saw this in the lesson about for-loops, but let's repeat.

  #include <array>
  #include <iostream>

  int main()
  {
    std::array myArray { 7, 3, 1, 9, 5 };

    // Print the array in reverse order.
    // We can use auto, because we're not initializing i with 0.
    // Bad:
    for (auto i{ myArray.size() - 1 }; i >= 0; --i)
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
  }

This is an infinite loop, producing undefined behavior once i wraps around. There are two issues here. If 'myArray' is empty, ie. size() returns 0 (which is possible with std::array), myArray.size() - 1 wraps around. The other issue occurs no matter how many elements there are. i >= 0 is always true, because unsigned integers cannot be less than 0.

A working reverse for-loop for unsigned integers takes an odd shape:

  #include <array>
  #include <iostream>

  int main()
  {
      std::array myArray { 7, 3, 1, 9, 5 };

      // Print the array in reverse order.
      for (auto i{ myArray.size() }; i-- > 0; )
          std::cout << myArray[i] << ' ';

      std::cout << '\n';

      return 0;
  }

Suddenly we decrement the index in the condition, and we use the postfix -- operator. The condition runs before every iteration, including the first. In the first iteration, i is myArray.size() - 1, because i was decremented in the condition. When i is 0 and about to wrap around, the condition is no longer true and the loop stops. i actually wraps around when we do i-- for the last time, but it's not used afterwards




### As a Parameter

Because std::array doesn’t decay to a pointer when passed to a function, the size() function will work even if you call it from within a function:

  #include <array>
  #include <iostream>

  void printLength(const std::array<double, 5> &myArray)
  {
      std::cout << "length: " << myArray.size() << '\n';
  }

  int main()
  {
      std::array myArray { 9.0, 7.2, 5.4, 3.6, 1.8 };
      printLength(myArray);

      return 0;
  }

Output:

  length: 5


Also note that we passed std::array by (const) reference. This is to prevent the compiler from making a copy of the std::array when the std::array was passed to the function (for performance reasons).

Rule

Always pass std::array by reference or const reference

Because the length is always known, range-based for-loops work with std::array:

std::array myArray{ 9, 7, 5, 3, 1 };

for (int element : myArray)
    std::cout << element << ' ';



### Storage Model

A std::array doesn’t make allocations; rather, like a built­in array, it contains all of its elements.

This means
  copies will generally be expensive, as each constituent element is copied.
  Moves can be inexpensive, if the underlying type of the array has move construction and move assignment, and not otherwise.

Each std::array is just a built­in array underneath. In fact, you can extract a
pointer to the first element of an array using four distinct methods:

•	 The data method, which returns a pointer to the first element, is preferred.
•	 The other three methods use the address­of operator & on the first element, obtained using operator[], at, and front.

If the array is empty, the address­-of-­based approaches will return undefined behavior.

How to obtain a pointer using these four methods:

  std::array<char, 9> color{ 'o', 'c', 't', 'a', 'r', 'i', 'n', 'e' };
  const auto* color_ptr = color.data();
  &color.front() == color_ptr;
  &color.at(0) == color_ptr;
  &color[0] == color_ptr);




Delete

std::array will clean up after itself when it goes out of scope, so there’s no need to do any kind of manual cleanup.


### Sort

You can sort std::array using std::sort from the <algorithm> header:

  #include <algorithm>
  #include <array>
  #include <iostream>

  int main()
  {
      std::array myArray { 7, 3, 1, 9, 5 };
      std::sort(myArray.begin(), myArray.end()); // sort array forwards
  //  std::sort(myArray.rbegin(), myArray.rend()); // sort array backwards

      for (int element : myArray)
          std::cout << element << ' ';

      std::cout << '\n';

      return 0;
  }

This prints:

  1 3 5 7 9

The sorting function uses iterators.

For more information regarding iterators, see
[C++\Utilities\STL\iterators.md]



A Partial List of Supported Operations
In this table, a, a1, and a2 are of type std::array<T, S>, t is of type T, S is the fixed length of the array, and i is of type size_t.


| Operation | Notes |
|-----------|-------|
| array<T, S>{ ... } | Performs braced initialization of a newly constructed array. |
| ~array | Destructs all elements contained by the array. |
| a1 = a2 | Copy-assigns all the members of a1 with the members of a2. |
| a.at(i)  Returns a reference to element i of a. Throws std::out_of_range if out of bounds. |
| a[i] | Returns a reference to element i of a. Undefined behavior if out of bounds. |
| get<i>(a) | Returns a reference to element i of a. Fails to compile if out of bounds. |
| a.front() | Returns a reference to first element. |
| a.back() | Returns a reference to last element. |
| a.data() | Returns a raw pointer to the first element if the array is non-empty. For empty arrays, returns a valid but non-dereferencable pointer. |
| a.empty() | Returns true if the array’s size is zero; otherwise false. |
| a.size() | Returns the size of the array. |
| a.max_size() | Identical to a.size(). |
| a.fill(t) | Copy-assigns t to every element of a. |
| a1.swap(a2) | Exchanges each element of a1 with those of a2. |
| swap(a1, a2) | Exchanges each element of a1 with those of a2. |
| a.begin() | Returns an iterator pointing to the first element. |
| a.cbegin() | Returns a const iterator pointing to the first element. |
| a.end() | Returns an iterator pointing to 1 past the last element. |
| a.cend() | Returns a const iterator pointing to 1 past the last element. |
| a1 == a2 | True if all elements are equal. |
| a1 != a2 | True if any elements differ. |
| a1 > a2 | Greater than, comparisons proceed from first element to last. |
| a1 >= a2 | Greater than or equal, comparisons proceed from first element to last. |
| a1 < a2 | Less than, comparisons proceed from first element to last. |
| a1 <= a2 | Less than or equal, comparisons proceed from first element to last.

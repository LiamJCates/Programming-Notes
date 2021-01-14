Library arrays

The fixed and dynamic arrays are directly implemented as a language feature, inherited from the C language. Although both are built right into the C++ language, they both have downsides: Fixed arrays decay into pointers, losing the array length information when they do, and dynamic arrays have messy deallocation issues and are challenging to resize without error.


To overcome some of these issues with language built-in arrays, C++ provides an alternative array type as a standard container. It is a type template (a class template, in fact) defined in header <array>.

Containers are a library feature that they operate in a similar way to built-in arrays, except that they allow being copied (an actually expensive operation that copies the entire block of memory, and thus to use with care) and decay into pointers only when explicitly told to do so (by means of its member data).

Just as an example, these are two versions of the same example using the language built-in array described in this chapter, and the container in the library:

language built-in array

  #include <iostream>

  using namespace std;

  int main()
  {
    int myarray[3] = {10,20,30};

    for (int i=0; i<3; ++i)
      ++myarray[i];

    for (int elem : myarray)
      cout << elem << '\n';
  }


container library array

  #include <iostream>
  #include <array>
  using namespace std;

  int main()
  {
    array<int,3> myarray {10,20,30};

    for (int i=0; i<myarray.size(); ++i)
      ++myarray[i];

    for (int elem : myarray)
      cout << elem << '\n';
  }


As you can see, both kinds of arrays use the same syntax to access its elements: myarray[i]. Other than that, the main differences lay on the declaration of the array, and the inclusion of an additional header for the library array. Notice also how it is easy to access the size of the library array.















An introduction to std::array

std::array provides fixed array functionality that won’t decay when passed into a function. std::array is defined in the <array> header, inside the std namespace.

Declaring a std::array variable is easy:

1
2
3

#include <array>

std::array<int, 3> myArray; // declare an integer array with length 3

Just like the native implementation of fixed arrays, the length of a std::array must be known at compile time.

std::array can be initialized using initializer lists or list initialization:

1
2

std::array<int, 5> myArray = { 9, 7, 5, 3, 1 }; // initializer list
std::array<int, 5> myArray2 { 9, 7, 5, 3, 1 }; // list initialization

Unlike built-in fixed arrays, with std::array you can not omit the array length when providing an initializer:

1
2

std::array<int, > myArray { 9, 7, 5, 3, 1 }; // illegal, array length must be provided
std::array<int> myArray { 9, 7, 5, 3, 1 }; // illegal, array length must be provided

However, since C++17, it is allowed to omit the type and size. They can only be omitted together, but not one or the other, and only if the array is explicitly initialized.

1
2

std::array myArray { 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
std::array myArray { 9.7, 7.31 }; // The type is deduced to std::array<double, 2>

We favor this syntax rather than typing out the type and size at the declaration. If your compiler is not C++17 capable, you need to use the explicit syntax instead.

1
2
3
4
5

// std::array myArray { 9, 7, 5, 3, 1 }; // Since C++17
std::array<int, 5> myArray { 9, 7, 5, 3, 1 }; // Before C++17

// std::array myArray { 9.7, 7.31 }; // Since C++17
std::array<double, 2> myArray { 9.7, 7.31 }; // Before C++17

Since C++20, it is possible to specify the element type but omit the array length. This makes creation of std::array a little more like creation of C-style arrays. To create an array with a specific type and deduced size, we use the std::to_array function:

1
2
3

auto myArray1 { std::to_array<int, 5>({ 9, 7, 5, 3, 1 }) }; // Specify type and size
auto myArray2 { std::to_array<int>({ 9, 7, 5, 3, 1 }) }; // Specify type only, deduce size
auto myArray3 { std::to_array({ 9, 7, 5, 3, 1 }) }; // Deduce type and size

Unfortunately, std::to_array is more expensive than creating a std::array directly, because it actually copies all elements from a C-style array to a std::array. For this reason, std::to_array should be avoided when the array is created many times, eg. in a loop.

You can also assign values to the array using an initializer list

1
2
3
4

std::array<int, 5> myArray;
myArray = { 0, 1, 2, 3, 4 }; // okay
myArray = { 9, 8, 7 }; // okay, elements 3 and 4 are set to zero!
myArray = { 0, 1, 2, 3, 4, 5 }; // not allowed, too many elements in initializer list!

Accessing std::array values using the subscript operator works just like you would expect:

1
2

std::cout << myArray[1] << '\n';
myArray[2] = 6;

Just like built-in fixed arrays, the subscript operator does not do any bounds-checking. If an invalid index is provided, bad things will probably happen.

std::array supports a second form of array element access (the at() function) that does bounds checking:

1
2
3

std::array myArray { 9, 7, 5, 3, 1 };
myArray.at(1) = 6; // array element 1 is valid, sets array element 1 to value 6
myArray.at(9) = 10; // array element 9 is invalid, will throw an error

In the above example, the call to myArray.at(1) checks to ensure the index 1 is valid, and because it is, it returns a reference to array element 1. We then assign the value of 6 to this. However, the call to myArray.at(9) fails because array element 9 is out of bounds for the array. Instead of returning a reference, the at() function throws an error that terminates the program (note: It’s actually throwing an exception of type std::out_of_range -- we cover exceptions in chapter 14). Because it does bounds checking, at() is slower (but safer) than operator[].

std::array will clean up after itself when it goes out of scope, so there’s no need to do any kind of manual cleanup.

Size and sorting

The size() function can be used to retrieve the length of the std::array:

1
2

std::array myArray { 9.0, 7.2, 5.4, 3.6, 1.8 };
std::cout << "length: " << myArray.size() << '\n';

This prints:

length: 5

Because std::array doesn’t decay to a pointer when passed to a function, the size() function will work even if you call it from within a function:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16

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

This also prints:

length: 5

Note that the standard library uses the term “size” to mean the array length — do not get this confused with the results of sizeof() on a native fixed array, which returns the actual size of the array in memory (the size of an element multiplied by the array length). Yes, this nomenclature is inconsistent.

Also note that we passed std::array by (const) reference. This is to prevent the compiler from making a copy of the std::array when the std::array was passed to the function (for performance reasons).

Rule

Always pass std::array by reference or const reference

Because the length is always known, range-based for-loops work with std::array:

1
2
3
4

std::array myArray{ 9, 7, 5, 3, 1 };

for (int element : myArray)
    std::cout << element << ' ';

You can sort std::array using std::sort, which lives in the <algorithm> header:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17

#include <algorithm> // for std::sort
#include <array>
#include <iostream>

int main()
{
    std::array myArray { 7, 3, 1, 9, 5 };
    std::sort(myArray.begin(), myArray.end()); // sort the array forwards
//  std::sort(myArray.rbegin(), myArray.rend()); // sort the array backwards

    for (int element : myArray)
        std::cout << element << ' ';

    std::cout << '\n';

    return 0;
}

This prints:

1 3 5 7 9

The sorting function uses iterators, which is a concept we haven’t covered yet, so for now you can treat the parameters to std::sort() as a bit of magic. We’ll explain them later.

Manually indexing std::array via size_type

Pop quiz: What’s wrong with the following code?

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15

#include <iostream>
#include <array>

int main()
{
    std::array myArray { 7, 3, 1, 9, 5 };

    // Iterate through the array and print the value of the elements
    for (int i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
}

The answer is that there’s a likely signed/unsigned mismatch in this code! Due to a curious decision, the size() function and array index parameter to operator[] use a type called size_type, which is defined by the C++ standard as an unsigned integral type. Our loop counter/index (variable i) is a signed int. Therefore both the comparison i < myArray.size() and the array index myArray[i] have type mismatches.

Interestingly enough, size_type isn't a global type (like int or std::size_t). Rather, it's defined inside the definition of std::array (C++ allows nested types). This means when we want to use size_type, we have to prefix it with the full array type (think of std::array acting as a namespace in this regard). In our above example, the fully-prefixed type of "size_type" is std::array<int, 5>::size_type!

Therefore, the correct way to write the above code is as follows:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15

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

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15

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

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17

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

This is an infinite loop, producing undefined behavior once i wraps around. There are two issues here. If `myArray` is empty, ie. size() returns 0 (which is possible with std::array), myArray.size() - 1 wraps around. The other issue occurs no matter how many elements there are. i >= 0 is always true, because unsigned integers cannot be less than 0.

A working reverse for-loop for unsigned integers takes an odd shape:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15

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

























The STL provides std::array in the <array> header. An array is a sequential
container that holds a fixed­size, contiguous series of elements. It combines
the sheer performance and efficiency of built­in arrays with the modern
conveniences of supporting copy/move construction/assignment, knowing
its own size, providing bounds­checked member access, and other advanced
features.
You should use array instead of built­in arrays in virtually all situations.
It supports almost all the same usage patterns as operator[] to access elements, so there aren’t many situations in which you’ll need a built­in array
instead.






Constructing
The array<T, S> class template takes two template parameters:
•	 The contained type T
•	 The fixed size of the array S

You can construct an array and built­in arrays using the same rules.

The preferred method is to use braced initialization to construct an array. Braced initialization fills the array with the values contained in the braces and fills the remaining elements with zeros. If you omit initialization braces, the array contains uninitialized values depending on its storage duration.


Braced initialization with several array declarations:

#include <array>
std::array<int, 10> static_array;

TEST_CASE("std::array") {
  REQUIRE(static_array[0] == 0);

  SECTION("uninitialized without braced initializers") {
    std::array<int, 10> local_array;
    REQUIRE(local_array[0] != 0);
  }

  SECTION("initialized with braced initializers") {
    std::array<int, 10> local_array{ 1, 1, 2, 3 };
    REQUIRE(local_array[0] == 1);
    REQUIRE(local_array[1] == 1);
    REQUIRE(local_array[2] == 2);
    REQUIRE(local_array[3] == 3);
    REQUIRE(local_array[4] == 0);
  }
}

You declare an array of 10 int objects called static_array with static
storage duration. You haven’t used braced initialization, but its elements initialize to zero anyway due to it's storage duration.

Next, you try declaring another array of 10 int objects, this time with
automatic storage duration. Because you haven’t used braced initialization, local_array contains uninitialized elements (that have an extremely
low probability of equaling zero).

Finally, you use braced initialization to declare another array and to fill
the first four elements. All remaining elements get set to zero.

Element Access
The three main methods by which you can access arbitrary array elements are:
•	 operator[]
•	 at
•	 get

The operator[] and at methods take a single size_t argument corresponding to the index of the desired element. The difference between these two lies in bounds checking: if the index argument is out of bounds, at will
throw a std::out_of_range exception, whereas operator[] will cause undefined
behavior. The function template get takes a template parameter of the
same specification. Because it’s a template, the index must be known at
compile time.

N O T E
Recall from “The size_t Type” on page 41 that a size_t object guarantees that its maximum value is sufficient to represent the maximum size in bytes of all objects. It is for this reason that operator[] and at take a size_t rather than an int, which makes no such guarantee.


A major bonus of using get is that you get compile-­time bounds checking:

TEST_CASE("std::array access") {
  std::array<int, 4> fib{ 1, 1, 0, 3};
  SECTION("operator[] can get and set elements") {
    fib[2] = 2;
    REQUIRE(fib[2] == 2);
    // fib[4] = 5;
  }

  SECTION("at() can get and set elements") {
    fib.at(2) = 2;
    REQUIRE(fib.at(2) == 2);
    REQUIRE_THROWS_AS(fib.at(4), std::out_of_range); {
  }

  SECTION("get can get and set elements") {
    std::get<2>(fib) = 2;
    REQUIRE(std::get<2>(fib) == 2);
    // std::get<4>(fib);
  }
}

Uncommenting // fib[4] = 5; x will cause undefined behavior.
Uncommenting // std::get<4>(fib); ~ will cause compilation failure.

You declare an array of length 4 called fib. Using operator[] you can set elements and retrieve them. The out of bounds write you’ve commented out would cause undefined behavior; there is no bounds checking with operator[].

You can use at for the same read and write operations, and you can safely perform an out­of­bounds operation thanks to bounds checking.

Finally, you can use std::get to set and get elements. The get element also performs bounds checking, so // std::get<4>(fib); will fail to compile if uncommented.


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


Storage Model
An array doesn’t make allocations; rather, like a built­in array, it contains all of its elements. This means copies will generally be expensive, because each
constituent element needs to be copied. Moves can be expensive, depending on whether the underlying type of the array also has move construction and move assignment, which are relatively inexpensive.

Each array is just a built­in array underneath. In fact, you can extract a
pointer to the first element of an array using four distinct methods:

•	 The go-­to method is to use the data method. As advertised, this returns
a pointer to the first element.
•	 The other three methods involve using the address­of operator & on the first element, which you can obtain using operator[], at, and front.

You should use data.

If the array is empty, the address­-of-­based approaches will return undefined behavior.

How to obtain a pointer using these four methods:

TEST_CASE("We can obtain a pointer to the first element using") {
  std::array<char, 9> color{ 'o', 'c', 't', 'a', 'r', 'i', 'n', 'e' };
  const auto* color_ptr = color.data();

  SECTION("data") {
    REQUIRE(*color_ptr == 'o');
  }
  SECTION("address-of front") {
    REQUIRE(&color.front() == color_ptr);
  }

  SECTION("address-of at(0)") {
    REQUIRE(&color.at(0) == color_ptr);
  }

  SECTION("address-of [0]") {
    REQUIRE(&color[0] == color_ptr);
  }
}





A Partial List of Supported Operations
In this table, a, a1, and a2 are of type std::array<T, S>, t is of type T, S is the fixed length of the array, and i is of type size_t.

Table 13-1: A Partial List of std::array Operations

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

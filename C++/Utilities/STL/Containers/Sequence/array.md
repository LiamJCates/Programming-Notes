Library arrays
The arrays explained above are directly implemented as a language feature, inherited from the C language. They are a great feature, but by restricting its copy and easily decay into pointers, they probably suffer from an excess of optimization.

To overcome some of these issues with language built-in arrays, C++ provides an alternative array type as a standard container. It is a type template (a class template, in fact) defined in header <array>.

Containers are a library feature that falls out of the scope of this tutorial, and thus the class will not be explained in detail here. Suffice it to say that they operate in a similar way to built-in arrays, except that they allow being copied (an actually expensive operation that copies the entire block of memory, and thus to use with care) and decay into pointers only when explicitly told to do so (by means of its member data).

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

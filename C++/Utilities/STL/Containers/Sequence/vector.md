## Dynamic Arrays
To program an application that is able to optimally consume memory resources on the basis of the needs of the user, you need to use dynamic memory allocation. This enables you to allocate more when you need more memory and release memory that you have in excess. C++ supplies you two operators, new and delete, to help you better manage the memory consumption of your application. Pointers being variables that are used to contain memory addresses play a critical role in efficient dynamic memory allocation.

choose dynamic arrays that optimize memory consumption and scale up depending on the demand for resources and memory at execution-time. C++ provides you with convenient and easy-to-use dynamic arrays in the form of std::vector

 #include <iostream>
 #include <vector>

using namespace std;
//using std::vector;

int main()
{
vector<int> dynArray (3); // dynamic array of int

dynArray[0] = 365;
dynArray[1] = -421;
dynArray[2]= 789;

cout << "Number of integers in array" << dynArray.size() << endl;

cout << "Enter another element to insert" << endl;
int newValue = 0;
cin >> newValue;
dynArray.push_back(newValue);

cout << "Number of integers in array" << dynArray.size() << endl;
cout << "Last element in array";
cout << dynArray[dynArray.size() - 1] << endl;
return 0;

}

To use the dynamic array class std::vector, you need to
include header vector.
 #include <vector>

[vector].push_back();
adds element to the end of the collection

ranged for loop useful for vector collection iteration






















vector
vectors are a sequential container that holds a dynamically sized, contiguous series of elements of a given type.

The std::vector available in the STL’s <vector> header
Thus, to use a vector container include the following statement:

  #include <vector>

The vector is the workhorse of the sequential ­data­ structure stable. For a very modest overhead, you gain substantial flexibility over the array. Plus, vector supports almost all of the same operations as an array and adds a slew of others. If you have a fixed number of elements on hand, you should strongly consider an array because you’ll get some small reductions in overhead versus a vector. In all other situations, your go-­to sequential container is the vector.

A vector container stores and manages its objects in a contiguous dynamic array. Because an array is a random access data structure, the elements of a vector can be accessed randomly in constant time.

A vector manages its storage dynamically, requiring no outside help from
the programmer. Storage is managed automatically so that on an attempt to insert an element into a full vector, a larger memory block is allocated for the vector, the vector elements are copied to the new block, and the old block is released. A vector is thus a flexible array; that is, an array whose size can be dynamically changed.

Item insertion in the middle or beginning of an array is time consuming, especially if the array is large, as it is directly
proportional to the number of elements behind the element being removed.. However, inserting an item at the end constant time.


## Constructing
The class template std::vector<T, Allocator> takes two template parameters:
  The contained type T
  The optional allocator type Allocator, which defaults to std::allocator<T>.

You have much more flexibility in constructing vectors than you do with arrays. A vector supports user­ defined allocators because vectors need
to allocate dynamic memory.

Default construction contains no elements:
std::vector<T> vec;

You might want to construct an empty vector so you can fill it with a variable number of elements depending on what happens at runtime.

We can specify a default vector of a particular size:
std::vector<T> vec(23);

An explicit size is enclosed in ordinary parentheses, for example, (23), and by default, the elements are initialized to the element type’s default value (e.g., nullptr for pointers and 0 for numbers).

Braced initialization fills the vector with the specified elements:
std::vector<int> vec{ 1, 1, 2, 3, 5 };
std::vector<int> vec = { 1, 1, 2, 3, 5 };

To fill construct a vector, you first pass a size_t corresponding to the number of elements you want to fill:
std::vector<int> five_nines(5, 9);

Optionally, you can pass a const reference to an object to copy.

Copy a vector of compatible type:
std::vector<int> other_vec(vec);

Use a half­-open range by passing in the begin and end iterators of the range you want to copy:
std::vector<int> range_vec(vec.begin(), vec.end());

You may also splice out a subset of some range and copy it into a vector:
std::vector<int> partial_range_vec(vec.begin()+1, vec.begin()+3);

DECLARING VECTOR OBJECTS

| Constructor | Effects |
|-------------|---------|
| vector<T> vec; | Creates the empty vector container vec. (default constructor) |
| vector<T> vec(othervec); | Creates the vector container vec and initializes vec to the elements of the vector othervec. vec and other_vec are of the same type. |
| vector<T> vec(size); | Creates the vector container vec of size size. vec is initialized using the default constructor. |
| vector<T> vec(n, elm); | Creates the vector container vec of size n. vec is initialized using n copies of the element elm. |
| vector<T> vec(beg, end); | Creates the vector container vec. vec is initialized to the elements in the range [beg, end), that is, all the elements in the range beg. . .end-1. Both beg and end are pointers, called iterators in STL terminology. |
| vector<T>(move(othervec)) | Takes ownership of memory, elements in othervec. No allocations. |
| ~vector | Destructs all elements contained by the vector and releases
dynamic memory. |
| v1 = v2 | v1 destructs its elements; copies each v2 element. Only allocates if it needs to resize to fit v2’s elements. |
| v1 = move(v2) | v1 destructs its elements; moves each v2 element. Only allocates if it needs to resize to fit v2’s elements. |


Move and Copy Semantics
Vectors have full copy/move construction/assignment support.
Any vector copy operation is potentially very expensive, because these are element­wise or deep copies.

Move operations, on the other hand, are usually very fast, because the contained elements reside in dynamic memory and the moved­ from vector can simply pass ownership to the moved­ into vector; there’s no need to move the contained elements.


Element Access
A vector supports most of the same element access operations as array:
at, operator[], front, back, and data.

| Expression | Description|
|------------|------------|
|vec.at(index) | Returns the element at the position specified by index. |
| vec[index] | Returns the element at the position specified by index. |
| vec.front() | Returns the first element. (Does not check whether the container is empty.) |
| vec.back() | Returns the last element. (Does not check whether the container is empty.) |
| vec.data() | Returns a raw pointer to the first element if array is non-empty. For empty arrays, returns a valid but non-dereferencable pointer. |


Test Capacity

| Expression | Description|
|------------|------------|
| vec.size() | Returns the number of elements currently in the container vec. |
| vec.max_size() | Returns the maximum number of elements that can be inserted into the container vec. |
| vec.capacity() | Returns the maximum number of elements that can be inserted into the container vec without reallocation. |
| vec.empty() | Returns true if the container vec is empty, false otherwise. |


Alter Capacity

| Expression | Description|
|------------|------------|
| vec.resize(num) | Changes the number of elements to num. If size increases, the default constructor creates the new elements. |
| vec.resize(num, elem) | Changes the number of elements to num. If size increases, the new elements are copies of elem. |
| v.reserve(s) | Increases the vector’s storage so it can contain at least s elements. |
| vec.shrink_to_fit() | Might reduce the vector’s storage so capacity() equals size(). |

Comparison Operations

| Expression | Description|
|------------|------------|
| v1 == v2 | True if all elements are equal. |
| v1 != v2 | True if at least one element is unequal. |
| v1 > v2 | Greater than comparisons proceed from first element to last. |
| v1 >= v2 | Greater than or equal comparisons proceed from first element to last. |
| v1 < v2 | Less than comparisons proceed from first element to last. |
| v1 <= v2 | Less than or equal comparisons proceed from first element to last. |



Modifiers
| Expression | Description|
|------------|------------|
| vec.assign({ ... }) | Replaces the contents of v with the elements .... |
| vec.assign(s, t) | Replaces the contents of v with s number of copies of t. |
| vec.assign(initialization list) | Replaces container elements. |
| vec.clear() | Deletes all of the elements from the container. |
| vec.erase(position) | Deletes the element at the position specified by position iterator. |
| vec.erase(beg, end) | Deletes all of the elements starting at beg until end-1. |
| vec.insert(position, elem) | A copy of elem is inserted at the position specified by position iterator. The position of the new element is returned. |
| vec.insert(position, n, elem) | n copies of elem are inserted at the position specified by position iterator. |
| vec.insert(position, beg, end) | A copy of the elements, starting at beg until end-1, is inserted into vec at the position specified by position iterator. |
| vec.push_back(elem) | A copy of elem is inserted into vec at the end. |
| vec.pop_back() | Deletes the last element. |
| vec.emplace(iter, (T)(...)) | construct and insert element at position pointed to by iterator an element constructed in place. |
| vec.emplace_back((T)(...))| Construct and insert element at the end |
| v1.swap(v2) | Exchanges each element of v1 with those of v2. |
| swap(v1, v2) | Exchanges each element of v1 with those of v2. |

Access and set individual elements
vec[0] = (T)object;

Because the emplacement methods can construct elements in place, it seems they should be more efficient than the insertion methods. This intuition is often correct, but for complicated and unsatisfying reasons it’s not always faster. As a general rule, use the emplacement methods. If you determine a performance bottleneck, also try the insertion methods.

See Item 42 of Effective Modern C++ by Scott Meyers for a treatise.







Compacting bools

std::vector has another cool trick up its sleeves. There is a special implementation for std::vector of type bool that will compact 8 booleans into a byte! This happens behind the scenes, and doesn’t change how you use the std::vector.

  #include <vector>
  #include <iostream>

  int main()
  {
      std::vector<bool> array { true, false, false, true, true };
      std::cout << "The length is: " << array.size() << '\n';

      for (int i : array)
          std::cout << i << ' ';

      std::cout << '\n';

      return 0;
  }

Outputs:

The length is: 5
1 0 0 1 1












## Storage Model
Although vector elements are contiguous in memory, like an array, the similarities stop there. A vector has dynamic size, so it must be able to
resize. The allocator of a vector manages the dynamic memory underpinning the vector.

Because allocations are expensive, a vector will request more memory than it needs to contain the current number of elements. Once it can no longer add any more elements, it will request additional memory. The memory for a vector is always contiguous, so if there isn’t enough space at the end of the existing vector, it will allocate a whole new region of memory and move all the elements of the vector into the new region. The number of elements a vector holds is called its size, and the number of elements it could theoretically hold before having to resize is called its capacity. Figure 13­2 illustrates a vector containing three elements with additional capacity for
three more.

The vector continues past the last element. The capacity determines how many elements the vector could hold in this space.

The upshot of this design is that inserting at the end of a vector is
extremely fast (unless the vector needs to resize). Inserting anywhere else
incurs additional cost, because the vector needs to move elements around
to make room.

If you know ahead of time that you’ll need a certain capacity, you can
use the reserve method, which takes a single size_t argument corresponding to the number of elements you want capacity for. On the other hand, if you’ve just removed several elements and want to return memory to the allocator, you can use the shrink_to_fit method, which declares that you have excess capacity. The allocator can decide to reduce capacity or not (it’s a non­binding call).

Additionally, you can delete all the elements in a vector and set its size
to zero using the clear method.

When you insert a new element, its value is copied
into the container. For example, when you put an integer with the value 7 into a container, the
resulting element really has the value 7. The element is not a reference or a pointer to some object
containing 7. This makes for nice, compact containers with fast access. For people who care about
memory sizes and run-time performance this is critical.




### VECTOR ITERATOR
The class vector contains a typedef iterator, which is declared as a public member. An iterator to a vector container is declared using the typedef iterator:

vector<int>::iterator intVecIter;

declares intVecIter to be an iterator in a vector container of type int.

Suppose that we have the following statements:
vector<int> intList; //Line 1
vector<int>::iterator intVecIter; //Line 2
The statement in Line 1 declares intList to be a vector container, and the element
type is int. The statement in Line 2 declares intVecIter to be an iterator in a vector
container whose element type is int.

Any time you use insert, existing iterators become invalid


| Expression | Description|
|------------|------------|
| vec.begin() | Returns an iterator pointing to the first element. |
| vec.cbegin() | Returns a const iterator pointing to the first element. |
| vec.rbegin() | Returns a reverse iterator pointing to the last element. |
| vec.crbegin() | Returns a reverse const iterator pointing to the last element. |
| vec.end() | Returns an iterator pointing to 1 past the last element. |
| vec.cend() | Returns a const iterator pointing to 1 past the last element. |
| vec.rend() | Returns a reverse iterator pointing to the first element. |
| vec.crend() | Returns a reverse const iterator pointing to the first element. |







Range Checking
The standard-library vector does not guarantee range checking. For example:
void silly(vector<Entr y>& book)
{
int i = book[book.size()].number; // book.size() is out of range
// ...
}

That initialization is likely to place some random value in i rather than giving an error. This is
undesirable, and out-of-range errors are a common problem. Consequently, I often use a simple
range-checking adaptation of vector:
template<typename T>
class Vec : public std::vector<T> {
public:
using vector<T>::vector; // use the constructors from vector (under the name Vec)
T& operator[](int i) // range check
{ return vector<T>::at(i); }
const T& operator[](int i) const // range check const objects; §4.2.1
{ return vector<T>::at(i); }
};
Vec inherits everything from vector except for the subscript operations that it redefines to do range
checking. The at() operation is a vector subscript operation that throws an exception of type
out_of_rang e if its argument is out of the vector’s range (§3.5.1).
For Vec, an out-of-range access will throw an exception that the user can catch. For example:
void checked(Vec<Entr y>& book)
{
try {
book[book.size()] = {"Joe",999999}; // will throw an exception
// ...
}
catch (out_of_rang e&) {
cerr << "range error\n";
}
}
The exception will be thrown, and then caught (§3.5.1). If the user doesn’t catch an exception, the
program will terminate in a well-defined manner rather than proceeding or failing in an undefined
manner. One way to minimize surprises from uncaught exceptions is to use a main() with a tr yblock as its body. For example:
int main()
try {
// your code
}
catch (out_of_rang e&) {
cerr << "range error\n";
}
catch (...) {
cerr << "unknown exception thrown\n";
}
This provides default exception handlers so that if we fail to catch some exception, an error message is printed on the standard error-diagnostic output stream cerr (§10.2).142 Containers Chapter 11
Why doesn’t the standard guarantee range checking? Many performance-critical applications
use vectors and checking all subscripting implies a cost on the order of 10%. Obviously, that cost
can vary dramatically depending on hardware, optimizers, and an application’s use of subscripting.
However, experience shows that such overhead can lead people to prefer the far more unsafe builtin arrays. Even the mere fear of such overhead can lead to disuse. At least vector is easily range
checked at debug time and we can build checked versions on top of the unchecked default. Some
implementations save you the bother of defining Vec (or equivalent) by providing a range-checked
version of vector (e.g., as a compiler option).
A range-for avoids range errors at no cost by accessing elements through iterators in the range
[begin():end()). As long as their iterator arguments are valid, the standard-library algorithms do the
same to ensure the absence of range errors.
If you can use vector::at() directly in your code, you don’t need my Vec workaround. Furthermore, some standard libraries have range-checked vector implementations that offer more complete
checking than Vec.

vector
The std::vector available in the STL’s <vector> header is a sequential container that holds a dynamically sized, contiguous series of elements. A
vector manages its storage dynamically, requiring no outside help from
the programmer.
The vector is the workhorse of the sequential ­data­ structure stable. For
a very modest overhead, you gain substantial flexibility over the array. Plus,
vector supports almost all of the same operations as an array and adds a
slew of others. If you have a fixed number of elements on hand, you should
strongly consider an array because you’ll get some small reductions in overhead versus a vector. In all other situations, your go-­to sequential container
is the vector.

A vector container stores and manages its objects in a contiguous dynamic array. Because an array is a random access data structure, the elements of a vector can be accessed randomly in constant time.
Storage is managed automatically so that on an attempt to insert an element
into a full vector, a larger memory block is allocated for the vector, the vector elements are copied to the new block, and the old block is released. A vector is thus a flexible array; that is, an array whose size can be dynamically changed.
Item insertion in the middle or beginning of an array is time consuming, especially if the array is large. However, inserting an item at the end is quite fast.


The name of the header file containing the class vector is vector. Thus, to use a vector container include the following statement:
#include <vector>

## Constructing
The class template std::vector<T, Allocator> takes two template parameters:
  The contained type T
  The optional allocator type Allocator, which defaults to std::allocator<T>.

You have much more flexibility in constructing vectors than you do
with arrays. A vector supports user­ defined allocators because vectors need
to allocate dynamic memory.

You can default construct a vector so it contains no elements:
std::vector<T> vec;

You might want to construct an empty vector so you can fill it with a variable number of elements depending on what happens at runtime.

You can use braced initialization with a vector. Similar to how you
brace initialize an array, this fills the vector with the specified elements:
std::vector<int> vec{ 1, 1, 2, 3, 5 };

If you want to populate a vector with many identical values, you can use one of the fill constructors. To fill construct a vector, you first pass a size_t corresponding to the number of elements you want to fill:
std::vector<int> five_nines(5, 9);

Optionally, you can pass a const reference to an object to copy.

Sometimes you want to initialize all your elements to the same value, for example, to keep track of counts related to particular indices. You might also have a vector of some user­ defined type that keeps track of program state, and you might need to keep track of such state by index.


You can also construct vectors from a half­-open range by passing in the
begin and end iterators of the range you want to copy. In various programming
contexts, you might want to splice out a subset of some range and copy it into
a vector for further processing:
std::array<int, 5> fib_arr{ 1, 1, 2, 3, 5 };
std::vector<int> fib_vec(fib_arr.begin(), fib_arr.end());

DECLARING VECTOR OBJECTS

| Constructor | Effects |
|-------------|---------|
| vector<T> vec; | Creates the empty vector container vec. (default constructor) |
| vector<T> vec(othervec); | Creates the vector container vec and initializes vec to the elements of the vector othervec. vec and other vec are of the same type. |
| vector<T> vec(size); | Creates the vector container vec of size size. vec is initialized using the default constructor. |
| vector<T> vec(n, elm); | Creates the vector container vec of size n. vec is initialized using n copies of the element elm. |
| vector<T> vec(beg, end); | Creates the vector container vec. vec is initialized to the elements in the range [beg, end), that is, all the elements in the range beg. . .end-1. Both beg and end are pointers, called iterators in STL terminology. |
| vector<T>(move(othervec)) | Takes ownership of memory, elements in othervec. No allocations. |
| ~vector | Destructs all elements contained by the vector and releases
dynamic memory. |


Move and Copy Semantics
With vectors, you have full copy/move construction/assignment support. Any vector copy operation is potentially very expensive, because these are element­wise or deep copies. Move operations, on the other hand, are usually very fast, because the contained elements reside in dynamic memory and the moved­from vector can simply pass ownership to the moved­ into vector; there’s no need to move the contained elements.


Element Access
A vector supports most of the same element access operations as array:
at, operator[], front, back, and data.


Now that we know how to declare a vector sequence container, let us discuss how to manipulate the data stored in a vector container. In order to manipulate the data in a vector container, we must know the following basic operations:






You can construct new elements in place using the emplace and emplace_back methods.
The emplace method is a variadic template that, like insert, accepts an iterator as its first argument. The remaining arguments get forwarded to the appropriate constructor.

The emplace_back method is also a variadic template, but like push_back, it doesn’t require an iterator. It accepts any number of arguments and forwards those to the appropriate constructor.

#include <utility>
TEST_CASE("std::vector emplace methods forward arguments") {
  std::vector<std::pair<int, int>> factors;
  factors.emplace_back(2, 30);
  factors.emplace(factors.begin(), 1, 60);
  REQUIRE(factors[0].first == 1);
  REQUIRE(factors[0].second == 60);
}

Here, you default construct a vector containing pairs of ints. Using
the emplace_back method, you push a pair onto the vector. These values get forwarded directly to the constructor of pair, which gets constructed in place. Next, you use emplace to insert a new pair at the beginning of the vector by passing the result of factors.begin() as the first argument. This causes all the elements in the vector to shift down to make room for the new pair (1, 60).

N O T E
There’s absolutely nothing special about a std::vector<std::pair<int, int>>. It’s just like any other vector. The individual elements in this sequential container just happen to be a pair. Because pair has a constructor that accepts two arguments, one for first and one for second, emplace_back can add a new element by simply passing the two values it should write into the newly created pair.

Because the emplacement methods can construct elements in place, it seems they should be more efficient than the insertion methods. This intuition is often correct, but for complicated and unsatisfying reasons it’s not always faster. As a general rule, use the emplacement methods. If you determine a performance bottleneck, also try the insertion methods.

See Item 42 of Effective Modern C++ by Scott Meyers for a treatise.




## Storage Model
Although vector elements are contiguous in memory, like an array, the similarities stop there. A vector has dynamic size, so it must be able to
resize. The allocator of a vector manages the dynamic memory underpinning the vector.

Because allocations are expensive, a vector will request more memory than it needs to contain the current number of elements. Once it can no longer add any more elements, it will request additional memory. The memory for a vector is always contiguous, so if there isn’t enough space at
the end of the existing vector, it will allocate a whole new region of memory
and move all the elements of the vector into the new region. The number of
elements a vector holds is called its size, and the number of elements it could
theoretically hold before having to resize is called its capacity. Figure 13­2
illustrates a vector containing three elements with additional capacity for
three more.

The vector continues past the last element. The capacity determines how many elements the vector could hold in this space.

The upshot of this design is that inserting at the end of a vector is
extremely fast (unless the vector needs to resize). Inserting anywhere else
incurs additional cost, because the vector needs to move elements around
to make room.

You can obtain the vector’s current capacity via the capacity method, and you can obtain the absolute maximum capacity that a vector could resize to with the max_size method.

If you know ahead of time that you’ll need a certain capacity, you can
use the reserve method, which takes a single size_t argument corresponding to the number of elements you want capacity for. On the other hand, if you’ve just removed several elements and want to return memory to the allocator, you can use the shrink_to_fit method, which declares that you have excess capacity. The allocator can decide to reduce capacity or not (it’s a non­binding call).

Additionally, you can delete all the elements in a vector and set its size
to zero using the clear method.

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
| vec.end() | Returns an iterator pointing to 1 past the last element. |
| vec.cend() | Returns a const iterator pointing to 1 past the last element. |
| v1 = v2 | v1 destructs its elements; copies each v2 element. Only allocates if it needs to resize to fit v2’s elements. |
| v1 = move(v2) | v1 destructs its elements; moves each v2 element. Only allocates if it needs to resize to fit v2’s elements. |
|vec.at(index) | Returns the element at the position specified by index. |
| vec[index] | Returns the element at the position specified by index. |
| vec.front() | Returns the first element. (Does not check whether the container is empty.) |
| vec.back() | Returns the last element. (Does not check whether the container is empty.) |
| vec.data() | Returns a raw pointer to the first element if array is non-empty. For empty arrays, returns a valid but non-dereferencable pointer. |
| vec.assign({ ... }) | Replaces the contents of v with the elements .... |
| vec.assign(s, t) | Replaces the contents of v with s number of copies of t. |
| vecCont.capacity() | Returns the maximum number of elements that can be inserted into the container vecCont without reallocation. |
| vecCont.empty() | Returns true if the container vecCont is empty, false otherwise. |
| vecCont.size() | Returns the number of elements currently in the container vecCont. |
| vecCont.max_size() | Returns the maximum number of elements that can be inserted into the container vecCont. |
| vec.clear(); | Deletes all of the elements from the container. |
| vec.assign(initialization list); | Replaces container elements. |
| vec.erase(position); | Deletes the element at the position specified by position iterator. |
| vec.erase(beg, end); | Deletes all of the elements starting at beg until end-1. |
| vec.insert(position, elem); | A copy of elem is inserted at the position specified by position iterator. The position of the new element is returned. |
| vec.insert(position, n, elem) | n copies of elem are inserted at the position specified by position iterator. |
| vec.insert(position, beg, end); | A copy of the elements, starting at beg until end-1, is inserted into vec at the position specified by position iterator. |
| vec.push_back(elem); | A copy of elem is inserted into vec at the end. |
| vec.pop_back(); | Deletes the last element.
| vec.resize(num); | Changes the number of elements to num. If size increases, the default constructor creates the new elements. |
| vec.resize(num, elem); | Changes the number of elements to num. If size increases, the new elements are copies of elem. |
| vec.shrink_to_fit() | Might reduce the vector’s storage so capacity() equals size(). |
| v.reserve(s) | Increases the vector’s storage so it can contain at least s elements. |
| v1.swap(v2) | Exchanges each element of v1 with those of v2. |
| swap(v1, v2) | Exchanges each element of v1 with those of v2. |
| v1 == v2 | True if all elements are equal. |
| v1 != v2 | True if at least one element is equal. |
| v1 > v2 | Greater than comparisons proceed from first element to last.
| v1 >= v2 |
| v1 < v2 | Less than comparisons proceed from first element to last. |
| v1 <= v2 |

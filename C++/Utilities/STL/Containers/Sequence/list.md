A list is a sequence container with fast insert/remove operations everywhere
but with no random element access.

insertion and deletion in the middle of the data structures are very inefficient operations for contiguous data structures. And that's where linked-list-like structures come into the picture.

List containers are implemented as doubly linked lists. Thus, every element in a list points to both its immediate predecessor and its immediate successor (except the first and last elements).

As a result of a lack of random access, you cannot use operator[] or at to access arbitrary elements in a list, because such operations would be very inefficient.

The trade­off is that inserting and removing elements in a list is much faster.

The STL implementation std::list is available from the <list> header. To use list in a program, the program must include the following statement:

	#include <list>


List Constructor

std::list<T> listName;      //default

| Constructor | Description |
|-------------|-------------|
| list<elementType> list | Creates the empty list container (default constructor) |
| list<elementType> list(otherList) | Creates the list container list and initializes it to the elements of otherList. |
| list<elementType> list(size) | Creates the list container list of size size. list is initialized using the default constructor.|
| list<elementType> list(n, elm) | Creates the list container list of size n. list is initialized using n copies of the element elm. |
| list<elementType> list(beg, end) | Creates the list container list. list is initialized to the elements in the range of iterators [beg, end) |




All the vector methods not implemented by list, along with an explanation for their absence, are as follows:

capacity, reserve, shrink_to_fit Because list acquires memory incrementally, it doesn’t require periodic resizing.
operator[], at Random element access is prohibitively expensive on lists.
data Unneeded because list elements are not contiguous.

You can perform special operations on lists, such as splicing elements
from one list into another using the splice method, removing consecutive
duplicate elements using the unique method, and even sorting the elements
of a container using the sort method. Consider, for example, the remove_if
method. The remove_if method accepts a function object as a parameter,
and it traverses the list while invoking the function object on each element.
If the result is true, remove_if removes the element.

## Elements Access
| Expression  | Description |
|-------------|-------------|
list.front() | Returns the first element. (Undefined behavior for empty list)
list.back() | Returns the last element. (Undefined behavior for empty list)


## Capacity Methods
| Expression  | Description |
|-------------|-------------|
| list.size() | Returns the number of elements currently in the container |
| list.max_size() | Returns maximum potential size the container can reach due to known system or library implementation limitations |
| list.empty() | Returns true if the container list is empty, false otherwise. |



##List Modification Methods
The list::insert() member function is available in three forms:

iterator insert(iterator pos, const T& x)

Here the insert function accepts the position of insertion as the first parameter and the value to insert as the second. This function returns an iterator pointing to the recently inserted element in the list.

void insert(iterator pos, size_type n, const T& x)
This function accepts the position of insertion as the first parameter, the value to insert as the last parameter, and the number of elements in variable n.

template <class InputIterator>
void insert(iterator pos, InputIterator f, InputIterator l)

This overloaded variant is a template function that accepts, in addition to the position, two input iterators that mark the bounds of the collection to insert into the list. Note that the input type InputIterator is a template parameterized type and therefore can point to the bounds of any collection—be it an array, a vector, or just another list.

The list member function erase() comes in two overloaded forms:
one that erases one element given an iterator that points to it
one that accepts a range and therefore erases a range of elements

| Expression  | Description |
|-------------|-------------|
| list.assign(n, elem) | Assigns n copies of elem. |
list.assign(beg, end) | Assigns elements in the iterator range beg...end−1. |

list.emplace_front(...) | Constructs an element in place at the list front by forwarding all arguments to the appropriate constructor.
| list.emplace(iter, (T)(...)) | construct and insert element at position pointed to by iterator an element constructed in place. |
| list.emplace_back((T)(...))| Construct and insert element at the end |

list.push_front(T) | Constructs an element in place at the front of d by copying T.
list.push_back(T) | Constructs an element in place at the back of list by copying T.
list.pop_back() | Removes the element at the back of list.
list.push_front(elem) | Inserts elem at the beginning of list.
list.pop_front() | Removes the first element from list.

| list.insert(position, elem) | A copy of elem is inserted at the position specified by position iterator. The position of the new element is returned. |
| list.insert(position, n, elem) | n copies of elem are inserted at the position specified by position iterator. |
| list.insert(position, beg, end) | A copy of the elements, starting at beg until end-1, is inserted into list at the position specified by position iterator. |
| list.erase(position) | Deletes the element at the position specified by position iterator. |
| list.erase(beg, end) | Deletes all of the elements starting at beg until end-1. |
| list.clear() | Deletes all of the elements from the container. |



## Operations
| Expression  | Description |
|-------------|-------------|
| list.remove(elem) | Removes all of the elements equal to elem. |
| list.remove_if(oper) | Removes all of the elements for which oper is true. |
| list.unique() | Removes consecutive list elements of the same value |
| list.unique(oper) | Removes consecutive list elements for which oper is true. |
| list1.splice(pos, list2) |  All list2 elements are moved to list1 before the position specified by the iterator pos. After this operation, list2 is empty. |
| list1.splice(pos, list2, pos2) | All elements starting at pos2 of list2 are moved to list1 before the position specified by the iterator pos. list1.splice(pos, list2, beg, end) | All list2 elements in range beg...end−1 are moved to list1 before the position specified by the iterator pos. Both beg and end are iterators. |
| list.sort() | list elements are sorted using sort criteria < |
| list.sort(oper) | list elements are sorted using sort criteria specified by oper. |
| list1.merge(list2) | Suppose that the elements of list1 and list2 are sorted. This operation moves all of the elements of list2 into list1. After this operation, the elements in list1 are sorted. Moreover, after this operation, list2 is empty.   |
| list1.merge(list2, oper) | Suppose that the elements of list1 and list2 are sorted according to the sort criteria oper. This operation moves all of the elements of list2 into list1. After this operation, the elements in list1 are sorted according to the sort criteria oper. |
| list.reverse() | The elements of list are reversed |



Sorting and Removing Elements from a list That Contains Instances of a class

What if you had a list of a class type, and not a simple built-in type such as int? Say a list of address book entries where each entry is a class that contains name, address, and so on. How would you ensure that this list is sorted on name?

The answer is one of the following:
Implement operator < within the class type that the list contains.
Supply a sort binary predicate — a function that takes two values as input and returns a Boolean value indicating whether the first value is smaller than the second.

Most practical applications involving STL containers rarely collect integers; instead, they collect user-defined types such as classes or structs.


## List Iterator

To declare an iterator that points to an element in the list, you would use
std::list<int>::const_iterator elementInList;


If you need an iterator that can be used to modify values or invoke non-const functions, you use iterator instead of const_iterator.


| Expression | Description|
|------------|------------|
| list.begin() | Returns an iterator pointing to the first element. |
| list.cbegin() | Returns a const iterator pointing to the first element. |
| list.rbegin() | Returns a reverse iterator pointing to the last element. |
| list.crbegin() | Returns a reverse const iterator pointing to the last element. |
| list.end() | Returns an iterator pointing to 1 past the last element. |
| list.cend() | Returns a const iterator pointing to 1 past the last element. |
| list.rend() | Returns a reverse iterator pointing to the first element. |
| list.crend() | Returns a reverse const iterator pointing to the first element. |

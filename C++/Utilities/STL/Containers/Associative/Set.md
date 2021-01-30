Sets

std::set is an associative container that contains sorted, unique elements called keys.

Because set stores sorted elements, you can insert, remove, and search efficiently. In addition, set supports sorted iteration over its elements, and you have complete control over how keys sort using comparator objects.

The std::set available in the STL’s <set> header:

	#include <set>


Constructing
The class template set<T, Comparator, Allocator> takes three parameters:
•	 T, The key type
•	 C, The comparator type that defaults to std::less
•	 A, The allocator type that defaults to std::allocator<T>

You have a lot of flexibility when constructing sets. Each of the following constructors accepts an optional comparator and allocator (whose types must match their corresponding template parameters):

A default constructor that initializes an empty set
	set<T, C, A> s1;

Move and copy constructors with the usual behavior
	auto s2(s1);
	auto s1_moved(std::move(s1));

A range constructor that copies the elements from the range into the set

	std::array<int, 5> a{ 1, 1, 2, 3, 5 };
	std::set<int> a_set(a.cbegin(), a.cend());

A braced initializer
	set<T, C, A> set { element-list };

~set
Destructs all elements contained by the set and releases dynamic memory.


### Move and Copy Semantics
In addition to move/copy constructors, move/copy assignment operators are also available. As with other container copy operations, set copies are potentially very slow because each element needs to get copied, and move operations are usually fast because elements reside in dynamic memory. A set can simply pass ownership without disturbing the elements.

set<T>(s)
Deep copy of s; allocates new memory.

s1 = s2
s1 destructs its elements; copies each s2 element. Only allocates if it needs to resize to fit s2’s elements.

The ‘=’ is an operator in C++ STL which copies (or moves) a set to another set and set::operator= is the corresponding operator function.

s1 = move(s2)
s1 destructs its elements; moves each s2 element. Only allocates if it needs to resize to fit s2’s elements.



### Element Access
You have several options for extracting elements from a set.

The basic method is find, which takes a const reference to a key and returns an iterator. If the set contains an element ­matching key, find will return an iterator pointing to the found element. If the set does not, it will return an iterator pointing to end.

The lower_bound method returns an iterator to the first element not less than the key argument

The upper_bound method returns the first element greater than the given key.

The set class supports two additional lookup methods, mainly for compatibility of non­unique associative containers:

The count method returns the number of elements matching the key. Because set elements are unique, count returns either 0 or 1.

The equal_range method returns a half­open range containing all the elements matching the given key. The range returns a std::pair of iterators with first pointing to the matching element and second pointing to the element after first. If equal_range finds no matching element, first and second both point to the first element greater than the given key. In other words, the pair returned by equal_range is equivalent to a pair of lower_bound as first and upper_bound as second.

| Operation | Note |
|-----------|------|
| find(const g) | Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end. |
| count(const g) | Returns 1 or 0 based on the element ‘g’ is present in the set or not. |
| lower_bound(const g) | Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set. |
| upper_bound(const g) | Returns an iterator to the first element that will go after the element ‘g’ in the set. |
| equal_range() | The function returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k. |





### Adding Elements

You have three options when adding elements to a set:
•	 insert to copy an existing element into the set
•	 emplace to in-­place construct a new element into the set
•	 emplace_hint to in­-place construct a new element, just like emplace (because
adding an element requires sorting).

The difference is the emplace_hint method takes an iterator as its first argument. This iterator is the search’s starting point (a hint). If the iterator is close to the correct position for the newly inserted element, this can provide a substantial speedup.

If you attempt to insert, emplace, or emplace_hint a key that’s already present in the set, the operation has no effect. All three of these methods return a std::pair<Iterator, bool> where the second element indicates whether the operation resulted in insertion (true) or not (false). The iterator at first points to either the newly inserted element or the existing element that prevented insertion.

| Operation | Note |
|-----------|------|
| insert(const g) | Adds a new element ‘g’ to the set. |
| insert (iterator position, const g) | Adds a new element ‘g’ at the position pointed by iterator. |
| emplace() | This function is used to insert a new element into the set container, only if the element to be inserted is unique and does not already exists in the set. |
| emplace_hint() | Returns an iterator pointing to the position where the insertion is done. If the element passed in the parameter already exists, then it returns an iterator pointing to the position where the existing element is. |
| swap() | This function is used to exchange the contents of two sets but the sets must be of same type, although sizes may differ. |






### Removing Elements
You can remove elements from a set using
	erase, which is overloaded to accept a key, an iterator, or a half­open range.
	clear, which removes all elements

| Operation | Note |
|-----------|------|
| erase(iterator position) | Removes the element at the position pointed by the iterator. |
| erase(const g) | Removes the value ‘g’ from the set. |
| erase(iterator first, iterator last) | removes values in range [first, last) |
| clear() | Removes all the elements from the set. |





### Storage Model

Set operations are fast because sets are typically implemented as red-black search trees.

For more information regarding red-black trees, see:
[Data Structures\CommonStructures\Trees\RedBlack.md]

This way, you can perform searches much quicker than with linear iteration, as long as a tree’s branches are roughly balanced (equal in length).





Operation Notes





s.extract(t)
s.extract(itr)
Obtains a node handle that owns the element matching t or pointed to by itr. (This is the only way to remove a move-only element.)

s1.merge(s2)
s1.merge(move(s2))
Splices each element of s2 into s1. If argument is an rvalue, will move the elements into s1.

s1.swap(s2)
swap(s1, s2)
Exchanges each element of s1 with those of s2.



### Observers

| Operation | Note |
|-----------|------|
| key_comp() / value_comp() | Returns the object that determines how the elements in the set are ordered (‘<‘ by default). |

### Allocator

| Operation | Note |
|-----------|------|
| get_allocator() | Returns the copy of the allocator object associated with the set. |




### Capacity

| Operation | Note |
|-----------|------|
| size() | Returns the number of elements in the set. |
| max_size() | Returns the maximum number of elements that the set can hold. |
| empty() | Returns whether the set is empty. |



### Iteration

| Operation | Note |
|-----------|------|
| begin() | Returns an iterator to the first element in the set. |
| end() | Returns an iterator to the theoretical element that follows last element in the set. |
| rbegin() | Returns a reverse iterator pointing to the last element in the container. |
| rend() | Returns a reverse iterator pointing to the theoretical element right before the first element in the set container. |
| crbegin() | Returns a constant iterator pointing to the last element in the container. |
| crend() | Returns a constant iterator pointing to the position just before the first element in the container. |
| cbegin() | Returns a constant iterator pointing to the first element in the container. |
| cend() | Returns a constant iterator pointing to the position past the last element in the container. |

An iterator is an object used to reference an element stored in a container. Thus, it is
a generalization of the pointer. An iterator allows for accessing information included
in a container so that desired operations can be performed on these elements.
As a generalization of pointers, iterators retain the same dereferencing notation. For
example, *i is an element referenced by iterator i. Also, iterator arithmetic is similar to
pointer arithmetic, although all operations on iterators are not allowed in all containers.
No iterators are supported for the stack, queue, and priority_queue containers. Iterator operations for classes list, map, multimap, set, and multiset
are as follows (i1 and i2 are iterators, n is a number):
	 i1++, ++i1, i1--, --i1
	 i1 = i2
	 i1 == i2, i1 != i2
	 *i1
In addition to these operations, iterator operations for classes deque and
vector are as follows:
	 i1 < i2, i1 <= i2, i1 > i2, i1 >= i2
	 i1 + n, i1 - n
	 i1 += n, i1 -= n
	 i1[n]


The iterators provide a unified interface across all of the dynamically iterable STL containers.

For all functions in C++ that specify a range with the help of iterators, the start() iterator is usually inclusive, and the end() iterator is usually exclusive, unless specified otherwise.


Apart from iterating, all the functions for which we need to specify a position inside the container are based on iterators; for example, insertion at a specific position, deletion
of elements in a range or at a specific position, and other similar functions. This makes the code more reusable, maintainable, and readable.

The container.begin() function returns an iterator that points to the first element,
The container.end() function returns an iterator just after the last element.

The container.data() function returns a pointer to the actual buffer stored inside the object. Allows pointer arithmetic and similar operations. Helpful when dealing with old/legacy code that only accepts a raw pointer as a function parameter.

const_iterator is a const version of the normal iterator. If
the container is declared to be a const, its functions that are related to iterators, such as begin() and end(), return const_iterator.

reverse_iterator allows us to traverse the array in the reverse direction. So, its functions, such as the increment operator (++) and advance, are inverses of such operations for normal iterators.

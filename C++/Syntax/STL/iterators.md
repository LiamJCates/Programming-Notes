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

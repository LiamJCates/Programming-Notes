The interface between containers and algorithms is the iterator.

An iterator is a type that knows the internal structure of a container and exposes simple, pointer­like operations to a container’s elements.

An iterator is an object used to reference an element stored in a container. Thus, it is a generalization of the pointer.

An iterator allows for accessing information included in a container so that desired operations can be performed on these elements.

As a generalization of pointers, iterators retain the same dereferencing notation. For example, *i is an element referenced by iterator i. Also, iterator arithmetic is similar to pointer arithmetic, although all operations on iterators are not allowed in all containers.





Iterators come in various flavors, but they all support at least the following operations:
1. Get the current element (operator*)
2. Go to the next element (operator++)
3. Assign an iterator equal to another iterator (operator=)






For all functions in C++ that specify a range with the help of iterators, the start() iterator is usually inclusive, and the end() iterator is usually exclusive, unless specified otherwise.


Apart from iterating, all the functions for which we need to specify a position inside the container are based on iterators; for example, insertion at a specific position, deletion
of elements in a range or at a specific position, and other similar functions. This makes the code more reusable, maintainable, and readable.

The container.begin() function returns an iterator that points to the first element,
The container.end() function returns an iterator just after the last element.

The container.data() function returns a pointer to the actual buffer stored inside the object. Allows pointer arithmetic and similar operations. Helpful when dealing with old/legacy code that only accepts a raw pointer as a function parameter.

const_iterator is a const version of the normal iterator. If
the container is declared to be a const, its functions that are related to iterators, such as begin() and end(), return const_iterator.

reverse_iterator allows us to traverse the array in the reverse direction. So, its functions, such as the increment operator (++) and advance, are inverses of such operations for normal iterators.







You can extract iterators from all STL containers using their begin and end methods.

The begin method returns an iterator pointing to the first element
The end method returns a pointer to one element past the last element.


end() points after the last element, is called a half-open range. It might seem counterintuitive at first — why not have a closed range where end() points to the last element — but a halfopen range has some advantages.

For example, if a container is empty, begin() will return the same value as end(). This allows you to know that, regardless of whether the container is empty, if the iterator equals end(), you’ve traversed the container.

Listing 13­5 illustrates what happens with half­open range iterators and
empty containers.

TEST_CASE("std::array begin/end form a half-open range") {
	std::array<int, 0> e{};
	REQUIRE(e.begin() == e.end());
}

Here, you construct an empty array e, and the begin and end iterators are equal.

Examine how to use iterators to perform pointer­like operations over a non­empty array.

TEST_CASE("std::array iterators are pointer-like") {
	std::array<int, 3> easy_as{ 1, 2, 3 };
	auto iter = easy_as.begin();
	REQUIRE(*iter == 1);
	++iter;
	REQUIRE(*iter == 2);
	++iter;
	REQUIRE(*iter == 3);
	++iter;
	REQUIRE(iter == easy_as.end());
}

The array easy_as contains the elements 1, 2, and 3.
You invoke begin on easy_as to obtain an iterator iter pointing to the first element.
The dereference operator yields the first element 1, because this is the first element in the array w.
Next, you increment iter so it points to the next element.
You continue in this fashion until you reach the last element.

Incrementing the pointer one last time puts you 1 past the last element, so iter equals easy_as.end(), indicating that you’ve traversed the array.

Recall from “Range Expressions” on page 235 that you can build your own types for use in range expressions by exposing a begin and an end method.

Well, containers already do all this work for you, meaning you can use any
STL container as a range expression:

TEST_CASE("std::array can be used as a range expression") {
	std::array<int, 5> fib{ 1, 1, 2, 3, 5 };
	int sum{};
	for (const auto element : fib)
	sum += element;
	REQUIRE(sum == 12);
}

You initialize an array and a sum variable. Because array is a valid
range, you can use it in a ranged­based for loop. This enables you to
accumulate the sum of each element.





















No iterators are supported for the stack, queue, and priority_queue containers.

Iterator operations for classes list, map, multimap, set, and multiset are as follows (i1 and i2 are iterators, n is a number):
	 i1++, ++i1, i1--, --i1
	 i1 = i2
	 i1 == i2, i1 != i2
	 *i1

In addition to these operations, iterator operations for classes deque and vector are as follows:
	 i1 < i2, i1 <= i2, i1 > i2, i1 >= i2
	 i1 + n, i1 - n
	 i1 += n, i1 -= n
	 i1[n]

The iterators provide a unified interface across all of the dynamically iterable STL containers.

The interface between containers and algorithms is the iterator.

The simplest example of an iterator is a pointer. Given a pointer to the first element in an
array, you can increment it and point to the next element or, in many cases, manipulate
the element at that location.
Iterators in STL are template classes that in some ways are a generalization of pointers.
These are template classes that give the programmer a handle by which he can work with
and manipulate STL containers and perform operations on them. Note that operations
could as well be STL algorithms that are template functions, Iterators are the bridge that
allows these template functions to work with containers, which are template classes, in a
consistent and seamless manner.

Iterators supplied by STL can be broadly classified into the following:
	Input iterator — One that can be dereferenced to reference an object. The object can be in a collection, for instance. Input iterators of the purest kinds guarantee read access only.

	Output iterator — One that allows the programmer to write to the collection. Output iterators of the strictest types guarantee write access only.

The basic iterator types mentioned in the preceding list are further refined into the following:
	Forward iterator — A refinement of the input and output iterators allowing both input and output. Forward iterators may be constant, allowing for read-only access to the object the iterator points to, and otherwise allow for both read and write operations, making it mutable. A forward iterator would typically find use in a singly linked list.

	Bidirectional iterator — A refinement of the forward iterator in that it can be decremented to move backward as well. A bidirectional iterator would typically find use in a doubly linked list.

	Random access iterators — In general, a refinement over the concept of bidirectional iterators that allow addition and subtraction of offsets or allow one iterator to be subtracted from another to find the relative separation or distance between the two objects in a collection. A random iterator would typically find use in an array

An iterator is a type that knows the internal structure of a container and exposes simple, pointer­like operations to a container’s elements.

An iterator is an object used to reference an element stored in a container. Thus, it is a generalization of the pointer.

An iterator allows for accessing information included in a container so that desired operations can be performed on these elements.

As a generalization of pointers, iterators retain the same dereferencing notation. For example, *i is an element referenced by iterator i. Also, iterator arithmetic is similar to pointer arithmetic, although all operations on iterators are not allowed in all containers.



What are iterators really? Any particular iterator is an object of some type. There are, however,
many different iterator types, because an iterator needs to hold the information necessary for doing
its job for a particular container type. These iterator types can be as different as the containers and
the specialized needs they serve.

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















### CONTAINERS AND THE FUNCTIONS begin AND end
Every container has the member functions begin and end. The function begin
returns the position of the first element in the container; the function end returns the
position of one past the last element in the container. Also, these functions have no
parameters.
After the following statement executes
intVecIter = intList.begin();
the iterator intVecIter points to the first element in the container intList.
The following for loop outputs the elements of intList to the standard output
device.
for (intVecIter = intList.begin(); intVecIter != intList.end();
++intVecIter)
cout << *intVecIter << " ";

Because iterator is a typedef defined inside the class vector, we must use the container name (which is vector), the container element type, and the scope resolution operator to use the typedef iterator.
The expression
++intVecIter
advances the iterator intVecIter to the next element in the container, and the
expression
*intVecIter
returns the element at the current iterator position.


### THE ostream ITERATOR AND THE FUNCTION copy
a special type of iterators called
ostream iterators. These iterators work well with the function copy to copy the
elements of a container to an output device.

One way to output the contents of a container is to use a for loop, the function
begin to initialize the for loop control variable, and the function end to set the limit.
Alternatively, the function copy can be used to output the elements of a container. In
this case, an iterator of type ostream specifies the destination. (ostream iterators are
discussed in detail later in this chapter.) When we create an iterator of type ostream,
we also specify the type of element that the iterator will output.
The following statement illustrates how to create an ostream iterator of type int:
ostream_iterator<int> screen(cout, " ");

This statement creates screen to be an ostream iterator with the element type int.
The iterator screen has two arguments: the object cout and a space. Thus, the iterator screen is initialized using the object cout. When this iterator outputs elements,
they are separated by a space.
The statement
copy(intArray, intArray + 9, screen);
outputs the elements of intArray on the screen. Similarly, the statement
copy(vecList.begin(), vecList.end(), screen);
outputs the elements of the container vecList on the screen.

Of course, we can directly specify an ostream iterator in the function copy the statement
copy(vecList.begin(), vecList.end(),
ostream_iterator<int>(cout, ", "));
outputs the elements of vecList with a comma and space between them.

Initializing vector Objects during Declaration
whlile the following statements can be used to declare intList to be a vector<int> object and store 13, 75, 28, and 35 in intList:

vector<int> intList;
intList.push_back(13);
intList.push_back(75);
intList.push_back(28);
intList.push_back(35);
C++ 11 allows a vector object to be declared and initialized at the same time. For example, the following statement declares inList to be a vector<int> object an stores 13, 75, 28, and 35 in it.

vector<int> intList = {13, 75, 28, 35};
That is, in C++ 11, the five statements used earlier to declare and initialize intList can be replaced by the preceding statement.

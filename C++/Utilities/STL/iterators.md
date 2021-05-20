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

	output iterators move forward only. You can use the increment operator (prefix or postfix), but not decrement.

The basic iterator types mentioned in the preceding list are further refined into the following:
	Forward iterator — A refinement of the input and output iterators allowing both input and output. Forward iterators may be constant, allowing for read-only access to the object the iterator points to, and otherwise allow for both read and write operations, making it mutable. A forward iterator would typically find use in a singly linked list.

	Bidirectional iterator — A refinement of the forward iterator in that it can be decremented to move backward as well. A bidirectional iterator would typically find use in a doubly linked list.

	Random access iterators — In general, a refinement over the concept of bidirectional iterators that allow addition and subtraction of offsets or allow one iterator to be subtracted from another to find the relative separation or distance between the two objects in a collection. A random iterator would typically find use in an array

An iterator is a type that knows the internal structure of a container and exposes simple, pointer­like operations to a container’s elements.

An iterator is an object used to reference an element stored in a container. Thus, it is a generalization of the pointer.

An iterator allows for accessing information included in a container so that desired operations can be performed on these elements.

As a generalization of pointers, iterators retain the same dereferencing notation. For example, *i is an element referenced by iterator i.

Iterator arithmetic is similar to pointer arithmetic, although all operations on iterators are not allowed in all containers.



What are iterators really? Any particular iterator is an object of some type.

There are, however, many different iterator types, because an iterator needs to hold the information necessary for doing its job for a particular container type. These iterator types can be as different as the containers and
the specialized needs they serve.

Iterators come in various flavors, but they all support at least the following operations:
1. Get the current element (operator*)
2. Go to the next element (operator++)
3. Assign an iterator equal to another iterator (operator=)





Ranges come in different flavors, depending on the type of the iterator and the nature of the ranged data.

For all functions in C++ that specify a range with the help of iterators, the start() iterator is usually inclusive, and the end() iterator is usually exclusive, unless specified otherwise.


Apart from iterating, all the functions for which we need to specify a position inside the container are based on iterators; for example, insertion at a specific position, deletion
of elements in a range or at a specific position, and other similar functions. This makes the code more reusable, maintainable, and readable.

The container.begin() function returns an iterator that points to the first element,
The container.end() function returns an iterator just after the last element.

The container.data() function returns a pointer to the actual buffer stored inside the object. Allows pointer arithmetic and similar operations. Helpful when dealing with old/legacy code that only accepts a raw pointer as a function parameter.

const_iterator is a const version of the normal iterator. If
the container is declared to be a const, its functions that are related to iterators, such as begin() and end(), return const_iterator.

reverse_iterator allows us to traverse the array in the reverse direction. So, its functions, such as the increment operator (++) and advance, are inverses of such operations for normal iterators.





A vector is an example of a sized range, that is, a range with a size that the C++ library can determine in
constant time. Suppose a program defines a range of lines of text read from a file; the number of lines cannot
be known beforehand, so such a range could not be a sized range.
The flavor of range also depends on the iterator type. C++ has six different kinds of iterators, but you can
broadly group them into two categories: read and write.
A read iterator refers to a position in a sequence of values that enables reading from the sequence. Most
algorithms require a read iterator with a corresponding sentinel in order to obtain the input data. Some
algorithms are read-only and others can modify the iterated values.
Most algorithms also require a write iterator, more commonly known as an output iterator. Most
algorithms use only the single output iterator instead of an output range. This is because the size of the
output range is not necessarily known until the algorithm has run its course over its input.
If the input range is sized, an algorithm could use that information to set the size of an output range, but
not all output ranges are sized. For example, writing the values of a vector to an output stream has a sized
input but not a sized output. In order to keep algorithms generic, they rarely require a sized range as input
and rarely accept a range as output.
Because a typical algorithm does not and cannot check for overflow of the output iterator, you must
ensure the output sequence has sufficient room to accommodate everything the algorithm will write.
For example, the std::ranges::copy algorithm copies values from an input range to an output iterator.
The function takes two arguments: an input range and output iterator. You must ensure the output has
enough capacity. Call the resize member function to set the size of the output vector

Demonstrating the std::ranges::copy Function
#include <cassert>
import <algorithm>;
import <vector>;
int main()
{
std::vector<int> input{ 10, 20, 30 };
std::vector<int> output{};
output.resize(input.size());
std::ranges::copy(input, output.begin());
// Now output has a complete copy of input.
assert(input == output);
}

























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










Being able to call resize() is fine if the output is a vector, but you can also use an output iterator to
write values to a file or console. Take an output file such as std::cout and construct a std::ostream_
iterator<int>{std::cout} object to turn it into an output iterator that prints int values. (Use import
<iterator> to get declarations of the iterator-related declarations.) Even better, you can pass a string as a
second argument, and the iterator writes that string after every value it writes.

Demonstrating the std::ostream_iterator Class
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main()
{
  std::vector<int> data;
  std::ranges::copy(std::ranges::istream_view<int>(std::cin),
                    std::back_inserter(data));
  std::ranges::sort(data);
  std::ranges::copy(data, std::ostream_iterator<int>{std::cout, "\n"});
}






Just as you can use the ostream_iterator to write a range to the standard output, you can also use the
standard library to read values from the standard input directly into a range.
with a std::ranges::istream_view.

A view is a kind of range that is easy to copy or assign. By naming this type a
view, it tells you that you can assign an istream_view variable without incurring a runtime penalty.

The job is now to use the std::ranges::copy() function to copy a range of int values from std::cin
to the data vector. But here we run into a problem of setting the size of data to match the number of input
values.

The emplace_back() function extends the size of a vector to accommodate the new value, so how do we arrange to call emplace_back() for every element that is read from the istream_view?

The answer is a special kind of output iterator called std::back_inserter. Pass data as the argument to
back_inserter, and every value written to the output iterator is added to the end of data.









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





### Output Iterator

```cpp
//Reversing the Input Order
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main()
{
  std::vector<int> data{};
  std::ranges::copy(std::ranges::istream_view<int>(std::cin),
                    std::back_inserter(data));

  for (auto start{data.begin()}, end{data.end()};
       start != end and start != --end;
       ++start)
  {
      std::iter_swap(start, end);
  }

  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}

```

The start iterator points to the beginning of the data vector, and end initially points to one past the
end. If the vector is empty, the for loop terminates without executing the loop body. Then the loop body
decrements end so that it points to an actual element of the vector.
Notice that the program is careful to compare start != end after each increment and again after
each decrement operation. If the program had only one comparison, it would be possible for start and
end to pass each other. The loop condition would never be true, and the program would exhibit undefined
behavior







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









STL iterators overview
By Alex on September 11th, 2011 | last modified by Alex on December 21st, 2020

An Iterator is an object that can traverse (iterate over) a container class without the user having to know how the container is implemented. With many classes (particularly lists and the associative classes), iterators are the primary way elements of these classes are accessed.

An iterator is best visualized as a pointer to a given element in the container, with a set of overloaded operators to provide a set of well-defined functions:

    Operator* -- Dereferencing the iterator returns the element that the iterator is currently pointing at.
    Operator++ -- Moves the iterator to the next element in the container. Most iterators also provide Operator-- to move to the previous element.
    Operator== and Operator!= -- Basic comparison operators to determine if two iterators point to the same element. To compare the values that two iterators are pointing at, dereference the iterators first, and then use a comparison operator.
    Operator= -- Assign the iterator to a new position (typically the start or end of the container’s elements). To assign the value of the element the iterator is pointing at, dereference the iterator first, then use the assign operator.

Each container includes four basic member functions for use with Operator=:

    begin() returns an iterator representing the beginning of the elements in the container.
    end() returns an iterator representing the element just past the end of the elements.
    cbegin() returns a const (read-only) iterator representing the beginning of the elements in the container.
    cend() returns a const (read-only) iterator representing the element just past the end of the elements.

It might seem weird that end() doesn’t point to the last element in the list, but this is done primarily to make looping easy: iterating over the elements can continue until the iterator reaches end(), and then you know you’re done.

Finally, all containers provide (at least) two types of iterators:

    container::iterator provides a read/write iterator
    container::const_iterator provides a read-only iterator

Lets take a look at some examples of using iterators.

Iterating through a vector

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
18
19

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vect;
    for (int count=0; count < 6; ++count)
        vect.push_back(count);

    std::vector<int>::const_iterator it; // declare a read-only iterator
    it = vect.cbegin(); // assign it to the start of the vector
    while (it != vect.cend()) // while it hasn't reach the end
        {
        std::cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
        }

    std::cout << '\n';
}

This prints the following:

0 1 2 3 4 5

Iterating through a list

Now let’s do the same thing with a list:

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
18
19
20

#include <iostream>
#include <list>

int main()
{

    std::list<int> li;
    for (int count=0; count < 6; ++count)
        li.push_back(count);

    std::list<int>::const_iterator it; // declare an iterator
    it = li.cbegin(); // assign it to the start of the list
    while (it != li.cend()) // while it hasn't reach the end
    {
        std::cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
    }

    std::cout << '\n';
}

This prints:

0 1 2 3 4 5

Note the code is almost identical to the vector case, even though vectors and lists have almost completely different internal implementations!

Iterating through a set

In the following example, we’re going to create a set from 6 numbers and use an iterator to print the values in the set:

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
18
19
20
21
22
23

#include <iostream>
#include <set>

int main()
{
    std::set<int> myset;
    myset.insert(7);
    myset.insert(2);
    myset.insert(-6);
    myset.insert(8);
    myset.insert(1);
    myset.insert(-4);

    std::set<int>::const_iterator it; // declare an iterator
    it = myset.cbegin(); // assign it to the start of the set
    while (it != myset.cend()) // while it hasn't reach the end
    {
        std::cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
    }

    std::cout << '\n';
}

This program produces the following result:

-6 -4 1 2 7 8

Note that although populating the set differs from the way we populate the vector and list, the code used to iterate through the elements of the set was essentially identical.

Iterating through a map

This one is a little trickier. Maps and multimaps take pairs of elements (defined as a std::pair). We use the make_pair() helper function to easily create pairs. std::pair allows access to the elements of the pair via the first and second members. In our map, we use first as the key, and second as the value.

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
18
19
20
21
22
23

#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<int, std::string> mymap;
	mymap.insert(std::make_pair(4, "apple"));
	mymap.insert(std::make_pair(2, "orange"));
	mymap.insert(std::make_pair(1, "banana"));
	mymap.insert(std::make_pair(3, "grapes"));
	mymap.insert(std::make_pair(6, "mango"));
	mymap.insert(std::make_pair(5, "peach"));

	auto it{ mymap.cbegin() }; // declare a const iterator and assign to start of vector
	while (it != mymap.cend()) // while it hasn't reach the end
	{
		std::cout << it->first << "=" << it->second << " "; // print the value of the element it points to
		++it; // and iterate to the next element
	}

	std::cout << '\n';
}

This program produces the result:

1=banana 2=orange 3=grapes 4=apple 5=peach 6=mango

Notice here how easy iterators make it to step through each of the elements of the container. You don’t have to care at all how map stores its data!

Conclusion

Iterators provide an easy way to step through the elements of a container class without having to understand how the container class is implemented. When combined with STL’s algorithms and the member functions of the container classes, iterators become even more powerful. In the next lesson, you’ll see an example of using an iterator to insert elements into a list (which doesn’t provide an overloaded operator[] to access its elements directly).

One point worth noting: Iterators must be implemented on a per-class basis, because the iterator does need to know how a class is implemented. Thus iterators are always tied to specific container classes.

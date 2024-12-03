New programmers typically spend a lot of time writing custom loops to perform relatively simple tasks, such as sorting or counting or searching arrays. These loops can be problematic, both in terms of how easy it is to make an error, and in terms of overall maintainability, as loops can be hard to understand.

Because searching, counting, and sorting are such common operations to do, the C++ standard library comes with a bunch of functions to do these things in just a few lines of code. Additionally, these standard library functions come pre-tested, are efficient, work on a variety of different container types, and many support parallelization (the ability to devote multiple CPU threads to the same task in order to complete it faster).

The functionality provided in the algorithms library generally fall into one of three categories:

    Inspectors -- Used to view (but not modify) data in a container. Examples include searching and counting.
    Mutators -- Used to modify data in a container. Examples include sorting and shuffling.
    Facilitators -- Used to generate a result based on values of the data members. Examples include objects that multiply values, or objects that determine what order pairs of elements should be sorted in.

These algorithms live in the algorithms library.

The STL provides some 70 generic functions, called algorithms, that can be applied to the STL containers and to arrays.

Finding, sorting, reversing, and the like are standard programming requirements that should not require the programmer to reinvent implementation to support.

This is precisely why STL supplies these functions in the form of STL algorithms that work well with containers using iterators to help the programmer with some of the most common requirements.

Some of the most used STL algorithms are

std::find — Helps find a value in a collection

std::find_if — Helps find a value in a collection on the basis of a specific
user-defined predicate

std::reverse — Reverses a collection

std::remove_if — Helps remove an item from a collection on the basis of a
user-defined predicate

std::transform — Helps apply a user-defined transformation function to elements in a container

These algorithms are template functions in the std namespace and require that the standard header <algorithm> be included.


These algorithms are implementing operations that are very frequently used in most programs, such as locating an element in a container, inserting an element into a sequence
of elements, removing an element from a sequence, modifying elements, comparing
elements, finding a value based on a sequence of elements, sorting the sequence of elements, and so on. Almost all STL algorithms use iterators to indicate the range of elements on which they operate. The first iterator references the first element of the range,
and the second iterator references an element after the last element of the range. Therefore, it is assumed that it is always possible to reach the position indicated by the second
iterator by incrementing the first iterator. Here are some examples.
The call
	 random_shuffle(c.begin(), c.end());


randomly reorders all the elements of the container c. The call
	 i3 = find(i1, i2, el);
returns an iterator indicating the position of element el in the range i1 up to, but
not including, i2. The call
	 n = count_if(i1, i2, oddNum);
counts with the algorithm count_if() the elements in the range indicated by iterators i1 and i2 for which a one-argument user-defined Boolean function oddNum()
returns true.
Algorithms are functions that are in addition to the member functions provided
by containers. However, some algorithms are also defined as member functions to
provide better performance.



Order of execution

Note that most of the algorithms in the algorithms library do not guarantee a particular order of execution. For such algorithms, take care to ensure any functions you pass in do not assume a particular ordering, as the order of invocation may not be the same on every compiler.

The following algorithms do guarantee sequential execution: std::for_each, std::copy, std::copy_backward, std::move, and std::move_backward.




STL algorithms overview
By Alex on September 11th, 2011 | last modified by Alex on December 21st, 2020

In addition to container classes and iterators, STL also provides a number of generic algorithms for working with the elements of the container classes. These allow you to do things like search, sort, insert, reorder, remove, and copy elements of the container class.

Note that algorithms are implemented as functions that operate using iterators. This means that each algorithm only needs to be implemented once, and it will generally automatically work for all containers that provides a set of iterators (including your custom container classes). While this is very powerful and can lead to the ability to write complex code very quickly, it’s also got a dark side: some combination of algorithms and container types may not work, may cause infinite loops, or may work but be extremely poor performing. So use these at your risk.

STL provides quite a few algorithms -- we will only touch on some of the more common and easy to use ones here. The rest (and the full details) will be saved for a chapter on STL algorithms.

To use any of the STL algorithms, simply include the algorithm header file.

min_element and max_element

The std::min_element and std::max_element algorithms find the min and max element in a container class. std::iota generates a contiguous series of values.

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

#include <algorithm> // std::min_element and std::max_element
#include <iostream>
#include <list>
#include <numeric> // std::iota

int main()
{
    std::list<int> li(6);
    // Fill li with numbers starting at 0.
    std::iota(li.begin(), li.end(), 0);

    std::cout << *std::min_element(li.begin(), li.end()) << ' '
              << *std::max_element(li.begin(), li.end()) << '\n';

    return 0;
}

Prints:

0 5

find (and list::insert)

In this example, we’ll use the std::find() algorithm to find a value in the list class, and then use the list::insert() function to add a new value into the list at that point.

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

#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>

int main()
{
    std::list<int> li(6);
    std::iota(li.begin(), li.end(), 0);

    // Find the value 3 in the list
    auto it{ find(li.begin(), li.end(), 3) };

    // Insert 8 right before 3.
    li.insert(it, 8);

    for (int i : li) // for loop with iterators
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}

This prints the values

0 1 2 8 3 4 5

When a searching algorithm doesn’t find what it was looking for, it returns the end iterator.
If we didn’t know for sure that 3 is an element of li, we’d have to check if std::find found it before we use the returned iterator for anything else.

1
2
3
4
5
6
7
8

if (it == li.end())
{
  std::cout << "3 was not found\n";
}
else
{
  // ...
}

sort and reverse

In this example, we’ll sort a vector and then reverse it.

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
24
25
26
27
28
29
30

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vect{ 7, -3, 6, 2, -5, 0, 4 };

    // sort the vector
    std::sort(vect.begin(), vect.end());

    for (int i : vect)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    // reverse the vector
    std::reverse(vect.begin(), vect.end());

    for (int i : vect)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}

This produces the result:

-5 -3 0 2 4 6 7
7 6 4 2 0 -3 -5

Alternatively, we could pass a custom comparison function as the third argument to std::sort. There are several comparison functions in the <functional> header which we can use so we don’t have to write our own. We can pass std::greater to std::sort and remove the call to std::reverse. The vector will be sorted from high to low right away.

Note that std::sort() doesn’t work on list container classes -- the list class provides its own sort() member function, which is much more efficient than the generic version would be.

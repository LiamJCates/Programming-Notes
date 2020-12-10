Container Types
A container is a data structure that holds some objects that are usually of the same type. Different types of containers organize the objects within them differently. Although the number of different organizations is theoretically unlimited, only a small number of them have practical significance, and the most frequently used organizations are incorporated in the STL.

The STL includes the following containers: deque, list, map,
multimap, set, multiset, stack, queue, priority_queue, and vector.

The STL containers are classified into the following three categories:
? Sequence containers (also called sequential containers)
? Associative containers
? Container adapters

There are three kinds of containers:
•	 Sequence containers store elements consecutively, as in an array.
•	 Associative containers store sorted elements.
•	 Unordered associative containers store hashed objects.




Associative and unordered associative containers offer rapid search for
individual elements. All containers are RAII wrappers around their contained objects, so they manage the storage durations and lifetimes of the
elements they own. Additionally, each container provides some set of member
functions that perform various operations on the object collection.

Modern C++ programs use containers all the time. Which container
you choose for a particular application depends on the required operations, the contained objects’ characteristics, and efficiencies under particular access patterns.


















Initializing Containers
A container exists to hold elements, so obviously we need convenient ways of getting elements into a container.
Initializer-list constructor: Initialize with a list of elements.
push_back(): Add a new element at the end of (at the back of) the sequence

The std::initializer_list used to define the initializer-list constructor is a standard-library type
known to the compiler: when we use a {}-list, such as {1,2,3,4}, the compiler will create an object of type initializer_list to give to the program.


ContainerClass::ContainerClass(std::initializer_list<double> lst)
:elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
{
  copy(lst.begin(),lst.end(),elem);
}

Unfortunately, the standard-library uses unsigned integers for sizes and subscripts, so I need to use the ugly static_cast to explicitly convert the size of the initializer list to an int. This is pedantic because the chance that the number of elements in a handwritten list is larger than the largest integer (32,767 for 16-bit integers and 2,147,483,647 for 32-bit integers) is rather low. However, the type system has no common sense. It knows about the possible values of variables, rather than actual values, so it might complain where there is no actual violation. Such warnings can occasionally save the programmer from a bad error.

Member Functions Common to All Containers


| Member function | Description |
|-----------------|-------------|
| Default constructor | Initializes the object to an empty state. |
| Constructor with parameters | In addition to the default constructor, every container has constructors with parameters. We will describe these constructors when we discuss a specific container. |
| Copy constructor | Executes when an object is passed as a parameter by value and when an object is declared and initialized using another object of the same type. |
| Destructor | Executes when the object goes out of scope. |
| ct.empty() | Returns true if container ct is empty, false otherwise. |
| ct.size() | Returns the number of elements currently in container ct. |
| ct.max_size() | Returns the maximum number of elements that can be inserted in container ct. |
| ct1.swap(ct2); | Swaps the elements of containers ct1 and ct2. |
| ct.begin() | Returns an iterator to the first element into container ct. |
| ct.end() | Returns an iterator to the position after the last element into container ct. |
| ct.rbegin() | Reverse begin. Returns a pointer to the last element into container ct. This function is used to process the elements of ct in reverse. |
| ct.rend() | Reverse end. Returns a pointer to the position before the first element into container ct.
| ct.insert(position,elem); | Inserts elem into container ct at the position specified by position. Note that here, position is an iterator. |
| ct.erase(beg, end); | Deletes all of the elements between beg...end-1 from container ct. Both beg and end are iterators. |
| ct.clear(); | Deletes all of the elements from the container. After a call to this function, container ct is empty. |

| Operator | Effect |
|----------|--------|
| ct1 = ct2; | Copies the elements of ct2 into ct1. After this operation, the elements in both containers are the same. |
| ct1 == ct2 | Returns true if containers ct1 and ct2 are equal, false otherwise. |
| ct1 != ct2 | Returns true if containers ct1 and ct2 are not equal, false otherwise. |











Comparing containers

All containers overload the operator == for comparing two containers of the same type that have the same element type. You can use == to compare a vector<string> to another vector<string>, but you can't use it to compare a vector<string> to a list<string> or a vector<string> to a vector<char*>.

In C++98/03, you can use std::equal or std::mismatch to compare dissimilar container types and/or element types.

In C++11, you can also use std::is_permutation.

But in all these cases the functions assume the containers are the same length. If the second range is shorter than the first, then undefined behavior results. If the second range is longer, results can still be incorrect because the comparison never continues past the end of the first range.

Comparing dissimilar containers (C++14)

In C++14 and later, you can compare dissimilar containers and/or dissimilar elements types by using one of the std::equal, std::mismatch, or std::is_permutation function overloads that take two complete ranges. These overloads enable you to compare containers with different lengths. These overloads are much less susceptible to user error, and are optimized to return false in constant time when containers of dissimilar lengths are compared. Therefore, we recommend you use these overloads unless you have a clear reason not to, or you're using a std::list container, which does not benefit from the dual-range optimizations.

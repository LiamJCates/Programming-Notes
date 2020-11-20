ANSI/ISO Standard C11 is equipped with a Standard Template Library (STL).
Among other things, the STL provides class templates to process lists (contiguous
or linked), stacks, and queues.

Components of the STL
The main objective of a program is to manipulate data and generate results. Achieving this goal requires the ability to store data into computer memory, access a particular
piece of data, and write algorithms to manipulate the data.
For example, if all data items are of the same type and we have some idea of the number of data items, we could use an array to store the data. We can then use an index to access a particular component of the array. Using a loop and the array index, we can
step through the elements of the array. Algorithms, such as those for initializing the array, sorting, and searching, are used to manipulate the data stored in an array. On the other hand, if we do not want to be concerned about the size of the data, we can use a linked list to process it. If the data needs to be processed in a Last In First Out (LIFO) manner, we can use a stack. Similarly, if the data needs to be processed in a
First In First Out (FIFO) manner, we can use a queue.

The STL is equipped with these features to effectively manipulate data. More formally, the STL has three main components:
? Containers
? Iterators
? Algorithms

Containers and iterators are class templates. Iterators are used to step through the elements of a container. Algorithms are used to manipulate data. The following
sections discuss each of these components in detail.

Container Types
Containers are used to manage objects of a given type. The STL containers are classified into the following three categories:
? Sequence containers (also called sequential containers)
? Associative containers
? Container adapters




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






Sequence Containers
Every object in a sequence container has a specific position. The three predefined sequence containers are as follows:
? vector
? deque
? list


Member Functions Common to Sequence Containers

| Expression | Description |
| seqCont.insert(position, elem); | A copy of elem is inserted at the position specified by the iterator position. The position of the new element is returned. |
| seqCont.insert(position, n, elem); | n copies of elem are inserted at the position specified by the iterator position. |
| seqCont.insert(position, beg, end); |
| A copy of the elements, starting at beg until end-1, is inserted into seqCont at the position specified by the iterator position. Also, beg and end are iterators. |
| seqCont.push_back(elem); | A copy of elem is inserted into seqCont at the end. |
| seqCont.pop_back(); | Deletes the last element. |
| seqCont.erase(position); | Deletes the element at the position specified by the iterator position. |
| seqCont.erase(beg, end); | Deletes all of the elements starting at beg until end-1. Both beg and end are iterators. |
| seqCont.clear(); Deletes all of the elements from the container. |
| seqCont.resize(num); | Changes the number of elements to num. If size grows, the new elements are created by their default constructor. |
| seqCont.resize(num, elem); | Changes the number of elements to num. If size grows, the new elements are copies of elem. |


The copy Algorithm
The STL
provides a convenient way to output the elements of a container with the help of
the function copy. The function copy is provided as a part of the generic algorithm
and can be used with any container type.

The function copy does more than output the elements of a container. In general, it allows us to copy the elements from one place to another.

template <class inputIterator, class outputIterator>
outputIterator copy(inputIterator first1, inputIterator last,
outputIterator first2);

The parameter first1 specifies the position from which to begin copying the elements; the parameter last specifies the end position, elements within the range first1...last-1 are copied

The parameter first2 specifies where to copy the elements. Therefore, the parameters first1 and last specify the source; parameter first2 specifies the destination.

The definition of the function template copy is contained in the header file algorithm.
Thus, to use the function copy, the program must include the statement
#include <algorithm>

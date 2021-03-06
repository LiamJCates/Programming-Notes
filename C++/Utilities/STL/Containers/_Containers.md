Container Types
A class with the main purpose of holding objects is commonly called a container.

Containers are a library feature that they operate in a similar way to built-in arrays, except that they allow being copied (an actually expensive operation that copies the entire block of memory, and thus to use with care) and decay into pointers only when explicitly told to do so (by means of its member data).

Most computing involves creating collections of values and then manipulating such collections. Providing suitable containers for a given task and supporting them with useful fundamental operations are important steps in the construction of any program.

Formally, a container is a data structure that holds some objects that are usually of the same type.

Different types of containers organize the objects within them differently. Although the number of different organizations is theoretically unlimited, only a small number of them have practical significance, and the most frequently used organizations are incorporated in the STL.

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













STL containers overview
By Alex on September 11th, 2011 | last modified by Alex on December 21st, 2020

By far the most commonly used functionality of the STL library are the STL container classes. If you need a quick refresher on container classes, check out lesson 16.6 -- Container classes.

The STL contains many different container classes that can be used in different situations. Generally speaking, the container classes fall into three basic categories: Sequence containers, Associative containers, and Container adapters. We’ll just do a quick overview of the containers here.

Sequence Containers

Sequence containers are container classes that maintain the ordering of elements in the container. A defining characteristic of sequence containers is that you can choose where to insert your element by position. The most common example of a sequence container is the array: if you insert four elements into an array, the elements will be in the exact order you inserted them.

As of C++11, the STL contains 6 sequence containers: std::vector, std::deque, std::array, std::list, std::forward_list, and std::basic_string.

    If you’ve ever taken physics, you probably are thinking of a vector as an entity with both magnitude and direction. The unfortunately named vector class in the STL is a dynamic array capable of growing as needed to contain its elements. The vector class allows random access to its elements via operator[], and inserting and removing elements from the end of the vector is generally fast.

    The following program inserts 6 numbers into a vector and uses the overloaded [] operator to access them in order to print them.

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

    #include <vector>
    #include <iostream>

    int main()
    {

        std::vector<int> vect;
        for (int count=0; count < 6; ++count)
            vect.push_back(10 - count); // insert at end of array

        for (int index=0; index < vect.size(); ++index)
            std::cout << vect[index] << ' ';

        std::cout << '\n';
    }

    This program produces the result:
    10 9 8 7 6 5
    The deque class (pronounced “deck”) is a double-ended queue class, implemented as a dynamic array that can grow from both ends.

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

    #include <iostream>
    #include <deque>

    int main()
    {
        std::deque<int> deq;
        for (int count=0; count < 3; ++count)
        {
            deq.push_back(count); // insert at end of array
            deq.push_front(10 - count); // insert at front of array
        }

        for (int index=0; index < deq.size(); ++index)
            std::cout << deq[index] << ' ';

        std::cout << '\n';
    }

    This program produces the result:

    8 9 10 0 1 2
    A list is a special type of sequence container called a doubly linked list where each element in the container contains pointers that point at the next and previous elements in the list. Lists only provide access to the start and end of the list -- there is no random access provided. If you want to find a value in the middle, you have to start at one end and “walk the list” until you reach the element you want to find. The advantage of lists is that inserting elements into a list is very fast if you already know where you want to insert them. Generally iterators are used to walk through the list.

    We’ll talk more about both linked lists and iterators in future lessons.
    Although the STL string (and wstring) class aren’t generally included as a type of sequence container, they essentially are, as they can be thought of as a vector with data elements of type char (or wchar).

Associative Containers

Associative containers are containers that automatically sort their inputs when those inputs are inserted into the container. By default, associative containers compare elements using operator<.

    A set is a container that stores unique elements, with duplicate elements disallowed. The elements are sorted according to their values.
    A multiset is a set where duplicate elements are allowed.
    A map (also called an associative array) is a set where each element is a pair, called a key/value pair. The key is used for sorting and indexing the data, and must be unique. The value is the actual data.
    A multimap (also called a dictionary) is a map that allows duplicate keys. Real-life dictionaries are multimaps: the key is the word, and the value is the meaning of the word. All the keys are sorted in ascending order, and you can look up the value by key. Some words can have multiple meanings, which is why the dictionary is a multimap rather than a map.

Container Adapters

Container adapters are special predefined containers that are adapted to specific uses. The interesting part about container adapters is that you can choose which sequence container you want them to use.

    A stack is a container where elements operate in a LIFO (Last In, First Out) context, where elements are inserted (pushed) and removed (popped) from the end of the container. Stacks default to using deque as their default sequence container (which seems odd, since vector seems like a more natural fit), but can use vector or list as well.
    A queue is a container where elements operate in a FIFO (First In, First Out) context, where elements are inserted (pushed) to the back of the container and removed (popped) from the front. Queues default to using deque, but can also use list.
    A priority queue is a type of queue where the elements are kept sorted (via operator<). When elements are pushed, the element is sorted in the queue. Removing an element from the front returns the highest priority item in the priority queue.






















| Container | Description |
|-----------|-------------|
| vector<T> | A variable-size vector |
| list<T> | A doubly-linked list |
| forward_list<T> | A singly-linked list |
| deque<T> | A double-ended queue |
| set<T> | A set (a map with just a key and no value) |
| multiset<T> | A set in which a value can occur many times |
| map<K,V> | An associative array |
| multimap<K,V> | A map in which a key can occur many times |
| unordered_map<K,V> | A map using a hashed lookup |
| unordered_multimap<K,V> | A multimap using a hashed lookup |
| unordered_set<T> | A set using a hashed lookup |
| unordered_multiset<T> | A multiset using a hashed lookup |







| Container | Advantages | Disadvantages |
|-----------|------------|---------------|
| std::vector (Sequential Container) | Quick (constant time) insertion at the end.  | Resizing can result in performance loss. Search time is proportional to the number of elements in the container. Constant time insertion only at the end. |
| std::deque  (Sequential Container) | All advantages of the vector.  Additionally, offers constant-time insertion at the beginning of the container too. | Disadvantages of the vector with respect to performance and search are applicable to the deques.  Unlike the vector, the deque by specification does not need to feature the reserve() function that allows the programmer to reserve memory space to be used — a feature that avoids frequent resizing to improve performance. |
| std::list (Sequential Container) | Constant time insertion at the any list location. Removal of elements from a list is a constant-time activity regardless of the position of the element. Insertion or removal of elements does not invalidate iterators that point to other elements in the list. | Elements cannot be accessed randomly by index. Accessing elements can be slower than the vector because elements are not stored in adjacent memory locations. Search time is proportional to the number of elements in the container. |
| std::forward_list (Sequential Container) | Singly linked list class that allows iteration only in one direction. | Allows insertion only at the front of the list via push_front(). |
| std::set (Associative Container) | Search is not directly proportional to the number of elements in the container, rather to the logarithm thereof and hence is often significantly faster than sequential containers. | Insertion of elements is slower than in sequential counterparts, as elements are sorted at
insertion. |
| std::unordered set (Associative Container) | Search, insertion, and removal in this type of container are nearly independent of the number of elements in
the container. | As elements are weakly ordered, one cannot rely on their relative position within the container. |  
| std::multiset (Associative Container) | Should be used when a set needs to contain nonunique values too. |  Insertions may be slower than in a sequential container as elements (pairs) are sorted on insertion. |
| std::unordered_multiset (Associative Container) | Should be preferred over an unordered_set when you need to contain nonunique values too. Performance is similar to unordered_set, namely, constant average time for search, insertion, and removal of elements, independent of size of container. | Elements are weakly ordered, so one cannot rely on their relative position within the container. |
|  std::map (Associative Container) | Key-value pairs container that offers search performance proportional to the logarithm of number of elements in the container and hence often significantly faster than sequential containers. | Elements (pairs) are sorted on insertion, hence insertion will be slower than in a sequential container of pairs. |
| std::unordered_map. (Associative Container) | Offers advantage of near constant time search, insertion, and removal of elements independent of the size of the container. |  Elements are weakly ordered and hence not suited to cases where order is important. |
| std::multimap. (Associative Container) | To be selected over std::map when requirements necessitate the need of a key-value pairs container that holds elements with nonunique keys. | Insertion of elements will be slower than in a sequential equivalent as elements are sorted on insertion. |
| std::unordered_multimap (Associative Container) | To be selected over multimap when you need a keyvalue pairs container where keys can be nonunique. Allows constant average time insertion, search, and removal of elements, independent of the size of the container | Is a weakly ordered container, so you cannot use it when you need to rely on the relative order of elements. |











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








The unordered containers are optimized for lookup with a key (often a string); in other words, they
are implemented using hash tables.
The containers are defined in namespace std and presented in headers <vector>, <list>, <map>,
etc. (§8.3). In addition, the standard library provides container adaptors queue<T>, stack<T>, and
priority_queue<T>. Look them up if you need them. The standard library also provides moreSection 11.6 Container Overview 147
specialized container-like types, such as array<T,N> (§13.4.1) and bitset<N> (§13.4.2).
The standard containers and their basic operations are designed to be similar from a notational
point of view. Furthermore, the meanings of the operations are equivalent for the various containers. Basic operations apply to every kind of container for which they make sense and can be efficiently implemented












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
| ct.capacity() | Returns the number of elements ct can hold without a new allocation |
| ct.capacity() | Returns the number of elements ct can hold without a new allocation |
| ct.reserve(k) | Make the capacity k |
| ct1.swap(ct2); | Swaps the elements of containers ct1 and ct2. |
| ct.begin() | Returns an iterator to the first element into container ct. |
| ct.end() | Returns an iterator to the position after the last element into container ct. |
| ct.rbegin() | Reverse begin. Returns a pointer to the last element into container ct. This function is used to process the elements of ct in reverse. |
| ct.rend() | Reverse end. Returns a pointer to the position before the first element into container ct.
| ct.insert(position,elem); | Inserts elem into container ct at the position specified by position. Note that here, position is an iterator. |
| ct.erase(beg, end); | Deletes all of the elements between beg...end-1 from container ct. Both beg and end are iterators. |
| ct.clear(); | Deletes all of the elements from the container. After a call to this function, container ct is empty. |
| ct.push_back(T); | insert element at the end |
| ct.emplace_back(T); | Construct and insert element at the end |


| Operator | Effect |
|----------|--------|
| ct1 = ct2; | Copies the elements of ct2 into ct1. After this operation, the elements in both containers are the same. |
| ct1 == ct2 | Returns true if containers ct1 and ct2 are equal, false otherwise. |
| ct1 != ct2 | Returns true if containers ct1 and ct2 are not equal, false otherwise. |
x=(c<c2), also <=, >, >= Lexicographical order of c and c2:
x<0 if less than, x==0 if equal, and 0<x if greater than










Comparing containers

All containers overload the operator == for comparing two containers of the same type that have the same element type. You can use == to compare a vector<string> to another vector<string>, but you can't use it to compare a vector<string> to a list<string> or a vector<string> to a vector<char*>.

In C++98/03, you can use std::equal or std::mismatch to compare dissimilar container types and/or element types.

In C++11, you can also use std::is_permutation.

But in all these cases the functions assume the containers are the same length. If the second range is shorter than the first, then undefined behavior results. If the second range is longer, results can still be incorrect because the comparison never continues past the end of the first range.

Comparing dissimilar containers (C++14)

In C++14 and later, you can compare dissimilar containers and/or dissimilar elements types by using one of the std::equal, std::mismatch, or std::is_permutation function overloads that take two complete ranges. These overloads enable you to compare containers with different lengths. These overloads are much less susceptible to user error, and are optimized to return false in constant time when containers of dissimilar lengths are compared. Therefore, we recommend you use these overloads unless you have a clear reason not to, or you're using a std::list container, which does not benefit from the dual-range optimizations.

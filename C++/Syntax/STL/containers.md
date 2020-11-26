Container Types
A container is a data structure that holds some objects that are usually of the same type. Different types of containers organize the objects within them differently. Although the number of different organizations is theoretically unlimited, only a small number of them have practical significance, and the most frequently used organizations are incorporated in the STL.

The STL includes the following containers: deque, list, map,
multimap, set, multiset, stack, queue, priority_queue, and vector.

The STL containers are classified into the following three categories:
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

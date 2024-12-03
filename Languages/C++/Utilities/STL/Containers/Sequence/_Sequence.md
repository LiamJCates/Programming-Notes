Sequence Containers
Sequence containers are STL containers that allow sequential member access.

Every object in a sequence container has a specific position.

That is, you can start from one end of the container and iterate through to
the other end.

Some containers have a fixed length; others can shrink and grow as program needs dictate. Some allow indexing directly into the container, whereas you can only access others sequentially. Additionally, each sequence container has unique performance characteristics that make it desirable in some situations and undesirable in others.

Sequence containers:
array
vector
deque
list


Sequence containers maintain the ordering of inserted elements that you specify.

An array container is random access and contiguously stored and a fixed.

A vector container is random access and contiguously stored. A vector behaves like an array, but can automatically grow as required. For these reasons and more, vector is the preferred sequence container for most applications. When in doubt as to what kind of sequence container to use, start by using a vector.

A deque (double-ended queue) container allows for fast insertions and deletions at the beginning and end of the container. It shares the random-access and flexible-length advantages of vector, but isn't contiguous.

A list container is a doubly linked list that enables bidirectional access, fast insertions, and fast deletions anywhere in the container, but you can't randomly access an element in the container.

A forward_list container is a singly linked list—the forward-access version of list.







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

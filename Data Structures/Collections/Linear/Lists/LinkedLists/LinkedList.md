## LinkedList

A linked list is a recursive data structure implementing the List abstract data type

Linked list data structures are dynamic linear collections of data elements represented by a resizable linked sequence of nodes.

Each node in the collection stores some data of a given type and maintains at least one link to other nodes. Maintaining a link between nodes is accomplished by storing the memory addresses of other nodes in the linked structure. In this way, nodes can be located anywhere in memory, and one way passage between nodes of the linked structure and thus subsequent members of the collection is achieved by following the memory address that represents a given link. Although linked structures can be implemented in a variety of ways, the most flexible implementation is by using pointers.

Linked Lists are often compared to array based data structures

array based structures have at least two limitations:
(1) the size of a static array has to be known at compilation time
(2) array structures are contiguous in computer memory, which means that element insertion and deletion requires shifting subsequent data members.

These limitations can be overcome by using linked structures however they have their own limitations

### Trade Offs

Linked List Advantages
  Dynamic
    Linked lists are dynamic data structures; that is, they can grow or shrink during the execution of the program.
  Collection Memory Efficiency
    Efficient memory utilization. Memory is allocated whenever it is required, and it is de-allocated whenever it is no longer needed so the collection's capacity matches it's size in memory
  Size Alteration
    insertion and deletion operations are similarly efficient from any position in the sequence

Disadvantages of linked lists
  Element Memory Efficiency
    Individual list elements consume more space than array elements as every node requires additional storage for address links
  Sequential Access
    Searching and Accessing a particular element in the list is difficult and time-consuming. Access time is linear (and difficult to pipeline). Faster access, such as random access, is not feasible.
  Slower Traversal
    Unlike an array, sequence order is not given by physical placement in memory but by following references that link to each subsequent node. The flexible memory locations of linked list elements means that they have worse cache locality than contiguous Arrays as, there's no way to bring the next element into the cache without actually visiting it with the pointer stored in the current element. So, although, in theory, it has the same time complexity for traversal as an array, in practice, it gives poorer performance.


### Notation

Linked data structures hold the data in multiple chunks of memory, also known as
nodes, which may be placed at different places in the memory.

Linked list: A list of items, called nodes, in which the order of the nodes is determined by the address, called the link, stored in each node. The last node contains a NULL pointer link to indicate the end of the list.

The address of the first node in the list is stored in a separate location called the head.


### Operations

Insert(k): adds k to the start of the list.
  Insert element at list head. Create a new node, assign it to the head and point link to list head. So that this new element becomes the head element of the list.
  O(1) constant time.

Delete(): delete element at the start of the list
  Delete an element at list. We just need to move one pointer and free the old head node.
  O(1) constant time.

PrintList(): display list elements
  Start with the first element and then follow the pointers to print the value of each list element.
  O(N) time

Find(k): find the position of element with value k
  Linear Search starting with the first element and follow the pointers until we get the value we are looking for or reach the end of the list.
  O(N) time

FindKth(k): find element at position k
  Start from the first element and follow the links until you reach the kth element.
  O(N) time

IsEmpty(): check if the number of elements in the list are zero.  
  Return true if the head pointer is nullptr, indicating an empty list.
  O(1) time

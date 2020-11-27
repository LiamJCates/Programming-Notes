## LinkedList

A linked list is a recursive data structure implementing the List data type
A linked list is a sequential list

The data structure is a dynamic linear collection of data elements represented by a resizable linked sequence of nodes.


An array is a very useful data structure provided in programming languages. However, it has at least two limitations:
(1) its size has to be known at compilation time
(2) the data in the array are separated in computer memory by the same distance, which means that inserting an item inside the array requires shifting other data in this array.

This limitation can be overcome by using linked structures. A linked structure is a collection of nodes storing data and links to other nodes. In this way, nodes can be located anywhere in memory, and passing from one node of the linked structure to another is accomplished by storing the addresses of other nodes in the linked structure. Although linked structures can be implemented
in a variety of ways, the most flexible implementation is by using pointers.

Unlike an array, sequence order is not given by physical placement in memory but by following references that link to each subsequent node.

Each node thus, at minimum, contains a list value and a reference to a location in memory that holds the next node in the sequence.
<br/><br/>

## Singly LinkedList

A Singly LinkedList is the most basic LinkedList implementation

A singly linked list is a collection of components called nodes. Every node in a singly linked list has two components: the list value and the link to its successor or the next list node

In this form, each node contains:
data of a given type consistent with the reset of the list
a reference (in other words, a link) to the next node in the sequence.

The Singly LinkedList structure is minimally defined by the list head, either:
An empty list represented by a single null reference
A reference to the first node in the list


The head is designated by being the only node with nothing linking to it.
The LinkedList data structure may store a reference to the last node as well.
The last node is called the tail and is designated by being the only node that points to a value of null.
A list with a single element has one node that is both the head and the tail of that list.




To implement a singly linked list

We create a Node for each item, setting:
the item field in each of the nodes to the desired value,
the next field to point the subsequent node in the order of the list collection.

We can then dynamically resize the LinkedList through the creation and deletion of nodes and altering the adjacent list member's links

Linked List Advantages
  Linked lists are dynamic data structures; that is, they can grow or shrink
  during the execution of the program.
  Efficient memory utilization. Memory is allocated whenever
  it is required, and it is de-allocated whenever it is no longer needed.
  Efficient insertion or removal of elements from any position in the sequence
  Many complex applications can be easily carried out with linked lists.

Disadvantages of linked lists
  Individual list elements consume more space than array elements because every node requires an additional pointer to store the address of the next node.
  Searching a particular element in the list is difficult and time-consuming.
  Access time is linear (and difficult to pipeline). Faster access, such as random access, is not feasible.
  Arrays have better cache locality compared to linked lists.

Because the links in a singly linked list consist only of next pointers (or references), the list can be traversed only in the forward direction.
Therefore a complete traversal of the list must begin with the first element, the head.
You need a pointer or reference to the first element of a list to locate all the elements in the list. When adding at the end of the list, if a reference to the tail element is maintained, the tail reference can be used to negate the need for traversing the entire list.

More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.
<br/><br/>

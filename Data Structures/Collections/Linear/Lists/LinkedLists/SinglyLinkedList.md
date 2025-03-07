## Singly Linked List

A Singly Linked List is the most basic Linked List implementation

A singly linked list is defined by the minimal structure of it's nodes, only two components.

In this form, each node contains:
	A data member of a given type, the element data
	A memory location of the next node in the sequence, the link.

The Singly Linked List structure is minimally defined by the list head, either:
	An empty list represented by a single null reference
	A reference to the first node in the list


The head is designated by being the only node with nothing linking to it.
The Linked List data structure may store a reference to the last node as well.
The last node is called the tail and is designated by being the only node that points to a value of null.
A list with a single element has one node that is both the head and the tail of that list.




To implement a singly linked list

We create a Node for each item, setting:
the item field in each of the nodes to the desired value,
the next field to point the subsequent node in the order of the list collection.

We can then dynamically resize the Linked List through the creation and deletion of nodes and altering the adjacent list member's links



Because the links in a singly linked list consist only of next pointers (or references), the list can be traversed only in the forward direction.
Therefore a complete traversal of the list must begin with the first element, the head.
You need a pointer or reference to the first element of a list to locate all the elements in the list. When adding at the end of the list, if a reference to the tail element is maintained, the tail reference can be used to negate the need for traversing the entire list.

More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.

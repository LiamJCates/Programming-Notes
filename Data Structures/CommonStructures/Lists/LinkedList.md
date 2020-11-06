## LinkedList

A linked list is a recursive data structure implementing the List data type

The data structure is a linear collection of data elements represented by a linked sequence of nodes.

Unlike an array, sequence order is not given by physical placement in memory but by following references that link to each subsequent node.

Each node thus, at minimum, contains a list value and a reference to a location in memory that holds the next node in the sequence.
<br/><br/>

## Singly LinkedList

A Singly LinkedList is the most basic LinkedList implementation

The Singly LinkedList structure is either
An empty list, a null reference
A reference to the first list node

The LinkedList data structure stores a reference to the first node and potentially the last node as well.
The first node is called the head and is designated by being the only node with nothing linking to it.
The last node is called the tail and is designated by being the only node that points to a value of null.
A list with a single element has one node that is both the head and the tail of that list.


In this form, each node contains:
data of a given type consistent with the reset of the list,
a reference (in other words, a link) to the next node in the sequence.

To implement a singly linked list, we start with a class that defines the node abstraction

Node <T> {
   T item;
   Node next;
}

We create a Node for each item, setting:
the item field in each of the nodes to the desired value,
the next field to point the subsequent node in the order of the list collection.

We can then dynamically resize the LinkedList through the creation and deletion of nodes

An advantage of this linked structure is that it allows for efficient insertion or removal of elements from any position in the sequence.

A drawback of linked lists is that access time is linear (and difficult to pipeline). Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists.

Because the links in a singly linked list consist only of next pointers (or references), the list can be traversed only in the forward direction.
Therefore a complete traversal of the list must begin with the first element, the head.
You need a pointer or reference to the first element of a list to locate all the elements in the list. When adding at the end of the list, if a reference to the tail element is maintained, the tail reference can be used to negate the need for traversing the entire list.

More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.
<br/><br/>

public class Node<T> {
  private T data;
  private Node<T> prev;
  private Node<T> next;

  public Node( T value ) { data = value; }

  public T getValue() { return data; }
  public void setValue( T value ) { data = value; }

  public Node<T> getPrev() { return prev; }
  public void setPrev( Node<T> elem ) { prev = elem; }

  public Node<T> getNext() { return next; }
  public void setNext( Node<T> elem ) { next = elem; }
}


## Doubly Linked List

In a doubly linked list, each element has a link to the previous element in the list as well as to the next element in the list. This additional link makes it possible to traverse the list in either direction. The entire list can be traversed starting from any element. A doubly linked list has head and tail elements just like a singly linked list. The head of the list has an empty or null previous link, just as the tail of the list has a null or empty next link.
<br/><br/>

## Circular Linked List
The final common variation on the linked list theme is the circular linked list, which comes in singly and doubly linked varieties. Circular linked lists have no ends — no head or tail. Each element in a circular linked list has non-null next (and previous, if it’s also doubly linked) pointers or references. A list with one element merely points to itself. The primary traversal problem for these lists is cycle avoidance — if you don’t track where you start, you’ll cycle infinitely through the list.

Considerations:
The head element of a singly linked list must always be tracked; otherwise, the list will be lost — either garbage collected or leaked, depending on the language. This means that the pointer or reference to the head of the list must be updated when a new element is inserted ahead of the first element or when the existing first element is removed from the list.


Often, you need to work with list elements other than the head element. Operations on any but the first element of a linked list require traversal of some elements of the list. When traversing, you must always check that you haven’t reached the end of the list.

Because links in a singly linked list are maintained exclusively with next pointers or references, any insertion or deletion of elements in the middle of a list requires modification of the previous element’s next pointer or reference. If you’re given only the element to delete (or before which to insert), this requires traversal of the list from the head because there’s no other way to find the preceding element. Special care must be taken when the element to be deleted is the head of the list.
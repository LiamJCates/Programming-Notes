## Circular Linked List
The final common variation on the linked list theme is the circular linked list, which comes in singly and doubly linked varieties. Circular linked lists have no ends — no head or tail. Each element in a circular linked list has non-null next (and previous, if it’s also doubly linked) pointers or references. A list with one element merely points to itself. The primary traversal problem for these lists is cycle avoidance — if you don’t track where you start, you’ll cycle infinitely through the list.

Considerations:
The head element of a singly linked list must always be tracked; otherwise, the list will be lost — either garbage collected or leaked, depending on the language. This means that the pointer or reference to the head of the list must be updated when a new element is inserted ahead of the first element or when the existing first element is removed from the list.


Often, you need to work with list elements other than the head element. Operations on any but the first element of a linked list require traversal of some elements of the list. When traversing, you must always check that you haven’t reached the end of the list.

Because links in a singly linked list are maintained exclusively with next pointers or references, any insertion or deletion of elements in the middle of a list requires modification of the previous element’s next pointer or reference. If you’re given only the element to delete (or before which to insert), this requires traversal of the list from the head because there’s no other way to find the preceding element. Special care must be taken when the element to be deleted is the head of the list.

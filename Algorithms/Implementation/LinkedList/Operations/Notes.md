Successfully solving linked list problems requires a thorough understanding of how to operate on linked lists.

Tracking the Head Element
The head element of a singly linked list must always be tracked; otherwise, the list will be lost—either garbage collected or leaked, depending on the language. This means that the pointer or reference to the head of the list must be updated when a new element is inserted ahead of the first element or when the existing first element is removed from the list.



When implementing a linked list, we access the linked list through a reference to the head Node of the linked list. When you implement the linked list, you need to be a bit careful. What if multiple objects need a reference to the linked list, and then the head of the linked list changes some objects might still be pointing to the old head.

We could, if we chose, implement a Linked List class that wraps the Node class. Just having a single member variable: the head Node, would largely resolve the earlier issue.




Traversing a List
Often, you need to work with list elements other than the head element. Operations on any but the first element of a linked list require traversal of some elements of the list. When traversing, you must always check that you haven’t reached the end of the list.




The "Runner" Technique
The "runner" (or second pointer) technique is used in many linked list problems. The runner technique means that you iterate through the linked list with two pointers simultaneously, with one ahead of the other. The "fast" node might be ahead by a fixed amount, or it might be hopping multiple nodes for each one node that the "slow" node iterates through. For example, suppose you had a linked list a1 ->a2 -> ••• ->an ->b1 ->b2 ->  ••• ->bn and you wanted to rearrange it into a1 ->b1 ->a2 ->b2 ->  ••• ->an ->bn. You do not know the length of the linked list (but you do know that the length is an even number).



Inserting and Deleting Elements
Because links in a singly linked list are maintained exclusively with next pointers or references, any
insertion or deletion of elements in the middle of a list requires modification of the previous element’s next pointer or reference. If you’re given only the element to delete (or before which to insert),
this requires traversal of the list from the head because there’s no other way to find the preceding
element. Special care must be taken when the element to be deleted is the head of the list as the head must be updated.


Linus Torvalds (creator of Linux) has pointed out that the special case for deleting the first element is inelegant and unnecessary. If instead of traversing the list using a pointer to the current element, you traverse using a pointer to a pointer to the next element, then your traversal pointer points at the pointer that you need to change when you delete the element, regardless of whether it’s the head pointer or the next pointer of a previous element. This double indirection approach is a little more complex to understand, but eliminates the special case and associated duplicated code:

bool deleteElement( IntElement **npp, IntElement *deleteMe ){
if (!npp || !*npp || !deleteMe ) /* Check for null pointers */
return false;
while (*npp) {
if( *npp == deleteMe ){
/* npp points to head pointer (if deleteMe is first element)
or to next pointer within preceding element */
*npp = deleteMe->next;
free(deleteMe);
return true;
}
npp = &((*npp)->next);
}
/* deleteMe not found */
return false;
}

NOTE Deletion and insertion require a pointer or reference to the element
immediately preceding the deletion or insertion location.

Performing deletions raises another issue in languages without garbage collection, like C or C++.
Suppose you want to remove all the elements from a linked list. The natural inclination is to use a
single pointer to traverse the list, freeing elements as you go. A problem arises, however, when this
is implemented. Do you advance the pointer first or free the element first? If you advance the pointer
first, then the freeing is impossible because you overwrote the pointer to the element to be freed. If
you free the element first, advancing the pointer is impossible because it involves reading the next
pointer in the element that was just freed. The solution is to use two pointers, as in the following
example:
void deleteList( IntElement **head )
{
IntElement *deleteMe = *head;
while ( deleteMe ){
IntElement *next = deleteMe->next;
free(deleteMe);
deleteMe = next;
}
*head = NULL;
}
NOTE

Deletion of an element always requires at least two pointer variables.

Insertion requires two pointer variables as well, but because one of them is used for an element in the list and the other for the pointer returned by the memory allocation call, there’s little danger of forgetting this in the insertion case.

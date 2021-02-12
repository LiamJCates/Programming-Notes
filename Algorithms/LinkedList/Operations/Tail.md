Maintain Linked List Tail Pointer

This problem seems relatively straightforward. Deletion and insertion are common operations on a linked list, and you should be accustomed to using a head pointer for the list. The requirement to maintain a tail pointer is the only unusual aspect of this problem. This requirement doesn’t seem to fundamentally change anything about the list or the way you operate on it, so it doesn’t look as if you need to design any new algorithms. Just be sure to update the head and tail pointers when necessary.

When do you need to update these pointers? Obviously, operations in the middle of a long list do
not affect either the head or tail. You need to update the pointers only when you change the list such
that a different element appears at the beginning or end. More specifically, when you insert a new
element at either end of the list, that element becomes the new beginning or end of the list. When
you delete an element at the beginning or end of the list, the next-to-first or next-to-last element
becomes the new first or last element.
For each operation you have a general case for operations in the middle of the list and special cases
for operations at either end. When you deal with many special cases, it can be easy to miss some of
them, especially if some of the special cases have more specific special cases of their own. One technique to identify special cases is to consider what circumstances are likely to lead to special cases
being invoked. Then, you can check whether your proposed implementation works in each of these
circumstances. If you discover a circumstance that creates a problem, you have discovered a new
special case.


The circumstance where you are instructed to operate on the ends of the list has already been discussed. Another error-prone circumstance is a null pointer argument. The only other thing that can
change is the list on which you are operating—specifically, its length.
What lengths of lists may be problematic? You can expect somewhat different cases for the beginning, middle, and end of the list. Any list that doesn’t have these three distinct classes of elements
could lead to additional special cases. An empty list has no elements, so it obviously has no beginning, middle, or end elements. A one-element list has no middle elements and one element that is
both the beginning and end element. A two-element list has distinct beginning and end elements,
but no middle element. Any list longer than this has all three classes of elements and is effectively
the general case of lists—unlikely to lead to additional special cases. Based on this reasoning, you
should explicitly confirm that your implementation works correctly for lists of length 0, 1, and 2.
At this point in the problem, you can begin writing delete. If you use the common implementation that traverses the list using a single pointer to the current element, then as mentioned earlier,
you need a special case for deleting the first element of the list. You can compare the element to be
deleted to head to determine whether you need to invoke this case:
bool delete( Element *elem ){
if ( elem == head ) {
head = elem->next;
free( elem );
return true;
}
...
Now write the general middle case. You need an element pointer to keep track of your position in
the list. (Call the pointer curPos.) Recall that to delete an element from a linked list, you need a
pointer to the preceding element so that you can change its next pointer. The easiest way to find the
preceding element is to compare curPos->next to elem, so curPos points to the preceding element
when you find elem.
You also need to construct your loop so you don’t miss any elements. If you initialize curPos to
head, then curPos->next starts as the second element of the list. Starting at the second item is fine
because you treat the first element as a special case, but make your first check before advancing
curPos or you’ll miss the second element. If curPos becomes NULL, you have reached the end of
the list without finding the element you were supposed to delete, so you should return failure. The
middle case yields the following (added code is bolded):
bool delete( Element *elem ){
Element *curPos = head;
if ( elem == head ) {
head = elem->next;
free( elem );
return true;
}
while ( curPos ){56 ❘ CHAPTER 5 Linked Lists
if ( curPos->next == elem ){
curPos->next = elem->next;
free( elem );
return true;
}
curPos = curPos->next;
}
return false;
...
Next, consider the last element case. The last element’s next pointer is NULL. To remove it from the
list, you need to make the next-to-last element’s next pointer NULL and free the last element. If you
examine the loop constructed for middle elements, you see that it can delete the last element as well
as middle elements. The only difference is that you need to update the tail pointer when you delete
the last element. If you set curPos->next to NULL, you know you changed the end of the list and
must update the tail pointer. Adding this to complete the function, you get the following:
bool delete( Element *elem ){
Element *curPos = head;
if ( elem == head ){
head = elem->next;
free( elem );
return true;
}
while ( curPos ){
if ( curPos->next == elem ){
curPos->next = elem->next;
free( elem );
if ( curPos->next == NULL )
tail = curPos;
return true;
}
curPos = curPos->next;
}
return false;
}
This solution covers the three discussed special cases. Before you present the interviewer with this
solution, you should check behavior for null pointer arguments and the three potentially problematic list length circumstances.
What happens if elem is NULL? The while loop traverses the list until curPos->next is NULL (when
curPos is the last element). Then, on the next line, evaluating elem->next dereferences a null
pointer. Because it’s never possible to delete NULL from the list, the easiest way to fix this problem is
to return false if elem is NULL.
If the list has zero elements, then head and tail are both NULL. Because you’ll check that elem isn’t
NULL, elem == head will always be false. Further, because head is NULL, curPos will be NULL, andLinked List Problems ❘ 57
the body of the while loop won’t be executed. There doesn’t seem to be any problem with zeroelement lists. The function simply returns false because nothing can be deleted from an empty list.
Now try a one-element list. In this case, head and tail both point to the one element, which is the
only element you can delete. Again, elem == head is true. elem->next is NULL, so you correctly set
head to NULL and free the element; however, tail still points to the element you just freed. As you
can see, you need another special case to set tail to NULL for one-element lists.
What about two-element lists? Deleting the first element causes head to point to the remaining element, as it should. Similarly, deleting the last element causes tail to be correctly updated. The lack
of middle elements doesn’t seem to be a problem. You can add the two additional special cases and
then move on to insertAfter:
bool delete( Element *elem ){
Element *curPos = head;
if ( !elem )
return false;
if ( elem == head ){
head = elem->next;
free( elem );
/* special case for 1 element list */
if ( !head )
tail = NULL;
return true;
}
while ( curPos ){
if ( curPos->next == elem ){
curPos->next = elem->next;
free( elem );
if ( curPos->next == NULL )
tail = curPos;
return true;
}
curPos = curPos->next;
}
return false;
}
You can apply similar reasoning to writing insertAfter. Because you allocate a new element in this
function, you must take care to check that the allocation is successful and that you don’t leak any
memory. Many of the special cases encountered in delete are relevant in insertAfter, however,
and the code is structurally similar:
bool insertAfter( Element *elem, int data ){
Element *newElem, *curPos = head;
newElem = malloc( sizeof(Element) );58 ❘ CHAPTER 5 Linked Lists
if ( !newElem )
return false;
newElem->data = data;
/* Insert at beginning of list */
if ( !elem ){
newElem->next = head;
head = newElem;
/* Special case for empty list */
if ( !tail )
tail = newElem;
return true;
}
while ( curPos ){
if ( curPos == elem ){
newElem->next = curPos->next;
curPos->next = newElem;
/* Special case for inserting at end of list */
if ( !(newElem->next) )
tail = newElem;
return true;
}
curPos = curPos->next;
}
/* Insert position not found; free element and return failure */
free( newElem );
return false;
}
These are adequate solutions, but not particularly elegant ones. Each of them has multiple special
cases, and one special case that’s nested inside another. Enumerating special cases as you design
the algorithm is good practice. Many interview problems have special cases, so you should expect
to encounter them frequently. In the real world of programming, unhandled special cases represent bugs that may be difficult to find, reproduce, and fix. Programmers who identify special cases
as they are coding are likely to be more productive than those who find special cases through
debugging.
An alternative to writing special-case code is to try to further generalize your general-case algorithm
so it can handle the special cases as the general case. When possible, this may produce code that is
more concise, elegant, better performing, and easier to maintain.
The introduction to this chapter demonstrated a technique to eliminate the special-case code for
updating the head pointer when the first element is deleted. How might you use that approach to
eliminate special-case code for this problem?
Again, start by considering delete. If you try to apply the technique from the introduction directly,
you’ll encounter a problem. The deleteElement function in the introduction didn’t need to do anything with the element preceding the element to be deleted other than changing next, so a pointerLinked List Problems ❘ 59
to next was sufficient. In the current problem, you may need to set tail to point at the element preceding the deleted element; there’s no good, portable way to get the address of the element if all you
have is a pointer to its next field. One solution is to traverse the list with two pointers in tandem:
curPos pointing to the current element and ppNext pointing to the pointer to the next element. Try
writing out this implementation.
Think carefully about what the initial values for these pointers should be. The reason for using ppNext
is that it generalizes updating the head pointer and the next pointers; to accomplish this ppNext must
be initialized to &head. If ppNext points to head, the current position in the traversal is effectively
before the first element of the list. Because there is no element before the first element, you can initialize curPos to NULL. This helps to generalize updating tail, but also introduces the complication that
curPos is NULL at the beginning as well as the end of the list traversal. You need to make sure that
you advance curPos before testing its value; otherwise you’ll never traverse the list. Reimplementing
delete with these considerations yields a more concise, elegant function:
bool delete( Element *elem ){
Element *curPos = NULL, **ppNext = &head;
if ( !elem )
return false;
while (true) {
if( *ppNext == elem ){
*ppNext = elem->next;
if ( !(elem->next)) /* If deleting last element update tail */
tail = curPos;
free( elem );
return true;
}
if (!(curPos = *ppNext))
break;
ppNext = &(curPos->next);
}
return false;
}
You can reimplement insertAfter using a similar approach with similar improvement in length
and elegance:
bool insertAfter( Element *elem, int data ){
Element *newElem, *curPos = NULL, **ppNext = &head;
newElem = malloc( sizeof(Element) );
if ( !newElem )
return false;
newElem->data = data;
while (true) {
if( curPos == elem ){
newElem->next = *ppNext;
*ppNext = newElem;60 ❘ CHAPTER 5 Linked Lists
/* Update tail if inserting at end of list */
if( !(newElem->next) )
tail = newElem;
return true;
}
if (!(curPos = *ppNext))
break;
ppNext = &(curPos->next);
}
/* Insert position not found; free element and return failure */
free( newElem );
return false;
}
Recognizing problematic special cases and writing code to specifically address them is important;
recoding to make special cases cease to exist is even better.

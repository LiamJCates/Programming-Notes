PROBLEM

Given a singly linked list, devise a time and space efficient algorithm to find the mth-to-last element of the list.

Define mth to last such that when m = 0 the last element of the list is returned.

Issue
Singly linked lists can be traversed only in the forward direction. For this problem you are asked to find a given element based on its position relative to the end of the list.

List traversal deals with links between subsequent list elements. As such, the structure is unconcerned with where the end of the list is, and when you find the end, there is no easy way to backtrack the required number of elements.

A singly linked list is a particularly poor choice for a data structure when you frequently need to find the mth-to-last element. If you were to encounter such a problem while implementing a real program, the correct and most efficient solution would probably be to substitute a more suitable data structure (such as a doubly linked list or dynamic array) to replace the singly linked list. Although this comment shows that you understand good design, the interviewer still wants you to solve the problem as it was originally phrased.

Solution

You know that the element you want is m elements from the end of the list.
Therefore, if you traverse m elements forward from an element and that places you exactly at the end of the list, you have found the element you were searching for.

One approach is to simply test each element in this manner until you find the one you’re searching for. Intuitively, this feels like an inefficient solution because you will traverse over the same elements many times. If you analyze this potential solution more closely, you can see that you would be traversing m elements for most of the elements in the list. If the length of the list is n, the algorithm would be O(mn). You need to find a solution more efficient than O(mn).

Another approach is to store some of the elements (or, more likely, pointers or references to the elements) as you traverse the list? Then, when you reach the end of the list, you can look back m elements in your storage data structure to find the appropriate element. If you use an appropriate temporary storage data structure, this algorithm is O(n) because it requires only one traversal through the list. Yet this approach is far from perfect. As m becomes large, the temporary data structure would become large as well. In the worst-case scenario, this approach might require almost as much storage space as the list itself—not a particularly space-efficient algorithm.

Perhaps working back from the end of the list is not the best approach. Because counting from the
beginning of the list is trivial, is there any way to count from the beginning to find the desired element? The desired element is m from the end of the list, and you know the value of m. It must also
be l elements from the beginning of the list, although you don’t know l. However, l + m = n, the
length of the list. It’s easy to count all the elements in the list. Then you can calculate l = n – m, and
traverse l elements from the beginning of the list.
Although this process involves two passes through the list, it’s still O(n). It requires only a few variables’ worth of storage, so this method is a significant improvement over the previous attempt. If
you could change the functions that modify the list such that they would increment a count variable
for every element added and decrement it for every element removed, you could eliminate the count
pass, making this a relatively efficient algorithm. Again, though this point is worth mentioning, the
interviewer is probably looking for a solution that doesn’t modify the data structure or place any
restrictions on the methods used to access it.
Assuming you must explicitly count the elements in the current algorithm, you must make almost
two complete traversals of the linked list. A large list on a memory-constrained system might exist
mostly in paged-out virtual memory (on disk). In such a case, each complete traversal of the list
would require a large amount of disk access to swap the relevant portions of the list in and out of
memory. Under these conditions, an algorithm that made only one complete traversal of the list
might be significantly faster than an algorithm that made two traversals, even though they would
both be O(n). Is there a way to find the target element with a single traversal?
The counting-from-the-beginning algorithm obviously demands that you know the length of the list.
If you can’t track the length so that you know it ahead of time, you can determine the length only by
a full-list traversal. There doesn’t seem to be much hope for getting this algorithm down to a single
traversal.
Try reconsidering the previous linear time algorithm, which required only one traversal but was
rejected for requiring too much storage. Can you reduce the storage requirements of this approach?
When you reach the end of the list, you are actually interested in only one of the m elements you’ve
been tracking—the element that is m elements behind your current position. You are tracking the
rest of the m elements merely because the element m behind your current position changes every
time your position advances. Keeping a queue m elements long, where you add the current element
to the head and remove an element from the end every time you advance your current position,
ensures that the last element in the queue is always m elements behind your current position.
In effect, you are using this m element data structure to make it easy to implicitly advance an
m-behind pointer in lock step with your current position pointer. However, this data structure is
unnecessary—you can explicitly advance the m-behind pointer by following each element’s next
pointer just as you do for your current position pointer. This is as easy as (or perhaps easier than)
implicitly advancing by shifting through a queue, and it eliminates the need to track all the elements
between your current position pointer and your m-behind pointer. This algorithm seems to be the64 ❘ CHAPTER 5 Linked Lists
one you’ve been looking for: linear time, a single traversal, and negligible storage requirements.
Now you just need to work out the details.
You need to use two pointers: a current position pointer and an m-behind pointer. You must ensure
that the two pointers are actually spaced m elements apart; then you can advance them at the same
rate. When your current position is the end of the list, m-behind points to the mth-to-last element.
How can you get the pointers spaced properly? If you count elements as you traverse the list, you
can move the current position pointer to the mth element of the list. If you then start the m-behind
pointer at the beginning of the list, they will be spaced m elements apart.
Are there any error conditions you need to watch for? If the list is less than m elements long, then
there is no mth-to-last element. In such a case, you would run off the end of the list as you tried to
advance the current position pointer to the mth element, possibly dereferencing a null pointer in the
process. Therefore, check that you don’t hit the end of the list while doing this initial advance.
With this caveat in mind, you can implement the algorithm. It’s easy to introduce off-by-one errors
in any code that spaces any two things m items apart or counts m items from a given point. You may
want to refer to the exact definition of “mth to last” given in the problem and try a simple example
on paper to make sure you get your counts right, particularly in the initial advancement of current.
ListElement *findMToLastElement( ListElement *head, int m ){
ListElement *current, *mBehind;
int i;
if (!head)
return NULL;
/* Advance current m elements from beginning,
* checking for the end of the list
*/
current = head;
for ( i = 0; i < m; i++ ){
if ( current->next ){
current = current->next;
} else {
return NULL;
}
}
/* Start mBehind at beginning and advance pointers
* together until current hits last element
*/
mBehind = head;
while ( current->next ){
current = current->next;
mBehind = mBehind->next;
}
/* mBehind now points to the element we were
* searching for, so return it
*/
return mBehind;
}

PROBLEM Unflatten the list created by the previous problem and restore the
data structure to its original condition.
This problem is the reverse of the previous problem, so you already know a lot about this data structure. One important insight is that you created the flattened list by combining all the child lists into
one long level. To get back the original list, you must separate the long flattened list back into its
original child lists.
Try doing the exact opposite of what you did to create the list. When flattening the list, you traversed down the list from the start and added child lists to the end. To reverse this, you go backward
from the tail and break off parts of the first level. You could break off a part when you encounter a
node that was the beginning of a child list in the unflattened list. Unfortunately, this is more difficult than it might seem because you can’t easily determine whether a particular node is a child (indicating that it started a child list) in the original data structure. The only way to determine whether
a node is a child is to scan through the child pointers of all the previous nodes. All this scanning
would be inefficient, so you should examine some additional possibilities to find a better solution.
One way to get around the child node problem is to go through the list from start to end, storing
pointers to all the child nodes in a separate data structure. Then you could go backward through the
list and separate every child node. Looking up nodes in this way frees you from repeated scans to
determine whether a node is a child. This is a good solution, but it still requires an extra data structure. Try looking for a solution without an extra data structure.
It seems you have exhausted all the possibilities for going backward through the list, so try an algorithm that traverses the list from the start to the end. You still can’t immediately determine whether
a node is a child. One advantage of going forward, however, is that you can find all the child nodes
in the same order that you appended them to the first level. You also know that every child node
began a child list in the original list. If you separate each child node from the node before it, you get
the unflattened list back.
You can’t simply traverse the list from the start, find each node with a child, and separate the child
from its previous node. You would get to the end of your list at the break between the first and second level, leaving the rest of the data structure untraversed. This approach seems promising, though.
You can traverse every child list, starting with the first level (which is a child list itself). When youLinked List Problems ❘ 69
find a child, continue traversing the original child list and also traverse the newly found child list.
You can’t traverse both at the same time, however. You could save one of these locations in a data
structure and traverse it later. However, rather than design and implement this data structure, you
can use recursion. Specifically, every time you find a node with a child, separate the child from its
previous node, start traversing the new child list, and then continue traversing the original child list.
This is an efficient algorithm because each node is checked at most twice, resulting in an O(n) running time. Again, an O(n) running time is the best you can do because you must check each node at
least once to see if it is a child. In the average case, the number of function calls is small in relation
to the number of nodes, so the recursive overhead is not too bad. In the worst case, the number of
function calls is no more than the number of nodes. This solution is approximately as efficient as
the earlier proposal that required an extra data structure, but somewhat simpler and easier to code.
Therefore, this recursive solution would probably be a better choice in an interview. In outline form,
the algorithm looks like the following:
Explore path:
While not at the end
If current node has a child
Separate the child from its previous node
Explore path beginning with the child
Go onto the next node
It can be implemented in C as:
/* unflattenList wraps the recursive function and updates the tail pointer. */
void unflattenList( Node *start, Node **tail ){
Node *curNode;
exploreAndSeparate( start );
/* Update the tail pointer */
for ( curNode = start; curNode->next; curNode = curNode->next )
; /* Body intentionally empty */
*tail = curNode;
}
/* exploreAndSeparate actually does the recursion and separation */
void exploreAndSeparate( Node *childListStart ){
Node *curNode = childListStart;
while ( curNode ){
if ( curNode->child ){
/* terminates the child list before the child */
curNode->child->prev->next = NULL;
/* starts the child list beginning with the child */
curNode->child->prev = NULL;
exploreAndSeparate( curNode->child );
}
curNode = curNode->next;
}
}70 ❘ CHAPTER 5 Linked Lists
The preceding solution was derived by reversing the list-flattening algorithm. The function call overhead in a recursive implementation can be substantial. Just because a problem can be solved with
recursion doesn’t mean it should be: consider whether there’s a simple iterative solution.
You might iterate through the list from start, looking for child pointers that are not NULL. When
you find one, you could break the remainder of the list starting at the child off so that it becomes
part of a lower level. However, this has the downside that the entire remainder of the list immediately becomes part of the next lower level. Instead of reconstructing the original data structure this
would produce a data structure that looks like a set of stairs.
However, if you look at how you constructed the flattened list, each child brought up to a higher
level is placed before each child encountered later in the search. So, if you start from the end of
the list and work backward, you can unflatten the list by breaking off each child list as soon as you
encounter its parent, while avoiding the previously described problem you would have if you used
this strategy while iterating forward through the list. If you’re careful about how you break out the
child list and track tail carefully, you can reconstruct the original list.
The C code to do this is:
void unflattenIteratative(Node* start, Node** tail) {
if (!(*tail)) return; //don't dereference if passed a null pointer
Node* tracker = *tail;
while (tracker){
if (tracker->child){
*tail = tracker->child->prev;
tracker->child->prev = NULL;
(*tail)->next = NULL;
}
tracker = tracker->prev;
}
}

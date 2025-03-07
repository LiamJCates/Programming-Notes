PROBLEM

Start with a standard doubly linked list. Now imagine that in addition to the next and previous pointers, each element has a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure

Flatten the list so that all the nodes appear in a single-level, doubly linked list.
You are given the head and tail of the first level of the list.


This list-flattening problem gives you plenty of freedom. You have simply been asked to flatten the
list. You can accomplish this task in many ways. Each way results in a one-level list with a different
node ordering. Start by considering several options for algorithms and the node orders they would
yield. Then implement the algorithm that looks easiest and most efficient.
Begin by looking at the data structure. This data structure is a little unusual for a list. It has levels
and children—somewhat like a tree. A tree also has levels and children, as you’ll see in the next
chapter, but trees don’t have links between nodes on the same level. You might try to use a common
tree traversal algorithm and copy each node into a new list as you visit it as a simple way to flatten
the structure.
The data structure is not exactly a normal tree, so any traversal algorithm you use must be modified.
From the perspective of a tree, each separate child list in the data structure forms a single extended
tree node. This may not seem too bad: where a standard traversal algorithm checks the child pointers of each tree node directly, you just need to do a linked list traversal to check all the child pointers.
Every time you check a node, you can copy it to a duplicate list. This duplicate list will be your flattened list.
Before you work out the details of this solution, consider its efficiency. Every node is examined once,
so this is an O(n) solution. There is likely to be some overhead for the recursion or data structure
required for the traversal. In addition, you make a duplicate copy of each node to create the new list.
This copying is inefficient, especially if the structure is large. See if you can identify a more efficient
solution that doesn’t require so much copying.
So far, the proposed solution has concentrated on an algorithm, letting the ordering follow.
Instead, try focusing on an ordering and then try to deduce an algorithm. You can focus on the
data structure’s levels as a source of ordering. It helps to define the parts of a level as child lists.
Just as rooms in a hotel are ordered by level, you can order nodes by the level in which they occur.
Every node is in a level and appears in an ordering within that level (arranging the child lists from
left to right). Therefore, you have a logical ordering just like hotel rooms. You can order by starting with all the first-level nodes, followed by all the second-level nodes, followed by all the thirdlevel nodes, and so on.


Now try to discover an algorithm that yields this ordering. One property of this ordering is that
you never rearrange the order of the nodes in their respective levels, so you could connect all the
nodes on each level into a list and then join all the connected levels. However, to find all the nodes
on a given level so that you can join them, you would need to do a breadth-first search of that level.
Breadth-first searching is inefficient, so you should continue to look for a better solution.
In Figure 5-3, the second level is composed of two child lists. Each child list starts with a different
child of a first-level node. You could try to append the child lists one at a time to the end of the first
level instead of combining the child lists.
To append the child lists one at a time, traverse the first level from the start, following the next
pointers. Every time you encounter a node with a child, append the child (and thus the child list) to
the end of the first level and update the tail pointer. Eventually, you append the entire second level
to the end of the first level. You can continue traversing the first level and arrive at the start of the
old second level. If you continue this process of appending children to the end of the first level, you
eventually append every child list to the end and have a flattened list in the required order. More formally, this algorithm is as follows:
Start at the beginning of the first level
While you are not at the end of the first level
If the current node has a child
Append the child to the end of the first level
Update the tail pointer
Advance to next node
This algorithm is easy to implement because it’s so simple. In terms of efficiency, every node after
the first level is examined twice. Each node is examined once when you update the tail pointer for
each child list and once when you examine the node to see if it has a child. The nodes in the first
level are examined only once when you examine them for children because you had a first-level
tail pointer when you began. Therefore, there are no more than 2n comparisons in this algorithm,
and it is an O(n) solution. This is the best time order you can achieve because every node must be
examined. Although this solution has the same time order as the tree traversal approach considered
earlier, it is more efficient because it requires no recursion or additional memory. (Other equally
efficient solutions to this problem exist. One such solution involves inserting child lists after their
parents, rather than at the end of the list.)
The code for this algorithm is as follows. Note that the function takes a pointer to the tail pointer so
that changes to the tail pointer are retained when the function returns:
void flattenList( Node *head, Node **tail ){
Node *curNode = head;
while ( curNode ){
/* The current node has a child */
if ( curNode->child ){
append( curNode->child, tail );
}
curNode = curNode->next;
}
}
/* Appends the child list to the end of the tail and updates
* the tail.
*/
void append( Node *child, Node **tail ){
Node *curNode;
/* Append the child list to the end */
(*tail)->next = child;
child->prev = *tail;
/* Find the new tail, which is the end of the child list. */
for ( curNode = child; curNode->next; curNode = curNode->next )
; /* Body intentionally empty */
/* Update the tail pointer now that curNode is the new tail */
*tail = curNode;
}

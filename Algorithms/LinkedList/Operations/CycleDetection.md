Write a function that takes a pointer to the head of a list and determines whether the list is cyclic or acyclic. Your function should return false if the list is acyclic and true if it is cyclic. You may not modify the list in any way.

In the acyclic list, there is an end node that is null terminated. Thus, if you can find this end node, you can test whether the list is cyclic or acyclic


In the acyclic list, it is easy to find the end node. You traverse the list until you reach a null terminated node.
In the cyclic list, though, it is more difficult. If you just traverse the list, you go in a circle and
won’t know whether you’re in a cyclic list or just a long acyclic list. You need a more sophisticated
approach.
Consider the end node a bit more. The end node points to a node that has another node pointing at
it. This means that two pointers are pointing at the same node. This node is the only node with two
elements pointing at it. You can design an algorithm around this property. You can traverse the list
and check every node to determine whether two other nodes are pointing at it. If you find such a
node, the list must be cyclic. Otherwise, the list is acyclic, and you will eventually encounter a null
pointer.
Unfortunately, it is difficult to check the number of nodes pointing at each element. Look for
another special property of the end node in a cyclic list. When you traverse the list, the end node’s
next node is a node that you have previously encountered. Instead of checking for a node with two
pointers pointing at it, you can check whether you have already encountered a node. If you find a
previously encountered node, you have a cyclic list. If you encounter a null pointer, you have an
acyclic list. This is only part of the algorithm. You still need to figure out how to determine whether
you have previously encountered a node.
The easiest way to do this would be to mark each element as you visit it, but you’ve been told you’re
not allowed to modify the list. You could keep track of the nodes you’ve encountered by putting
them in a separate list. Then you would compare the current node to all the nodes in the alreadyencountered list. If the current node ever points to a node in the already-encountered list, you have
a cycle. Otherwise, you’ll get to the end of the list and see that it’s null terminated and thus acyclic.
This would work, but in the worst case the already-encountered list would require as much memory
as the original list. Try to reduce this memory requirement.

What are you storing in the already-encountered list? The already-encountered list’s first node
points to the original list’s first node, its second node points to the original list’s second node, its
third node points to the original list’s third node, and so on. You’re creating a list that mirrors the
original list. This is unnecessary—you can just use the original list.
Try this approach: Because you know your current node in the list and the start of the list, you can
compare your current node’s next pointer to all its previous nodes directly. For the ith node, compare its next pointer to see if it points to any of nodes 1 to i – 1. If any are equal, you have a cycle.
What’s the time order of this algorithm? For the first node, 0 previous nodes are examined; for the
second node, one previous node is examined; for the third node, two previous nodes are examined,
and so on. Thus, the algorithm examines 0 + 1 + 2 + 3 +. . .+ n nodes.

or O(n^2)







What are you storing in the already-encountered list? The already-encountered list’s first node
points to the original list’s first node, its second node points to the original list’s second node, its
third node points to the original list’s third node, and so on. You’re creating a list that mirrors the
original list. This is unnecessary—you can just use the original list.
Try this approach: Because you know your current node in the list and the start of the list, you can
compare your current node’s next pointer to all its previous nodes directly. For the ith node, compare its next pointer to see if it points to any of nodes 1 to i – 1. If any are equal, you have a cycle.
What’s the time order of this algorithm? For the first node, 0 previous nodes are examined; for the
second node, one previous node is examined; for the third node, two previous nodes are examined,
and so on. Thus, the algorithm examines 0 + 1 + 2 + 3 +. . .+ n nodes. As discussed in Chapter 4,
such an algorithm is O(n2).
That’s about as far as you can go with this approach. Although it’s difficult to discover without
some sort of hint, there is a better solution involving two pointers. What can you do with two pointers that you couldn’t do with one? You can advance them on top of each other, but then you might
as well have one pointer. You could advance them with a fixed interval between them, but this
doesn’t seem to gain anything. What happens if you advance the pointers at different speeds?
In the acyclic list, the faster pointer reaches the end. In the cyclic list, they both loop endlessly. The
faster pointer eventually catches up with and passes the slower pointer. If the fast pointer is ever
behind or equal to the slower pointer, you have a cyclic list. If it encounters a null pointer, you have
an acyclic list. You’ll need to start the fast pointer one node ahead of the slow pointer so they’re not
equal to begin with. In outline form, this algorithm looks like this:
Start slow pointer at the head of the list
Start fast pointer at second node
Loop infinitely
If the fast pointer reaches a null pointer
Return that the list is null terminated
If the fast pointer moves onto or over the slow pointer
Return that there is a cycle
Advance the slow pointer one node
Advance the fast pointer two nodes
You can now implement this solution:
/*

*/

/* Takes a pointer to the head of a linked list and determines if
* the list ends in a cycle or is NULL terminated
*/
bool isCyclicList(Node *head)
{

    if (head)
		{
			Node *fast, *slow;  
	    slow = head;
	    fast = head->next;
	    while (true)
	    {
	        if (!fast || !fast->next)
	            return false;
	        else if (fast == slow || fast->next == slow)
	            return true;
	        else
	        {
	            slow = slow->next;
	            fast = fast->next->next;
	        }
	    }
		}
		return false;
}

Is this algorithm faster than the earlier solution? If this list is acyclic, the faster pointer comes to the
end after examining n nodes, while the slower pointer traverses 1⁄2 n nodes. Thus, you examine
3⁄2n nodes, which is an O(n) algorithm.
What about a cyclic list? The slower pointer never goes around any loop more than once. When the
slower pointer has examined n nodes, the faster pointer will have examined 2n nodes and “passed”
the slower pointer, regardless of the loop’s size. Therefore, in the worst case you examine 3n nodes,
which is still O(n). Regardless of whether the list is cyclic or acyclic, this two-pointer approach is
better than the single-pointer approach to the problem.

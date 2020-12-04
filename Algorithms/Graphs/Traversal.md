Graph Traversal
Traversing a graph means systematically following the edges of the graph to visit its vertices

There are two types of standard graph traversal techniques:
1. Breadth First Search (BFS)
2. Depth First Search (DFS)

A breadth-first search (BFS) algorithm visits the immediate children
of a node before it goes any deeper. 

A depth-first search (DFS) goes as deep as it can down a path before visiting sibling nodes (that is, before visiting nodes that share the same parent).

A breadth-first search typically uses a Queue (FIFO) to keep track of
nodes
a depth-first search typically uses a Stack (LIFO) to keep track of
nodes






Breadth First Search (BFS)

implement the breadth first search traversal technique with a queue.

The queue collection stores all the adjacent unvisited neighbor nodes of a given node under consideration.

Initially, the front and rear are set to -1.

We will also maintain the status of the visited nodes in a Boolean array, which will have value 1 if the node is visited and 0 if it is not visited.
•	 First, we will en-queue/insert the starting node into the queue.
•	 Second, the first node/element in the queue is deleted from the queue
and all the adjacent unvisited nodes are inserted into the queue.

This is repeated until the queue becomes empty.




Depth First Search (DFS)

Implement the depth first search traversal technique with a stack.

we first select any node in the graph as a starting
node, and then we travel along a path which begins from the starting node.
We will visit the adjacent node of the starting node, and again the adjacent
node of the previous node, and so on.

we will maintain a stack collection to store all the adjacent unvisited neighbor nodes of a given node.

Initially, the top is set to -1.

We will also maintain the status of the visited nodes in a Boolean array, which will have value 1 if the node is visited and 0 if it is not visited.

•	 First, we will push the starting node onto the stack.

•	 Second, the topmost node/element is popped out from the stack and is traversed. If it is already traversed, then we will ignore it.

•	 Third, all the adjacent unvisited nodes of the popped node/element are pushed onto the stack. This process is repeated until the queue becomes empty. The steps are repeated until the stack becomes empty.

When visiting nodes in a depth-first algorithm the three distinct orders of traversal are preorder, inorder, and postorder



memory aid:
Breadth first search is implemented using a queue data structure, and
depth first search is implemented using a stack data structure, as it can
be remembered by alphabetical order. B (Breadth First Search) and Q
(Queue) comes before than D (Depth First Search) and S (Stack) in alphabetical order.

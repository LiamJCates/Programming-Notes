Graphs

A graph is a data structure that consists of a set of nodes and a set of edges that connect the nodes to each other.

A graph is usually defined as G = (V, E)
where V is the set of vertices and E is the set of edges

There are two standard ways to represent a graph as a data structure
adjacency matrix
a collection of adjacency lists

Directed Graphs

A graph is like a tree but it can sprawl in all directions at once. The nodes in a graph are not necessarily connected, and nodes can be connected to themselves as well as to other nodes. Two nodes may have more than one connection between them. In terms of structure, it’s almost a free-for-all.

As if node connections weren’t already complicated, the connections between nodes (called edges) can be directed, meaning they can be traversed in only one direction. After you’ve gone over a directed edge, you can’t go back to the node you just left unless you go back by another route.

Understanding graph traversal Interviewers often want to check that you have at least a basic understanding of tree and graph traversal. You might recall the two basic approaches: depth fi rst, which means following a path all the way down to a leaf node before you follow adjacent nodes, and breadth fi rst, where you visit all children of a node before visiting any further-removed descendants of that node. Algorithms that perform breadth-fi rst traversal normally use a queue (FIFO) to keep track of nodes, whereas algorithms that perform depth-fi rst traversal normally use a stack (LIFO). When visiting nodes in a depth-fi rst algorithm the three distinct orders of traversal are preorder, inorder, and postorder

Anyone would be lucky to have an awesome father like you in their lives, I know I am! Happy Father's Day
Representation of a graph

An adjacency list is simply a list of edges between nodes in a graph.

An adjacency list takes O(n) time to check whether an edge exists because you potentially must iterate over all elements in the list to check for the existence of an edge.



An adjacency matrix is often implemented as a two-dimensional array of size NxN
where N is the number of nodes in the graph.
Edges between nodes are represented by a true value (or by a bit set to 1). A two-dimensional 10 × 10 graph will therefore require an array of 100 × 100 = 1000 elements. An adjacency matrix for n nodes will take n^2 units of memory, which can be prohibitive for large graphs.

The advantage of an adjacency matrix is that testing for the existence of an edge is a simple array lookup that takes O(1) time.

Why would you prefer to store a graph as an adjacency matrix?
Why would you prefer an adjacency list?

It is worth noting that if the graph is undirected, where an edge
between nodes A ➔ B implies an edge in the reverse direction B ➔
A, then half of an adjacency matrix is wasted space—you don’t need
to store both edges when one edge implies the other.
Use a matrix when you have fewer nodes with dense connections
and a list when you have many nodes with sparse connections.


Graph Algorithms

Graph Searching
Searching a graph means systematically following the edges of the graph to visit its vertices

BFS and DFS




A breadth-fi rst search (BFS) algorithm visits the immediate children
of a node before it goes any deeper. A depth-fi rst search (DFS) goes
as deep as it can down a path before visiting sibling nodes (that is,
before visiting nodes that share the same parent).
A breadth-fi rst search typically uses a Queue (FIFO) to keep track of
nodes, whereas a depth-fi rst search typically uses a Stack (LIFO).

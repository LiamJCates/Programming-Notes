Graphs

A graph is a data structure that consists of a set of nodes and a set of edges that connect the nodes to each other.

A graph is usually defined as G = (V, E)
where V is the set of vertices and E is the set of edges

Thus, a graph G can be defined as an ordered set of vertices and edges
G = (V, E), where V(G) represents the set of vertices and E(G) represents the set
of edges that connect these vertices


There are two types of graphs:
Undirected Graph – In an undirected graph, the edges do not have
any direction associated with them. An edge between two verticies can be traversed in either direction

Directed Graph – In a directed graph, the edges have directions associated with them and can only be traversed in their associated direction




Terms
Degree of a vertex/node – The degree of a node is the total number
of edges incident to that particular node.

In-degree of a node – The in-degree of a node is equal to the
number of edges arriving at that particular node.

Out-degree of a node – The out-degree is equal to the number of
edges leaving that particular node.

Isolated Node/Vertex – A node having zero edges is known as the
isolated node. The degree of such a node is zero.

Pendant Node/Vertex – A node having one edge is known as a
pendant node. The degree of such a node is one.


Adjacent Nodes – For every edge e = (A, B) that connect nodes A
and B, the nodes A and B are said to be the adjacent nodes.

Parallel Edges – If there is more than one edge between the same
pair of nodes, then they are known as parallel edges.

Loop – If an edge has a starting and ending point at the same node,
that is, e = (A, A), then it is known as a loop

Simple Graph – A graph G(V, E) is known as a simple graph if it does
not contain any loop or parallel edge.

Complete Graph – A graph G(V, E) is known as a complete graph if
and only if every node in the graph is connected to another node and
there is no loop on any of the nodes.

Regular Graph – A regular graph is a graph in which every node has
the same degree. If every node has a degree r, then the graph is called
a regular graph of degree r. In the given figure, all the nodes have the
same degree, that is, 2; hence, it is known as the 2-regular graph.

Multi-graph - A graph G(V, E) is known as a multi-graph if it contains
either a loop, parallel edges, or both.

Cycle – It is a path containing one or more edges which start from a
particular node and also terminate at the same node.

Cyclic Graph – A graph which has cycles in it is known as a cyclic
graph.

Acyclic Graph – A graph without any cycles is known as an acyclic
graph.

Connected Graph – A graph G(V, E) is known as a connected graph
if there is a path from any node in the graph to another node in the
graph such that for every pair of distinct nodes, there must be a path.

Strongly Connected Graph – A directed graph is said to be a
strongly connected graph if there exists a dedicated path between
every pair of nodes in the graph. For example, if there are two nodes,
say P and Q, and there is a dedicated path from P to Q, then there
must be a path from Q to P.

Size of a graph – The size of a graph is equal to the total number of
edges present in the graph.

Weighted Graph – A graph G(V, E) is said to be a weighted graph if
all the edges in the graph are assigned some data. This data indicates
the cost of traversing the edge.









Graphs can be represented in a computer’s memory in either of the
following ways:
1. Sequential Representation of Graphs using Adjacency Matrix
2. Linked Representation of Graphs using Adjacency List








Understanding graph traversal Interviewers often want to check that you have at least a basic understanding of tree and graph traversal. You might recall the two basic approaches: depth fi rst, which means following a path all the way down to a leaf node before you follow adjacent nodes, and breadth fi rst, where you visit all children of a node before visiting any further-removed descendants of that node. Algorithms that perform breadth-fi rst traversal normally use a queue (FIFO) to keep track of nodes, whereas algorithms that perform depth-fi rst traversal normally use a stack (LIFO). When visiting nodes in a depth-fi rst algorithm the three distinct orders of traversal are preorder, inorder, and postorder

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

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








Representation of a graph

Graphs can be represented in a computer’s memory in either of the
following ways:
1. Sequential Representation of Graphs using Adjacency Matrix
2. Linked Representation of Graphs using Adjacency List


Adjacency Matrix Representation


An adjacency matrix is used to represent the information of the nodes
which are adjacent to one another. The two nodes will only be adjacent
when there is an edge connecting those nodes. For any graph G having n
nodes, the dimension of the adjacency matrix will be (n X n).
Thus the memory space needed to represent a graph using it's adjacency matrix is n^2
Let G(V, E) be a graph having vertices V = {V1, V2, V3, …, Vn}, and then the adjacency matrix representation (n X n) will be given by:

aij = [0,1]

where 1 if there is an edge from Vi to Vj, 0 otherwise

The adjacency matrix is also known as a bit matrix or Boolean matrix,
since it contains only 0s and 1s.

An adjacency matrix is often implemented as a two-dimensional array of size NxN
where N is the number of nodes in the graph. n^2 units of memory, which can be prohibitive for large graphs.

The advantage of an adjacency matrix is that testing for the existence of an edge is a simple array lookup that takes O(1) time.

weighted adjacency matrix
The adjacency matrix for a weighted graph will always contain the
weights of the edges connecting the nodes instead of 0 and 1.

multigraph adjacency matrix
The adjacency matrix for an undirected multi-graph will contain the
number of edges connecting the vertices instead of 1.

Extra trivia
The adjacency matrix for an undirected graph is always symmetric
The adjacency matrix for a simple graph having no loops or parallel
edges will always contain 0s on the diagonal.










Adjacency List Representation


An adjacency list is simply a list of edges between nodes in a graph.

In this representation, every node is linked to its list of all the other nodes which are adjacent to it.

An adjacency list takes O(n) time to check whether an edge exists because you potentially must iterate over all elements in the list to check for the existence of an edge.

weighted adjacency list
Also includes the weight of an edge in each none head list node





The adjacency matrix representation has some major drawbacks. First, it
is very difficult to insert and delete the nodes in/from the graph as the size of the matrix needs to be changed accordingly, which is a very time-consuming
process. Also, sometimes the matrix may contain many zeroes (sparse matrix).
Hence, it is a wasteful representation.

Therefore, adjacency list representation is preferred for representing sparse graphs in the memory. Adjacency list representation makes it easier to add or delete nodes. Also, it shows the adjacent nodes of a particular node.





Why would you prefer to store a graph as an adjacency matrix?
Why would you prefer an adjacency list?

It is worth noting that if the graph is undirected, where an edge
between nodes A ➔ B implies an edge in the reverse direction B ➔
A, then half of an adjacency matrix is wasted space—you don’t need
to store both edges when one edge implies the other.
Use a matrix when you have fewer nodes with dense connections
and a list when you have many nodes with sparse connections.

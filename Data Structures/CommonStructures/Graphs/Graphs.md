Graphs

Graphs, like trees, consist of a set of nodes with parents and children — a tree is actually a special case of a graph. But unlike tree nodes, graph nodes, called vertices, can have multiple “parents,” possibly creating a loop (a cycle). In addition, the links between vertices, as well as the vertices themselves, may have values or weights. These links are called edges because
they may contain more information than just a pointer. In a graph, edges can be one-way or two-way. A graph with one-way edges is called a directed graph. A graph with only two-way edges is called an undirected graph.


Graphs are commonly used to model real-world problems that are difficult to model with other data structures. For example, a directed graph could represent the aqueducts connecting cities because water flows only one way. You might use such a graph to help you find the fastest way to get water from city A to city D. An undirected graph can represent something such as a series of relays in signal transmission.

A graph is defined as G = (V, E)

where
	V is the set of vertices
	E is the set of edges between vertices
	V(G) represents the set of vertices
	E(G) represents the set of edges






There are two general types of graphs:

Undirected Graph
In an undirected graph, the edges do not have any direction associated with them. An edge between two vertices can be traversed in either direction

Directed Graph
In a directed graph, the edges have directions associated with them and can only be traversed in their associated direction




Terms
Isolated Vertex – A vertex having zero edges is known as the isolated vertex. The degree of such a vertex is zero.

Pendant Vertex – A vertex having one edge is known as a pendant vertex. The degree of such a vertex is one.

Adjacent Vertices – For every edge e = (A, B) that connect vertices A and B, the vertices A and B are said to be the adjacent.

Parallel Vertices – If there is more than one edge between the same pair of vertices, then they are known as parallel edges.

Incident Edges - If two edges e and f have a common vertex A, the edges are called incident.

Vertex and Edge Incidence - A vertex and an edge are called incident if the vertex is one of the two vertices the edge connects.

Degree of a vertex – The degree of a vertex is the total number of edges incident to that particular vertex.

In-degree of a vertex – The in-degree of a vertex is equal to the number of edges arriving at that particular vertex.

Out-degree of a vertex – The out-degree is equal to the number of edges leaving that particular vertex.

Loop – If an edge has a starting and ending point at the same vertex,
that is, e = (A, A), then it is known as a loop

Simple Graph – A graph G(V, E) is known as a simple graph if it does
not contain any loop or parallel edge.

Complete Graph – A graph G(V, E) is known as a complete graph if and only if every vertex in the graph is connected to another vertex and there is no loop on any of the vertex.

Regular Graph – A regular graph is a graph in which every vertex has the same degree. If every vertex has a degree r, then the graph is called a regular graph of degree r.

Multi-graph - A graph G(V, E) is known as a multi-graph if it contains either a loop, parallel edges, or both.

Cycle – It is a path containing one or more edges which start from a particular vertex and also terminate at the same vertex.

Cyclic Graph – A graph which has cycles in it is known as a cyclic graph.

Acyclic Graph – A graph without any cycles is known as an acyclic graph.

Connected Graph – A graph G(V, E) is known as a connected graph if there is a path from any vertex in the graph to another vertex in the graph such that for every pair of distinct vertices, there must be a path.

Strongly Connected Graph – A directed graph is said to be a strongly connected graph if there exists a dedicated path between every pair of vertices in the graph. For example, if there are two vertices, say P and Q, and there is a dedicated path from P to Q, then there must be a path from Q to P.

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


An adjacency matrix is used to represent the information of the vertices
which are adjacent to one another. The two vertices will only be adjacent
when there is an edge connecting those vertices. For any graph G having n
vertices, the dimension of the adjacency matrix will be (n X n).
Thus the memory space needed to represent a graph using it's adjacency matrix is n^2
Let G(V, E) be a graph having vertices V = {V1, V2, V3, …, Vn}, and then the adjacency matrix representation (n X n) will be given by:

aij = [0,1]

where 1 if there is an edge from Vi to Vj, 0 otherwise

The adjacency matrix is also known as a bit matrix or Boolean matrix,
since it contains only 0s and 1s.

An adjacency matrix is often implemented as a two-dimensional array of size NxN
where N is the number of vertices in the graph. n^2 units of memory, which can be prohibitive for large graphs.

The advantage of an adjacency matrix is that testing for the existence of an edge is a simple array lookup that takes O(1) time.

weighted adjacency matrix
The adjacency matrix for a weighted graph will always contain the
weights of the edges connecting the vertices instead of 0 and 1.

multigraph adjacency matrix
The adjacency matrix for an undirected multi-graph will contain the
number of edges connecting the vertices instead of 1.

Extra trivia
The adjacency matrix for an undirected graph is always symmetric
The adjacency matrix for a simple graph having no loops or parallel
edges will always contain 0s on the diagonal.










Adjacency List Representation


An adjacency list is simply a list of edges between vertices in a graph.

In this representation, every vertex is linked to its list of all the other vertices which are adjacent to it.

An adjacency list takes O(n) time to check whether an edge exists because you potentially must iterate over all elements in the list to check for the existence of an edge.

weighted adjacency list
Also includes the weight of an edge in each none head list vertex





The adjacency matrix representation has some major drawbacks. First, it
is very difficult to insert and delete the vertices in/from the graph as the size of the matrix needs to be changed accordingly, which is a very time-consuming
process. Also, sometimes the matrix may contain many zeroes (sparse matrix).
Hence, it is a wasteful representation.

Therefore, adjacency list representation is preferred for representing sparse graphs in the memory. Adjacency list representation makes it easier to add or delete vertices. Also, it shows the adjacent vertices of a particular vertex.



The best representation is often determined by the algorithm being implemented.

Why would you prefer to store a graph as an adjacency matrix?
Why would you prefer an adjacency list?

It is worth noting that if the graph is undirected, where an edge between vertices A ➔ B implies an edge in the reverse direction B ➔ A, then half of an adjacency matrix is wasted space—you don’t need to store both edges when one edge implies the other.

Use a matrix when you have fewer vertices with dense connections
and a list when you have many vertices with sparse connections.

A spanning tree of an undirected and connected graph G is a subgraph which contains all the vertices and edges that connect these
vertices and is a tree. The weights/costs can be assigned to the edges,
and these weights/costs can be used to calculate the weight/cost of the
spanning tree by calculating the sum of the weights/cost of each edge.
A graph can have many spanning trees. Thus, a minimum spanning tree
(MST) is defined as a spanning tree that has weights/costs associated
with the edges such that the total weights/costs of the spanning tree is
at a minimum. Although there are various approaches for determining
an MST, the two most popular approaches for determining a minimum
cost spanning tree of a graph are:
1. Prim’s Algorithm
2. Kruskal’s Algorithm

Prim’s Algorithm
Prim’s algorithm is the algorithm that is used to build a minimum cost
spanning tree. This algorithm works in such a way that it builds a tree edge
by edge. The next edge to be included is chosen according to some criterion.

The steps involved in Prim’s algorithm are:
Step 1: Select a starting vertex/node and add it to the spanning tree.
Step 2: During each iteration, select a vertex/node in such a way that
the edge connecting vertex Vi to another vertex Vj has the minimum cost/
weight assigned to it. Remember, the edge forming a cycle must not be
added.
Step 3: End the process when (n-1) number of edges have been
inserted into the tree.



Kruskal’s Algorithm
Kruskal’s algorithm is another approach for determining the minimum
cost spanning tree of a graph. In this approach also, the tree is built edge by
edge. The next edge to be included is chosen according to some criterion.

The steps involved in Kruskal’s algorithm are:
Step 1: The weights/costs assigned to the edges are sorted in ascending
order.
Step 2: In this step, the lowest weighted/cost edge is added to the tree.
Remember, the edge forming a cycle must not be added.
Step 3: End the process when (n-1) number of edges have been
inserted into the tree.

Topological sort is a procedure to determine the linear ordering of the
nodes of an acyclic directed graph also known as (DAG) in which each node
comes before all those nodes which have zero predecessors. A topological
sort of a DAG is a linear ordering of the vertices of a graph G(V, E) such that
if (a, b) is an edge, then a must appear before b in the topological ordering.
The main idea behind this is that in a graph, if a vertex has in-degree 0, then
that vertex should be selected as the first element in the topological order.
Also, a topological sort is possible only in acyclic directed graphs. An acyclic graph is one which does not have any cycles in it. Topological sorting is
widely used in scheduling tasks, applications, and so on.

Steps
Find the in-degree of every node.
Insert all the nodes/elements having in-degree zero in the queue.
Repeat Steps 5 and 6 until the queue becomes empty.
Delete the first node from the queue by incrementing FRONT by 1.
Repeat for each neighbor P of node N –
  a. Delete the edge from P to M by decreasing the in-degree by 1.
  b. If in-degree of P is zero, then add P to the rear of the queue.

A tree is a non-linear data structure in which the data elements or the nodes are represented in a hierarchical order.

A tree is a recursive data structure consisting of a collection of nodes, which store values and references to trees

The collection can be empty; otherwise, A tree consists of
a distinguished node r, called the root,
zero or more nonempty (sub)trees T1, T2, ... , Tk,

Edges
A subtree root is connected by a directed edge from r.
The root of each subtree is said to be a child of r, and r is the parent of each subtree root.

A tree has N − 1 edges which follows from the fact that
each edge connects some node to its parent
every node except the root has one parent


Node Relationships
Each node is the parent of zero or more child nodes.
A node without a parent is the root node.
Nodes with no children are known as leaves
Nodes with the same parent are siblings
Grandparent and grandchild relations can be defined in a similar manner.


Path
A path from node n1 to nk is defined as a sequence of nodes n1, n2, ... , nk  
such that ni is the parent of ni+1 for 1 ≤ i < k.
path length is the number of edges on the path, namely k − 1.
There is a path of length zero from every node to itself.
There is exactly one path from the root to each tree node.



For any node ni, the depth of ni is the length of the unique path from the root to ni.
Thus, the root is at depth 0.
The height of ni is the length of the longest path from ni to a leaf.
Thus all leaves are at height 0.
The height of a tree is equal to the height of the root.
The depth of a tree is equal to the depth of the deepest leaf; this is always equal to the height of the tree.

If there is a path from n1 to n2, then n1 is an ancestor of n2 and n2 is a descendant of n1.
If n1 ≠ n2, then n1 is a proper ancestor of n2 and n2 is a proper descendant of n1.

Time Complexity

For large amounts of input, the linear access time of linked lists is prohibitive.

There is a data structure for which the running time of most operations is O(logN) on average.
A simple modification also guarantees the above time bound in the worst case
A second modification that essentially gives an O(logN) running time per operation for a long sequence of instructions.

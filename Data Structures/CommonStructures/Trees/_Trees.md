A tree is a non-linear, recursive data structure in which the data elements are represented by a collection of one or more nodes that have a hierarchical order, often called a parent-child relationship.

Tree nodes each have:
a unique key (that identifies the element)
a value (that is the data for an element, often the value is used as the key)
zero or more references to sub-trees

The collection can be empty; otherwise, A tree consists of
a distinguished node r, called the root,
zero or more subtrees T1, T2, ... , Tk,

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
Grandparent, grandchild, and further relations can be defined similarly.


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





There is a distinction between a tree as an abstract data type and as a concrete data structure, analogous to the distinction between a list and a linked list.

As a data type, a tree has a value and children, and the children are themselves trees; the value and children of the tree are interpreted as the value of the root node and the subtrees of the children of the root node. To allow finite trees, one must either allow the list of children to be empty (in which case trees can be required to be non-empty, an "empty tree" instead being represented by a forest of zero trees), or allow trees to be empty, in which case the list of children can be of fixed size (branching factor, especially 2 or "binary"), if desired.

As a data structure, a linked tree is a group of nodes, where each node has a value and a list of references to other nodes (its children). There is also the requirement that no two "downward" references point to the same node. In practice, nodes in a tree commonly include other data as well, such as next/previous references, references to their parent nodes, or nearly anything.

Due to the use of references to trees in the linked tree data structure, trees are often discussed implicitly assuming that they are being represented by references to the root node, as this is often how they are actually implemented. For example, rather than an empty tree, one may have a null reference: a tree is always non-empty, but a reference to a tree may be null.




Terms

Root – The root node is the topmost node of the tree. It does not have a parent node. If the root node is empty, then the tree is empty.

Parent – The parent of a node is the immediate predecessor of that node. In the following figure, X is the parent of the Y and Z nodes.

Child – The child nodes are the immediate successors of a node. They
must have a parent node. A child node placed at the left side is called
the left child, and similarly, a child node placed at the right side is
called a right child. Y is the left child of X and Z is the right child of X.

Leaf / Terminal nodes – A leaf node is one which does not have any
child nodes.

Subtrees – The nodes B, X, and Y form the left subtree of root A.
Similarly, the nodes C and Z form the right subtree of A.

Path – It is a unique sequence of consecutive edges which is required
to be followed to reach the destination from a given source. The path
from root node A to Y is given as A-B, B-Y.

Level number of a node – Every node in the tree is assigned a
level number. The root is at level 0, the children of the root node are
at level 1, and so on.

Height –The height of the tree is the maximum level of the node + 1.
The height of a tree containing a single node will be 1. Similarly, the
height of an empty tree will be 0.

Ancestors – The ancestors of a node are any predecessor nodes on
the path between the root and the destination. There are no ancestors
for the root node.

Descendants – The descendants of a node are any successor nodes
on the path between the given source and the leaf node. There are no
descendants of the leaf node.

Siblings – The child nodes of a given parent node are called siblings.

Degree of a node – It is equal to the number of children that a node has.

Out-degree of a node – It is equal to the number of edges leaving
that node.

In-degree of a node – It is equal to the number of edges arriving at
that node.

Depth – It is given as the length of the path from the root node to the
destination node



Tree Types
General Tree: no constraint imposed on the hierarchy of the tree

Binary Trees: only two children

  Strictly Binary Trees: non-terminal nodes consist of non empty left subtree and right subtree
  Complete Binary Tree: every level, except possibly the last, is completely filled and all nodes appear as far left as possible.
  Extended Binary Trees: (2-tree) each node in the tree has either no child or exactly two children.
  Binary Search Tree: basic ordered binary tree
  AVL: self-balancing binary search tree using height count
  Red-Black Tree: self-balancing binary search tree using 1 bit flag

  Huffman Tree: frequency-sorted binary tree used for lossless data compression
  Splay Tree: self-balanced binary search tree where recently accessed elements are quick to access again

Multiway Trees
  N-ary tree: number of children that a node can have is limited to N
  Multiway Search Trees:
  B-Tree: Ordered self-balancing tree well suited to storage systems

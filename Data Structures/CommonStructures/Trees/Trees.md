Tree Terms and Ideas
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


public abstract class Node {
 private Node[] children;
 public Node( Node[] children ){
 this.children = children;
 }
 public int getNumChildren(){
 return children.length;
 }
 public Node getChild( int index ){
 return children[ index ];
 }
}
public class IntNode extends Node {
 private int value;
 public IntNode( Node[] children, int value ){
 super( children );
 this.value = value;
 }
 public int getValue(){
 return value;
 }
}


Types of Trees

Binary Tree:
A tree in which all nodes have at most two child nodes.

Binary search tree:     (Unique, Ordered binary tree)
Binary Tree  in which there are no duplicate nodes and in which all nodes are arranged in a sorted order

Heap:

trie tree

Self Balancing BST
Red-Black Tree
AVL tree
R-tree

B-tree: A sorted self-balancing tree that allows more than two children per node
A B-Tree is more suitable for reading and writing large sets of data because the height of a B-tree will be smaller than that of an equivalent binary tree.
















Tree Searching

It’s convenient when you have a tree with ordering properties such as various BST or a heap.
A tree without the benefit of ordering, the time to find a node is O(n), so this type of search is best avoided for large trees.

Breadth First Search
a BFS you start with the root, move left to right across the second level, then move left to right across the third level, and so forth. You continue the search until either you have examined all the nodes or you find the node you are searching for. A BFS uses additional memory because it is necessary to track the child nodes for all nodes on a given level while searching that level.

Depth First Search
depth-first search follows one branch of the tree down as many levels as possible until the target node is found or the end is reached. When the search can’t go down any farther, it is continued at the nearest ancestor with unexplored children. DFS has much lower memory requirements than BFS because it is not necessary to store all the child pointers at each level.


If you have additional information on the likely location of your target node, one or the other of these algorithms may be more efficient. For instance, if your node is likely to be in the upper levels of the tree, BFS is most efficient. If the target node is likely to be in the lower levels of the tree, DFS has the advantage that it doesn’t examine any single level last. (BFS always examines the lowest level last.)













Tree Traversal

Another common type of tree problem is called a traversal. A traversal is just like a search, except
that instead of stopping when you find a particular target node, you visit every node in the tree.
Often this is used to perform some operation on each node in the tree. There are many types of traversals, each of which visits nodes in a different order, but you’re most likely to be asked about the
three most common types of depth-first traversals for binary trees:

➤ Preorder — Performs the operation first on the node itself, then on its left descendants, and
finally on its right descendants. In other words, a node is always visited before any of its
children.

➤ Inorder — Performs the operation first on the node’s left descendants, then on the node
itself, and finally on its right descendants. In other words, the left subtree is visited first,
then the node itself, and then the node’s right subtree.

➤ Postorder — Performs the operation first on the node’s left descendants, then on the node’s
right descendants, and finally on the node itself. In other words, a node is always visited
after all its children.

These classes of traversals can also apply to nonbinary trees as long as you have a way to classify
whether a child is “less than” (on the left of) or “greater than” (on the right of) its parent node.
Recursion is usually the simplest way to implement a depth-first traversal.












Heap

Heaps are trees (usually binary trees) where (in a max-heap) each child of a node has a value less than or equal to the node’s own value. (In a min-heap, each child is greater than or equal to its parent.) Consequently, the root node always has the largest value in the tree, which means that you can find the maximum value in constant time: Simply return the root value. Insertion and deletion are still O(log(n)), but lookup becomes O(n). You cannot find the next higher node to a given node in O(log(n)) time or print out the nodes in sorted order in O(n) time as in a BST.

[HeapComplexity.png]












Self-balancing binary search tree

A self-balancing binary search tree (BST) automatically keeps its nodes arranged so as to minimize the height of the tree. The height of a binary search tree is the distance from the root node to the furthest leaf node in the tree. Keeping the height of a BST small also minimizes the time it takes to perform operations on the tree. The automatic balancing of a BST can take a signifi cant amount of time, so not all implementations are strict about minimizing height, tolerating some deviation in the interest of performance. Two popular implementations of self-balancing BSTs are red-black tree and AVL tree.

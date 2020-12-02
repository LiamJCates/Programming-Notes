Binary Tree:
A tree in which all nodes have at most two child nodes.

A binary tree is the simplest form of a tree. A binary tree consists of a
root node and two subtrees known as the left subtree and the right subtree,
where both subtrees are also binary trees.

Binary search tree:     (Unique, Ordered binary tree)
Binary Tree  in which there are no duplicate nodes and in which all nodes are arranged in a sorted order


Each Binary Tree node has three components
A Data Element
A Left Tree Link
A Right Tree Link


A binary tree is a hierchical data structure in which each node has at most
two children, that is, a left and right child. In a binary tree, the degree of each node can be at most two. A binary tree is a popular subtype of a k-ary tree, where k is 2..







There are two types of binary trees:

1. Complete Binary Trees – A complete binary tree is a type of binary
tree which obeys/satisfies two properties:
a. First, every level in a complete binary tree except the last one must
be completely filled.
b. Second, all the nodes in the complete binary tree must appear left as
much as possible.

In a complete binary tree, the maximum number of nodes at level n is
2^n nodes. Also, the total number of nodes in a complete binary tree of depth
d is equal to the sum of all nodes present at each level between 0 and d.


2. Extended Binary Trees – Extended binary trees are also known as 2Ttrees. A binary tree is said to be an extended binary tree if and only if
every node in the tree has either zero children or two children. In an
extended binary tree, nodes having two children are known as internal
nodes. On the contrary, nodes having no children are known as external nodes. In the following figure, the internal nodes are represented by
I and the external nodes are represented by E.






Memory Representation of Binary Trees
Binary trees can be represented in a computer’s memory in either of
the following ways:
1. Array Representation of Binary Trees
2. Linked Representation of Binary Trees360 • Data StructureS anD Program DeSign uSing c++
Now, let us discuss both of them in detail.
Array Representation of Binary Trees
A binary tree is represented using an array in the computer’s memory.
It is also known as sequential representation. Sequential representation of
binary trees is done using one-dimensional (1-D) arrays. This type of representation is static and hence inefficient, as the size must be known in
advance and thus requires a lot of memory space. The following rules are
used to decide the location of each node in the memory:
a. The root node of the tree is stored in the first location.
b. If the parent node is present at location k, then the left child is stored
at location 2k, and the right child is stored at location (2k + 1).
c. The maximum size of the array is given as (2h – 1), where h is the
height of the tree.
For Example – A binary tree is given as follows. Give its array representation in the memory.
FIGURE 8.12. Binary tree and its array representation.treeS • 361
Linked Representation of Binary Trees
A binary tree can also be represented using a linked list in a computer’s memory. This type of representation is dynamic, as memory is
dynamically allocated, that is, when it is needed, and thus it is efficient
and avoids wastage of memory space. In linked representation, every
node has three parts:
1. The first part is called the left pointer, which contains the address of the
left subtree.
2. The second part is called the data part, which contains the information
of the node.
3. The third part is called the right pointer, which contains the address of
the right subtree.
The structure of the node is declared as follows:
struct node
{
struct node *leftchild ;
int information ;
struct node *rightchild ;
}

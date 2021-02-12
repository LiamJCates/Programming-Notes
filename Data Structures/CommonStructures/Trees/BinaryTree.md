Binary Tree:

A binary tree is a tree which satisfies the property:
	tree nodes have at most two children

A binary tree is a non-unique, unordered, hierarchal

A binary tree is also the simplest form of a tree.

A binary tree is a recursive structure that consists of a root node and two subtrees known as the left subtree and the right subtree, where both subtrees are also binary trees.

Each Binary Tree node has three components
A Data Element
A Left Tree Link
A Right Tree Link


The degree of each node can be at most two, formally a binary tree is a popular subtype of a k-ary tree, where k = 2.



## Memory Representation

Binary trees are typically represented in memory in either of the following ways:
	1. Array
	2. Linked


### Array Representation of Binary Trees
A binary tree can be represented using a static or dynamic array, this representation is known as a sequential representation.

Sequential representation of binary trees is done using one-dimensional (1-D) arrays.

When using an array representation is often inefficient, as a simple array requires the maximum size be known in advance or requires a dynamic array which implements move operations when the collection exceeds capacity.

The following rules apply to node array locations:
a. The root node of the tree is stored in the first location.
b. If the parent node is present at location k, then the left child is stored at location 2k, and the right child is stored at location (2k + 1).
c. The maximum size of the array is given as (2h – 1), where h is the
height of the tree.


### Linked Representation of Binary Trees
A binary tree can be represented using a linked list.

This type of representation is dynamic, as memory is dynamically allocated, that is, when it is needed, and thus it is efficient and avoids wastage of memory space. In linked representation, every
node has three parts:
	A data element, which contains the information of the node.
	A pointer, often called leftchild, which contains the address of the left subtree's root.
	A pointer, often called rightchild, which contains the address of the right subtree's root.


The structure of the node is declared as follows:

template <typename T>
class Node
{
	T data;
	class Node *leftchild ;
	class Node *rightchild ;
}



## Additional Tree Properties



### Complete Binary Trees

A complete binary tree is a binary tree which satisfies two properties:
	a. Every level except the last one must be completely filled.
	b. Leaf nodes in the last level must appear as far left as possible.

In a complete binary tree, the maximum number of nodes at level n is 2^n nodes.



### Extended Binary Trees (2-Trees)

A binary tree is said to be an extended binary tree if and only if every node in the tree has either zero children or two children.

In an extended binary tree, nodes having two children are known as internal nodes. On the contrary, nodes having no children are known as external nodes.

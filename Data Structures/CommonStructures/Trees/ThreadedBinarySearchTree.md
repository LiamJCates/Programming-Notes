Inorder traversal of a basic Binary Tree can either be done using recursion or with the use of a auxiliary stack.

The idea of Threaded Binary Trees is to make inorder traversal faster and do it without stack and without recursion.

A Binary Tree is made Threaded by making child pointers that would normally be NULL point to the inorder successor of the node (if it exists).

There are two types of threaded binary trees.

In a binary search tree, there are many nodes that have an empty left child or empty right child or both. We can utilize these fields in such a way so that the empty left child of a node points to its inorder predecessor and empty right child of the node points to its inorder successor.

The successor threads are useful for inorder and preorder traversal
The predecessor threads are useful for reverse inorder and postorder traversal.

Single Threaded:
	Either the empty left child field of a node can be used to point to its inorder predecessor.
	Or the empty right child field of a node can be used to point toits in-order successor.
	Such a type of Binary Tree is also known as a one way threaded binary tree.
	A field that holds the address of its in-order successor is known as thread.

Double Threaded:
	Both the empty left and right child field of a node can be used to point to its inorder predecessor and in-order successor, respectively.
	Such a type of binary tree is known as a threaded binary tree.
	A field that holds the address of its inorder successor or predecessor isknown as thread

In an empty Double Threaded Binary Tree the right child of the header node always points to itself


The threads are also useful for fast accessing ancestors of a node.

In the following diagram:
```
{30, 40, 50, 60, 65, 69, 72, 80}

           60
         /    \
      40        72
     /  \      /  \
   30    50  69    80
```

If this BST was turned into a Single Threaded BST using inorder threads the following thread would be added to the null right child of
30 ➡ 40, 50 ➡ 60, 69 ➡ 80
while 80 has a null right child, there is no inorder successor.

If this BST was turned into a Single Threaded BST using reverse inorder threads the following thread would be added to the null left child of
80 ➡ 72, 69 ➡ 50, 50 ➡ 30
while 30 has a null left child, there is no inorder predecessor.

If this BST was turned into a Double Threaded BST both of the groups of threads above would be added.



To represent the existance of a threaded member we add a boolean data member to the Node class. The right and left pointers are then used for two purposes, the boolean variable rightThread is used to indicate whether right pointer points to right child or inorder successor. Similarly, we can add leftThread for a double threaded binary tree.

```cpp
class Node<T>
{
	T value
	Node<T> * left;
	Node<T> * right;
	// True if left pointer points to predecessor in Inorder Traversal
	bool leftThread;
	// True if right pointer points to successor in Inorder Traversal
	bool rightThread;
};
```

For information about manupulating a Threaded Binary Seach Tree, see:
[Algorithms\Trees\ThreadedBST]

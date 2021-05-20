The AVL tree was invented by Adelson-Velski and Landis in 1962.

The AVL tree is so named in honor of its inventors.

The AVL tree was the first balanced binary search tree. It is a self-balancing binary search tree. The AVL tree is also known as a height-balanced tree because of its property that the heights of the two subtrees of a node can differ at most by one. AVL trees are very efficient in performing searching, insertion, and deletion operations, as they take O(log n) time to perform all these operations.


Need of Height-Balanced Trees
AVL trees are very similar to binary search trees but with a small difference. All AVL tree nodes have a special variable known as a balance factor associated with them.

The balance factor is determined by subtracting the height of the right subtree from the height of the left subtree.

The balance factor is calculated as follows:
Balance Factor = Height(Left sub-tree) – Height(Right sub-tree)

Thus, a node with a balance factor of -1, 0, or 1 is said to be a height-balanced tree.

```
If the balance factor of the tree is 0, then it means that the height of the left and the right subtrees of a node are equal.

Balance Factor 0

	 Node
	/    \
null   null

Balance Factor 0

	 Node
	/    \
Node   Node

If the balance factor of the tree is 1, then it means that the height of the left subtree of that node is one more than the height of its right subtree.

Balance Factor 1

	 Node
	/    \
Node   null


If the balance factor of the tree is -1, then it means that the height of the right subtree of that node is one more than the height of the left subtree of that node.

Balance Factor -1

	 Node
	/    \
null   Node
```

Whenever the balance factor of a node becomes less than -1 or greater than 1 the tree nodes must be reordered so that the balance factors of all nodes fall within the range of -1 <= BF <= 1

The primary need for the height-balanced tree is that the process of searching becomes very fast as benefit of maintaining balancing condition ensures that the depth of the tree is O(logn).


AVL Tree Operations:
[Algorithms\Trees\AVLOperations.md]

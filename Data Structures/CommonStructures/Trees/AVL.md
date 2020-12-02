The AVL tree was invented by Adelson-Velski and Landis in 1962.
The AVL tree is so named in honor of its inventors. The AVL tree was
the first balanced binary search tree. It is a self-balancing binary search
tree. The AVL tree is also known as a height-balanced tree because of its
property that the heights of the two subtrees of a node can differ at most
by one. AVL trees are very efficient in performing searching, insertion,
and deletion operations, as they take O(log n) time to perform all these
operations.


Need of Height-Balanced Trees
AVL trees are very similar to binary search trees but with a small
difference. AVL trees have a special variable known as a balance
factor associated with them. Every node in the AVL tree has a balance
factor associated with it. The balance factor is determined by subtracting
the height of the right subtree from the height of the left subtree. Thus,
a node with a balance factor of -1, 0, or 1 is said to be a height-balanced
tree. The primary need for the height-balanced tree is that the process
of searching becomes very fast. This balancing condition also ensures
that the depth of the tree is O(logn). The balance factor is calculated as
follows:
Balance Factor = Height(Left sub-tree) – Height(Right sub-tree)
•	 If the balance factor of the tree is -1, then it means that the height of
the right subtree of that node is one more than the height of the left
subtree of that node.
•	 If the balance factor of the tree is 0, then it means that the height of
the left and the right subtrees of a node are equal.
•	 If the balance factor of the tree is 1, then it means that the height of
the left subtree of that node is one more than the height of its right
subtree.
Thus, the overall benefit of the height-balanced tree is to assist in fast
searching.


AVL Tree Operations:
[Algorithms\Trees\AVLOperations.md]

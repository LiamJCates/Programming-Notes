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

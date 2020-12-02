B-tree: A sorted self-balancing tree that allows more than two children per node
A B-Tree is more suitable for reading and writing large sets of data because the height of a B-tree will be smaller than that of an equivalent binary tree.


A B-tree is a specialized multi-way tree which is widely used for
disk access. The B-tree was developed in 1970 by Rudolf Bayer and
Ed McCreight. In a B-tree each node may contain large number of
keys. A B-tree is designed to store a large number of keys in a single
node so that the height remains relatively small.

A B-tree of order m has all the properties of a multi-way search tree. In addition, it has the following properties:
1. All leaf nodes are at the bottom level or at the same level.

2. Every node in a B-tree can have at most m children.

3. The root node can have at least two children if it is not a leaf node, and it can obviously have no children if it is a leaf node.

4. Each node in a B-tree can have at least (m/2) children except the root node and the leaf node.

5. Each leaf node must contain at least ceil [(m/2) – 1] keys.


Application of a B-Tree
The main application of a B-tree is the organization of a large amount
of data or a huge collection of records into a file structure. A B-tree should
search the records very efficiently, and all the operations such as insertion,
deletion, searching, and so on should be done very efficiently; therefore,
the organization of records should be very good.

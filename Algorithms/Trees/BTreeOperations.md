Insertion
insertions in a B-tree are done at the leaf-node level.

Insertion Steps:
Step 1 – search the B-tree to find the leaf node where the new key is to be inserted.

Step 2 – If the leaf node is full, that is, if it already contains (m – 1)
keys, then follow these steps:
  i. Insert the new key into the existing set of keys in order.
  ii. Now, the node is split into two halves.
  iii.Finally, push the middle (median) element upward to its parent node.
Also, if the parent node is full, then split the parent node by following
these steps.

Step 3 – If the leaf node is not full, that is, it contains < (m – 1) keys, then insert the new key into the node, keeping the elements of the node
in order.


Deletion
traversal in the B-tree; that is, after reaching a particular node, we can come across two cases which are:
1. Node is a leaf node.
2. Node is not a leaf node.

Now, let us discuss both these cases in detail.
1. Node is a leaf node
If the node has more than a minimum number of keys, then deletion
can be done very easily. But if the node has a minimum number of keys,
then first we will check the number of keys in the adjacent leaf node. If the number of keys in the adjacent node is greater than the minimum number
of keys, then the first key of the adjacent leaf node will go to the parent
node and the key present in the parent node will be combined in a single
leaf node. If the parent node also has less than the minimum number of
keys, then the same steps will be repeated until we get a node which has
more than the minimum number of keys present in it.

2. Node is not a leaf node
In this case the key from the node is deleted, and its place will be occupied by either its successor or predecessor key. If both predecessor and
successor nodes have keys less than the minimum number, then the keys of
the successor and predecessor are combined.

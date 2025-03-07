Insertion
insertions in a binary tree are done at the leaf-node level.

Insertion Steps:
Step 1 – search the binary tree to find the leaf node where the new key is to be inserted.

Step 2 – If the leaf node is full, that is, if it already contains (m – 1)
keys, then follow these steps:
  i. Insert the new key into the existing set of keys in order.
  ii. Now, the node is split into two halves.
  iii.Finally, push the middle (median) element upward to its parent node.
Also, if the parent node is full, then split the parent node by following
these steps.

Step 3 – If the leaf node is not full, that is, it contains < (m – 1) keys, then insert the new key into the node, keeping the elements of the node
in order.

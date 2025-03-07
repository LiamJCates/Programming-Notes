Deletion
traversal in the binary tree; that is, after reaching a particular node, we can come across two cases which are:
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

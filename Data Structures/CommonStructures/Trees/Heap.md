Heaps are trees (usually binary trees) where (in a max-heap) each child of a node has a value less than or equal to the node’s own value. (In a min-heap, each child is greater than or equal to its parent.) Consequently, the root node always has the largest value in the tree, which means that you can find the maximum value in constant time: Simply return the root value. Insertion and deletion are still O(log(n)), but lookup becomes O(n). You cannot find the next higher node to a given node in O(log(n)) time or print out the nodes in sorted order in O(n) time as in a BST.

[HeapComplexity.png]

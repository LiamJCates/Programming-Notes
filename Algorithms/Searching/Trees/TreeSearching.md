Tree Searching

It’s convenient when you have a tree with ordering properties such as various BST or a heap.
A tree without the benefit of ordering, the time to find a node is O(n), so this type of search is best avoided for large trees.

Breadth First Search
a BFS you start with the root, move left to right across the second level, then move left to right across the third level, and so forth. You continue the search until either you have examined all the nodes or you find the node you are searching for. A BFS uses additional memory because it is necessary to track the child nodes for all nodes on a given level while searching that level.

Depth First Search
depth-first search follows one branch of the tree down as many levels as possible until the target node is found or the end is reached. When the search can’t go down any farther, it is continued at the nearest ancestor with unexplored children. DFS has much lower memory requirements than BFS because it is not necessary to store all the child pointers at each level.


If you have additional information on the likely location of your target node, one or the other of these algorithms may be more efficient. For instance, if your node is likely to be in the upper levels of the tree, BFS is most efficient. If the target node is likely to be in the lower levels of the tree, DFS has the advantage that it doesn’t examine any single level last. (BFS always examines the lowest level last.)

### Search for Given Node
The search, or lookup, operation is performed to determine whether a given key value exists in the tree.

As the BST is an ordered binary tree, searching for a given key value is more efficient, and as a result, time is also reduced by a great margin, from O(n) to O(lg n).

The search operation starts at the root node which is made accessible to the function.
If the tree is empty, then the algorithm terminates, returning NULL.
  (The search key value is not present in the tree)
Else If the search key value is equal to the key value of the current node, then the algorithm terminates, returning the ROOT, the current node.
  (The search key value is present in the tree)
Else If the search key value is less than the key value of the current node, make a recursive call passing the left child node.
  (The search key value is required to be in the left subtree by the order property)
Else the search node/key is greater than the key value of the current node:
  make a recursive call passing the right child node.
  (The search key value is required to be in the right subtree by the order property)

SEARCH(ROOT, VALUE)
  IF(ROOT == NULL)
    Print "Value not found"
    Return NULL
  ELSE IF(ROOT -> INFO == VALUE)
    Return ROOT
  ELSE IF(ROOT -> INFO > VALUE)
    SEARCH(ROOT -> LCHILD, VALUE)
  ELSE
    SEARCH(ROOT -> RCHILD, VALUE)

This lookup is fast because on each iteration you eliminate half the remaining nodes from your search by choosing to follow the left subtree or the right subtree. In the worst case, you will know whether the lookup was successful by the time there is only one node left to search.

One important caveat exists in saying that lookup is O(log(n)) in a BST: lookup is only O(log(n)) if you can guarantee that the number of nodes remaining to be searched will be halved or nearly halved on each iteration. Why? Because in the worst case, each node has only one child, in which case you end up with a linked list and lookup becomes an O(n) operation. This worst case may be encountered more commonly than you might expect, such as when a tree is created by adding data already in sorted order.


Binary search trees have other important properties. For example, you can obtain the smallest element by following all the left children and the largest element by following all the right children. The nodes can also be printed out, in order, in O(n) time. Given a node, you can even find the next highest node in O(log(n)) time.

### Search For Largest
We know that it is the basic property of the binary search tree that the largest value always occurs in the extreme right of the right subtree. If there is no right subtree, the value of the root node will be the largest. Hence, to find the largest value in a binary search tree, we will simply find the value of
the node present at the extreme right of the right subtree.

LARGEST_VALUE(ROOT)
  IF(ROOT = NULL OR ROOT -> RCHILD = NULL)
    Return NULL
  ELSE
    Return LARGEST_VALUE(ROOT)

### Search For Smallest
We know that it
is the basic property of the binary search tree that the smallest value always occurs in the extreme left of the left subtree. If there is no left subtree, then the value of the root node will be the smallest. Hence, to find
the smallest value in a binary search tree, we will simply find the value of
the node present at the extreme left of the left subtree.

SMALLEST_VALUE(ROOT
IF(ROOT = NULL OR ROOT -> LCHILD = NULL)
Return NULL
ELSE
Return SMALLEST_VALUE(ROOT)

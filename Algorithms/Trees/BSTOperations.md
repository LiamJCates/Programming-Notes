Binary Search Tree Operations:
•	 Searching a node/key in the binary search tree
•	 Finding the smallest node in the binary search tree
•	 Finding the largest node in the binary search tree
•	 Inserting a node/key in the binary search tree
•	 Deleting a node/key from the binary search tree
•	 Deleting the entire binary search tree
•	 Finding the mirror image of the binary search tree
•	 Determining the height of the binary search tree
•	 Traversal


## Search

### Search for Given Node
This operation is performed to find whether a given key exists in the tree or not.

The searching operation starts at the root node, passed into the function.
If the tree is empty, the search node/key is not present in the tree:
  terminate algorithm, return NULL.
Else If the search node/key is equal to the key value of the current node:
  terminate algorithm, return current node.
Else If the search node/key is less than the key value of the current node:
  make a recursive call passing the left child node.
Else the search node/key is greater than the key value of the current node:
  make a recursive call passing the right child node.

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


## Insertion

The insertion operation is performed to insert a new node with the given value in the binary search tree. The new node is inserted at the correct position following the binary search tree constraint. It should not violate
the property of the binary search tree.

The insertion operation starts at the root node, passed into the function.
If the tree is empty, then we will allocate the memory for the
new node.
Else, we will compare the key value to be inserted with the value stored in the current node.
  If the node/key is equal, the node is not unique and already in the tree, insertion terminates
  Else If the node/key to be inserted is less than the key value of the current node and we insert on the left subtree.
  Else the node/key to be inserted is greater than the key value of the current node and we insert on the right subtree.

INSERT(ROOT, VALUE)
  IF(ROOT == NULL)
    Allocate memory for ROOT node:
      Set ROOT -> DATA = VALUE
      Set ROOT -> LCHILD = ROOT -> RCHILD = NULL
  ELSE IF(ROOT -> DATA > VALUE)
    INSERT(ROOT -> LCHILD, VALUE)
  ELSE
    INSERT(ROOT -> RCHILD, VALUE)

## Deletion

### Node Deletion
The deletion operation is performed to delete a node with a given key value from the binary search tree.

The deletion operation is handled in three cases by which we delete nodes with zero, one or two children

Zero Children
This is the simplest case of deletion, as we can directly remove or delete
a node which has no children.

One Child
In this case of deletion, the node which is to be deleted, the parent
node, is simply replaced by its child node.

Two Children
In this case, the node which is to be deleted is simply replaced by its in-order predecessor, that is, the largest value in the left subtree, or by its in-order successor, that is, the smallest value in the right subtree.
The deletion of the in-order predecessor or in-order successor is handled using the method presented by the previous two cases.

A tree root and a node/key to be deleted is passed into deletion operation
If the current node is null the tree is empty:
  indicate an error
Else we traverse the tree searching for the deletion node/key
  If the deletion node/key is smaller than the root node/key:
    make a recursive call on the left child
  Else if the deletion node/key is larger than the root node/key:
    make a recursive call on the left child
  Else the current node is larger nor smaller and thus must be the deletion key:
    If both children are null, handle first deletion case, zero children:
      Delete/Free Root
    Else If neither child is NULL, handle third deletion case, two children:
      Find either the in-order predecessor or in-order successor
      replace root key/value with the found key/value
      free/delete the found in-order predecessor or in-order successor
    Else only a single child exists:
      If the left child is not empty:
        replace root key/value/link with the left child key/value/link
        free original left child
      Else the right child is not empty:
        replace root key/value/links with the right child key/value/links
        free original right child


DELETE_NODE(ROOT, VALUE)
  IF(ROOT == NULL)
    Print "Error"
  ELSE
    IF(ROOT -> INFO > VALUE)
      DELETE_NODE(ROOT -> LCHILD, VALUE)
    ELSE IF(ROOT -> INFO < VALUE)
      DELETE_NODE(ROOT -> RCHILD, VALUE)
    ELSE
      IF(ROOT -> LCHILD = NULL & ROOT -> RCHILD == NULL)
        FREE(ROOT)
      ELSE IF(ROOT -> LCHILD & ROOT -> RCHILD)
        TEMP = FIND_LARGEST(ROOT -> LCHILD)
        OR
        TEMP = FIND_SMALLEST(ROOT -> RCHILD)
        Set ROOT -> INFO = TEMP -> INFO
        FREE(TEMP)
      ELSE
        IF(ROOT -> LCHILD != NULL)
          Set TEMP = ROOT -> LCHILD
          Set ROOT -> INFO = TEMP -> INFO
          FREE(TEMP)
        ELSE
          Set TEMP = ROOT -> RCHILD
          Set ROOT -> INFO = TEMP -> INFO
          FREE(TEMP)

### Tree Deletion
Used to delete or free all members of an entire binary search tree.

If the tree is not empty, root != null
  Make a recursive call on the left and right subtrees
  The root node is freed/deleted

This ensures that all subtree members are freed before the current node

DELETE_BST(ROOT)
  IF(ROOT != NULL)
    DELETE_BST(ROOT -> LCHILD)
    DELETE_BST(ROOT -> RCHILD)
    FREE(ROOT)


## Mirror
The mirror operation is used to interchange the right subtree
with the left subtree at each tree node.

If the tree is not empty
  make a recursive call on the left child
  make a recursive call on the right child
  (or vice versa)
  Swap the root's left and right child

MIRROR_IMAGE(ROOT)
  IF(ROOT != NULL)
    MIRROR_IMAGE(ROOT -> LCHILD)
    MIRROR_IMAGR(ROOT -> RCHILD)
    Set TEMP = ROOT -> LEFT
    ROOT -> LEFT = ROOT -> RIGHT
    Set ROOT -> RIGHT = TEMP


## Height
The height of a binary search tree can easily be determined. We will first calculate the heights of the left subtree and the right subtree. Whichever height is greater, 1 is added to that height

CALCULATE_HEIGHT(ROOT)
  IF ROOT = NULL
    Return 0;
  ELSE
    Set LHEIGHT = CALCULATE_HEIGHT(ROOT -> LCHILD)
    Set RHEIGHT = CALCULATE_HEIGHT(ROOT -> RCHILD)
    Return MAX(LHEIGHT, RHEIGHT) + 1

## Traversal
Traversing is the process of visiting each node in the tree exactly once
in a particular order. We all know that a tree is a non-linear data structure,
and therefore a tree can be traversed in various ways. There are three types
of traversals, which are:
•	 Pre-Order Traversal
•	 In-Order Traversal
•	 Post-Order Traversal

### Pre-Order
In pre-order traversal, the following operations are performed recursively at each node:
1. Visit the root node.
2. Traverse the left subtree.
3. Traverse the right subtree.

The word “pre” in pre-order determines that the root node is accessed
before accessing any other node in the tree. Hence, it is also known as a
DLR traversal, that is, Data Left Right.

PREORDER(ROOT)
  IF ROOT != NULL
    Print ROOT->VALUE
    PREORDER(ROOT->LCHILD)
    PREORDER(ROOT->RCHILD)

### In-Order
In in-order traversal, the following operations are performed recursively
at each node:
1. Traverse the left subtree.
2. Visit the root node.
3. Traverse the right subtree.
The word “in” in “in-order” determines that the root node is accessed in
between the left and the right subtrees. Hence, it is also known as an LDR
traversal, that is, Left Data Right.

INORDER(ROOT)
  IF ROOT != NULL
    INORDER(ROOT->LCHILD)
    Print ROOT->VALUE
    INORDER(ROOT->RCHILD)

### Post-Order
In a post-order traversal, the following operations are performed recursively at each node:
1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the root node.
The word “post” in post-order determines that the root node will
be accessed last after the left and the right subtrees. Hence, it is also
known as an LRD traversal, that is, Left Right Data.

POSTORDER(ROOT)
  IF ROOT != NULL
    POSTORDER(ROOT->LCHILD)
    POSTORDER(ROOT->RCHILD)
    Print ROOT->VALUE


## Creating a Binary Tree Using Traversal Methods
A binary tree can be constructed if we are given at least two of the
traversal results, provided that one traversal should always be an in-order
traversal and the second is either a pre-order traversal or a post-order traversal. An in-order traversal determines the left and right child nodes of the
binary tree. A Pre-order or post-order traversal determines the root node
of the binary tree. Hence, there are two different ways of creating a binary
tree, which are:
1. In-order and pre-order traversal
2. In-order and post-order traversal

If we have pre-order and in-order traversal sequences. Then, the
following steps are followed to construct a binary tree:

Step 1: The pre-order traversing sequence is used to determine the
root node of the binary tree. The first node in the pre-order sequence will
be the root node.

Step 2: The in-order traversing sequence is used to determine the left
and the right subtrees of the binary tree. Keys toward the left side of the
root node in the in-order sequence form the left subtree. Similarly, keys
toward the right side of the root node in the in-order sequence form the
right subtree.

Step 3: Now, each element from the pre-order traversing sequence is
recursively selected and the left and the right subtrees are created from the
in-order traversing sequence.

NOTE:
This process is the same for the post-order however the element latest in the post-order sequence is the root node

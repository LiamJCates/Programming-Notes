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

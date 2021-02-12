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

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

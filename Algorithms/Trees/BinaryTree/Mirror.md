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

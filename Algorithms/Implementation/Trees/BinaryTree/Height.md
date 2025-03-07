## Height
The height of a tree (binary or not) is defined to be the number of nodes along the longest path from the root node to any leaf node.

The height of a binary tree can easily be determined. We will first calculate the heights of the left subtree and the right subtree. Whichever height is greater, 1 is added to that height

CALCULATE_HEIGHT(ROOT)
  IF ROOT = NULL
    Return 0;
  ELSE
    Set LHEIGHT = CALCULATE_HEIGHT(ROOT -> LCHILD)
    Set RHEIGHT = CALCULATE_HEIGHT(ROOT -> RCHILD)
    Return MAX(LHEIGHT, RHEIGHT) + 1

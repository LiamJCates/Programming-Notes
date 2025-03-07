AVL Operations:
Search
Insert
Delete

## Searching
The process of searching a node in an AVL tree is the same as for a
binary search tree.


## Insertion
The process of inserting a new node in an AVL tree is quite similar to
that of binary search trees. The new node is always inserted as a terminal/
leaf node in the AVL tree. But the insertion of a new node can disturb the
balance of the AVL tree, as the balance factor may be disturbed.

Thus, for the tree to remain balanced, the insertion process is followed by a balance factor check for every node.

If the balance factor of all nodes is
  within the range -1 <= BF <= 1, then there is nothing more to be done.
  out of the range -1 <= BF <= 1 then a suitabe Rotation is made


### AVL Rotations
Rotations are used to preserve the balance porperty of the tree

For any node that is inserted the balance factor us 0, as it will be a leaf node with no children. Hence, the nodes whose balance factors will be disturbed are the ones which lie in the path of the root node to the newly inserted node.

So, we will perform the rotation process only on those nodes whose balance factors will be disturbed. In the rotation process, our first work is to find the critical node in the AVL tree.

The critical node is the nearest ancestor node from the newly inserted node to the root node which does not have a balance factor of -1, 0, or 1.

There are four types of rotations which are:
1. Left-Left Rotation (LL Rotation) – New node is inserted in the left
subtree of the left subtree of the critical node.
a
 \
  b
   \
    c

Where c has BF of 0, b has BF of -1, and a has BF of -2

2. Right-Right Rotation (RR Rotation) – New node is inserted in the
right subtree of the right subtree of the critical node.
    c
   /
  b
 /
a

Where a has BF of 0, b has BF of 1, and c has BF of 2

3. Right-Left Rotation (RL Rotation) – New node is inserted in the left
subtree of the right subtree of the critical node.
  c
 /
a
 \
  b

Where b has BF of 0, a has BF of -1, and c has BF of -2

4. Left-Right Rotation (LR Rotation) – New node is inserted in the right
subtree of the left subtree of critical node.
a
 \
  c
 /
b

Where b has BF of 0, c has BF of 1, and a has BF of -2

After rotations all trees will have the form

  b
 / \
a   c


When to rotate

A tree rotation is necessary when you have inserted or deleted a node which leaves the tree in an unbalanced state.  An unbalanced state is defined as a state in which any subtree has a balance factor of greater than 1, or less than -1.  That is, any tree with a difference between the heights of its two subtrees greater than 1, is considered unbalanced.

A node with a balance factor of < 0 is called left-heavy
A node with a balance factor of > 0 is called right-heavy
A node with a balance factor == 0 is called balanced


IF tree is right heavy
  IF tree's right subtree is left heavy
    Perform Double Left rotation
  ELSE
    Perform Single Left rotation
ELSE IF tree is left heavy
  IF tree's left subtree is right heavy
    Perform Double Right rotation
  ELSE
    Perform Single Right rotation

#### Height
HEIGHT(ROOT)
  RETURN ROOT == NULL ? -1 : ROOT->HEIGHT

#### LL Rotation
LL_ROTATION(ROOT)
  TEMP = ROOT->LEFT
  ROOT->LEFT = TEMP->RIGHT
  TEMP->RIGHT = ROOT
  ROOT->HEIGHT = MAX(HEIGHT(ROOT->LEFT), HEIGHT(ROOT->RIGHT))+1
  TEMP->HEIGHT = MAX(HEIGHT(TEMP->LEFT), ROOT->HEIGHT)+1

  RETURN TEMP

#### RR Rotation
RR_ROTATION(ROOT)
  TEMP = ROOT->RIGHT
  ROOT->RIGHT = TEMP->LEFT
  TEMP->LEFT = ROOT

  ROOT->HEIGHT = MAX(HEIGHT(ROOT->LEFT), HEIGHT(ROOT->RIGHT))+1
  TEMP->HEIGHT = MAX(HEIGHT(TEMP->RIGHT), ROOT->HEIGHT)+1

  RETURN TEMP

#### RL Rotation
RL_ROTATION(ROOT)
  ROOT->RIGHT = LL_ROTATION(ROOT->RIGHT)
  ROOT = RR_ROTATION(ROOT)

  RETURN ROOT

#### LR Rotation
LR_ROTATION(ROOT)
  ROOT->LEFT = RR_ROTATION(ROOT->LEFT)
  ROOT = LL_ROTATION(ROOT)

  RETURN ROOT


#### BALANCE

BALANCE(ROOT)  
  LHEIGHT = (!ROOT->LEFT) ? 0 : ROOT->LEFT->HEIGHT + 1
  RHEIGHT = (!ROOT->RIGHT) ? 0 : ROOT->RIGHT->HEIGHT + 1

  BALANCEFACTOR = LHEIGHT - RHEIGHT;

  IF(BALANCEFACTOR  < 2 && BALANCEFACTOR > -2)
    return ROOT;
  ELSE IF(BALANCEFACTOR == 2)
    return ( HEIGHT(ROOT->LEFT->LEFT) > HEIGHT(ROOT->LEFT->RIGHT) ) ? LL_ROTATION(ROOT): LR_ROTATION(ROOT);
  ELSE
    return ( HEIGHT(ROOT->RIGHT->RIGHT) > HEIGHT(ROOT->RIGHT->LEFT) ) ?
    RR_ROTATION(p) : RL_ROTATION(p)


#### INSERT
INSERT(ROOT, VALUE)
  IF(ROOT == NULL)
    Allocate memory for ROOT node
    Set ROOT -> INFO = VALUE
    Set ROOT -> LCHILD = ROOT -> RCHILD = NULL
  ELSE IF(VALUE > ROOT -> DATA)
    INSERT(ROOT->RIGHT, VALUE)
  ELSE
    INSERT(ROOT->LEFT, VALUE)
  ROOT->HEIGHT = MAX(HEIGHT(ROOT->LEFT), HEIGHT(ROOT->RIGHT)) + 1

  ROOT = BALANCE(ROOT)

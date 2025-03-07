
## Traversal
Tree Traversal is the process of visiting each node in the tree exactly once
in a particular order.

A traversal is just like a search, except that instead of stopping when you find a particular target node, you visit every node in the tree.

Often this is used to perform some operation on each node in the tree.


We all know that a tree is a non-linear data structure, and therefore a tree can be traversed in various ways, each of which visits nodes in a different order

You’re most likely to be asked about the three most common types of depth-first traversals for binary trees:
•	 Pre-Order Traversal
•	 In-Order Traversal
•	 Post-Order Traversal

These classes of traversals can also apply to nonbinary trees as long as you have a way to classify whether a child is “less than” (on the left of) or “greater than” (on the right of) its parent node.


### Pre-Order
Performs the operation first on the node itself, then on its left descendants, and finally on its right descendants.

The word “pre” in pre-order determines that the root node is accessed
before accessing any other node in the tree. Hence, it is also known as a
DLR traversal, that is, Data Left Right.

In pre-order traversal, the following operations are performed recursively at each node:
	1. Visit the root node.
	2. Traverse the left subtree.
	3. Traverse the right subtree.

PREORDER(ROOT)
  IF ROOT != NULL
    Print ROOT->VALUE
    PREORDER(ROOT->LCHILD)
    PREORDER(ROOT->RCHILD)



### In-Order
Performs the operation first on the node’s left descendants, then on the node itself, and finally on its right descendants.

The word “in” in “in-order” determines that the root node is accessed in
between the left and the right subtrees. Hence, it is also known as an LDR
traversal, that is, Left Data Right.

In in-order traversal, the following operations are performed recursively
at each node:
1. Traverse the left subtree.
2. Visit the root node.
3. Traverse the right subtree.

INORDER(ROOT)
  IF ROOT != NULL
    INORDER(ROOT->LCHILD)
    Print ROOT->VALUE
    INORDER(ROOT->RCHILD)



### Post-Order
Performs the operation first on the node’s left descendants, then on the node’s right descendants, and finally on the node itself.

The word “post” in post-order determines that the root node will
be accessed last after the left and the right subtrees. Hence, it is also
known as an LRD traversal, that is, Left Right Data.

In a post-order traversal, the following operations are performed recursively at each node:
1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the root node.

POSTORDER(ROOT)
  IF ROOT != NULL
    POSTORDER(ROOT->LCHILD)
    POSTORDER(ROOT->RCHILD)
    Print ROOT->VALUE




### Iterative Implementation
Recursion as used in the methods above is usually the simplest way to implement a depth-first traversal.

Recursion implicitly uses a stack data structure by placing data on the call stack. That means there should be an equivalent solution that avoids recursion by explicitly using a stack.

You can explicitly store the same data on a stack for iterative implementations


To summarize, the algorithm prints the value of the current node, pushes the right child onto an
implicit stack, and moves to the left child. The algorithm pops the stack to obtain a new current
node when there are no more children (when it reaches a leaf). This continues until the entire tree
has been traversed and the stack is empty.
Before implementing this algorithm, first remove any unnecessary special cases that would make
the algorithm more difficult to implement. Instead of coding separate cases for the left and right
children, why not push pointers to both nodes onto the stack? Then all that matters is the order in
which the nodes are pushed onto the stack: you need to find an order that enables you to push both
nodes onto the stack so that the left node is always popped before the right node.
Because a stack is a last-in-first-out data structure, push the right node onto the stack first, followed
by the left node. Instead of examining the left child explicitly, simply pop the first node from the
stack, print its value, and push both of its children onto the stack in the correct order. If you start
the procedure by pushing the root node onto the stack and then pop, print, and push as described,
you can emulate the recursive preorder traversal. To summarize:
Create the stack
Push the root node on the stack
While the stack is not empty
Pop a node
Print its value
If right child exists, push the node's right child
If left child exists, push the node's left child
The code (with no error checking) for this algorithm is as follows:
void preorderTraversal( Node root ){
Stack<Node> stack = new Stack<Node>();
stack.push( root );
while( !stack.empty() ){
Node curr = stack.pop();
curr.printValue();
Node n = curr.getRight();
if ( n != null ) stack.push( n );
n = curr.getLeft();
if ( n != null ) stack.push( n );
}
}

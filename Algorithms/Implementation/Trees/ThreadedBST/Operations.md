Operations

Search
Insertion
Traversal
Deletion



### Data Structure
``` cpp
class Node
{
	int value;
	Node *left;
	Node *right;
	//True if left pointer points to predecessor in Inorder Traversal
	bool lThread;
	//True if right pointer points to successor in Inorder Traversal
	bool rThread;
};
```


### Search
Like standard BST, we search for the key value in the tree. For a standard BST search terminates either when we find the key or when we reach a NULL left or right pointer.

The difference for the TBST is that all left and right NULL pointers are replaced by threads except left pointer of first node and right pointer of last node. During search of a TBST will be unsuccessful when we reach a NULL pointer or a thread.


### Insertion

Let tmp be the newly inserted node. There can be three cases during insertion:

#### Case 1: Insertion in empty tree
Both left and right pointers of tmp will be set to NULL and new node becomes the root.

root = tmp;
tmp -> left = NULL;
tmp -> right = NULL;

#### Case 2: When new node inserted as the left child
After inserting the node at its proper place we have to make its left and right threads points to inorder predecessor and successor respectively. The node which was inorder successor. So the left and right threads of the new node will be-

tmp -> left = par ->left;
tmp -> right = par;

Before insertion, the left pointer of parent was a thread, but after insertion it will be a link pointing to the new node.

par -> lThread = false;
par -> left = temp;

Following example show a node being inserted as left child of its parent.

#### Case 3: When new node is inserted as the right child
The parent of tmp is its inorder predecessor. The node which was inorder successor of the parent is now the inorder successor of this node tmp. So the left and right threads of the new node will be-

tmp -> left = par;
tmp -> right = par -> right;

Before insertion, the right pointer of parent was a thread, but after insertion it will be a link pointing to the new node.

par -> rThread = false;
par -> right = tmp;




Like standard BST insert, we search for the key value in the tree. If key is already present, then we return otherwise the new key is inserted at the point where search terminates. In BST, search terminates either when we find the key or when we reach a NULL left or right pointer. Here all left and right NULL pointers are replaced by threads except left pointer of first node and right pointer of last node. So here search will be unsuccessful when we reach a NULL pointer or a thread.

```cpp
// Insertion in Threaded Binary Search Tree.
#include <iostream>
using namespace std;

// Insert a Node in Binary Threaded Tree
struct Node *insert(struct Node *root, int ikey)
{
    // Searching for a Node with given value
    Node *ptr = root;
    Node *par = nullptr; // Parent of key to be inserted
    while (ptr != nullptr)
    {
        // If key already exists, return
        if (ikey == (ptr->value))
        {
            printf("Duplicate Key !\n");
            return root;
        }

        par = ptr; // Update parent pointer

        // Moving on left subtree.
        if (ikey < ptr->value)
        {
            if (ptr->lThread == false)
                ptr = ptr->left;
            else
                break;
        }

        // Moving on right subtree.
        else
        {
            if (ptr->rThread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    // Create a new node
    Node *tmp = new Node;
    tmp->value = ikey;
    tmp->lThread = true;
    tmp->rThread = true;

		//Insertion into empty tree
    if (par == nullptr)
    {
        root = tmp;
        tmp->left = nullptr;
        tmp->right = nullptr;
    }
    //Inserted as left child
    else if (ikey < (par->value))
    {
				//predecessor of the parent node becomes predecessor of the child
        tmp->left = par->left;
				//Parent is sucessor of the child
				//as the new child is the greatest node value less than the parent
        tmp->right = par;
				//Left child of the parent is no longer a thread
        par->lThread = false;
				//new child is now the left child of the parent node
        par->left = tmp;
    }
		//Inserted as right child
    else
    {
				//Parent is predecessor of the child
				//as the new child is the least node value greater than the parent
        tmp->left = par;
				//sucessor of the parent becomes the sucessor of the child
        tmp->right = par->right;
				//Right child of the parent is no longer a thread
        par->rThread = false;
				//new child is now the right child of the parent
        par->right = tmp;
    }

    return root;
}

// Driver Program
int main()
{
    struct Node *root = nullptr;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);

    return 0;
}
```


### Traversal


```cpp
// Returns inorder successor using rThread
struct Node *inorderSuccessor(struct Node *ptr)
{
    // If rThread is set, we can quickly find
    if (ptr->rThread == true)
        return ptr->right;

    // Else return leftmost child of right subtree
    ptr = ptr->right;
    while (ptr->lThread == false)
        ptr = ptr->left;
    return ptr;
}

// Printing the threaded tree
void inorder(struct Node *root)
{
    if (root == nullptr)
        printf("Tree is empty");

    // Reach leftmost node
    struct Node *ptr = root;
    while (ptr->lThread == false)
        ptr = ptr->left;

    // One by one print successors
    while (ptr != nullptr)
    {
        printf("%d ", ptr->value);
        ptr = inorderSuccessor(ptr);
    }
}

```



### Deletion




In deletion, first the key to be deleted is searched, and then there are differenct cases for deleting the Node in which key is found.

##### Case A: Leaf Node need to be deleted

In BST, for deleting a leaf Node the left or right pointer of parent was set to NULL.


In a TBST, instead of setting the pointer to NULL it is made a thread.

There are three cases for the deletion of a leaf node:
 	The leaf is the root
	The leat is the left child
	The leaf is the left child


if the leaf Node to be deleted is the root
root = nullptr;


if the leaf Node to be deleted is left child of its parent then after deletion, left pointer of parent should become a thread pointing to its predecessor of the parent Node after deletion.

par -> lthread = true;
par -> left = ptr -> left;


If the leaf Node to be deleted is right child of its parent then after deletion, right pointer of parent should become a thread pointing to its successor. The Node which was inorder successor of the leaf Node before deletion will become the inorder successor of the parent Node after deletion.

par->rThread = true;
par->right = ptr->right;


#### Case B: Node to be deleted has only one child
After deleting the Node as in a BST, the inorder successor and inorder predecessor of the Node are found.

```cpp
s = inSucc(ptr); // Returns inorder successor using left and right children
p = inPred(ptr); // Returns inorder predecessor using left and right children
```

There are two cases for the deletion of a non-leaf node with a single subtree:
	has left subtree
	has right subtree


If Node to be deleted has a left subtree, then after deletion the right thread of its predecessor should point to its successor.

p->left = s;


If Node to be deleted has a right subtree, then after deletion the left thread of its successor should point to its prredecessor.

s->left = p;


#### Case C: Node to be deleted has two children
We find inorder successor of Node ptr (Node to be deleted) and then copy the information of this successor into Node ptr. After this inorder successor Node is deleted using either Case A or Case B.



```cpp
// Complete C++ program to demonstrate deletion
// in threaded BST
#include <iostream>
using namespace std;

//See data structure above
struct Node;

// Insert a Node in Binary Threaded Tree
struct Node *insert(struct Node *root, int ikey);
//See insertion above

// Printing the threaded tree
void inorder(struct Node *root);
//See Traversal above


// Returns inorder successor using left and right children (Used in deletion)
struct Node *inSucc(struct Node *ptr)
{
    if (ptr->rThread == true)
        return ptr->right;

    ptr = ptr->right;
    while (ptr->lThread == false)
        ptr = ptr->left;

    return ptr;
}

// Returns inorder predecessor using left and right children (Used in deletion)
struct Node *inPred(struct Node *ptr)
{
    if (ptr->lThread == true)
        return ptr->left;

    ptr = ptr->left;
    while (ptr->rThread == false)
        ptr = ptr->right;
    return ptr;
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
struct Node *caseA(struct Node *root, struct Node *par,
                   struct Node *ptr)
{
    // If Node to be deleted is root
    if (par == nullptr)
        root = nullptr;

    // If Node to be deleted is left
    // of its parent
    else if (ptr == par->left)
    {
        par->lThread = true;
        par->left = ptr->left;
    }
    else
    {
        par->rThread = true;
        par->right = ptr->right;
    }

    // Free memory and return new root
    free(ptr);
    return root;
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
struct Node *caseB(struct Node *root, struct Node *par,
                   struct Node *ptr)
{
    struct Node *child;

    // Initialize child Node to be deleted has
    // left child.
    if (ptr->lThread == false)
        child = ptr->left;

    // Node to be deleted has right child.
    else
        child = ptr->right;

    // Node to be deleted is root Node.
    if (par == nullptr)
        root = child;

    // Node is left child of its parent.
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;

    // Find successor and predecessor
    Node *s = inSucc(ptr);
    Node *p = inPred(ptr);

    // If ptr has left subtree.
    if (ptr->lThread == false)
        p->right = s;

    // If ptr has right subtree.
    else
    {
        if (ptr->rThread == false)
            s->left = p;
    }

    free(ptr);
    return root;
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
struct Node *caseC(struct Node *root, struct Node *par,
                   struct Node *ptr)
{
    // Find inorder successor and its parent.
    struct Node *parsucc = ptr;
    struct Node *succ = ptr->right;

    // Find leftmost child of successor
    while (succ->lThread == false)
    {
        parsucc = succ;
        succ = succ->left;
    }

    ptr->info = succ->info;

    if (succ->lThread == true && succ->rThread == true)
        root = caseA(root, parsucc, succ);
    else
        root = caseB(root, parsucc, succ);

    return root;
}

// Deletes a key from threaded BST with given root and
// returns new root of BST.
struct Node *delThreadedBST(struct Node *root, int dkey)
{
    // Initialize parent as nullptr and ptrent
    // Node as root.
    struct Node *par = nullptr, *ptr = root;

    // Set true if key is found
    int found = 0;

    // Search key in BST : find Node and its
    // parent.
    while (ptr != nullptr)
    {
        if (dkey == ptr->info)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->info)
        {
            if (ptr->lThread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rThread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    if (found == 0)
        printf("dkey not present in tree\n");

    // Two Children
    else if (ptr->lThread == false && ptr->rThread == false)
        root = caseC(root, par, ptr);

    // Only Left Child
    else if (ptr->lThread == false)
        root = caseB(root, par, ptr);

    // Only Right Child
    else if (ptr->rThread == false)
        root = caseB(root, par, ptr);

    // No child
    else
        root = caseA(root, par, ptr);

    return root;
}

// Driver Program
int main()
{
    struct Node *root = nullptr;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);

    root = delThreadedBST(root, 20);
    inorder(root);

    return 0;
}
```

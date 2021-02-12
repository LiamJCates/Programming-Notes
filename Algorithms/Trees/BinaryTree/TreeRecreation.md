## Creating a Binary Tree Using Traversal Methods
A binary tree can be constructed if we are given at least two of the
traversal results, an in-order and either a pre or post-order traversal.

	pre or post-order traversal sequence indicates the root node
	in-order traversal sequence indicates left and right children of each node

The following steps are used to re-construct the binary tree:

	1. Root Node
		The first node in a pre-order sequence will be the root node.
		The last node is a post-order sequence will be the root node.

	2. left and right subtrees
		Keys toward the left side of the root node in the in-order sequence form the left subtree. Similarly, keys toward the right side of the root node in the in-order sequence form the right subtree.

	3. Each element from the pre-order traversing sequence is recursively selected and the left and the right subtrees are created from the in-order traversing sequence.

NOTE:
This process is the same for the post-order however the element latest in the post-order sequence is the root node


Algorithm: buildTree()
1) Pick an element from Preorder.
	Increment a Preorder Index Variable (preIndex in below code) to pick next element in next recursive call.
2) Create a new tree node tNode with the selected element.

3) Find the picked element’s index in Inorder. Let the index be inIndex.

4) Recursively call buildTree for the left subtree elements, those with an index less than inIndex.

5) Recursively call buildTree for the right subtree elements, those with an index greater than inIndex.

6) return tNode.



/*
A binary tree node has:
	some datatype representing the collection element data,
	a left child pointer
	a right child pointer
*/
template <typename T>
class node
{
    public:
    T data;
    node* left;
    node* right;
		node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
int search(T arr[], int strt, int end, T value)
{
    for (int i = strt; i <= end; i++)
			if (arr[i] == value)
      	return i;
}

/*
Recursive function to construct binary of size len from Inorder traversal in[]
and Preorder traversal pre[].
Initial values of inStrt and inEnd should be 0 and len -1.
*/
template <typename T>
node* buildTree(T in[], T pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

		// Pick current node from Preorder traversal using preIndex and increment
    node* tNode = new node(pre[preIndex++]);

    // If this node has no children then return
    if (inStrt == inEnd)
        return tNode;

    // Else find the index of this node in Inorder traversal
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    // Using index in Inorder traversal, construct left and right subtress
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

/* Driver code */
template <typename T>
int main()
{
  T in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
  T pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
  int len = sizeof(in) / sizeof(in[0]);
  node* root = buildTree(in, pre, 0, len - 1);
}

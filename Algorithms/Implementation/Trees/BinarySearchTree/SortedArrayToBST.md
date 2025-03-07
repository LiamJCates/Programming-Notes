Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

1) Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.

Given:
arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]


int size = 10
int start = 0;
int end = 10;

The middle of an array is the average of the start and end index:

ind middle = (end + start) / 2;

We create the root node with the value of arr[middle]

We split the array into a left and right subarray

The left subarray:    arr[start, mid - 1]
The right subarray:   arr[mid + 1, end]

We recursively construct the left and right child of the root by finding the middle element of these arrays.






```cpp
#include <iostream>

using namespace std;
/* A Binary Tree node */
class TNode
{
public:
  int data;
  TNode *left;
  TNode *right;

  TNode(int data) : data(data), left(nullptr), right(nullptr){};
};

/* Constructs Balanced Binary Search Tree from a sorted array */
TNode *sortedArrayToBST(int arr[], int start, int end)
{
  /* Base Case */
  if (start > end) return nullptr;

  /* Get the middle element and make it root */
  int mid = (start + end) / 2;
  TNode *root = new TNode(arr[mid]);

  /* Recursively construct the left subtree of root */
  root->left = sortedArrayToBST(arr, start, mid - 1);

  /* Recursively construct the right subtree of root */
  root->right = sortedArrayToBST(arr, mid + 1, end);

  return root;
}

/* A utility function to print
preorder traversal of BST */
void inOrder(TNode *node)
{
  if (!node) return;

  inOrder(node->left);
  cout << node->data << " ";
  inOrder(node->right);
}

// Driver Code
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  /* Convert List to BST */
  TNode *root = sortedArrayToBST(arr, 0, n - 1);
  cout << "Inorder Traversal of constructed BST: ";
  inOrder(root);
  cout << endl;

  return 0;
}
```

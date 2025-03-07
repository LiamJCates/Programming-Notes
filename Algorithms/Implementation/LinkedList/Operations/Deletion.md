
Write a linked list node deletion function for a situation in which you are only provided a pointer to the node to be deleted and are not given access to the head of the linked list.

The solution is simply to copy the data from the next node over to the current node, and then to delete the next node.

The code below implements this algorithm.

```c++

bool deleteNode(LinkedListNode *node)
{
	if (node == nullptr || node->next == nullptr) {
		return false; // Failure
	}

	LinkedListNode *toDelete = node->next;
	node->data= toDelete->data;
	node->next = toDelete->next;

	/*
		//if the nodes are allocated on the heap via the new operation
		toDelete->next = nullptr;
		delete toDelete;
	*/

	return true;
}
```

Note that this problem cannot be solved if the node to be deleted is the last node in the linked list. That's okay - your interviewer wants you to point that out, and to discuss how to handle this case. You could, for example, consider marking the node as dummy.

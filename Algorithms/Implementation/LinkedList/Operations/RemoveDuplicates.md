In order to remove duplicates from a linked list, we need to be able to track duplicates.

### Brute Force
The simple brute force solution is to use a pointer to iterate through the list,
and for each node, check all subsequent nodes for duplicates and remove them.

```c++
void deleteDuplicates(LinkedListNode *head)
{
	LinkedListNode *current = head, *runner;
	while(current)
	{
		runner = current;
		while(runner->next)
		{

		}
	}
}
```

A simple hash table will work well here

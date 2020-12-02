Linked List
Linked data structures hold the data in multiple chunks of memory, also known as
nodes, which may be placed at different places in the memory.

Linked list: A list of items, called nodes, in which the order of the nodes is determined by the address, called the link, stored in each node. The last node contains a NULL pointer link to indicate the end of the list.

The address of the first node in the list is stored in a separate location called the head or first.

A linked list can't provide cache locality at all since the elements are not stored contiguously in memory. Hence, there's no way to bring the next element into the cache
without actually visiting it with the pointer stored in the current element. So, although,
in theory, it has the same time complexity for traversal as an array, in practice, it gives
poor performance.

Operations

Insert(k): adds k to the start of the list.
  Insert element at list head. Create a new node, assign it to the head and point link to list head. So that this new element becomes the head element of the list.
  O(1) constant time.

Delete(): delete element at the start of the list
  Delete an element at list. We just need to move one pointer and free the old head node.
  O(1) constant time.

PrintList(): display list elements
  Start with the first element and then follow the pointers to print the value of each list element.
  O(N) time

Find(k): find the position of element with value k
  Linear Search starting with the first element and follow the pointers until we get the value we are looking for or reach the end of the list.
  O(N) time

FindKth(k): find element at position k
  Start from the first element and follow the links until you reach the kth element.
  O(N) time

IsEmpty(): check if the number of elements in the list are zero.  
  Return true if the head pointer is nullptr, indicating an empty list.
  O(1) time
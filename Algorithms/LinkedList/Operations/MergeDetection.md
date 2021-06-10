Given pointers to the head nodes of linked lists that merge together at some point, find the node where the two lists merge. The merge point is where both lists point to the same node, i.e. they reference the same memory location. It is guaranteed that the two head nodes will be different, and neither will be NULL. If the lists share a common node, return that node's

value.

Note: After the merge point, both lists will share the same node pointers.

Example

In the diagram below, the two lists converge at Node x:

```
[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
```


### Function Description



findMergeNode has the following parameters:

  LinkedListNode pointer head1: a reference to the head of the first list
  LinkedListNode pointer head2: a reference to the head of the second list


To solve this problem we will use two node pointer so iterate from each head to the tail, once we reach the tail with a given pointer we will begin iterating from the other head to the tail. We will stop iteration when the address pointed to are the same.

There are two cases:

#### Case One a == b
In this case the number of nodes between each head and the merge node are equal so each will iterate through nodes and reach the merge node at the same time.



#### Case Two a != b
In this case the number of nodes between each head and the merger node are not equal.

To detect a merge point in two linked lists we can represent the linked list as composed of three segments:

Segment 1 is the nodes from head1 up to the merge node
	we will call the count of these nodes: a
Segment 2 is the nodes from head2 up to the merge node
	we will call the count of these nodes: b
Segment 3 is the nodes from the merged node to the end of the shared tail
	we will call the count of these nodes: c

```
						|<---a--->| = 3 nodes
	[List #1] a--->b--->c
	                     \|    c    | = 3 nodes
	                      x--->y--->z--->NULL
	                     /
	     [List #2] p--->q
                |<-b->| = 2 nodes
```

In the above image,
a = 3, b = 2, c = 3
The number of nodes in the linked list pointed to by head1 is x = a+c = 6
The number of nodes in the linked list pointed to by head2 is y = b+c = 5

Using the iteration technique described above, the two interation pointers, p1 and p2, travel over the segments:

p1 = segment 1 -> segment 3 -> segment 2
p2 = segment 2 -> segment 3 -> segment 1

Thus the length traveled by each pointer is

p1 = a+c+b = 8
p2 = b+c+a = 8

meaning that each pointer will iterate through all nodes in each list once and arrive at the merger point at the same time.

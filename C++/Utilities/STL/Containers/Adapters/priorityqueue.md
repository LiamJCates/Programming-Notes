Priority Queues (Heaps)

A priority queue (also called a heap) is a data structure that supports push and pop operations and keeps elements sorted according to some user-­specified comparator object.

The comparator object is a function object invokable with two parameters, returning true if the first argument is less than the second.

When you pop an element from a priority queue, you remove the element that is greatest, according to the comparator object.

The STL offers the std::priority_queue in the <queue> header:

	#include <queue>

### Construction

A priority_queue template std::priority_queue<T, W, C> has three parameters:
•	 T, the underlying type of the wrapped container
•	 W, the type of the wrapped container, defaults to std::vector
•	 C, the type of the comparator object, defaults to std::less




NOTE
The std::less class template is available from the <functional> header, and it returns true if the first argument is less than the second.

The priority_queue has an identical interface to a stack. The only difference is that stacks pop elements according to the last­in, first­out arrangement, whereas priority queues pop elements according to the comparator object criteria.



N O T E

A priority_queue holds its elements in a tree structure, so if you peered into its underlying container, the memory ordering wouldn’t match the orders implied by

Table 13­7 summarizes the operations of priority_queue.

In this table, pq, pq1, and pq2 are of type std::priority_queue<T>; t is of type T; ctr is a container of type ctr_type<T>; and srt is a container of type srt_type<T>.

| Operation | Notes |
|-----------|-------|
| priority_queue <T, [ctr_type<T>], [cmp_type]> ([cmp], [ctr]) | Constructs a priority_queue of Ts using ctr as its internal container and srt as its comparator object. If no container is provided, constructs an empty deque. Uses std::less as default sorter. |
| pq.empty() | Returns true if container is empty. |
| pq.size() | Returns number of elements in container. |
| pq.top() | Returns a reference to the greatest element in the container. |
| pq.push(t) | Puts a copy of t onto the end of the container. |
| pq.emplace(...) | Constructs a T in place by forwarding ... to the appropriate constructor. |
| pq.pop() | Removes the element at the end of the container. |
| pq1.swap(pq2) | Exchanges the contents of s2 with s1. |
| swap(pq1, pq2) | Exchanges the contents of s2 with s1. |

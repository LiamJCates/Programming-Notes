Priority Queue (Heap)
Priority queue is implemented using a binary heap data structure. In a heap, the
records are stored in an array so that each key is larger than its two children
keys. Each node in the heap follows the same rule that the parent value is greater
than its two children.
There are two types of the heap data structure:
1. Max heap: each node should be greater than or equal to each of its
children.
2. Min heap: each node should be smaller than or equal to each of its
children.
A heap is a useful data structure when you want to get max/min one by one from
data. Heap-Sort uses max heap to sort data in increasing/decreasing order.
Heap ADT OperationsInsert() - Adding a new element to the heap. The Time Complexity of this
operation is O(log(n))
remove() - Extracting max for max heap case (or min for min heap case). The
Time Complexity of this operation is O(log(n))
Heapify() – To convert a list of numbers in an array into a heap. This operation
has a Time Complexity O(n)
PriorityQueue implementation in C++ Collection
Min heap implementation of Priority Queue
Example 4.7
#include <queue>
void minheapdemo()
{
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
std::vector<int> arr = { 1, 2, 10, 8, 7, 3, 4, 6, 5, 9 };
for (auto i : arr)
minHeap.push(i);
for (unsigned int i = 0; i < arr.size(); i++)
{
std::cout << minHeap.top() << " ";
minHeap.pop();
}
} O
utput
1 2 3 4 5 6 7 8 9 10
Max heap implementation of Priority Queue
We just need to change collection order to make max heap from
PriorityQueue<> collection.
Example 4.9
std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
Output
10 9 8 7 6 5 4 3 2 1

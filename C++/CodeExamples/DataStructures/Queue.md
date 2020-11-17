A queue is a First-In-First-Out (FIFO) kind of data structure. The element that is
added to the queue first will be the first to be removed from the queue and so on.
Queue has the following application uses:
1. Access to shared resources (e.g., printer)
2. Multiprogramming
3. Message queue
Queue ADT Operations:
Add(): Add a new element to the back of the queue.
Remove(): remove an element from the front of the queue and return its value.
Front(): return the value of the element at the front of the queue.
Size(): returns the number of elements inside the queue.
IsEmpty(): returns 1 if the queue is empty otherwise return 0
Note:- All the above Queue operations are implemented in O(1) Time
Complexity.
Queue implementation in C++ Collection
Queue<T> is the class implementation of queue.
Example 4.4
#include <queue>
int main(){
std::queue<int> que;
std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
for (auto i : arr)
que.push(i);
for (unsigned int i = 0; i < arr.size(); i++)
{
std::cout << que.front() << " ";
que.pop();
}re
turn 0;
} A
nalysis: Values are added to the queue and are taken out of the queue. Since
stack is first-in-first-out, the values that are added first are the first to come out
of the queue.

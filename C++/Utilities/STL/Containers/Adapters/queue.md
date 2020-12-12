Queue implementation in C++

The std::queue class is a container adapter that gives the programmer the functionality of a queue - specifically, a FIFO (first-in, first-out) data structure.

The class template acts as a wrapper to the underlying container

empty(): Returns whether the queue is empty
size(): Returns the size of the queue
push(T data): Adds element at the end of the queue.
pop(): Removes and returns the element at the front of the queue
front(): Returns the element at the front of the queue
back(): Returns the element at the back of the queue

#include <queue>
int main(){
  std::queue<int> que;
  std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  std::cout << "The queue is empty: " << que.empty() << std::endl;

  for (auto i : arr)
    que.push(i);

  std::cout << "The queue size is " << que.size() << std::endl;

  for (unsigned int i = 0; i < arr.size(); i++)
  {
    std::cout << que.front() << " ";
    que.pop();
  }
  std::cout << std::endl;

  std::cout << "The queue is empty: " << que.empty() << std::endl;
}

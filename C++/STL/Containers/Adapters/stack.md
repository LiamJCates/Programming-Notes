Stack implementation in C++

The std::stack class is a container adapter that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.

The class template acts as a wrapper to the underlying container

empty(): Returns whether the stack is empty
size(): Returns the size of the stack
push(T data): Adds element at the top of the stack
pop(): Removes and returns the element at the top of the stack
top(): Returns the element at the top of the stack

#include <stack>
int main()
{
  std::stack<int> stk;
  std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  std::cout << "The stack is empty: " << stk.empty() << std::endl;

  for (auto i : arr)
    stk.push(i);

  std::cout << "stack size is " << stk.size() << std::endl;

  for (unsigned int i = 0; i < arr.size(); i++)
  {
    std::cout << stk.top() << " ";
    stk.pop();
  }
  std::cout << std::endl;

  std::cout << "The stack is empty: " << stk.empty() << std::endl;
}

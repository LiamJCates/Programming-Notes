A stack is a memory in which values are stored and retrieved in “last in first out” manner. Data is added to stack using push operation and data is taken out of stack using pop operation.

#include <stdio.h>

using namespace std;

#define MAX 1000

class Stack {
  int top;

public:
  int a[MAX]; // Maximum size of Stack

  Stack() { top = -1; }

  bool push(int x) {
      if (top >= (MAX - 1)) {
          cout << "Stack Overflow";
          return false;
      }
      else {
          a[++top] = x;
          cout << x << " pushed into stack\n";
          return true;
      }
  }

  int pop() {
      if (top < 0) {
          cout << "Stack Underflow";
          return 0;
      }
      else {
          int x = a[top--];
          return x;
      }
  }

  int peek() {
      if (top < 0) {
          cout << "Stack is Empty";
          return 0;
      }
      else {
          int x = a[top];
          return x;
      }
  }

  bool Stack::isEmpty() {
      return (top < 0);
  }
};

// Driver program to test above functions
int main()
{
  class Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  cout << s.pop() << " Popped from stack\n";
  cout << s.pop() << " Popped from stack\n";
  cout << s.pop() << " Popped from stack\n";
  cout << " Stack is empty: " << s.isEmpty() << endl;

  return 0;
}

1. Initially the stack was empty.

2. Then we have added value 1 to stack using push(1) operator.
    Similarly, push(2) and push(3)

Pop operation takes the top of the stack in “last in, first out” manner.
3. The pop() operation will take 3 out of the stack.
    Similarly, other pop operations will take 2 then 1 out of the stack.

4. The stack is empty as all the elements are taken out of the stack.

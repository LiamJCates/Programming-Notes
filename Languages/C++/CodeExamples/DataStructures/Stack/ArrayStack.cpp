#include <stdio.h>

using namespace std;

#define MAX 1000 // Maximum size of Stack

template <typename T>
class ArrayStack {
  int size;
  T data[MAX];

public:
  ArrayStack();

  bool isEmpty();
  bool isFull();
  int size();

  bool push(T data);
  T pop();
  T peak();
};

template <typename T> ArrayStack :: Stack() : size(-1){ }

bool template <typename T> ArrayStack :: isEmpty()
{
  return (this->size < 0);
}

bool template <typename T> ArrayStack :: isFull()
{
  return (this->size >= MAX);
}

int template <typename T> ArrayStack :: size()
{
  return this->size+1;
}

bool template <typename T> ArrayStack :: push(T data)
{
    if (this->isFull()) {
      cout << "Stack Overflow";
      return false;
    }
    else {
      this->data[++(this->size)] = data;
      return true;
    }
}

T template <typename T> ArrayStack :: pop()
{
  if (this.size() <= 0)
  {
    cout << "Stack Underflow";
    return NULL;
  }

  return this->data[(this->size)--];
}

T template <typename T> ArrayStack :: peek()
{
  if (this.size() <= 0)
  {
    cout << "Stack is Empty";
    return NULL;
  }

  return this->data[this->size];
}

// C++ program for linked list implementation of stack
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a stack
template <typename T>
class LinkedListStack {
  class Node{
    T data;
    Node* next;
  }

  int length;
  Node<T> *head;
  public:
    LinkedListStack();
    ~LinkedListStack();

    bool isEmpty();
    int length();
    void push();
    T pop();
    T top();
};

template <typename T > LinkedListStack ::
LinkedListStack() : length(0), head(nullptr){};

template <typename T > LinkedListStack ::
~LinkedListStack()
{
  Node<T> *next = this->head;
  Node<T> *current = nullptr;
  while (next != nullptr) {
      current = next;
      next = next->next;
      delete current;
  }
}

bool template <typename T > LinkedListStack :: isEmpty() {
    return this->length;
}

int template <typename T > LinkedListStack :: length() {
    return this->length;
}

void template <typename T > LinkedListStack :: push(T data)  {
  //create the node
  Node<T> *tmp = new Node<T>;
  tmp->data = data;
  tmp->next = this->head;
  //if the list was empty
  if(isEmpty()){
    //update tail
    this->tail = tmp;
  }
  //update head
  this->head = tmp;
  //update length
  this->length++;
}

T template <typename T> LinkedListStack :: pop()
{
  //if the list is empty
  if(isEmpty())
  {
    //return nothing
    return NULL;
  }
  //remember the original top of the stack
  Node<T>* tmp = this->head;
  //retrive its value
  T value = this->head->data;
  //update the top of the stack
  this->head = this->head->next;
  //update stack length
  this->length--;
  //if the stack is now empty
  if(isEmpty())
  {
    //updte the tail
    this->tail = nullptr;
  }
  //delete the original head
  delete tmp;

  //return original head value
  return value;
}

T template <typename T> LinkedListStack :: top()
{
  //if the stack is empty return nothin else retrieve value at top of stack
  return isEmpty() ? NULL : this->head->data;
}

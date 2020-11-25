template <typename T>
class LinkedListStack {
  class Node{
    T data;
    Node* next;
  }

  int length;
  Node<T> *top;
  
  public:
    LinkedListStack();
    ~LinkedListStack();

    bool isEmpty();
    int length();
    void push();
    T pop();
    T peak();
};

template <typename T > LinkedListStack ::
LinkedListStack() : length(0), top(nullptr){};

template <typename T > LinkedListStack ::
~LinkedListStack()
{
  Node<T> *next = this->top;
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
  tmp->next = this->top;
  //if the list was empty
  if(this->isEmpty()){
    //update tail
    this->tail = tmp;
  }
  //update top
  this->top = tmp;
  //update length
  this->length++;
}

T template <typename T> LinkedListStack :: pop()
{
  //if the list is empty
  if(this->isEmpty())
  {
    //return nothing
    return NULL;
  }
  //remember the original top of the stack
  Node<T>* tmp = this->top;
  //retrive its value
  T value = this->top->data;
  //update the top of the stack
  this->top = this->top->next;
  //update stack length
  this->length--;
  //if the stack is now empty
  if(this->isEmpty())
  {
    //updte the tail
    this->tail = nullptr;
  }
  //delete the original top
  delete tmp;

  //return original top value
  return value;
}

T template <typename T> LinkedListStack :: peak()
{
  //if the stack is empty return nothin else retrieve value at top of stack
  return this->isEmpty() ? NULL : this->top->data;
}

template <typename T>
class LinkedListQueue
{

    int length;
    Node<T> *front;
    Node<T> *rear;

    class Node {
        T data;
        Node *next;
    };
public:
    LinkedListQueue();
    ~LinkedListQueue();

    bool isEmpty();
    int length();
    void add(T data);
    T remove();
    T front();
    void print();
};

template <typename T> LinkedListQueue<T>::LinkedListQueue()
: length(0), front(nullptr), rear(nullptr) {}

template <typename T> LinkedListQueue<T> :: ~LinkedListQueue()
{
  Node<T> *next = this->front;
  Node<T> *current = nullptr;
  while (next != nullptr) {
      current = next;
      next = next->next;
      delete current;
  }
}

//returns whether the list is empty
bool template <typename T> LinkedListQueue :: isEmpty()
{
    return this->length;
}

//returns the list's length
int template <typename T> LinkedListQueue :: length()
{
    return this->length;
}

void template <typename T> LinkedListQueue :: add(T data)
{
  //create the node
  Node<T> *tmp = new Node<T>;
  tmp->data = data;
  tmp->next = nullptr;
  //if the list was empty
  if(this->isEmpty())
  {
    //update the front
    this->front = tmp;
  }
  //else the list was not empty
  else
  {
    //append node to the rear
    this->rear->next = tmp;
  }
  //update the rear
  this->rear = tmp;
  //update length
  this->length++;
}

T template <typename T> LinkedListQueue :: remove()
{
  if(this->isEmpty())
  {
    return NULL;
  }
  //create a pointer the front of the queue
  Node<T> *current = this->front;
  //retrieve the value at the front of the queue
  return current->data;
}

T template <typename T> LinkedListQueue :: remove()
{
  if(this->isEmpty())
  {
    return NULL;
  }
  //create a pointer to hold the previous value of front
  Node<T> *current = this->front;
  //retrieve the value at the front of the list
  T value = current->data;
  //update the front to point the new front
  this->front = this->front->next;
  //delete the original front
  delete current;
  //update the length
  this->length--;
  //if the list is now empty
  if (this->isEmpty())
  {
    //update the rear
    this->rear = nullptr;
  }
  return value;
}

void template <typename T> LinkedListQueue :: print(){
  //if the list is empty
  if (this->isEmpty())
  {
    //indicate empty list
    std::cout << "List is empty." << std::endl;
  }
  //else the list has members
  else
  {
    //create traversal pointer
    Node<T> *current = this->front;
    //indicate start of element sequence
    std::cout << "Singly linked list sequence:" << std::endl;
    //while there are members to traverse
    while (current != nullptr) {
      //output the element data
      std::cout << current->data << ' ';
      //update traversal pointer
      current = current->next;
    }
    std::cout << std::endl;
  }
}

template <typename T>
class CircularLinkedListQueue
{

    int length;
    Node<T> *front;
    Node<T> *rear;

    class Node {
      T data;
      Node *next;

      Node();
      Node(T data, Node* next);
      ~Node();
    };
public:
    CircularLinkedListQueue();
    ~CircularLinkedListQueue();

    bool isEmpty();
    int length();
    void add(T data);
    T front();
    T remove();
    T rear();
    void print();
};

template <typename T> CircularLinkedListQueue<T> :: Node ::
Node() : next(nullptr) { }

template <typename T> CircularLinkedListQueue<T> :: Node ::
Node(T element, Node* ptr = nullptr) : data(element), next(ptr) { }

template <typename T> CircularLinkedListQueue<T> :: Node ::
~Node() {data = 0, next = NULL}

template <typename T> CircularLinkedListQueue<T>::CircularLinkedListQueue()
: length(0), front(nullptr), rear(nullptr) {}

template <typename T> CircularLinkedListQueue<T> :: ~CircularLinkedListQueue()
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
bool template <typename T> CircularLinkedListQueue :: isEmpty()
{
    return this->length;
}

//returns the list's length
int template <typename T> CircularLinkedListQueue :: length()
{
    return this->length;
}

void template <typename T> CircularLinkedListQueue :: add(T data)
{
  //create the new rear node linked to the front
  Node<T> *tmp = new Node<T>(data, this->front);
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

T template <typename T> CircularLinkedListQueue :: front()
{
  //return NULL if list is empty else the value of front
  return this->isEmpty() ? NULL : front->data;
}

T template <typename T> CircularLinkedListQueue :: remove()
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

T template <typename T> CircularLinkedListQueue :: rear()
{
  //return NULL if list is empty else the value of rear
  return this->isEmpty() ? NULL : rear->data;
}

void template <typename T> CircularLinkedListQueue :: print(){
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
    //retrieve the number of nodes to traverse
    int nodes = this->length;
    //indicate start of element sequence
    std::cout << "Singly linked list sequence:" << std::endl;
    //while there are members to traverse
    while (nodes--) {
      //output the element data
      std::cout << current->data << ' ';
      //update traversal pointer
      current = current->next;
    }
    std::cout << std::endl;
  }
}

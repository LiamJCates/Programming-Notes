template <typename T>
class CircularDoublyLinkedList
{

    int length;
    Node<T> *head;
    Node<T> *tail;

    class Node {
        T data;
        Node *next;
        Node *previous;

        Node();
        Node(T data, Node* next, Node* previous);
        ~Node();
    };
public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();

    bool isEmpty();
    int length();
    void insert(int idx);
    void prepend(T data);
    void append(T data);
    void delete(int idx);
    void delete(T value);
    bool search(T value);
    void reverse();
    void print();
    void concatenate(CircularDoublyLinkedList<T> second);
};

template <typename T> CircularDoublyLinkedList<T> :: Node :: Node()
: next(nullptr), previous(nullptr) { }

template <typename T> CircularDoublyLinkedList<T> :: Node ::
Node(T element, Node* n = nullptr, Node* p = nullptr)
: data(element), next(n), previous(p) { }

template <typename T> CircularDoublyLinkedList<T> :: Node ::
~Node() {data = 0, next = NULL, previous = NULL}

template <typename T> CircularDoublyLinkedList<T>::CircularDoublyLinkedList()
: length(0), head(nullptr), tail(nullptr) {}

template <typename T> CircularDoublyLinkedList<T> :: ~CircularDoublyLinkedList()
{
  Node<T> *next = this->head;
  Node<T> *current = nullptr;
  while (next != nullptr) {
      current = next;
      next = next->next;
      delete current;
  }
  this->head = 0;
}

//returns whether the list is empty
bool template <typename T> CircularDoublyLinkedList :: isEmpty()
{
    return this->length;
}

//returns the list's length
int template <typename T> CircularDoublyLinkedList :: length()
{
    return this->length;
}
/*
void template <typename T> CircularDoublyLinkedList :: prepend(T data)
{
  //create the node
  Node<T> *tmp = new Node<T>(data, this->head, this->tail);
  //if the list was empty
  if(this->isEmpty()){
    //update tail
    this->tail = tmp;
  }
  //update head
  this->head = tmp;
  //update tail's next to the new head
  this->tail->next = tmp;
  //update length
  this->length++;
}

void template <typename T> CircularDoublyLinkedList :: append(T data)
{
  //create a temperary node identifier
  Node<T> *tmp CircularDoublyLinkedList;
  //if the list was empty
  if(this->isEmpty()){
    //create the node with default nullptr for next and previous nodes
    tmp = new Node<T>(data);
    //update the head and tail
    this->head = this->tail = tmp;
  }
  //else the list was not empty
  else{
    //create the node with default nullptr for next and the current
    tmp = new Node<T>(data, this->head, this->tail);
    //append node to the tail
    this->tail->next = tmp;
    //update the tail
    this->tail = tmp;
  }
  //update length
  this->length++;
}


void template <typename T> CircularDoublyLinkedList :: delete(T data)
{
  //if the list is not empty traverse the list to search for the data to delete
  if (!this->isEmpty())
  {
    //Set traversal node to current to the list head
    Node<T> *current = this->head;
    //if the data to delete is the head
    if(current->data == data)
    {
      //update the list head
      this->head = current->next;
      //if the list would now be empty
      if(head == nullptr)
      {
        //update tail to nullptr
        this->tail = nullptr;
      }
      else
      {
        //current head has no previous node
        this->head->previous = nullptr;
      }
      //delete the original head
      delete current;
      this->length--;
      //finish list processing
      return;
    }
    //else traverse the list
    else
    {
      while(current != nullptr){
        //if the data to delete is the current node
        if(current->data == data)
        {
          //update the previous nodes next link
          current->previous->next = current->next;
          //if the current node is the tail
          if(current->next == nullptr)
          {
            //update tail to the previous node
            this->tail = current->previous;
          }
          else
          {
            //link the new next back to previous
            current->next->previous = current->previous;
          }
          //delete the current node
          delete current;
          //update length
          this->length--;
          //finish list processing
          return;
        }
        //if we have not found the data to delete
        else
        {
          //move both list traversal pointers
          previous = current;
          current = current->next;
        }
      }
    }
  }
}


void template <typename T> CircularDoublyLinkedList :: delete(int idx)
{
  //if the index exists in the list
  if (idx < 0 || idx >= this->length)
  {
    //create a traversal pointer
    Node<T> *current = this->head;
    //if the node to delete is the head
    if (idx == 0)
    {
      //update the list head
      this->head = this->head->next;
      //if the list would now be empty
      if(head == nullptr)
      {
        //update tail to nullptr
        this->tail = nullptr;
      }
      else
      {
        //current head has no previous node
        this->head->previous = this->tail;
      }
      //delete the original head
      delete current;
      this->length--;
      //finish list processing
      return;
    }
    //else traverse the list
    else
    {
      //locate the node at given index
      for (int i = 0; i < idx; i++, current = current->next);
      //update the previous nodes next link
      current->previous->next = current->next;
      //if the current node is the tail
      if(current->next == nullptr)
      {
        //update tail to the previous node
        this->tail = current->previous;
      }
      else
      {
        //link the new next back to previous
        current->next->previous = current->previous;
      }
      //delete the current node
      delete current;
      //update length
      this->length--;
    }
  }
}


void template <typename T> CircularDoublyLinkedList :: search(T data)
{
  //Set traversal pointer to the list head
  Node<T> *current = this->head;
  //while there are elements to traverse
  while(current != nullptr){
    //if the current node holds the search value
    if(current->data == data)
    {
      //indicate serach value found
      return true
    }
    //else search value not found
    else
    {
      //update traversal pointer
      current = current->next;
    }
  }
  //indicate search value cloud not be found
  return false;
}

void template <typename T> CircularDoublyLinkedList :: print(){
  //if the list is empty
  if (this->isEmpty()) {
    //indicate empty list
    std::cout << "List is empty." << std::endl;
  //else the list has members
  } else {
    //create traversal pointer
    Node<T> *current = this->head;
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

void template <typename T> CircularDoublyLinkedList :: concatenate(CircularDoublyLinkedList<T> second)
{
  this->tail->next = second->head;
  this->tail = second->tail;
  second->head->previous = this->tail;
}
*/

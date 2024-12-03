template <typename T>
class DoublyLinkedList
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
    DoublyLinkedList();
    ~DoublyLinkedList();

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
    void concatenate(DoublyLinkedList<T> second);
};

template <typename T> DoublyLinkedList<T> :: Node ::
Node() : next(nullptr), previous(nullptr) { }

template <typename T> DoublyLinkedList<T> :: Node ::
Node(T element, Node* n = nullptr, Node* p = nullptr)
: data(element), next(n), previous(p) { }

template <typename T> DoublyLinkedList<T> :: Node ::
~Node() {data = 0, next = NULL, previous = NULL}

template <typename T> DoublyLinkedList<T> ::
DoublyLinkedList() : length(0), head(nullptr), tail(nullptr) {}

template <typename T> DoublyLinkedList<T> ::
~DoublyLinkedList()
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
bool template <typename T> DoublyLinkedList :: isEmpty()
{
    return this->length;
}

//returns the list's length
int template <typename T> DoublyLinkedList :: length()
{
    return this->length;
}

void template <typename T> DoublyLinkedList :: prepend(T data)
{
  //create the new head node
  Node<T> *tmp = new Node<T>(data, this->head);
  //if the list was empty
  if(this->isEmpty())
  {
    //the new head is also the tail
    this->tail = tmp;
  }
  else
  {
    //update original head previous link to point to the new head
    this->head->previous = tmp;
  }
  //point head at the new head
  this->head = tmp;
  //update length
  this->length++;
}

void template <typename T> DoublyLinkedList :: append(T data)
{

  //create the new tail node
  Node<T> *tmp = new Node<T>(data, nullptr, this->tail);
  //if the list was empty
  if(this->isEmpty())
  {
    //the new tail is also the head
    this->head = tmp;
  }
  else
  {
    //append node to the original tail
    this->tail->next = tmp;
  }
  //update the tail
  this->tail = tmp;
  //update length
  this->length++;
}


void template <typename T> DoublyLinkedList :: delete(T data)
{
  //traverse a non-empty list to search for the data to delete
  if (!this->isEmpty())
  {
    //Set traversal node to the list head
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


void template <typename T> DoublyLinkedList :: delete(int idx)
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

void template <typename T> DoublyLinkedList :: search(T data)
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
  //indicate search value could not be found
  return false;
}

void template <typename T> DoublyLinkedList :: print(){
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


void template <typename T> DoublyLinkedList :: reverse()
{
  //create traversal pointers
  Node<T> *current = this->head;
  Node<T> *previous = nullptr;
  Node<T> *next;
  //while there are elements to reverse
  while(current != nullptr){
    //the next traversal pointer is updated to the link value of current
    next = current->next;
    //the next link value of current is linked to the previous node
    current->next = previous;
    //previous link value of current is linked to the next node
    current->previous = next;
    //the previous traversal pointer is updated to the current node
    previous = current;
    //the current traversal pointer is updated to the next value
    current = next;
  }
}

void template <typename T> DoublyLinkedList :: concatenate(DoublyLinkedList<T> second)
{
  //link this tail to head of second list
  this->tail->next = second->head;
  //link head of second to tail of this list
  second->head->previous = this->tail;
  //set new tail of this list to tail of second
  this->tail = second->tail;
}

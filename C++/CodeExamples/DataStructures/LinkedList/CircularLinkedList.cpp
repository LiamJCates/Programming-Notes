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

void template <typename T> CircularDoublyLinkedList :: prepend(T data)
{
  //create the new head node
  Node<T> *tmp = new Node<T>(data, this->head, this->tail);
  //if the list was empty
  if(this->isEmpty())
  {
    //update tail
    this->tail = tmp;
  }
  else
  {
    //update original head previous link to point to the new head
    this->head->previous = tmp;
    //update tail's next link to point to the new head
    this->tail->next = tmp;
  }
  //update head
  this->head = tmp;
  //update length
  this->length++;
}

void template <typename T> CircularDoublyLinkedList :: append(T data)
{
  //create the new tail node
  Node<T> *tmp = new Node<T>(data, this->head, this->tail);
  //if the list was empty
  if(this->isEmpty())
  {
    //the tail is also the head
    this->head = tmp;
  }
  else
  {
    //append node to the original tail
    this->tail->next = tmp;
    //update head's previous link to point to the new tail
    this->head->previous = tmp;
  }
  //update the tail
  this->tail = tmp;
  //update length
  this->length++;
}


void template <typename T> CircularDoublyLinkedList :: delete(T data)
{
  //traverse a non-empty list to search for the data to delete
  if (!this->isEmpty())
  {
    //Set traversal node to the list head
    Node<T> *current = this->head;
    //if the data to delete is the head
    if(current->data == data)
    {
      //move the list head
      this->head = this->head->next;
      //if the list would now be empty
      if(head == nullptr)
      {
        //update tail to nullptr
        this->tail = nullptr;
      }
      else
      {
        //current head points back to
        this->head->previous = this->tail;
        //update tail's next link to the new head
        this->tail->next = this->head;
      }
      //delete the original head
      delete current;
      this->length--;
      //finish list processing
      return;
    }
    else
    {
      //traverse the list
      while(current != nullptr){
        //if the data to delete is the current node
        if(current->data == data)
        {
          //update the previous nodes next link to skip node to be deleted
          current->previous->next = current->next;
          //if the tail is to be deleted
          if(current->next == nullptr)
          {
            //make the previous node the new tail
            this->tail = current->previous;
            //point head's previous link to the new tail
            this->head->previous = this->tail;
          }
          else
          {
            //link the node after node to be deleted back to previous
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
      //move the list head
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
        //update tail's next link to the new head
        this->tail->next = this->head;
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
      //if the tail is to be deleted
      if(current->next == nullptr)
      {
        //make the previous node the new tail
        this->tail = current->previous;
        //point head's previous link to the new tail
        this->head->previous = this->tail;
      }
      else
      {
        //link the node after node to be deleted back to previous
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
  //retrieve number of nodes
  int nodes = this->length;
  //while there are elements to traverse
  while(nodes--)
  {
    //if the current node holds the search value
    if(current->data == data)
    {
      //indicate serach value found
      return true
    }
    else
    {
      //update traversal pointer
      current = current->next;
    }
  }
  //indicate search value could not be found
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
    //retrieve number of nodes
    int nodes = this->length;
    //while there are elements to traverse
    while(nodes--)
    {
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
  //link this tail to head of second list
  this->tail->next = second->head;
  //link this head to tail of second
  this->head->previous = second->tail;
  //link head of second to tail of this list
  second->head->previous = this->tail;
  //link tail of second to head of this list
  second->tail->next = this->head->previous;
  //set new tail of this list to tail of second
  this->tail = second->tail;

}

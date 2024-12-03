#include <iostream>

using namespace std;

template <typename T>
class SinglyLinkedList
{

    class Node {
        T data;
        Node *next;

        Node();
        Node(T data, Node* next);
        ~Node();
    };
    int length;
    Node *head;
    Node *tail;


public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    bool isEmpty();
    int size();
    void prepend(T data);
    void append(T data);
    void insert(int idx, T data);
    void remove(int idx);
    void remove(T value);
    bool search(T value);
    void reverse();
    void print();
    void concatenate(SinglyLinkedList<T> second);
};

template <typename T> SinglyLinkedList<T> :: Node :: Node()
: next(nullptr) { };

template <typename T> SinglyLinkedList<T> :: Node :: Node(T element, Node* ptr)
: data(element), next(ptr) { };

template <typename T> SinglyLinkedList<T> :: Node :: ~Node() {data = 0, next = NULL;}

template <typename T> SinglyLinkedList<T>::SinglyLinkedList()
: length(0), head(nullptr), tail(nullptr) { };

template <typename T> SinglyLinkedList<T> :: ~SinglyLinkedList()
{
  Node *next = this->head;
  Node *current = nullptr;
  while (next != nullptr) {
      current = next;
      next = next->next;
      delete current;
  }
  this->head = 0;
}

//returns whether the list is empty
template <typename T>
bool SinglyLinkedList<T> :: isEmpty()
{
    return this->length;
}

//returns the list's length
template <typename T>
int SinglyLinkedList<T> :: size()
{
    return this->length;
}

template <typename T>
void  SinglyLinkedList<T> :: prepend(T data)
{
  //create the node
  Node *tmp = new Node(data, this->head);
  //if the list was empty
  if(this->isEmpty()){
    //update tail
    this->tail = tmp;
  }
  //update head
  this->head = tmp;
  //update length
  this->length++;
}

template <typename T>
void  SinglyLinkedList<T> :: append(T data)
{
  //create the node
  Node *tmp = new Node(data);

  //if the list was empty
  if(this->isEmpty()){
    //update the head and tail
    this->head = this->tail = tmp;
  }
  //else the list was not empty
  else{
    //append node to the tail
    this->tail->next = tmp;
    //update the tail
    this->tail = tmp;
  }
  //update length
  this->length++;
}

template <typename T>
void  SinglyLinkedList<T> ::
insert(int index, T data)
{
  if (index > 0 || index >= this->length)
  {
    if(index == 0)
      prepend(data);
    if(index == length)
      append(data);

    Node *tmp = new Node(data);
    Node *next = this->head;
    Node *prev;
    while(index--)
    {
      prev = next;
      next = next->next;
    }
    prev->next = tmp;
    tmp->next = next;
    this->length++;
  }
}

template <typename T>
void  SinglyLinkedList<T> :: remove(T data)
{
  //if the list is not empty traverse the list for a value to delete
  if (!this->isEmpty())
  {
    //Set current to the list head
    Node *current = this->head;
    //if the data to delete is the list head
    if(current->data == data)
    {
      //move the list head
      this->head = current->next;
      //if the list would now be empty
      if(head == nullptr)
      {
        //update tail
        this->tail = head;
      }
      //delete the original head
      delete current;
    }
    else
    {
      //remember the node previous to current
      Node *previous = current;
      //move current
      current = current->next;
      while(current != nullptr){
        //if the data to delete is the current node
        if(current->data == data){
          //update the previous nodes link
          previous->next = current->next;
          //delete the current node
          delete current;
          //if the previous node is now the tail
          if(previous->next == nullptr)
          {
            //update tail
            this->tail = previous;
          }
          //update length
          this->length--;
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

template <typename T>
void  SinglyLinkedList<T> :: remove(int idx)
{
  //if the index exists in the list
  if (idx > 0 || idx <= this->length)
  {
    //create a traversal pointer
    Node *current = this->head;
    //if the node to delete is the head
    if (idx == 0)
    {
      //update the head
      this->head = this->head->next;
      //delete the current node
      delete current;
      //update the length
      this->length--;
      //if the list is now empty
      if (this->isEmpty())
      {
        //update the tail
        this->tail = nullptr;
      }
    }
    //else traverse the list
    else
    {
      //remember the node previous to current
      Node *previous = current;
      //move current past head
      current = current->next;
      //locate the node at given index
      for (int i = 1; i < idx; i++)
      {
        previous = current;
        current = current->next;
      }
      //update the previous nodes link
      previous->next = current->next;
      //delete the desired node
      delete current;
      //update the length
      this->length--;
      //if deletion occured at the tail
      if (idx == this->length)
      {
          this->tail = previous;
      }
    }
  }
}

template <typename T>
bool SinglyLinkedList<T> :: search(T data)
{
  //Set traversal pointer to the list head
  Node *current = this->head;
  //while there are elements to traverse
  while(current != nullptr){
    //if the current node holds the search value
    if(current->data == data)
    {
      //indicate serach value found
      return true;
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

template <typename T>
void  SinglyLinkedList<T> :: print(){
  //if the list is empty
  if (this->isEmpty()) {
    //indicate empty list
    std::cout << "List is empty." << std::endl;
  //else the list has members
  } else {
    //create traversal pointer
    Node *current = this->head;
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

template <typename T>
void  SinglyLinkedList<T> :: reverse()
{
  //create traversal pointers
  Node *current = this->head;
  Node *previous = nullptr;
  Node *next = nullptr;
  //while there are elements to reverse
  while(current != nullptr){
    //the next traversal pointer is updated to the link value of current
    next = current->next;
    //the link value of current is linked to the previous node
    current->next = previous;
    //the previous traversal pointer is updated to the current node
    previous = current;
    //the current traversal pointer is updated to the next value
    current = next;
  }
}

template <typename T>
void  SinglyLinkedList<T> :: concatenate(SinglyLinkedList<T> second)
{
  this->tail->next = second->head;
  this->tail = second->tail;
}

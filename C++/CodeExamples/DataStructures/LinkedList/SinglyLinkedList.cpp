template <typename T>
class SinglyLinkedList
{

    int length;
    Node<T> *head;
    Node<T> *tail;

    class Node {
        T data;
        Node *next;
    };
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

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
    void concatenate(SinglyLinkedList<T> second);
};

template <typename T> SinglyLinkedList<T>::SinglyLinkedList()
: length(0), head(nullptr), tail(nullptr) {}

template <typename T> SinglyLinkedList<T> :: ~SinglyLinkedList()
{
  Node<T> *next = this->head;
  Node<T> *current = nullptr;
  while (next != nullptr) {
      current = next;
      next = next->next;
      delete current;
  }
}

//returns whether the list is empty
bool template <typename T> SinglyLinkedList :: isEmpty()
{
    return this->length;
}

//returns the list's length
int template <typename T> SinglyLinkedList :: length()
{
    return this->length;
}

void template <typename T> SinglyLinkedList :: prepend(T data)
{
  //create the node
  Node<T> *tmp = new Node<T>;
  tmp->data = data;
  tmp->next = this->head;
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

void template <typename T> SinglyLinkedList :: append(T data)
{
  //create the node
  Node<T> *tmp = new Node<T>;
  tmp->data = data;
  tmp->next = nullptr;
  //if the list was empty
  if(this->isEmpty()){
    //update the head and tail
    this->head = tmp;
    this->tail = tmp;
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


void template <typename T> SinglyLinkedList :: delete(T data)
{
  //if the list is not empty traverse the list for a value to delete
  if (!this->isEmpty())
  {
    //Set current to the list head
    Node<T> *current = this->head;
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
      Node<T> *previous = current;
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

void template <typename T> SinglyLinkedList :: delete(int idx)
{
  //if the index exists in the list
  if (idx < 0 || idx >= this->length)
  {
    //create a traversal pointer
    Node<T> *current = this->head;
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
      Node<T> *previous = current;
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

void template <typename T> SinglyLinkedList :: search(T data)
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

void template <typename T> SinglyLinkedList :: print(){
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

void template <typename T> SinglyLinkedList :: reverse()
{
  //create traversal pointers
  Node<T> *current = this->head;
  Node<T> *previous = nullptr;
  Node<T> *next = nullptr;
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

void template <typename T> SinglyLinkedList :: concatenate(SinglyLinkedList<T> second)
{
  this->tail->next = second->head;
  this->tail = second->tail;
}

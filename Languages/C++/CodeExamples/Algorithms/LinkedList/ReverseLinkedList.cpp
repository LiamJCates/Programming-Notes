template <typename T>
class SinglyLinkedList
{

    int length;
    Node<T> *head;
    Node<T> *tail;

    class Node {
        T data;
        Node *next;

        Node();
        Node(T data, Node* next);
        ~Node();
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

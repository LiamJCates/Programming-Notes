template <class T>
class Stack
{
public:
    Stack() : head(nullptr){};
    ~Stack();
    void push(T data);
    T pop();

protected:
    class Element
    {
    public:
        Element(Element *n, T d) : next(n), data(d) {}
        Element *getNext() const { return next; }
        T value() const { return data; }

    private:
        Element *next;
        T data;
    };
    Element *head;
};

template <class T>
Stack<T>::~Stack()
{
    while (head)
    {
        Element *next = head->getNext();
        delete head;
        head = next;
    }
}

template <class T>
void Stack<T>::push(T data)
{
    ///* Allocation error will throw exception */
    Element *element = new Element(head, data);
    head = element;
}

template <class T>
T Stack<T>::pop()
{
    Element *popElement = head;
    T data;
    /* Assume StackError exception class is defined elsewhere */
    if (head == nullptr)
        throw StackError(E_EMPTY);
    54 ❘ CHAPTER 5 Linked Lists
        data = head->value();
    head = head->getNext();
    delete popElement;
    return data;
}

/*
A more complete C++ implementation should include a copy constructor and assignment operator, because the default versions created by the compiler could lead to multiple deletes of the same
Element due to inadvertent sharing of elements between copies of a Stack.
*/

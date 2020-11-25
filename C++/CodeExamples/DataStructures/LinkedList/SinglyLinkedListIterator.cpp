template<class T>
class List
{
    public:
        //Class declarations.
        class Iterator;
        class ConstIterator;

        //Constructors and Destructors.
        List() : head(NULL), tail(NULL), size(0) {} //Constructor
        ~List(); //Destructor

        //Methods
        Iterator<T> begin();
        Iterator<T> end();
        void insert(const T& data);
        void insert(const T& data, const Iterator<T>& iterator);
        void remove(const Iterator<T>& iterator);
        int getSize() const;
        Iterator<T> find();
        void sort();

    private:
        class Node<T>;
        Node<T>* head;
        Node<T>* tail;
        int size;
};


template<class T>
class List<class T>::Iterator
{
    public:
        Iterator(); //Constructor
        ~Iterator(); //Destructor

        T& operator ++ ();
        T operator ++ (int);
        T& operator -- ();
        T operator -- (int);
        bool operator == (const Iterator<T>& iterator) const;
        bool operator != (const Iterator<T>& iterator) const;
        T& operator * ();

    private:
        List<T>* list;
        Node<T>* node;
};


template<class T>
class List<class T>::ConstIterator
{
    public:
        ConstIterator(); //Constructor
        ~ConstIterator(); //Destructor

        T& operator ++ ();
        T operator ++ (int);
        T& operator -- ();
        T operator -- (int);
        bool operator == (const ConstIterator<T>& iterator) const;
        bool operator != (const ConstIterator<T>& iterator) const;
        T& operator * ();

    private:
        const List<T> * list;
        const Node<T> * node;
};


template<class T>
class List<class T>::Node
{
    public:
        Node(const T& _data, const Node* _next = NULL) : data(_data), next(_next) {} //Constructor
        ~Node(); //Destructor

    private:
        T data;
        Node* next;
};

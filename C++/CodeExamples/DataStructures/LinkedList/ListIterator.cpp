/*
here are two options where to declare Node and Iterator. Inside the list class as List<T>::Node or outside as Node<T>. It is, in part, a matter of taste. From engineering perspective though, the symbol names are longer for nested classes, so your debuginfo is bigger. Also, when nested classes are also templates it is harder to specialize them if/when necessary (because that requires fully specializing the enclosing template first), but this is not the case here.

It leads to more elegant code when one list node is used as list head and tail. Empty list is a node whose next and prev point to itself. push_front appends to list.next which points to the first node or itself. push_back appends a node to list.prev which points to the last node or itself. When inserting/removing nodes there is no need to have special handling of the first and last nodes. E.g. :
*/

template<class T>
class List;

class Iterator;

class Node {
    friend class Iterator;
    template<class T> friend class List;

protected:
    Node *next_, *prev_;

    void push_back(Node* n) {
        n->next_ = this;
        n->prev_ = prev_;
        prev_->next_ = n;
        prev_ = n;
    }

    void unlink() {
        Node *next = next_, *prev = prev_;
        next->prev_ = prev;
        prev->next_ = next;
        next_ = this;
        prev_ = this;
    }

public:
    Node()
        : next_(this), prev_(this)
    {}

    ~Node() { unlink(); }
};

class Iterator {
protected:
    Node* node_;

    Iterator(Node* node)
        : node_(node)
    {}

public:
    Iterator& operator++() {
        node_ = node_->next_;
        return *this;
    }

    bool operator==(Iterator b) const { return node_ == b.node_; }
    bool operator!=(Iterator b) const { return node_ != b.node_; }

    // Implement the rest of iterator interface.
};

template<class T>
class List {
    class NodeT : public Node {
        friend class List<T>;
        T value_;
        NodeT(T t) : value_(t) {}
    };

    template<class U>
    class IteratorT : public Iterator {
        friend class List<T>;
        NodeT* node() const { return static_cast<NodeT*>(node_); }
    public:
        U& operator*() const { return node()->value_; }
        U* operator->() const { return &node()->value_; }
        operator IteratorT<U const>() const { return node_; } // iterator to const_iterator conversion
        IteratorT(Node* node) : Iterator{node} {}
    };

    Node list_;

public:
    using iterator = IteratorT<T>;
    using const_iterator = IteratorT<T const>;

    ~List() { clear(); }

    bool empty() const { return list_.next_ == &list_; }

    iterator begin() { return list_.next_; }
    iterator end() { return &list_; }

    void push_back(T t) { list_.push_back(new NodeT(t)); }
    void erase(const_iterator i) { delete i.node(); }

    void clear() {
        while(!empty())
            erase(begin());
    }

    // Implement the rest of the functionality.
};

int main() {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    for(auto elem : l)
        std::cout << elem << ' ';
    std::cout << '\n';
}

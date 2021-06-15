#include <iostream>

using namespace std;

template <typename T>
class Node {
  public:
    T value;
    Node *next;
    Node *previous;

    Node(T value) { this->value = value; }
  };

template <typename T>
class Queue {


private:
  int size_;
  Node<T> *head_ = nullptr;
  Node<T> *tail_ = nullptr;
  Node<T> *itr_ = nullptr;

public:
  Queue() { this->size_ = 0; }

  void enqueue(T value) {
    if (this->head_ == nullptr) {
      this->head_ = new Node<T>(value);
      this->tail_ = this->head_;
    } else {
      this->tail_->next = new Node<T>(value);
      this->tail_->next->previous = this->tail_;
      this->tail_ = this->tail_->next;
    }
    this->size_ += 1;
  }

  Node<T> dequeue() {
    Node<T> *tmp = this->tail_;

    this->tail_ = this->tail->previous;
    this->tail_->next = nullptr;
    this->size_ -= 1;
    return tmp;
  }
  Node<T> *iterate()
    {
        if (this->itr_ == nullptr)
        {
            this->itr_ = this->head_;
        }
        else
        {
            this->itr_ = this->itr_->next;
        }
        return this->itr_;
    }

    T ptr()
    {
        return this->itr_->value;
    }

    void resetIterator()
    {
        this->itr_ = nullptr;
    }
};

int main(int argc, char **argv)
{
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(12);
    q1.enqueue(14);
    q1.enqueue(16);
    q1.enqueue(5);
    q1.enqueue(4);
    q1.enqueue(3);
    q1.enqueue(2);
    q1.enqueue(1);

    cout << "Printing Queue" << endl;

    while (q1.iterate() != nullptr)
        cout << q1.ptr() << "\t";

    cout << endl;

    return 0;
}

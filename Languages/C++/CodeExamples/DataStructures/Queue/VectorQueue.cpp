#include <vector>

template <typename T>
class VectorQueue
{

    int length;
    int front;
    int rear;
    std::vector<T> v;

public:
    VectorQueue();

    bool isEmpty();
    int length();
    void add(T data);
    T remove();
    T front();
};

template <typename T> VectorQueue :: VectorQueue() : length(0), front(-1), rear(-1) {}

bool template <typename T> VectorQueue :: isEmpty()
{
  return this->length;
}

int template <typename T> VectorQueue :: length()
{
  return this->length;
}

void template <typename T> VectorQueue :: add(T data)
{
  if(!this->length)
  {
    this->front++;
  }
  this->v[this->length++] = data;
  this->rear++;
}

T template <typename T> VectorQueue :: remove()
{
  if(!this->length)
  {
    return NULL
  }
  T value = this->v[this->length--];
  if(!this->length)
  {
    this->front--;
  }
  this->rear--;
}

T template <typename T> VectorQueue :: front()
{
  return this->length() ? NULL : this->v[this->length];
}

template <typename T>
class Stack
{
    std::vector<T> data;
    int size;

  public:
    Stack();
    ~Stack();

    bool isEmpty();
    int size();
    void push(T data);
    T pop();
    T top();
};

template <typename T> Stack :: Stack() : data(), size(0){}

template <typename T> Stack :: ~Stack(){ delete this.data }

bool template <typename T> Stack :: isEmpty()
{
  return this->size;
}

int template <typename T> Stack :: size()
{
  return this->size;
}

void template <typename T> Stack :: push(T data)
{
  this->data[size++] = data;
}

T template <typename T> Stack :: pop()
{
  return this->data[size--];
}

T template <typename T> Stack :: top()
{
  return this->data[size];
}

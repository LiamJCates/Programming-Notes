/*
The DynamicArray class specifies an initial size of 5.
In the add function, we can see that if we have reached the max capacity, the array size is doubled and copied.

This is how vector<T> data structure works in reality, typically with a base size is around 30.

Knowing this could come in handle in an interview.

One more thing to note is that we are using both constructors and destructors.
This is because we have a pointer to memory that we allocate as the array expands.
This allocated memory must be released to avoid overflows.
The beauty of this implementation is that the user does not have to know anything about the ugly pointers. 

Overloading the operator[] allows indexed access like a native array.

*/

using namespace std;

class DynamicArray
{
private:
    int size_;
    int max_;
    int *arrayholder_;

public:
    DynamicArray()
    {
        this->size_ = 0;
        this->max_ = 5;
        this->arrayholder_ = new int[5];
    }

    ~DynamicArray()
    {
        delete[] this->arrayholder_;
    }

    int size()
    {
        return this->size_;
    }

    int& operator[](int i)
    {
        assert(i < this->size_);
        return this->arrayholder_[i];
    }

    void add(int n)
    {
        if (this->max_ < this->size_ + 1)
        {
            this->max_ *= 2;
            int *tmp_ = new int[this->max_];

            for (size_t i = 0; i < this->size_; i++)
            {
                tmp_[i] = this->arrayholder_[i];

            }
            delete[] this->arrayholder_;
            this->arrayholder_ = tmp_;
            this->arrayholder_[this->size_] = n;
            this->size_ += 1;
        }
        else
        {
            this->arrayholder_[this->size_] = n;
            this->size_ += 1;
        }
    }
};

int main(int argc, char **argv)
{
    DynamicArray darray;
    vector<int> varray;

    for (size_t i = 0; i <= 15; i++)
    {
        darray.add(i);
    }
    return 0;
}

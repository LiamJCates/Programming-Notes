Vector

std::array is a really good improvement over C-style arrays. But there are some limitations of std::array, where it lacks functions for some frequent use cases while writing applications. Here are some of the major drawbacks of std::array:

• The size of std::array must be constant and provided at compile time, and fixed. So, we can't change it at runtime.

• Due to size limitations, we can't insert or remove elements from the array.

• No custom allocation is possible for std::array. It always uses stack memory.

In the majority of real-life applications, data is quite dynamic and not a fixed size.

std::vector solves one of the most prominent problems of arrays – fixed size. std::vector does not require us to provide its length during initialization.

Vector implementation in C++ Collections
Vector<E> in by C++ Collections is a collection of similar type of variables.

Vector is an implementation as dynamic array that can grow or shrink as needed.
(Internally array is used when it is full a bigger array is allocated and the old array values are copied to it.)

Vectors store multiple data elements of same data types in contiguous storage location just like arrays. There elements can also be accessed using offsets and are as efficient as arrays. But unlike arrays the size of vectors can change dynamically. The data storage is handled automatically by the vector.

Here are some of the ways in which we can initialize a vector:
std::vector<int> vec;
// Declares vector of size 0
std::vector<int> vec = {1, 2, 3, 4, 5};
// Declares vector of size 5 with provided elements
std::vector<int> vec(10);
// Declares vector of size 10
std::vector<int> vec(10, 5);
// Declares vector of size 10 with each element's value = 5

As we can see from the first initialization, providing the size is not mandatory. If we don't specify the size explicitly, and if we don't infer it by specifying its elements, the vector is initialized with the capacity of elements depending on the compiler implementation. The term "size" refers to the number of elements actually present in the vector, which may differ from its capacity. So, for the first initialization, the size will be zero, but the capacity could be some small number or zero.

We can insert elements inside the vector using the push_back or insert functions. push_
back will insert elements at the end. insert takes the iterator as the first parameter for
the position, and it can be used to insert the element in any location. push_back is a very
frequently used function for vectors because of its performance. The pseudocode of the
algorithm for push_back would be as follows:
push_back(val):
if size < capacity
// If vector has enough space to accommodate this element
- Set element after the current last element = val
- Increment size
- return;
if vector is already full
- Allocate memory of size 2*size
- Copy/Move elements to newly allocated memory
- Make original data point to new memory
- Insert the element at the end
The actual implementation might differ a bit, but the logic remains the same. As we
can see, if there's enough space, it only takes O(1) time to insert something at the back.
However, if there's not enough space, it will have to copy/move all the elements, which
will take O(n) time. Most of the implementations double the size of the vector every
time we run out of capacity. Hence, the O(n) time operation is done after n elements.
So, on average, it just takes one extra step, making its average time complexity closer to
O(1). This, in practice, provides pretty good performance, and, hence, it is a highly used
container.
For the insert function, you don't have any option other than to shift the elements that
come after the given iterator to the right. The insert function does that for us. It also
takes care of reallocation whenever it is required. Due to the need to shift the elements,
it takes O(n) time.

void vectorExample()
{
  std::vector<int> vec;
  for (int i = 0; i < 10; i++)
    vec.push_back(i);

  printVector(vec);
}

Analysis: Defines a vector of integer vec. Value 0 to 9 is added to the vector by calling push_back() method. Vector is passed to printVector() method. No need to pass size of vector it keep track of its size too.

void printVector(std::vector<int> &data)
{
  int count = data.size();
  std::cout << "Values stored are : ";
  for (int i = 0; i < count; i++)
    std::cout << " " << data[i];

}
Analysis:
· Size of the vector is stored inside count variable.
· For loop is executed for all the elements of the vector. .
· Finally vector values are printed to screen using the std::cout in a for loop.

Point to Remember:
1. Vector index always starts from 0 index and highest index is size - 1.
2. The subscript operator has highest precedence if you write vec[2]++. Then the value of vec[2] will be incremented.

Note:- Vector has mental model same as array so we will use vector and array as interchangeably. We will prefer vectors over array in most of the cases



The generic insert function can be used to insert an element at the front, as follows:
vec.insert(int.begin(), 0);

Let's take a look a few more examples of the push_back and insert functions:

std::vector<int> vec;
// Empty vector {}

vec.push_back(1);
// Vector has one element {1}

vec.push_back(2);
// Vector has 2 elements {1, 2}

vec.insert(vec.begin(), 0);
// Vector has 3 elements {0, 1, 2}

vec.insert(find(vec.begin(), vec.end(), 1), 4);
// Vector has 4 elements {0, 4, 1, 2}

As shown in the preceding code, push_back inserts an element at the end. Additionally,
the insert function takes the insertion position as a parameter. It takes it in the form of an iterator. So, the begin() function allows us to insert an element at the beginning.


One of the drawbacks of push_back and insert is that they first construct the element, and then either copy or move the element to its new location inside the vector's buffer.

This operation can be optimized by calling a constructor for the new element at the new location itself, which can be done by the emplace_back and emplace functions. It is recommended that you use these functions instead of normal insertion functions for better performance. Since we are constructing the element in place, we just need to pass the constructor parameters, instead of the constructed value itself. Then, the function will take care of forwarding the arguments to the constructor at the appropriate location.

std::vector also provides pop_back and erase functions to remove elements from it. pop_back removes the last element from the vector, effectively reducing the size by
one. erase has two overloads – to remove the single element provided by the iterator
pointing to it, and to remove a range of elements provided by the iterator, where the
range is defined by defining the first element to be removed (inclusive) and the last
element to be removed (exclusive). The C++ standard doesn't require these functions to
reduce the capacity of the vector. It depends entirely on the compiler implementation.
pop_back doesn't require any rearranging of elements, and hence can be completed very
quickly. Its complexity is O(1). However, erase requires the shifting of the elements, and
hence takes O(n) time. In the following exercise, we shall see how these functions are
implemented.
Now, let's take a look at the example about removing elements from a vector in different
ways:
Consider a vector with 10 elements – {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:
vec.pop_back();
// Vector has now 9 elements {0, 1, 2, 3, 4, 5, 6, 7, 8}
vec.erase(vec.begin());
// vector has now 7 elements {1, 2, 3, 4, 5, 6, 7, 8}
vec.erase(vec.begin() + 1, vec.begin() + 4);
// Now, vector has 4 elements {1, 5, 6, 7, 8}std::vector | 23
Now, let's take a look at some other useful functions:
• clear(): This function simply empties the vector by removing all of the elements.
• reserve(capacity): This function is used to specify the capacity of the vector.
If the value specified as the parameter is greater than the current capacity, it
reallocates memory and the new capacity will be equal to the parameter. However,
for all other cases, it will not affect the vector's capacity. This function doesn't
modify the size of the vector.
• shrink_to_fit(): This function can be used to free up the extra space. After calling this function, size and capacity become equal. This function can be used when we are not expecting a further increase in the size of the vector.


Allocators for std::vector

std::vector resolves the drawback of std::array regarding custom allocators by allowing us to pass an allocator as a template parameter after the type of data.

To use custom allocators, we follow certain concepts and interfaces. Since a vector uses allocator functions for most of its behaviors related to memory access, we need to provide those functions as part of the allocator – allocate, deallocate, construct, and destroy. This allocator will have to take care of memory allocation, deallocation, and handling so as not to corrupt any data.

For advanced applications, where relying on automatic memory management, mechanisms can be too costly, and where the application has got its own memory pool or similar resource that must be used instead of default heap memory, a customer allocator is very handy. Therefore, std::vector is a really good alternative to std::array and provides a lot more flexibility in terms of its size, growth, and other aspects.

Asymptotically, all the similar functions of an array have the same time complexity as a vector. We usually pay extra performance cost only for the extra features, which is quite reasonable. For an average case, the performance of a vector is not very far from an array. Hence, in practice, std::vector is one of the most commonly used STL containers in C++ because of its flexibility and performance.

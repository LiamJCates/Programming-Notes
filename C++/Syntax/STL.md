ANSI/ISO Standard C11 is equipped with a Standard Template Library (STL).
Among other things, the STL provides class templates to process lists (contiguous
or linked), stacks, and queues.

Components of the STL
The main objective of a program is to manipulate data and generate results. Achieving this goal requires the ability to store data into computer memory, access a particular
piece of data, and write algorithms to manipulate the data.
For example, if all data items are of the same type and we have some idea of the number of data items, we could use an array to store the data. We can then use an index to access a particular component of the array. Using a loop and the array index, we can
step through the elements of the array. Algorithms, such as those for initializing the array, sorting, and searching, are used to manipulate the data stored in an array. On the other hand, if we do not want to be concerned about the size of the data, we can use a linked list to process it. If the data needs to be processed in a Last In First Out (LIFO) manner, we can use a stack. Similarly, if the data needs to be processed in a
First In First Out (FIFO) manner, we can use a queue.

The STL is equipped with these features to effectively manipulate data. More formally, the STL has three main components:
? Containers
? Iterators
? Algorithms

Containers and iterators are class templates. Iterators are used to step through the elements of a container. Algorithms are used to manipulate data. The following
sections discuss each of these components in detail.

Container Types
Containers are used to manage objects of a given type. The STL containers are classified into the following three categories:
? Sequence containers (also called sequential containers)
? Associative containers
? Container adapters

Sequence Containers
Every object in a sequence container has a specific position. The three predefined sequence containers are as follows:
? vector
? deque
? list

vector
A vector container stores and manages its objects in a dynamic array. Because an
array is a random access data structure, the elements of a vector can be accessed
randomly. Item insertion in the middle or beginning of an array is time consuming,
especially if the array is large. However, inserting an item at the end is quite fast.
The name of the class that implements the vector container is vector.

The name of the header file containing the class
vector is vector. Thus, to use a vector container in a program, the program must
include the following statement:
#include <vector>
Furthermore, to define an object of type vector, we must specify the type of the
object because the class vector is a class template. For example, the statement
vector<int> intList;
declares intList to be a vector and the component type to be int. Similarly, the statement
vector<string> stringList;
declares stringList to be a vector container and the component type to be string.

DECLARING VECTOR OBJECTS
| Constructor | Effects |
|-------------|---------|
| vector<elemType> vecList; |
Creates the empty vector container vecList. (default constructor) |
| vector<elemType> vecList(otherVecList); | Creates the vector container vecList and initializes vecList to the elements of the vector otherVecList. vecList and other VecList are of the same type. |
| vector<elemType> vecList(size); | Creates the vector container vecList of size size. vecList is initialized using the default constructor. |
| vector<elemType> vecList(n, elm); | Creates the vector container vecList of size n. vecList is initialized using n copies of the element elm. |
| vector<elemType> vecList(beg, end); | Creates the vector container vecList. vecList is initialized to the elements in the range [beg, end), that is, all the elements in the range beg. . .end-1. Both beg and end are pointers, called iterators in STL terminology. |

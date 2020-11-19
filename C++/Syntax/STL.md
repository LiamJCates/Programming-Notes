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




Member Functions Common to All Containers


| Member function | Description |
|-----------------|-------------|
| Default constructor | Initializes the object to an empty state. |
| Constructor with parameters | In addition to the default constructor, every container has constructors with parameters. We will describe these constructors when we discuss a specific container. |
| Copy constructor | Executes when an object is passed as a parameter by value and when an object is declared and initialized using another object of the same type. |
| Destructor | Executes when the object goes out of scope. |
| ct.empty() | Returns true if container ct is empty, false otherwise. |
| ct.size() | Returns the number of elements currently in container ct. |
| ct.max_size() | Returns the maximum number of elements that can be inserted in container ct. |
| ct1.swap(ct2); | Swaps the elements of containers ct1 and ct2. |
| ct.begin() | Returns an iterator to the first element into container ct. |
| ct.end() | Returns an iterator to the position after the last element into container ct. |
| ct.rbegin() | Reverse begin. Returns a pointer to the last element into container ct. This function is used to process the elements of ct in reverse. |
| ct.rend() | Reverse end. Returns a pointer to the position before the first element into container ct.
| ct.insert(position,elem); | Inserts elem into container ct at the position specified by position. Note that here, position is an iterator. |
| ct.erase(beg, end); | Deletes all of the elements between beg...end-1 from container ct. Both beg and end are iterators. |
| ct.clear(); | Deletes all of the elements from the container. After a call to this function, container ct is empty. |

| Operator | Effect |
|----------|--------|
| ct1 = ct2; | Copies the elements of ct2 into ct1. After this operation, the elements in both containers are the same. |
| ct1 == ct2 | Returns true if containers ct1 and ct2 are equal, false otherwise. |
| ct1 != ct2 | Returns true if containers ct1 and ct2 are not equal, false otherwise. |






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
| vector<elemType> vec; | Creates the empty vector container vec. (default constructor) |
| vector<elemType> vec(othervec); | Creates the vector container vec and initializes vec to the elements of the vector othervec. vec and other vec are of the same type. |
| vector<elemType> vec(size); | Creates the vector container vec of size size. vec is initialized using the default constructor. |
| vector<elemType> vec(n, elm); | Creates the vector container vec of size n. vec is initialized using n copies of the element elm. |
| vector<elemType> vec(beg, end); | Creates the vector container vec. vec is initialized to the elements in the range [beg, end), that is, all the elements in the range beg. . .end-1. Both beg and end are pointers, called iterators in STL terminology. |

Now that we know how to declare a vector sequence container, let us discuss how to
manipulate the data stored in a vector container. In order to manipulate the data in a vector container, we must know the following basic operations:


| Expression | Description|
|------------|------------|
|vec.at(index) | Returns the element at the position specified by index. |
| vec[index] | Returns the element at the position specified by index. |
| vec.front() | Returns the first element. (Does not check whether the container is empty.) |
| vec.back() | Returns the last element. (Does not check whether the container is empty.) |
| vecCont.capacity() | Returns the maximum number of elements that can be inserted into the container vecCont without reallocation. |
| vecCont.empty() | Returns true if the container vecCont is empty, false otherwise. |
| vecCont.size() | Returns the number of elements currently in the container vecCont. |
| vecCont.max_size() | Returns the maximum number of elements that can be inserted into the container vecCont. |
| vec.clear(); | Deletes all of the elements from the container. |
| vec.erase(position); | Deletes the element at the position specified by position. |
| vec.erase(beg, end); | Deletes all of the elements starting at beg until end-1. |
| vec.insert(position, elem); | A copy of elem is inserted at the position specified by position. The position of the
new element is returned. |
| vec.insert(position, n, elem) | n copies of elem are inserted at the position specified by position. |
| vec.insert(position, beg, end); | A copy of the elements, starting at beg until end-1, is inserted into vec at the
position specified by position. |
| vec.push_back(elem); | A copy of elem is inserted into vec at the end. |
| vec.pop_back(); | Deletes the last element.
| vec.resize(num); | Changes the number of elements to num. If size increases, the default constructor creates the new elements. |
| vec.resize(num, elem); | Changes the number of elements to num. If size increases, the new elements are copies of elem. |

### DECLARING AN ITERATOR TO A VECTOR CONTAINER
The class vector contains a typedef iterator, which is declared as a public member. An iterator to a vector container is declared using the typedef iterator:

vector<int>::iterator intVecIter;

declares intVecIter to be an iterator in a vector container of type int.

Suppose that we have the following statements:
vector<int> intList; //Line 1
vector<int>::iterator intVecIter; //Line 2
The statement in Line 1 declares intList to be a vector container, and the element
type is int. The statement in Line 2 declares intVecIter to be an iterator in a vector
container whose element type is int.

### CONTAINERS AND THE FUNCTIONS begin AND end
Every container has the member functions begin and end. The function begin
returns the position of the first element in the container; the function end returns the
position of one past the last element in the container. Also, these functions have no
parameters.
After the following statement executes
intVecIter = intList.begin();
the iterator intVecIter points to the first element in the container intList.
The following for loop outputs the elements of intList to the standard output
device.
for (intVecIter = intList.begin(); intVecIter != intList.end();
++intVecIter)
cout << *intVecIter << " ";

Because iterator is a typedef defined inside the class vector, we must use the container name (which is vector), the container element type, and the scope resolution operator to use the typedef iterator.
The expression
++intVecIter
advances the iterator intVecIter to the next element in the container, and the
expression
*intVecIter
returns the element at the current iterator position.

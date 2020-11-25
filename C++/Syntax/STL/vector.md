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


### THE ostream ITERATOR AND THE FUNCTION copy
a special type of iterators called
ostream iterators. These iterators work well with the function copy to copy the
elements of a container to an output device.

One way to output the contents of a container is to use a for loop, the function
begin to initialize the for loop control variable, and the function end to set the limit.
Alternatively, the function copy can be used to output the elements of a container. In
this case, an iterator of type ostream specifies the destination. (ostream iterators are
discussed in detail later in this chapter.) When we create an iterator of type ostream,
we also specify the type of element that the iterator will output.
The following statement illustrates how to create an ostream iterator of type int:
ostream_iterator<int> screen(cout, " ");

This statement creates screen to be an ostream iterator with the element type int.
The iterator screen has two arguments: the object cout and a space. Thus, the iterator screen is initialized using the object cout. When this iterator outputs elements,
they are separated by a space.
The statement
copy(intArray, intArray + 9, screen);
outputs the elements of intArray on the screen. Similarly, the statement
copy(vecList.begin(), vecList.end(), screen);
outputs the elements of the container vecList on the screen.

Of course, we can directly specify an ostream iterator in the function copy the statement
copy(vecList.begin(), vecList.end(),
ostream_iterator<int>(cout, ", "));
outputs the elements of vecList with a comma and space between them.

Initializing vector Objects during Declaration
whlile the following statements can be used to declare intList to be a vector<int> object and store 13, 75, 28, and 35 in intList:

vector<int> intList;
intList.push_back(13);
intList.push_back(75);
intList.push_back(28);
intList.push_back(35);
C++ 11 allows a vector object to be declared and initialized at the same time. For example, the following statement declares inList to be a vector<int> object an stores 13, 75, 28, and 35 in it.

vector<int> intList = {13, 75, 28, 35};
That is, in C++ 11, the five statements used earlier to declare and initialize intList can be replaced by the preceding statement.

Array
Arrays are the most basic data structures used to store information. An array is a data structure used to store multiple data elements of the same data type. All the data is stored sequentially. The value stored at any index can be accessed in constant time.

Arrays can store a fixed number of elements, whereas a collection stores object dynamically so there is no size restrictions it grows and shrinks automatically.

Array ADT Operations
Below is the API of array:
1. Adds an element at kth position
    Value can be stored in array at Kth position in O(1) constant time. We just need to store value at arr[k].
2. Reading the value stored at kth position.
    Accessing value stored a some location in array is also O(1) constant time.
    We just need to read value stored at arr[k].

C++ standard arrays are of fixed length. Sometime we do not know how much memory we need so we create a bigger size array. There by wasting space to avoid this situation C++ Collection framework had implemented ArrayList to solve this problem.



void arrayExample()
{
  int arr[10];
  for (int i = 0; i < 10; i++)
    arr[i] = i;

    printArray(arr, 10);
}

Analysis: Defines an array of integer arr. The array is of size 10 - which means that it can store 10 integers inside it. Array elements are accessed using the subscript operator []. Lowest subscript is 0 and highest subscript is (size – 1). Value 0 to 9 is stored in the array at index 0 to 9.
Array and its size are passed to printArray() method.

void printArray(int arr[], int count)
{
  std::cout << "Values stored in vector are : " << std::endl;
  for (int i = 0; i < count; i++)
    std::cout << " " << arr[i] << std::endl;
}

Analysis:
· Array variable arr and its variable count are passed as arguments to
printArray() method.
· Finally array values are printed to screen using std::cout in a for loop.
Point to Remember:
1. Array index always starts from 0 index and highest index is size -1.2. The subscript operator has highest precedence if you write arr[2]++. Then
the value of arr[2] will be incremented.










Vector
Vectors store multiple data elements of same data types in contiguous storage location just like arrays. There elements can also be accessed using offsets and are as efficient as arrays. But unlike arrays the size of vectors can change dynamically. The data storage is handled automatically by the vector.

Vector implementation in C++ Collections
Vector<E> in by C++ Collections is a collection of similar type of variables.Vector is an implementation as dynamic array that can grow or shrink as needed.
(Internally array is used when it is full a bigger array is allocated and the old array values are copied to it.)

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

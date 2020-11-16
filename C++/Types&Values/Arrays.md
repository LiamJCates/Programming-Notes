## Array
The most fundamental collection of data is a contiguously allocated sequence of elements of the same type, called an array.

arrays enable you to store data elements of  identical type in the memory, in a sequential and ordered fashion.

To declare five distinct and unique integer variables and use them to store by declaring an array of five integers each initialized to zero, like this:

int myNumbers [5] = {};



You can initialize its contents on a per-element basis:

int myNumbers [5] = {34, 56, -21, 5002, 365}

Or partially initialize elements:
int myNumbers [5] = {34, 56};

The remaining elements may be default initialized depending on the type of the array but a value should be assigned to them before they are used.

The general format:
ElementType ArrayName [constant_number of elements] = {optional initial values};

Such arrays are called static arrays because the number of elements they contain as well as the memory the array consumes is fixed at the time of compilation.



You can define the length of an array as a constant:
const int ARRAY_LENGTH = 5;
int myNumbers [ARRAY_LENGTH] = {34, 56, -21, 5002, 365};

This is particularly useful when you need to access and use the length of the array at multiple places, such as when iterating elements in one, and then instead of having to change the length at each of those places, you just correct the initialization value at the const int declaration.



You can opt to leave out the number of elements in an array if you know the initial values of the elements in the array:
int myNumbers [] = {2016, 2052, -525}; // array of 3 elements



Arrays declared thus far are called static arrays as the length of the array is a constant and fixed by the programmer at compile-time. This array cannot take more data than what the programmer has specified. It also does not consume any less memory if left half-used or unused. Arrays where the length is decided at execution-time are called dynamic arrays.




## array access

Elements in an array can be accessed using their zero-based index.
In other words, the index of the last element in an array is always (Length of Array – 1).

When asked to access element at index N, the compiler uses the memory address of the first element (positioned at index zero) as the starting point and then skips N elements by adding the offset computed as N * sizeof(element) to reach the address containing the (N+1)th element.

The C++ compiler does not check if the index is within the actual
defined bounds of the array. You can try fetching the element at index 1001 in an array of only 10 elements, putting the security and stability of your program at risk. The onus of ensuring that the array is not accessed beyond its bounds lies solely on the programmer. Accessing an array beyond its bounds results in unpredictable
behavior. In many cases this causes your program to crash.
Accessing arrays beyond their bounds should be avoided at
all costs.


## sizeof an array
Use the sizeof operator to obtain the total size in bytes of an array.

In general, the amount of memory reserved by the compiler for an array:
Bytes consumed by an array = sizeof(element-type) * Number of Elements

You can use a simple trick to determine the number of elements in an array: divide the size of the array by the size of a single constituent element:
short array[] = { 104, 105, 32, 98, 105, 108, 108, 0 };
size_t n_elements = sizeof(array)u / sizeof(short)v;

On most systems, sizeof(array) u will evaluate to 16 bytes and
sizeof(short) v will evaluate to 2 bytes. Regardless of the size of a short,
n_elements will always initialize to 8 because the factor will cancel. This
evaluation happens at compile time, so there is no runtime cost in evaluating the length of an array in this way.
The sizeof(x)/sizeof(y) construction is a bit of a hack, but it’s widely used in older code.

##std::size
If you really
must use an array, you can safely obtain the number of elements using the
std::size() function available in the <iterator> header.

std::size can be used with any container that exposes a
size method. This includes all the containers in Chapter 13. This is especially useful
when writing generic code, a topic you’ll explore in Chapter 6. Further, it will refuse
to compile if you accidentally pass an unsupported type, like a pointer.



## Multidimensional arrays
C++ enables you to declare multidimensional arrays by indicating the number of elements you want to reserve in each dimension.

arrayType arrayName [rows] [columns];

int solarPanels [2][3] = {{0, 1, 2}, {3, 4, 5}};

|0|1|2|
|3|4|5|

Even though C++ enables us to model multidimensional arrays,
the memory where the array is contained is one-dimensional. So,
the compiler maps the multidimensional array into the memory
space, which expands only in one direction.
If you wanted to, you could also initialize the array called
solarPanels like the following, and it would still contain the
same values in the respective elements:
int solarPanels [2][3] = {0, 1, 2, 3, 4, 5};
However, the earlier method makes a better example because
it’s easier to imagine and understand a multidimensional array
as an array of arrays.

When you need to access an integer in this array, you would need to use a first subscript
to address the array where the integer is and the second subscript to address that integer
in this array.






## Dynamic Arrays
To program an application that is able to optimally consume memory resources on the basis of the needs of the user, you need to use dynamic memory allocation. This enables you to allocate more when you need more memory and release memory that you have in excess. C++ supplies you two operators, new and delete, to help you better manage the memory consumption of your application. Pointers being variables that are used to contain memory addresses play a critical role in efficient dynamic memory allocation.

choose dynamic arrays that optimize memory consumption and scale up depending on the demand for resources and memory at execution-time. C++ provides you with convenient and easy-to-use dynamic arrays in the form of std::vector

 #include <iostream>
 #include <vector>

using namespace std;
//using std::vector;

int main()
{
vector<int> dynArray (3); // dynamic array of int

dynArray[0] = 365;
dynArray[1] = -421;
dynArray[2]= 789;

cout << "Number of integers in array" << dynArray.size() << endl;

cout << "Enter another element to insert" << endl;
int newValue = 0;
cin >> newValue;
dynArray.push_back(newValue);

cout << "Number of integers in array" << dynArray.size() << endl;
cout << "Last element in array";
cout << dynArray[dynArray.size() - 1] << endl;
return 0;

}

To use the dynamic array class std::vector, you need to
include header vector.
 #include <vector>

[vector].push_back();
adds element to the end of the collection

ranged for loop useful for vector collection iteration


## iterator
vector<int> nums;

for(auto i=begin(nums); i != end(nums); i++){
  cout << *i << " ";
}
i is an iterator and needs a * to be accessed







## algorithm

#include <algorithm>

algorithm functions are called free functions an work with the vector class and other collection classes

vector<string> strs;

sort(begin(strs), end(strs));

vector<int> ints;
int threes = count(begin(ints), end(ints), 3);

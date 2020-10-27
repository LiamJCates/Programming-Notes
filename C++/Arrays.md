## Array
The most fundamental collection of data is a contiguously allocated sequence of elements of the same type, called an array.

arrays enable you to store data elements of a type in the memory, in a sequential and ordered fashion.

To declare five distinct and unique integer variables and use them to store by declaring an array of five integers each initialized to zero, like this:

int myNumbers [5] = {};

In general, the amount of memory reserved by the compiler for an array:
Bytes consumed by an array = sizeof(element-type) * Number of Elements

You can initialize its contents on a per-element basis:

int myNumbers [5] = {34, 56, -21, 5002, 365}

Or partially initialize elements, the rest defaulting to zero:
int myNumbers [5] = {34, 56};

Such arrays are called static arrays because the number of elements they contain as well
as the memory the array consumes is fixed at the time of compilation.

ElementType ArrayName [constant_number of elements] = {optional initial values};

You can define the length of an array (that is, the number of elements in one) as a
constant and use that constant in your array definition:
const int ARRAY_LENGTH = 5;
int myNumbers [ARRAY_LENGTH] = {34, 56, -21, 5002, 365};
This is particularly useful when you need to access and use the length of the array at
multiple places, such as when iterating elements in one, and then instead of having to
change the length at each of those places, you just correct the initialization value at the
const int declaration.
You can opt to leave out the number of elements in an array if you know the initial values
of the elements in the array:
int myNumbers [] = {2016, 2052, -525}; // array of 3 elements



Arrays declared thus far are called static arrays as the length
of the array is a constant and fixed by the programmer at
compile-time. This array cannot take more data than what the
programmer has specified. It also does not consume any less
memory if left half-used or unused. Arrays where the length is
decided at execution-time are called dynamic arrays.


Elements in an array can be accessed using their zero-based index. These indexes are
called zero-based because the first element in an array is at index 0. So, the first integer
value stored in the array myNumbers is myNumbers[0], the second is myNumbers[1],
and so on. The fifth is myNumbers[4]. In other words, the index of the last element in
an array is always (Length of Array – 1).
When asked to access element at index N, the compiler uses the memory address of the
first element (positioned at index zero) as the starting point and then skips N elements
by adding the offset computed as N*sizeof(element) to reach the address containing
the (N+1)th element. The C++ compiler does not check if the index is within the actual
defined bounds of the array. You can try fetching the element at index 1001 in an array of
only 10 elements, putting the security and stability of your program at risk. The onus of
ensuring that the array is not accessed beyond its bounds lies solely on the programmer.Accessing an array beyond its bounds results in unpredictable
behavior. In many cases this causes your program to crash.
Accessing arrays beyond their bounds should be avoided at
all costs.

C++ enables you to declare multidimensional arrays by indicating the number of
elements you want to reserve in each dimension.

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
To program an application that is able to optimally consume memory resources on the
basis of the needs of the user, you need to use dynamic memory allocation. This enables
you to allocate more when you need more memory and release memory that you have
in excess. C++ supplies you two operators, new and delete, to help you better manage
the memory consumption of your application. Pointers being variables that are used to
contain memory addresses play a critical role in efficient dynamic memory allocation.

choose
dynamic arrays that optimize memory consumption and scale up depending on the
demand for resources and memory at execution-time. C++ provides you with convenient
and easy-to-use dynamic arrays in the form of std::vector

 #include <iostream>
 #include <vector>

using namespace std;

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
include header vector, which is also shown in Line 1 of Listing 4.4.
 #include <vector>

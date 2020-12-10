## Array
The most fundamental collection of data is a contiguously allocated sequence of elements of the same type, called an array.

arrays enable you to store data elements of  identical type in the memory, in a sequential and ordered fashion.

syntax:
dataType arrayName[intExp];

in which intExp specifies the number of components in the array and can be any constant expression that evaluates to a positive integer.

To declare five distinct and unique integer variables and use them to store by declaring an array of five integers each initialized to zero, like this:
int myNumbers [5] = {};

You can initialize array contents on a per-element basis:
int myNumbers [5] = {34, 56, -21, 5002, 365}

Or partially initialize elements:
int myNumbers [5] = {34, 56};

During partial initialization, the remaining elements may be default initialized depending on the type of the array.

Good practice dictates a value should be assigned to each array elements before it is used.

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

The general form (syntax) used for accessing an array component is:
arrayName[indexExp]

in which indexExp, called the index, is any expression whose value is a nonnegative
integer. The index value specifies the position of the component in the array.
In C++, [] is an operator called the array subscripting operator. Moreover, in
C++, the array index starts at 0.
Consider the following statement:
int list[10];
This statement declares an array list of 10 components. The components are
list[0], list[1], . . ., list[9]. In other words, we have declared 10 variables.

When asked to access element at index N, the compiler uses the memory address of the first element (positioned at index zero) as the starting point and then skips N elements by adding the offset computed as N * sizeof(element) to reach the address containing the (N+1)th element.

The C++ compiler does not check if the index is within the actual
defined bounds of the array. You can try fetching the element at index 1001 in an array of only 10 elements, putting the security and stability of your program at risk. The onus of ensuring that the array is not accessed beyond its bounds lies solely on the programmer. Accessing an array beyond its bounds results in unpredictable
behavior. In many cases this causes your program to crash.
Accessing arrays beyond their bounds should be avoided at
all costs.


### Bounds
The index—say, index—of an array is in bounds if index is between 0 and
ARRAY_ SIZE - 1, that is, 0 <= index <= ARRAY_SIZE - 1. If index is negative or
index is greater than ARRAY_SIZE - 1, then we say that the index is out of bounds.
Unfortunately, C++ does not check whether the index value is within range—that is,
between 0 and ARRAY_SIZE - 1. If the index goes out of bounds and the program tries to
access the component specified by the index, then whatever memory location is indicated
by the index that location is accessed. This situation can result in altering or accessing
the data of a memory location that you never intended to modify or access, or in trying
to access protected memory that causes the program to instantly halt. Consequently,
several strange things can happen if the index goes out of bounds during execution. It
is solely the programmer’s responsibility to make sure that the index is within bounds.



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




## Restrictions on Arrays
Consider the following statements:
int myList[5] = {0, 4, 8, 12, 16};
int yourList[5];
Note that these arrays are of the same type and have the same number of components. Suppose that you want to copy the elements of myList into the corresponding elements of yourList.

The following statement is illegal:
yourList = myList; //illegal

In fact, this statement will generate a syntax error.

C++ does not allow aggregate operations on an array. An aggregate operation on an array is any operation that
manipulates the entire array as a single unit.

To copy one array into another array, you must copy it component-wise—that is, one component at a time. For example, the following statements copy myList into yourList.
yourList[0] = myList[0];
yourList[1] = myList[1];
yourList[2] = myList[2];
yourList[3] = myList[3];
yourList[4] = myList[4];

This can be accomplished more efficiently using a loop, such as the following:

for (int index = 0; index < 5; index++)
  yourList[index] = myList[index];

Next, suppose that you want to read data into the array yourList. The following statement is illegal and, in fact, would generate a syntax error:
cin >> yourList; //illegal

To read data into yourList, you must read one component at a time, using a loop such as the following:

for (int index = 0; index < 5; index++)
  cin >> yourList[index];

Similarly, determining whether two arrays have the same elements and printing the contents of an array must be done component-wise. Note that the following statements are legal in the sense that they do not generate a syntax error; however, they do not give the desired results as they deal with the array's base address.

cout << yourList;
if (myList <= yourList)


The base address of an array is the address (that is, the memory location) of the
first array component.

The base address of the array myList is the address of the component myList[0].
Suppose that the base address of the array myList is 1000. Then, the address of the
component myList[0] is 1000. Typically, the memory allocated for an int variable is
four bytes.

main memory is an ordered sequence of cells,
and each cell has a unique address. Typically, each cell is one byte. Therefore, to store
a value into myList[0], starting at the address 1000, the next four bytes are allocated
for myList[0]. It follows that the starting address of myList[1] is 1004, the starting
address of myList[2] is 1008, and so on

Now myList is the name of an array. There is also a memory space associated with
the identifier myList, and the base address of the array is stored in that memory
space. Consider the following statement:
cout << myList << endl; //Line 2
Earlier, we said that this statement will not give the desired result. That is, this statement will not output the values of the components of myList. In fact, the statement

outputs the value stored in myList, which is the base address of the array. This is why
the statement will not generate a syntax error.
Suppose that you also have the following statement:
int yourList[5];
Then, in the statement:
if (myList <= yourList) //Line 3
...
the expression myList <= yourList evaluates to true if the base address of the array
myList is less than the base address of the array yourList; and evaluates to false
otherwise. It does not determine whether the elements of myList are less than or
equal to the corresponding elements of yourList.

You might be wondering why the base address of an array is so important. The reason
is that when you declare an array, the only things about the array that the computer
remembers are the name of the array, its base address, the data type of each component, and (possibly) the number of components. Using the base address of the array,
the index of an array component, and the size of each component in bytes, the computer calculates the address of a particular component.

### As Parameters

By reference only: In C++, arrays are passed by reference only.

Because arrays are passed by reference only, you do not use the symbol & when declaring an array as a formal parameter.
When declaring a one-dimensional array as a formal parameter, the size of the array is usually omitted. If you specify the size of a one-dimensional array when it is declared as a formal parameter, the size is ignored by the compiler.

Consider the following function:
void funcArrayAsParam(int listOne[], double listTwo[])
{
.
.
.
}

To write a function
to process such arrays, in addition to declaring an array as a formal parameter, we
declare another formal parameter specifying the number of elements in the array, as
in the following function:
void initialize(int list[], int listSize)
{
for (int count = 0; count < listSize; count++)
list[count] = 0;
}
The first parameter of the function initialize is an int array of any size. When
the function initialize is called, the size of the actual array is passed as the second
parameter of the function initialize.

If C++ allowed arrays to be passed by value, the computer would have to allocate memory for the components of the formal parameter and copy the contents of the actual array
into the corresponding formal parameter when the function is called. If the array size was
large, this process would waste memory as well as the computer time needed for copying
the data. That is why in C++ arrays are always passed by reference.

functions also return the address of an array rather than copy each member back to the caller





Parallel Arrays
Two (or more) arrays are called parallel if their corresponding components hold related
information.

The statements:
int studentId[50];
char courseGrade[50];
declare these two arrays.
Suppose you need to input data into these arrays, and the data is provided in a file in
the following form:
studentId courseGrade
For example, a sample data set is:
23456 A
86723 B
22356 C
92733 B
11892 D
...
Suppose that the input file is opened using the ifstream variable infile. Because
the size of each array is 50, a maximum of 50 elements can be stored into each array.
Moreover, it is possible that there may be fewer than 50 students in the class. Therefore, while reading the data, we also count the number of students and ensure that
the array indices do not go out of bounds. The following loop reads the data into the
parallel arrays studentId and courseGrade:

int noOfStudents = 0;
infile >> studentId[noOfStudents] >> courseGrade[noOfStudents];
while (infile && noOfStudents++ < 50) {
infile >> studentId[noOfStudents] >> courseGrade[noOfStudents];
}
Note that, in general, when swapping values in one array, the corresponding values in
parallel arrays must also be swapped.








## Multidimensional arrays
C++ enables you to declare multidimensional arrays by indicating the number of elements you want to reserve in each dimension.

We can also define three-dimensional or larger arrays. In
C++, there is no limit, except the limit of the memory space, on the dimension of arrays. Following is the general definition of an array.
n-dimensional array: A collection of a fixed number of components arranged in n dimensions (n >= 1).

The general syntax for declaring an n-dimensional array is:
dataType arrayName[intExp1][intExp2] ... [intExpn];


where intExp1, intExp2, . . ., and intExpn are constant expressions yielding positive integer values.

The syntax to access a component of an n-dimensional array is:
arrayName[indexExp1][indexExp2] ... [indexExpn]


where indexExp1, indexExp2, . . ., and indexExpn are expressions yielding nonnegative integer values. indexExpi gives the position of the array component in the
ith dimension.








## Two-Dimensions
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


## Two-Dimensional Arrays and Enumeration Types
You can also use the enumeration type for array indices. Consider the following
statements:
const int NUMBER_OF_ROWS = 6;
const int NUMBER_OF_COLUMNS = 5;
enum carType {GM, FORD, TOYOTA, BMW, NISSAN, VOLVO};
enum colorType {RED, BROWN, BLACK, WHITE, GRAY};
int inStock[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];

These statements define the carType and colorType enumeration types and define
inStock as a two-dimensional array of six rows and five columns. Suppose that
each row in inStock corresponds to a car type, and each column in inStock corresponds to a color type. That is, the first row corresponds to the car type GM, the
second row corresponds to the car type FORD, and so on. Similarly, the first column
corresponds to the color type RED, the second column corresponds to the color type
BROWN, and so on. Suppose further that each entry in inStock represents the number
of cars of a particular type and color

The statement:
inStock[1][3] = 15;
is equivalent to the following statement:
inStock[FORD][WHITE] = 15;


### PROCESSING TWO-DIMENSIONAL ARRAYS
A two-dimensional array can be processed in four ways:
1. Process a single element.
2. Process the entire array.
3. Process a particular row of the array, called row processing.
4. Process a particular column of the array, called column processing.
Processing a single element is like processing a single variable. Initializing and printing the array are examples of processing the entire two-dimensional array. Finding the
largest element in a row (column) or finding the sum of a row (column) are examples
of row (column) processing. We will use the following declaration for our discussion:
const int NUMBER_OF_ROWS = 7; //This can be set to any number.
const int NUMBER_OF_COLUMNS = 6; //This can be set to any number.
int matrix[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
int row;
int col;
int sum;
int largest;
int temp;

All of the components of a two-dimensional array, whether rows or columns, are identical in type. If a row is looked at by itself, it can be seen to be just a one-dimensional
array. A column seen by itself is also a one-dimensional array. Therefore, when processing a particular row or column of a two-dimensional array, we use algorithms
similar to those that process one-dimensional arrays.

Suppose that we want to process row number 5 of matrix (that is, the sixth row of matrix).
We see that in these components, the first index (the row position) is fixed at 5. The second index (the column position) ranges from 0 to 5. Therefore, we can use the following for loop to process row number 5:
row = 5;
for (col = 0; col < NUMBER_OF_COLUMNS; col++)
process(matrix[row][col]

Similarly, suppose that we want to process column number 2 of matrix, the second index (that is, the column position) is fixed at 2. The first index (that is, the row position) ranges from 0 to 6. In this case, we can use the following for loop to process column 2 of matrix:
col = 2;
for (row = 0; row < NUMBER_OF_ROWS; row++)
process(matrix[row][col])


Passing Two-Dimensional Arrays as Parameters to Functions
Two-dimensional arrays can be passed as parameters to a function, and they are
passed by reference. The base address (that is, the address of the first component of
the actual parameter) is passed to the formal parameter. If matrix is the name of a
two-dimensional array, then matrix[0][0] is the first component of matrix.
When storing a two-dimensional array in the computer’s memory, C++ uses the row
order form. That is, the first row is stored first, followed by the second row, followed
by the third row, and so on.
In the case of a one-dimensional array, when declaring it as a formal parameter, we
usually omit the size of the array. Because C++ stores two-dimensional arrays in
row order form, to compute the address of a component correctly, the compiler must
know where one row ends and the next row begins. Thus, when declaring a twodimensional array as a formal parameter, you can omit the size of the first dimension,
but not the second; that is, you must specify the number of columns.
Suppose we have the following declaration:
const int NUMBER_OF_ROWS = 6;
const int NUMBER_OF_COLUMNS = 5;
Consider the following definition of the function printMatrix:
void printMatrix(int matrix[][NUMBER_OF_COLUMNS],
int noOfRows)
{
for (int row = 0; row < noOfRows; row++)
{
for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
cout << setw(5) << matrix[row][col] << " ";
cout << endl;
}
}
This function takes as a parameter a two-dimensional array of an unspecified number
of rows and five columns, and outputs the content of the two-dimensional array. During the function call, the number of columns of the actual parameter must match the
number of columns of the formal parameter.
Similarly, the following function outputs the sum of the elements of each row of a
two-dimensional array whose elements are of type int:
void sumRows(int matrix[][NUMBER_OF_COLUMNS], int noOfRows)
{
int sum;Two- and Multidimensional Arrays | 571
8
//Sum of each individual row
for (int row = 0; row < noOfRows; row++)
{
sum = 0;
for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
sum = sum + matrix[row][col];
cout << "Sum of row " << (row + 1) << " = " << sum
<< endl;
}
}
The following function determines the largest element in each row:
void largestInRows(int matrix[][NUMBER_OF_COLUMNS],
int noOfRows)
{
int largest;
//Largest element in each row
for (int row = 0; row < noOfRows; row++)
{
largest = matrix[row][0]; //Assume that the first element
//of the row is the largest.
for (int col = 1; col < NUMBER_OF_COLUMNS; col++)
if (largest < matrix[row][col])
largest = matrix[row][col];
cout << "The largest element of row " << (row + 1)
<< " = " << largest << endl;
}
}
Likewise, you can write a function to find the sum of the elements of each column,
read the data into a two-dimensional array, find the largest and/or smallest element
in each row or column, and so on.


### Another Way to Declare a Two-Dimensional Array

If you know the size of the tables with which the program will be working, then you
can use typedef to first define a two-dimensional array data type and then declare
variables of that type.
For example, consider the following:
const int NUMBER_OF_ROWS = 20;
const int NUMBER_OF_COLUMNS = 10;
typedef int tableType[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
The previous statement defines a two-dimensional array data type tableType. Now
we can declare variables of this type. So:
tableType matrix;
declares a two-dimensional array matrix of 20 rows and 10 columns.
You can also use this data type when declaring formal parameters, as shown in the
following code:
void initialize(tableType table)
{
for (int row = 0; row < NUMBER_OF_ROWS; row++)
for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
table[row][col] = 0;
}
This function takes as an argument any variable of type tableType, which is a twodimensional array containing 20 rows and 10 columns, and initializes the array to 0.
By first defining a data type, you do not need to keep checking the exact number of
columns when you declare a two-dimensional array as a variable or formal parameter,
or when you pass an array as a parameter during a function call.







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

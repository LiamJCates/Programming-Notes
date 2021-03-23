## Multidimensional arrays
C++ enables you to declare multidimensional arrays by indicating the number of elements you want to reserve in each dimension.

In C++ has no limit, except the limit of the memory space, on the dimension of arrays.

Following is the general definition of an array.

n-dimensional array: A collection of a fixed number of components arranged in n dimensions (n >= 1).

The general syntax for declaring an n-dimensional array is:

  dataType arrayName[intExp1][intExp2] ... [intExpn];


where intExp1, intExp2, . . ., and intExpn are constant expressions yielding positive integer values.

The syntax to access a component of an n-dimensional array is:

  arrayName[indexExp1][indexExp2] ... [indexExpn]


where indexExp1, indexExp2, . . ., and indexExpn are expressions yielding nonnegative integer values. indexExpi gives the position of the array component in the ith dimension.



## Two-Dimensions

  arrayType arrayName [rows] [columns];

  int solarPanels [2][3] = {{0, 1, 2}, {3, 4, 5}};

  |0|1|2|
  |3|4|5|

Even though C++ enables us to model multidimensional arrays, the memory where the array is contained is one-dimensional. So, the compiler maps the multidimensional array into the memory space, which expands only in one direction.

If matrix is the name of a two-dimensional array, then matrix[0][0] is the first component of matrix.


### Element Ordering
When storing a two-dimensional array in the computer’s memory, C++ uses the row
order form. That is, the first row is stored first, followed by the second row, followed by the third row, and so on.

If you wanted to, you could also initialize the array called solarPanels like the following, and it would still contain the same values in the respective elements:

  int solarPanels [2][3] = {0, 1, 2, 3, 4, 5};

However, the earlier method makes a better example because it’s easier to imagine and understand a multidimensional array as an array of arrays.

When you need to access an integer in this array, you would need to use a first subscript operator to address the array where the integer is and the second subscript operator to address that integer in this array.



## Two-Dimensional Arrays and Enumeration Types
You can also use the enumeration type for array indices. Consider the following
statements:

  const int NUMBER_OF_ROWS = 6;
  const int NUMBER_OF_COLUMNS = 5;
  enum carType {GM, FORD, TOYOTA, BMW, NISSAN, VOLVO};
  enum colorType {RED, BROWN, BLACK, WHITE, GRAY};
  int inStock[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];

These statements define the carType and colorType enumeration types and define inStock as a two-dimensional array of six rows and five columns. Suppose that each row in inStock corresponds to a car type, and each column in inStock corresponds to a color type. That is, the first row corresponds to the car type GM, the second row corresponds to the car type FORD, and so on. Similarly, the first column corresponds to the color type RED, the second column corresponds to the color type BROWN, and so on. Suppose further that each entry in inStock represents the number of cars of a particular type and color

Using the definitions above, the statement:

  inStock[1][3] = 15;

is equivalent to the following statement:

  inStock[FORD][WHITE] = 15;



### Processing Two-Dimensional Arrays

A two-dimensional array can be processed in four ways:
  Process a single element.
  Process the entire array.
  Process a particular row of the array, called row processing.
  Process a particular column of the array, called column processing.

Processing a single element is like processing a single variable. Initializing and printing the array are examples of processing the entire two-dimensional array. Finding the largest element in a row (column) or finding the sum of a row (column) are examples of row (column) processing. We will use the following declaration for our discussion:

  const int NUMBER_OF_ROWS = 7; //This can be set to any number.
  const int NUMBER_OF_COLUMNS = 6; //This can be set to any number.
  int matrix[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
  int row;
  int col;
  int sum;
  int largest;
  int temp;

All of the components of a two-dimensional array, whether rows or columns, are identical in type. If a row is looked at by itself, it can be seen to be just a one-dimensional array. A column seen by itself is also a one-dimensional array. Therefore, when processing a particular row or column of a two-dimensional array, we use algorithms similar to those that process one-dimensional arrays.

Suppose that we want to process row number 5 of matrix (that is, the sixth row of matrix).

We see that in these components, the first index (the row position) is fixed at 5. The second index (the column position) ranges from 0 to 5. Therefore, we can use the following for loop to process row number 5:

  row = 5;
  for (col = 0; col < NUMBER_OF_COLUMNS; col++)
    process(matrix[row][col]

Similarly, suppose that we want to process column number 2 of matrix, the second index (that is, the column position) is fixed at 2. The first index (that is, the row position) ranges from 0 to 6. In this case, we can use the following for loop to process column 2 of matrix:

  col = 2;
  for (row = 0; row < NUMBER_OF_ROWS; row++)
    process(matrix[row][col])



#### Passing Two-Dimensional Arrays as Parameters

Two-dimensional arrays can be passed as parameters to a function, and they are passed by reference. The base address (that is, the address of the first component of the actual parameter) is passed to the formal parameter.

In the case of a one-dimensional array, when declaring it as a formal parameter, we usually omit the size of the array. Because C++ stores two-dimensional arrays in row order form, to compute the address of a component correctly, the compiler must know where one row ends and the next row begins.

Thus, when declaring a two-dimensional array as a formal parameter, you can omit the size of the first dimension, but not the second; that is, you must specify the number of columns.

Suppose we have the following declaration:

  const int NUMBER_OF_ROWS = 6;
  const int NUMBER_OF_COLUMNS = 5;

Consider the following definition of the function printMatrix:

  void printMatrix(int matrix[][NUMBER_OF_COLUMNS], int noOfRows)
  {
    for (int row = 0; row < noOfRows; row++)
    {
    for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
      cout << setw(5) << matrix[row][col] << " ";
      cout << endl;
    }
  }

This function takes as a parameter a two-dimensional array of an unspecified number of rows and five columns, and outputs the content of the two-dimensional array. During the function call, the number of columns of the actual parameter must match the number of columns of the formal parameter.

Similarly, the following function outputs the sum of the elements of each row of a two-dimensional array whose elements are of type int:

  void sumRows(int matrix[][NUMBER_OF_COLUMNS], int noOfRows)
  {
    int sum;
    //Sum of each individual row
    for (int row = 0; row < noOfRows; row++)
    {
      sum = 0;
      for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
        sum = sum + matrix[row][col];
      cout << "Sum of row " << (row + 1) << " = " << sum << endl;
    }
  }

The following function determines the largest element in each row:

  void largestInRows(int matrix[][NUMBER_OF_COLUMNS], int noOfRows)
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
      cout << "Largest element of row " << (row + 1) << " = " << largest << "\n";
    }
  }

Likewise, you can write a function to find the sum of the elements of each column, read the data into a two-dimensional array, find the largest and/or smallest element in each row or column, and so on.



### Another Way to Declare a Two-Dimensional Array

If you know the size of the tables with which the program will be working, then you can use typedef to first define a two-dimensional array data type and then declare variables of that type.

For example, consider the following:

  const int NUMBER_OF_ROWS = 20;
  const int NUMBER_OF_COLUMNS = 10;
  typedef int tableType[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];

The previous statement defines a two-dimensional array data type tableType. Now
we can declare variables of this type. So:

  tableType matrix;

declares a two-dimensional array matrix of 20 rows and 10 columns.

You can also use this data type when declaring formal parameters, as shown in the following code:

  void initialize(tableType table)
  {
    for (int row = 0; row < NUMBER_OF_ROWS; row++)
      for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
        table[row][col] = 0;
  }

This function takes as an argument any variable of type tableType, which is a twodimensional array containing 20 rows and 10 columns, and initializes the array to 0.

By first defining a data type, you do not need to keep checking the exact number of columns when you declare a two-dimensional array as a variable or formal parameter, or when you pass an array as a parameter during a function call.



### Two-dimensional dynamically allocated arrays
An understanding of the mechanics of dynamic allocation and dynamic array allocation are required to understand the following content.

For information regarding dynamic memory allocation, see:
[C++\Syntax\Statements\Declarations\Derived Types\PointersAndReferences\DynamicMemory.md]

Another common use for pointers to pointers is to facilitate dynamically allocated multidimensional arrays.

Unlike a two dimensional fixed array, which can easily be declared like this:

  int array[10][5];

Dynamically allocating a two-dimensional array is a little more challenging. You may be tempted to try something like this:

  int **array = new int[10][5]; // won’t work!

But it won’t work.

There are two possible solutions here. If the rightmost array dimension is a compile-time constant, you can do this:

  int (*array)[5] = new int[10][5];

The parenthesis are required here to ensure proper precedence. In C++11 or newer, this is a good place to use automatic type deduction:

  auto array = new int[10][5]; // so much simpler!

Unfortunately, this relatively simple solution doesn’t work if any non-leftmost array dimension isn’t a compile-time constant. In that case, we have to get a little more complicated. First, we allocate an array of pointers (as per above). Then we iterate through the array of pointers and allocate a dynamic array for each array element. Our dynamic two-dimensional array is a dynamic one-dimensional array of dynamic one-dimensional arrays!

  // allocate an array of 10 int pointers — these are our rows
  int **array = new int*[10];
  for (int count = 0; count < 10; ++count)
      array[count] = new int[5]; // these are our columns

We can then access our array like usual:

  array[9][4] = 3; // This is the same as (array[9])[4] = 3;

With this method, because each array column is dynamically allocated independently, it’s possible to make dynamically allocated two dimensional arrays that are not rectangular. For example, we can make a triangle-shaped array:

  // allocate an array of 10 int pointers — these are our rows
  int **array = new int*[10];
  for (int count = 0; count < 10; ++count)
      array[count] = new int[count+1]; // these are our columns

In the above example, note that array[0] is an array of length 1, array[1] is an array of length 2, etc…

Deallocating a dynamically allocated two-dimensional array using this method requires a loop as well:

  for (int count = 0; count < 10; ++count)
      delete[] array[count];

  delete[] array; // this needs to be done last

Note that we delete the array in the opposite order that we created it (elements first, then the array itself). If we delete array before the array elements, then we’d have to access deallocated memory to delete the array elements. And that would result in undefined behavior.






### Dynamic 2D Arrays
Malik offers two ways of creating a dynamic two-dimensional array.

In the first method, you declare a variable to be an array of pointers, where each pointer is of type integer. ex.

int *board[4];

..and then use a for-loop to create the 'columns' while using the array of pointers as 'rows'.

The second method, you use a pointer to a pointer.

int **board;
board = new int* [10];

example:


int row, col;

cout << "Enter row size:";
cin >> row;
cout << "\ncol:";
cin >> col;

int *p_board[row];
for (int i=0; i < row; i++)
    p_board[i] = new int[col];

for (int i=0; i < row; i++)
{
    for (int j=0; j < col; j++)
    {
        p_board[i][j] = j;
        cout << p_board[i][j] << " ";
    }
    cout << endl;
}
cout << endl << endl;

int **p_p_board;
p_p_board = new int* [row];
for (int i=0; i < row; i++)
    p_p_board[i] = new int[col];

for (int i=0; i < row; i++)
{
    for (int j=0; j < col; j++)
    {
        p_p_board[i][j] = j;
        cout << p_p_board[i][j] << " ";
    }
    cout << endl;
}



In both cases your inner dimension may be dynamically specified (i.e. taken from a variable), but the difference is in the outer dimension.

This question is basically equivalent to the following:

    Is int* x = new int[4]; "better" than int x[4]?

The answer is: "no, unless you need to choose that array dimension dynamically."



The first method cannot be used to create a truly dynamic 2D arrays because by doing:

int *board[4];

you essentially allocated an array of 4 pointers to int on stack. Therefore, if you now populate each of these 4 pointers with a dynamic array:

for (int i = 0; i < 4; ++i) {
  board[i] = new int[10];
}

what you end-up with is a 2D array with static number of rows (in this case 4) and dynamic number of columns (in this case 10). So it is not fully dynamic because when you allocate an array on stack you should specify a constant size, i.e. known at compile-time. Dynamic array is called dynamic because its size is not necessary to be known at compile-time, but can rather be determined by some variable in runtime.

Once again, when you do:

int *board[4];

or:

const int x = 4; // <--- const qualifier is absolutely needed in this case!
int *board[x];

you supply a constant known at compile-time (in this case 4 or x) so that compiler can now pre-allocate this memory for your array, and when your program is loaded into the memory it would already have this amount of memory for the board array, that's why it is called static, i.e. because the size is hard-coded and cannot be changed dynamically (in runtime).

On the other hand, when you do:

int **board;
board = new int*[10];

or:

int x = 10; // <--- Notice that it does not have to be const anymore!
int **board;
board = new int*[x];

the compiler does not know how much memory board array will require, and therefore it does not pre-allocate anything. But when you start your program, the size of array would be determined by the value of x variable (in runtime) and the corresponding space for board array would be allocated on so-called heap - the area of memory where all programs running on your computer can allocate unknown beforehand (at compile-time) amounts memory for personal usage.

As a result, to truly create dynamic 2D array you have to go with the second method:

int **board;
board = new int*[10]; // dynamic array (size 10) of pointers to int

for (int i = 0; i < 10; ++i) {
  board[i] = new int[10];
  // each i-th pointer is now pointing to dynamic array (size 10) of actual int values
}

We've just created an square 2D array with 10 by 10 dimensions. To traverse it and populate it with actual values, for example 1, we could use nested loops:

for (int i = 0; i < 10; ++i) {   // for each row
  for (int j = 0; j < 10; ++j) { // for each column
    board[i][j] = 1;
  }
}




### Dynamic 2D Array In Class

```cpp
#include <iostream>

class Array2D
{
public:
    Array2D();                                  //default
    Array2D(int rows, int cols);                //fill
    Array2D(Array2D &A, int rows, int cols);    //copy


    int ** fill_array(int rows, int cols);
    int ** copy_array(Array2D &A, int rows, int cols);

    int **D;
};


int ** Array2D::fill_array(int rows, int cols)
{
    int **board;
    board = new int*[rows];
    for (int i = 0; i < 10; ++i) {
        board[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {   // for each row
        for (int j = 0; j < cols; ++j) { // for each column
            board[i][j] = 1;
        }
    }

    return board;
}

int ** Array2D::copy_array(Array2D &A, int rows, int cols)
{
    int **board;
    board = new int*[rows];
    for (int i = 0; i < 10; ++i) {
        board[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {   // for each row
        for (int j = 0; j < cols; ++j) { // for each column
            board[i][j] = A.D[i][j];
        }
    }

    return board;
}

Array2D::Array2D()
{
    int rows = 10, cols = 10;

    this->D = fill_array(rows, cols);
}

Array2D::Array2D(int rows, int cols)
{
    this->D = fill_array(rows, cols);
}

Array2D::Array2D(Array2D &A, int rows, int cols)
{
    this->D = copy_array(A, rows, cols);
}

int main()
{
    Array2D A(10, 10);
    std::cout << A.D[8][8];
    Array2D B(10, 10);
    std::cout << B.D[8][8];
    Array2D C(B, 10, 10);
    std::cout << C.D[8][8];
}
```

### Flattened Arrays

Because allocating and deallocating two-dimensional arrays is complex and easy to mess up, it’s often easier to “flatten” a two-dimensional array (of size x by y) into a one-dimensional array of size x * y:

  // Instead of this:
  // allocate an array of 10 int pointers — these are our rows
  int **array = new int*[10];
  for (int count = 0; count < 10; ++count)
      array[count] = new int[5]; // these are our columns

  // Do this
  int *array = new int[50]; // a 10x5 array flattened into a single array

Simple math can then be used to convert a row and column index for a rectangular two-dimensional array into a single index for a one-dimensional array:

  int getSingleIndex(int row, int col, int numberOfColumnsInArray)
  {
       return (row * numberOfColumnsInArray) + col;
  }

  // set array[9,4] to 3 using our flattened array
  array[getSingleIndex(9, 4, 5)] = 3;

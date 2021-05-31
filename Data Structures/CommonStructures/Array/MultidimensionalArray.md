We can define multidimensional arrays in simple words as array of arrays. Data in multidimensional arrays are stored in tabular form (in row major order).

General form of declaring N-dimensional arrays:

	data_type  array_name[size1][size2]....[sizeN];

data_type:								Type of data to be stored in the array.
array_name: 							Name of the array
size1, size2,... ,sizeN:	Sizes of the dimensions


### Examples:

Two dimensional array:

	int two_d[10][20];

Three dimensional array:

	int three_d[10][20][30];


### Size of multidimensional arrays

Total number of elements that can be stored in a multidimensional array can be calculated by multiplying the size of all the dimensions.
For example:
The array int x[10][20] can store total (10*20) = 200 elements.
Similarly array int x[5][10][20] can store total (5*10*20) = 1000 elements.



Two-Dimensional Array

Two – dimensional array is the simplest form of a multidimensional array. We can see a two – dimensional array as an array of one – dimensional array for easier understanding.

The basic form of declaring a two-dimensional array of size x, y:

Syntax:

	data_type array_name[x][y];

We can declare a two dimensional integer array say ‘x’ of size 10,20 as:

	int x[10][20];

Elements in two-dimensional arrays are commonly referred by x[i][j] where i is the row number and ‘j’ is the column number.
A two – dimensional array can be seen as a table with ‘x’ rows and ‘y’ columns where the row number ranges from 0 to (x-1) and column number ranges from 0 to (y-1).

 A two – dimensional array ‘x’ with 3 rows and 3 columns:

x[0][0] x[0][1] x[0][2]
x[1][0] x[1][1] x[1][2]
x[2][0] x[2][1] x[2][2]


### Initializing Two – Dimensional Arrays

There are two ways in which a Two-Dimensional array can be initialized.

#### Linear Method:

int x[3][4] = {0, 1 ,2 ,3 ,4 , 5 , 6 , 7 , 8 , 9 , 10 , 11}

The above array have 3 rows and 4 columns. The elements in the braces from left to right are stored in the table also from left to right. The elements will be filled in the array in the order, first 4 elements from the left in first row, next 4 elements in second row and so on.

#### Explicit Method:

int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};

This type of initialization make use of nested braces. Each set of inner braces represents one row. In the above example there are total three rows so there are three sets of inner braces.



### Accessing Elements of Two-Dimensional Arrays:

Elements in Two-Dimensional arrays are accessed using the row indexes and column indexes.

Example:

int x[2][1];

The above example represents the element present in third row and second column.

Note: In arrays if size of array is N. Its index will be from 0 to N-1. Therefore, for row index 2 row number is 2+1 = 3.



### Traversal of 2D Array

We can use either a nested for loop or a singular for loop to visit each member of a 2D array

```cpp
#include <iostream>

int main()
{
    int height = 10;
    int width = 8;

    //2D array accessed through int pointer pointer
    int **x;
    x = new int *[height];

    // loop to create table rows dynamically
    for (int i = 0; i < height; i++)
        x[i] = new int[width];

    //initialize array values using nested loop
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            x[i][j] = (i * width) + j;

		//Traverse array values using single loop
    for (int i = 0; i < height * width; i++)
        std::cout << x[i / width][i % width]
            << ((i%width == width-1) ? '\n' : ' ');

    std::cout << std::endl;
}
```

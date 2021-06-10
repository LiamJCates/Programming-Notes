Declaring Arrays

An array declaration specifies the type and number of the elements:

type arrayName [ arraySize ];

This is called a single-dimensional array. The arraySize must be an integer constant greater than zero and type can be any valid C data type.

Accessing Array Elements

An element is accessed by indexing the array name. This is done by placing the index of the element within square brackets after the name of the array. For example −

double salary = balance[9];

As arrays are start there indexes at zero, the above statement will take the 10th element from the array and assign the value to salary variable.

we assign a value to array elements in much the same way.

balance[9] = 10.0;


Multidimensional Arrays
C programming language allows multidimensional arrays of the form:

type name[size1][size2]...[sizeN];

Where type is any valid C data type, name is a valid C identifier, and size must be an integer constant greater than zero




Accessing Two-Dimensional Array Elements

An element in a two-dimensional array is accessed by using the subscripts, i.e., row index and column index of the array. For example −

int val = a[2][3];

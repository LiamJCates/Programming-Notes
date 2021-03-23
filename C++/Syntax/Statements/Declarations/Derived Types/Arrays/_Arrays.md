## Array

The most fundamental collection of data is a contiguously allocated sequence of elements of the same type, called an array.

Arrays enable you to store data elements of identical type in memory. These elements are stored in sequential fashion, meaning that each element has a position, and these positions are in sequential memory blocks, one after the other.

An elements position in the array is called it's index, like most languages, C++ uses zero-based indexing. This means that the index of the element in the first position in the array is zero rather than one. For example, if we were to put the first 10 natural numbers, (1, 2, ..., 10), into an array their index numbers would be 0, 1, ..., 9, respectively.

Array:    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
Indexes:    0   1   2   3   4   5   6   7   8   9


### Declaring Arrays

The syntax for array declaration is as follows:

  dataType arrayName[intExp];

where
  dataType is the type of all elements in the array.
  arrayName is the identifier used to reference the array.
  intExp is a constant expression that evaluates to a positive integer which specifies the number of elements to be stored in the array.


Consider the following statement:

  int list[10];

We could use the above statement to hold the first 10 natural numbers as this statement declares an array, called list, of 10 integer components:

  list[0], list[1], . . ., list[9].

In other words, we have declared space in memory with the ability to hold 10 integer type variables.

Such arrays are called static arrays because the number of elements they contain as well as the memory the array consumes is fixed at the time of compilation by intExp.

As static arrays only allocate a static, or unchanging amount of space in memory, static arrays cannot take more data than what the programmer has specified using intExp. Likewise, as the amount of memory is static, it also does not consume any less memory if the programmer does not all memory locations or the array is unused.

You can define the length of an array as a constant:

  const int ARRAY_LENGTH = 5;
  int myNumbers [ARRAY_LENGTH];

This is particularly useful when you need to access and use the length of the array at multiple places. If the length needed to change, instead of having to change the length in multiple places, you just correct the initialization value at the const int declaration.

Keep in mind, while we have only specified int arrays above, an array of any type can be specified.



## Initialization

To this point we have only allocated space for array elements, we will now look at how to fill the array with elements at the point of declaration, called initialization.

Array initialization syntax:
  dataType arrayName [intExp] = { optional_initial_values};

To initialize an array as shown above, in addition to the array declaration syntax, we use the assignment operator, =, and specify a brace delimited, {...}, comma separated list of initial values of the type dataType, as this is the only type of value the declared array can hold.

You can initialize array contents on a per-element basis:

  int myNumbers [5] = {34, 56, -21, 5002, 365}

Above we have declared an array of five distinct integer variables.

We can also declare an array of five integers but initialize each to zero using empty brace initialization.

  int myNumbers [5] = {};

Or partially initialize elements:

  int myNumbers [5] = {34, 56};

Here the remaining elements are zero initialized.

You can opt to leave out the number of elements in an array if you initialize it with all necessary values:

  int myNumbers [] = {2016, 2052, -525}; // array of 3 elements

Good practice dictates a value should be assigned to each array element before that element is used, otherwise the behavior of the value is undefined.

While initialization of int arrays using empty braces initialize to zero, arrays of other types may behave differently, for more information regarding array initialization, see:
[C++\Syntax\Statements\Expressions\Initialization\arrays.md]



## Array Access

Elements in an array can be accessed using the subscript operator [], and a zero-based index.

The general form (syntax) used for accessing an array component is:

  arrayName[indexExp]

in which indexExp, called the index, is any expression whose value is a nonnegative integer.

As C++ arrays are zero indexed, the index of the first array element is 0 and the last element is (Length of Array – 1). 0 and length-1 are called the bounds of the array as they provide the boundaries, or highest and lowest, valid index values for a given array.

It should be noted that the C++ compiler does not check if the index is within the actual defined bounds of the array. You can try fetching the element at index 1001 in an array of only 10 elements, putting the security and stability of your program at risk.  

C++ puts the responsibility of ensuring that the array is not accessed beyond its bounds solely on the programmer.

Accessing an array beyond its bounds results in unpredictable behavior. The program tries to access the component specified by the index, whatever memory location is indicated is accessed. This situation can result in altering or accessing the data of a memory location that you never intended to modify or access, or it may be an attempt to access protected memory that causes the program to crash.

Accessing arrays beyond their bounds should be avoided at all costs.



### Array Memory Format

The index value specifies the position of the component in the array to which we desire access, and is used to find the position in memory as well.

Array elements occupy a sequential space in memory equal to the number of array elements specified during the declaration of the array. So the memory space is equal to the number of array elements, intExp, multiplied by the size of the type of elements, dataType, specified by during the declaration of the array:

  Memory Space = intExp * sizeof(dataType)

When asked to access element at index N, the compiler uses the memory address of the first element (positioned at index zero) as the starting point and then skips N elements by adding the offset computed as N * sizeof(dataType) to reach the address containing the (N+1)th element.

The base address of an array is the address (that is, the memory location) of the first array component.

The base address of the array myList is the address of the component myList[0].

Suppose that the base address of the array myList is 1000. Then, the address of the component myList[0] is 1000. Typically, the memory allocated for an int variable is four bytes.

main memory is an ordered sequence of cells, and each cell has a unique address. Typically, each cell is one byte. Therefore, to store a value into myList[0], starting at the address 1000, the next four bytes are allocated for myList[0]. It follows that the starting address of myList[1] is 1004, the starting address of myList[2] is 1008, and so on

Suppose myList is the name of an array. There is also a memory space associated with the identifier myList, and the base address of the array is stored in that memory space.

You might be wondering why the base address of an array is so important. The reason is that when you declare an array, the only things about the array that the computer remembers are the name of the array, its base address, the data type of each component, and (possibly) the number of components. Using the base address of the array, the index of an array component, and the size of each component in bytes, the computer calculates the address of a particular component.



## Library
The arrays explained above are directly implemented as a language feature, inherited from the C language. They are a great feature, but it does come with certain restrictions and the fact that arrays decay into pointers when used as parameters.

For information regarding the restrictions mentioned above, see:
[C++\Syntax\Statements\Declarations\Derived Types\Arrays\Restrictions.md]

For information regarding array decay, see:
[C++\Syntax\Statements\Declarations\Derived Types\Arrays\asParameters.md]

To overcome some of these issues, C++ provides an alternative array type as a standard container:
[C++\Utilities\STL\Containers\Sequence\array.md]



## Dynamic
To program an application that is able to optimally consume memory resources on the basis of the needs of the user, you need to use dynamic memory allocation. So called dynamic arrays optimize memory consumption and scale depending on the demand for resources and memory at execution-time.

C++ provides dynamic arrays in the form of std::vector:
[C++\Utilities\STL\Containers\Sequence\vector.md]

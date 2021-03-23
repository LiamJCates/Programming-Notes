### As Parameters

C++ does not allow to pass an entire array as an argument to a function. However, You can pass a pointer to an array by specifying the array's name without an index.

If you want to pass a single-dimension array as an argument in a function, you would have to declare function formal parameter in one of following three ways and all three declaration methods produce similar results because each tells the compiler that an integer pointer is going to be received.

Formal parameters as a pointer as follows −

void myFunction(int *param);

Formal parameters as a sized array as follows −

void myFunction(int param[10]);

Formal parameters as an unsized array as follows −

void myFunction(int param[]);



By reference only: In C++, arrays are passed by reference only.

For more information regarding the handling of function parameters, see:
[C++\Syntax\Statements\Declarations\Derived Types\Functions\Parameters]

Because array are only passed by reference, it is said that arrays "decay" into pointers.

When an array decays, it loses its the loss of type and dimensions of an array. This generally occurs when we pass the array into a function.

What it does is, it sends first address to the array which is a pointer, hence the size of array is not the original one, but the one occupied by the pointer in the memory.

Because arrays are passed by reference only, you do not use the symbol & when declaring an array as a formal parameter.

A typical solution to handle decay is to pass size of array as a parameter.

While we might typically use sizeof to find the total size of the array then divide this by the size of the type of the elements in the array, once the array has decayed into a pointer sizeof(arrayName) will only return the size of the pointer and not the size of the array.

To write a function to process such arrays, in addition to declaring an array as a formal parameter, we declare another formal parameter specifying the number of elements in the array, as in the following function:

  void initialize(int list[], int listSize)
  {
    for (int count = 0; count < listSize; count++)
      list[count] = 0;
  }

The first parameter of the function initialize is an int array of any size. When the function initialize is called, the size of the actual array is passed as the second parameter of the function initialize.

If C++ allowed arrays to be passed by value, the computer would have to allocate memory for the components of the formal parameter and copy the contents of the actual array into the corresponding formal parameter when the function is called. If the array size was large, this process would waste memory as well as the computer time needed for copying the data. That is why in C++ arrays are always passed by reference.

functions also return the address of an array rather than copy each member back to the caller


As C++ implicitly converts parameters using the array syntax ([]) to the pointer syntax (*). That means the following two function declarations are identical:

  void printSize(int array[]);
  void printSize(int *array);

Some programmers prefer using the [] syntax because it makes it clear that the function is expecting an array, not just a pointer to a value. However, in most cases, because the pointer doesn’t know how large the array is, you’ll need to pass in the array size as a separate parameter anyway (strings being an exception because they’re null terminated).

We lightly recommend using the pointer syntax, because it makes it clear that the parameter is being treated as a pointer, not a fixed array, and that certain operations, such as sizeof(), will operate as if the parameter is a pointer.

Recommendation: Favor the pointer syntax (*) over the array syntax ([]) for array function parameters.

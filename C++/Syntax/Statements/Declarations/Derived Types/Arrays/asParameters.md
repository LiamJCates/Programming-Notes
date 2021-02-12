### As Parameters

By reference only: In C++, arrays are passed by reference only.

Because arrays are passed by reference only, you do not use the symbol & when declaring an array as a formal parameter.
When declaring a one-dimensional array as a formal parameter, the size of the array is usually omitted. If you specify the size of a one-dimensional array when it is declared as a formal parameter, the size is ignored by the compiler.

Consider the following function:

  void funcArrayAsParam(int listOne[], double listTwo[])
  {
    ...
  }

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

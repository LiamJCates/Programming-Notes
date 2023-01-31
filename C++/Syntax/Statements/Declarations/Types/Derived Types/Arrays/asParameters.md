### As Parameters

C++ does not allow us to pass an entire array as an argument to a function. Typically, we pass a pointer to an array by specifying the array's name without an index.

The passage of a pointer to the array is efficient as it does not require all values in the array to be copied into the function.

You may read that, in C++,

  "arrays are passed by reference only."

In this statement, the context of reference is used in a way that was inherited from C.

The wording is very confusing and uses a meaning of "reference" that is not the same as the term reference relating to the C++ feature of the same name. This is because C did not have the refence operator, &, nor the ability to pass parameters by reference using it.

In the "olden days" "reference" was used in a more general sense in the same way as "handle" — an abstract term to represent the use of indirection to fake by-reference semantics in languages that did not support it. But, C++ does support things that it calls references; thus, we tend not to use "reference" in its "handle" sense when talking about C++

For more information regarding the handling of function parameters, see:
[C++\Syntax\Statements\Declarations\Derived Types\Functions\Parameters]





If C++ allowed arrays to be passed by value, the computer would have to allocate memory for the components of the formal parameter and copy the contents of the actual array into the corresponding formal parameter when the function is called. If the array size was large, this process would waste memory as well as the computer time needed for copying the data. That is why, in C++, arrays are always passed by reference.

Functions also return the address of an array rather than copy each member back to the caller


As C++ implicitly converts parameters using the array syntax ([]) to the pointer syntax (*). That means the following two function declarations are identical:

  void printSize(int array[]);
  void printSize(int *array);

Some programmers prefer using the [] syntax because it makes it clear that the function is expecting an array, not just a pointer to a value. However, in most cases, because the pointer doesn’t know how large the array is, you’ll need to pass in the array size as a separate parameter anyway (strings being an exception because they’re null terminated).

We lightly recommend using the pointer syntax, because it makes it clear that the parameter is being treated as a pointer, not a fixed array, and that certain operations, such as sizeof(), will operate as if the parameter is a pointer.

Recommendation: Favor the pointer syntax (*) over the array syntax ([]) for array function parameters.





### Parameter Declaration

If you want to pass a single-dimension array as an argument in a function, you would have to declare function formal parameter in one of following three ways:

Formal parameters as a pointer:

  void myFunction(int *param);

Formal parameters as a sized array:

  void myFunction(int param[10]);

Formal parameters as an unsized array:

  void myFunction(int param[]);

all three declaration methods produce similar results because each tells the compiler that an integer pointer is going to be received. They're all treated as taking an int * parameter, you can pass any size array to them.


You may wonder why we do not show passing by reference using the & operator above, like this:

  void foo(int & x[100]); // error

That is because this is parsed as an "array of references" - which isn't legal.

In the C++ Standard §8.3.2/4:

  There shall be no references to references, no arrays of references, and no pointers to references.


To mitigate future confusion, you may come across function declarations like these:

  void foo(int (&x)[100]);
  void foo(int (&x)[]);

It's a syntax for array references - you need to use (&array) to clarify to the compiler that you want a reference to an array, rather than the (invalid) array of references as described above.

Additionally:

  void foo(int (&x)[100]);

only accepts arrays of 100 integers. You can safely use sizeof on x



### Array Decay

Because array are "only passed by reference", meaning pointers, it is said that arrays "decay" into pointers.

When an array decays, it loses its type and dimensions. While it can occur other places, most typically we deal with it when we pass the array into a function.

When we pass in an array using only the identifier

  int array[] = {1, 2, 3, 4};
  sum(array);

It sends first address to the array which is a pointer, hence the size of array is not the original one, but the one occupied by the pointer in the memory.

Because arrays are passed by reference only, you do not use the symbol & when declaring an array as a formal parameter. As mentioned above, this would produce a reference to a reference, which is illegal by the C++ standard.

While we might typically use sizeof to find the total size of the array then divide this by the size of the type of the elements in the array, once the array has decayed into a pointer sizeof(arrayName) will only return the size of the pointer and not the size of the array.



### Solving Decay

A typical solution to handle decay is to pass size of array as a parameter.

To write a function to process such arrays, in addition to declaring an array as a formal parameter, we declare another formal parameter specifying the number of elements in the array, as in the following function:

  void initialize(int list[], int listSize)
  {
    for (int count = 0; count < listSize; count++)
      list[count] = 0;
  }

The first parameter of the function initialize is an int array of any size. When the function initialize is called, the size of the actual array is passed as the second parameter of the function initialize.

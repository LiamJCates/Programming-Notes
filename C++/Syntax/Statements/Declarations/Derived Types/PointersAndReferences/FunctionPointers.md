## Function Pointers
C++ allows operations with pointers to functions. The typical use of this is for passing a function as an argument to another function.

Functions occupy memory, just like objects. You can refer to this memory address via usual pointer mechanisms. However, unlike objects, you cannot modify the pointed-to function. In this respect, functions are conceptually similar to const objects. You can take the address of functions and invoke them, and that’s about it.



### Declaring a Function Pointer
To declare a function pointer, use the following ugly syntax:
return-type (*pointer-name)(arg-type1, arg-type2, ...);

This has the same appearance as a function declaration where the function name is replaced (*pointer-name).

As usual, you can employ the address-of operator & to take the address of a function. This is optional, however; you can simply use the function name as a pointer.

#include <cstdio>
float add(float a, int b) {
  return a + b;
}

float subtract(float a, int b) {
  return a - b;
}
int main() {
  const float first{ 100 };
  const int second{ 20 };
  float(*operation)(float, int) {};
  printf("operation initialized to 0x%p\n", operation);
  operation = &add;
  printf("&add = 0x%p\n", operation);
  printf("%g + %d = %g\n", first, second, operation(first, second));
  operation = subtract;
  printf("&subtract = 0x%p\n", operation);
  printf("%g - %d = %g\n", first, second, operation(first, second));
}

Output:
operation initialized to 0x0000000000000000
&add = 0x00007FF6CDFE1070
100 + 20 = 120
&subtract = 0x00007FF6CDFE10A0
100 - 20 = 80

(Due to address space layout randomization, addresses will vary at runtime.)

This listing shows two functions with identical function signatures, add and subtract. Because the function signatures match, pointer types to these functions will also match.



#### Default Parameters
One interesting note: Default parameters won’t work for functions called through function pointers. Default parameters are resolved at compile-time (that is, if you don’t supply an argument for a defaulted parameter, the compiler substitutes one in for you when the code is compiled). However, function pointers are resolved at run-time. Consequently, default parameters can not be resolved when making a function call with a function pointer. You’ll explicitly have to pass in values for any defaulted parameters in this case.




#### Passing functions as arguments to other functions

One of the most useful things to do with function pointers is pass a function as an argument to another function. Functions used as arguments to another function are sometimes called callback functions.

Consider a case where you are writing a function to perform a task (such as sorting an array), but you want the user to be able to define how a particular part of that task will be performed (such as whether the array is sorted in ascending or descending order). Let’s take a closer look at this problem as applied specifically to sorting, as an example that can be generalized to other similar problems.

Many comparison-based sorting algorithms work on a similar concept: the sorting algorithm iterates through a list of numbers, does comparisons on pairs of numbers, and reorders the numbers based on the results of those comparisons. Consequently, by varying the comparison, we can change the way the algorithm sorts without affecting the rest of the sorting code.



Providing default functions

If you’re going to allow the caller to pass in a function as a parameter, it can often be useful to provide some standard functions for the caller to use for their convenience. For example, in the selection sort example above, providing the ascending() and descending() function along with the selectionSort() function would make the caller’s life easier, as they wouldn’t have to rewrite ascending() or descending() every time they want to use them.

You can even set one of these as a default parameter:

  // Default the sort to ascending sort
  void selectionSort(int *array, int size, bool (*comparisonFcn)(int, int) = ascending);

In this case, as long as the user calls selectionSort normally (not through a function pointer), the comparisonFcn parameter will default to ascending.




### Type Aliases and Function Pointers
Type aliases provide a neat way to program with function pointers.

Syntax:
using alias-name = return-type(*)(arg-type1, arg-type2, ...)


using operation_func = float(*)(float, int);

This is especially useful if you’ll be using function pointers of the same
type; it can really clean up the code.




Type inference for function pointers

Much like the auto keyword can be used to infer the type of normal variables, the auto keyword can also infer the type of a function pointer.

  #include <iostream>

  int foo(int x)
  {
  	return x;
  }

  int main()
  {
  	auto fcnPtr{ &foo };
  	std::cout << fcnPtr(5) << '\n';

  	return 0;
  }

This works exactly like you’d expect, and the syntax is very clean. The downside is, of course, that all of the details about the function’s parameters types and return type are hidden, so it’s easier to make a mistake when making a call with the function, or using its return value.

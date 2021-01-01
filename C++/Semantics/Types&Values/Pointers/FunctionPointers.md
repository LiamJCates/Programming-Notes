## Function Pointers
Functional programming is a programming paradigm that emphasizes function
evaluation and immutable data. One of the major concepts in functional
programming is to pass a function as a parameter to another function.
One way you can achieve this is to pass a function pointer. Functions
occupy memory, just like objects. You can refer to this memory address via
usual pointer mechanisms. However, unlike objects, you cannot modify the
pointed-to function. In this respect, functions are conceptually similar to
const objects. You can take the address of functions and invoke them, and
that’s about it.

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


### Type Aliases and Function Pointers
Type aliases provide a neat way to program with function pointers.

Syntax:
using alias-name = return-type(*)(arg-type1, arg-type2, ...)


using operation_func = float(*)(float, int);

This is especially useful if you’ll be using function pointers of the same
type; it can really clean up the code.

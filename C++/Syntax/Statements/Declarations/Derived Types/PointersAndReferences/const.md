### const Pointers

declaring a variable as const effectively ensures that value of the variable is fixed as the initialization value for the life of the variable. The value of a const-variable cannot be changed, and therefore it cannot be used as an l-value.

Pointers are variables, too, and hence the const keyword that is relevant to variables is relevant to pointers as well. However, pointers are a special kind of variable as they contain a memory address and are used to modify memory at that address. Thus, when it comes to pointers and constants, you have the following cases:

The address contained in the pointer is constant and cannot be changed, yet the data at that address can be changed:

  int daysInMonth = 30;
  int* const pDaysInMonth = \&daysInMonth;
  *pDaysInMonth = 31; // OK! Data pointed to can be changed
  int daysInLunarMonth = 28;
  pDaysInMonth = \&daysInLunarMonth; // Not OK! Cannot change address!


Data pointed to is constant and cannot be changed, yet the address contained in the pointer can be changed — that is, the pointer can also point elsewhere:

  int hoursInDay = 24;
  const int* pointsToInt = &hoursInDay;
  int monthsInYear = 12;
  pointsToInt = &monthsInYear; // OK!
  *pointsToInt = 13; // Not OK! Cannot change data being pointed to
  int* newPointer = pointsToInt; // Not OK! Cannot assign const to non-const


Both the address contained in the pointer and the value being pointed to are
constant and cannot be changed (most restrictive variant):

  int hoursInDay = 24;
  const int* const pHoursInDay = &hoursInDay;
  *pHoursInDay = 25; // Not OK! Cannot change data being pointed to
  int daysInMonth = 30;
  pHoursInDay = &daysInMonth; // Not OK! Cannot change address


These different forms of const are particularly useful when passing pointers to functions. Function parameters need to be declared to support the highest possible (restrictive) level of const-ness, to ensure that a function does not modify the pointed value when it is not supposed to. This will keep programmers of your application from making unwanted changes to pointer values or data.








Pointer to const value

A pointer to a const value is a (non-const) pointer that points to a constant value.

To declare a pointer to a const value, use the const keyword before the data type:

1
2
3

const int value = 5;
const int *ptr = &value; // this is okay, ptr is a non-const pointer that is pointing to a "const int"
*ptr = 6; // not allowed, we can't change a const value

In the above example, ptr points to a const int.

So far, so good, right? Now consider the following example:

1
2

int value = 5; // value is not constant
const int *ptr = &value; // this is still okay

A pointer to a constant variable can point to a non-constant variable (such as variable value in the example above). Think of it this way: a pointer to a constant variable treats the variable as constant when it is accessed through the pointer, regardless of whether the variable was initially defined as const or not.

Thus, the following is okay:

1
2
3

int value = 5;
const int *ptr = &value; // ptr points to a "const int"
value = 6; // the value is non-const when accessed through a non-const identifier

But the following is not:

1
2
3

int value = 5;
const int *ptr = &value; // ptr points to a "const int"
*ptr = 6; // ptr treats its value as const, so changing the value through ptr is not legal

Because a pointer to a const value is not const itself (it just points to a const value), the pointer can be redirected to point at other values:

1
2
3
4
5

int value1 = 5;
const int *ptr = &value1; // ptr points to a const int

int value2 = 6;
ptr = &value2; // okay, ptr now points at some other const int

Const pointers

We can also make a pointer itself constant. A const pointer is a pointer whose value can not be changed after initialization

To declare a const pointer, use the const keyword between the asterisk and the pointer name:

1
2

int value = 5;
int *const ptr = &value;

Just like a normal const variable, a const pointer must be initialized to a value upon declaration. This means a const pointer will always point to the same address. In the above case, ptr will always point to the address of value (until ptr goes out of scope and is destroyed).

1
2
3
4
5

int value1 = 5;
int value2 = 6;

int * const ptr = &value1; // okay, the const pointer is initialized to the address of value1
ptr = &value2; // not okay, once initialized, a const pointer can not be changed.

However, because the value being pointed to is still non-const, it is possible to change the value being pointed to indirection through the const pointer:

1
2
3

int value = 5;
int *const ptr = &value; // ptr will always point to value
*ptr = 6; // allowed, since ptr points to a non-const int

Const pointer to a const value

Finally, it is possible to declare a const pointer to a const value by using the const keyword both before the type and before the variable name:

1
2

int value = 5;
const int *const ptr = &value;

A const pointer to a const value can not be set to point to another address, nor can the value it is pointing to be changed through the pointer.

Recapping

To summarize, you only need to remember 4 rules, and they are pretty logical:

    A non-const pointer can be redirected to point to other addresses.
    A const pointer always points to the same address, and this address can not be changed.

    A pointer to a non-const value can change the value it is pointing to. These can not point to a const value.
    A pointer to a const value treats the value as const (even if it is not), and thus can not change the value it is pointing to.

Keeping the declaration syntax straight can be challenging. Just remember that the type of value the pointer points to is always on the far left:

1
2
3
4

int value = 5;
const int *ptr1 = &value; // ptr1 points to a "const int", so this is a pointer to a const value.
int *const ptr2 = &value; // ptr2 points to an "int", so this is a const pointer to a non-const value.
const int *const ptr3 = &value; // ptr3 points to a "const int", so this is a const pointer to a const value.

Conclusion

Pointers to const values are primarily used in function parameters (for example, when passing an array to a function) to help ensure the function doesn’t inadvertently change the passed in argument. We will discuss this further in the section on functions.

### const Pointers

declaring a variable as const effectively ensures that value of the variable is fixed as the initialization value for the life of the variable. The value of a const-variable cannot be changed, and therefore it cannot be used as an l-value.

Pointers are variables, too, and hence the const keyword that is relevant to variables is relevant to pointers as well. However, pointers are a special kind of variable as they contain a memory address and are used to modify memory at that address. Thus, when it comes to pointers and constants, you have the following cases.


#### A Pointer to Const Data

A pointer to a const value is a (non-const) pointer that points to a constant value.

Such a pointer does not allow modification of the data through the pointer. The declaration of const data merely requires that the const precede the *, so either of the following two declarations are valid.

  const type* variable;
  type const * variable;

The memory address stored in a pointer to constant data cannot be assigned into regular pointers (that is, pointers to non-const data) without a const cast.

The address contained in the pointer is constant and cannot be changed, yet the data at that address can be changed:

  int daysInMonth = 30;
  int* const pDaysInMonth = \&daysInMonth;
  *pDaysInMonth = 31; // OK! Data pointed to can be changed
  int daysInLunarMonth = 28;
  pDaysInMonth = \&daysInLunarMonth; // Not OK! Cannot change address!

More Examples:

  const int value = 5;

  // legal, ptr is a non-const pointer that is pointing to a "const int"
  const int *ptr = &value;

  // illegal we can't change a const value
  *ptr = 6;

In the above example, ptr points to a const int.

So far, so good, right? Now consider the following example:

  int value = 5; // value is not constant
  const int *ptr = &value; // this is still okay

A pointer to a constant variable can point to a non-constant variable (such as variable value in the example above). Think of it this way: a pointer to a constant variable treats the variable as constant when it is accessed through the pointer, regardless of whether the variable was initially defined as const or not.

Thus, the following is okay:

int value = 5;
const int *ptr = &value; // ptr points to a "const int"
value = 6; // the value is non-const when accessed through a non-const identifier

But the following is not:

int value = 5;
const int *ptr = &value; // ptr points to a "const int"
*ptr = 6; // ptr treats its value as const, so changing the value through ptr is not legal

Because a pointer to a const value is not const itself (it just points to a const value), the pointer can be redirected to point at other values:

int value1 = 5;
const int *ptr = &value1; // ptr points to a const int

int value2 = 6;
ptr = &value2; // okay, ptr now points at some other const int



#### Pointers with Const Memory Address

Pointers with a constant memory address are declared by including the const after the *. Because the address is const, the pointer must be assigned a value immediately.

  type * const variable = some memory address;

Data pointed to is constant and cannot be changed, yet the address contained in the pointer can be changed — that is, the pointer can also point elsewhere:

  int hoursInDay = 24;
  const int* pointsToInt = &hoursInDay;
  int monthsInYear = 12;
  pointsToInt = &monthsInYear; // OK!
  *pointsToInt = 13; // Not OK! Cannot change data being pointed to
  int* newPointer = pointsToInt; // Not OK! Cannot assign const to non-const

A const pointer is a pointer whose value can not be changed after initialization

  int value = 5;
  int *const ptr = &value;

Just like a normal const variable, a const pointer must be initialized to a value upon declaration. This means a const pointer will always point to the same address. In the above case, ptr will always point to the address of value (until ptr goes out of scope and is destroyed).

  int value1 = 5;
  int value2 = 6;

  // legal, the const pointer is initialized to the address of value1
  int * const ptr = &value1;

  // illegal, once initialized, a const pointer can not be changed.
  ptr = &value2;

However, because the value being pointed to is still non-const, it is possible to change the value being pointed to indirection through the const pointer:

  int value = 5;
  int *const ptr = &value; // ptr will always point to value
  *ptr = 6; // allowed, since ptr points to a non-const int



#### Const Data with a Const Pointer

To combine the two modes of const-ness with pointers, you can simply include const for both data and pointer by putting const both before and after the *:

  const type * const variable = some memory address;
  type const * const variable = some memory address;

Both the address contained in the pointer and the value being pointed to are
constant and cannot be changed (most restrictive variant):

  int hoursInDay = 24;
  const int* const pHoursInDay = &hoursInDay;
  *pHoursInDay = 25; // Not OK! Cannot change data being pointed to
  int daysInMonth = 30;
  pHoursInDay = &daysInMonth; // Not OK! Cannot change address


It is possible to declare a const pointer to a const value by using the const keyword both before the type and before the variable name:

  int value = 5;
  const int *const ptr = &value;

A const pointer to a const value can not be set to point to another address, nor can the value it is pointing to be changed through the pointer.



### Recapping

To summarize, you only need to remember 4 rules, and they are pretty logical:

    A non-const pointer can be redirected to point to other addresses.

    A const pointer always points to the same address, and this address can not be changed.

    A pointer to a non-const value can change the value it is pointing to. These can not point to a const value.

    A pointer to a const value treats the value as const (even if it is not), and thus can not change the value it is pointing to.

Keeping the declaration syntax straight can be challenging. Just remember that the type of value the pointer points to is always on the far left:

  int value = 5;

  // ptr1 points to a "const int", so this is a pointer to a const value.
  const int *ptr1 = &value;

  // ptr2 points to an "int", so this is a const pointer to a non-const value.
  int *const ptr2 = &value;

  // ptr3 points to a "const int", so this is a const pointer to a const value.
  const int *const ptr3 = &value; 

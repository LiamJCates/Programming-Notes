### const Pointers

declaring a variable as const effectively ensures that value of the variable is fixed as the initialization value for the life of the variable. The value of a const-variable cannot be changed, and therefore it cannot be used as an l-value.

Pointers are variables, too, and hence the const keyword that is relevant to variables is relevant to pointers as well.

Pointers can be made const.

The compiler will still endeavor to prevent storage allocation and do constant folding when dealing with const pointers, but these features seem less useful in this case.

More importantly, the compiler will tell you if you attempt to change a const pointer, which adds a great deal of safety.

When using const with pointers, you have two options:
  const can be applied to what the pointer is pointing to, a pointer to constant data
  the const can be applied to the address stored in the pointer itself, a pointer with constant address


#### A Pointer to Const Data

A pointer to a const value is a (non-const) pointer that points to a constant value. Such a pointer does not allow modification of the data through the pointer.

The trick with a pointer definition, as with any complicated definition, is to read it starting at the identifier and work your way out. The const specifier binds to the thing it is “closest to.” So if you want to prevent any changes to the element you are pointing to, you write a definition like this:

  const type* identifier;

Starting from the identifier, we read “identifier is a pointer, which points to a const of type.” Here, no initialization is required because you’re saying that it can point to anything (that is, it is not const), but the thing it points to cannot be changed.

Here’s the mildly confusing part. You might think that to make the pointer itself unchangeable, that is, to prevent any change to the address contained inside the pointer, you would simply move the const to the other side of the int like this:

type const* identifier;

The declaration of const data merely requires that the const precede the *, so the above declaration is also valid.

It’s not all that crazy to think that this should read “identifier is a const pointer of type.”

However, the way it actually reads is “identifier is an ordinary pointer of type that happens to be const.” That is, the const has bound itself to the type again, and the effect is the same as the previous definition. The fact that these two definitions are the same is the confusing point; to prevent this confusion on the part of your reader, you should probably stick to the first form.


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

  type * const identifier = some memory address;

This declaration reads: “identifier is a pointer, which is const, that points to a value of type.”

Because the pointer itself is now the const, the compiler requires that it be given an initial value that will be unchanged for the life of that pointer.

It’s OK, however, to change what that value points to by saying

int d = 1;
int* const w = &d;

*w = 2;

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

An example of a const pointer to a const object using either of two legal forms:

  int d = 1;
  const int* const x = &d; // (1)
  int const* const x2 = &d; // (2)

Now neither the pointer nor the object can be changed.  Some people argue that the second form is more consistent because  the const is always placed to the right of what it modifies. You’ll have to decide which is clearer for your particular coding style.

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


### Assignment and type checking
C++ is very particular about type checking, and this extends to pointer assignments. You can assign the address of a non-const object to a const pointer because you’re simply promising not to change something that is OK to change. However, you can’t assign the address of a const object to a non-const pointer because then you’re saying you might change the object via the pointer. Of course, you can always use a cast to force such an assignment, but this is bad programming practice because you are then breaking the constness of the object, along with any safety promised by the const.

For example:

```cpp
//: C08:PointerAssignment.cpp
int d = 1;
const int e = 2;
int* u = &d; // OK -- d not const
//! int* v = &e; // Illegal -- e const
int* w = (int*)&e; // Legal but bad practice
int main() {}
```
Although C++ helps prevent errors it does not protect you from yourself if you want to break the safety mechanisms.


Character array literals
The place where strict constness is not enforced is with character
array literals. You can say
char* cp = "howdy";
and the compiler will accept it without complaint. This is
technically an error because a character array literal (“howdy”in
this case) is created by the compiler as a constant character array,
and the result of the quoted character array is its starting address in
memory. Modifying any of the characters in the array is a runtime
error, although not all compilers enforce this correctly.
So character array literals are actually constant character arrays. Of
course, the compiler lets you get away with treating them as nonconst because there’s so much existing C code that relies on this.
However, if you try to change the values in a character array literal,
the behavior is undefined, although it will probably work on many
machines.
If you want to be able to modify the string, put it in an array:
char cp[] = "howdy";
Since compilers often don’t enforce the difference you won’t be
reminded to use this latter form and so the point becomes rather
subtle.


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

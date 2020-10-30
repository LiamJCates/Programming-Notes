Heaping and Stacking the Variables
C++ applications use two kinds of memory: heap and stack. The heap is
a common area of memory that your application allocates — that is, sets
aside — for the different functions in your application to use. Global variables
go in this heap.
Whenever your application calls a function, however, the function gets its
own little private area of memory storage in an area of memory known as a
stack. It is called a stack because it’s treated like a stack of papers: You can
put something on the top of the stack, and you can take something off the
top of the stack, but you can’t put anything in the middle or take anything
from the middle. The computer uses this stack to keep track of all your function calls.


Every position in memory has a number associated with it. When your application starts, the computer sets aside a large chunk of memory and then
works closely with the microprocessor itself to assign a bunch of numbers
to the memory. Your application’s variables and your application’s code go
in this memory. And consider this: If your application sits in memory, each
function sits in a particular place in memory, a place with a number or an
address associated with it. In other words, each function has an address.
Each function and each variable in your application has a place where it
resides in memory. That place has a number associated with it. Therefore,
each function and each variable has an address.


The stack where the computer keeps track of the function calls is just a
bunch of memory, too. What the computer considers the top of the stack is
really the next position in memory. And the way the computer puts a function on the stack is by putting on the stack the address of where the computer left off in the preceding function.
When the computer calls one of your functions, it not only saves the address
of the return location on the stack but also reserves some space on the stack
for your local variables.
This means that your variables can live in two places:
✦ Heap: The heap is a common area in memory where you can store global
variables.
✦ Stack: The stack is the area where the computer stores both the information about the functions being called and the local variables for those
functions.



Getting a variable’s address
Because every variable lives somewhere in memory, every variable has
an address.

If you want to take the address of (which is computerspeak for find the
address of) the variable NumberOfPotholes, you simply throw an ampersand (&) in front of it.






But when you obtain that address, you can
use it for other purposes. For example, you can use the address to modify
www.it-ebooks.info150 Heaping and Stacking the Variables
the variable itself by using what are called pointer variables. A pointer variable is just like any other variable except that it stores the address of another
variable.
To declare a pointer variable, you need to specify the type of variable it will
point to. Then you precede the variable’s name with an asterisk, as in the
following:
int *ptr;
This line declares a variable that points to an integer. In other words, it can
contain the address of an integer variable. And how do you grab the address
of an integer variable? Easy! By using the & notation! Thus, you can do something like this:
ptr = &NumberOfPotholes;
This line puts the address of the variable NumberOfPotholes in the ptr
variable. Remember that ptr doesn’t hold the number of potholes; rather, it
holds the address of the variable called NumberofPotholes.








A pointer is a variable that stores an address in memory.
Like all variables a pointer occupies space in memory.

As a variable of type int is used to contain an integer value, a pointer variable is used to contain a memory address

So, a pointer is a special variable that points to a location in memory

Memory locations are typically addressed using hexadecimal

A pointer, being a variable needs to be declared.
To declare a pointer specify a value type. This would mean that the address
contained in the pointer points to a location in the memory that holds that type.

PointedType * PointerVariableName;

You can also specify a pointer to a block of memory (also called a void pointer).

As is the case with most variables, unless you initialize a pointer it will contain a random value.

Uninitialized pointers can result in your program accessing invalid memory locations, resulting in a crash.


When you access the characters of the string through a pointer, you need to
put parentheses around the asterisk and the pointer variable. Otherwise, the
compiler gets confused and first tries to access the index in brackets with
the variable name and afterward applies the asterisk.

(*ptrToString)[i]


You don’t want a random memory address to be accessed so you initialize a
pointer to NULL. NULL is a value that can be checked against and one that cannot be a memory address:
PointedType * PointerVariableName = NULL; // initializing value

Thus, declaring a pointer to an integer would be
int *pointsToInt = NULL;



If you try to declare multiple pointers on a single line but put an asterisk
only before the first pointer, only that one will be a pointer. The rest will not
be.

The Null Pointer
We try to ensure that a pointer always points to an object so that dereferencing it is valid. When we don’t have an object to point to or if we need to represent the notion of ‘‘no object available’’ (e.g.,
for an end of a list), we give the pointer the value nullptr (‘‘the null pointer’’).

There is only one nullptr shared by all pointer types:
double∗ pd = nullptr;
Link<Record>∗ lst = nullptr; // pointer to a Link to a Record
int x = nullptr; // error : nullptr is a pointer not an integer
It is often wise to check that a pointer argument actually points to something:
int count_x(const char∗ p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-ter minated array of char (or to nothing)
{
if (p==nullptr)
return 0;
int count = 0;
for (; ∗p!=0; ++p)
if (∗p==x)
++count;
return count;
}

Note how we can advance a pointer to point to the next element of an array using ++




## Reference Operator (&)
If varName is a variable, &varName gives the address in memory where its value is placed:
int age = 30;
&age would be the address in memory where the value (30) is placed.

The referencing operator (&) is also called the address-of operator.

Assume a variable declaration of the types you already know:
// Declaring a variable
Type VariableName = InitialValue;
To store the address of this variable in a pointer, you would declare a pointer to the same Type and initialize the pointer to the variable’s address using the referencing operator
(&):
// Declaring a pointer to Type and initializing to address
Type* Pointer = &Variable;

Thus, if you have declared an integer, using the syntax that you’re well acquainted with,
such as
int age = 30;
You would declare a pointer to the type int to hold the actual address where age is
stored, like this:
int* pointsToInt = &age; // Pointer to integer age


In a declaration, the unary suffix & means ‘‘reference to.’’ A reference is similar to a pointer,
except that you don’t need to use a prefix ∗ to access the value referred to by the reference. Also, a
reference cannot be made to refer to a different object after its initialization.
References are particularly useful for specifying function arguments. For example:
void sort(vector<double>& v); // sor t v (v is a vector of doubles)
By using a reference, we ensure that for a call sor t(my_vec), we do not copy my_vec and that it
really is my_vec that is sorted and not a copy of it.
When we don’t want to modify an argument but still don’t want the cost of copying, we use a
const reference (§1.6). For example:
double sum(const vector<double>&)
Functions taking const references are very common.
When used in declarations, operators (such as &, ∗, and [ ]) are called declarator operators:
T a[n] // T[n]: a is an array of n Ts
T∗ p // T*: p is a pointer to T
T& r // T&: r is a reference to T
T f(A) // T(A): f is a function taking an argument of type A returning a result of type T

What Is a Reference?
A reference is an alias for a variable. When you declare a reference, you need to initialize it to a variable using the reference operator (&):
VarType original = Value;
VarType& ReferenceVariable = original;

What Makes References Useful?
References enable you to work with the memory location they are initialized to. This
makes references particularly useful when programming functions.



Passing by Reference
A reference is
another way of specifying a parameter in a function whereby the function
can modify the original variable. Instead of following the parameter type
with an asterisk (*) to denote a pointer, you follow it with an ampersand (&).
Then, throughout your function, you can use the parameter just as you normally would, not as a pointer. But every change you make to the parameter
affects the original variable

void MessMeUp(int &myparam)
{
myparam = myparam * 2 + 10;
}

If you have string parameters, and you use the & to pass them by reference, skip the shortcut -> notation to call the string functions. And don’t
dereference anything. There are no pointers. Just type the dot (or period)
and the function. No asterisks needed.

If you write a function that uses a reference and somebody else uses your
function in code (see Book I, Chapter 6, for information on how to do this),
you could end up making that other person angry. The other person may not
realize that, “Hey, man — this thing just messed up my variable!” WHAM! The
variable gets changed. How do you avoid this? Warn the other person. Make
it clear to anybody using your function that it uses references and will
modify variables


Function DoSomething() is invoked like this:
ReturnType Result = DoSomething(argument); // function call

The preceding code would result in the argument being copied into Parameter, which is then used by the function DoSomething(). This copying step can be quite an overhead if the argument in question consumes a lot of memory. Similarly, when DoSomething() returns a value, it is copied again into Result. It would be ideal if we could avoid or eliminate the copy steps, enabling the function to work directly on the data in the caller’s stack. References enable you to do just that.

A version of the function without the copy step looks like this:
ReturnType DoSomething(Type& parameter); // note the reference&

This function would be invoked as the following:
ReturnType Result = DoSomething(argument);

As the argument is being passed by reference, Parameter is not a copy of argument, rather it is an alias

#include <iostream>
 using namespace std;

 void GetSquare(int& number)
 {
 number *= number;
 }

 int main()
 {
 cout << "Enter a number you wish to square ";
 int number = 0;
 cin >> number;

 GetSquare(number);
 cout << "Square is " << number << endl;

 return 0;
 }

 The function that performs the operation of accepts
the number to be squared as a parameter by reference and returns the result in the same.
Had you forgotten to mark the parameter number as a reference (&), the result would not
reach the calling function main() as GetSquare() would then perform its operations
on a local copy of number and that would be destroyed when the function exits. Using
references, you ensure that GetSquare() is operating in the same address space where
number in main() is defined. Thus, the result of the operation is available in main()
even after the function GetSquare() has exited



Using Keyword const on References
You might need to have references that are not allowed to change the value of the
original variable being aliased. Using const when declaring such references is the way
to achieve that:
int original = 30;
const int& constRef = original;
constRef = 40; // Not allowed: constRef can’t change value in original
int& ref2 = constRef; // Not allowed: ref2 is not const
const int& constRef2 = constRef; // OK





Access Pointed Data Using the Dereference Operator (*)
You have a pointer to data, containing a valid address. How do you access that
location—that is, get or set data at that location? The answer lies in using the
dereferencing operator (*). Essentially, if you have a valid pointer pData, use *pData to access the value stored at the address contained in the pointer.

When you
don’t initialize the pointer, it can contain any random value (that existed in the memory
location where the pointer variable is located) and dereference of that pointer usually
results in an Access Violation—that is, accessing a memory location that your application
was not authorized to.

The dereferencing operator (*) is also called the indirection operator.



If we want different objects to refer to the same (shared) value, we must say so. We could use
pointers:
int x = 2;
int y = 3;
int∗ p = &x;
int∗ q = &y; // now p!=q and *p!=*q
p = q; // p becomes &y; now p==q, so (obviously)*p == *q

A reference and a pointer both refer/point to an object and both are represented in memory as a
machine address. However, the language rules for using them differ. Assignment to a reference
does not change what the reference refers to but assigns to the referenced object:
int x = 2;
int y = 3;
int& r = x; // r refers to x
int& r2 = y; // now r2 refers to y
r = r2; // read through r2, write through r: x becomes 3

Initialization differs from assignment. In general, for an assignment to work correctly, the
assigned-to object must have a value. On the other hand, the task of initialization is to make an
uninitialized piece of memory into a valid object. For almost all types, the effect of reading from or
writing to an uninitialized variable is undefined. For built-in types, that’s most obvious for references:
int x = 7;
int& r {x}; // bind r to x (r refers to x)
r = 7; // assign to whatever r refers to
int& r2; // error : uninitialized reference
r2 = 99; // assign to whatever r2 refers to
Fortunately, we cannot have an uninitialized reference; if we could, then that r2=99 would assign 99
to some unspecified memory location; the result would eventually lead to bad results or a crash.
You can use = to initialize a reference but please don’t let that confuse you. For example:
int& r = x; // bind r to x (r refers to x)
This is still initialization and binds r to x, rather than any form of value copy.



sizeof() of a Pointer?
Hence, irrespective of the type that is being pointed to, the content of a
pointer is an address—a number. The length of an address, that is the number of bytes
required to store it, is a constant for a given system. The sizeof() a pointer is hence
dependent on the compiler and the operating system the program has been compiled
for and is not dependent on the nature of the data being pointed to

even though a sizeof(char) is 1 byte and a
sizeof(double) is 8 bytes, the sizeof(char*) and sizeof(double*) are both 4
bytes. This is because the amount of memory consumed by a pointer that stores an
address is the same, irrespective of whether the memory at the address contains 1 byte or
8 bytes of data.

The output was generated when the code was compiled using a
32-bit compiler. If you use a 64-bit compiler and run the program
on a 64-bit system, you might see that the sizeof your pointer
variable is 64 bits—that is, 8 bytes.


Effect of Incrementing and Decrementing Operators (++ and --) on Pointers
A pointer contains a memory address. An increment or decrement operation on a pointer is interpreted by the compiler as your
need to point to the next value in the block of memory, assuming it to be of the same
type, and not to the next byte (unless the value type is 1 byte large, like a char, for
instance).

Decrementing pointers using operator (--) demonstrates the same effect—the address value
contained in the pointer is reduced by the sizeof the data type it is being pointed to.

What Happens When You Increment or Decrement a Pointer?
The address contained in the pointer is incremented or decremented by the sizeof
the type being pointed to (and not necessarily a byte). This way, the compiler ensures
that the pointer never points to the middle or end of data placed in the memory; it
only points to the beginning.
If a pointer has been declared as
Type* pType = Address;
++pType would mean that pType contains (and hence points to) Address +
sizeof(Type).

Using the const Keyword on Pointers

declaring a variable as const effectively ensures that value
of the variable is fixed as the initialization value for the life of the variable. The value of
a const-variable cannot be changed, and therefore it cannot be used as an l-value.
Pointers are variables, too, and hence the const keyword that is relevant to variables
is relevant to pointers as well. However, pointers are a special kind of variable as they
contain a memory address and are used to modify memory at that address. Thus, when it
comes to pointers and constants, you have the following combinations:
■ The address contained in the pointer is constant and cannot be changed, yet the data
at that address can be changed:
int daysInMonth = 30;
int* const pDaysInMonth = &daysInMonth;
*pDaysInMonth = 31; // OK! Data pointed to can be changed
int daysInLunarMonth = 28;
pDaysInMonth = &daysInLunarMonth; // Not OK! Cannot change address!■ Data pointed to is constant and cannot be changed, yet the address contained in the
pointer can be changed—that is, the pointer can also point elsewhere:
int hoursInDay = 24;
const int* pointsToInt = &hoursInDay;
int monthsInYear = 12;
pointsToInt = &monthsInYear; // OK!
*pointsToInt = 13; // Not OK! Cannot change data being pointed to
int* newPointer = pointsToInt; // Not OK! Cannot assign const to non-const
■ Both the address contained in the pointer and the value being pointed to are
constant and cannot be changed (most restrictive variant):
int hoursInDay = 24;
const int* const pHoursInDay = &hoursInDay;
*pHoursInDay = 25; // Not OK! Cannot change data being pointed to
int daysInMonth = 30;
pHoursInDay = &daysInMonth; // Not OK! Cannot change address
These different forms of const are particularly useful when passing pointers to
functions. Function parameters need to be declared to support the highest possible
(restrictive) level of const-ness, to ensure that a function does not modify the pointed
value when it is not supposed to. This will keep programmers of your application from
making unwanted changes to pointer values or data.





Never return from a function the address of a local variable in the function.
The local variables live in the stack space allocated for the function, not in
the heap. When the function is finished, the computer frees the stack space
used for the function, making room for the next function call.

Returning a Pointer as a Nonpointer
You may find it annoying to dereference a pointer returned from a function
every time you want to use it. Listing 7-14, in the preceding section, is an
example of how you need to dereference a pointer each time. But you can
avoid this issue by dereferencing the pointer as soon as it comes cranking
out of the machine. The ReturnPointer2 example, shown in Listing 7-15,
demonstrates: You preceded the call to the function with an asterisk, which
dereferences the result immediately. You then place the result in a local nonpointer variable. After that, you have the value in the variable, and you don’t
need to dereference the pointer when you want to use the value. Thus, when
you call cout, you just use the variable directly without the use of asterisks
and other pointer paraphernalia.
Listing 7-15: Dereferencing Your Return Value Immediately So You
Don’t Need to Use It as a Pointer
#include <iostream>
using namespace std;
string *GetNotSoSecretCode()
{
string *code = new string("ABCDEF");
return code;
}
int main()
{
string newcode;
int index;
for (index = 0; index < 10; index++)
{
newcode = *GetNotSoSecretCode();
cout << newcode << endl;
}
return 0;
}





Arrays and Pointers
an array is a pointer to the first element in it.
Should you need to access the second element via the expression myNumbers[1], you can
also access the same using the pointer pointToNums with the syntax *(pointToNums
+ 1). The third element is accessed in the static array using myNumbers[2], whereas the
third element is accessed in the dynamic array using the syntax *(pointToNums + 2).


It is up to you—the programmer—to ensure that all allocated memory is also released
by your application. Something like this should never be allowed to happen:
int* pointToNums = new int[5]; // initial allocation
// use pointToNums
...
// forget to release using delete[] pointToNums;
...
// make another allocation and overwrite
pointToNums = new int[10]; // leaks the previously allocated memory

Dangling Pointers (Also Called Stray
or Wild Pointers)
Note that any valid pointer is invalid after it has been released using delete.
To avoid this problem, some programmers follow the convention of assigning NULL to a
pointer when initializing it or after it has been deleted. They also always check a pointer
for validity (by comparing against NULL) before dereferencing it using operator (*).





std::unique_ptr








Dynamically Allocating with new
The heap is a special place where you can declare storage. However, to use
this storage, you take a different approach from simply declaring a variable.

To allocate memory on the heap, you need to do two things: First, declare a
pointer variable. Second, call a function named new. The new function is a
little different from other functions in that you don’t put parentheses around
its parameter. For this reason, it’s actually considered to be an operator.

To use the new function, you specify the type of variable you want to create.
For example, the following line creates a new integer variable:
int *somewhere = new int;

int *ptr = new int;
*ptr = 10;
cout << *ptr << endl;
return 0;

When you allocate memory on the heap by calling the new function and you’re
finished using the memory, you need to let the computer know, whether it’s
just a little bit of memory or a lot.

The way you free the memory is by calling the delete function and passing
the name of the pointer:
delete MyPointer;

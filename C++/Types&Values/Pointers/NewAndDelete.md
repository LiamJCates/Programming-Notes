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

## Operators new and delete
new and delete Allocate and Release memory dynamically
You use new to allocate new memory blocks. The most frequently used form of new
returns a pointer to the requested memory if successful or else throws an exception.
When using new, you need to specify the data type for which the memory is being
allocated:
Type* Pointer = new Type; // request memory for one element
You can also specify the number of elements you want to allocate that memory for
(when you need to allocate memory for more than one element):
Type* Pointer = new Type[numElements]; // request memory for numElements
Thus, if you need to allocate integers, you use the following syntax:
int* pointToAnInt = new int; // get a pointer to an integer
int* pointToNums = new int[10]; // pointer to a block of 10 integers

Note that new indicates a request for memory. There is no
guarantee that a call for allocation always succeeds because
this depends on the state of the system and the availability of
memory resources.
NOTE
Every allocation using new needs to be eventually released using an equal and opposite
de-allocation via delete:
Type* Pointer = new Type; // allocate memory
delete Pointer; // release memory allocated above
This rule also applies when you request memory for multiple elements:
Type* Pointer = new Type[numElements]; // allocate a block
delete[] Pointer; // release block allocated above
Note the usage of delete[] when you allocate a block using
new[...] and delete when you allocate just an element
using new.

Such allocations for an array of elements need to be matched by de-allocation using delete[] to free memory when done


NOTE
If you don’t release allocated memory after you stop using it, this memory remains
reserved and allocated for your application. This in turn reduces the amount of system
memory available for applications to consume and possibly even makes the execution of
your application slower. This is called a leak and should be avoided at all costs

Operator delete cannot be invoked on any address contained in
a pointer, rather only those that have been returned by new and
only those that have not already been released by a delete.

Operators new and delete allocate memory from the free store.
The free store is a memory abstraction in the form of a pool of
memory where your application can allocate (that is, reserve)
memory from and de-allocate (that is, release) memory to.


Checking Whether Allocation Request Using new Succeeded
In our code to this point, we have assumed that new will return a valid pointer to a block
of memory. Indeed, new usually succeeds unless the application asks for an unusually
large amount of memory or if the system is in such a critical state that it has no memory
to spare. There are applications that need to make requests for large chunks of memory
(for example, database applications). Additionally, it is good to not simply assume that
memory allocation requests will always be successful. C++ provides you with two
possible methods to ensure that your pointer is valid before you use it. The default
method—one that we have been using thus far—uses exceptions wherein unsuccessful
allocations result in an exception of the type std::bad_alloc to be thrown. An exception results in the execution of your application being disrupted, and unless you have
programmed an exception handler, your application ends rather inelegantly with an
error message “unhandled exception.”

#include <iostream>
using namespace std;

// remove the try-catch block to see this application crash
int main()
{
try
{
// Request a LOT of memory!
int* pointsToManyNums = new int [0x1fffffff];
// Use the allocated memory
delete[] pointsToManyNums;
}
catch (bad_alloc)
{
cout << "Memory allocation failed. Ending program" << endl;
}
return 0;
}

The exception handling try-catch construct thus helped the application in making a
controlled exit after informing the user that a problem in memory allocation hampers
normal execution.For those who don’t want to rely on exceptions, there is a variant of new called
new(nothrow). This variant does not throw an exception when allocation requests
fail, rather it results in the operator new returning NULL. The pointer being assigned,
therefore, can be checked for validity against NULL before it is used.

#include <iostream>
using namespace std;

int main() {
  int* pointsToManyNums = new(nothrow) int [0x1fffffff];

  if (pointsToManyNums) // check pointsToManyNums != NULL
    delete[] pointsToManyNums;

  else
    cout << "Memory allocation failed. Ending program" << endl;

  return 0;
}





































To dynamically allocate and deallocate memory, two functions are used. One
function, new, takes from memory as much space as needed to store an object whose
type follows new. For example, with the instruction
	 p = new int;
the program requests enough space to store one integer, from the memory manager,
and the address of the beginning of this portion of memory is stored in p. Now the
values can be assigned to the memory block pointed to by p only indirectly through a
pointer, either pointer p or any other pointer q that was assigned the address stored
in p with the assignment q = p.
If the space occupied by the integer accessible from p is no longer needed, it can
be returned to the pool of free memory locations managed by the operating system
by issuing the instruction
	 delete p;

However, after executing this statement, the beginning addresses of the released
memory block are still in p, although the block, as far as the program is concerned,
does not exist anymore. It is like treating an address of a house that has been demolished as the address of the existing location. If we use this address to find someone,
the result can be easily foreseen. Similarly, if after issuing the delete statement we
do not erase the address from the pointer variable participating in deletion, the result is potentially dangerous, and we can crash the program when trying to access
nonexisting locations, particularly for more complex objects than numerical values.
This is the dangling reference problem. To avoid this problem, an address has to be
assigned to a pointer; if it cannot be the address of any location, it should be a null
address, which is simply 0. After execution of the assignment
	 p = 0;
we may not say that p refers to null or points to null but that p becomes null or p is null.

It is up to you—the programmer—to ensure that all allocated memory is also released by your application. Something like this should never be allowed to happen:

int* pointToNums = new int[5]; // initial allocation
// use pointToNums
...
// forget to release using delete[] pointToNums;
...
// make another allocation and overwrite
pointToNums = new int[10]; // leaks the previously allocated memory



## Memory Leak
A problem associated with delete is the memory leak. Consider the following two lines of code:
	 p = new int;
	 p = new int;

After allocating one cell for an integer, the same pointer p is used to allocate another
cell. After the second assignment, the first cell becomes inaccessible and also unavailable for subsequent memory allocations for the duration of the program. The problem
is with not releasing with delete the memory accessible from p before the second
assignment is made. The code should be:
	 p = new int;
	 delete p;
	 p = new int;

Memory leaks can become a serious problem when a program uses more and
more memory without releasing it, eventually exhausting memory and leading to abnormal termination. This is especially important in programs that are executed for a
long time, such as programs in servers.




## Dangling Pointers
(Also Called Stray or Wild Pointers)
Note that any valid pointer is invalid after it has been released using delete.
To avoid this problem, some programmers follow the convention of assigning NULL to a pointer when initializing it or after it has been deleted. They also always check a pointer for validity (by comparing against NULL) before dereferencing it using operator (*).


Suppose p and name are pointer variables, as declared previously. Notice that an
expression such as
delete p;
or
delete [] name;
only marks the memory spaces that these pointer variables point to as deallocated.
Depending on the particular operating system, after these statements execute, these
pointer variables may still contain the addresses of the deallocated memory spaces.
In this case, we say that these pointers are dangling. Therefore, if later you access the
memory spaces via these pointers without properly initializing them, depending on
the particular system, either the program will access a wrong memory space, which
may result in corrupting data now stored in those spaces, or the program may terminate with an error message. One way to avoid this pitfall is to set these pointers to
nullptr after the delete operation. Also note that for the operator delete to work
properly, the pointer must point to a valid memory space.

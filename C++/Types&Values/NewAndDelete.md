## Operators new and delete
new and delete Allocate and Release Memory Dynamically
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

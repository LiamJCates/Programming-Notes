A stack is a last-in-first-out (LIFO) data structure: elements are always removed in the reverse order in which they were added from the position known as the top of the stack. The add element and remove element operations are conventionally called push and pop, respectively.

Tracking return addresses, parameters, and local variables for subroutines is one example of stack use; tracking tokens when parsing a programming language is another.

## Underlying Data Structure
Linked lists and dynamic arrays are two obvious structures for implementing the Stack ADT

Linked List Advantages
	Stack operations only effect the top of the list so the random accessibility of a dynamic array gains you little.
	A dynamic array resizes, are a time-consuming operation as all elements are copied


Array Advantages
	Linked lists usually allocate memory dynamically for each element. Depending on the overhead of the memory allocator, these allocations are often more time consuming than the copies required by a dynamic array.
	Dynamic Arrays contiguous memory addresses provide cache locality, an increasingly important performance implications as processors have become much faster than memory.
 	Dynamic arrays don’t have the overhead of a pointer for every element.

For the reasons above, a stack based on a dynamic array is usually faster than one based on a linked list. However, implementing a linked list is less complicated than implementing a dynamic array, so in an interview, a linked list is probably the best choice for your solution.


## Operations
Now consider what happens in these routines in terms of proper functionality and error handling.

### Functionality
Both push and pop operations change the first element of the list. The calling routine’s stack pointer must be modified to reflect this change

### Error Handling
What about error handling?

The push operation needs to dynamically allocate memory for a new element, so remember to check that the allocation succeeded when you write this routine.

You also need some way to indicate to the calling routine whether the push succeeded or failed.
Return true or false

it’s generally most convenient to have a routine indicate success or failure by its return value. This way, the routine can be called from the condition of an if statement with error handling in the body for languages that don't support error handling

Throwing an exception is an option in other languages with exception support.

Can pop fail?
It doesn’t have to allocate memory, but what if it’s asked to pop an empty stack?

It should indicate that the operation was unsuccessful, but it still has to return data when it is successful.

The interface design is straightforward in an object oriented language. The createStack and deleteStack operations become the constructor and
destructor, respectively.

The push and pop routines are bound to the stack object, so they don’t need to have the stack explicitly passed to them.

An exception can be thrown when there’s an attempt to pop an empty stack or a memory allocation fails, which enables you to use the return value of pop for data instead of an error code.

You can use templates to allow the stack to be used to store different data types, eliminating the potentially error-prone type casting required when using the C implementation that stores void *.

For a minimal C++ implementation, see:
[C++\CodeExamples\DataStructures\Stack\SimpleLinkedStack.cpp]

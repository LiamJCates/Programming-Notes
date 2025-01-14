Stack overflow

For information regarding the call stack, see:
[Programming Methods\Fundamentals\Environment\CallStack.md]

The stack has a limited size, and consequently can only hold a limited amount of information. On Windows, the default stack size is 1MB. On some unix machines, it can be as large as 8MB.

If the program tries to put too much information on the stack, stack overflow will result. Stack overflow happens when all the memory in the stack has been allocated -- in that case, further allocations begin overflowing into other sections of memory.

Stack overflow is generally the result of allocating too many variables on the stack, and/or making too many nested function calls (where function A calls function B calls function C calls function D etc…) On modern operating systems, overflowing the stack will generally cause your OS to issue an access violation and terminate the program.

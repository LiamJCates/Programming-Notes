Whenever your application calls a function, the function gets its own little private area of memory storage in an area of memory known as the call stack.

It is called a stack because it’s treated like a stack of papers: You can put something on the top of the stack, and you can take something off the top of the stack, but you can’t put anything in the middle or take anything from the middle. The computer uses this stack to keep track of all your function calls.

The stack keeps track of all the active functions (those that have been called but have not yet terminated) from the start of the program to the current point of execution, and handles allocation of all function parameters and local variables.

The call stack is implemented as a stack data structure.

For more information regarding the stack data structure, see:
[Data Structures\CommonStructures\Stack\Stack.md]






The call stack segment

The call stack memory segment holds the memory used for the call stack. When the application starts, the main() function is pushed on the call stack by the operating system. Then the program begins executing.

When a function call is encountered, the function and its associated memory is pushed onto the call stack. When the current function ends, that function and the associated memory is popped off the call stack. Thus, by looking at the functions pushed on the call stack, we can see all of the functions that were called to get to the current point of execution.



The call Stack Segment

The call stack memory segment holds the memory used for the call stack.

The stack itself is a fixed-size chunk of memory addresses.

A stack frame keeps track of all of the data associated with one function call.

A register (a small piece of memory in the CPU) known as the stack pointer (sometimes abbreviated “SP”) keeps track of where the top of the call stack currently is.

When we pop an item off the call stack, we don’t have to erase the memory. We can just leave it to be overwritten by the next item pushed to that piece of memory. Because the stack pointer will be below that memory location, we know that memory location is not on the stack.



The call stack in action

Here is the sequence of steps that takes place when a function is called:

  The program encounters a function call.
  A stack frame is constructed and pushed on the stack.
    The stack frame consists of:
      The address of the instruction beyond the function call (called the return address). This is how the CPU remembers where to return to after the called function exits.
      All function arguments.
      Memory for any local variables.
      Saved copies of any registers modified by the function that need to be restored when the function returns
  The CPU jumps to the function’s start point.
  The instructions inside of the function begin executing.

When the function terminates, the following steps happen:

    Registers are restored from the call stack
    The stack frame is popped off the stack. This frees the memory for all local variables and arguments.
    The return value is handled.
    The CPU resumes execution at the return address.

Return values can be handled in a number of different ways, depending on the computer’s architecture. Some architectures include the return value as part of the stack frame. Others use CPU registers.

Typically, it is not important to know all the details about how the call stack works. However, understanding that functions are effectively pushed on the stack when they are called and popped off when they return gives you the fundamentals needed to understand recursion, as well as some other concepts that are useful when debugging.

A technical note: on some architectures, the call stack grows away from memory address 0. On others, it grows towards memory address 0. As a consequence, newly pushed stack frames may have a higher or a lower memory address than the previous ones.


The stack has advantages and disadvantages:

  Allocating memory on the stack is comparatively fast.
  Memory allocated on the stack stays in scope as long as it is on the stack. It is destroyed when it is popped off the stack.
  All memory allocated on the stack is known at compile time. Consequently, this memory can be accessed directly through a variable.
  Because the stack is relatively small, it is generally not a good idea to do anything that eats up lots of stack space. This includes passing by value or creating local variables of large arrays or other memory-intensive structures.

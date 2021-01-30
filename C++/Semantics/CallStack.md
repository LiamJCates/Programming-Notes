The call stack

Whenever your application calls a function, the function gets its own little private area of memory storage in an area of memory known as the call stack.

It is called a stack because it’s treated like a stack of papers: You can put something on the top of the stack, and you can take something off the top of the stack, but you can’t put anything in the middle or take anything from the middle. The computer uses this stack to keep track of all your function calls.

The stack keeps track of all the active functions (those that have been called but have not yet terminated) from the start of the program to the current point of execution, and handles allocation of all function parameters and local variables.

The call stack is implemented as a stack data structure.

For more information regarding the stack data structure, see:
[Data Structures\CommonStructures\Stack\Stack.md]

 When the application starts, the main() function is pushed on the call stack by the operating system. Then the program begins executing.

When a function call is encountered, the function and its associated memory is pushed onto the call stack. When the current function ends, that function and the associated memory is popped off the call stack. Thus, by looking at the functions pushed on the call stack, we can see all of the functions that were called to get to the current point of execution.

For information regarding the call stack, see:
[Programming Methods\Fundamentals\Environment\CallStack.md]



### Example

Consider the following simple application:

int foo(int x)
{
    // b
    return x;
} // foo is popped off the call stack here

int main()
{
    // a
    foo(5); // foo is pushed on the call stack here
    // c

    return 0;
}

The call stack looks like the following at the labeled points:

  a:
    main()

  b:
    foo() (including parameter x)
    main()

  c:
    main()



### Stack overflow

The stack has a limited size, and consequently can only hold a limited amount of information.

If the program tries to put too much information on the stack, stack overflow will result.

Stack overflow is generally the result of allocating too many variables on the stack, and/or making too many nested function calls (where function A calls function B calls function C calls function D etc…) On modern operating systems, overflowing the stack will generally cause your OS to issue an access violation and terminate the program.

Here is an example program that will cause a stack overflow:

  #include <iostream>

  int main()
  {
    int stack[10000000];
    std::cout << "hi";
    return 0;
  }

This program tries to allocate a huge (likely 40MB) array on the stack. Because the stack is not large enough to handle this array, the array allocation overflows into portions of memory the program is not allowed to use.

Here’s another program that will cause a stack overflow for a different reason:

  void foo()
  {
    foo();
  }

  int main()
  {
    foo();

    return 0;
  }

In the above program, a stack frame is pushed on the stack every time function foo() is called. Since foo() calls itself infinitely, eventually the stack will run out of memory and cause an overflow.

For information regarding stack overflow, see:
[Programming Methods\Fundamentals\Environment\StackOverflow.md]

When a C++ program is executed, it executes sequentially, beginning at the top of main(). When a function call is encountered, the point of execution jumps to the beginning of the function being called. How does the CPU know to do this?

When a program is compiled, the compiler converts each statement in your C++ program into one or more lines of machine language. Each line of machine language is given its own unique sequential address. This is no different for functions -- when a function is encountered, it is converted into machine language and given the next available address. Thus, each function ends up with a unique address.

Binding refers to the process that is used to convert identifiers (such as variable and function names) into addresses. Binding is done for each variable and function.

For functions, it means that matching the call with the right function definition by the compiler. It takes place either at compile time or at runtime.



### Early Binding
Most of the function calls the compiler encounters will be direct function calls. A direct function call is a statement that directly calls a function. Direct function calls can be resolved using a process known as early binding.

Early binding (also called static binding) means the compiler (or linker) is able to directly associate the identifier name (such as a function or variable name) with a machine address. Remember that all functions have a unique address. So when the compiler (or linker) encounters a function call, it replaces the function call with a machine language instruction that tells the CPU to jump to the address of the function.

C++'s default method of binging is early binding.

Here we have taken base and derived class example so that readers can easily compare and see difference in outputs:

  #include<iostream>
  using namespace std;

  class Base
  {
  public:
    void show() { cout<<" In Base \n"; }
  };

  class Derived: public Base
  {
  public:
    void show() { cout<<"In Derived \n"; }
  };

  int main(void)
  {
    Base *bp = new Derived;

    // The function call decided at compile time (compiler sees type
    // of pointer and calls base class function).
    bp->show();   

    return 0;
  }

Output:

  In Base



### Late Binding
In some programs, it is not possible to know which function will be called until runtime (when the program is run). This is known as late binding (or dynamic binding). In C++, one way to get late binding is to use function pointers. To review function pointers briefly, a function pointer is a type of pointer that points to a function instead of a variable. The function that a function pointer points to can be called by using the function call operator (()) on the pointer. Calling a function via a function pointer is also known as an indirect function call.

For example, the following code calls the add() function:

  #include <iostream>

  int add(int x, int y)
  {
    return x + y;
  }

  int main()
  {
    // Create a function pointer and make it point to the add function
    int (*pFcn)(int, int) = add;
    std::cout << pFcn(5, 3) << std::endl; // add 5 + 3

    return 0;
  }

Calling a function via a function pointer is also known as an indirect function call. The following calculator program is functionally identical to the calculator example above, except it uses a function pointer instead of a direct function call:

  #include <iostream>

  int add(int x, int y)
  {
    return x + y;
  }

  int subtract(int x, int y)
  {
    return x - y;
  }

  int multiply(int x, int y)
  {
    return x * y;
  }

  int main()
  {
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;

    int y;
    std::cout << "Enter another number: ";
    std::cin >> y;

    int op;
    do
    {
        std::cout << "Enter an operation (0=add, 1=subtract, 2=multiply): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    // Create a function pointer named pFcn (yes, the syntax is ugly)
    int (*pFcn)(int, int) = nullptr;

    // Set pFcn to point to the function the user chose
    switch (op)
    {
        case 0: pFcn = add; break;
        case 1: pFcn = subtract; break;
        case 2: pFcn = multiply; break;
    }

    // Call the function that pFcn is pointing to with x and y as parameters
    // This uses late binding
    std::cout << "The answer is: " << pFcn(x, y) << std::endl;

    return 0;
  }

In this example, instead of calling the add(), subtract(), or multiply() function directly, we’ve instead set pFcn to point at the function we wish to call. Then we call the function through the pointer. The compiler is unable to use early binding to resolve the function call pFcn(x, y) because it can not tell which function pFcn will be pointing to at compile time!

Late Binding is a form of run time polymorphism in which the compiler adds code that identifies the kind of object at runtime then matches the call with the right function definition.

Late binding is slightly less efficient since it involves an extra level of indirection. With early binding, the CPU can jump directly to the function’s address. With late binding, the program has to read the address held in the pointer and then jump to that address. This involves one extra step, making it slightly slower. However, the advantage of late binding is that it is more flexible than early binding, because decisions about what function to call do not need to be made until run time.


To implement virtual functions, C++ uses a special form of late binding known as the virtual table. The virtual table is a lookup table of functions used to resolve function calls in a dynamic/late binding manner. The virtual table sometimes goes by other names, such as “vtable”, “virtual function table”, “virtual method table”, or “dispatch table”.

For more information on Dynamic Dispatch, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\DynamicDispatch.md]

A declaration introduces its name into a scope:

• Local scope: A name declared in a function or lambda is called a local name. Its scope extends from its point of declaration to the end of the block in which its declaration  occurs.  A block is  delimited by a {} pair.  Function  argument  names  are  considered local names.

• Class scope: A name is called a member name(or a class member name) if it is defined in a class  (§2.2,  §2.3,  Chapter  4),  outside  any  function  (§1.3),  lambda  (§6.3.2),  or enum  class(§2.5).   Its scope  extends  from  the  opening { of  its  enclosing  declaration  to  the  end  of  that declaration.

• Namespace scope: A name is called a namespace member name if  it  is  defined  in  a  name-space  (§3.4)  outside  any function,  lambda  (§6.3.2),  class  (§2.2,  §2.3,  Chapter  4),  or enum class(§2.5).  Its scope extends from the point of declaration to the end of its namespace.

Global scope: A  name  not  declared  inside  any  other  construct  is  called  a global  name and  is  said  to  be  in  the global namespace. he global variables will hold their value throughout the life-time of your program. A global variable can be accessed by any function. That is, a global variable is available for use throughout your entire program after its declaration.

An object must be constructed (initialized) before it is used and will be destroyed at the end of its scope.  For a namespace object the point of destruction is the end of the program.  For a member, the point of destruction is determined by the point of destruction of the object of which it is a member.  An object created by new ‘‘lives’’ until destroyed by delete

Indiscriminate use of global variables is considered poor programming practice. This is because global variables can be
assigned values in any/every function and can contain an unpredictable state, especially when functions that modify them run in
different threads or are programmed by different programmers in
a team.







Storage Classes in C++

Previous Page
Next Page  

A storage class defines the scope (visibility) and life-time of variables and/or functions within a C++ Program. These specifiers precede the type that they modify. There are following storage classes, which can be used in a C++ Program

    auto
    register
    static
    extern
    mutable

The auto Storage Class

The auto storage class is the default storage class for all local variables.

{
   int mount;
   auto int month;
}

The example above defines two variables with the same storage class, auto can only be used within functions, i.e., local variables.
The register Storage Class

The register storage class is used to define local variables that should be stored in a register instead of RAM. This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).

{
   register int  miles;
}

The register should only be used for variables that require quick access such as counters. It should also be noted that defining 'register' does not mean that the variable will be stored in a register. It means that it MIGHT be stored in a register depending on hardware and implementation restrictions.
The static Storage Class

The static storage class instructs the compiler to keep a local variable in existence during the life-time of the program instead of creating and destroying it each time it comes into and goes out of scope. Therefore, making local variables static allows them to maintain their values between function calls.

The static modifier may also be applied to global variables. When this is done, it causes that variable's scope to be restricted to the file in which it is declared.

In C++, when static is used on a class data member, it causes only one copy of that member to be shared by all objects of its class.
Live Demo

#include <iostream>

// Function declaration
void func(void);

static int count = 10; /* Global variable */

main() {
   while(count--) {
      func();
   }

   return 0;
}

// Function definition
void func( void ) {
   static int i = 5; // local static variable
   i++;
   std::cout << "i is " << i ;
   std::cout << " and count is " << count << std::endl;
}

When the above code is compiled and executed, it produces the following result −

i is 6 and count is 9
i is 7 and count is 8
i is 8 and count is 7
i is 9 and count is 6
i is 10 and count is 5
i is 11 and count is 4
i is 12 and count is 3
i is 13 and count is 2
i is 14 and count is 1
i is 15 and count is 0

The extern Storage Class

The extern storage class is used to give a reference of a global variable that is visible to ALL the program files. When you use 'extern' the variable cannot be initialized as all it does is point the variable name at a storage location that has been previously defined.

When you have multiple files and you define a global variable or function, which will be used in other files also, then extern will be used in another file to give reference of defined variable or function. Just for understanding extern is used to declare a global variable or function in another file.

The extern modifier is most commonly used when there are two or more files sharing the same global variables or functions as explained below.
First File: main.cpp

#include <iostream>
int count ;
extern void write_extern();

main() {
   count = 5;
   write_extern();
}

Second File: support.cpp

#include <iostream>

extern int count;

void write_extern(void) {
   std::cout << "Count is " << count << std::endl;
}

Here, extern keyword is being used to declare count in another file. Now compile these two files as follows −

$g++ main.cpp support.cpp -o write

This will produce write executable program, try to execute write and check the result as follows −

$./write
5

The mutable Storage Class

The mutable specifier applies only to class objects, which are discussed later in this tutorial. It allows a member of an object to override const member function. That is, a mutable member can be modified by a const member function.

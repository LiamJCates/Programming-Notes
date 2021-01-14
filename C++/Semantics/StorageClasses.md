## Storage Classes
When used as part of an identifier declaration, the static and extern keywords are called storage class specifiers.

A storage class defines the scope (visibility) and life-time of variables and/or functions within a C++ Program. These specifiers precede the type that they modify. There are following storage classes, which can be used in a C++ Program

In this context, they set the storage duration and linkage of the identifier.

C++ supports 4 active storage class specifiers:
| Specifier | Meaning |
|-----------|---------|
| extern | static (or thread_local) storage duration and external linkage |
| static | static (or thread_local) storage duration and internal linkage |
| thread_local | thread storage duration (C++11) |
| mutable | object allowed to be modified even if containing class is const |
| auto | automatic storage duration Deprecated in C++11 |
| register | automatic storage duration and hint to the compiler to place in a register Deprecated in C++17 |




### The automatic Storage Class

The automatic storage class is the default storage class for all local variables.


{
   int mount;
   auto int month;
}

The example above defines two variables with the same storage class, automatic can only be used within functions, i.e., local variables.



### The register Storage Class

The register storage class is used to define local variables that should be stored in a register instead of RAM. This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).

{
   register int  miles;
}

The register should only be used for variables that require quick access such as counters. It should also be noted that defining 'register' does not mean that the variable will be stored in a register. It means that it MIGHT be stored in a register depending on hardware and implementation restrictions.





### The static Storage Class
Using the static keyword on a local variable changes its duration from automatic duration to static duration.

The static storage class instructs the compiler to keep a local variable in existence during the life-time of the program instead of creating and destroying it each time it comes into and goes out of scope. Therefore, making local variables static allows them to maintain their values between function calls.

global variables have static duration by default, which means they are created when the program starts and destroyed when the program ends.

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





### The extern Storage Class

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




### The mutable Storage Class

The mutable specifier applies only to class objects, which are discussed later in this tutorial. It allows a member of an object to override const member function. That is, a mutable member can be modified by a const member function.

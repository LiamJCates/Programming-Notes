## Storage Classes
A storage class specifiers define the scope (visibility) and duration (life-time) of variables and/or functions within a C++ Program. These specifiers precede the type that they modify.

The C++ storage classes are:
  auto
  register
  static
  extern
  mutable
  thread_local

Modern C++ supports 4 active storage class specifiers:
	static
	extern
	mutable
	thread_local

When used as part of an identifier declaration, the static, extern, thread_local, and mutable keywords are called storage class specifiers.

In this context, they set the storage duration and linkage of the identifier.

C++ supports 4 active storage class specifiers:
| Specifier | Meaning |
|-----------|---------|
| extern | static (or thread_local) storage duration and external linkage |
| static | static (or thread_local) storage duration and internal linkage |
| thread_local | thread storage duration C++11 Introduced |
| mutable | object allowed to be modified even if containing class is const |
| auto | automatic storage duration C++11 Deprecated |
| register | automatic storage duration and hint to the compiler to place in a register C++17 Deprecated |




### The automatic Storage Class
An object for which memory is allocated at block entry and deallocated at block exit is called automatic. The automatic storage class is the default storage class for all local variables.

The auto specifier was only allowed for objects declared at block scope or in function parameter lists. It indicated automatic storage duration, which is the default for these kinds of declarations. The meaning of this keyword was changed in C++11 and the use of auto as a storage specifier is no longer valid.

{
   int count;
   auto int month;
}

The pre-C++11 example above defines two variables with the same storage class, automatic can only be used within functions, i.e., local variables.

A local automatic object or variable is initialized every time the flow of control reaches its definition.

An automatic object is allocated at the beginning of an enclosing code block,
and it’s deallocated at the end. The enclosing block is the automatic object’s
scope. Automatic objects are said to have automatic storage duration. Note that
function parameters are automatic, even though rotationally they appear
outside the function body.




### The register Storage Class

The register specifier is only allowed for objects declared at block scope and in function parameter lists. It indicates automatic storage duration, which is the default for these kinds of declarations.

The presence of this keyword may be used as a hint for the optimizer to store the value of this variable in a CPU register instead of RAM. This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).

The register keyword was deprecated in C++11 and removed in C++17.

{
   register int  miles;
}

The register keyword should only be used for variables that require quick access such as counters. It should also be noted that defining 'register' does not mean that the variable will be stored in a register. It means that it MIGHT be stored in a register depending on hardware and implementation restrictions.





### The static Storage Class
The static specifier is allowed in object (except in function parameter lists), function (except at block scope), and anonymous union declarations:
  When used in a declaration of an object, it specifies static storage duration (except if accompanied by thread_local).
  When used in a declaration of a class member, it declares a static member.
  When used in a declaration at namespace scope, it specifies internal linkage.


#### Static Local Object
Local static variables are declared at function scope, just like automatic variables. However, their lifetimes begin upon the first invocation of the enclosing function and end when the program exits. Making local variables static allows them to maintain their values between function calls, retaining its value even after the variable goes out of scope!

Static variables offer some of the benefit of global variables (they don’t get destroyed until the end of the program) while limiting their visibility to block scope. This makes them safe for use even if you change their values regularly.

Avoid static local variables unless the variable never needs to be reset. static local variables decrease reusability and make functions harder to reason about.

Static local variables should only be used if in your entire program and in the foreseeable future of your program, the variable is unique and it wouldn’t make sense to reset the variable.


#### Static Member
Static members are members of a class that aren’t associated with a particular
instance of the class. Like other static variables, static members have only a single instance. All instances of a class with static members share the same member, so if you modify a static member, all class instances will observe the modification.

Normal class members have lifetimes nested within the class’s lifetime, but static members have static storage duration. These members are essentially similar to static variables and functions declared at global scope; however, you must refer to them by the containing class’s name, using the scope resolution operator ::. In fact, you must initialize static members at global scope. There is an exception to the static member initialization rule: you can declare and define integral types within a class definition as long as they’re also const.


#### Static Global Object
When you use the static specifier keyword at global or namespace scope, you specify internal linkage, making the object inaccessible to other translation units.

NOTE
Unlike local variables, which are uninitialized by default, static variables are zero-initialized by default.





### The extern Storage Class
The extern specifier is only allowed in the declarations of variables and functions (except class members or function parameters). It specifies external linkage, and does not technically affect storage duration, but it cannot be used in a definition of an automatic storage duration object, so all extern objects have static or thread durations. In addition, a variable declaration that uses extern and has no initializer is not a definition.

The extern storage class is used to give a reference of a global variable that is visible to ALL program files. When you use 'extern' the variable cannot be initialized as all it does is point the variable name at a storage location that has been previously defined.

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

The mutable specifier applies only to class objects.

This keyword can only be applied to non-static and non-const data members of a class. If a data member is declared mutable, then it is legal to assign a value to this data member from a const member function.

It allows a member of an object to override const member function. That is, a mutable member can be modified by a const member function.



### The thread_local Storage Class
One of the fundamental concepts in concurrent programs is the thread. Each program has one or more threads that can perform independent operations. The sequence of instructions that a thread executes is called its thread of execution.

Programmers must take extra precautions when using more than one thread of execution. Code that multiple threads can execute safely is called thread-safe code. Mutable global variables are the source of many thread safety issues. Sometimes, you can avoid these issues by giving each thread its own
copy of a variable. You can do this by specifying that an object has thread storage duration.

The thread_local keyword is only allowed for objects declared at namespace scope, objects declared at block scope, and static data members. It indicates that the object has thread storage duration.

You can modify any variable with static storage duration to have thread_local storage duration by adding the thread_local keyword to the static or
extern keyword. If only thread_local is specified, static is assumed. The variable’s linkage is unchanged.

If combined with static or extern it specifies internal or external linkage (except for static data members which always have external linkage), respectively, but that additional static doesn't affect the storage duration.

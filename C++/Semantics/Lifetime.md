An object is a region of storage that has a type and a value. When you
declare a variable, you create an object. A variable is simply an object
that has a name.


TODO: C++ Crash Course Ch 4

### Allocation, Deallocation, and Lifetime
Every object requires storage. You reserve storage for objects in a process called allocation. When you’re done with an object, you release the object’s storage in a process called deallocation.

An object’s storage duration begins when the object is allocated and ends when the object is deallocated. The lifetime of an object is a runtime property that is bound by the object’s storage duration. An object’s lifetime begins once its constructor completes, and it ends just before a destructor is invoked.

In summary, each object passes through the following stages:
1. The object’s storage duration begins, and storage is allocated.
2. The object’s constructor is called.
3. The object’s lifetime begins.
4. You can use the object in your program.
5. The object’s lifetime ends.
6. The object’s destructor is called.
7. The object’s storage duration ends, and storage is deallocated.


Memory Management
If you’ve been programming in an application language, chances are you’ve
used an automatic memory manager, or a garbage collector. At runtime, programs
create objects. Periodically, the garbage collector determines which objects
are no longer required by the program and safely deallocates them. This
approach frees the programmer from worrying about managing an object’s
life cycle, but it incurs several costs, including runtime performance, and
requires some powerful programming techniques like deterministic
resource management.
C++ takes a more efficient approach. The trade-off is that C++ programmers must have intimate knowledge of storage durations. It’s our job,
not the garbage collector’s, to craft object lifetimes.


Memory Allocation
The variables discussed so far have followed two simple rules:
1. Memory for global variables remains allocated as long as the program
executes.
2. Memory for a variable declared within a block is allocated at block
entry and deallocated at block exit. For example, memory for the formal parameters and local variables of a function is allocated when the
function is called and deallocated when the function exits.


A variable for which memory is allocated at block entry and deallocated at block exit is called an automatic variable.

A variable for which memory remains allocated as long as the program executes is called a static variable.

Global variables are static variables, and by default, variables declared within a block are automatic variables.

You can declare a static variable within a block by using the reserved word static.
The syntax for declaring a static variable is:
static dataType identifier;






An object must be constructed (initialized) before it is used and will be destroyed at the end of its scope.  For a namespace object the point of destruction is the end of the program.  For a member, the point of destruction is determined by the point of destruction of the object of which it is a member.  An object created by new ‘‘lives’’ until destroyed by delete



Object Types

An automatic object is allocated at the beginning of an enclosing code block,
and it’s deallocated at the end. The enclosing block is the automatic object’s
scope. Automatic objects are said to have automatic storage duration. Note that
function parameters are automatic, even though notationally they appear
outside the function body.



A static object is declared using the static or extern keyword. You declare
static variables at the same level you declare functions—at global scope (or
namespace scope). Static objects with global scope have static storage duration
and are allocated when the program starts and deallocated when the program stops.

When you use the static keyword, you specify internal linkage. Internal
linkage means that a variable is inaccessible to other translation units. You
can alternately specify external linkage, which makes a variable accessible to
other translation units. For external linkage, you use the extern keyword
instead of static.

A local static variable is a special kind of static variable that is a local—rather
than global—variable. Local static variables are declared at function scope,
just like automatic variables. But their lifetimes begin upon the first invocation of the enclosing function and end when the program exits.

Static members are members of a class that aren’t associated with a particular
instance of the class. Normal class members have lifetimes nested within
the class’s lifetime, but static members have static storage duration.
These members are essentially similar to static variables and functions
declared at global scope; however, you must refer to them by the containing
class’s name, using the scope resolution operator ::. In fact, you must initialize static members at global scope. You cannot initialize a static member
within a containing class definition.

There is an exception to the static member initialization rule: you can declare and define integral types within a class definition as long as they’re also const.

Like other static variables, static members have only a single instance.
All instances of a class with static members share the same member, so if
you modify a static member, all class instances will observe the modification.




Thread-Local Storage Duration
One of the fundamental concepts in concurrent programs is the thread. Each
program has one or more threads that can perform independent operations. The sequence of instructions that a thread executes is called its
thread of execution.
Programmers must take extra precautions when using more than one
thread of execution. Code that multiple threads can execute safely is called
thread-safe code. Mutable global variables are the source of many thread safety
issues. Sometimes, you can avoid these issues by giving each thread its own
copy of a variable. You can do this by specifying that an object has thread storage duration.
You can modify any variable with static storage duration to have threadlocal storage duration by adding the thread_local keyword to the static or
extern keyword. If only thread_local is specified, static is assumed. The variable’s linkage is unchanged.


Dynamic Storage Duration
Objects with dynamic storage duration are allocated and deallocated on request.
You have manual control over when a dynamic object’s life begins and when it
ends. Dynamic objects are also called allocated objects for this reason.
The primary way to allocate a dynamic object is with a new expression. A
new expression begins with the new keyword followed by the desired type of
the dynamic object. New expressions create objects of a given type and then
return a pointer to the newly minted object.

You deallocate dynamic objects using the delete expression, which is composed of the delete keyword followed by a pointer to the dynamic object.
Delete expressions always return void.

The value contained in memory where the deleted object resided is
undefined, meaning the compiler can produce code that leaves anything
there. In practice, major compilers will try to be as efficient as possible, so
typically the object’s memory will remain untouched until the program
reuses it for some other purposes. You would have to implement a custom
destructor to, for example, zero out some sensitive contents.

N O T E
Because the compiler doesn’t typically clean up memory after an object is deleted, a subtle and potentially serious type of bug called a use after free can occur. If you
delete an object and accidentally reuse it, your program might appear to function correctly because the deallocated memory might still contain reasonable values. In some
situations, the problems don’t manifest until the program has been in production for a
long time—or until a security researcher finds a way to exploit the bug and discloses it!

Dynamic arrays are arrays with dynamic storage duration. You create
dynamic arrays with array new expressions. Array new expressions have the
following form:
new MyType[n_elements] { init-list }
MyType is the desired type of the array elements, n_elements is the length
of the desired array, and the optional init-list is an initialization list to initialize the array. Array new expressions return a pointer to the first element
of the newly allocated array.

To deallocate a dynamic array, use the array delete expression. Unlike the
array new expression, the array delete expression doesn’t require a length:
delete[] my_int_ptr;
Like the delete expression, the array delete expression returns void.

Memory Leaks
With privilege comes responsibility, so you must make sure that dynamic
objects you allocate are also deallocated. Failure to do so causes memory
leaks in which memory that is no longer needed by your program isn’t
released. When you leak memory, you use up a resource in your environment that you’ll never reclaim. This can cause performance problems
or worse.

N O T E

In practice, your program’s operating environment might clean up leaked resources
for you. For example, if you’ve written user-mode code, modern operating systems will
clean up the resources when the program exits. However, if you’ve written kernel code,
those operating systems won’t clean up the resources. You’ll only reclaim them when
the computer reboots.



Consider the following program. Four different Tracer objects have
different storage durations. By looking at the order of the program’s Tracer
output, you can verify what you’ve learned about storage durations.

Example
#include <cstdio>
struct Tracer {
Tracer(const char* nameu) : name{ name }v {
printf("%s constructed.\n", name); w
}
~Tracer() {
printf("%s destructed.\n", name); x
}
private:
const char* const name;
};

static Tracer t1{ "Static variable" }; u
thread_local Tracer t2{ "Thread-local variable" }; v
int main() {
printf("A\n"); w
Tracer t3{ "Automatic variable" }; x
printf("B\n");
const auto* t4 = new Tracer{ "Dynamic variable" }; y
printf("C\n");
}

Output:
Static variable constructed.
Thread-local variable constructed.
A
Automatic variable constructed.
B
Dynamic variable constructed.
C
Automatic variable destructed.
Thread-local variable destructed.
Static variable destructed.

A Tracer with static duration, thread local duration, automatic duration, and dynamic duration. Between each line in main, it prints the character A, B, or C for reference.

Before the first line of main, the static and thread local variables
t1 and t2 have been initialized. Both variables have printed their initialization messages before A. As an automatic variable, the scope of t3 is bounded by the enclosing function main.
Accordingly, t3 is constructed where it is initialized just after A.
After B, you see the message corresponding to the initialization of t4.
Notice that there’s no corresponding message generated by the dynamic
destructor of Tracer. The reason is that you’ve (intentionally) leaked the
object pointed to by t4. Because there’s no command to delete t4, the
destructor is never called. Just before main returns, C prints. Because t3 is an automatic variable
whose scope is main, it’s destroyed at this point because main is returning.
Finally, the static and thread-local variables t1 and t2 are destroyed just
before program exit, yielding the final two messages

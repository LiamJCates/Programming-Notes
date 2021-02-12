Resource Management




When we call new, a special member function called a constructor allocates the elements and initializes the members appropriately.

When we call delete, a special member function called a destructor deallocates the elements.

This handle-to-data model is very commonly used to manage data that can vary in size during the lifetime of an object.

The technique of acquiring resources in a constructor and releasing them in a destructor is known as Resource Acquisition Is Initialization or RAII.


RAII

RAII (Resource Acquisition Is Initialization) is a programming technique whereby resource use is tied to the lifetime of objects with automatic duration (e.g. non-dynamically allocated objects). In C++, RAII is implemented via classes with constructors and destructors. A resource (such as memory, a file or database handle, etc…) is typically acquired in the object’s constructor (though it can be acquired after the object is created if that makes sense). That resource can then be used while the object is alive. The resource is released in the destructor, when the object is destroyed. The primary advantage of RAII is that it helps prevent resource leaks (e.g. memory not being deallocated) as all resource-holding objects are cleaned up automatically.

The IntArray class at the top of this lesson is an example of a class that implements RAII -- allocation in the constructor, deallocation in the destructor. std::string and std::vector are examples of classes in the standard library that follow RAII -- dynamic memory is acquired on initialization, and cleaned up automatically on destruction.


RAII allows us to eliminate ‘‘naked new operations,’’ that is, to avoid allocations in general code and keep them buried inside the implementation of well-behaved abstractions, like constructors and destructors. Similarly, ‘‘naked delete operations’’ should be avoided. Avoiding naked new and naked delete makes code far less error-prone and far easier to keep free of resource leaks.

An example of the difference between using a dynamic allocation via a naked new and delete and using automatic allocation follows.  

We might created the two object on the heap by using pointers and calling
Object *ob1 = new Object;
Object *ob2 = new Object;

Then delete them
delete ob1;
delete ob2;

But we could have made them on the stack by just declaring them without pointers:
Object ob1;
Object ob2;

You can do this, and the application will run fine, provided you remove the delete lines.

You do not delete stack variables. The computer calls the destructor when the function they are contained by ends, and they go out of scope. That’s the general rule with objects on the stack: They are created when you declare them, and they stay until the function ends.










### Memory Management
If you’ve been programming in an application language, chances are you’ve used an automatic memory manager, or a garbage collector. At runtime, programs create objects. Periodically, the garbage collector determines which objects are no longer required by the program and safely deallocates them. This approach frees the programmer from worrying about managing an object’s life cycle, but it incurs several costs, including runtime performance, and requires some powerful programming techniques like deterministic resource management.

C++ takes a more efficient approach. The trade-off is that C++ programmers must have intimate knowledge of storage durations. It’s our job, not the garbage collector’s, to craft object lifetimes.


Memory Allocation
The variables discussed so far have followed two simple rules:
1. Memory for global variables remains allocated as long as the program
executes.
2. Memory for a variable declared within a block is allocated at block
entry and deallocated at block exit. For example, memory for the formal parameters and local variables of a function is allocated when the
function is called and deallocated when the function exits.

The value contained in memory where the deleted object resided is
undefined, meaning the compiler can produce code that leaves anything
there. In practice, major compilers will try to be as efficient as possible, so
typically the object’s memory will remain untouched until the program
reuses it for some other purposes. You would have to implement a custom
destructor to, for example, zero out sensitive content.

N O T E
Because the compiler doesn’t typically clean up memory after an object is deleted, a subtle and potentially serious type of bug called a use after free can occur. If you delete an object and accidentally reuse it, your program might appear to function correctly because the deallocated memory might still contain reasonable values. In some
situations, the problems don’t manifest until the program has been in production for a
long time—or until a security researcher finds a way to exploit the bug and discloses it!

Memory Leaks
With privilege comes responsibility, so you must make sure that dynamic
objects you allocate are also deallocated. Failure to do so causes memory
leaks in which memory that is no longer needed by your program isn’t
released. When you leak memory, you use up a resource in your environment that you’ll never reclaim. This can cause performance problems
or worse.

N O T E

In practice, your program’s operating environment might clean up leaked resources for you. For example, if you’ve written user-mode code, modern operating systems will
clean up the resources when the program exits. However, if you’ve written kernel code,
those operating systems won’t clean up the resources. You’ll only reclaim them when
the computer reboots.

























Avoiding naked new in modern C++

The old-days way of acquiring memory resources is to have a pair of malloc and free calls. The C++’s addition, the new and delete keywords simplified the syntax, but did not eliminate the problem of proper memory management.
The Problem

Here is a typical approach: you create some place for your data, get a pointer, and later you have to delete it yourself. In the following code fragment, the new and delete calls are called at correct places, but the program is still error-prone.

#include <iostream>

class data {
public:
    int value;    
};

int main() {
    data* p = new data[10];

    p[5].value = 42;
    std::cout << p[5].value << "\n";

    delete[] p;
}

Imagine now what happens if you append the following lines after destroying the data array.

int main() {
    data* p = new data[10];

    p[5].value = 42;
    std::cout << p[5].value << "\n";

    delete[] p;

    p[5].value++;
    std::cout << p[5].value << "\n";
}

The program access the data after its memory was released back to the operating system. I believe that in most cases you will not notice this when executing the program, as it will still work visually correct. Run it and you’ll see that it prints both 42 and 43 as if it indeed was working with the earlier allocated data.

In this example, both new and delete are located close to each other. In bigger examples, you may hide both of them in some kind of create and destroy function. It can happen that delete occurs to happen in one of the branch of some if–else check, and thus could be called incorrectly or not called at all.
The Solution

The proper solution is to allow the compiler to destroy the object at a proper time. You still need to call delete, but you place that in a destructor of an object. Having that done, you allow the compiler to call it at the end of the current scope.

The following modification of the program contains a helper class that does all the job for relocating and freeing memory.

#include <iostream>

class data {
public:
    int value;    
};

class DataList {
    data* storage;
public:
    DataList(int n) {
        storage = new data[n];
    }

    ~DataList() {
        delete[] storage;
    }

    data& operator[](int i) {
        return storage[i];
    }
};

int main() {
    DataList p(10);

    p[5].value = 42;
    std::cout << p[5].value << "\n";

    p[5].value++;
    std::cout << p[5].value << "\n";
}

It is not possible now to make any attempt of calling delete inside the main function. Neither you have any need to worry not to forget to call it.

At the end of the main function, the destructor DataList::~DataList() is called automatically. Its job is to free the memory for you.

From the user perspective, the data is still placed on heap, its size can be chosen at runtime if needed, but there is no way to make it wrong.

If you worry about the size of the second program, you have to look at the clearness of the updated main function first. The class definitions in real application are most likely placed in separate files and are part of a library. What has been achieved is simplification and safety of working with this code.



























By defining constructors, copy operations, move operations, and a destructor, a programmer can provide complete control of the lifetime of a contained resource (such as the elements of a container). Furthermore, a move constructor allows an object to move simply and cheaply from one scope to another. That way, objects that we cannot or would not want to copy out of a scope can be simply and cheaply moved out instead. Consider a standard-library thread representing a concurrent activity and a Vector of a million doubles. We can’t copy the former and don’t want to copy the latter.

std::vector<thread> my_threads;

Vector init(int n)
{
  thread t {heartbeat}; // run heartbeat concurrently (in a separate thread)
  my_threads.push_back(std::move(t)); // move t into my_threads
  // ... more initialization ...

  Vector vec(n);

  for (int i=0; i!=vec.size(); ++i)
    vec[i] = 777;

  return vec; // move vec out of init()
}

auto v = init(1'000'000); // star t hear tbeat and initialize v

Resource handles, such as Vector and thread, are superior alternatives to direct use of built-in pointers in many cases. In fact, the standard-library ‘‘smart pointers,’’ such as unique_ptr, are themselves resource handles.

I used the standard-library vector to hold the threads because we don’t get to parameterize our simple Vector with an element type unt.

In very much the same way that new and delete disappear from application code, we can make pointers disappear into resource handles.

In both cases, the result is simpler and more maintainable code, without added overhead. In particular, we can achieve strong resource safety; that is, we can eliminate resource leaks for a general notion of a resource.

Examples are vectors holding memory, threads holding system threads, and fstreams holding file handles.

In many languages, resource management is primarily delegated to a garbage collector. C++ also offers a garbage collection interface so that you can plug in a garbage collector. Garbage collection is the last choice after cleaner, more general, and better localized alternatives to resource management have been exhausted. The ideal is not to create any garbage, thus
eliminating the need for a garbage collector: Do not litter!

Garbage collection is fundamentally a global memory management scheme. Clever implementations can compensate, but as systems are getting more distributed (think caches, multicores, and clusters), locality is more important than ever.

Also, memory is not the only resource. A resource is anything that has to be acquired and (explicitly or implicitly) released after use. Examples are memory, locks, sockets, file handles, and thread handles. Unsurprisingly, a resource that is not just memory is called a non-memory resource. A good resource management system handles all kinds of resources. Leaks must be
avoided in any long-running system, but excessive resource retention can be almost as bad as a leak. For example, if a system holds on to memory, locks, files, etc. for twice as long, the system needs to be provisioned with potentially twice as many resources.

Before resorting to garbage collection, systematically use resource handles: let each resource have an owner in some scope and by default be released at the end of its owners scope. In C++, this is known as RAII (Resource Acquisition Is Initialization) and is integrated with error handling
in the form of exceptions. Resources can be moved from scope to scope using move semantics or ‘‘smart pointers,’’ and shared ownership can be represented by ‘‘shared pointers’’ .
In the C++ standard library, RAII is pervasive: for example, memory (string, vector, map,
unordered_map, etc.), files (ifstream, ofstream, etc.), threads (thread), locks (lock_guard, unique_lock,
etc.), and general objects (through unique_ptr and shared_ptr). The result is implicit resource management that is invisible in common use and leads to low resource retention durations



Copying Containers
When a class is a resource handle – that is, when the class is responsible for an object accessed through a pointer – the default memberwise copy is typically a disaster. Memberwise copy would
violate the resource handle’s invariant (§3.5.2). For example, the default copy would leave a copy
of a Vector referring to the same elements as the original:
void bad_copy(Vector v1)
{
Vector v2 = v1; // copy v1’s representation into v2
v1[0] = 2; // v2[0] is now also 2!
v2[1] = 3; // v1[1] is now also 3!
}
Assuming that v1 has four elements, the result can be represented graphically like this:
4
v1:
4
v2:
2 3
Fortunately, the fact that Vector has a destructor is a strong hint that the default (memberwise) copy
semantics is wrong and the compiler should at least warn against this example. We need to define
better copy semantics.
Copying of an object of a class is defined by two members: a copy constructor and a copy
assignment:
class Vector {
private:
double∗ elem; // elem points to an array of sz doubles
int sz;
public:
Vector(int s); // constr uctor: establish invariant, acquire resources
˜Vector() { delete[] elem; } // destr uctor: release resources
Vector(const Vector& a); // copy constr uctor
Vector& operator=(const Vector& a); // copy assignment
double& operator[](int i);
const double& operator[](int i) const;
int size() const;
};
A suitable definition of a copy constructor for Vector allocates the space for the required number of70 Essential Operations Chapter 5
elements and then copies the elements into it so that after a copy each Vector has its own copy of
the elements:
Vector::Vector(const Vector& a) // copy constr uctor
:elem{new double[a.sz]}, // allocate space for elements
sz{a.sz}
{
for (int i=0; i!=sz; ++i) // copy elements
elem[i] = a.elem[i];
}
The result of the v2=v1 example can now be presented as:
4
v1:
4
v2:
2 2
Of course, we need a copy assignment in addition to the copy constructor:
Vector& Vector::operator=(const Vector& a) // copy assignment
{
double∗ p = new double[a.sz];
for (int i=0; i!=a.sz; ++i)
p[i] = a.elem[i];
delete[] elem; // delete old elements
elem = p;
sz = a.sz;
return ∗this;
}
The name this is predefined in a member function and points to the object for which the member
function is called.

Moving Containers
We can control copying by defining a copy constructor and a copy assignment, but copying can be costly for large containers. We avoid the cost of copying when we pass objects to a function by using references, but we can’t return a reference to a local object as the result (the local object would be destroyed by the time the caller got a chance to look at it).

Consider:

Vector operator+(const Vector& a, const Vector& b)
{
  if (a.size()!=b.siz e())
  throw Vector_size_mismatch{};
  Vector res(a.size());Section 5.2.2 Moving Containers 71
  for (int i=0; i!=a.size(); ++i)
  res[i]=a[i]+b[i];
  return res;
}

Returning from a + involves copying the result out of the local variable res and into some place where the caller can access it. We might use this + like this:

void f(const Vector& x, const Vector& y, const Vector& z)
{
Vector r;
// ...
r = x+y+z;
// ...
}

That would be copying a Vector at least twice (one for each use of the + operator). If a Vector is large, say, 10,000 doubles, that could be embarrassing. The most embarrassing part is that res in operator+() is never used again after the copy. We didn’t really want a copy; we just wanted to get
the result out of a function: we wanted to move a Vector rather than copy it. Fortunately, we can state that intent:

class Vector {
  // ...
  Vector(const Vector& a);              // copy constructor
  Vector& operator=(const Vector& a);   // copy assignment
  Vector(Vector&& a);                   // move constructor
  Vector& operator=(Vector&& a);        // move assignment
};

Given that definition, the compiler will choose the move constructor to implement the transfer of the return value out of the function. This means that r=x+y+z will involve no copying of Vectors.

Instead, Vectors are just moved.

As is typical, Vector’s move constructor is trivial to define:

Vector::Vector(Vector&& a)
:elem{a.elem}, // "grab the elements" from a
sz{a.sz}
{
  a.elem = nullptr; // now a has no elements
  a.sz = 0;
}

The && means ‘‘rvalue reference’’ and is a reference to which we can bind an rvalue. The word ‘‘rvalue’’ is intended to complement ‘‘lvalue,’’ which roughly means ‘‘something that can appear on the left-hand side of an assignment.’’ So an rvalue is – to a first approximation – a value that you can’t assign to, such as an integer returned by a function call. Thus, an rvalue reference is a reference to something that nobody else can assign to, so we can safely ‘‘steal’’ its value. The res local variable in operator+() for Vectors is an example.


A move constructor does not take a const argument: after all, a move constructor is supposed to remove the value from its argument. A move assignment is defined similarly.

A move operation is applied when an rvalue reference is used as an initializer or as the righthand side of an assignment.
After a move, a moved-from object should be in a state that allows a destructor to be run. Typically, we also allow assignment to a moved-from object. The standard-library algorithms (Chapter
12) assumes that. Our Vector does that.
Where the programmer knows that a value will not be used again, but the compiler can’t be
expected to be smart enough to figure that out, the programmer can be specific:
Vector f()
{
Vector x(1000);
Vector y(2000);
Vector z(3000);
z = x; // we get a copy (x might be used later in f())
y = std::move(x); // we get a move (move assignment)
// ... better not use x here ...
return z; // we get a move
}
The standard-library function move() doesn’t actually move anything. Instead, it returns a reference
to its argument from which we may move – an rvalue reference; it is a kind of cast (§4.2.3).
Just before the return we have:
nullptr 0
x:
1000
y:
1000
z:
1 2 ... 1 2 ...
When we return from f(), z is destroyed after its elements has been moved out of f() by the return.
However, y’s destructor will delete[] its elements.
The compiler is obliged (by the C++ standard) to eliminate most copies associated with initialization, so move constructors are not invoked as often as you might imagine. This copy elision
eliminates even the very minor overhead of a move. On the other hand, it is typically not possible
to implicitly eliminate copy or move operations from assignments, so move assignments can be
critical for performance.

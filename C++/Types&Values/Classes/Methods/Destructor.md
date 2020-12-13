## Destructor
A destructor, like a constructor, is a special function. A constructor is invoked at object instantiation, and a destructor is automatically invoked when an object is destroyed.

An object’s destructor is its cleanup function.

Destructors are almost never called explicitly: the compiler will ensure that each object’s destructor is called as appropriate.

Defining a destructor is optional.

If you do decide to implement a destructor, it must not take any arguments. Examples of actions you might want to take in a destructor include releasing file handles, flushing network sockets, and freeing dynamic objects.

If you don’t define a destructor, a default destructor is automatically generated. The default destructor’s behavior is to perform no action.


## Declaring a Destructor
A destructor is a function that is automatically invoked when an object is destroyed. A destructor is always invoked when an object of a class is destroyed when it goes out of scope or is deleted via delete. This property makes a destructor the ideal place to reset variables and release dynamically allocated memory and other resources.

Several rules govern the declaration of destructors, destructors:
  Do not accept arguments.
  Do not return a value (or void).
  There is only one destructor declared per class, it cannot be overloaded.
  Destructors are functions with the same name as the class but preceded by a tilde (~)
  Cannot be declared as const, volatile, or static. However, they can be invoked for the destruction of objects declared as const, volatile, or static.
  Can be declared as virtual. Using virtual destructors, you can destroy objects without knowing their type — the correct destructor for the object is invoked using the virtual function mechanism. Note that destructors can also be declared as pure virtual functions for abstract classes.


So, class MyClass would have a destructor that is declared like this:

class MyClass
{
  ~MyClass(); // declaration of a destructor
};

This destructor can either be implemented inline in the class or externally outside the class declaration. An implementation or definition inside the class looks like this:

class MyClass
{
public:
  ~MyClass()
  {
  // destructor code here
  }
};

A variant enabling you to define the destructor outside the class’s declaration looks like this:
class MyClass
{
public:
~MyClass(); // destructor declaration
};
// destructor definition (implementation)
MyClass::~MyClass()
{
// destructor code here
}


If you forget to implement a destructor, the compiler creates and invokes a dummy destructor, that is, an empty one (that does no cleanup of dynamically allocated memory).




## Implementing a Constructor

Consider

struct Node {
  char *name;
  int age;
public:
  Node(char *n = "", int a = 0) {
    name = strdup(n);
    age = a;
  }
};

What happens to locally defined objects of type Node? Like all local items, they are destroyed in the sense that they become unavailable outside the block in which they are defined, and memory occupied by them is also released.

But although memory occupied by an object of type Node is released, not all the memory related to this object becomes available. One of the data members of this object is a pointer to a string; therefore, memory occupied by the pointer data member is released, but memory taken by the string is not.

After the object is destroyed, the string previously available from its data member name becomes inaccessible (if not assigned to the name of some other object or to a string variable) and memory occupied by this string can no longer be released, which leads to a memory leak.

This is a problem with objects that have data members pointing to dynamically allocated locations. To avoid the problem, the class definition should include a definition of a destructor.

For the class Node, a destructor can be defined as
~Node() {
  if (name != 0)
  free(name);
}



Using destructors

Destructors are called when one of the following events occurs:

    A local (automatic) object with block scope goes out of scope.

    An object allocated using the new operator is explicitly deallocated using delete.

    The lifetime of a temporary object ends.

    A program ends and global or static objects exist.

    The destructor is explicitly called using the destructor function's fully qualified name.

Destructors can freely call class member functions and access class member data.

There are two restrictions on the use of destructors:

    You cannot take its address.

    Derived classes do not inherit the destructor of their base class.

Order of destruction

When an object goes out of scope or is deleted, the sequence of events in its complete destruction is as follows:

    The class's destructor is called, and the body of the destructor function is executed.

    Destructors for nonstatic member objects are called in the reverse order in which they appear in the class declaration. The optional member initialization list used in construction of these members does not affect the order of construction or destruction.

    Destructors for non-virtual base classes are called in the reverse order of declaration.

    Destructors for virtual base classes are called in the reverse order of declaration.




Virtual Destructor
Classes and Virtual Destructors
One thing recommended for classes with pointer member variables is that these
classes should have the destructor. The destructor executes automatically when the
class object goes out of scope. Thus, if the object creates dynamic memory space, the
destructor can be designed to deallocate that memory space. If a derived class object
is passed to a formal parameter of the base class type, the destructor of the base class
executes regardless of whether the derived class object is passed by reference or by
value. Logically, however, the destructor of the derived class should be executed when
the derived class object goes out of scope.
To correct this problem, the destructor of the base class must be virtual. The virtual
destructor of a base class automatically makes the destructor of a derived class virtual.
When a derived class object is passed to a formal parameter of the base class type, then
when the object goes out of scope, the destructor of the derived class executes. After
executing the destructor of the derived class, the destructor of the base class executes.
Therefore, when the derived class object is destroyed, the base class part (that is, the
members inherited from the base class) of the derived class object is also destroyed.
If a base class contains virtual functions, make the destructor of the base class virtual.


Can a destructor be pure virtual in C++?
Yes, it is possible to have pure virtual destructor. Pure virtual destructors are legal in standard C++ and one of the most important things to remember is that if a class contains a pure virtual destructor, it must provide a function body for the pure virtual destructor. You may be wondering why a pure virtual function requires a function body. The reason is because destructors (unlike other functions) are not actually ‘overridden’, rather they are always called in the reverse order of the class derivation. This means that a derived class’ destructor will be invoked first, then base class destructor will be called. If the definition of the pure virtual destructor is not provided, then what function body will be called during object destruction? Therefore the compiler and linker enforce the existence of a function body for pure virtual destructors.
Consider the following program:

#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed";
    }
};

int main()
{
    Base *b=new Derived();
    delete b;
    return 0;
}

The linker will produce following error in the above program.

test.cpp:(.text$_ZN7DerivedD1Ev[__ZN7DerivedD1Ev]+0x4c):
undefined reference to 'Base::~Base()'

Now if the definition for the pure virtual destructor is provided, then the program compiles & runs fine.

#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};
Base::~Base()
{
    std::cout << "Pure virtual destructor is called";
}

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed\n";
    }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}

Output:

~Derived() is executed
Pure virtual destructor is called

It is important to note that a class becomes abstract class when it contains a pure virtual destructor. For example, try to compile the following program.



#include <iostream>
class Test
{
public:
    virtual ~Test()=0; // Test now becomes abstract class
};
Test::~Test() { }

int main()
{
    Test p;
    Test* t1 = new Test;
    return 0;
}

The above program fails in compilation & shows following error messages.
[Error] cannot declare variable ‘p’ to be of abstract type ‘Test’
[Note] because the following virtual functions are pure within ‘Test’:
[Note] virtual Test::~Test()
[Error] cannot allocate an object of abstract type ‘Test’
[Note] since type ‘Test’ has pure virtual functions

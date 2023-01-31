## Destructor
An object’s destructor is its cleanup function.

A destructor, like a constructor, is a special method, which is involved with the proper handeling of an object's memory resources.

Destructor methods are used to do the clean-up of the memory contained in the object. In this sense, a destructor peforms the opposite role of a constructor.

While a constructor is invoked at object instantiation to allocate necessary memory, a destructor is automatically invoked when an object is destroyed to return allocated memory to the system.

A destructor is always invoked when an object of a class is destroyed; when it goes out of scope or is deleted via delete. This property makes a destructor the ideal place to reset variables and release dynamically allocated memory and other resources.

Unlike constructors, destructors are almost never called explicitly: the compiler will ensure that each object’s destructor is called as appropriate.

Examples of actions you might want to take in a destructor include releasing file handles, flushing network sockets, and freeing dynamical allocated objects/memory.




## Declaring a Destructor

Defining a destructor is optional. If you don’t define a destructor, a default destructor is automatically generated. The default destructor’s behavior is to perform no action.

One thing recommended for classes with pointer member variables is that these
classes should have a destructor. If the object creates dynamic memory space, the destructor can be designed to deallocate that memory space.

If you do decide to implement a destructor, there are several rules which govern the declaration of destructors, destructors:
  Do not accept arguments.
  Do not return a value (or void).
  There is only one destructor declared per class, it cannot be overloaded.
  Destructors are functions with the same name as the class but preceded by a tilde (~)
  Cannot be declared as const, volatile, or static. However, they can be invoked for the destruction of objects declared as const, volatile, or static.
  Can be declared as virtual. Using virtual destructors, you can destroy objects without knowing their type — the correct destructor for the object is invoked using the virtual function mechanism. Note that destructors can also be declared as pure virtual functions for abstract classes.


As stated above, destructor methods are indicated by a “~” prepended to the name of the class.

So, class MyClass would have a destructor that is declared like this:

```cpp
class MyClass
{
  ~MyClass(); // declaration of a destructor
};
```

This destructor can either be implemented inline in the class or externally outside the class declaration.

An implementation or definition inside the class looks like this:

```cpp
class MyClass
{
public:
  ~MyClass()
  {
    // destructor code here
  }
};
```

A variant enabling definition outside the class’s declaration looks like this:

```cpp
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
```

If you forget to implement a destructor, the compiler creates and invokes a dummy destructor, that is, an empty one (that does no cleanup of dynamically allocated memory).




## Implementing a Destructor

Consider

```cpp
struct Node {
  char *name;
  int age;
public:
  Node(char *n = "", int a = 0)
  {
    name = strdup(n);
    age = a;
  }
};
```

What happens to locally defined objects of type Node? Like all local items, they are destroyed when they go out of scope, when they become unavailable outside the block in which they are defined, and memory occupied by them is also released.

But although memory occupied by an object of type Node is released, not all the memory related to this object becomes available. One of the data members of this object is a pointer to a string; therefore, memory occupied by the pointer data member is released, but memory taken by the string is not.

After the object is destroyed, the string previously available from its data member name becomes inaccessible (if not assigned to the name of some other object or to a string variable) and memory occupied by this string can no longer be released, which leads to a memory leak.

This is a problem with objects that have data members pointing to dynamically allocated locations. To avoid the problem, the class definition should include a definition of a destructor.

For the class Node, a destructor can be defined as

```cpp
~Node()
{
  if (name)
  free(name);
}
```


## Using destructors

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



## Order of destruction

When an object goes out of scope or is deleted, the sequence of events in its complete destruction is as follows:

    The class's destructor is called, and the body of the destructor function is executed.

    Destructors for nonstatic member objects are called in the reverse order in which they appear in the class declaration. The optional member initialization list used in construction of these members does not affect the order of construction or destruction.

    Destructors for non-virtual base classes are called in the reverse order of declaration.

    Destructors for virtual base classes are called in the reverse order of declaration.

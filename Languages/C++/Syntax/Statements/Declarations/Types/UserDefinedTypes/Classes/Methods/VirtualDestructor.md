Destructors require special consideration in relation to inheritance.

When an object in the class goes out of scope or the execution of the main() function is about to end, a destructor is automatically called into the program to free up the space occupied by the class' destructor function.

If a derived class object is referenced by the base class type, the destructor of the base class is all that executes due to the early bind by the compiler.

In this way, it skips calling the derived class' destructor, which leads to memory leaks issue in the program.

Logically, the destructor of the derived class should be executed when the derived class object goes out of scope. To correct this problem, the destructor of the base class must be virtual.



### Virtual Destructor

When we use virtual keyword preceded by the destructor tilde (~) sign inside the base class, it guarantees that first the derived class' destructor is called, then the base class' destructor is called to release the space occupied by both destructors in the inheritance class.

A virtual destructor is used to free up the memory space allocated by the derived class object or instance while deleting instances of the derived class using a base class pointer object. A base or parent class destructor use the virtual keyword that ensures both base class and the derived class destructor will be called at run time, but it called the derived class first and then base class to release the space occupied by both destructors.

The virtual destructor of a base class automatically makes the destructor of a derived class virtual. Then when a derived class object referenced by the base class type, and the object goes out of scope, the destructor of the derived class executes. After executing the destructor of the derived class, the destructor of the base class executes.

Therefore, when the derived class object is destroyed, the base class part (that is, the members inherited from the base class) of the derived class object is also destroyed.


NOTE
If a base class contains virtual functions, make the destructor of the base class virtual.

Deleting a derived class object using a pointer to a base class, the base class should be defined with a virtual destructor.





Destructors in the Base class can be Virtual.

Whenever Upcasting is done, when a derived type is referenced using the a base type, destructors of the Base class must be made virtual for proper destrucstion of the object when the program exits.

NOTE: Constructors are never Virtual, only Destructors can be Virtual.
Upcasting without Virtual Destructor in C++



### With No Virtual Distructor

Lets first see what happens when we do not have a virtual Base class destructor.

```cpp
class Base
{
    public:
    ~Base()
    {
        cout << "Base Destructor\n";
    }
};

class Derived:public Base
{
    public:
    ~Derived()
    {
        cout<< "Derived Destructor\n";
    }
};

int main()
{
    Base* b = new Derived;     // Upcasting
    delete b;
}
```

Output
```
Base Destructor
```
In the above example, delete b will only call the Base class destructor, which is undesirable because, then the object of Derived class remains undestructed, because its destructor is never called. Which results in memory leak.

Note: If the base class destructor does not use a virtual keyword, only the base class destructor will be called or deleted its occupied space because the pointer object is pointing to the base class. So it does not call the derived class destructor to free the memory used by the derived class, which leads to memory leak for the derived class.



### Upcasting with Virtual Destructor in C++

Now lets see. what happens when we have Virtual destructor in the base class.

```cpp
class Base
{
    public:
    virtual ~Base()
    {
        cout << "Base Destructor\n";
    }
};

class Derived:public Base
{
    public:
    ~Derived()
    {
        cout<< "Derived Destructor";
    }
};

int main()
{
    Base* b = new Derived;     // Upcasting
    delete b;
}
```

Output:
```
Derived Destructor
Base Destructor
```

When we have Virtual destructor inside the base class, then first Derived class's destructor is called and then Base class's destructor is called, which is the desired behaviour.




### Pure Virtual Destructors

Pure virtual destructors are legal in standard C++.

One of the most important things to remember is that if a class contains a pure virtual destructor, it must provide a function body for the pure virtual destructor.

pure virtual Destructors must be defined, which is against the pure virtual behaviour.

You may be wondering why a pure virtual function requires a function body. The reason is because destructors (unlike other functions) are not actually ‘overridden’, rather they are always called in the reverse order of the class derivation. This means that a derived class’ destructor will be invoked first, then base class destructor will be called. If the definition of the pure virtual destructor is not provided, then what function body will be called during object destruction? Therefore the compiler and linker enforce the existence of a function body for pure virtual destructors.

The only difference between Virtual and Pure Virtual Destructor is, that pure virtual destructor will make its Base class Abstract, hence you cannot create object of that class.

There is no requirement of implementing pure virtual destructors in the derived classes.


Consider the following program:

```cpp
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
```

The linker will produce following error in the above program.
```
test.cpp:(.text$_ZN7DerivedD1Ev[__ZN7DerivedD1Ev]+0x4c):
undefined reference to 'Base::~Base()'
```
Now if the definition for the pure virtual destructor is provided, then the program compiles & runs fine.

```cpp
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
```
Output:
```
~Derived() is executed
Pure virtual destructor is called
```

It is important to note that a class becomes abstract class when it contains a pure virtual destructor. For example, try to compile the following program.

```cpp
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
```
The above program fails in compilation & shows following error messages.
```
[Error] cannot declare variable ‘p’ to be of abstract type ‘Test’
[Note] because the following virtual functions are pure within ‘Test’:
[Note] virtual Test::~Test()
[Error] cannot allocate an object of abstract type ‘Test’
[Note] since type ‘Test’ has pure virtual functions
```

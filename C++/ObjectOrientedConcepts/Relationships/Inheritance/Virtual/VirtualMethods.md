## Virtual Functions

A "virtual function" is a special type of method that, when called, resolves to the most-derived match of that method that exists between the base and derived class. A derived function is considered a match if it is an override of the base class function; it has the same signature (name, parameter types, and whether it is const) and return type as the base version of the function.

For more information regarding method override, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\CreatingDerivedClasses\MethodOverride.md]

To specify a virtual function, prepend the “virtual” keyword to the method signature:

  virtual return-type method-name(parameter-list) { // body }

Unlike a non-virtual function, when a virtual function is overridden the most-derived version is used at all levels of the class hierarchy, rather than just the level at which it was created.

This is in contrast to non-virtual functions, which can still be overridden in a derived class, but the "new" version will only be used by the derived class and below, but will not change the functionality of the base class at all.



### Virtual functions and polymorphism

In C++, a virtual function or virtual method is an inheritable and overridable function or method for which dynamic dispatch is facilitated.

In short, a virtual function defines a target function to be executed, but the target might not be known at compile time. This concept is an important part of the (runtime) polymorphism portion of object-oriented programming (OOP).



### Use of the virtual keyword

If a function is marked as virtual, all matching overrides are also considered virtual, even if they are not explicitly marked as such. However, having the keyword virtual on the derived functions does not hurt, and it serves as a useful reminder that the function is a virtual function rather than a normal one. Consequently, it’s generally a good idea to use the virtual keyword for virtualized functions in derived classes even though it’s not strictly necessary.



### Example

  #include <iostream>
  #include <string>
  using namespace std;

  class Base
  {
  public:
  	// note virtual keyword specifies a virtual method
  	virtual std::string getName() const { return "Base"; }
  };

  class Derived : public Base
  {
  public:
  	virtual std::string getName() const { return "Derived"; }
  };

  int main()
  {
  	Derived derived;
  	Base &rBase{derived};
  	std::cout << "rBase is a " << rBase.getName() << '\n';

  	return 0;
  }

Output:

  rBase is a Derived

Because rBase is a reference to the Base portion of a Derived object, when rBase.getName() is evaluated, it would normally resolve to Base::getName(). However, Base::getName() is virtual, which tells the program to go look and see if there are any more-derived versions of the function available between Base and Derived. In this case, it will resolve to Derived::getName()!

Note:
the signature of the derived class function must exactly match the signature of the base class virtual function in order for the derived class function to be used. If the derived class function has different parameter types, the program will likely still compile fine, but the virtual function will not resolve as intended.

For an example use case of virtual functions, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\VirtualMethodExample.md]



### Virtual Function Override

A derived class virtual function is only considered an override if its signature and return types match exactly. That can lead to inadvertent issues, where a function that was intended to be an override actually isn’t.

Consider the following example:

  class A
  {
  public:
  	virtual const char* getName1(int x) { return "A"; }
  	virtual const char* getName2(int x) { return "A"; }
  };

  class B : public A
  {
  public:
    // note: parameter is a short int
  	virtual const char* getName1(short int x) { return "B"; }

    // note: function is const
    virtual const char* getName2(int x) const { return "B"; }
  };

  int main()
  {
  	B b{};
  	A& rBase{ b };
  	std::cout << rBase.getName1(1) << '\n';
  	std::cout << rBase.getName2(2) << '\n';

  	return 0;
  }

Output:

  A
  A

Because rBase is an A reference to a B object, the intention here is to use virtual functions to access B::getName1() and B::getName2(). However, because B::getName1() takes a different parameter (a short int instead of an int), it’s not considered an override of A::getName1(). More insidiously, because B::getName2() is const and A::getName2() isn’t, B::getName2() isn’t considered an override of A::getName2().


In this particular case, because A and B just print their names, it’s fairly easy to see that we messed up our overrides, and that the wrong virtual function is being called. However, in a more complicated program, where the functions have behaviors or return values that aren’t printed, such issues can be very difficult to debug.


### The override specifier

To help address the issue of functions that are meant to be overrides but aren’t, C++11 introduced the override specifier. The override specifier can be applied to any override function as a suffix. If the function does not override a base class function (or is applied to a non-virtual function), the compiler will flag the function as an error.

  class A
  {
  public:
  	virtual const char* getName1(int x) { return "A"; }
  	virtual const char* getName2(int x) { return "A"; }
  	virtual const char* getName3(int x) { return "A"; }
  };

  class B : public A
  {
  public:
  	virtual const char* getName1(short int x) override { return "B"; } // compile error, function is not an override
  	virtual const char* getName2(int x) const override { return "B"; } // compile error, function is not an override
  	virtual const char* getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)

  };

  int main()
  {
  	return 0;
  }

The above program produces two compile errors: one for B::getName1(), and one for B::getName2(), because neither override a prior function. B::getName3() does override A::getName3(), so no error is produced for that line.

There is no performance penalty for using the override specifier, and it helps avoid inadvertent errors. Consequently, we highly recommend using it for every virtual function override you write to ensure you’ve actually overridden the function you think you have.

Rule

Apply the override specifier to every intended override function you write.



#### Return types of virtual functions

Under normal circumstances, the return type of a virtual function and its override must match:

  class Base
  {
  public:
    virtual int getValue() const { return 5; }
  };

  class Derived: public Base
  {
  public:
    virtual double getValue() const { return 6.78; }
  };

In this case, Derived::getValue() is not considered a matching override for Base::getValue() (it is considered a completely separate function).




#### Do not call virtual functions from constructors or destructors

Rule: Never call virtual functions from constructors or destructors

Remember that when a derived class is instantiate, the base class portion is constructed first. If you were to call a virtual function from the base class constructor, and derived portion of the class would not have been instantiated yet. Thus the derived version of the function would not be callable as there’s no derived object for the derived function to work on. In C++, the base version of the function will be called, this may provide unexpected behavior.

A similar issue exists for destructors. If you call a virtual function in a base class destructor, it will always resolve to the base class version of the function, because the derived portion of the class will have already been destroyed.

For examples of construction and destruction order of class hierarchies see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\CreatingDerivedClasses\Construction&Destruction.md]



#### The downside of virtual functions

Since most of the time you’ll want your functions to be virtual, why not just make all functions virtual?

It’s inefficient -- resolving a virtual function call takes longer than resolving a regular one. Furthermore, the compiler also has to allocate an extra pointer for each class object that has one or more virtual functions.

Virtual functions can incur runtime overhead, although the cost is typically low (within 25 percent of a regular function call). The compiler generates virtual function tables (vtables) that contain function pointers. At runtime, a consumer of an interface doesn’t generally know its underlying type, but it knows how to invoke the interface’s methods (thanks to the vtable).

In some circumstances, the linker can detect all uses of an interface and devirtualize a function call. This removes the function call from the vtable and thus eliminates associated runtime cost.



### Ignoring virtualization

Very rarely you may want to ignore the virtualization of a function. For example, consider the following code:

  class Base
  {
  public:
     virtual const char* getName() const { return "Base"; }
  };

  class Derived: public Base
  {
  public:
     virtual const char* getName() const { return "Derived"; }
  };

There may be cases where you want a Base pointer to a Derived object to call Base::getName() instead of Derived::getName(). To do so, simply use the scope resolution operator:

  #include <iostream>
  int main()
  {
     Derived derived;
     const Base &base { derived };
     // Calls Base::GetName() instead of the virtualized Derived::GetName()
     std::cout << base.Base::getName() << '\n';

     return 0;
  }

You probably won’t use this very often, but it’s good to know it’s at least possible.



## Virtual destructors

Although C++ provides a default destructor for your classes if you do not provide one yourself, it is sometimes the case that you will want to provide your own destructor (particularly if the class needs to deallocate memory). You should always make your destructors virtual if you’re dealing with inheritance. Consider the following example:

	#include <iostream>
	class Base
	{
	public:
	   ~Base() // note: not virtual
	   {
	       std::cout << "Calling ~Base()\n";
	   }
	};

	class Derived: public Base
	{
	private:
	   int* m_array;

	public:
	   Derived(int length)
	     : m_array{ new int[length] }
	   {
	   }

	   ~Derived() // note: not virtual (your compiler may warn you about this)
	   {
	       std::cout << "Calling ~Derived()\n";
	       delete[] m_array;
	   }
	};

	int main()
	{
	   Derived *derived { new Derived(5) };
	   Base *base { derived };

	   delete base;
	}

Output:

  Calling ~Base()

We receive this output because base is a Base pointer, when base is deleted, the program looks to see if the Base destructor is virtual. As it is not, only the Base destructor is called.

Note:
If you compile the above example, your compiler may warn you about the non-virtual destructor (which is intentional for this example). You may need to disable the compiler flag that treats warnings as errors to proceed.

However, we really want the delete function to call Derived’s destructor (which will call Base’s destructor in turn), otherwise m_array will not be deleted. We do this by making Base’s destructor virtual:

	#include <iostream>
	class Base
	{
	public:
	   virtual ~Base() // note: virtual
	   {
	       std::cout << "Calling ~Base()\n";
	   }
	};

	class Derived: public Base
	{
	private:
	   int* m_array;

	public:
	   Derived(int length)
	     : m_array{ new int[length] }
	   {
	   }

	   virtual ~Derived() // note: virtual
	   {
	       std::cout << "Calling ~Derived()\n";
	       delete[] m_array;
	   }
	};

	int main()
	{
	   Derived *derived { new Derived(5) };
	   Base *base { derived };

	   delete base;

	   return 0;
	}

Output:

  Calling ~Derived()
  Calling ~Base()

Rule: Whenever you are dealing with inheritance, you should make any explicit destructors virtual.

As with normal virtual member functions, if a base class function is virtual, all derived overrides will be considered virtual regardless of whether they are specified as such. It is not necessary to create an empty derived class destructor just to mark it as virtual.

Should we make all destructors virtual?

If the base class destructor isn’t marked as virtual, then the program is at risk for leaking memory if a programmer later deletes a base class pointer that is pointing to a derived object. One way to avoid this is to mark all your destructors as virtual. But should you?

It’s easy to say yes, so that way you can later use any class as a base class -- but there’s a performance penalty for doing so (a virtual pointer added to every instance of your class). So you have to balance that cost, as well as your intent.

Conventional wisdom (as initially put forth by Herb Sutter, a highly regarded C++ guru) has suggested avoiding the non-virtual destructor memory leak situation as follows, “A base class destructor should be either public and virtual, or protected and nonvirtual.” A class with a protected destructor can’t be deleted via a pointer, thus preventing the accidental deleting of a derived class through a base pointer when the base class has a non-virtual destructor. Unfortunately, this also means the base class can’t be deleted through a base class pointer, which essentially means the class can’t be dynamically allocated or deleted except by a derived class. This also precludes using smart pointers (such as std::unique_ptr and std::shared_ptr) for such classes, which limits the usefulness of that rule (we cover smart pointers in a later chapter). It also means the base class can’t be allocated on the stack. That’s a pretty heavy set of penalties.

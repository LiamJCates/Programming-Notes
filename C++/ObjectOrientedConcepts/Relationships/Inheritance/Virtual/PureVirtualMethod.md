## Pure virtual (abstract) functions

C++ allows the creation of a special kind of virtual function called a pure virtual function (or abstract function). While a virtual function provides a way to override the functionality of the base class, and a pure-virtual function requires it.

To create a basic pure virtual function, rather than define a body for the virtual function, we simply assign the function the value 0:

  virtual return-type function-name() suffix-modifiers = 0;

where "= 0;" is known as a pure virtual specifier

When a pure virtual function is defined within a class, the class is "abstract" and can no longer be instantiated. A pure virtual function declaration effectively says, “it is required by a derived classes to implement this function”.

For more information regarding abstract classes, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\AbstractClass.md]

A pure virtual function is a virtual function that is required to be implemented by a derived class if the derived class is to have the ability to be instantiated, to not be abstract. By specifying pure virtual functions the programmer can create a contract with all future derived classes indicating what behavior is required by a class that is to be instantiable, we call such classes "concrete".

A pure virtual function declaration simply acts as a placeholder that is meant to be redefined by derived classes.  

The following is an example of an abstract class:

	class AbstractClass {
	public:
	  virtual void f() = 0;
	};

In summary, the key consequences of using a pure virtual function are:
  Any class with one or more pure virtual functions becomes an "abstract" base class, which means that it can not be instantiated.
  Any derived class must define a body for this function, or that derived class will be considered an abstract base class as well.
	The abstract base class declares a contract that a derived concrete classes must fulfill by implementing required behavior.

Errors
	A non-class function cannot have a pure specifier
	A non-virtual function cannot have a pure specifier
	A method declaration cannot have both a pure specifier and a definition


### Example

  #include <iostream>

  class AbstractBase
  {
  public:
  	// a normal non-virtual function
  	const char *sayHi() const { return "Hi"; }

  	// a normal virtual function
  	virtual const char *getName() const { return "Base"; }

  	// a pure virtual function
  	virtual int getValue() const = 0;

  	// Compile error: can not set non-virtual functions to 0
  	// int doSomething() = 0;

  	// Compile error: illegal pure specifier and method definition
  	// virtual void g() { } = 0;
  };

  class ConcreteDerived : public AbstractBase
  {
  	int value;

  public:
  	ConcreteDerived(int value) : value(value) {}

  	int getValue() { return value; }
  };

  int main()
  {
  	// AbstractBase ab;		We can't instantiate an abstract base class
  	// ab.getValue(); 		If we could, what would this do?

  	ConcreteDerived cd(1);
  	std::cout << cd.getValue() << '\n';
  }

Because there’s no definition for getValue(), base.getValue() would be unable to resolve.

A pure virtual function is useful when we have a function that we want to put in the base class, but only the derived classes know what it should return. A pure virtual function makes it so the base class can not be instantiated, and the derived classes are forced to define these functions before they can be instantiated. This helps ensure the derived classes do not forget to redefine functions that the base class was expecting them to.

For a simple pure virtual function use case, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\PureVirtualExample.md]



### Pure virtual Function Bodies

It turns out that we can define pure virtual functions that have bodies:

  class AbstractBase
  {
  public:
    virtual int getValue() const = 0;
  };

  int AbstractBase::getValue() const { return 0; }

When providing a body for a pure virtual function, the body must be provided separately using scope resolution, not inline.

In this case, getValue() is still considered a pure virtual function because of the pure virtual function specifier “=0” (even though it has been given a body) and AbstractBase is still considered an abstract base class (and thus can’t be instantiated). Any class that inherits from AbstractBase needs to provide its own definition for getValue() or it will also be considered an abstract base class.

This paradigm can be useful when you want your base class to provide a default implementation for a function, but still force any derived classes to provide their own implementation. However, if the derived class is happy with the default implementation provided by the base class, it can simply call the base class implementation directly.


class ConcreteDerived : public AbstractBase
{
public:
  int getValue() const
  {
    return AbstractBase::getValue();
  }
};

This capability isn’t used very commonly.

For a use case whereby a pure virtual function body defines default behavior, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\PureVirtualDefaultExample.md]



### Pure virtual functions and the virtual table

Abstract classes still have virtual tables, as these can still be used if you have a pointer or reference to the abstract class. The virtual table entry for a pure virtual function will generally either contain a null pointer, or point to a generic function that prints an error (sometimes this function is named __purecall) if no override is provided.

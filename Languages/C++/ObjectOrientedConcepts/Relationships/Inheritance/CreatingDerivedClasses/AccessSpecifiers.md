## Inheritance Access Specifiers

The general member access rules for inheritance are:
  A public class member can be accessed anywhere
  A protected class member can only be accessed by member functions and friends of that class, and by member functions and friends of derived classes
  A private class member can only be accessed by member functions and friends of that class, and are never accessible directly from a derived class

A derived class inherits all base class attributes.

A derived class inherits all base class methods with the following exceptions
  Constructors, destructors and copy constructors of the base class.
  Overloaded operators of the base class.
  The friend functions of the base class.



### Type of Inheritance

When deriving a class from a base class, the type of inheritance is specified by an access-specifier

C++ has three inheritance access specifiers / modifiers:
  public
  protected
  private

These are the same keywords as C++ class access specifiers, likewise, if you do not specify an inheritance type, C++ defaults to:
  private for classes
  public for structs

While using different type of inheritance, the following rules are applied.

Public Inheritance
When deriving a class from a public base class:
  base class public members become public members of the derived class
  base class protected members become protected members of the derived class.
  base class private members become private members of the derived class.

Protected Inheritance
When deriving from a protected base class:
  base class public and protected members become protected members of the derived class.
  base class private members become private members of the derived class.

Private Inheritance
When deriving from a private base class:
  base class public and protected members of the base class become private members of the derived class.
  base class private members become private members of the derived class.


Three class member access specifiers, and three inheritance access specifiers gives us nine total access specifier combinations between a given derived class and it's base class.

We can summarize the different access types according to where they can be accessed from using the following table:

| Access | public | protected | private |
|--------|--------|-----------|---------|
| Same class | yes | yes | yes |
| Derived classes | yes | yes | no |
| Outside classes |	yes | no | no |

For information on class member access modifiers see:
[C++\Syntax\Statements\Declarations\UserDefinedTypes\Classes\AccessControls.md]




### Changing an inherited member’s access level

C++ gives us the ability to change an inherited member’s access specifier in the derived class. This is done with a using declaration to identify the base class member that is having its access changed in the derived class, under the new access specifier:

  using base-class::member-name;

where
base-class is the name of a class from which derived class is derived.
member-name is the name of a member which the derived class has access to.
  as the using declaration is not a function call, no parenthesis follow the member name.

A derived class that implements the using declaration in this way can only change the access specifiers of base members the derived class would normally be able to access. A derived class can never change the access specifier of a base member from private to protected or public, because derived classes do not have access to private members of the base class.


For example, consider the following Base:

  #include <iostream>

  class Base
  {
  private:
      int m_value;

  public:
      Base(int value) : m_value(value) {}

  protected:
      void printValue() { std::cout << m_value; }
  };

Because Base::printValue() has been declared as protected, it can only be called by Base or its derived classes. The public can not access it.

Let’s define a Derived class that changes the access specifier of printValue() to public:

  class Derived: public Base
  {
  public:
      Derived(int value) : Base(value) {}

      // Base::printValue was inherited as protected, the public has no access
      // we change it to public via a using declaration
      using Base::printValue; // note: no parenthesis here
  };

This means that this code will now work:

  int main()
  {
      Derived derived(7);

      // printValue is public in Derived, so this is okay
      derived.printValue(); // prints 7
      return 0;
  }



Another example using the Car concept from above:

  class Motor
  {
    public:
  	void start() { cout << "started\n"; }
  };

  class Car : private Motor
  {
    public:
  	void key() { start(); }
  	using Motor::start;
  };

  class RaceCar : public Car
  {
  	public:
  		void ignition() { start(); }
  };

  int main()
  {
  	Car c;
  	c.key();
  	RaceCar r;
  	r.ignition();
  }



### Hiding functionality

In C++, it is not possible to remove or restrict functionality from a base class other than by modifying the source code. However, in a derived class, it is possible to hide functionality that exists in the base class, so that it can not be accessed through the derived class. This can be done simply by changing the relevant access specifier.

For example, we can make a public member private:

  #include <iostream>
  class Base
  {
  public:
  	int m_value;
  };

  class Derived : public Base
  {
  private:
  	using Base::m_value;

  public:
  	Derived(int value)
  	// We can't initialize m_value, since it's a Base member (Base must initialize it)
  	{
  		// But we can assign it a value
  		m_value = value;
  	}
  };

  int main()
  {
  	Derived derived(7);

  	// The following won't work because m_value has been redefined as private
  	std::cout << derived.m_value;

  	return 0;
  }

This allowed us to take a poorly designed base class and encapsulate its data in our derived class. Alternatively, instead of inheriting Base’s members publicly and making m_value private by overriding its access specifier, we could have inherited Base privately, which would have caused all of Base’s member to be inherited privately in the first place.

You can also mark member functions as deleted in the derived class, which ensures they can’t be called at all through a derived object:

  #include <iostream>
  class Base
  {
  private:
  	int m_value;

  public:
  	Base(int value)
  		: m_value(value)
  	{
  	}

  	int getValue() { return m_value; }
  };

  class Derived : public Base
  {
  public:
  	Derived(int value)
  		: Base(value)
  	{
  	}


  	int getValue() = delete; // mark this function as inaccessible
  };

  int main()
  {
  	Derived derived(7);

  	// The following won't work because getValue() has been deleted!
  	std::cout << derived.getValue();

  	return 0;
  }

In the above example, we’ve marked the getValue() function as deleted. This means that the compiler will complain when we try to call the derived version of the function. Note that the Base version of getValue() is still accessible though. This means that a Derived object can still access getValue() by upcasting the Derived object to a Base first:

int main()
{
	Derived derived(7);

	// We can still access the function deleted in the Derived class through the Base class
	std::cout << static_cast<Base>(derived).getValue();

	return 0;
}

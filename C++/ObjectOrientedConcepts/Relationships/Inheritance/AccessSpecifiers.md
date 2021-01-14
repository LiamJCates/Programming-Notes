Access Specifiers

C++ has three forms of inheritance access specifiers
  public
  protected
  private

If you do not choose an inheritance type, C++ defaults to private inheritance (just like members default to private access if you do not specify otherwise).

That gives us 9 combinations: 3 member access specifiers (public, private, and protected), and 3 inheritance types (public, private, and protected).

In general, the access-specifier relationships are
  public specifies a “derived class is a base class”
  private or protected specifies a “derived class has a base class”


The is-a relationship between a derived class and its base is applicable only to public inheritance, this is the most frequent form of inheritance.



Type of Inheritance

When deriving a class from a base class, the base class may be inherited through public, protected or private inheritance. The type of inheritance is specified by the access-specifier

While using different type of inheritance, following rules are applied:

    Public Inheritance − When deriving a class from a public base class, public members of the base class become public members of the derived class and protected members of the base class become protected members of the derived class. A base class's private members are never accessible directly from a derived class, but can be accessed through calls to the public and protected members of the base class.

    Protected Inheritance − When deriving from a protected base class, public and protected members of the base class become protected members of the derived class.

    Private Inheritance − When deriving from a private base class, public and protected members of the base class become private members of the derived class.


We can summarize the different access types according to - who can access them in the following way −

Access 	          public   protected   private
Same class 	      yes 	   yes         yes
Derived classes 	yes      yes         no
Outside classes 	Yes      no          no




A derived class inherits all base class methods with the following exceptions −

    Constructors, destructors and copy constructors of the base class.
    Overloaded operators of the base class.
    The friend functions of the base class.



For information on class member access modifiers see:
[C++\Syntax\Statements\Declarations\UserDefinedTypes\Classes\AccessControls.md]




Changing an inherited member’s access level

C++ gives us the ability to change an inherited member’s access specifier in the derived class. This is done by using a using declaration to identify the (scoped) base class member that is having its access changed in the derived class, under the new access specifier.

For example, consider the following Base:

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

  protected:
      void printValue() { std::cout << m_value; }
  };

Because Base::printValue() has been declared as protected, it can only be called by Base or its derived classes. The public can not access it.

Let’s define a Derived class that changes the access specifier of printValue() to public:

  class Derived: public Base
  {
  public:
      Derived(int value)
          : Base(value)
      {
      }

      // Base::printValue was inherited as protected, so the public has no access
      // But we're changing it to public via a using declaration
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

Two notes:

First, you can only change the access specifiers of base members the derived class would normally be able to access. Therefore, you can never change the access specifier of a base member from private to protected or public, because derived classes do not have access to private members of the base class.





Hiding functionality

In C++, it is not possible to remove or restrict functionality from a base class other than by modifying the source code. However, in a derived class, it is possible to hide functionality that exists in the base class, so that it can not be accessed through the derived class. This can be done simply by changing the relevant access specifier.

For example, we can make a public member private:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30

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

Note that this allowed us to take a poorly designed base class and encapsulate its data in our derived class. Alternatively, instead of inheriting Base’s members publicly and making m_value private by overriding its access specifier, we could have inherited Base privately, which would have caused all of Base’s member to be inherited privately in the first place.

You can also mark member functions as deleted in the derived class, which ensures they can’t be called at all through a derived object:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36

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

1
2
3
4
5
6
7
8
9

int main()
{
	Derived derived(7);

	// We can still access the function deleted in the Derived class through the Base class
	std::cout << static_cast<Base>(derived).getValue();

	return 0;
}





































Private Inheritance
Private inheritance differs from public inheritance (which is what you have seen up to
now) in that the keyword private is used in the line where the derived class declares its
inheritance from a base class:
class Base
{
// ... base class members and methods
};
class Derived: private Base // private inheritance
{
// ... derived class members and methods
};
Private inheritance of the base class means that all public members and attributes of the
base class are private (that is, inaccessible) to anyone with an instance of the derived
class. In other words, even public members and methods of class Base can only be
consumed by class Derived, but not by anyone else in possession of an instance of
Derived.


Thus, for the world outside the inheritance hierarchy, private inheritance essentially
does not imply an "is-a" relationship (imagine a tuna that can’t swim!). As private inheritance allows base class attributes and methods to be consumed only by the subclass that
derives from it, this relationship is also called a “has-a” relationship.


If another class RaceCar had to inherit from Car, then irrespective of the nature of inheritance between RaceCar and
Car, RaceCar would not have access to any public member or
function of base class Motor. This is because the relationship
between Car and Motor is one of private inheritance, meaning
that all entities other than Car have private access (that is,
no access) to public and protected members of Base when
using an instance of Car.
In other words, the most restrictive access specifier takes dominance in the compiler’s calculation of whether one class should
have access to a base class’s public or protected members.


Protected Inheritance
Protected inheritance differs from public inheritance in that the keyword protected is
used in the line where the derived class declares its inheritance from a base class:
class Base
{
// ... base class members and methods
};
class Derived: protected Base // protected inheritance
{
// ... derived class members and methods
};Protected inheritance is similar to private inheritance in the following ways:
■ It also signifies a has-a relationship.
■ It also lets the derived class access all public and protected members of Base.
■ Those outside the inheritance hierarchy with an instance of Derived cannot access
public members of Base.
Yet, protected inheritance is a bit different when it comes to the derived class being
inherited from:
class Derived2: protected Derived
{
// can access public & protected members of Base
};
Protected inheritance hierarchy allows the subclass of the subclass (that is, Derived2)
access to public and protected members of the Base. This
would not be possible if the inheritance between Derived and Base were private.

Use private or protected inheritance only when you have to.
In most cases where private inheritance is used, such as that of
the Car and the Motor, the base class could have as well been
a member attribute of the class Car instead of being a superclass. By inheriting from class Motor, you have essentially
restricted your Car to having only one motor, for no significant
gain over having an instance of class Motor as a private
member.
Cars have evolved, and hybrid cars, for instance, have a gas
motor in addition to an electric one. Our inheritance hierarchy for
class Car would prove to be a bottleneck in being compatible
to such developments.

Having an instance of Motor as a private member instead of
inheriting from it is called composition or aggregation. Such a
class Car looks like this:
class Car
{
private:
Motor heartOfCar;
public:
void Move()
{
heartOfCar.SwitchIgnition();
heartOfCar.PumpFuel();
heartOfCar.FireCylinders();
}
};
This can be good design as it enables you to easily add more
motors as member attributes to an existing Car class without
changing its inheritance hierarchy or its design with respect to its
clients.

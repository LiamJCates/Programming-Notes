Inheritance allows us to define a class in terms of another class

For general information about inheritance see:
[System Design\ObjectOrientedDesign\ObjectOrientedConcepts\Abstraction\Inheritance.md]

To define a derived class in C++ we use:

  class derived-class : access-specifier base-class

where derived-class, the name of the derived class is followed by a colon, :, and a base class relationship. The base class relationship is specified by an access-specifier and base-class the name of a previously defined class.


Example

class Base
{
  // ... base class members
};

class Derived: access-specifier Base
{
  // ... derived class members
};








Access Specifiers
C++ has three forms of inheritance access specifiers
  public
  protected
  private

If the access-specifier is not used, then it is private by default.

In general, the access-specifier relationships are
  public specifies a “derived class is a base class”
  private or protected specifies a “derived class has a base class”


The is-a relationship between a derived class and its base is applicable only to public inheritance, this is the most frequent form of inheritance.



Type of Inheritance

When deriving a class from a base class, the base class may be inherited through public, protected or private inheritance. The type of inheritance is specified by the access-specifier as explained above.

We hardly use protected or private inheritance, but public inheritance is commonly used. While using different type of inheritance, following rules are applied −

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



Derived Class Instantiation

When a derived object is instantiated:
  Memory for derived is set aside (enough for both the Base and Derived portions)
  The appropriate Derived constructor is called
  The Base object is constructed first using the appropriate Base constructor. If no base constructor is specified, the default constructor will be used.
  The initialization list initializes variables
  The body of the constructor executes
  Control is returned to the caller

The only real difference between this case and the non-inherited case is that before the Derived constructor can do anything substantial, the Base constructor is called first. The Base constructor sets up the Base portion of the object, control is returned to the Derived constructor, and the Derived constructor is allowed to finish up its job.

#include <iostream>
class Foo {
 public:
 Foo() { std::cout << "Foo's constructor" << std::endl; }
};

class Bar : public Foo {
 public:
 Bar() { std::cout << "Bar's constructor" << std::endl; }
};

int main() {
 Bar bar;
}
The object bar is constructed in two stages: first, the Foo constructor is invoked and then the Bar constructor is invoked. The output of the above program will be to indicate that Foo's constructor is called first, followed by Bar's constructor.

Why do this? There are a few reasons. First, each class should need to initialize things that belong to it, not things that belong to other classes. So a child class should hand off the work of constructing the portion of it that belongs to the parent class. Second, the child class may depend on these fields when initializing its own fields; therefore, the constructor needs to be called before the child class's constructor runs. In addition, all of the objects that belong to the class should be initialized so that the constructor can use them if it needs to.




Base Class Initialization — Passing Parameters to the Base Class

If a base class contains an overloaded constructor that requires arguments at the time of instantiation the base class is instantiated using an initialization list to invoke the appropriate base class constructor:

class Base
{
public:
  Base(int someNumber) // overloaded constructor
  {
    // Use someNumber
  }
};

Class Derived: public Base
{
public:
  Derived(): Base(25) // instantiate Base with argument 25
  {
    // derived class constructor code
  }
};









Derived Class Overriding Base Class’s Methods
If a class Derived implements the same functions with the same return values and signatures as in a class Base it inherits from, it effectively overrides that method in class Base as shown in the following code:

class Base
{
public:
  void DoSomething()
  {
    // implementation code… Does something
  }
};

class Derived:public Base
{
public:
  void DoSomething()
  {
  // implementation code… Does something else
  }
};

Thus, if method DoSomething() were to be invoked using an instance of Derived, then it would not invoke the functionality in class Base



Invoking Overridden Methods of a Base Class
The only way to invoke a base class method from the derived class is by the scope resolution operator (::).

Invoking an overloaded function from a derived class will

  Tuna myDinner;
  myDinner.Swim(); // will invoke Tuna::Swim()

To invoke Fish::Swim() the scope resolution operator (::) syntax:

  myDinner.Fish::Swim(); // invokes Fish::Swim() using instance of Tuna



Invoking Methods of a Base Class in a Derived Class

Typically, Fish::Swim() would contain a generic implementation of swimming applicable to all fish. If your specialized implementations in Tuna::Swim() and Carp::Swim() need to reuse the base class’s generic implementation of Fish::Swim(), use the scope resolution operator (::):

class Carp: public Fish
{
public:
  Carp(): Fish(true) {}
  void Swim()
  {
    cout << "Carp swims real slow" << endl;
    Fish::Swim(); // invoke base class function using operator::
  }
};


Derived Class Hiding Base Class’s Methods

Overriding can take an extreme form where Tuna::Swim() can potentially hide all overloaded versions of Fish::Swim() available, even causing compilation failure when the overloaded ones are used (hence, called hidden)

This version of class Fish is a bit different from those that you have seen so far. Apart from being a minimalized version to explain the problem at hand, this version of Fish contains two overloaded methods for Swim(), one that takes no parameters and another that takes a bool parameter.

As Tuna inherits public from Fish one would not be wrong to expect that
both versions of method Fish::Swim() would be available via an instance of class Tuna. The fact is, however, that Tuna implementing its own Tuna::Swim(), as shown
in Lines 23–26, results in the hiding of Fish::Swim(bool) from the compiler. If you
uncomment Line 35, you see a compilation failure.
So, if you want to invoke the Fish::Swim(bool) function via an instance of Tuna, you
have the following solutions:
■ Solution 1: Use the scope resolution operator in main():
myDinner.Fish::Swim();
■ Solution 2: Use keyword using in class Tuna to unhide Swim() in class
Fish:
class Tuna: public Fish
{
public:
using Fish::Swim; // unhide all Swim() methods in class Fish
void Swim()
{
cout << "Tuna swims real fast" << endl;
}
};■ Solution 3: Override all overloaded variants of Swim() in class Tuna (invoke
methods of Fish::Swim(...) via Tuna::Fish(...) if you want):
class Tuna: public Fish
{
public:
void Swim(bool isFreshWaterFish)
{
Fish::Swim(isFreshWaterFish);
}
void Swim()
{
cout << "Tuna swims real fast" << endl;
}
};







In general, while writing the definitions of the member functions of a derived class
to specify a call to a public member function of the base class, we do the following:
? If the derived class overrides a public member function of the
base class, then to specify a call to that public member function of
the base class, you use the name of the base class, followed by the
scope resolution operator, ::, followed by the function name with
the appropriate parameter list. For example, to call the function area of
the class rectangleType the statement is: rectangleType::area().
? If the derived class does not override a public member function of
the base class, you may specify a call to that public member function
by using the name of the function and the appropriate parameter list.
(See the following note for member functions of the base class that are
overloaded in the derived class.)

If a derived class overloads a public member function of the base class, then while writing the definition of a member function of the derived class, to specify a call to that (overloaded) member function of the base class (depending on the compiler), you might need to
use the name of the base class, followed by the scope resolution operator, ::, followed
by the function name with the appropriate parameter list.











Order of Construction
So, when you create an object of class Tuna that derives from class Fish, was the
constructor of Tuna invoked before or after the constructor of class Fish? Additionally,
within the instantiation of objects in the class hierarchy, what respective order do member attributes such as Fish::isFreshWaterFish have? Thankfully, the instantiation
sequence is standardized. Base class objects are instantiated before the derived class.
So, the Fish part of Tuna is constructed first, so that member attributes—especially the
protected and public ones contained in class Fish—are ready for consumption when
class Tuna is instantiated. Within the instantiation of class Fish and class Tuna,
the member attributes (such as Fish::isFreshWaterFish) are instantiated before the
constructor Fish::Fish() is invoked, ensuring that member attributes are ready before
the constructor works with them.


Order of Destruction
When an instance of Tuna goes out of scope, the sequence of destruction is the opposite
to that of construction.




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


The Problem of Slicing
What happens when a programmer does the following?
Derived objDerived;
Base objectBase = objDerived;
Or, alternatively, what if a programmer does this?
void UseBase(Base input);
...
Derived objDerived;
UseBase(objDerived); // copy of objDerived will be sliced and sent
In both cases, an object of type Derived is being copied into another of type Base,
either explicitly via assignment or by passing as an argument. What happens in these
cases is that the compiler copies only the Base part of objDerived—that is, not the
complete object. The information contained by the data members belonging to Derived
is lost in the process. This is not anticipated, and this unwanted reduction of that part of
data that makes the Derived a specialization of Base is called slicing.

To avoid slicing problems, don’t pass parameters by value. Pass
them as pointers to the base class or as a (optionally const)
reference to the same







Multiple Inheritance

C++ allows a class to derive from two or more base classes:
class Derived: access-specifier Base1, access-specifier Base2
{
// class members
};

Where access is one of public, protected, or private and would be given for every base class and they will be separated by comma as shown above. Let us try the following example −
Live Demo

#include <iostream>

using namespace std;

// Base class Shape
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }

   protected:
      int width;
      int height;
};

// Base class PaintCost
class PaintCost {
   public:
      int getCost(int area) {
         return area * 70;
      }
};

// Derived class
class Rectangle: public Shape, public PaintCost {
   public:
      int getArea() {
         return (width * height);
      }
};

int main(void) {
   Rectangle Rect;
   int area;

   Rect.setWidth(5);
   Rect.setHeight(7);

   area = Rect.getArea();

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;

   return 0;
}






Avoiding Inheritance Using final
Starting with C++11, compilers support specifier final. A class declared as final cannot be used as a base class.

For instance, class Platypus represents a well-evolved species. You may therefore want to ensure that this class is final, thereby blocking every possibility to inherit from it.

A version of class Platypus, declared as final would look like this:

class Platypus final: public Mammal, public Bird, public Reptile
{
public:
  void Swim()
  {
    cout << "Platypus: Voila, I can swim!" << endl;
  }
};


Similarly, a virtual function declared as final cannot be overridden in a derived class.

Thus, a version of class Tuna that doesn’t allow any further specialization of virtual function Swim() would look like this:

class Tuna : public Fish
{
public:
  // override Fish::Swim and make this final
  void Swim() override final
  {
  cout << "Tuna swims!" << endl;
  }
};

This version of Tuna can be inherited from, but Swim() cannot be overridden:

class BluefinTuna final:public Tuna
{
public:
void Swim() // Error: Swim() was final in Tuna, cannot override
{
}
};
















DO DON’T
DO create a public inheritance
hierarchy to establish an is-a
relationship.
DO create a private or protected
inheritance hierarchy to establish a
has-a relationship.
DO remember that public inheritance
means that classes deriving from
the derived class have access to the
public and protected members
of the base class. An object of the
derived class can be used to access
public members of the base.
DO remember that private inheritance means that even classes deriving from the derived class have no
access to any member of the base
class.
DO remember that protected inheritance means that classes deriving
from the derived class have access
to the public and protected methods of the base class. Yet, an object
of the derived class cannot be used
to access public members of the
base.
DO remember that irrespective of the
nature of inheritance relationship,
private members in the base class
cannot be accessed by any derived
class.
DON’T create an inheritance hierarchy just to reuse a trivial function.
DON’T use private or public inheritance indiscriminately as they can
end up being architectural bottlenecks towards the future scalability
of your application.
DON’T program derived class functions that hide those in the base
class by having the same name but a
different set of input parameters.



























## virtual inheritance

class BaseClass {
public:
BaseClass() { }
void f(char *s = "unknown") {
cout << "Function f() in BaseClass called from " << s << endl;
h();
}
protected:
void g(char *s = "unknown") {
cout << "Function g() in BaseClass called from " << s << endl;
}
private:
void h() {
cout << "Function h() in BaseClass\n";
}
};
class Derived1Level1 : public virtual BaseClass {
public:
void f(char *s = "unknown") {
cout << "Function f() in Derived1Level1 called from " << s << endl;
g("Derived1Level1");
h("Derived1Level1");
}
void h(char *s = "unknown") {
cout << "Function h() in Derived1Level1 called from " << s << endl;
}
};
class Derived2Level1 : public virtual BaseClass {
public:
void f(char *s = "unknown") {
cout << "Function f() in Derived2Level1 called from " << s << endl;
g("Derived2Level1");
// h(); // error: BaseClass::h() is not accessible
}
};
class DerivedLevel2 : public Derived1Level1, public Derived2Level1 {
public:
void f(char *s = "unknown") {
cout << "Function f() in DerivedLevel2 called from " << s << endl;
g("DerivedLevel2");
Derived1Level1::h("DerivedLevel2");
BaseClass::f("DerivedLevel2");
}
};

A sample program is
int main() {
BaseClass bc;
Derived1Level1 d1l1;
Derived2Level1 d2l1;
DerivedLevel2 dl2;
bc.f("main(1)");
// bc.g(); // error: BaseClass::g() is not accessible
// bc.h(); // error: BaseClass::h() is not accessible
d1l1.f("main(2)");
// d1l1.g(); // error: BaseClass::g() is not accessible
d1l1.h("main(3)");
d2l1.f("main(4)");
// d2l1.g(); // error: BaseClass::g() is not accessible
// d2l1.h(); // error: BaseClass::h() is not accessible
dl2.f("main(5)");
// dl2.g(); // error: BaseClass::g() is not accessible
dl2.h();
return 0;
}

This sample produces the following output:
Function f() in BaseClass called from main(1)
Function h() in BaseClass
Function f() in Derived1Level1 called from main(2)
Function g() in BaseClass called from Derived1Level1
Function h() in Derived1Level1 called from Derived1Level1
Function h() in Derived1Level1 called from main(3)
Function f() in Derived2Level1 called from main(4)
Function g() in BaseClass called from Derived2Level1
Function f() in DerivedLevel2 called from main(5)
Function g() in BaseClass called from DerivedLevel2
Function h() in Derived1Level1 called from DerivedLevel2
Function f() in BaseClass called from DerivedLevel2
Function h() in BaseClass
Function h() in Derived1Level1 called from unknown


The class BaseClass is called a base class or a superclass, and other classes are called subclasses or derived classes because they are derived from the superclass in that they can
use the data members and member functions specified in BaseClass as protected or
public. They inherit all these members from their base class so that they do not have
to repeat the same definitions. However, a derived class can override the definition of a

member function by introducing its own definition. In this way, both the base class and
the derived class have some measure of control over their member functions.
The base class can decide which member functions and data members can be revealed to derived classes so that the principle of information hiding holds not only with
respect to the user of the base class, but also to the derived classes. Moreover, the derived
class can decide which parts of the public and protected member functions and data
members to retain and use and which to modify. For example, both Derived1Level1
and Derived2Level1 define their own versions of f(). However, the access to the
member function with the same name in any of the classes higher up in the hierarchy is
still possible by preceding the function with the name of the class and the scope operator, as shown in the call of BaseClass::f() from f() in DerivedLevel2.
A derived class can add some new members of its own. Such a class can become
a base class for other classes that can be derived from it so that the inheritance hierarchy can be deliberately extended. For example, the class Derived1Level1 is derived
from BaseClass, but at the same time, it is the base class for DerivedLevel2.
Inheritance in our examples is specified as public by using the word public
after the semicolon in the heading of the definition of a derived class. Public inheritance means that public members of the base class are also public in the derived class,
and protected members are also protected. In the case of protected inheritance (with
the word protected in the heading of the definition), both public and protected
members of the base class become protected in the derived class. Finally, for private
inheritance, both public and protected members of the base class become private in
the derived class. In all types of inheritance, private members of the base class are
inaccessible to any of the derived classes. For example, an attempt to call h() from
f() in Derived2Level1 causes a compilation error, “BaseClass::h() is not accessible.” However, a call of h() from f() in Derived1Level1 causes no problem
because it is a call to h() defined in Derived1Level1.
Protected members of the base class are accessible only to derived classes
and not to nonderived classes. For this reason, both Derived1Level1 and
Derived2Level1 can call BaseClass's protected member function g(), but a call
to this function from main() is rendered illegal.
A derived class does not have to be limited to one base class only. It can be
derived from more than one base class. For example, DerivedLevel2 is defined
as a class derived from both Derived1Level1 and Derived2Level1, inheriting
in this way all the member functions of Derived1Level1 and Derived2Level1.
However, DerivedLevel2 also inherits the same member functions from BaseClass twice because both classes used in the definition of DerivedLevel2
are derived from BaseClass. This is redundant at best, and at worst can
cause a compilation error, "member is ambiguous BaseClass::g() and
BaseClass::g()." To prevent this from happening, the definitions of the
two classes include the modifier virtual, which means that DerivedLevel2
contains only one copy of each member function from BaseClass. A similar problem arises if f() in DerivedLevel2 calls h() without the preceding
scope operator and class name, Derived1Level1::h(). It does not matter
that h() is private in BaseClass and inaccessible to DerivedLevel2. An
error would be printed, "member is ambiguous Derived1Level1::h() and
BaseClass::h()."

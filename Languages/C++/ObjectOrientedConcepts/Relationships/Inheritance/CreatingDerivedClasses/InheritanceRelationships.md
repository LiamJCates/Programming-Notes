Human beings abstract things on two dimensions; part-of and kind-of:
	A Car is-a-kind-of-a Vehicle
	A Car has-a(n) Motor

The part-of hierarchy has been an element of software design since the ADT style became relevant; inheritance adds “the other” major dimension of decomposition.

In general, the inheritance access-specifier relationships are
  public inheritance by which a derived class "is a" base class
  private or protected inheritance by which a derived class "has a" base class

For specific information about inheritance access specifiers, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\AccessSpecifiers.md]



### Public Inheritance Relationships

    class Car : public Vehicle {
      // ...
    };

We state the above relationship in several ways:

  Car is “a kind of a” Vehicle
  Car is “derived from” Vehicle
  Car is “a specialized” Vehicle
  Car is a “subclass” of Vehicle
	Car is a “derived class” of Vehicle
	Car is a "subtype" of Vehicle

  Vehicle is the “base class” of Car
  Vehicle is the “superclass” of Car (this not as common in the C++ community)

Only by public inheritance do the public members of the base class remain accessible outside the inheritance hierarchy.



### Private and Protected Inheritance Relationships

    class Car : private Motor {
      // ...
    };

		class Car : protected Motor {
      // ...
    };

We state the above relationships in several ways:

	Car has “a kind of” Motor
	Car is “derived from” an Motor
	Car is a “subclass” of Motor
	Car is a “derived class” of Motor
	Car is not a "subtype" of Motor

	Motor is the “base class” of Car
	Motor is the “superclass” of Car


Private inheritance of the base class means that all public and protected members and attributes of the base class are now specified as private, that is, inaccessible to anyone with an instance of the derived class. In other words, even public members and methods of class Motor can only be consumed by class Car, but not by anyone else in possession of an instance of Car.

	class Car : private Motor
	{
	  //...
	}

In this case, if a class RaceCar inherited from Car it would not have access to any member or function of base class Motor, no matter the type of inheritance RaceCar used. This is because the relationship between Car and Motor is one of private inheritance. Ultimately this means that all entities other than Car have private access, that is, no access to public and protected members of Motor when using an instance of Car.

Protected inheritance of the base class means that all public members and attributes of the base class are now specified as protected, that is, inaccessible to anyone outside the base class inheritance hierarchy with an instance of the derived class.

	class Car : protected Motor
	{
	  //...
	}

In this case, if a class RaceCar inherited from Car it would have access to any member or function of base class Motor that used either the public or protected access specifier. This is because the relationship between Car and Motor is one of protected inheritance. Ultimately this means that all entities that are not a descendant of Car have private access, that is, no access to members of Motor when using an instance of Car.

NOTE

The most restrictive access specifier takes dominance in the compiler’s calculation of whether one class should have access to a base class’s public or protected members.

Thus, for the world outside the inheritance hierarchy, private and protected inheritance essentially does not imply an "is-a" relationship.

How is protected inheritance related to private inheritance?  

Similarities: both allow overriding virtual functions in the private/protected base class, neither claims the derived "is-a" kind 0f its base.

Dissimilarities: protected inheritance allows derived classes of derived classes to know about the inheritance relationship and are effectively exposed to your implementation details. This has both benefits (it allows derived classes of the protected derived class to exploit the relationship to the protected base class) and costs (the protected derived class can’t change the relationship without potentially breaking further derived classes).



How are “private inheritance” and “composition” similar?  

private inheritance is a syntactic variant of composition (AKA aggregation and/or has-a).

E.g., the “Car has-a Motor” relationship can be expressed using simple composition:

    class Motor {
    public:
      Motor(int numCylinders);
      void start();                 // Starts this Motor
    };
    class Car {
    public:
      Car() : e_(8) { }             // Initializes this Car with 8 cylinders
      void start() { e_.start(); }  // Start this Car by starting its Motor
    private:
      Motor e_;                    // Car has-a Motor
    };

The “Car has-a Motor” relationship can also be expressed using private inheritance:

    class Car : private Motor {    // Car has-a Motor
    public:
      Car() : Motor(8) { }         // Initializes this Car with 8 cylinders
      using Motor::start;          // Start this Car by starting its Motor
    };

There are several similarities between these two variants:

    In both cases there is exactly one Motor member object contained in every Car object
    In neither case can users (outsiders) convert a Car\* to an Motor\*
    In both cases the Car class has a start() method that calls the start() method on the contained Motor object.

There are also several distinctions:
  The simple-composition variant is needed if you want to contain several Motors per Car
  The private-inheritance variant can introduce unnecessary multiple inheritance
  The private-inheritance variant allows members of Car to convert a Car\* to a Motor\*
  The private-inheritance variant allows access to the protected members of the base class
  The private-inheritance variant allows Car to override Motor’s virtual functions
  The private-inheritance variant makes it slightly simpler (20 characters compared to 28 characters) to give Car a start() method that simply calls through to the Motor’s start() method

Note that private inheritance is usually used to gain access into the protected members of the base class, but this is usually a short-term solution (translation: a band-aid).



### Prefer Composition

Which should I prefer: composition or private inheritance?  

Use composition when you can, private inheritance when you have to.

Normally you don’t want to have access to the internals of too many other classes, and private inheritance gives you some of this extra power (and responsibility). But private inheritance isn’t evil; it’s just more expensive to maintain, since it increases the probability that someone will change something that will break your code.

In most cases, composition has advantage over private or protected inheritance.

For more information regarding composition in the context of C++, see:
[C++\ObjectOrientedConcepts\Relationships\Composition.md]

Use private or protected inheritance only when you have to.

In most cases where private inheritance is used, such as that of the Car and the Motor above, the base class, Motor, could have as well been a member attribute of the derived class, Car, instead of being a superclass.

By inheriting from class Motor, we have restricted our Car objects to having only one motor, for no significant gain over having an instance of class Motor as a private member.

As well, hybrid cars, for instance, have a gas motor in addition to an electric one. Our inheritance hierarchy for class Car would not be compatible.

Having an instance of Motor as a private member instead of inheriting from it is called composition or aggregation.

Such a class Car looks like this:

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

This can be good design as it enables you to easily add more motors as member attributes to an existing Car class without changing its inheritance hierarchy or its design with respect to its clients.



### Use Case

A legitimate, long-term use for private inheritance is when you want to build a class Fred that uses code in a class Wilma, and the code from class Wilma needs to invoke member functions from your new class, Fred. In this case, Fred calls non-virtuals in Wilma, and Wilma calls (usually pure virtuals) in itself, which are overridden by Fred. This would be much harder to do with composition.

  class Wilma {
  protected:
    void fredCallsWilma()
    {
      std::cout << "Wilma::fredCallsWilma()\n";
      wilmaCallsFred();
    }
    virtual void wilmaCallsFred() = 0;   // A pure virtual function
  };
  class Fred : private Wilma {
  public:
    void barney()
    {
      std::cout << "Fred::barney()\n";
      Wilma::fredCallsWilma();
    }
  protected:
    virtual void wilmaCallsFred()
    {
      std::cout << "Fred::wilmaCallsFred()\n";
    }
  };



### Real World Uses Case

Private and protected inheritance, despite the name, isn’t really inheritance – at least not from the outside (of the class), where it matters.

In C++, private inheritance is said to model an “is implemented in terms of” relationship.

Thus, a priority queue which is implemented in terms of a heap, could look like this:

	template <typename T, typename Comp = std::less<T> >
	class priority_queue : private heap<T, Comp> {
	    // …
	};

Since it’s such an established pattern, the meaning of a private inheritance is immediately clear to a seasoned C++ programmer; the above code would tell them that the priority queue is implemented in terms of a heap – which wouldn’t be obvious if the class just happened to use a heap as one of its members.

Private inheritance tends to get used in C++ primarily for policy classes. The classical example is allocators, which determine how a container class manages storage internally:

	template <typename T, typename A = std::allocator<T> >
	class vector : private A {
	    // …
	};

While this could also have been done using composition.

Private inheritance allows things which can't be done by composition:

  zero-size base class optimization (a base class of size zero will not increase the size of a class, a member of size zero will), that's the reason behind its use for policy classes which often have no data members

  controlling initialization order so that what is composed is initialized before a public base

  Overriding a virtual member in what is composed

  With private virtual inheritance, ensuring that there is only one composed thing even if one do it in several bases

Note that for the latter two uses, the fact that the base class exist can be observed in a descendant.




### Subtyping

A formal distinction between a protected or private inheritance relationship and a public inheritance relationship is called subtyping.

Subtyping enables a given type to be substituted for another type or abstraction, and is said to establish an is-a relationship between the subtype and some existing abstraction. In C++, subtyping can be expressed explicitly via public inheritance.

For example, the above example C++ code establishes an explicit inheritance relationship between classes Car and Vehicle, where Car is both a subclass and a subtype of Vehicle, and can be used as a Vehicle wherever a Car is specified (via a reference, a pointer, or the object itself).

class A {
 public:
  void DoSomethingALike() const {}
};

class B : public A {
 public:
  void DoSomethingBLike() const {}
};

void UseAVehicle(const Vehicle& v) {
  v.DoSomethingVehicleLike();
}

void SomeFunc() {
  Car c;
  UseAVehicle(c);  // Car c can be substituted for a Vehicle.
}

In programming languages that do not support inheritance as a subtyping mechanism, the relationship between a base class and a derived class is only a relationship between implementations (a mechanism for code reuse), as compared to a relationship between types.

Inheritance, even in programming languages like C++ that support inheritance as a subtyping mechanism, does not necessarily entail behavioral subtyping. It is entirely possible to derive a class whose object will behave incorrectly when used in a context where the parent class is expected; see the Liskov substitution principle.

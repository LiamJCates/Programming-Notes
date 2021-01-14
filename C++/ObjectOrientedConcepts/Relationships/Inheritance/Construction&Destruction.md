### Order of Construction

When we instantiate an instance of Derived, first the Base portion of Derived is constructed (using the Base default constructor). Once the Base portion is finished, the Derived portion is constructed (using the Derived default constructor). At this point, there are no more derived classes, so we are done.

  #include <iostream>

  class Base
  {
  public:
      int m_id;

      Base(int id=0) : m_id(id)
      {
          std::cout << "Base\n";
      }

      int getId() const { return m_id; }
  };

  class Derived: public Base
  {
  public:
      double m_cost;

      Derived(double cost = 0.0) : m_cost(cost)
      {
          std::cout << "Derived\n";
      }

      double getCost() const { return m_cost; }
  };

  int main()
  {
      std::cout << "Instantiating Base\n";
      Base cBase;

      std::cout << "Instantiating Derived\n";
      Derived cDerived;

      return 0;
  }

Output:

  Instantiating Base
  Base
  Instantiating Derived
  Base
  Derived

When we constructed Derived, the Base portion of Derived got constructed first. This makes sense: logically, a child can not exist without a parent. It’s also the safe way to do things: the child class often uses variables and functions from the parent, but the parent class knows nothing about the child.

Instantiating the parent class first ensures those variables are already initialized by the time the derived class is created and ready to use them.

It is sometimes the case that classes are derived from other classes, which are themselves derived from other classes. Remember that C++ always constructs the “first” or “most base” class first. It then walks through the inheritance tree in order and constructs each successive derived class along the inheritance chain.

C++ constructs derived classes in phases, starting with the most-base class (at the top of the inheritance tree) and finishing with the most-child class (at the bottom of the inheritance tree). As each class is constructed, the appropriate constructor from that class is called to initialize that part of the class.


With non-derived classes, constructors only have to worry about their own members. For example, consider Base. We can create a Base object like this:

  int main()
  {
      Base base{ 5 }; // use Base(int) constructor

      return 0;
  }

Here’s what actually happens when base is instantiated:

    Memory for base is set aside
    The appropriate Base constructor is called
    The initialization list initializes variables
    The body of the constructor executes
    Control is returned to the caller

This is pretty straightforward. With derived classes, things are slightly more complex:

  int main()
  {
      Derived derived{ 1.3 }; // use Derived(double) constructor

      return 0;
  }

Here’s what actually happens when derived is instantiated:

    Memory for derived is set aside (enough for both the Base and Derived portions)
    The appropriate Derived constructor is called
    The Base object is constructed first using the appropriate Base constructor. If no base constructor is specified, the default constructor will be used.
    The initialization list initializes variables
    The body of the constructor executes
    Control is returned to the caller

The only real difference between this case and the non-inherited case is that before the Derived constructor can do anything substantial, the Base constructor is called first. The Base constructor sets up the Base portion of the object, control is returned to the Derived constructor, and the Derived constructor is allowed to finish up its job.

Why do this? There are a few reasons. First, each class should need to initialize things that belong to it, not things that belong to other classes. So a child class should hand off the work of constructing the portion of it that belongs to the parent class. Second, the child class may depend on these fields when initializing its own fields; therefore, the constructor needs to be called before the child class's constructor runs. In addition, all of the objects that belong to the class should be initialized so that the constructor can use them if it needs to.


### Order of Destruction
When an instance of a derived class goes out of scope, the sequence of destruction is the opposite to that of construction, using the only class destructor.




### Passing Parameters to Base Class Constructors

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

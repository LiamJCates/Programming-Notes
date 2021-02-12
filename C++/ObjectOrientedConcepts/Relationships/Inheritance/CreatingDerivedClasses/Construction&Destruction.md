### Order of Construction

When instantiating instances of a derived class using the default constructor:
  1. the Base portion of Derived is constructed (using the Base default constructor).
  2. the Derived portions are constructed from highest to lowest in the inheritance hierarchy (using the Derived default constructor).


  #include <iostream>

  class Base
  {
  public:
      int m_id;

      Base(int id=0) : m_id(id)
      {
          std::cout << "Base Constructor\n";
      }

      int getId() const { return m_id; }
  };

  class Derived: public Base
  {
  public:
      double m_cost;

      Derived(double cost = 0.0) : m_cost(cost)
      {
          std::cout << "Derived Constructor\n";
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
  Base Constructor
  Instantiating Derived
  Base Constructor
  Derived Constructor

When we construct an instance of Derived, the Base portion of Derived got constructed first.

Instantiating a parent class first ensures those variables are already initialized by the time the derived class is created and ready to use them.

It is sometimes the case that classes are derived from other classes, which are themselves derived from other classes. Remember that C++ always constructs the “most base” class first. It then walks through the inheritance tree in order and constructs each successive derived class along the inheritance chain.

As each class is constructed, the appropriate constructor from that class is called to initialize that part of the class.

With non-derived classes, constructors only have to worry about their own members. For example, consider Base. We can create a Base object like this:

  int main()
  {
      Base base{ 5 }; // use Base(int) constructor
  }

Here are the steps to base class instantiation:
    Memory required for base is set aside
    The appropriate Base constructor is called
    The initialization list initializes variables
    The body of the constructor executes
    Control is returned to the caller

With derived classes, things are slightly more complex:

  int main()
  {
      Derived derived{ 1.3 }; // use Derived(double) constructor
  }

Here are the steps to derived class instantiation:
    Memory for all base classes is set aside
    Memory for the derived class is set aside
    The appropriate Derived constructor is called
    Base class object is constructed using a specified constructor, or the default constructor other.
    The initialization list initializes variables
    The body of the constructor executes
    Control is returned to the caller

The only real difference between this case and the non-inherited case is that before the Derived constructor can do anything substantial, the Base constructor is called first. The Base constructor sets up the Base portion of the object, control is returned to the Derived constructor, and the Derived constructor is allowed to finish up its job.

Why do this? There are a few reasons. First, each class needs to initialize things that belong to it. So the base classes handle the work of constructing the portion of it that belongs to the derived class. Second, the derived class may depend on these base class fields when initializing its own fields; therefore, the base constructor needs to be called before the derived class constructor runs.



### Order of Destruction
When an instance of a derived class goes out of scope, the sequence of destruction is the opposite to that of construction. As there is only one destructor for a given class each class calls it's singular constructor progressing from the derived class to the most base class.


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

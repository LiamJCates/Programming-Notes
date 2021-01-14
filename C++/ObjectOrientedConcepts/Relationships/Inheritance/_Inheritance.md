Inheritance allows us to define a class in terms of another class

For general information about inheritance see:
[System Design\ObjectOrientedDesign\ObjectOrientedConcepts\Abstraction\Inheritance.md]

To define a derived class in C++ we use:

  class derived-class : access-specifier base-class
  {
    //class members
  };

where the name of the derived class, derived-class, is followed by a colon, :, and a base class relationship.

The base class relationship is specified by an optional access-specifier and the name of a previously defined class, base-class.


Example

class Base
{
  // ... base class members
};

class Derived: access-specifier Base
{
  // ... derived class members
};



Topics
  Construction & Destruction
  Access Specifiers

  Method Override
  Virtual Methods
  Final
  Override

  Abstract Class
  Interface
  Virtual Inheritance

  Multiple Inheritance
  Slicing

  Polymorphism
  Binding
  Dynamic Dispatch

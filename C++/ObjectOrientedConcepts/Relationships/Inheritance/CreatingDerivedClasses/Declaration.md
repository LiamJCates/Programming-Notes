## Derived Object Declaration

To define a derived class in C++ we use:

  class derived-class : access-specifier base-class
  {
    //class members
  };

Where the name of the derived class, derived-class, is followed by a colon, :, and a base class inheritance type.

For specific information about the usage of derived objects, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\CreatingDerivedClasses\DerivedObjectUsage.md]



### Inheritance Types

The type of inheritance relationship is specified by an optional access-specifier and the name of a previously defined class, base-class.

For specific information about inheritance access specifiers, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\AccessSpecifiers.md]



### Single Inheritance

The most basic mode of inheritance is single inheritance which is specified syntactically as follows:

	class Base
	{
	  // ... base class members
	};

	class Derived : access-specifier Base
	{
	  // ... derived class members
	};

For information regarding various modes of inheritance, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Modes.md]

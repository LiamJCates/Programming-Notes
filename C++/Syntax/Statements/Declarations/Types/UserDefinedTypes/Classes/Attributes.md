Attributes
Attributes are a classes' data members.

Composition (Aggregation)
Composition (aggregation) is another way to relate two classes. In composition
(aggregation), one or more members of a class are objects of another class type.

Composition is a “has-a” relation; for example, “every person has a date of birth.”












### Non-static member initialization

When writing a class that has multiple constructors (which is most of them), having to specify default values for all members in each constructor results in redundant code. If you update the default value for a member, you need to touch each constructor.

It’s possible to give normal class member variables (those that don’t use the static keyword) a default initialization value directly:

  #include <iostream>

  class Rectangle
  {
  private:
      double m_length{ 1.0 }; // m_length has a default value of 1.0
      double m_width{ 1.0 }; // m_width has a default value of 1.0

  public:
      void print()
      {
          std::cout << "length: " << m_length << ", width: " << m_width << '\n';
      }
  };

  int main()
  {
      Rectangle x{}; // x.m_length = 1.0, x.m_width = 1.0
      x.print();

      return 0;
  }

Output:

  length: 1.0, width: 1.0

Non-static member initialization (also called in-class member initializers) provides default values for your member variables that your constructors will use if the constructors do not provide initialization values for the members themselves (via the member initialization list).

However, note that constructors still determine what kind of objects may be created. Consider the following case:

  #include <iostream>

  class Rectangle
  {
  private:
      double m_length{ 1.0 };
      double m_width{ 1.0 };

  public:

      // note: No default constructor provided in this example

      Rectangle(double length, double width)
          : m_length{ length },
            m_width{ width }
      {
          // m_length and m_width are initialized by the constructor (the default values aren't used)
      }

      void print()
      {
          std::cout << "length: " << m_length << ", width: " << m_width << '\n';
      }

  };

  int main()
  {
      Rectangle x{}; // will not compile, no default constructor exists, even though members have default initialization values

      return 0;
  }

Even though we’ve provided default values for all members, no default constructor has been provided, so we are unable to create Rectangle objects with no arguments.

If a default initialization value is provided and the constructor initializes the member via the member initializer list, the member initializer list will take precedence. The following example shows this:

  #include <iostream>

  class Rectangle
  {
  private:
      double m_length{ 1.0 };
      double m_width{ 1.0 };

  public:

      Rectangle(double length, double width)
          : m_length{ length },
            m_width{ width }
      {
          // m_length and m_width are initialized by the constructor (the default values aren't used)
      }

      Rectangle(double length)
          : m_length{ length }
      {
          // m_length is initialized by the constructor.
          // m_width's default value (1.0) is used.
      }

      void print()
      {
          std::cout << "length: " << m_length << ", width: " << m_width << '\n';
      }

  };

  int main()
  {
      Rectangle x{ 2.0, 3.0 };
      x.print();

      Rectangle y{ 4.0 };
      y.print();

      return 0;
  }

Output:

length: 2.0, width: 3.0
length: 4.0, width: 1.0

Note that initializing members using non-static member initialization requires using either an equals sign, or a brace (uniform) initializer -- the direct initialization form doesn’t work here.

Favor use of non-static member initialization to give default values for your member variables.


### Allocation Order of Non-Static Attributes

The order of allocation of nonstatic class members separated by an access_specifier is implementation-dependent. The compiler allocates class members in the order in which they are declared.

Suppose A is a name of a class. The following class members of A must have a name different from A:

    All data members
    All type members
    All enumerators of enumerated type members
    All members of all anonymous union members

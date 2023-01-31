How struct Differs from class

struct is a keyword from the days of C, and for all practical purposes it is treated by a C++ compiler similarly to a class.

The exceptions are applicable to their default access specification.

Members in a struct are public by default 
Members in a class are private by default,

A struct features public inheritance from a base struct by default
A class features private inheritance from a base class by default

  // Program 1
  #include <stdio.h>

  class Base {
      public:
          int x;
  };

  class Derived : Base { }; // Is equivalent to class Derived : private Base {}

  int main()
  {
      Derived d;
      d.x = 20; // Compiler error because inheritance is private
      getchar();
      return 0;
  }

  // Program 2
  #include <stdio.h>

  struct Base {
      public:
          int x;
  };

  struct Derived : Base { }; // Is equivalent to struct Derived : public Base {}

  int main()
  {
      Derived d;
      d.x = 20; // Works fine because inheritance is public
      getchar();
      return 0;
  }

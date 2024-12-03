An "abstract" class is a class that is designed to be specifically used as a base class. The purpose of an abstract class (often referred to as an ABC) is to provide an appropriate base class from which other classes can inherit.

An abstract class, generally, is one for which an implementation of all member functions cannot be provided in a base class but are required for derived classes.

An abstract class contains at least one pure virtual function which specifies a behavioral contract required to be fulfilled by derived concrete classes.

For information regarding the declaration of pure virtual functions, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\PureVirtualMethods.md]

A derived class that fulfills the contract specified by the pure virtual functions of an abstract class is called a "concrete" class.

Any concrete class (a class that can be instantiated) derived from an abstract class must declare and define a matching member function for each abstract member function of the base class.



### Designing Strategy

An object-oriented system might use an abstract base class to provide a common and standardized behavioral contract appropriate for all the external applications. Then, through inheritance from that abstract base class, derived classes are formed that operate similarly.

The capabilities (i.e., the public functions) offered by the external applications are provided as pure virtual functions in the abstract base class. The implementations of these pure virtual functions are provided in the derived classes that correspond to the specific types of the application.

This architecture also allows new applications to be added to a system easily, even after the system has been defined.



### Abstract Class Use

You cannot use an abstract class as a parameter type, a function return type, or the type of an explicit conversion, nor can you declare an object of an abstract class. You can, however, declare pointers and references to an abstract class.

The following example demonstrates this:

struct A {
  virtual void f() = 0;
};

struct B : A {
  virtual void f() { }
};

// Compile Error: return type A is an abstract class
// A g();

// Compile Error: parameter type A is an abstract class
// void h(A);

// Legal: parameter type and return type are pointer to abstract class
A& i(A&);

int main() {

// Compile Error: object type A is an abstract class
// A a;

// Legal: pointer to abstract class
 A* pa;

// Compile Error: explicit conversion to type A, an abstract class
// static_cast<A>(b);
}

Class A is an abstract class. The compiler would not allow the function declarations A g() or void h(A), declaration of object a, nor the static cast of b to type A.


### Concrete Class Use

A derived class that does not fulfill the contract defined by the abstract base class' pure virtual functions will also be abstract. A concrete class must override and provide an implementation for each pure virtual function in the abstract base class.

For example:

  class AB {
  public:
    virtual void f() = 0;
  };

  class D : public AB {
    void g();
  };

  int main() {
    D d;
  }

The compiler will not allow the declaration of object d because D is an abstract class; it inherited the pure virtual function f() from AB.

The compiler will allow the declaration of object d if D define function D::f(), as this overrides the inherited pure virtual function AB::f().

  class D : public AB {
    void f();
  };



### Advanced Abstraction

It is possible to:
Derive an abstract class from a non-abstract class by specifying a pure virtual function in the derived class.
Override a non-pure virtual function in an abstract base class with a pure virtual function in the derived class.


You can call member functions from a constructor or destructor of an abstract class. However, the results of calling (directly or indirectly) a pure virtual function from its constructor are undefined. The following example demonstrates this:

struct A {
  A() {
    direct();
    indirect();
  }
  virtual void direct() = 0;
  virtual void indirect() { direct(); }
};

The default constructor of A calls the pure virtual function direct() both directly and indirectly (through indirect()).



### Interfaces

A special kind of abstract class is called an "interface" class or "pure abstract" class. These titles indicate a class that exclusively has pure virtual functions (and no data). The concept of an interface class is mapped to pure abstract classes in C++, as there is no "interface" construct or keyword in C++ the same way that there are in some other Object Oriented Languages.

For more information regarding interfaces, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\Interface.md]

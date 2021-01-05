## Constructors
A constructor is a special method with a special declaration, invoked during the instantiation of a class to construct an object.

A constructor is a function and it has no type. That is, it is neither a value-returning function nor a void function. The name of a constructor is the same as the name of the class. A class can have more than one constructor. All constructors of a class have the same name but a different number or order of formal parameters, called constructor overloading.

Because they have no types, they cannot be called like other functions. Constructors execute automatically when a class object is declared and enters its scope. Which constructor executes depends on the types of values passed to the class object when the class object is declared.

It is the job of a constructor to establish the invariant for its class (so that the member functions can rely on it) and for the member functions to make sure that the invariant holds when they exit.

The notion of invariants is central to the design of classes, and preconditions serve a similar role in the design of functions.

Invariants
• help us to understand precisely what we want
• force us to be specific; that gives us a better chance of getting our code correct (after debugging and testing).

The notion of invariants underlies C++’s notions of resource management supported by constructors and destructors


### Constructor Types
There are three types of constructors in C++:
  Default Constructors
  Parameterized
  Copy Constructors

We discuss the first two here and the third is discussed:
[C++\Types&Values\Classes\Copy&Move\CopyConstructor.md]



### Declaring and Implementing a Constructor
Constructor declarations are like that of a normal member function, however, the its name of matches the class’s name, and constructors don't state a return type.

A constructor can be implemented either inline within the class or externally outside the class declaration.

An implementation (also called definition) inside the class looks like this:

class Human {
public:
  Human() { // constructor code here }
};

To define the constructor outside the class’ declaration we use the scope resolution operator:

class Human {
  public:
  Human(); // constructor declaration
};

// constructor implementation (definition)
Human::Human() {
  // constructor code here
}

:: is called the scope resolution operator.

For example, Human::dateOfBirth would refer to variable dateOfBirth declared within the scope of class Human.
::dateOfBirth, on the other hand would refer to another variable dateOfBirth in a global scope.



### Default Constructor
A constructor that is invoked without arguments is called the default constructor. Programming a default constructor is optional. If you don’t program any constructor the compiler creates one for you (that constructs member attributes but does not initialize Plain Old Data types such as int to any specific non-zero value).

You can choose to not implement the default constructor to enforce object instantiation with certain minimal parameters.

Constructors can be overloaded just like functions. You can implement as many constructors as you’d like, as long as their argument types differ.

### Invoking the Default Constructor
Suppose that a class contains the default constructor. The syntax to invoke the default constructor is:

  className classObjectName;

If a class has no constructor(s), C++ automatically provides the default
constructor. However, the object declared is still uninitialized.



### Invoking a Constructor with Parameters
A class may contain constructors with parameters, called parameterized constructors.

The syntax to invoke a constructor with a parameter is:
className classObjectName(argument1, argument2, ...);

in which argument1, argument2, and so on are either a variable or an expression.

The way of calling constructors by enclosing their arguments in parentheses, as shown above, is known as functional form. But constructors can also be called with other syntaxes:

First, constructors with a single parameter can be called using the variable initialization syntax (an equal sign followed by the argument):

class_name object_name = initialization_value;

More recently, C++ introduced the possibility of constructors to be called using uniform initialization, which essentially is the same as the functional form, but using braces ({}) instead of parentheses (()):

class_name object_name { value, value, value, ... }

Optionally, this last syntax can include an equal sign before the braces.

Here is an example with four ways to construct objects of a class whose constructor takes a single parameter:

  // classes and uniform initialization
  #include <iostream>
  using namespace std;

  class Circle {
      double radius;
    public:
      Circle(double r) { radius = r; }
      double circum() {return 2*radius*3.14159265;}
  };

  int main () {
    Circle foo (10.0);   // functional form
    Circle bar = 20.0;   // assignment init.
    Circle baz {30.0};   // uniform init.
    Circle qux = {40.0}; // POD-like

    cout << "foo's circumference: " << foo.circum() << '\n';
    return 0;
  }

Note the following:
The number of arguments and their type should match the formal parameters (in the order given) of one of the constructors.

If the type of the arguments does not match the formal parameters of any constructor (in the order given), C++ uses type conversion and looks for the best match. For example, an integer value might be converted to a floating-point value with a zero decimal part. Any ambiguity will result in a compile-time error.

Suppose a class, say, dummyClass, includes constructor(s) with parameter(s) and does not include the default constructor. In this case, C++ does not provide the default constructor for the class dummyClass. Therefore, when an object of the class dummyClass is declared, we must include the appropriate arguments in its declaration.


### Initialization Lists
When a constructor is used to initialize other members, these other members can be initialized directly, without resorting to statements in its body. This is done by inserting, before the constructor's body, a colon (:) and a list of initializations for class members, called an initialization list.

class Rectangle {
    int width,height;
  public:
    Rectangle(int,int);
    int area() {return width*height;}
};

The constructor for this class could be defined, as usual, as:

  Rectangle::Rectangle (int x, int y) { width=x; height=y; }

But it could also be defined using member initialization as:

  Rectangle::Rectangle (int x, int y) : width(x) { height=y; }

Or even:

  Rectangle::Rectangle (int x, int y) : width(x), height(y) { }

Note how in this last case, the constructor does nothing else than initialize its members, hence it has an empty function body.

For members of fundamental types, it makes no difference which of the ways above the constructor is defined, because they are not initialized by default, but for member objects (those whose type is a class), if they are not initialized after the colon, they are default-constructed.

Default-constructing all members of a class may or may always not be convenient: in some cases, this is a waste (when the member is then reinitialized otherwise in the constructor), but in some other cases, default-construction is not even possible (when the class does not have a default constructor). In these cases, members shall be initialized in the member initialization list.

// member initialization
#include <iostream>
using namespace std;

class Circle {
    double radius;
  public:
    Circle(double r) : radius(r) { }
    double area() {return radius\*radius*3.14159265;}
};

class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : base (r), height(h) {}
    double volume() {return base.area() * height;}
};

int main () {
  Cylinder foo (10,20);

  cout << "foo's volume: " << foo.volume() << '\n';
  return 0;
}

In this example, class Cylinder has a member object whose type is another class (base's type is Circle). Because objects of class Circle can only be constructed with a parameter, Cylinder's constructor needs to call base's constructor, and the only way to do this is in the member initializer list.

These initializations can also use uniform initializer syntax, using braces {} instead of parentheses ():

  Cylinder::Cylinder (double r, double h) : base{r}, height{h} { }



## Default Initialization
Constructor parameters can be given default values.

Note that a default constructor is one that can be instantiated without arguments, and not necessarily one that doesn’t take parameters. So a constructor with parameters that all have designated default values is a default constructor

When a data member of a class is defined, we can supply a default initializer called a default member initializer.

class complex {
  // representation: two doubles with default value 0.0
  double re = 0;
  double im = 0;
public:
  // construct complex from two scalars: {r,i}
  complex(double r, double i) :re{r}, im{i} {}

  // construct complex from one scalar: {r,0}
  complex(double r) :re{r} {}

  complex() {} // default complex: {0,0}
// ...
}

The default value is used whenever a constructor doesn’t provide a value. This simplifies code and helps us to avoid accidentally leaving a member uninitialized.

## Constructors

A constructor is a special method invoked during the instantiation of a class to construct an object.

A constructor is automatically called whenever a new object of some class is created, allowing the class to initialize member variables or allocate storage.



### Constructor's Role

It is the job of a constructor to establish the invariant for its class, to initialize each class instance so that the associated member functions can rely on it, and for the member functions to make sure that the invariant holds when they exit.

The notion of invariants is central to the design of classes, and preconditions serve a similar role in the design of functions.

Invariants
• help us to understand precisely what is required from the input
• force specificity that gives us a better chance of getting our code correct

The notion of invariants underlies C++’s notions of resource management supported by constructors and destructors



### Constructor Types

There are three types of constructors in C++:
  Default Constructors
  Parameterized
  Copy Constructors

We discuss the first two here and the third is discussed:
[C++\Types&Values\Classes\Copy&Move\CopyConstructor.md]



### Declaring and Implementing a Constructor

Constructor declarations are like that of a normal member function, however,   
  the name matches the class name
  constructors don't state a return type.

As a constructor function has no type, it is neither a value-returning function nor a void function.

Because they have no types, they cannot be called like other functions.
Constructors execute automatically when a class object is declared and enters its scope. Which constructor executes depends on the types of values passed to the class object when the class object is declared.

A class can have more than one constructor. All constructors of a class have the same name but a different number or order of formal parameters, called constructor overloading.

A constructor can be implemented either inline within the class or externally outside the class declaration.

A definition inside the class' declaration looks like this:

  class Human {
  public:
    Human() { // constructor code here }
  };

A definition outside the class’ declaration looks like this:

  class Human {
    public:
    Human(); // constructor declaration
  };

  // constructor implementation (definition)
  Human::Human() {
    // constructor code here
  }

An external declaration uses, ::, the scope resolution operator:

For example, Human::dateOfBirth would refer to variable dateOfBirth declared within the scope of class Human.

::dateOfBirth, on the other hand would refer to another variable dateOfBirth in a global scope.



### Default Constructor

A constructor that is invoked without arguments is called the default constructor. Programming a default constructor is optional. If you don’t program any constructor the compiler creates one for you (that constructs member attributes but does not initialize Plain Old Data types such as int to any specific non-zero value).

You can choose to not implement the default constructor to enforce object instantiation with certain minimal parameters.



### Invoking the Default Constructor

Suppose that a class contains the default constructor. The syntax to invoke the default constructor is:

  className classObjectName;

If a class has no constructor(s), C++ automatically provides the default
constructor. However, the object declared is still uninitialized.



### Invoking a Constructor with Parameters

A class may contain constructors with parameters, called parameterized constructors.

Constructors can be overloaded just like functions. You can implement as many constructors as you’d like, as long as their argument types differ.

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



### Default Initialization

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



### Delegating constructors

Constructors are allowed to call other constructors. This process is called delegating constructors (or constructor chaining).

To have one constructor call another, simply call the constructor in the member initializer list. This is one case where calling another constructor directly is acceptable. Applied to our example above:

  class Foo
  {
  private:

  public:
      Foo()
      {
          // code to do A
      }

      Foo(int value): Foo{} // use Foo() default constructor to do A
      {
          // code to do B
      }

  };

This works exactly as you’d expect. Make sure you’re calling the constructor from the member initializer list, not in the body of the constructor.



### Using a separate function

Relatedly, you may find yourself in the situation where you want to write a member function to re-initialize a class back to default values. Because you probably already have a constructor that does this, you may be tempted to try to call the constructor from your member function. However, trying to call a constructor directly will generally result in unexpected behavior as we have shown above. Many developers simply copy the code from the constructor into the initialization function, which would work, but lead to duplicate code. The best solution in this case is to move the code from the constructor to your new function, and have the constructor call your function to do the work of “initializing” the data:

class Foo
{
public:
    Foo()
    {
        init();
    }

    Foo(int value)
    {
        init();
        // do something with value
    }

    void init()
    {
        // code to "initialize" Foo
    }
};

Constructors are allowed to call non-constructor functions in the class. Just be careful that any members the non-constructor function uses have already been initialized. Although you may be tempted to copy code from the first constructor into the second constructor, having duplicate code makes your class harder to understand and more burdensome to maintain.

We say “initialize”, but it’s not real initialization. By the time the constructor calls init(), the members already exist and have been default initialized or are uninitialized. The init function can only assign values to the members. There are some types that cannot be instantiated without arguments, because they don’t have a default constructor. If any of the class members has such a type, the init function doesn’t work and the constructors have to initialize those members themselves.

It is fairly common to include an init() function that initializes member variables to their default values, and then have each constructor call that init() function before doing its parameter-specific tasks. This minimizes code duplication and allows you to explicitly call init() from wherever you like.

One small caveat: be careful when using init() functions and dynamically allocated memory. Because init() functions can be called by anyone at any time, dynamically allocated memory may or may not have already been allocated when init() is called. Be careful to handle this situation appropriately -- it can be slightly confusing, since a non-null pointer could be either dynamically allocated memory or an uninitialized pointer!

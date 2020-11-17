## Inline
C++ inline function is a powerful concept that is commonly used with classes. If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time.

A function definition in a class definition is an inline function definition, even without the use of the inline specifier.


The const specifiers on the functions indicate that these functions do not modify the object for which they are called. A const member function can be invoked for both const and non-const objects, but a non-const member function can only be invoked for non-const objects.














## Constructors
A constructor is a special function (or method) with a special declaration, invoked during the instantiation of a class to construct an object.

Declaring and Implementing a Constructor
Constructor declarations don’t state a return type, and their name matches the class’s name.

This constructor can be implemented either inline within the class or externally outside the class declaration.

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



### Initialization Lists
Another way to initialize members is by using initialization lists.

class Human {
private:
  string name;
  int age;

public:
  // two parameters to initialize members age and name
  Human(string humansName, int humansAge)
  :name(humansName), age(humansAge) {
    cout << "Constructed a human called " << name;
    cout << ", " << age << " years old" << endl;
  }
  // ... other class members
};

Thus, the initialization list is characterized by a colon (:) following the parameter declaration contained in parentheses (…), followed by an individual member variable and the value it is initialized to. This initialization value can be a parameter such as humansName or can even be a fixed value.


### Default Constructor
A constructor that is invoked without arguments is called the
default constructor. Programming a default constructor is
optional. If you don’t program any constructor the compiler creates one for you (that constructs member attributes but does not initialize Plain Old Data types such as int to any specific non-zero value).

You can choose to not implement the default constructor to
enforce object instantiation with certain minimal parameters.

Constructors can be overloaded just like functions.
You can implement as many constructors as you’d like, as long as their argument types differ.

Constructor parameters can be given default values.

Note that a default constructor is one that can be instantiated without arguments, and not necessarily one that doesn’t take parameters. So a constructor with two parameters, both with default values, is a default constructor

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



### constexpr
It is possible to define a constructor as a constant expression
too, using keyword constexpr. In special cases where such a
construct would be useful from a performance point of view, you
would use it at the constructor declaration.
class Sample {
  const char* someString;
public:
  constexpr Sample(const char* input) :someString(input)
  { // constructor code }
};



## Destructor
A destructor, like a constructor, is a special function. A constructor is invoked at object instantiation, and a destructor is automatically invoked when an object is destroyed.

An object’s destructor is its cleanup function.

Destructors are almost never called explicitly: the compiler will ensure that each object’s destructor is called as appropriate.

Defining a destructor is optional. If you do decide to implement a
destructor, it must not take any arguments. Examples of actions you might
want to take in a destructor include releasing file handles, flushing network
sockets, and freeing dynamic objects.
If you don’t define a destructor, a default destructor is automatically
generated. The default destructor’s behavior is to perform no action.


Declaring and Implementing a Destructor
The destructor looks like a function that takes the name of the class, yet has a tilde (~) preceding it. So, class Human would have a destructor that is declared like this:

class Human
{
~Human(); // declaration of a destructor
};

This destructor can either be implemented inline in the class or externally outside the class declaration. An implementation or definition inside the class looks like this:

class Human
{
public:
  ~Human()
  {
  // destructor code here
  }
};

A variant enabling you to define the destructor outside the class’s declaration looks like this:
class Human
{
public:
~Human(); // destructor declaration
};
// destructor definition (implementation)
Human::~Human()
{
// destructor code here
}

A destructor is always invoked when an object of a class is destroyed when it goes out of scope or is deleted via delete. This property makes a destructor the ideal place to reset variables and release dynamically allocated memory and other resources.

A destructor cannot be overloaded. A class can have only one destructor. If you forget to implement a destructor, the compiler creates and invokes a dummy destructor, that is, an empty one (that does no cleanup of dynamically allocated memory).





Using Constructors to Convert Types

A constructor taking a single argument defines a conversion from its argument type. For example,
complex (§4.2.1) provides a constructor from a double:
complex z1 = 3.14; // z1 becomes {3.14,0.0}
complex z2 = z1∗2; // z2 becomes z1*{2.0,0} == {6.28,0.0}
This implicit conversion is sometimes ideal, but not always.

For example, Vector provides a constructor from an int:
Vector v1 = 7; // OK: v1 has 7 elements
This is typically considered unfortunate, and the standard-library vector does not allow this int to vector ‘‘conversion.’’
The way to avoid this problem is to say that only explicit ‘‘conversion’’ is allowed; that is, we can define the constructor like this:

class Vector {
public:
explicit Vector(int s); // no implicit conversion from int to Vector
// ...
};
That gives us:
Vector v1(7); // OK: v1 has 7 elements
Vector v2 = 7; // error : no implicit conversion from int to Vector
When it comes to conversions, more types are like Vector than are like complex, so use explicit for
constructors that take a single argument unless there is a good reason not to.

Such converting constructors allow implicit conversions:
Human anotherKid = 11; // int converted to Human
DoSomething(10); // 10 converted to Human!
We declared DoSomething(Human person) as a function that
accepts a parameter of type Human and does not accept an
int! So, why did that line work? The compiler knows that class
Human supports a constructor that accepts an integer and performed an implicit conversion for you—it created an object of
type Human using the integer you supplied and sent it as an argument to the function.
To avoid implicit conversions, use keyword explicit at the time
of declaring the constructor:
class Human
{
int age;
public:
explicit Human(int humansAge): age(humansAge) {}
};
Using explicit is not a prerequisite but in many cases a good
programming practice. The following sample in Listing 9.12 demonstrates a version of class Human that does not permit implicit
conversions.

















constexpr with Classes and Objects
constexpr offers a powerful way to improve the performance of your C++ application. By marking functions that
operate on constants or const-expressions as constexpr, we are instructing the compiler to evaluate those functions and insert their result instead of inserting instructions
that compute the result when the application is executed.

This keyword can also be used with classes and objects that evaluate as constants.

Note
that the compiler would ignore constexpr when the function or class is used with entities that are not constant.

#include <iostream>
 using namespace std;

 class Human
 {
 int age;
 public:
 constexpr Human(int humansAge) age(humansAge) {}
 constexpr int GetAge() const { return age; }
 };

 int main()
 {
 constexpr Human somePerson(15);
 const int hisAge = somePerson.GetAge();

 Human anotherPerson(45); // not constant expression

 return 0;
 }

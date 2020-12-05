Methods
Methods are a classes' member functions. They create an explicit connection among a class, its data members, and some code. Defining a method is as simple as adding a function to a class definition. Methods have access to all of a class’s members.



Accessor function: A member function of a class that only accesses (that is, does not
modify) the value(s) of the member variable(s).
Mutator function: A member function of a class that modifies the value(s) of the
member variable(s).



## Inline
C++ inline function is a powerful concept that is commonly used with classes. If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time.

A function definition in a class definition is an inline function definition by default.

## Const
The const specifiers on the functions indicate that a function does not modify the object for which it is called. A const member function can be invoked for both const and non-const objects, but a non-const member function can only be invoked for non-const objects.














## Constructors
A constructor is a special function (or method) with a special declaration, invoked during the instantiation of a class to construct an object.

Constructors have the following properties:
  The name of a constructor is the same as the name of the class.
  A constructor is a function and it has no type. That is, it is neither a
value-returning function nor a void function.
  A class can have more than one constructor. However, all constructors of a class have the same name.
  If a class has more than one constructor, the constructors must have different formal parameter lists. That is, either they have a different number of formal parameters or, if the number of formal parameters is the same, then the data type of the formal parameters, in the order you list, must differ in at least one position. Like function overloading
  Constructors execute automatically when a class object is declared and enters its scope. Because they have no types, they cannot be called like other functions.
  Which constructor executes depends on the types of values passed to the class object when the class object is declared.


### Declaring and Implementing a Constructor
Constructor declarations don’t state a return type, and their name matches the class’s name.

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
A constructor that is invoked without arguments is called the
default constructor. Programming a default constructor is
optional. If you don’t program any constructor the compiler creates one for you (that constructs member attributes but does not initialize Plain Old Data types such as int to any specific non-zero value).

You can choose to not implement the default constructor to
enforce object instantiation with certain minimal parameters.

Constructors can be overloaded just like functions.
You can implement as many constructors as you’d like, as long as their argument types differ.

### Invoking the Default Constructor
Suppose that a class contains the default constructor. The syntax to invoke the default constructor is:
className classObjectName;


### Invoking a Constructor with Parameters
Suppose a class contains constructors with parameters. The syntax to invoke a constructor with a parameter is:
className classObjectName(argument1, argument2, ...);

in which argument1, argument2, and so on are either a variable or an expression.
Note the following:
? The number of arguments and their type should match the formal
parameters (in the order given) of one of the constructors.
? If the type of the arguments does not match the formal parameters of any
constructor (in the order given), C11 uses type conversion and looks
for the best match. For example, an integer value might be converted
to a floating-point value with a zero decimal part. Any ambiguity will
result in a compile-time error.



The important things to remember about classes and constructors are the following:
? If a class has no constructor(s), C11 automatically provides the default
constructor. However, the object declared is still uninitialized.
? On the other hand, suppose aclass, say,dummyClass, includes constructor(s)
with parameter(s) and does not include the default constructor. In this case,
C11 does not provide the default constructor for the class dummyClass.
Therefore, when an object of the class dummyClass is declared, we must
include the appropriate arguments in its declaration.



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





## Default Initialization
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



Pointers and Destructors
Consider

struct Node {
  char *name;
  int age;
public:
  Node(char *n = "", int a = 0) {
    name = strdup(n);
    age = a;
  }
};

What happens to locally defined objects of type Node? Like all local items, they are destroyed in the sense that they become unavailable outside the block in which they are defined, and memory occupied by them is also released. But although memory occupied by an object of type Node is released, not all the memory related to this object becomes available. One of the data members of this object is a pointer to a string;
therefore, memory occupied by the pointer data member is released, but memory
taken by the string is not. After the object is destroyed, the string previously available from its data member name becomes inaccessible (if not assigned to the name of
some other object or to a string variable) and memory occupied by this string can no
longer be released, which leads to a memory leak. This is a problem with objects that
have data members pointing to dynamically allocated locations. To avoid the problem, the class definition should include a definition of a destructor. A destructor is a
function that is automatically invoked when an object is destroyed, which takes place
upon exit from the block in which the object is defined or upon the call of delete.
Destructors take no arguments and return no values so that there can be only one
destructor per class. For the class Node, a destructor can be defined as
	 ~Node() {
if (name != 0)
free(name);
	 }






















Virtual Destructor
Classes and Virtual Destructors
One thing recommended for classes with pointer member variables is that these
classes should have the destructor. The destructor executes automatically when the
class object goes out of scope. Thus, if the object creates dynamic memory space, the
destructor can be designed to deallocate that memory space. If a derived class object
is passed to a formal parameter of the base class type, the destructor of the base class
executes regardless of whether the derived class object is passed by reference or by
value. Logically, however, the destructor of the derived class should be executed when
the derived class object goes out of scope.
To correct this problem, the destructor of the base class must be virtual. The virtual
destructor of a base class automatically makes the destructor of a derived class virtual.
When a derived class object is passed to a formal parameter of the base class type, then
when the object goes out of scope, the destructor of the derived class executes. After
executing the destructor of the derived class, the destructor of the base class executes.
Therefore, when the derived class object is destroyed, the base class part (that is, the
members inherited from the base class) of the derived class object is also destroyed.
If a base class contains virtual functions, make the destructor of the base class virtual.


Can a destructor be pure virtual in C++?
Yes, it is possible to have pure virtual destructor. Pure virtual destructors are legal in standard C++ and one of the most important things to remember is that if a class contains a pure virtual destructor, it must provide a function body for the pure virtual destructor. You may be wondering why a pure virtual function requires a function body. The reason is because destructors (unlike other functions) are not actually ‘overridden’, rather they are always called in the reverse order of the class derivation. This means that a derived class’ destructor will be invoked first, then base class destructor will be called. If the definition of the pure virtual destructor is not provided, then what function body will be called during object destruction? Therefore the compiler and linker enforce the existence of a function body for pure virtual destructors.
Consider the following program:

#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed";
    }
};

int main()
{
    Base *b=new Derived();
    delete b;
    return 0;
}

The linker will produce following error in the above program.

test.cpp:(.text$_ZN7DerivedD1Ev[__ZN7DerivedD1Ev]+0x4c):
undefined reference to 'Base::~Base()'

Now if the definition for the pure virtual destructor is provided, then the program compiles & runs fine.

#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};
Base::~Base()
{
    std::cout << "Pure virtual destructor is called";
}

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed\n";
    }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}

Output:

~Derived() is executed
Pure virtual destructor is called

It is important to note that a class becomes abstract class when it contains a pure virtual destructor. For example, try to compile the following program.



#include <iostream>
class Test
{
public:
    virtual ~Test()=0; // Test now becomes abstract class
};
Test::~Test() { }

int main()
{
    Test p;
    Test* t1 = new Test;
    return 0;
}

The above program fails in compilation & shows following error messages.
[Error] cannot declare variable ‘p’ to be of abstract type ‘Test’
[Note] because the following virtual functions are pure within ‘Test’:
[Note] virtual Test::~Test()
[Error] cannot allocate an object of abstract type ‘Test’
[Note] since type ‘Test’ has pure virtual functions






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
 constexpr Human(int humansAge) : age(humansAge) {}
 constexpr int GetAge() const { return age; }
 };

 int main()
 {
 constexpr Human somePerson(15);
 const int hisAge = somePerson.GetAge();

 Human anotherPerson(45); // not constant expression

 return 0;
 }

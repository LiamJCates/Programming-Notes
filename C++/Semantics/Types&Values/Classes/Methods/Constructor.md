## Constructors
A constructor is a special method with a special declaration, invoked during the instantiation of a class to construct an object.

Constructors have the following properties:
  The name of a constructor is the same as the name of the class.
  A constructor is a function and it has no type. That is, it is neither a value-returning function nor a void function.
  A class can have more than one constructor. However, all constructors of a class have the same name.
  If a class has more than one constructor, the constructors must have different formal parameter lists. That is, either they have a different number of formal parameters or, if the number of formal parameters is the same, then the data type of the formal parameters, in the order you list, must differ in at least one position. Like function overloading
  Constructors execute automatically when a class object is declared and enters its scope. Because they have no types, they cannot be called like other functions.
  Which constructor executes depends on the types of values passed to the class object when the class object is declared.

It is the job of a constructor to establish the invariant for its class (so that the member functions can rely on it) and for the member functions to make sure that the invariant holds when they exit.

The notion of invariants is central to the design of classes, and preconditions serve a similar role in the design of functions.

Invariants
• help us to understand precisely what we want
• force us to be specific; that gives us a better chance of getting our code correct (after debugging and testing).

The notion of invariants underlies C++’s notions of resource management supported by constructors (Chapter 4) and destructors


### Constructor Types
There are three types of constructors in C++:
Default Constructors
Parameterized
Copy Constructors

We discuss the first two here and the third is discussed:
[C++\Types&Values\Classes\Copy&Move\CopyConstructor.md]



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
A constructor that is invoked without arguments is called the default constructor. Programming a default constructor is optional. If you don’t program any constructor the compiler creates one for you (that constructs member attributes but does not initialize Plain Old Data types such as int to any specific non-zero value).

You can choose to not implement the default constructor to enforce object instantiation with certain minimal parameters.

Constructors can be overloaded just like functions. You can implement as many constructors as you’d like, as long as their argument types differ.

### Invoking the Default Constructor
Suppose that a class contains the default constructor. The syntax to invoke the default constructor is:
className classObjectName;


### Invoking a Constructor with Parameters
A class may contain constructors with parameters, called parameterized constructors.

The syntax to invoke a constructor with a parameter is:
className classObjectName(argument1, argument2, ...);

in which argument1, argument2, and so on are either a variable or an expression.

Note the following:
? The number of arguments and their type should match the formal parameters (in the order given) of one of the constructors.

? If the type of the arguments does not match the formal parameters of any constructor (in the order given), C++ uses type conversion and looks for the best match. For example, an integer value might be converted to a floating-point value with a zero decimal part. Any ambiguity will result in a compile-time error.


The important things to remember about classes and constructors are the following:
? If a class has no constructor(s), C++ automatically provides the default
constructor. However, the object declared is still uninitialized.

? On the other hand, suppose aclass, say, dummyClass, includes constructor(s) with parameter(s) and does not include the default constructor. In this case, C++ does not provide the default constructor for the class dummyClass. Therefore, when an object of the class dummyClass is declared, we must include the appropriate arguments in its declaration.



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

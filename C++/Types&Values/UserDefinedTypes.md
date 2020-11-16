User-defined types are types that the user can define:

Structures
The simplest kind of classes are plain-old-data classes (PODs) often called Structures.

Enumerations The simplest of the user-defined types. The values
that an enumeration can take are restricted to a set of possible values. Enumerations are excellent for modeling categorical concepts.

Classes More fully featured types that give you flexibility to pair data and functions. Classes that only contain data are called plain-old-data classes

Unions A boutique user-defined type. All members share the same
memory location. Unions are dangerous and easy to misuse.











Plain-Old-Data Classes
Classes are user-defined types that contain data and functions, and they’re the heart and soul of C++. PODs are simple containers. Think of them as a sort of heterogeneous array of elements of potentially different types.



PODs are often called Structures.

Every Structure begins with the keyword struct followed by the Structures desired name. Next, you list the members’ types and names.
Each element of a class is called a member.

General struct syntax:

struct [structure tag] {
   member definition;
   member definition;
   ...
   member definition;
} [one or more structure variables];  


Consider the following Book class declaration with four members:
struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};


You declare POD variables just like any other variables: by type and name.
You can then access members of the variable using the dot operator (.).

#include <cstdio>
struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};
int main() {
  Book neuromancer;
  neuromancer.pages = 271;
  printf("Neuromancer has %d pages.", neuromancer.pages);
}

PODs have some useful low-level features: they’re C compatible, you can employ machine instructions that are highly efficient to copy or move them, and they can be efficiently represented in memory.
C++ guarantees that members will be sequential in memory, although some implementations require members to be aligned along word boundaries, which depend on
CPU register length. As a general rule, you should order members from largest to
smallest within POD definitions.

Pointers to Structures

You can define pointers to structures in very similar way as you define pointer to any other variable:

struct [struct type] *[struct pointer name];

Now, you can store the address of a structure variable in the above defined pointer variable. To find the address of a structure variable, place the & operator before the structure's name as follows −

[struct pointer name] = &[struct name];

To access the members of a structure using a pointer to that structure, you must use the -> operator as follows −

[struct name]->[struct member];


The typedef Keyword

To define an "alias" for struct types:

typedef struct {
  member definition;
  member definition;
  ...
  member definition;
} [struct Type name];

Then use the alias directly to define variables without using the struct keyword:

[struct Type name] struct1, struct2;




struct Vector {
int sz; // number of elements
double∗ elem; // pointer to elements
};

This first version of Vector consists of an int and a double∗.

A variable of type Vector can be defined like this:

Vector v;

However, by itself that is not of much use because v’s elem pointer doesn’t point to anything. For it to be useful, we must give v some elements to point to. For example, we can construct a Vector like
this:

void vector_init(Vector& v, int s)
{
v.elem = new double[s]; // allocate an array of s doubles
v.sz = s;
}

That is, v’s elem member gets a pointer produced by the new operator and v’s sz member gets the number of elements. The & in Vector& indicates that we pass v by non-const reference (§1.7); that way, vector_init() can modify the vector passed to it.

The new operator allocates memory from an area called the free store (also known as dynamic memory and heap). Objects allocated on the free store are independent of the scope from which they are created and ‘‘live’’ until they are destroyed using the delete operator.




A simple use of Vector looks like this:
double read_and_sum(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
Vector v;
vector_init(v,s); // allocate s elements for v
for (int i=0; i!=s; ++i)
cin>>v.elem[i]; // read into elements
double sum = 0;
for (int i=0; i!=s; ++i)
sum+=v.elem[i]; // compute the sum of the elements
return sum;
}

We use . (dot) to access struct members through a name (and through a reference) and −> to
access struct members through a pointer. For example:
void f(Vector v, Vector& rv, Vector∗ pv)
{
int i1 = v.sz; // access through name
int i2 = rv.sz; // access through reference
int i3 = pv−>sz; // access through pointer
}








## Enumerations
Declare enumerations using the keywords enum class followed by the type name and a listing of the values it can take.

These values are arbitrary alphanumeric strings that will represent whatever categories you want to represent. Under the hood, these values are simply integers, but they allow you to write safer, more expressive code by using programmer-defined types rather than integers that could mean anything

There are situations where a particular variable should be allowed to accept only a certain set of values. These are situations where you don’t want the colors in the rainbow to contain Turquoise or the directions on a compass to contain Left.

In both these cases, you need a type of variable whose values are restricted to a certain set defined by you. Enumerations are exactly the tool you need in this situation.

Enumerations comprise a set of constants called enumerators.

Enumeration Classes

enum class RainbowColors {
Violet,
Indigo,
Blue,
Green,
Yellow,
Orange,
Red
};

To initialize an enumeration variable to a value, use the name of the
type followed by two colons :: and the desired value.

RainbowColors color = RainbowColors::Red;

Technically, an enum class is one of two kinds of enumerations: it’s called a scoped enum. For compatibility with C, C++ also supports an unscoped enum, which is declared with enum rather than enum class. The major difference is that scoped enums
require the enum’s type followed by :: to precede the values, whereas unscoped enums
don’t. Unscoped enum classes are less safe to use than scoped enums, so shy away from
them unless absolutely necessary. They’re supported in C++ for mainly historical reasons, especially interoperation with C code.

Syntax:
enum enum-name { list of names } var-list;

RainbowColors as an unscoped enumeration:

enum RainbowColors
{
Violet,
Indigo,
Blue,
Green,
Yellow,
Orange,
Red
} color;


color = Red;
















Unions
A union is a special class type where only one of the non-static data members is active at a time.

A union is a struct in which all members are allocated at the same address so that the union occupies only as much space as its largest member. Naturally, a union can hold a value for only one
member at a time.

The union is a cousin of the POD that puts all of its members in the same place. You can think of unions as different views or interpretations of a block of memory.

Declaring a Union
A union is declared using keyword union, followed by the name of the union and its data members within braces:
 union UnionName
 {
 Type1 member1;
 Type2 member2;
 …
 TypeN memberN;
 };

 You would instantiate and use a union like this:
 UnionName unionObject;
 unionObject.member2 = value; // choose member2 as the active member

Similar to the struct, the members of a union are public by default. Unlike a struct, however, unions cannot be used in inheritance hierarchies.

Additionally, the sizeof() a union is always fixed as the size of the largest member contained in the union—even if that member were inactive in an instance of the union.

Example declare a union: simply use the union keyword instead of struct.
union Variant {
  char string[10];
  int integer;
  double floating_point;
};


It takes up only as much memory as its largest member (probably string in
this case).
You use the dot operator (.) to specify a union’s interpretation.
Syntactically, this looks like accessing a member of a POD, but it’s completely different under the hood.
Because all members of a union are in the same place, you can cause
data corruption very easily.

#include <cstdio>
union Variant {
  char string[10];
  int integer;
  double floating_point;
};

int main() {
  Variant v;
  v.integer = 42;
  printf("The ultimate answer: %d\n", v.integer);
  v.floating_point = 2.7182818284;
  printf("Euler's number e: %f\n", v.floating_point);
  printf("A dumpster fire: %d\n", v.integer);
}


Where Would You Use a union?
the main problem with unions: it’s up to you to keep track of
which interpretation is appropriate. The compiler won’t help you.
You should avoid using unions in all but the rarest of cases

Often a union is used as a member of a struct to model a complex data type. In some implementations, the ability of a union to interpret the fixed memory space as another type is used for type conversions or memory reinterpretation—a practice that is controversial and not necessary given alternatives.

They can be useful in some low-level situations, such as when marshalling structures that must be consistent across architectures, dealing with type-checking issues related to C/C++ interoperation, and even when packing bitfields.





Classes
POD classes contain only data members, and sometimes that’s all you want from a class. However, designing a program using only PODs can create a lot of complexity. You can fight such complexity with encapsulation, a design pattern that binds data with the functions that manipulate it. Placing related
functions and data together helps to simplify code in at least two ways. First,
you can put related code in one place, which helps you to reason about your
program. You can understand how a code segment works because it describes
in one place both program state and how your code modifies that state.
Second, you can hide some of a class’s code and data from the rest of your
program using a practice called information hiding.
In C++, you achieve encapsulation by adding methods and access controls to class definitions.

Having the data specified separately from the operations on it has advantages, such as the ability to use the data in arbitrary ways. However, a tighter connection between the representation and the
operations is needed for a user-defined type to have all the properties expected of a ‘‘real type.’’

We often want to keep the representation inaccessible to users so as to ease use, guarantee consistent use of the data, and allow us to later improve the representation. To do that we have to distinguish between the interface to a type (to be used by all) and its implementation (which has access to the otherwise inaccessible data).

The language mechanism for that is called a class.

Concrete Types
The basic idea of concrete classes is that they behave ‘‘just like built-in types.’’ For example, a complex number type and an infinite-precision integer are much like built-in int, except of course
that they have their own semantics and sets of operations.

The defining characteristic of a concrete type is that its representation is part of its definition, and that representation is present in each object of a concrete class. That allows implementations to be optimally efficient in time and space.

In particular, it allows us to:
• place objects of concrete types on the stack, in statically allocated memory, and in other objects (§1.5);
• refer to objects directly (and not just through pointers or references);
• initialize objects immediately and completely (e.g., using constructors; §2.3);
• copy and move objects (§5.2).



The class Keyword
You can replace the struct keyword with the class keyword, which declares members private by default. Aside from default access control, classes declared with the struct and class keywords are the same.

The keyword class, creates a data type that encapsulates member attributes and functions

Declaring a Class

class ClassName{
  type attribute name;

  type methodName(){};
};

A class has a set of members, which can be data, function, or type members. The interface is defined by the public members of a class, and private members are accessible only through that interface.

Attributes
Attributes are a classes' data members.

Methods
Methods are a classes' member functions. They create an explicit connection among a class, its data members, and some code. Defining a method is as simple
as adding a function to a class definition. Methods have access to all of a
class’s members.


For example:
class Vector {
public:
Vector(int s) :elem{new double[s]}, sz{s} { } // constr uct a Vector
double& operator[](int i) { return elem[i]; } // element access: subscripting
int size() { return sz; }
private:
double∗ elem; // pointer to the elements
int sz; // the number of elements
};

Here, the representation of a Vector (the members elem and sz) is accessible only through the interface provided by the public members: Vector(), operator[](), and size().



Creating an object of type class Human is similar to creating an instance of another type, say double:
double pi= 3.1415; // a variable of type double
Human firstMan; // firstMan: an object of class Human

Alternatively, you would dynamically create an instance of class Human using new as you would for another type, say an int:
int* pointsToNum = new int; // an integer allocated dynamically
delete pointsToNum; // de-allocating memory when done using
Human* firstWoman = new Human(); // dynamically allocated Human
delete firstWoman; // de-allocating memory






Access members using the dot operator

If you have a pointer firstWoman to an instance of class Human, you can either use the pointer operator (->) to access members, or use the indirection operator (*) to reference the object following the dot operator.

Human* firstWoman = new Human();
(*firstWoman).IntroduceSelf();

If an object has been instantiated on the free store using new or if you have a pointer to an object, then you use the pointer operator (->) to access the member attributes and functions:
Human* firstWoman = new Human();
firstWoman->dateOfBirth = "1970";
firstWoman->IntroduceSelf();
delete firstWoman;

What is a better way to access members: using the dot operator (.) or using the pointer operator (->)?

A If you have a pointer to an object, the pointer operator would be best suited. If you have instantiated an object as a local variable on the stack, then the dot operator is best suited.



Member Initializers
When a data member of a class is defined, we can supply a default initializer called a default member initializer. Consider a revision of complex (§4.2.1):

class complex {
double re = 0;
double im = 0; // representation: two doubles with default value 0.0
public:
complex(double r, double i) :re{r}, im{i} {} // constr uct complex from two scalars: {r,i}
complex(double r) :re{r} {} // constr uct complex from one scalar: {r,0}
complex() {} // default complex: {0,0}
// ...
}

The default value is used whenever a constructor doesn’t provide a value. This simplifies code and helps us to avoid accidentally leaving a member uninitialized.




C++ inline function is a powerful concept that is commonly used with classes. If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time.

Any change to an inline function could require all clients of the function to be recompiled because compiler would need to replace all the code once again otherwise it will continue with old functionality.

To inline a function, place the keyword inline before the function name and define the function before any calls are made to the function. The compiler can ignore the inline qualifier in case defined function is more than a line.

A function definition in a class definition is an inline function definition, even without the use of the inline specifier.

Following is an example, which makes use of inline function to return max of two numbers −
Live Demo

#include <iostream>

using namespace std;

inline int Max(int x, int y) {
   return (x > y)? x : y;
}

// Main function for the program
int main() {
   cout << "Max (20,10): " << Max(20,10) << endl;
   cout << "Max (0,200): " << Max(0,200) << endl;
   cout << "Max (100,1010): " << Max(100,1010) << endl;

   return 0;
}





The const specifiers on the functions indicate that these functions do not modify the object for which they are called. A const member function can be invoked for both const and non-const objects, but a non-const member function can only be invoked for non-const objects.




Access Controls
Access controls restrict class-member access. Public and private are the two major access controls. Anyone can access a public member, but only a class can access its private members. All struct members are public by default.


Keywords public and private
Information can be classified into at least two categories: data that we don’t mind the public knowing and data that is private.
C++ enables you to model class attributes and methods as public or private.
Public class members can be used by anyone in possession of an object of the class. Private class members can be used only within the class

Private members play an important role in encapsulation.

class Human
{
private:
// Private member data:
int age;
string name;
public:
int GetAge()
{
return age;
}
void SetAge(int humansAge)
{
age = humansAge;
}
// ...Other members and declarations
};



## Constructors
A constructor is a special function (or method) with a special declaration, invoked during the instantiation of a class to construct an object.

Declaring and Implementing a Constructor
Constructor declarations don’t state a return type, and their name matches the class’s name.

So, class Human would have a constructor that is declared like this:

class Human
{
public:
Human(); // declaration of a constructor
};
This constructor can be implemented either inline within the class or externally outside the class declaration. An implementation (also called definition) inside the class looks like this:

class Human
{
public:
Human()
{
// constructor code here
}
};

A variant enabling you to define the constructor outside the class’ declaration:

class Human
{
public:
Human(); // constructor declaration
};

// constructor implementation (definition)
Human::Human()
{
  // constructor code here
}

:: is called the scope resolution operator.

For example, Human::dateOfBirth is referring to variable dateOfBirth
declared within the scope of class Human.
::dateOfBirth, on the other hand would refer to another variable dateOfBirth in a global scope.



### Default Constructor
A constructor that is invoked without arguments is called the
default constructor. Programming a default constructor is
optional. If you don’t program any constructor the compiler creates one for you (that constructs member attributes but does not initialize Plain Old Data types such as int to any specific non-zero value).

You can choose to not implement the default constructor to
enforce object instantiation with certain minimal parameters.

Constructors can be overloaded just like functions.
You can implement as many constructors as you’d like, as long as their argument types differ.

Constructor parameters can be given default values.

Note that a default constructor is one that can be instantiated
without arguments, and not necessarily one that doesn’t take
parameters. So a constructor with two parameters, both with
default values, is a default constructor









Another way to initialize members is by using initialization lists.

class Human
{
private:
string name;
int age;

public:
// two parameters to initialize members age and name
Human(string humansName, int humansAge)
:name(humansName), age(humansAge)
{
cout << "Constructed a human called " << name;
cout << ", " << age << " years old" << endl;
}
// ... other class members
};

Thus, the initialization list is characterized by a colon (:) following the parameter declaration contained in parentheses (…), followed by an individual member variable and the value it is initialized to. This initialization value can be a parameter such as humansName or can even be a fixed value. Initialization lists can also be useful in
invoking base class constructors with specific arguments.

It is possible to define a constructor as a constant expression
too, using keyword constexpr. In special cases where such a
construct would be useful from a performance point of view, you
would use it at the constructor declaration.
class Sample
{
const char* someString;
public:
constexpr Sample(const char* input)
:someString(input)
{ // constructor code }
};





## Supercharging enums with Classes
When you work with classes, you can use a technique called wrapping, which helps you manage a resource.

An instance where this is useful is printing an enumeration,
Attempting to do this you don’t see the word, such as red or blue; you see
a number. The DisplayEnum example, is a simple class that wraps an enum type — essentially, it helps you convert the number into a human readable form, which is a kind of resource management.

You can use this class with enum ColorEnum, as main() demonstrates. When you run this application, you see the single word red in the console.

#include <iostream>
using namespace std;
class Colors
{
  public:
  enum ColorEnum {blue, red, green, yellow, black};

  Colors(Colors::ColorEnum value);

  string AsString();

  protected:
  ColorEnum value;
};
Colors::Colors(Colors::ColorEnum initvalue)
{
value = initvalue;
}
string Colors::AsString()
{
switch (value)
{
case blue:
return "blue";
case red:
return "red";
case green:
return "green";
case yellow:
return "yellow";
case black:
return "black";
default:
return "Not Found";
}
}
int main()
{
Colors InkColor = Colors::red;
cout << InkColor.AsString() << endl;
return 0;
}



In main(), we created the InkColor instance and set it not to a Color
object but to an enum. We just violated An Important Rule about setting
things equal to something of the same type. Why? C++ has a neat little
trick: You can create a constructor that takes a certain type. In this case,
we have a constructor that takes a ColorEnum. Then when you create
a stack variable (not a pointer), you can just set it equal to a value of
that type. The computer will implicitly call the constructor, passing it
that value.







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


Steps to Using Objects
1 Pen *MyPen; Declares the pointer
2 MyPen = new Pen; Calls new to create the object
3 MyPen->InkColor = red; Accesses object member through the pointer
4 delete MyPen; Deletes the object
5 MyPen = 0; Clears the pointer


The technique of acquiring resources in a constructor and releasing them in a destructor, known as Resource Acquisition Is Initialization or RAII, allows us to eliminate ‘‘naked new operations,’’ that is, to avoid allocations in general code and keep them buried inside the implementation of well-behaved abstractions. Similarly, ‘‘naked delete operations’’ should be avoided. Avoiding naked new and naked delete makes code far less error-prone and far easier to keep free of resource leaks




We might created the two object on the heap by using pointers and calling
Object *ob1 = new Object;
Object *ob2 = new Object;

Then delete them
delete ob1;
delete ob2;

But we could have made them on the stack by just declaring them without pointers:
Object ob1;
Object ob2;

You can do this, and the application will run fine, provided you remove the delete lines.
You do not delete stack variables. The computer calls the destructor when the function they are contained by ends, and they go out of scope. That’s the general rule with objects on the stack: They are created when you declare them, and they stay until the function ends.















Shallow Copying and Associated Problems
Classes that contain a pointer member buffer that points to dynamically allocated memory, allocated in the constructor using new and deallocated in the destructor using delete[].

When an object of this class is copied, the pointer member is copied, but not the pointed memory, resulting in two objects pointing to the same dynamically allocated buffer in memory. When an object is destructed, delete[] deallocates the memory, thereby invalidating the pointer copy held by the other object.

Such copies are shallow and are a threat to the stability of the program



Copy Constructor
The copy constructor is a constructor which creates an object by initializing it with an object of the same class, which has been created previously. The copy constructor is used to −

    Initialize one object from another of the same type.
    Copy an object to pass it as an argument to a function.
    Copy an object to return it from a function.

If a copy constructor is not defined in a class, the compiler itself defines one.If the class has pointer variables and has some dynamic memory allocations, then it is a must to have a copy constructor. The most common form of copy constructor is shown here −

classname (const classname &obj) {
   // body of constructor
}


Ensuring Deep Copy Using a Copy Constructor
The copy constructor is an overloaded constructor that you supply. It is invoked by the
compiler every time an object of the class is copied.
The declaration syntax of a copy constructor for class MyString is the following:
class MyString
{
MyString(const MyString& copySource); // copy constructor
};
MyString::MyString(const MyString& copySource)
{
// Copy constructor implementation code
}
Thus, a copy constructor takes an object of the same class by reference as a parameter.
This parameter is an alias of the source object and is the handle you have in writing your
custom copy code. You would use the copy constructor to ensure a deep copy

he copy constructor has ensured deep copy in cases such as
function calls:
MyString sayHello("Hello from String Class");
UseMyString(sayHello);
However, what if you tried copying via assignment:
MyString overwrite("who cares? ");
overwrite = sayHello;
This would still be a shallow copy because you still haven’t yet
supplied a copy assignment operator=. In the absence of one,
the compiler has supplied a default for you that does a shallow
copy.
The copy assignment operator is discussed in length in Lesson
12. Listing 12.8 is an improved MyString that implements the
same:
MyString::operator= (const MyString& copySource)
{
//... copy assignment operator code
}

Using const in the copy constructor declaration ensures that
the copy constructor does not modify the source object being
referred to.
Additionally, the parameter in the copy constructor is passed by
reference as a necessity. If this weren’t a reference, the copy
constructor would itself invoke a copy, thus invoking itself again
and so on till the system runs out of memory

The class MyString with a raw pointer member, char* buffer
is used as an example to explain the need for copy constructors.
If you were to program a class that needs to contain string data
for storing names and so on, you use std::string instead of
char* and might not even need a copy constructor given the
absence of raw pointers. This is because the default copy constructor inserted by the compiler would ensure the invocation
of all available copy constructors of member objects such as
std::string.

Move Constructors Help Improve Performance
There are cases where objects are subjected to copy steps automatically, due to the nature
of the language and its needs. Consider the following:
class MyString
{
// pick implementation from Listing 9.9
};
MyString Copy(MyString& source) // function
{
MyString copyForReturn(source.GetString()); // create copy
return copyForReturn; // return by value invokes copy constructor
}int main()
{
MyString sayHello ("Hello World of C++");
MyString sayHelloAgain(Copy(sayHello)); // invokes 2x copy constructor
return 0;
}
As the comment indicates, in the instantiation of sayHelloAgain, the copy constructor
was invoked twice, thus a deep copy was performed twice because of our call to function
Copy(sayHello) that returns a MyString by value. However, this value returned is very
temporary and is not available outside this expression. So, the copy constructor invoked
in good faith by the C++ compiler is a burden on performance. This impact becomes significant if our class were to contain objects of great size.
To avoid this performance bottleneck, versions of C++ starting with C++11 feature a
move constructor in addition to a copy constructor. The syntax of a move constructor is
// move constructor
MyString(MyString&& moveSource)
{
if(moveSource.buffer != NULL)
{
buffer = moveSource.buffer; // take ownership i.e. 'move'
moveSource.buffer = NULL; // set the move source to NULL
}
}
When a move constructor is programmed, the compiler automatically opts for the same
for “moving” the temporary resource and hence avoiding a deep-copy step. With the
move constructor implemented, the comment should be appropriately changed to the following:
MyString sayHelloAgain(Copy(sayHello)); // invokes 1x copy, 1x move constructors

You would ensure that your class cannot be copied by declaring a private copy constructor. This ensures that the function call DoSomething(ourPresident) will cause a
compile failure. To avoid assignment, you declare a private assignment operator.
Thus, the solution is the following:
class President
{
private:
President(const President&); // private copy constructor
President& operator= (const President&); // private copy assignment operator
// … other attributes
};
There is no need for implementation of the private copy constructor or assignment
operator. Just declaring them as private is adequate and sufficient toward fulfilling your
goal of ensuring non-copyable objects of class President











Constructors, destructors, and copy and move operations for a type are not logically separate.

We must define them as a matched set or suffer logical or performance problems.

If a class X has a destructor that performs a nontrivial task, such as free-store deallocation or lock release, the class is likely to need the full complement of functions:
class X {
public:
X(Sometype); // ‘‘ordinar y constructor’’: create an object
X(); // default constructor
X(const X&); // copy constructor
X(X&&); // move constructor
X& operator=(const X&); // copy assignment: clean up target and copy
X& operator=(X&&); // move assignment: clean up target and move
˜X(); // destr uctor: clean up
// ...
};
There are five situations in which an object can be copied or moved:
• As the source of an assignment
• As an object initializer
• As a function argument
• As a function return value
• As an exception

An assignment uses a copy or move assignment operator. In principle, the other cases use a copy or move constructor. However, a copy or move constructor invocation is often optimized away by constructing the object used to initialize right in the target object.

For example:
X make(Sometype);
X x = make(value);
Here, a compiler will typically construct the X from make() directly in x; thus eliminating (‘‘eliding’’) a copy.

In addition to the initialization of named objects and of objects on the free store, constructors are used to initialize temporary objects and to implement explicit type conversion.
Except for the ‘‘ordinary constructor,’’ these special member functions will be generated by the compiler as needed. If you want to be explicit about generating default implementations, you can:
class Y {
public:
Y(Sometype);
Y(const Y&) = default; // I really do want the default copy constr uctor
Y(Y&&) = default; // and the default move constr uctor
// ...
};

If you are explicit about some defaults, other

A good rule of thumb (sometimes called the rule of zero) is to either define all of the essential operations or none (using the default for all). For example:

struct Z {
Vector v;
string s;
};

Z z1; // default initialize z1.v and z1.s
Z z2 = z1; // default copy z1.v and z1.s
Here, the compiler will synthesize memberwise default construction, copy, move, and destructor as needed, and all with the correct semantics.

To complement =default, we have =delete to indicate that an operation is not to be generated. A base class in a class hierarchy is the classical example where we don’t want to allow a memberwise copy.

For example:
class Shape {
public:
Shape(const Shape&) =delete; // no copy operations
Shape& operator=(const Shape&) =delete;
// ...
};
void copy(Shape& s1, const Shape& s2)
{
s1 = s2; // error : Shape copy is deleted
}
A =delete makes an attempted use of the deleted function a compile-time error; =delete can be used
to suppress any function, not just essential member functions.










Static Members of a C++ Class

We can define class members static using static keyword. When we declare a member of a class as static it means no matter how many objects of the class are created, there is only one copy of the static member.

A static member is shared by all objects of the class. All static data is initialized to zero when the first object is created, if no other initialization is present. We can't put it in the class definition but it can be initialized outside the class as done in the following example by redeclaring the static variable, using the scope resolution operator :: to identify which class it belongs to.

Let us try the following example to understand the concept of static data members −
Live Demo

#include <iostream>

using namespace std;

class Box {
   public:
      static int objectCount;

      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;

         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
         return length * breadth * height;
      }

   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects.
   cout << "Total objects: " << Box::objectCount << endl;

   return 0;
}

When the above code is compiled and executed, it produces the following result −

Constructor called.
Constructor called.
Total objects: 2

Static Function Members

By declaring a function member as static, you make it independent of any particular object of the class. A static member function can be called even if no objects of the class exist and the static functions are accessed using only the class name and the scope resolution operator ::.

A static member function can only access static data member, other static member functions and any other functions from outside the class.

Static member functions have a class scope and they do not have access to the this pointer of the class. You could use a static member function to determine whether some objects of the class have been created or not.

Let us try the following example to understand the concept of static function members −
Live Demo

#include <iostream>

using namespace std;

class Box {
   public:
      static int objectCount;

      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;

         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
         return length * breadth * height;
      }
      static int getCount() {
         return objectCount;
      }

   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
   // Print total number of objects before creating object.
   cout << "Inital Stage Count: " << Box::getCount() << endl;

   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects after creating object.
   cout << "Final Stage Count: " << Box::getCount() << endl;

   return 0;
}



Singleton Class That Permits a Single Instance

Welcome to the concept of singleton that uses private constructors, a private
assignment operator, and a static instance member to create this (controversially)
powerful pattern.
When the keyword static is used on a class’s data member, it
ensures that the member is shared across all instances.
When static is used on a local variable declared within the
scope of a function, it ensures that the variable retains its value
between function calls.
When static is used on a member function—a method—the
method is shared across all instances of the class.

Use the singleton pattern only where absolutely necessary,
keeping future growth of the application and its features in perspective. Note that the very feature that it restricts creation of
multiple instances can become an architectural bottleneck when
a use case comes up that needs multiple instances of the class.









Class That Prohibits Instantiation on the Stack
Space on the stack is often limited. If you are writing a database that may contain terabytes of data in its internal structures, you might want to ensure that a client of this class
cannot instantiate it on the stack; instead it is forced to create instances only on the free
store. The key to ensuring this is declaring the destructor private:
class MonsterDB
{
private:
~MonsterDB(); // private destructor
//... members that consume a huge amount of data
};Declaring a private destructor ensures that one is not allowed to create an instance like
this:
int main()
{
MonsterDB myDatabase; // compile error
// … more code
return 0;
}
This instance, if successfully constructed, would be on the stack. All objects on the stack
get popped when the stack is unwound and therefore the compiler would need to compile
and invoke the destructor ~MonsterDB() at the end of main(). However, this destructor
is private and therefore inaccessible, resulting in a compile failure.
A private destructor would not stop you from instantiating on the heap:
int main()
{
MonsterDB* myDatabase = new MonsterDB(); // no error
// … more code
return 0;
}
If you see a memory leak there, you are not mistaken. As the destructor is not accessible
from main, you cannot do a delete, either. What class MonsterDB needs to support is a
public static member function that would destroy the instance (a class member would
have access to the private destructor)













Using Constructors to Convert Types

A constructor taking a single argument defines a conversion from its argument type. For example,
complex (§4.2.1) provides a constructor from a double:
complex z1 = 3.14; // z1 becomes {3.14,0.0}
complex z2 = z1∗2; // z2 becomes z1*{2.0,0} == {6.28,0.0}
This implicit conversion is sometimes ideal, but not always. For example, Vector (§4.2.2) provides
a constructor from an int:
Vector v1 = 7; // OK: v1 has 7 elements
This is typically considered unfortunate, and the standard-library vector does not allow this int-tovector ‘‘conversion.’’
The way to avoid this problem is to say that only explicit ‘‘conversion’’ is allowed; that is, we
can define the constructor like this:68 Essential Operations Chapter 5
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










this Pointer
An important concept in C++, this is a reserved keyword applicable within the scope
of a class and contains the address of the object. In other words, the value of this is
&object. Within a class member method, when you invoke another member method, the
compiler sends this pointer as an implicit, invisible parameter in the function call

Every object in C++ has access to its own address through an important pointer called this pointer. The this pointer is an implicit parameter to all member functions. Therefore, inside a member function, this may be used to refer to the invoking object.

Friend functions do not have a this pointer, because friends are not members of a class. Only member functions have a this pointer.

Note that the this pointer is not sent to class methods declared
as static as static functions are not connected to an instance
of the class. Instead they are shared by all instances.
To use an instance variable in a static function, you would explicitly declare a parameter and send this pointer as an argument.








sizeof() a Class
You have learned the fundamentals of defining your own type using keyword class
that enables you to encapsulate data attributes and methods that operate on that data.
Operator sizeof(), covered in Lesson 3, “Using Variables, Declaring Constants,” is
used to determine the memory requirement of a specific type, in bytes. This operator
is valid for classes, too, and basically reports the sum of bytes consumed by each data
attribute contained within the class declaration. Depending on the compiler you use,
sizeof() might or might not include padding for certain attributes on word boundaries.










## Class File Locations
When you divide the class, you put part in the header file and part in the
source code file. The following list describes what goes where:
✦ Header file: Put the class definition in the header file. You can include
the function code inside the class definition itself if it’s a short function.
Most people prefer not to put any function code longer than a line or
two in the header — in fact, many don’t put any function code at all in
the header. You may want to name the header file the same as the class
but with an .h or .hpp extension. Thus, the class Pen, for instance,
might be in the file Pen.h.
✦ Source file: If your class has member functions, and you did not put the
code in the class definition, you need to put the code in a source file.
When you do, precede the function name with the class name and two
colons. (Do not put any spaces between the two colons, but you can put
spaces on either side of the pair of colons.) If you named the header file
the same as the class, you probably want to name the source file the
same as the class as well but with a .cpp or .cc extension.






How struct Differs from class
struct is a keyword from the days of C, and for all practical purposes it is treated by a
C++ compiler similarly to a class. The exceptions are applicable to the access specifiers
(public and private) when the programmer has not specified any. Unless specified,
members in a struct are public by default (private for a class), and unless specified, a struct features public inheritance from a base struct (private for a class).

A struct variant of class Human from Listing 9.13 would be the following:
struct Human
{
// constructor, public by default (as no access specified is mentioned)
Human(const MyString& humansName, int humansAge, bool humansGender)
: name(humansName), age (humansAge), Gender(humansGender) {}int GetAge ()
{
return age;
}
private:
int age;
bool gender;
MyString name;
};
As you can see, a struct Human is similar to class Human, and instantiation of an
object of type struct would be similar to type class as well:
Human firstMan("Adam", 25, true); // an instance of struct Human











Friend Function

A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not member functions.

A friend can be a function, function template, or member function, or a class or class template, in which case the entire class and all of its members are friends.

To declare a function as a friend of a class, precede the function prototype in the class definition with keyword friend as follows −

class Box {
   double width;

   public:
      double length;
      friend void printWidth( Box box );
      void setWidth( double wid );
};

To declare all member functions of class ClassTwo as friends of class ClassOne, place a following declaration in the definition of class ClassOne −

friend class ClassTwo;

Consider the following program −
Live Demo

#include <iostream>

using namespace std;

class Box {
   double width;

   public:
      friend void printWidth( Box box );
      void setWidth( double wid );
};

// Member function definition
void Box::setWidth( double wid ) {
   width = wid;
}

// Note: printWidth() is not a member function of any class.
void printWidth( Box box ) {
   /* Because printWidth() is a friend of Box, it can
   directly access any member of this class */
   cout << "Width of box : " << box.width <<endl;
}

// Main function for the program
int main() {
   Box box;

   // set box width without member function
   box.setWidth(10.0);

   // Use friend function to print the wdith.
   printWidth( box );

   return 0;
}

Declaring a friend of a class
A class does not permit external access to its data members and methods that are
declared private. This rule is waived for classes and functions that are disclosed as
friend classes or functions, using keyword friend

#include <iostream>
 #include <string>
 using namespace std;

 class Human
 {
 private:
 friend class Utility;
 friend void DisplayAge(const Human& person);
 string name;
 int age;

 public:
 Human(string humansName, int humansAge)
 {
 name = humansName;
 age = humansAge;
 }
 };

 class Utility {
  public:
  static void DisplayAge(const Human& person)
  {
  cout << person.age << endl;
  }
  };

 void DisplayAge(const Human& person)
 {
 cout << person.age << endl;
 }23
 int main()
 {
 Human firstMan("Adam", 25);
 cout << "Accessing private member age via friend function ";
 DisplayAge(firstMan);

 return 0;
 }






Using Aggregate Initialization on Classes
and Structs
The following initialization syntax is called an aggregate initialization syntax:
Type objectName = {argument1, …, argumentN};
Alternatively, since C++11:
Type objectName {argument1, …, argumentN};
Aggregate initialization can be applied to an aggregate, and therefore it is important to
understand what data types fall under this category.
You already saw examples of aggregate initialization in the initialization of arrays in
Lesson 4, “Managing Arrays and Strings.”
int myNums[] = { 9, 5, -1 }; // myNums is int[3]
char hello[6] = { 'h', 'e', 'l', 'l', 'o', ' \0' };The term aggregate, however, is not limited to arrays of simple types like integers or
characters, but extends also to classes (and therefore structs and unions) too. There are
restrictions imposed by the standard on the specification of a struct or a class that
can be called an aggregate. These restrictions get nuanced depending on the version of
C++ standard that you refer to. Yet, it can be safely said that classes/structs that comprise public and non-static data members, contain no private or protected data members,
contain no virtual member functions, feature none or only public inheritance (that is, no
private, protected, or virtual inheritance), and no user-defined constructors are aggregates
too and can be initialized as one.

Thus, the following struct fulfills the prerequisites of being an aggregate and hence,
can be initialized as one:
struct Aggregate1
{
int num;
double pi;
};
Initialization:
Aggregate1 a1{ 2017, 3.14 };
Another example:
struct Aggregate2
{
int num;
char hello[6];
int impYears[5];
};
Initialization:
Aggregate2 a2 {42, {'h', 'e', 'l', 'l', 'o'}, {1998, 2003, 2011, 2014, 2017}};













constexpr with Classes and Objects
constexpr offers a powerful way to improve the performance of your C++ application. By marking functions that
operate on constants or const-expressions as constexpr, we are instructing the compiler to evaluate those functions and insert their result instead of inserting instructions
that compute the result when the application is executed. This keyword can also be used
with classes and objects that evaluate as constants as demonstrated by Listing 9.18. Note
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

Structures
The first step in building a new type is often to organize the elements it needs into a data structure, a struct:

struct [structure tag] {
   member definition;
   member definition;
   ...
   member definition;
} [one or more structure variables];  


Pointers to Structures

You can define pointers to structures in very similar way as you define pointer to any other variable as follows −

struct Books *struct_pointer;

Now, you can store the address of a structure variable in the above defined pointer variable. To find the address of a structure variable, place the & operator before the structure's name as follows −

struct_pointer = &Book1;

To access the members of a structure using a pointer to that structure, you must use the -> operator as follows −

struct_pointer->title;


The typedef Keyword

There is an easier way to define structs or you could "alias" types you create. For example −

typedef struct {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Books;

Now, you can use Books directly to define variables of Books type without using struct keyword. Following is the example −

Books Book1, Book2;




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







Unions
A union is a special class type where only one of the non-static data members is active at a time.

A union is a struct in which all members are allocated at the same address so that the union occupies only as much space as its largest member. Naturally, a union can hold a value for only one
member at a time.

Declaring a Union
A union is declared using keyword union, followed by the name of the union and its data members within braces:
 union UnionName
 {
 Type1 member1;
 Type2 member2;
 …
 TypeN memberN;
 };You would instantiate and use a union like this:
 UnionName unionObject;
 unionObject.member2 = value; // choose member2 as the active member
 Similar to the struct, the members of a union are public by
 default. Unlike a struct, however, unions cannot be used in
 inheritance hierarchies.
 Additionally, the sizeof() a union is always fixed as the size of
 the largest member contained in the union—even if that member were inactive in an instance of the union.

 Where Would You Use a union?
Often a union is used as a member of a struct to model a complex data type. In some
implementations, the ability of a union to interpret the fixed memory space as another
type is used for type conversions or memory reinterpretation—a practice that is controversial and not necessary given alternatives.






Classes

Having the data specified separately from the operations on it has advantages, such as the ability to use the data in arbitrary ways. However, a tighter connection between the representation and the
operations is needed for a user-defined type to have all the properties expected of a ‘‘real type.’’ In
particular, we often want to keep the representation inaccessible to users so as to ease use, guarantee consistent use of the data, and allow us to later improve the representation. To do that we have
to distinguish between the interface to a type (to be used by all) and its implementation (which has
access to the otherwise inaccessible data). The language mechanism for that is called a class. A
class has a set of members, which can be data, function, or type members. The interface is defined
by the public members of a class, and private members are accessible only through that interface.
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

Here, the representation of a Vector (the members elem and sz) is accessible only through the
interface provided by the public members: Vector(), operator[](), and siz e(). The read_and_sum()
example from §2.2 simplifies to:
double read_and_sum(int s)
{
Vector v(s); // make a vector of s elements
for (int i=0; i!=v.siz e(); ++i)
cin>>v[i]; // read into elements
double sum = 0;
for (int i=0; i!=v.siz e(); ++i)
sum+=v[i]; // take the sum of the elements
return sum;
}



Declaring a Class
You declare a class

class ClassName{
  type attribute name;

  type methodName(){};
};

class member methods and attributes work much like java

The keyword class, creates a data type that encapsulates member attributes and functions

Creating an object of type class Human is similar to creating an instance of another type, say double:
double pi= 3.1415; // a variable of type double
Human firstMan; // firstMan: an object of class Human

Alternatively, you would dynamically create an instance of class Human using new as you would for another type, say an int:
int* pointsToNum = new int; // an integer allocated dynamically
delete pointsToNum; // de-allocating memory when done using
Human* firstWoman = new Human(); // dynamically allocated Human
delete firstWoman; // de-allocating memory

Access members using the dot operator

If you have a pointer firstWoman to an instance of class Human, you can either use
the pointer operator (->) to access members, or use the
indirection operator (*) to reference the object following the dot operator.
Human* firstWoman = new Human();
(*firstWoman).IntroduceSelf();

If an object has been instantiated on the free store using new or if you have a pointer
to an object, then you use the pointer operator (->) to access the member attributes and
functions:
Human* firstWoman = new Human();
firstWoman->dateOfBirth = "1970";
firstWoman->IntroduceSelf();
delete firstWoman;

What is a better way to access members: using the dot operator (.) or using
the pointer operator (->)?
A If you have a pointer to an object, the pointer operator would be best suited. If you
have instantiated an object as a local variable on the stack, then the dot operator is best suited.




C++ inline function is powerful concept that is commonly used with classes. If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time.

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




Keywords public and private
Information can be classified into at least two categories: data that we don’t mind the
public knowing and data that is private.
C++ enables you to model class attributes and methods as public or private. Public class
members can be used by anyone in possession of an object of the class. Private classmembers can be used only within the class

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

Constructors
A constructor is a special function (or method) invoked during the instantiation of a class
to construct an object. Just like functions, constructors can also be overloaded.
Declaring and Implementing a Constructor
A constructor is a special function that takes the name of the class and returns no value.
So, class Human would have a constructor that is declared like this:
class Human
{
public:
Human(); // declaration of a constructor
};
This constructor can be implemented either inline within the class or externally outside
the class declaration. An implementation (also called definition) inside the class looks
like this:
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
:: is called the scope resolution operator. For example,
Human::dateOfBirth is referring to variable dateOfBirth
declared within the scope of class Human. ::dateOfBirth, on
the other hand would refer to another variable dateOfBirth in a
global scope.

A constructor that is invoked without arguments is called the
default constructor. Programming a default constructor is
optional.
If you don’t program any constructor the
compiler creates one for you (that constructs member attributes
but does not initialize Plain Old Data types such as int to any
specific non-zero value).

You can choose to not implement the default constructor to
enforce object instantiation with certain minimal parameters

Constructors can be overloaded just like functions.
Constructor parameters can be given default values.

Note that a default constructor is one that can be instantiated
without arguments, and not necessarily one that doesn’t take
parameters. So a constructor with two parameters, both with
default values, is a default constructor


Another
way to initialize members is by using initialization lists.

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

Thus, the initialization list is characterized by a colon (:) following the parameter
declaration contained in parentheses (…), followed by an individual member variable
and the value it is initialized to. This initialization value can be a parameter such as
humansName or can even be a fixed value. Initialization lists can also be useful in
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



Destructor
A destructor, like a constructor, is a special function, too. A constructor is invoked
at object instantiation, and a destructor is automatically invoked when an object is
destroyed.Declaring and Implementing a Destructor
The destructor looks like a function that takes the name of the class, yet has a tilde (~)
preceding it. So, class Human would have a destructor that is declared like this:
class Human
{
~Human(); // declaration of a destructor
};
This destructor can either be implemented inline in the class or externally outside the
class declaration. An implementation or definition inside the class looks like this:
class Human
{
public:
~Human()
{
// destructor code here
}
};
A variant enabling you to define the destructor outside the class’s declaration looks like
this:
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

A destructor is always invoked when an object of a class is destroyed when it goes out of
scope or is deleted via delete. This property makes a destructor the ideal place to reset
variables and release dynamically allocated memory and other resources.

A destructor cannot be overloaded. A class can have only one
destructor. If you forget to implement a destructor, the compiler
creates and invokes a dummy destructor, that is, an empty one
(that does no cleanup of dynamically allocated memory).



Shallow Copying and Associated Problems
Classes that contain a pointer member buffer that
points to dynamically allocated memory, allocated in the constructor using new and deallocated in the destructor using delete[].

When an object of this class is copied, the
pointer member is copied, but not the pointed memory, resulting in two objects pointing
to the same dynamically allocated buffer in memory. When an object is destructed,
delete[] deallocates the memory, thereby invalidating the pointer copy held by the
other object. Such copies are shallow and are a threat to the stability of the program



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
We were introduced to constexpr in Lesson 3, where we learned that it offers a powerful way to improve the performance of your C++ application. By marking functions that
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

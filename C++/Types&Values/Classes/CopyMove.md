

The copy constructor is a constructor which creates an object by initializing it with an object of the same class, which has been created previously. The copy constructor is used to −

    Initialize one object from another of the same type.
    Copy an object to pass it as an argument to a function.
    Copy an object to return it from a function.

If a copy constructor is not defined in a class, the compiler itself defines one.If the class has pointer variables and has some dynamic memory allocations, then it is a must to have a copy constructor. The most common form of copy constructor is shown here −

classname (const classname &obj) {
   // body of constructor
}

Here, obj is a reference to an object that is being used to initialize another object.
Live Demo

#include <iostream>

using namespace std;

class Line {

   public:
      int getLength( void );
      Line( int len );             // simple constructor
      Line( const Line &obj);  // copy constructor
      ~Line();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
Line::Line(int len) {
   cout << "Normal constructor allocating ptr" << endl;

   // allocate memory for the pointer;
   ptr = new int;
   *ptr = len;
}

Line::Line(const Line &obj) {
   cout << "Copy constructor allocating ptr." << endl;
   ptr = new int;
   *ptr = *obj.ptr; // copy the value
}

Line::~Line(void) {
   cout << "Freeing memory!" << endl;
   delete ptr;
}

int Line::getLength( void ) {
   return *ptr;
}

void display(Line obj) {
   cout << "Length of line : " << obj.getLength() <<endl;
}

// Main function for the program
int main() {
   Line line(10);

   display(line);

   return 0;
}

When the above code is compiled and executed, it produces the following result −

Normal constructor allocating ptr
Copy constructor allocating ptr.
Length of line : 10
Freeing memory!
Freeing memory!

Let us see the same example but with a small change to create another object using existing object of the same type −
Live Demo

#include <iostream>

using namespace std;

class Line {
   public:
      int getLength( void );
      Line( int len );             // simple constructor
      Line( const Line &obj);  // copy constructor
      ~Line();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
Line::Line(int len) {
   cout << "Normal constructor allocating ptr" << endl;

   // allocate memory for the pointer;
   ptr = new int;
   *ptr = len;
}

Line::Line(const Line &obj) {
   cout << "Copy constructor allocating ptr." << endl;
   ptr = new int;
   *ptr = *obj.ptr; // copy the value
}

Line::~Line(void) {
   cout << "Freeing memory!" << endl;
   delete ptr;
}

int Line::getLength( void ) {
   return *ptr;
}

void display(Line obj) {
   cout << "Length of line : " << obj.getLength() <<endl;
}

// Main function for the program
int main() {

   Line line1(10);

   Line line2 = line1; // This also calls copy constructor

   display(line1);
   display(line2);

   return 0;
}

When the above code is compiled and executed, it produces the following result −

Normal constructor allocating ptr
Copy constructor allocating ptr.
Copy constructor allocating ptr.
Length of line : 10
Freeing memory!
Copy constructor allocating ptr.
Length of line : 10
Freeing memory!
Freeing memory!
Freeing memory!













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

The copy constructor has ensured deep copy in cases such as
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

an improved MyString that implements the
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









For classes with pointer member variables, three things are normally done:
1. Include the destructor in the class.
2. Overload the assignment operator for the class.
3. Include the copy constructor.

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

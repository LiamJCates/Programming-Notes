We can define class members static using static keyword.

A class can contain static members, either data or functions.

static members solve the problem of: “how do you make a compile-time constant inside a class?”

The static keyword, in this
situation, means “there’s only one instance, regardless of how
many objects of the class are created,” which is precisely what we
need here: a member of a class which is constant, and which cannot
change from one object of the class to another. Thus, a static const
of a built-in type can be treated as a compile-time constant.

There is one feature of static cons when used inside classes which t
is a bit unusual: you must provide the initializer at the point of
definition of the static cons. This is something that only occurs t
with the static cons; as much as you might like to use it in other t
situations it won’t work because all other data members must be
initialized in the constructor or in other member functions.

### Static Data Members
A static data member of a class is also known as a "class variable", because there is only one common variable for all the objects of that same class, sharing the same value: i.e., its value is not different from one object of this class to another.

When we declare a data member of a class as static it means no matter how many objects of the class are created, there is only one copy of the static member.

Because it is a common variable value for all the objects of the same class, it can be referred to as a member of any object of that class or even directly by the class name (of course this is only valid for static members).

cout << objectName.n;
cout << ClassName::n;

These two calls above are referring to the same variable: the static variable n within ClassName shared by all objects of this class.

In fact, static members have the same properties as non-member variables but they enjoy class scope. For that reason, and to avoid them to be declared several times, they cannot be initialized directly in the class, but need to be initialized somewhere outside it.

All static data is initialized to zero when the first object is created, if no other initialization is present.

While static members are declared inside the class, you must define static data members outside the class. Static members are initialized outside the class as done in the following example by redeclaring the static variable, using the scope resolution operator :: to identify which class it belongs to.



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

Output:
Constructor called.
Constructor called.
Total objects: 2



### Static Function Members
Classes can also have static member functions. These represent the same: members of a class that are common to all object of that class, acting exactly as non-member functions but being accessed like members of the class.

By declaring a function member as static, you make it independent of any particular object of the class. A static member function can be called even if no objects of the class exist and the static functions are accessed using only the class name and the scope resolution operator ::.

Because they are like non-member functions, they cannot access non-static members of the class (neither member variables nor member functions). They neither can use the keyword this.

A static member function can only access static data members, other static member functions, and any other functions defined at a higher scope, outside the class.

Static member functions have a class scope and they do not have access to the this pointer of the class. You could use a static member function to determine whether some objects of the class have been created or not.

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



### Singleton Class That Permits a Single Instance

The concept of singleton that uses private constructors, a private assignment operator, and a static instance member to create this (controversially) powerful pattern.

When the keyword static is used on a class’s data member, it ensures that the member is shared across all instances. When static is used on a local variable declared within the
scope of a function, it ensures that the variable retains its value
between function calls.
When static is used on a member function—a method—the
method is shared across all instances of the class.

Use the singleton pattern only where absolutely necessary, keeping future growth of the application and its features in perspective. Note that the very feature that it restricts creation of multiple instances can become an architectural bottleneck when a use case comes up that needs multiple instances of the class.



### Class That Prohibits Instantiation on the Stack
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

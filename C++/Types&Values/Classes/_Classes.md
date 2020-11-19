Classes
POD classes contain only data members, and sometimes that’s all you want from a class. However, designing a program using only PODs can create a lot of complexity. You can fight such complexity with abstraction by placing related functions and data together.

This helps to simplify code in at least two ways.

First, you can put related code in one place, which helps you to reason about your program. You can understand how a code segment works because it describes in one place both program state and how your code modifies that state.

Second, when you bundle class’s code and data you can abstract the implementation for use by the rest of your program. Rather than having users interact with class data directly, the programmer can provide functionality which simplifies these operations for the user, this is known as providing an interface.


Having the data specified separately from the operations on it has advantages, such as the ability to use the data in arbitrary ways. However, a tighter connection between the representation and the operations is needed for a user-defined type to have all the properties expected of a ‘‘real type.’’


### Concrete Types
The basic idea of concrete classes is that they behave ‘‘just like built-in types.’’ For example, a complex number type and an infinite-precision integer are much like built-in int, except of course that they have their own semantics and sets of operations.

The defining characteristic of a concrete type is that its representation is part of its definition, and that representation is present in each object of a concrete class. That allows implementations to be optimally efficient in time and space.

In particular, it allows us to:
• place objects of concrete types on the stack, in statically allocated memory, and in other objects
• refer to objects directly (and not just through pointers or references);
• initialize objects immediately and completely (e.g., using constructors;
• copy and move objects



## The class Keyword
You can replace the struct keyword with the class keyword, which declares members private by default. Aside from default access control, classes declared with the struct and class keywords are the same.

The keyword class, creates a data type that encapsulates member attributes and functions

### Declaring a Class

class ClassName{
  type attribute name;

  type methodName(){};

  class NestedClass{};
};

A class has a set of members, which can be data, function, or type members.

Attributes
Attributes are a classes' data members.
Attribute values are initialized using a special method called a constructor.

Methods
Methods are a classes' member functions. They create an explicit connection among a class, its data members, and some code. Defining a method is as simple as adding a function to a class definition. Methods have access to all of a class’s members.

Member Types
Classes can have member types or nested types (including type aliases).





### Accessing Class Members
Once an object of a class is declared, it can access the members of the class. The general syntax for an object to access a member of a class is:
classObjectName.memberName

The class members that a class object can access depend on where the object is declared.
? If the object is declared in the definition of a member function of the class, then the object can access both the public and private members.
? If the object is declared elsewhere (for example, in a user’s program), then the object can access only the public members of the class.

Recall that in C11, the dot, . (period), is an operator called the member access
operator.




Once a class is properly defined and implemented, it can be used in a program. A program
or software that uses and manipulates the objects of a class is called a client of that class.









## Creating Instances
Creating an object of type class Human is similar to creating an instance of another type, say double:
double pi= 3.1415; // a variable of type double
Human firstMan; // firstMan: an object of class Human

Alternatively, you would dynamically create an instance of class Human using new as you would for another type, say an int:
int* pointsToNum = new int; // an integer allocated dynamically
delete pointsToNum; // de-allocating memory when done using
Human* firstWoman = new Human(); // dynamically allocated Human
delete firstWoman; // de-allocating memory



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

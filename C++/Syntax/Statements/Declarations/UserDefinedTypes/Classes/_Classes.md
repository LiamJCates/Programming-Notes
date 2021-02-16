Classes

POD classes contain only data members, and sometimes that’s all you want from a class. However, designing a program using only PODs can create a lot of complexity. You can fight such complexity with abstraction, by placing related functions and data together and providing a user friendly interface for the clients of a class.

Classes expand POD structures. Like POD structures, they can contain data members, but they can also contain user defined member functions.

This helps to simplify code in at least two ways.

First, you can put related code in one place, which helps you to reason about your program. You can understand how a code segment works because it describes in one place both program state and how your code modifies that state.

Second, when you bundle class’s code and data you can abstract the implementation for use by the rest of your program. Rather than having users interact with class data directly, the programmer can provide functionality which simplifies these operations for the user, this is known as providing an interface.

Having the data specified separately from the operations on it has advantages, such as the ability to use the data in arbitrary ways. However, a tighter connection between the representation and the operations is needed for a user-defined type to have all the properties expected of a ‘‘real type.’’




## The class Keyword

You can replace the struct keyword with the class keyword, which declares members private by default. Aside from default access control, classes declared with the struct keyword and those declared with the class keyword are basically the same.

### Declaring a Class

Classes are defined using either keyword class or keyword struct, with the following syntax:

  class class_name {
    access_specifier_1:
      member1;
    access_specifier_2:
      member2;
    ...
  } object_names;

Where class_name is a valid identifier for the class, object_names is an optional list of names for objects of this class. The body of the declaration contains its member list.

Classes have the same format as plain data structures, except that their members can also include methods, types, and access specifiers.

Attributes
Attributes are a classes' data members.

Methods
Methods are a classes' member functions. They create an explicit connection among a class, its data members, and some code. Defining a method is as simple as adding a function to a class definition. Methods have access to all of a class’s members.

Member Types
Classes can have member types which are enumerations, nested types and type aliases.



### Member List

An optional member list declares subobjects called class members.

The member list follows the class name and is placed between braces.

A member list is the only place where you can declare class members and you may not declare a member twice in a member list. Class members can be data, functions, and member types.

You may declare a nested class, a member class template, or a member function, and define it outside the class.

You may declare a data member or member function as static but not auto, extern, or register.

The enumerators of a enumeration defined in a class member list are also members of the class.

Nonstatic members that are class objects must be objects of previously defined classes; a class A cannot contain an object of class A, but it can contain a pointer or reference to an object of class A.

You must specify all dimensions of a nonstatic array member.




### Classes defined with struct and union

Classes can be defined not only with keyword class, but also with keywords struct and union.

The keyword struct, generally used to declare plain data structures, can also be used to declare classes that have member functions, with the same syntax as with keyword class. The only difference between both is that members of classes declared with the keyword struct have public access by default, while members of classes declared with the keyword class have private access by default. For all other purposes both keywords are equivalent in this context.

Conversely, the concept of unions is different from that of classes declared with struct and class, since unions only store one data member at a time, but nevertheless they are also classes and can thus also hold member functions. The default access in union classes is public.




### Creating Instances

A program or software that uses and manipulates the objects of a class is called a client of that class.

Creating an object of type class is similar to creating an instance of another type, say double:

  double pi;        // a variable of type double
  Human firstMan;   // an object of class Human

Alternatively, you would dynamically create an instance of class Human using new as you would for another type, say an int:

  int* pointsToNum = new int;         // an integer allocated dynamically
  delete pointsToNum;                 // de-allocating memory when done using
  Human* firstWoman = new Human();    // dynamically allocated Human
  delete firstWoman;                  // de-allocating memory




### Accessing Class Members

Once an object of a class is declared, it can access the members of the class using member access operators . and -> .

The general syntax for an object to access a member of a class is:

  classObjectName.memberName

As with structs, when we have a pointer to a class instance we can use the member of pointer operator, ->:

  Object* class_name;
  classname -> member;




### General Steps to Using Objects
1 Declare the pointer:                        Pen *MyPen;
2 Calls new to create the object:             MyPen = new Pen;
3 Accesses object pointer member:             MyPen->InkColor = red;
4 Delete the object:                          delete MyPen;
5 Clears the pointer:                         MyPen = 0;



### sizeof() a Class
Operator sizeof() is used to determine the memory requirement of a specific type, in bytes. This operator is valid for classes, too, and basically reports the sum of bytes consumed by each data attribute contained within the class declaration.

Depending on the compiler you use, sizeof() might or might not include padding for certain attributes on word boundaries.

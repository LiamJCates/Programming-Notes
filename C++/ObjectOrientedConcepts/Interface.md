Interfaces

An interface describes the behavior or capabilities of a C++ class without committing to a particular implementation of that class.

The C++ interfaces are implemented using abstract classes and these abstract classes should not be confused with data abstraction which is a concept of keeping implementation details separate from associated data.

A class is made abstract by declaring at least one of its functions as pure virtual function. A pure virtual function is specified by placing "= 0" in its declaration:

The purpose of an abstract class (often referred to as an ABC) is to provide an appropriate base class from which other classes can inherit. Abstract classes cannot be used to instantiate objects and serves only as an interface. Attempting to instantiate an object of an abstract class causes a compilation error.

Thus, if a subclass of an ABC needs to be instantiated, it has to implement each of the virtual functions, which means that it supports the interface declared by the ABC. Failure to override a pure virtual function in a derived class, then attempting to instantiate objects of that class, is a compilation error.

Classes that can be used to instantiate objects are called concrete classes.

Abstract Class Example

Designing Strategy

An object-oriented system might use an abstract base class to provide a common and standardized interface appropriate for all the external applications. Then, through inheritance from that abstract base class, derived classes are formed that operate similarly.

The capabilities (i.e., the public functions) offered by the external applications are provided as pure virtual functions in the abstract base class. The implementations of these pure virtual functions are provided in the derived classes that correspond to the specific types of the application.

This architecture also allows new applications to be added to a system easily, even after the system has been defined.














Interfaces
In software engineering, an interface is a shared boundary that contains no
data or code. It defines function signatures that all implementations of the
interface agree to support. An implementation is code or data that declares
support for an interface. You can think of an interface as a contract between
classes that implement the interface and users (also called consumers) of that
class.
Consumers know how to use implementations because they know
the contract. In fact, the consumer never needs to know the underlying
implementation type.

Interfaces impose stringent requirements. A consumer of an interface
can use only the methods explicitly defined in the interface.

Interfaces promote highly reusable and loosely coupled code. You can
understand the notation for specifying an interface, but you’ll need to
know a bit about object composition and implementation inheritance.

Object Composition and Implementation Inheritance
Object composition is a design pattern where a class contains members of
other class types. An alternate, antiquated design pattern called implementation inheritance achieves runtime polymorphism. Implementation
inheritance allows you to build hierarchies of classes; each child inherits
functionality from its parents. Over the years, accumulated experience
with implementation inheritance has convinced many that it’s an antipattern. For example, Go and Rust—two new and increasingly popular
system­-programming languages—have zero support for implementation
inheritance. A brief discussion of implementation inheritance is warranted
for two reasons:
•	 You might encounter it infecting legacy code.
•	 The quirky way you define C++ interfaces has a shared lineage with
implementation inheritance, so you’ll be familiar with the mechanics
anyway

Defining Interfaces
Unfortunately, there’s no interface keyword in C++. You have to define
interfaces using antiquated inheritance mechanisms.

you’ll need to understand the virtual keyword, the virtual destructor, the =0 suffix and pure-­virtual methods, base class inheritance, and the override keyword.
Once you understand these, you’ll know how to define an interface.


You declare derived classes using the following syntax:
struct DerivedClass : BaseClass {
--snip--
};

Derived classes are declared just like any other class. The benefit is
that you can treat derived class references as if they were of base class reference type.

struct BaseClass {};
struct DerivedClass : BaseClass {};
void are_belong_to_us(BaseClass& base) {}
void all_about_that(DerivedClass& derived) {}

int main() {
  DerivedClass derived;
  are_belong_to_us(derived);  //Fine
  BaseClass base;
all_about_that(base);         //Trouble
}

The DerivedClass derives from BaseClass. The are_belong_to_us function takes a reference­to­BaseClass argument base. You can invoke it with an instance of a DerivedClass because DerivedClass derives from BaseClass.

The opposite is not true.
Here, BaseClass doesn’t derive from DerivedClass. (The inheritance
relationship is the other way around.) The all_about_that function takes a
DerivedClass argument. When you attempt to invoke all_about_that with a
BaseClass, the compiler yields an error.


Member Inheritance
Derived classes inherit non­private members from their base classes. Classes
can use inherited members just like normal members. The supposed benefit of member inheritance is that you can define functionality once in a
base class and not have to repeat it in the derived classes.

Unfortunately, experience has convinced many in the programming community to avoid member inheritance because it can easily yield brittle, hard­ to­ reason ­about code compared to composition ­based polymorphism. (This is why so many
modern programming languages exclude it.)


virtual Methods
If you want to permit a derived class to override a base class’s methods, you
use the virtual keyword. By adding virtual to the beginning of a method’s definition, you declare that a derived class’s implementation should be used if one is supplied. Within the implementation, you add the override keyword to the
method’s declaration.

If you want to require a derived class to implement the method, you can
append the =0 suffix to a method definition. You call methods with both
the virtual keyword and =0 suffix pure virtual methods. You can’t instantiate a class containing any pure virtual methods.

struct BaseClass {
  virtual return_type function_name() =0;
};

struct DerivedClass : BaseClass {
  const char* final_message() override
  {
    return "We apologize for the inconvenience.";
  }
};

The =0 suffix specifies a pure virtual method, meaning you can’t
instantiate a BaseClass—only derive from it. DerivedClass still derives from
BaseClass, and you provide the requisite final_message. Attempting to
instantiate a BaseClass would result in a compiler error. Both DerivedClass
and the BaseClass reference behave as before.

Virtual functions can incur runtime overhead, although the cost is typically low (within 25 percent of a regular function call). The compiler generates virtual function tables (vtables) that contain function pointers. At runtime, a consumer of an interface doesn’t generally know its underlying type, but it knows how to invoke the interface’s methods (thanks to the vtable). In some circumstances, the linker can detect all uses of an interface and devirtualize a function call. This removes the function call from the vtable and thus eliminates associated runtime cost.

Pure-Virtual Classes and Virtual Destructors
You achieve interface inheritance through deriving from base classes that
contain only pure­virtual methods. Such classes are referred to as pure-virtual
classes. In C++, interfaces are always pure­virtual classes. Usually, you add
virtual destructors to interfaces. In some rare circumstances, it’s possible to
leak resources if you fail to mark destructors as virtual.

#include <cstdio>
struct BaseClass {};
struct DerivedClass : BaseClass {
DerivedClass() {
printf("DerivedClass() invoked.\n");
}
~DerivedClass() {
printf("~DerivedClass() invoked.\n");
}
};
int main() {
printf("Constructing DerivedClass x.\n");
BaseClass* x{ new DerivedClass{} };
printf("Deleting x as a BaseClass*.\n");
delete x;
}

Here you see a DerivedClass deriving from BaseClass. This class has a
constructor and destructor that print when they’re invoked. Within main, you allocate and initialize a DerivedClass with new and set the result to a BaseClass pointer. When you delete the pointer, the BaseClass destructor
gets invoked, but the DerivedClass destructor doesn’t!

Adding virtual to the BaseClass destructor solves the problem

#include <cstdio>
struct BaseClass {
virtual ~BaseClass() = default;
};
struct DerivedClass : BaseClass {
DerivedClass() {
printf("DerivedClass() invoked.\n");
}
~DerivedClass() {
printf("~DerivedClass() invoked.\n");
}
};
int main() {
printf("Constructing DerivedClass x.\n");
BaseClass* x{ new DerivedClass{} };
printf("Deleting x as a BaseClass*.\n");
delete x;
}

Adding the virtual destructor causes the DerivedClass destructor to
get invoked when you delete the BaseClass pointer, which results in the
DerivedClass destructor printing the message.
Declaring a virtual destructor is optional when declaring an interface,
but beware. If you forget that you haven’t implemented a virtual destructor
in the interface and accidentally do something like the previous example, you can leak resources, and the compiler won’t warn you.

NOTE
Declaring a protected non-virtual destructor is a good alternative to declaring a public virtual destructor because it will cause a compilation error when writing code that deletes a base class pointer. Some don’t like this approach because you eventually have to make a class with a public destructor, and if you derive from that class, you run into the same issues.

Implementing Interfaces
To declare an interface, declare a pure virtual class. To implement an interface, derive from it. Because the interface is pure virtual, an implementation must implement all of the interface’s methods.144 Chapter 5
It’s good practice to mark these methods with the override keyword.
This communicates that you intend to override a virtual function, allowing
the compiler to save you from simple mistakes.




Using Interfaces
As a consumer, you can only deal in references or pointers to interfaces.
The compiler cannot know ahead of time how much memory to allocate for
the underlying type: if the compiler could know the underlying type, you
would be better off using templates.

There are two options for how to set the member:
Constructor injection With constructor injection, you typically use an
interface reference. Because references cannot be reseated, they won’t
change for the lifetime of the object.

Property injection With property injection, you use a method to set
a pointer member. This allows you to change the object to which the
member points.
You can combine these approaches by accepting an interface pointer
in a constructor while also providing a method to set the pointer to something else.
Typically, you’ll use constructor injection when the injected field won’t
change throughout the lifetime of the object. If you need the flexibility of
modifying the field, you’ll provide methods to perform property injection.

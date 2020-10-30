A class hierarchy is a set of
classes ordered in a lattice created by derivation (e.g., : public). We use class hierarchies to represent concepts that have hierarchical relationships, such as ‘‘A fire engine is a kind of a truck which
is a kind of a vehicle’’

Benefits from Hierarchies
A class hierarchy offers two kinds of benefits:
• Interface inheritance: An object of a derived class can be used wherever an object of a base
class is required. That is, the base class acts as an interface for the derived class. The Container and Shape classes are examples. Such classes are often abstract classes.
• Implementation inheritance: A base class provides functions or data that simplifies the
implementation of derived classes. Smiley’s uses of Circle’s constructor and of Circle::draw()
are examples. Such base classes often have data members and constructors.
Concrete classes – especially classes with small representations – are much like built-in types: we
define them as local variables, access them using their names, copy them around, etc. Classes in
class hierarchies are different: we tend to allocate them on the free store using new, and we access
them through pointers or references.



Hierarchy Navigation
The read_shape() function returns Shape∗ so that we can treat all Shapes alike. However, what can
we do if we want to use a member function that is only provided by a particular derived class, such
as Smiley’s wink()? We can ask ‘‘is this Shape a kind of Smiley?’’ using the dynamic_cast operator:
Shape∗ ps {read_shape(cin)};
if (Smiley∗ p = dynamic_cast<Smiley∗>(ps)) { // ... does ps point to a Smiley? ...
// ... a Smiley; use it
}
else {
// ... not a Smiley, try something else ...
}
If at run time the object pointed to by the argument of dynamic_cast (here, ps) is not of the expected
type (here, Smiley) or a class derived from the expected type, dynamic_cast returns nullptr.
We use dynamic_cast to a pointer type when a pointer to an object of a different derived class is
a valid argument. We then test whether the result is nullptr. This test can often conveniently be
placed in the initialization of a variable in a condition.
When a different type is unacceptable, we can simply dynamic_cast to a reference type. If the
object is not of the expected type, dynamic_cast throws a bad_cast exception:
Shape∗ ps {read_shape(cin)};
Smiley& r {dynamic_cast<Smiley&>(∗ps)}; // somewhere, catch std::bad_cast
Code is cleaner when dynamic_cast is used with restraint. If we can avoid using type information,62 Classes Chapter 4
we can write simpler and more efficient code, but occasionally type information is lost and must be
recovered. This typically happens when we pass an object to some system that accepts an interface
specified by a base class. When that system later passes the object back to us, we might have to
recover the original type. Operations similar to dynamic_cast are known as ‘‘is kind of’’ and ‘‘is
instance of’’ operations.




Polymorphism
The word polymorphism means having many forms. Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

polymorphic behavior that can be implemented in C++ via the
inheritance hierarchy, also known as subtype polymorphism.

Need for Polymorphic Behavior
In Lesson 10, “Implementing Inheritance,” you found out how Tuna and Carp inherit
public method Swim() from Fish as shown in Listing 10.1. It is, however, possible that
both Tuna and Carp provide their own Tuna::Swim() and Carp::Swim() methods
to make Tuna and Carp different swimmers. Yet, as each of them is also a Fish, if a
user with an instance of Tuna uses the base class type to invoke Fish::Swim(), he ends
up executing only the generic part Fish::Swim() and not Tuna::Swim(), even though
that base class instance Fish is a part of a Tuna.


#include <iostream>
using namespace std;

class Fish
{
public:
void Swim()
{
cout << "Fish swims! " << endl;
}
};
class Tuna:public Fish
{
public:
// override Fish::Swim
void Swim()
{
cout << "Tuna swims!" << endl;
}
};

void MakeFishSwim(Fish& inputFish)
{
// calling Fish::Swim
inputFish.Swim();
}

int main()
{
Tuna myDinner;

// calling Tuna::Swim
myDinner.Swim();

// sending Tuna as Fish
MakeFishSwim(myDinner);

return 0;
}




C++ polymorphism means that a call to a member function will cause a different function to be executed depending on the type of object that invokes the function.

Consider the following example where a base class has been derived by other two classes

#include <iostream>
using namespace std;

class Shape {
   protected:
      int width, height;

   public:
      Shape( int a = 0, int b = 0){
         width = a;
         height = b;
      }
      int area() {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape {
   public:
      Rectangle( int a = 0, int b = 0):Shape(a, b) { }

      int area () {
         cout << "Rectangle class area :" <<endl;
         return (width * height);
      }
};

class Triangle: public Shape {
   public:
      Triangle( int a = 0, int b = 0):Shape(a, b) { }

      int area () {
         cout << "Triangle class area :" <<endl;
         return (width * height / 2);
      }
};

// Main function for the program
int main() {
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   // store the address of Rectangle
   shape = &rec;

   // call rectangle area.
   shape->area();

   // store the address of Triangle
   shape = &tri;

   // call triangle area.
   shape->area();

   return 0;
}


The reason for the incorrect output is that the call of the function area() is being set once by the compiler as the version defined in the base class. This is called static resolution of the function call, or static linkage - the function call is fixed before the program is executed. This is also sometimes called early binding because the area() function is set during the compilation of the program.

But now, let's make a slight modification in our program and precede the declaration of area() in the Shape class with the keyword virtual so that it looks like this −

class Shape {
   protected:
      int width, height;

   public:
      Shape( int a = 0, int b = 0) {
         width = a;
         height = b;
      }
      virtual int area() {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};

After this slight modification, when the previous example code is compiled and executed, it produces the following result −

Rectangle class area
Triangle class area

This time, the compiler looks at the contents of the pointer instead of it's type. Hence, since addresses of objects of tri and rec classes are stored in *shape the respective area() function is called.

As you can see, each of the child classes has a separate implementation for the function area(). This is how polymorphism is generally used. You have different classes with a function of the same name, and even the same parameters, but with different implementations.
Virtual Function

A virtual function is a function in a base class that is declared using the keyword virtual. Defining in a base class a virtual function, with another version in a derived class, signals to the compiler that we don't want static linkage for this function.

What we do want is the selection of the function to be called at any given point in the program to be based on the kind of object for which it is called. This sort of operation is referred to as dynamic linkage, or late binding.


Pure Virtual Functions

It is possible that you want to include a virtual function in a base class so that it may be redefined in a derived class to suit the objects of that class, but that there is no meaningful definition you could give for the function in the base class.

We can change the virtual function area() in the base class to the following −

class Shape {
   protected:
      int width, height;

   public:
      Shape(int a = 0, int b = 0) {
         width = a;
         height = b;
      }

      // pure virtual function
      virtual int area() = 0;
};

The = 0 tells the compiler that the function has no body and above virtual function will be called pure virtual function.




Polymorphic Behavior Implemented Using Virtual
Functions

You have access to an object of type Fish, via pointer Fish* or reference Fish&. This
object could have been instantiated solely as a Fish, or be part of a Tuna or Carp
that inherits from Fish. You don’t know (and don’t care). You invoke method Swim()
using this pointer or reference, like this:
pFish->Swim();
myFish.Swim();
What you expect is that the object Fish swims as a Tuna if it is part of a Tuna, as a
Carp if it is part of a Carp, or an anonymous Fish if it wasn’t instantiated as part of
a specialized class such as Tuna or Carp. You can ensure this by declaring function
Swim() in the base class Fish as a virtual function:
class Base
{
virtual ReturnType FunctionName (Parameter List);
};
class Derived
{
ReturnType FunctionName (Parameter List);
};
Use of keyword virtual means that the compiler ensures that any overriding variant
of the requested base class method is invoked.

Need for Virtual Destructors
There is a more sinister side to the feature demonstrated by Listing 11.1—unintentionally
invoking base class functionality of an instance of type derived, when a specialization is
available. What happens when a function calls operator delete using a pointer of type
Base* that actually points to an instance of type Derived?

main() creates an instance of Tuna on the free store using new at Line 37 and
then releases the allocated memory immediately after using service function
DeleteFishMemory() at Line 39. For the sake of comparison, another instance of
Tuna is created as a local variable myDinner on the stack at Line 42 and goes out of
scope when main() ends. The output is created by the cout statements in the constructors and destructors of classes Fish and Tuna. Note that while Tuna and Fish wereboth constructed on the free store due to new, the destructor of Tuna was not invoked
during delete, rather only that of the Fish. This is in stark contrast to the construction
and destruction of local member myDinner where all constructors and destructors are
invoked. Lesson 10 demonstrated in Listing 10.7 the correct order of construction and
destruction of classes in an inheritance hierarchy, showing that all destructors need to be
invoked, including ~Tuna(). Clearly, something is amiss.
This flaw means that the destructor of a deriving class that has been instantiated on the
free store using new would not be invoked if delete is called using a pointer of type
Base*. This can result in resources not being released, memory leaks, and so on and is a
problem that is not to be taken lightly.
To avoid this problem, you use virtual destructors

the addition of keyword
virtual at Line 10 where the destructor of base class Fish has been declared. Note
that this small change resulted in the compiler essentially executing Tuna::~Tuna() in
addition to Fish::~Fish() when operator delete is invoked on Fish* that actually
points to a Tuna

Always declare the base class destructor as virtual:
class Base
{
public:
virtual ~Base() {}; // virtual destructor
};
This ensures that one with a pointer Base* cannot invoke
delete in a way that instances of the deriving classes are not
correctly destroyed.


How Do virtual Functions Work? Understanding the
Virtual Function Table

The Swim() method that needs
to be invoked is evidently a decision made at runtime, using a logic that implements
polymorphism, which is supplied by the compiler at compile-time.
Consider a class Base that declared N virtual functions:
class Base
{
public:
virtual void Func1()
{
// Func1 implementation
}
virtual void Func2()
{
// Func2 implementation
}// .. so on and so forth
virtual void FuncN()
{
// FuncN implementation
}
};
class Derived that inherits from Base overrides Base::Func2(), exposing the other
virtual functions directly from class Base:
class Derived: public Base
{
public:
virtual void Func1()
{
// Func2 overrides Base::Func2()
}
// no implementation for Func2()
virtual void FuncN()
{
// FuncN implementation
}
};
The compiler sees an inheritance hierarchy and understands that the Base defines certain
virtual functions that have been overridden in Derived. What the compiler now does is
to create a table called the Virtual Function Table (VFT) for every class that implements
a virtual function or derived class that overrides it. In other words, classes Base and
Derived get an instance of their own Virtual Function Table. When an object of these
classes is instantiated, a hidden pointer (let’s call it VFT*) is initialized to the respective
VFT. The Virtual Function Table can be visualized as a static array containing function
pointers, each pointing to the virtual function (or override) of interest

Thus, each table is comprised of function pointers, each pointing to the available implementation of a virtual function. In the case of class Derived, all except one function
pointer in its VFT point to local implementations of the virtual method in Derived.
Derived has not overridden Base::Func2(), and hence that function pointer points to
the implementation in class Base.
This means that when a user of class Derived calls
CDerived objDerived;
objDerived.Func2();
the compiler ensures a lookup in the VFT of class Derived and ensures that the
implementation Base::Func2() is invoked. This also applies to calls that use methods
that have been virtually overridden:
void DoSomething(Base& objBase)
{
objBase.Func1(); // invoke Derived::Func1
}
int main()
{
Derived objDerived;
DoSomething(objDerived);
};In this case, even though objDerived is being interpreted via objBase as an instance
of class Base, the VFT pointer in this instance is still pointing to the same table
created for class Derived. Thus, Func1() executed via this VFT is certainly
Derived::Func1().
This is how Virtual Function Tables help the implementation of (subtype) polymorphism
in C++.

This is a sample that has been stripped to the bare minimum. You see two classes,
SimpleClass and Base, that are identical in the types and number of members,
yet Base has the function DoSomething() declared as virtual (nonvirtual in
SimpleClass). The difference in adding this virtual keyword is that the compiler
generates a virtual function table for class Base and a reserved place for a pointer to the
same in Base as a hidden member. This pointer consumes the 4 extra bytes in my 32-bit
system and is the proof of the pudding.
C++ also allows you to query a pointer Base* if it is of type
Derived* using casting operator dynamic_cast and then perform conditional execution on the basis of the result of the
query.
This is called runtime type identification (RTTI) and should ideally
be avoided even though it is supported by most C++ compilers.
This is because needing to know the type of derived class object
behind a base class pointer is commonly considered poor programming practice.
RTTI and dynamic_cast are discussed in Lesson 13, “Casting
Operators.


Abstract Base Classes and Pure Virtual Functions

Types such as complex and Vector are called concrete types because their representation is part of
their definition. In that, they resemble built-in types. In contrast, an abstract type is a type that
completely insulates a user from implementation details. To do that, we decouple the interface
from the representation and give up genuine local variables.


A base class that cannot be instantiated is called an abstract base class. Such a base
class fulfills only one purpose, that of being derived from. C++ allows you to create an
abstract base class using pure virtual functions.
A virtual method is said to be pure virtual when it has a declaration as shown in the
following:
class AbstractBase
{
public:
virtual void DoSomething() = 0; // pure virtual method
};This declaration essentially tells the compiler that DoSomething() needs to be implemented and by the class that derives from AbstractBase:
class Derived: public AbstractBase
{
public:
void DoSomething() // pure virtual fn. must be implemented
{
cout << "Implemented virtual function" << endl;
}
};
Thus, what class AbstractBase has done is that it has enforced class Derived to supply
an implementation for virtual method DoSomething(). This functionality where a base
class can enforce support of methods with a specified name and signature in classes that
derive from it is that of an interface.


First, we define the interface of a class Container, which we will design as a more abstract version of our Vector:
class Container {
public:
vir tual double& operator[](int) = 0; // pure virtual function
vir tual int size() const = 0; // const member function (§4.2.1)
vir tual ˜Container() {} // destr uctor (§4.2.2)
};
This class is a pure interface to specific containers defined later. The word vir tual means ‘‘may be
redefined later in a class derived from this one.’’ Unsurprisingly, a function declared vir tual is
called a virtual function. A class derived from Container provides an implementation for the Container interface. The curious =0 syntax says the function is pure virtual; that is, some class derived
from Container must define the function. Thus, it is not possible to define an object that is just a
Container. For example:
Container c; // error : there can be no objects of an abstract class
Container∗ p = new Vector_container(10); // OK: Container is an interface
A Container can only serve as the interface to a class that implements its operator[]() and siz e() functions. A class with a pure virtual function is called an abstract class.
This Container can be used like this:
void use(Container& c)
{
const int sz = c.size();
for (int i=0; i!=sz; ++i)
cout << c[i] << '\n';
}
Note how use() uses the Container interface in complete ignorance of implementation details. It
uses siz e() and [ ] without any idea of exactly which type provides their implementation. A class
that provides the interface to a variety of other classes is often called a polymorphic type.
As is common for abstract classes, Container does not have a constructor. After all, it does not
have any data to initialize. On the other hand, Container does have a destructor and that destructor
is vir tual, so that classes derived from Container can provide implementations. Again, that is common for abstract classes because they tend to be manipulated through references or pointers, and
someone destroying a Container through a pointer has no idea what resources are owned by its
implementation



The abstract class Container defines only an interface and no implementation. For Container to
be useful, we have to implement a container that implements the functions required by its interface.
For that, we could use the concrete class Vector:
class Vector_container : public Container { // Vector_container implements Container
public:
Vector_container(int s) : v(s) { } // Vector of s elements
˜Vector_container() {}
double& operator[](int i) override { return v[i]; }
int size() const override { return v.siz e(); }
private:
Vector v;
};
The :public can be read as ‘‘is derived from’’ or ‘‘is a subtype of.’’ Class Vector_container is said to
be derived from class Container, and class Container is said to be a base of class Vector_container.
An alternative terminology calls Vector_container and Container subclass and superclass, respectively. The derived class is said to inherit members from its base class, so the use of base and
derived classes is commonly referred to as inheritance.
The members operator[]() and siz e() are said to override the corresponding members in the base
class Container. I used the explicit override to make clear what’s intended. The use of override is
optional, but being explicit allows the compiler to catch mistakes, such as misspellings of function
names or slight differences between the type of a vir tual function and its intended overrider. The
explicit use of override is particularly useful in larger class hiearchies where it can otherwise be
hard to know what is supposed to override what.
The destructor (˜Vector_container()) overrides the base class destructor (˜Container()). Note that
the member destructor (˜Vector()) is implicitly invoked by its class’s destructor (˜Vector_container()).
For a function like use(Container&) to use a Container in complete ignorance of implementation
details, some other function will have to make an object on which it can operate. For example:
void g()
{
Vector_container vc(10); // Vector of ten elements
// ... fill vc ...
use(vc);
}
Since use() doesn’t know about Vector_containers but only knows the Container interface, it will
work just as well for a different implementation of a Container. For example:
class List_container : public Container { // List_container implements Container
public:
List_container() { } // empty List
List_container(initializ er_list<double> il) : ld{il} { }
˜List_container() {}56 Classes Chapter 4
double& operator[](int i) override;
int size() const override { return ld.size(); }
private:
std::list<double> ld; // (standard-librar y) list of doubles (§11.3)
};
double& List_container::operator[](int i)
{
for (auto& x : ld) {
if (i==0)
return x;
−−i;
}
throw out_of_range{"List container"};
}
Here, the representation is a standard-library list<double>. Usually, I would not implement a container with a subscript operation using a list, because performance of list subscripting is atrocious
compared to vector subscripting. However, here I just wanted to show an implementation that is
radically different from the usual one.
A function can create a List_container and have use() use it:
void h()
{
List_container lc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
use(lc);
}
The point is that use(Container&) has no idea if its argument is a Vector_container, a List_container,
or some other kind of container; it doesn’t need to know. It can use any kind of Container. It knows
only the interface defined by Container. Consequently, use(Container&) needn’t be recompiled if the
implementation of List_container changes or a brand-new class derived from Container is used.
The flip side of this flexibility is that objects must be manipulated through pointers or references
(§5.2, §13.2.1).



## Virtual Functions
Consider again the use of Container:
void use(Container& c)
{
const int sz = c.size();
for (int i=0; i!=sz; ++i)
cout << c[i] << '\n';
}
How is the call c[i] in use() resolved to the right operator[]()? When h() calls use(), List_container’s
operator[]() must be called. When g() calls use(), Vector_container’s operator[]() must be called. ToSection 4.4 Virtual Functions 57
achieve this resolution, a Container object must contain information to allow it to select the right
function to call at run time. The usual implementation technique is for the compiler to convert the
name of a virtual function into an index into a table of pointers to functions. That table is usually
called the virtual function table or simply the vtbl. Each class with virtual functions has its own vtbl
identifying its virtual functions.

The functions in the vtbl allow the object to be used correctly even when the size of the object and
the layout of its data are unknown to the caller. The implementation of the caller needs only to
know the location of the pointer to the vtbl in a Container and the index used for each virtual function. This virtual call mechanism can be made almost as efficient as the ‘‘normal function call’’
mechanism (within 25%). Its space overhead is one pointer in each object of a class with virtual
functions plus one vtbl for each such class.







Using virtual Inheritance to Solve
the Diamond Problem

due to multiple inheritance and all three base classes
of Platypus inheriting in turn from class Animal, you have three instances of
Animal created automatically for every instance of a Platypus, as shown in Line 38.
This is ridiculous as Platypus is still one animal that has inherited certain attributes
from Mammal, Bird, and Reptile. The problem in the number of instances of base
Animal is not limited to memory consumption alone. Animal has an integer member
Animal::age (that has been kept public for explanation purposes). When you want
to access Animal::age via an instance of Platypus, as shown in Line 42, you get a
compilation error simply because the compiler doesn’t know whether you want to set
Mammal::Animal::age or Bird::Animal::age or Reptile::Animal::age. It can get
even more ridiculous—if you so wanted you could set all three:
duckBilledP.Mammal::Animal::age = 25;
duckBilledP.Bird::Animal::age = 25;
duckBilledP.Reptile::Animal::age = 25;
Clearly, one duck-billed platypus should have only one age. Yet, you want class
Platypus to be a Mammal, Bird, and Reptile. The solution is in virtual inheritance. If
you expect a derived class to be used as a base class, it possibly is a good idea to define
its relationship to the base using the keyword virtual:
class Derived1: public virtual Base
{
// ... members and functions
};
class Derived2: public virtual Base
{
// ... members and functions
};

the number of instances of class Animal constructed has fallen to one, which
is finally reflective of the fact that only one Platypus has been constructed as well.
This is because of the keyword virtual used in the relationship between classes
Mammal, Bird, and Reptile ensures that when these classes are grouped together under
Platypus the common base Animal exists only in a single instance.

Problems caused in an inheritance hierarchy containing two or
more base classes that inherit from a common base, which
results in the need for ambiguity resolution in the absence of
virtual inheritance, is called the Diamond Problem.

The virtual keyword in C++ often is used in different contexts
for different purposes. (My best guess is that someone wanted
to save time on inventing an apt keyword.) Here is a summary:
A function declared virtual means that an existing overriding
function in a derived class is invoked.
An inheritance relationship declared using keyword virtual
between classes Derived1 and Derived2 that inherits from
class Base means that another class Derived3 that inherits
from Derived1 and Derived2 still results in the creation of only
one instance of Base during instantiation of type Derived3.
Thus the same keyword virtual is used to implement two
different concepts.





Specifier Override to Indicate Intention
to Override
Our versions of base class Fish have featured a virtual function called Swim() as seen in
the following code:
class Fish
{
public:
virtual void Swim()
{
cout << "Fish swims!" << endl;
}
};
Assume that derived class Tuna were to define a function Swim() but with a slightly
different signature—one using const inserted unintentionally by a programmer who
wants to override Fish::Swim():
class Tuna:public Fish
{
public:
void Swim() const
{
cout << "Tuna swims!" << endl;
}
};
This function Tuna::Swim() actually does not override Fish::Swim(). The signatures
are different thanks to the presence of const in Tuna::Swim(). Compilation succeeds,
however, and the programmer may falsely believe that he has successfully overridden the
function Swim() in class Tuna. C++11 and beyond give the programmer a specifier
override that is used to verify whether the function being overridden has been declared
as virtual by the base class:
class Tuna:public Fish
{
public:
void Swim() const override // Error: no virtual fn with this sig in Fish
{
cout << "Tuna swims!" << endl;
}
};Thus, override supplies a powerful way of expressing the explicit intention to override
a base class virtual function, thereby getting the compiler to check whether
■ The base class function is virtual.
■ The signature of the base class virtual function exactly matches the signature of the
derived class function declared to override.


Use final to Prevent Function
Overriding
Specifier final, introduced in C++11, was first presented to you in Lesson 10. A class
declared as final cannot be used as a base class. Similarly, a virtual function
declared as final cannot be overridden in a derived class.
Thus, a version of class Tuna that doesn’t allow any further specialization of virtual
function Swim() would look like this:
class Tuna:public Fish
{
public:
// override Fish::Swim and make this final
void Swim() override final
{
cout << "Tuna swims!" << endl;
}
};
This version of Tuna can be inherited from, but Swim() cannot be overridden any
further:
class BluefinTuna final:public Tuna
{
public:
void Swim() // Error: Swim() was final in Tuna, cannot override
{
}
};
A demonstration of specifiers override and final is available in Listing 11.9.We used final in the declaration of class BluefinTuna as
well. This ensures that class BluefinTuna cannot be used as
a base class. Therefore, the following would result in error:
class FailedDerivation:public BluefinTuna
{
};










Data Abstraction
Data abstraction refers to providing only essential information to the outside world and hiding their background details, i.e., to represent the needed information in program without presenting the details.

Data abstraction is a programming (and design) technique that relies on the separation of interface and implementation.

Let's take one real life example of a TV, which you can turn on and off, change the channel, adjust the volume, and add external components such as speakers, VCRs, and DVD players, BUT you do not know its internal details, that is, you do not know how it receives signals over the air or through a cable, how it translates them, and finally displays them on the screen.

Thus, we can say a television clearly separates its internal implementation from its external interface and you can play with its interfaces like the power button, channel changer, and volume control without having any knowledge of its internals.

In C++, classes provides great level of data abstraction. They provide sufficient public methods to the outside world to play with the functionality of the object and to manipulate object data, i.e., state without actually knowing how class has been implemented internally.

For example, your program can make a call to the sort() function without knowing what algorithm the function actually uses to sort the given values. In fact, the underlying implementation of the sorting functionality could change between releases of the library, and as long as the interface stays the same, your function call will still work.

In C++, we use classes to define our own abstract data types (ADT). You can use the cout object of class ostream to stream data to standard output like this −
Live Demo

#include <iostream>
using namespace std;

int main() {
   cout << "Hello C++" <<endl;
   return 0;
}

Here, you don't need to understand how cout displays the text on the user's screen. You need to only know the public interface and the underlying implementation of ‘cout’ is free to change.
Access Labels Enforce Abstraction

In C++, we use access labels to define the abstract interface to the class. A class may contain zero or more access labels −

    Members defined with a public label are accessible to all parts of the program. The data-abstraction view of a type is defined by its public members.

    Members defined with a private label are not accessible to code that uses the class. The private sections hide the implementation from code that uses the type.

There are no restrictions on how often an access label may appear. Each access label specifies the access level of the succeeding member definitions. The specified access level remains in effect until the next access label is encountered or the closing right brace of the class body is seen.
Benefits of Data Abstraction

Data abstraction provides two important advantages −

    Class internals are protected from inadvertent user-level errors, which might corrupt the state of the object.

    The class implementation may evolve over time in response to changing requirements or bug reports without requiring change in user-level code.

By defining data members only in the private section of the class, the class author is free to make changes in the data. If the implementation changes, only the class code needs to be examined to see what affect the change may have. If data is public, then any function that directly access the data members of the old representation might be broken.
Data Abstraction Example

Any C++ program where you implement a class with public and private members is an example of data abstraction. Consider the following example −
Live Demo

#include <iostream>
using namespace std;

class Adder {
   public:
      // constructor
      Adder(int i = 0) {
         total = i;
      }

      // interface to outside world
      void addNum(int number) {
         total += number;
      }

      // interface to outside world
      int getTotal() {
         return total;
      };

   private:
      // hidden data from outside world
      int total;
};

int main() {
   Adder a;

   a.addNum(10);
   a.addNum(20);
   a.addNum(30);

   cout << "Total " << a.getTotal() <<endl;
   return 0;
}

When the above code is compiled and executed, it produces the following result −

Total 60

Above class adds numbers together, and returns the sum. The public members - addNum and getTotal are the interfaces to the outside world and a user needs to know them to use the class. The private member total is something that the user doesn't need to know about, but is needed for the class to operate properly.
Designing Strategy

Abstraction separates code into interface and implementation. So while designing your component, you must keep interface independent of the implementation so that if you change underlying implementation then interface would remain intact.

In this case whatever programs are using these interfaces, they would not be impacted and would just need a recompilation with the latest implementation.






Encapsulation

All C++ programs are composed of the following two fundamental elements −

    Program statements (code) − This is the part of a program that performs actions and they are called functions.

    Program data − The data is the information of the program which gets affected by the program functions.

Encapsulation is an Object Oriented Programming concept that binds together the data and functions that manipulate the data, and that keeps both safe from outside interference and misuse. Data encapsulation led to the important OOP concept of data hiding.

Data encapsulation is a mechanism of bundling the data, and the functions that use them and data abstraction is a mechanism of exposing only the interfaces and hiding the implementation details from the user.

C++ supports the properties of encapsulation and data hiding through the creation of user-defined types, called classes. We already have studied that a class can contain private, protected and public members. By default, all items defined in a class are private. For example −

class Box {
   public:
      double getVolume(void) {
         return length * breadth * height;
      }

   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

The variables length, breadth, and height are private. This means that they can be accessed only by other members of the Box class, and not by any other part of your program. This is one way encapsulation is achieved.

To make parts of a class public (i.e., accessible to other parts of your program), you must declare them after the public keyword. All variables or functions defined after the public specifier are accessible by all other functions in your program.

Making one class a friend of another exposes the implementation details and reduces encapsulation. The ideal is to keep as many of the details of each class hidden from all other classes as possible.
Data Encapsulation Example

Any C++ program where you implement a class with public and private members is an example of data encapsulation and data abstraction. Consider the following example −
Live Demo

#include <iostream>
using namespace std;

class Adder {
   public:
      // constructor
      Adder(int i = 0) {
         total = i;
      }

      // interface to outside world
      void addNum(int number) {
         total += number;
      }

      // interface to outside world
      int getTotal() {
         return total;
      };

   private:
      // hidden data from outside world
      int total;
};

int main() {
   Adder a;

   a.addNum(10);
   a.addNum(20);
   a.addNum(30);

   cout << "Total " << a.getTotal() <<endl;
   return 0;
}

When the above code is compiled and executed, it produces the following result −

Total 60

Above class adds numbers together, and returns the sum. The public members addNum and getTotal are the interfaces to the outside world and a user needs to know them to use the class. The private member total is something that is hidden from the outside world, but is needed for the class to operate properly.
Designing Strategy

Most of us have learnt to make class members private by default unless we really need to expose them. That's just good encapsulation.

This is applied most frequently to data members, but it applies equally to all members, including virtual functions.









Interfaces

An interface describes the behavior or capabilities of a C++ class without committing to a particular implementation of that class.

The C++ interfaces are implemented using abstract classes and these abstract classes should not be confused with data abstraction which is a concept of keeping implementation details separate from associated data.

A class is made abstract by declaring at least one of its functions as pure virtual function. A pure virtual function is specified by placing "= 0" in its declaration as follows −

class Box {
   public:
      // pure virtual function
      virtual double getVolume() = 0;

   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

The purpose of an abstract class (often referred to as an ABC) is to provide an appropriate base class from which other classes can inherit. Abstract classes cannot be used to instantiate objects and serves only as an interface. Attempting to instantiate an object of an abstract class causes a compilation error.

Thus, if a subclass of an ABC needs to be instantiated, it has to implement each of the virtual functions, which means that it supports the interface declared by the ABC. Failure to override a pure virtual function in a derived class, then attempting to instantiate objects of that class, is a compilation error.

Classes that can be used to instantiate objects are called concrete classes.
Abstract Class Example

Consider the following example where parent class provides an interface to the base class to implement a function called getArea() −
Live Demo

#include <iostream>

using namespace std;

// Base class
class Shape {
   public:
      // pure virtual function providing interface framework.
      virtual int getArea() = 0;
      void setWidth(int w) {
         width = w;
      }c

      void setHeight(int h) {
         height = h;
      }

   protected:
      int width;
      int height;
};

// Derived classes
class Rectangle: public Shape {
   public:
      int getArea() {
         return (width * height);
      }
};

class Triangle: public Shape {
   public:
      int getArea() {
         return (width * height)/2;
      }
};

int main(void) {
   Rectangle Rect;
   Triangle  Tri;

   Rect.setWidth(5);
   Rect.setHeight(7);

   // Print the area of the object.
   cout << "Total Rectangle area: " << Rect.getArea() << endl;

   Tri.setWidth(5);
   Tri.setHeight(7);

   // Print the area of the object.
   cout << "Total Triangle area: " << Tri.getArea() << endl;

   return 0;
}

When the above code is compiled and executed, it produces the following result −

Total Rectangle area: 35
Total Triangle area: 17

You can see how an abstract class defined an interface in terms of getArea() and two other classes implemented same function but with different algorithm to calculate the area specific to the shape.
Designing Strategy

An object-oriented system might use an abstract base class to provide a common and standardized interface appropriate for all the external applications. Then, through inheritance from that abstract base class, derived classes are formed that operate similarly.

The capabilities (i.e., the public functions) offered by the external applications are provided as pure virtual functions in the abstract base class. The implementations of these pure virtual functions are provided in the derived classes that correspond to the specific types of the application.

This architecture also allows new applications to be added to a system easily, even after the system has been defined.

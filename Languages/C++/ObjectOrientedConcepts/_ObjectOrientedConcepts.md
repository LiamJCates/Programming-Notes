C++ features classes that are used to contain member data and member
methods. These member methods operate using member data. The effect of this
organization is that the programmer models objects containing data and actions they wants to perform.

A class hierarchy is a set of classes related by derivation (e.g., : public). We use class hierarchies to represent concepts that have hierarchical relationships

Benefits from Hierarchies
A class hierarchy offers two kinds of benefits:
• Interface inheritance: An object of a derived class can be used wherever an object of a base class is required. That is, the base class acts as an interface for the derived class.
• Implementation inheritance: A base class provides functions or data that simplifies the implementation of derived classes.

Concrete classes – especially classes with small representations – are much like built-in types: we define them as local variables, access them using their names, copy them around, etc.

The defining characteristic of a concrete type is that its representation is part of its definition. In many important cases, that representation is only one or more pointers to data stored elsewhere, but that representation is present in each object of a concrete class. That allows implementations to be optimally efficient in time and space. In particular, it allows us to
• place objects of concrete types on the stack, in statically allocated memory, and in other objects (§1.5);
• refer to objects directly (and not just through pointers or references);
• initialize objects immediately and completely (e.g., using constructors; §2.3);
• copy and move objects (§5.2).



The representation can be private and accessible only through the member functions, but it is present. Therefore, if the representation changes in any significant way, a user must recompile. This is the price to pay for having concrete types behave exactly like built-in types. For types that don’t change often, and where local variables provide much-needed clarity and efficiency, this is acceptable and often ideal. To increase flexibility, a concrete type can keep major parts of its representation on the free store (dynamic memory, heap) and access them through the part stored in the class object itself. That’s the way vector and string are implemented; they can be considered resource handles with carefully crafted interfaces.

Classes in class hierarchies are different: we tend to allocate them on the free store using new, and we access them through pointers or references.

To derive a class from an existing class, you write the new class as you
would any other class, but you extend the header after the class name with a
colon, :, the word public, and then the class you’re deriving from, as in the
following class header line:
class Derived : public Base {
}















const Aliase
One of the most common reasons to use an alias in C++ is to change the
manner in which an object is accessed. Moving a pointer to an object is
always going to be easier than moving the object itself because a pointer is
simply a number that specifies the address of the object. The object could
contain complex data and pointers to yet other objects. Moving objects is
complicated and messy, so developers try to avoid it at all cost.
However, sending a pointer to someone gives them access to the original
data. The recipient could modify the data in ways that you don’t want. So,
you could create an alias of the original object that is a constant. No one can
modify a constant.




Hierarchy Navigation
The read_shape() function returns Shape∗ so that we can treat all Shapes alike. However, what can we do if we want to use a member function that is only provided by a particular derived class, such
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
Code is cleaner when dynamic_cast is used with restraint. If we can avoid using type information,
we can write simpler and more efficient code, but occasionally type information is lost and must be
recovered. This typically happens when we pass an object to some system that accepts an interface
specified by a base class. When that system later passes the object back to us, we might have to
recover the original type. Operations similar to dynamic_cast are known as ‘‘is kind of’’ and ‘‘is
instance of’’ operations.















## Virtual Function
A virtual function is a function in a base class that is declared using the keyword virtual. Defining in a base class a virtual function, with another version in a derived class, signals to the compiler that we don't want static linkage for this function.

What we do want is the selection of the function to be called at any given point in the program to be based on the kind of object for which it is called. This sort of operation is referred to as dynamic linkage, or late binding.


Consider again the use of Container:
void use(Container& c)
{
const int sz = c.size();
for (int i=0; i!=sz; ++i)
cout << c[i] << '\n';
}
How is the call c[i] in use() resolved to the right operator[]()? When h() calls use(), List_container’s
operator[]() must be called. When g() calls use(), Vector_container’s operator[]() must be called. To achieve this resolution, a Container object must contain information to allow it to select the right
function to call at run time. The usual implementation technique is for the compiler to convert the
name of a virtual function into an index into a table of pointers to functions. That table is usually
called the virtual function table or simply the vtbl. Each class with virtual functions has its own vtbl
identifying its virtual functions.

The functions in the vtbl allow the object to be used correctly even when the size of the object and
the layout of its data are unknown to the caller. The implementation of the caller needs only to
know the location of the pointer to the vtbl in a Container and the index used for each virtual function. This virtual call mechanism can be made almost as efficient as the ‘‘normal function call’’
mechanism (within 25%). Its space overhead is one pointer in each object of a class with virtual
functions plus one vtbl for each such class.





## Pure Virtual Functions
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




Polymorphic Behavior Implemented Using Virtual Functions

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





## Need for Virtual Destructors
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


How Do virtual Functions Work?
Understanding the Virtual Function Table

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

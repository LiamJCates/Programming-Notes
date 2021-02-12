## Inheritance Complications

C++ provides the ability for  multiple inheritance. Multiple inheritance enables a derived class to inherit members from more than one parent.



### Problems with multiple inheritance

While multiple inheritance seems like a simple extension of single inheritance, multiple inheritance introduces a lot of issues that can markedly increase the complexity of programs and make them a maintenance nightmare.

First, ambiguity can result when multiple base classes contain a function with the same name:

  #include <iostream>

  class A
  {
    private:
      long m_id;

    public:
      A(long id) : m_id(id) {}

      long getID() { return m_id; }
  };

  class A2
  {
    private:
      long m_id;

    public:
      A2(long id) : m_id(id) {}

      long getID() { return m_id; }
  };

  class B: public A, public A2
  {
    public:
        B(long AId, long A2Id) : A(AId), A2(A2Id) {}
  };

  int main()
  {
      B b(1, 2);
      std::cout << b.getID(); // Which getID() do we call?

      return 0;
  }

When b.getID() is compiled, the compiler looks to see if B contains a function named getID(). It doesn’t. The compiler then looks to see if any of the parent classes have a function named getID().

See the problem here?
The problem is that b actually contains TWO getID() functions: one inherited from A, and one inherited from A2. Consequently, this function call is ambiguous, and you will receive a compiler error if you try to compile it.

However, to work around this problem, you can explicitly specify which version to call:

int main()
{
    B b(1, 2);
    std::cout << b.A::getID();
}

Output:
  1

While this workaround is pretty simple, you can see how things can get complex when your class inherits from four or six base classes, which inherit from other classes themselves. The potential for naming conflicts increases exponentially as you inherit more classes, and each of these naming conflicts needs to be resolved explicitly.



### The Diamond Problem

More serious is the diamond problem. This occurs when a class multiply inherits from two classes which each inherit from a single base class. This leads to a diamond shaped inheritance pattern.

For example, consider the following set of classes:

A derived class with two base classes and these two base classes have one common base class. An ambiguity can arise in this type of inheritance.

  #include<iostream.h>
  #include<conio.h>

  class A
  {
    public:
    int a;
  };

  class B : public A
  {
    public:
    int b;
  };

  class C : public A
  {
    public:
    int c;
  };

  class D : public B, public C
  {
    public:
    int d;
  };

  void main()
  {

    D obj;

    //obj.a = 10;      //Statement 1, Error
    //obj.a = 100;     //Statement 2, Error

    obj.B::a = 10;     //Statement 3
    obj.C::a = 100;    //Statement 4

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    cout<< "\n A from B  : "<< obj.B::a;
    cout<< "\n A from C  : "<< obj.C::a;

    cout<< "\n B : "<< obj.b;
    cout<< "\n C : "<< obj.c;
    cout<< "\n D : "<< obj.d;

  }

Output:

  A from B  : 10
  A from C  : 100
  B : 20
  C : 30
  D : 40

In the above example, both B & C inherit A, they both have single copy of A.

However D inherits both B & C, therefore D has two copies of A, one from B and another from C.

If we need to access the data member a of A through the object of D, we must specify the path from which a will be accessed, whether it is from B or C, because compiler can’t differentiate between two copies of A in D.

There are 2 ways to avoid this ambiguity:
  Use scope resolution operator
  Use virtual base class



### Avoiding ambiguity using scope resolution operator

Using scope resolution operator we can manually specify the path from which data member a will be accessed, as shown in statement 3 and 4, in the above example.

obj.B::a = 10;    //Statement 3
obj.C::a = 100;   //Statement 4

Note : Still, there are two copies of A in D.



###  Avoiding ambiguity using virtual base class:

  #include<iostream.h>
  #include<conio.h>

  class A
  {
    public:
    int a;
  };

  class B : virtual public A
  {
    public:
    int b;
  };
  class C : virtual public A
  {
    public:
    int c;
  };

  class D : public B, public C
  {
    public:
    int d;
  };

  void main()
  {

    D obj;

    obj.a = 10;        //Statement 3
    obj.a = 100;      //Statement 4

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    cout<< "\n A : "<< obj.a;
    cout<< "\n B : "<< obj.b;
    cout<< "\n C : "<< obj.c;
    cout<< "\n D : "<< obj.d;

  }

Output:

A : 100
B : 20
C : 30
D : 40

According to the above example, D has only one copy of A, therefore, statement 4 will overwrite the value of a, given at statement 3.


For more information regarding virtual inheritance, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\VirtualInheritance.md]









Is multiple inheritance more trouble than it’s worth?

As it turns out, most of the problems that can be solved using multiple inheritance can be solved using single inheritance as well. Many object-oriented languages (eg. Smalltalk, PHP) do not even support multiple inheritance. Many relatively modern languages such as Java and C# restrict classes to single inheritance of normal classes, but allow multiple inheritance of interface classes (which we will talk about later). The driving idea behind disallowing multiple inheritance in these languages is that it simply makes the language too complex, and ultimately causes more problems than it fixes.

Many authors and experienced programmers believe multiple inheritance in C++ should be avoided at all costs due to the many potential problems it brings. However there are times and situations when multiple inheritance is the best way to proceed. However, multiple inheritance should be used extremely carefully. Avoid multiple inheritance unless alternatives lead to more complexity.

As an interesting aside, you have already been using classes written using multiple inheritance without knowing it: the iostream library objects std::cin and std::cout are both implemented using multiple inheritance!




Virtual base classes



The diamond problem

An example illustrating the diamond problem:

  class PoweredDevice
  {
  public:
    PoweredDevice(int power)
      { std::cout << "PoweredDevice: " << power << '\n'; }
  };

  class Scanner: public PoweredDevice
  {
  public:
    Scanner(int scanner, int power) :
      PoweredDevice{ power } { std::cout << "Scanner: " << scanner << '\n'; }
  };

  class Printer: public PoweredDevice
  {
  public:
    Printer(int printer, int power) :
      PoweredDevice{ power } { std::cout << "Printer: " << printer << '\n'; }
  };

  class Copier: public Scanner, public Printer
  {
  public:
    Copier(int scanner, int printer, int power) :
      Scanner{ scanner, power }, Printer{ printer, power } {}
  };

  int main()
  {
    Copier copier{ 1, 2, 3 };
  }

Output:

  PoweredDevice: 3
  Scanner: 1
  PoweredDevice: 3
  Printer: 2

When you create a Copier class object, by default you would end up with two copies of the PoweredDevice class -- one from Printer, and one from Scanner.

While this is often desired, other times you may want only one copy of PoweredDevice to be shared by both Scanner and Printer.



Virtual base classes

To share a single copy of base class members, simply insert the “virtual” keyword in the inheritance list of the derived class. This creates what is called a virtual base class, which means there is only one base object. The base object is shared between all objects in the inheritance tree and it is only constructed once. Here is an example (without constructors for simplicity) showing how to use the virtual keyword to create a shared base class:


class PoweredDevice { //implementation };

class Scanner: virtual public PoweredDevice { //implementation };

class Printer: virtual public PoweredDevice { //implementation };

class Copier: public Scanner, public Printer { //implementation };

Now, when you create a Copier class object, you will get only one copy of PoweredDevice per Copier that will be shared by both Scanner and Printer.

However, this leads to one more problem: if Scanner and Printer share a PoweredDevice base class, who is responsible for creating it? The answer, as it turns out, is Copier. The Copier constructor is responsible for creating PoweredDevice. Consequently, this is one time when Copier is allowed to call a non-immediate-parent constructor directly:

  #include <iostream>

  class PoweredDevice
  {
  public:
    PoweredDevice(int power)
      { std::cout << "PoweredDevice: " << power << '\n'; }
  };

  class Scanner: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
  {
  public:
    Scanner(int scanner, int power) :
      PoweredDevice{ power } { std::cout << "Scanner: " << scanner << '\n'; }
    // this line is required to create Scanner objects, but ignored in this case
  };

  class Printer: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
  {
  public:
    Printer(int printer, int power) :
      PoweredDevice{ power } { std::cout << "Printer: " << printer << '\n'; }
    // this line is required to create Printer objects, but ignored in this case
  };

  class Copier: public Scanner, public Printer
  {
  public:
    Copier(int scanner, int printer, int power)
      : PoweredDevice{ power }, // PoweredDevice is constructed here
      Scanner{ scanner, power }, Printer{ printer, power } {}    
  };

  int main()
  {
    Copier copier{ 1, 2, 3 };
  }

Output:

  PoweredDevice: 3
  Scanner: 1
  Printer: 2

As you can see, PoweredDevice only gets constructed once.

There are a few details that we would be remiss if we did not mention.

First, virtual base classes are always created before non-virtual base classes, which ensures all bases get created before their derived classes.

Second, note that the Scanner and Printer constructors still have calls to the PoweredDevice constructor. When creating an instance of Copier, these constructor calls are simply ignored because Copier is responsible for creating the PoweredDevice, not Scanner or Printer. However, if we were to create an instance of Scanner or Printer, those constructor calls would be used, and normal inheritance rules apply.

Third, if a class inherits one or more classes that have virtual parents, the most derived class is responsible for constructing the virtual base class. In this case, Copier inherits Printer and Scanner, both of which have a PoweredDevice virtual base class. Copier, the most derived class, is responsible for creation of PoweredDevice. Note that this is true even in a single inheritance case: if Copier was singly inherited from Printer, and Printer was virtually inherited from PoweredDevice, Copier is still responsible for creating PoweredDevice.

Fourth, all classes inheriting a virtual base class will have a virtual table, even if they would normally not have one otherwise, and thus be larger by a pointer.

Because Scanner and Printer derive virtually from PoweredDevice, Copier will only be one PoweredDevice subobject. Scanner and Printer both need to know how to find that single PoweredDevice subobject, so they can access its members (because after all, they are derived from it). This is typically done through some virtual table magic (which essentially stores the offset from each subclass to the PoweredDevice subobject).

### Pointers and references to the base class of derived objects

When you create a derived class, it is composed of multiple parts: one part for each inherited class, and a part for itself.

  #include <string_view>

  class Base
  {
  protected:
      int m_value;

  public:
      Base(int value) : m_value{ value }{}

      std::string_view getName() const { return "Base"; }
      int getValue() const { return m_value; }
  };

  class Derived: public Base
  {
  public:
      Derived(int value) : Base{ value }{}

      std::string_view getName() const { return "Derived"; }
      int getValueDoubled() const { return m_value * 2; }
  };

When we create a Derived object, it contains a Base part (which is constructed first), and a Derived part (which is constructed second). Remember that inheritance implies an is-a relationship between two classes. Since a Derived is-a Base, it is appropriate that Derived contain a Base part.

### Pointers, references, and derived classes

It should be fairly intuitive that we can set Derived pointers and references to Derived objects:

  #include <iostream>

  int main()
  {
    Derived derived{ 5 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Derived &rDerived{ derived };
    std::cout << "rDerived is a " << rDerived.getName() << " and has value " << rDerived.getValue() << '\n';

    Derived *pDerived{ &derived };
    std::cout << "pDerived is a " << pDerived->getName() << " and has value " << pDerived->getValue() << '\n';

    return 0;
  }

This produces the following output:

derived is a Derived and has value 5
rDerived is a Derived and has value 5
pDerived is a Derived and has value 5

However, since Derived has a Base part, a more interesting question is whether C++ will let us set a Base pointer or reference to a Derived object. It turns out, we can!

  #include <iostream>

  int main()
  {
    Derived derived{ 5 };

    // These are both legal!
    Base &rBase{ derived };
    Base *pBase{ &derived };

    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
    std::cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';
    std::cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';

    return 0;
  }

This produces the result:

derived is a Derived and has value 5
rBase is a Base and has value 5
pBase is a Base and has value 5

This result may not be quite what you were expecting at first!

It turns out that because rBase and pBase are a Base reference and pointer, they can only see members of Base (or any classes that Base inherited). So even though Derived::getName() shadows (hides) Base::getName() for Derived objects, the Base pointer/reference can not see Derived::getName(). Consequently, they call Base::getName(), which is why rBase and pBase report that they are a Base rather than a Derived.

Note that this also means it is not possible to call Derived::getValueDoubled() using rBase or pBase. They are unable to see anything in Derived.

### Use for pointers and references to base classes

Why would we set a pointer or reference to the base class of a derived object when I can just use the derived object?

First, Supposed we have a base class Animal as well as two derived classes Cat and Dog. Each class possesses a name variable and a speak() method.

Let’s say you wanted to write a function that printed an animal’s name and sound. Without using a pointer to a base class, you’d have to write it using overloaded functions:

  void report(const Cat &cat)
  {
    std::cout << cat.getName() << " says " << cat.speak() << '\n';
  }

  void report(const Dog &dog)
  {
    std::cout << dog.getName() << " says " << dog.speak() << '\n';
  }

Not too difficult, but consider what would happen if we had 30 different animal types instead of 2. You’d have to write 30 almost identical functions! Plus, if you ever added a new type of animal, you’d have to write a new function for that one too. This is a huge waste of time considering the only real difference is the type of the parameter.

However, because Cat and Dog are derived from Animal, Cat and Dog have an Animal part. Therefore, it makes sense that we should be able to do something like this:

  void report(const Animal &rAnimal)
  {
    std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
  }

This would let us pass in any class derived from Animal, even ones that we created after we wrote the function! Instead of one function per derived class, we get one function that works with all classes derived from Animal!

The problem is, of course, that because rAnimal is an Animal reference, rAnimal.speak() will call Animal::speak() instead of the derived version of speak().

Second, let’s say you had 3 cats and 3 dogs that you wanted to keep in an array for easy access. Because arrays can only hold objects of one type, without a pointer or reference to a base class, you’d have to create a different array for each derived type. 30 different animal types would necessitate 30 arrays, one for each type of animal!

However, because both Cat and Dog are derived from Animal, it makes sense that we should be able to do something like this:

  #include <iostream>

  int main()
  {
      const Cat fred{ "Fred" };
      const Cat misty{ "Misty" };
      const Cat zeke{ "Zeke" };

      const Dog garbo{ "Garbo" };
      const Dog pooky{ "Pooky" };
      const Dog truffle{ "Truffle" };

      // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
      const auto animals{ std::to_array<const Animal*>({&fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

      // Before C++20, with the array size being explicitly specified
      // const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

      for (const auto animal : animals)
      {
          std::cout << animal->getName() << " says " << animal->speak() << '\n';
      }

      return 0;
  }

While this compiles and executes, unfortunately the fact that each element of array “animals” is a pointer to an Animal means that animal->speak() will call Animal::speak() instead of the derived class version of speak() that we want. The output is

Fred says ???
Garbo says ???
Misty says ???
Pooky says ???
Truffle says ???
Zeke says ???

Although both of these techniques could save us a lot of time and energy, they have the same problem. The pointer or reference to the base class calls the base version of the function rather than the derived version. If only there was some way to make those base pointers call the derived version of a function instead of the base version…




Virtual functions and polymorphism

A virtual function is a special type of function that, when called, resolves to the most-derived version of the function that exists between the base and derived class. This capability is known as polymorphism. A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const) and return type as the base version of the function. Such functions are called overrides.

To make a function virtual, simply place the “virtual” keyword before the function declaration:

  virtual return-type method-name(parameter-list) { // body }

Here’s the above example with a virtual function:

  #include <iostream>
  #include <string_view>

  class Base
  {
  public:
    virtual std::string_view getName() const { return "Base"; } // note addition of virtual keyword
  };

  class Derived: public Base
  {
  public:
    virtual std::string_view getName() const { return "Derived"; }
  };

  int main()
  {
    Derived derived;
    Base &rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
  }

Output:

  rBase is a Derived

Because rBase is a reference to the Base portion of a Derived object, when rBase.getName() is evaluated, it would normally resolve to Base::getName(). However, Base::getName() is virtual, which tells the program to go look and see if there are any more-derived versions of the function available between Base and Derived. In this case, it will resolve to Derived::getName()!


Here’s the equivalent class with the speak() function made virtual:

  #include <iostream>
  #include <string>
  #include <string_view>

  class Animal
  {
  protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(const std::string &name) : m_name{ name } {}

  public:
    const std::string &getName() const { return m_name; }
    virtual std::string_view speak() const { return "???"; }
  };

  class Cat: public Animal
  {
  public:
    Cat(const std::string &name) : Animal{ name } {}

    virtual std::string_view speak() const { return "Meow"; }
  };

  class Dog: public Animal
  {
  public:
    Dog(const std::string& name) : Animal{ name } {}

    virtual std::string_view speak() const { return "Woof"; }
  };

  void report(const Animal &animal)
  {
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
  }

  int main()
  {
    Cat cat{ "Fred" };
    Dog dog{ "Garbo" };

    report(cat);
    report(dog);

    return 0;
  }

This program produces the result:

Fred says Meow
Garbo says Woof

It works!

When animal.speak() is evaluated, the program notes that Animal::speak() is a virtual function. In the case where animal is referencing the Animal portion of a Cat object, the program looks at all the classes between Animal and Cat to see if it can find a more derived function. In that case, it finds Cat::speak(). In the case where animal references the Animal portion of a Dog object, the program resolves the function call to Dog::speak().

Note that we didn’t make Animal::getName() virtual. This is because getName() is never overridden in any of the derived classes, therefore there is no need.

Similarly, the following array example now works as expected:

  Cat fred{ "Fred" };
  Cat misty{ "Misty" };
  Cat zeke{ "Zeke" };

  Dog garbo{ "Garbo" };
  Dog pooky{ "Pooky" };
  Dog truffle{ "Truffle" };

  // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
  Animal *animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

  for (const auto *animal : animals)
      std::cout << animal->getName() << " says " << animal->speak() << '\n';

Which produces the result:

Fred says Meow
Garbo says Woof
Misty says Meow
Pooky says Woof
Truffle says Woof
Zeke says Meow

Even though these two examples only use Cat and Dog, any other classes we derive from Animal would also work with our report() function and animal array without further modification! This is perhaps the biggest benefit of virtual functions -- the ability to structure your code in such a way that newly derived classes will automatically work with the old code without modification!

Note:
the signature of the derived class function must exactly match the signature of the base class virtual function in order for the derived class function to be used. If the derived class function has different parameter types, the program will likely still compile fine, but the virtual function will not resolve as intended.



### Virtual Methods
In C++, a virtual function or virtual method is an inheritable and overridable function or method for which dynamic dispatch is facilitated. This concept is an important part of the (runtime) polymorphism portion of object-oriented programming (OOP).

In short, a virtual function defines a target function to be executed, but the target might not be known at compile time.

Unlike a non-virtual function, when a virtual function is overridden the most-derived version is used at all levels of the class hierarchy, rather than just the level at which it was created.

This is in contrast to non-virtual functions, which can still be overridden in a derived class, but the "new" version will only be used by the derived class and below, but will not change the functionality of the base class at all.


### Use of the virtual keyword

If a function is marked as virtual, all matching overrides are also considered virtual, even if they are not explicitly marked as such. However, having the keyword virtual on the derived functions does not hurt, and it serves as a useful reminder that the function is a virtual function rather than a normal one. Consequently, it’s generally a good idea to use the virtual keyword for virtualized functions in derived classes even though it’s not strictly necessary.

#### Return types of virtual functions

Under normal circumstances, the return type of a virtual function and its override must match:

  class Base
  {
  public:
    virtual int getValue() const { return 5; }
  };

  class Derived: public Base
  {
  public:
    virtual double getValue() const { return 6.78; }
  };

In this case, Derived::getValue() is not considered a matching override for Base::getValue() (it is considered a completely separate function).




#### Do not call virtual functions from constructors or destructors

Here’s another gotcha that often catches unsuspecting new programmers. You should not call virtual functions from constructors or destructors. Why?

Remember that when a Derived class is created, the Base portion is constructed first. If you were to call a virtual function from the Base constructor, and Derived portion of the class hadn’t even been created yet, it would be unable to call the Derived version of the function because there’s no Derived object for the Derived function to work on. In C++, it will call the Base version instead.

A similar issue exists for destructors. If you call a virtual function in a Base class destructor, it will always resolve to the Base class version of the function, because the Derived portion of the class will already have been destroyed.

Rule: Never call virtual functions from constructors or destructors

#### The downside of virtual functions

Since most of the time you’ll want your functions to be virtual, why not just make all functions virtual? The answer is because it’s inefficient -- resolving a virtual function call takes longer than resolving a regular one. Furthermore, the compiler also has to allocate an extra pointer for each class object that has one or more virtual functions.


Virtual destructors, virtual assignment, and overriding virtualization
By Alex on February 1st, 2008 | last modified by Alex on December 21st, 2020

Virtual destructors

Although C++ provides a default destructor for your classes if you do not provide one yourself, it is sometimes the case that you will want to provide your own destructor (particularly if the class needs to deallocate memory). You should always make your destructors virtual if you’re dealing with inheritance. Consider the following example:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37

#include <iostream>
class Base
{
public:
   ~Base() // note: not virtual
   {
       std::cout << "Calling ~Base()\n";
   }
};

class Derived: public Base
{
private:
   int* m_array;

public:
   Derived(int length)
     : m_array{ new int[length] }
   {
   }

   ~Derived() // note: not virtual (your compiler may warn you about this)
   {
       std::cout << "Calling ~Derived()\n";
       delete[] m_array;
   }
};

int main()
{
   Derived *derived { new Derived(5) };
   Base *base { derived };

   delete base;

   return 0;
}

Note: If you compile the above example, your compiler may warn you about the non-virtual destructor (which is intentional for this example). You may need to disable the compiler flag that treats warnings as errors to proceed.

Because base is a Base pointer, when base is deleted, the program looks to see if the Base destructor is virtual. It’s not, so it assumes it only needs to call the Base destructor. We can see this in the fact that the above example prints:

Calling ~Base()

However, we really want the delete function to call Derived’s destructor (which will call Base’s destructor in turn), otherwise m_array will not be deleted. We do this by making Base’s destructor virtual:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37

#include <iostream>
class Base
{
public:
   virtual ~Base() // note: virtual
   {
       std::cout << "Calling ~Base()\n";
   }
};

class Derived: public Base
{
private:
   int* m_array;

public:
   Derived(int length)
     : m_array{ new int[length] }
   {
   }

   virtual ~Derived() // note: virtual
   {
       std::cout << "Calling ~Derived()\n";
       delete[] m_array;
   }
};

int main()
{
   Derived *derived { new Derived(5) };
   Base *base { derived };

   delete base;

   return 0;
}

Now this program produces the following result:

Calling ~Derived()
Calling ~Base()

Rule: Whenever you are dealing with inheritance, you should make any explicit destructors virtual.

As with normal virtual member functions, if a base class function is virtual, all derived overrides will be considered virtual regardless of whether they are specified as such. It is not necessary to create an empty derived class destructor just to mark it as virtual.

Virtual assignment

It is possible to make the assignment operator virtual. However, unlike the destructor case where virtualization is always a good idea, virtualizing the assignment operator really opens up a bag full of worms and gets into some advanced topics outside of the scope of this tutorial. Consequently, we are going to recommend you leave your assignments non-virtual for now, in the interest of simplicity.

Ignoring virtualization

Very rarely you may want to ignore the virtualization of a function. For example, consider the following code:

1
2
3
4
5
6
7
8
9
10
11

class Base
{
public:
   virtual const char* getName() const { return "Base"; }
};

class Derived: public Base
{
public:
   virtual const char* getName() const { return "Derived"; }
};

There may be cases where you want a Base pointer to a Derived object to call Base::getName() instead of Derived::getName(). To do so, simply use the scope resolution operator:

1
2
3
4
5
6
7
8
9
10

#include <iostream>
int main()
{
   Derived derived;
   const Base &base { derived };
   // Calls Base::GetName() instead of the virtualized Derived::GetName()
   std::cout << base.Base::getName() << '\n';

   return 0;
}

You probably won’t use this very often, but it’s good to know it’s at least possible.

Should we make all destructors virtual?

This is a common question asked by new programmers. As noted in the top example, if the base class destructor isn’t marked as virtual, then the program is at risk for leaking memory if a programmer later deletes a base class pointer that is pointing to a derived object. One way to avoid this is to mark all your destructors as virtual. But should you?

It’s easy to say yes, so that way you can later use any class as a base class -- but there’s a performance penalty for doing so (a virtual pointer added to every instance of your class). So you have to balance that cost, as well as your intent.

Conventional wisdom (as initially put forth by Herb Sutter, a highly regarded C++ guru) has suggested avoiding the non-virtual destructor memory leak situation as follows, “A base class destructor should be either public and virtual, or protected and nonvirtual.” A class with a protected destructor can’t be deleted via a pointer, thus preventing the accidental deleting of a derived class through a base pointer when the base class has a non-virtual destructor. Unfortunately, this also means the base class can’t be deleted through a base class pointer, which essentially means the class can’t be dynamically allocated or deleted except by a derived class. This also precludes using smart pointers (such as std::unique_ptr and std::shared_ptr) for such classes, which limits the usefulness of that rule (we cover smart pointers in a later chapter). It also means the base class can’t be allocated on the stack. That’s a pretty heavy set of penalties.

Now that the final specifier has been introduced into the language, our recommendations are as follows:

   If you intend your class to be inherited from, make sure your destructor is virtual.
   If you do not intend your class to be inherited from, mark your class as final. This will prevent other classes from inheriting from it in the first place, without imposing any other use restrictions on the class itself.








### Pure Virtual Methods
A pure virtual function or pure virtual method is a virtual function that is required to be implemented by a derived class if the derived class is not abstract.

For more information on Pure Virtual Methods, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\AbstractClasses.md]

## Derived Object Usage

Derived classes inherits access to non­private members from their base classes. Classes can use inherited members just like normal members. The supposed benefit of member inheritance is that you can define functionality once in a base class and not have to repeat it in the derived classes.

To understand how interactions with derived objects are carried out we must understand how derived objects interact with the classes they are based on.

When we create a Derived object, it contains
  members for each Base class (which is constructed first)
  members for each Derived class (which is constructed second).

Why can’t my derived class access private base class members?  

To protect you from future changes to the base class.

Derived classes do not get access to private members of a base class. This effectively “seals off” the derived class from any changes made to the private members of the base class.

How can I protect derived classes from breaking when I change the internal parts of the base class?  

A class has two distinct interfaces for two distinct sets of clients:

  It has a public interface that serves unrelated classes
  It has a protected interface that serves derived classes

Unless you expect all your derived classes to be built by your own team, you should declare your base class’s data members as private and use protected inline access functions by which derived classes will access the private data in the base class. This way the private data declarations can change, but the derived class’s code won’t break (unless you change the protected access functions).


### Example of a Derived Class

  #include <string>

  class Base
  {
  protected:
      int m_value;

  public:
      Base(int value) : m_value{ value }{}

      std::string getName() const { return "Base"; }
      int getValue() const { return m_value; }
  };

  class Derived: Base
  {
  public:
      Derived(int value) : Base{ value }{}

      std::string getName() const { return "Derived"; }
      int getValueDoubled() const { return m_value * 2; }
  };

  void are_belong_to_us(BaseC& base) { //implementation }
  void all_about_that(Derived& derived) {//implementation }

The Derived class derives from Base class. The are_belong_to_us function takes a reference­ to a ­Base class argument, base. You can invoke it with a reference to an instance of a Derived as the Derived class derives from Base.

The opposite is not true.
Here, Base class doesn’t derive from Derived class. (The inheritance
relationship is the other way around.) The all_about_that function takes a
Derived class argument. If you attempt to invoke all_about_that with a
BaseClass, the compiler yields an error.



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

Output:

  derived is a Derived and has value 5
  rDerived is a Derived and has value 5
  pDerived is a Derived and has value 5


It is okay to convert a pointer from a derived class to its base class if they implement public inheritance

As an object of a derived class is a kind of the base class. Therefore the conversion from a derived class pointer to a base class pointer is perfectly safe, and happens all the time. For example, if I am pointing at a Car object that publicly inherits from the Vehicle class, I am in fact pointing at a vehicle, so converting a Car type pointer to a Vehicle type pointer is perfectly safe and normal:

    void f(Vehicle* v);
    void g(Car* c) { f(c); }  // Perfectly safe implicit conversion; no cast

Should I pointer-cast from a private derived class to its base class?  

Generally, No. From a member function or friend of a privately derived class, the relationship to the base class is known, and the upward conversion from PrivatelyDervived\* to Base\* (or PrivatelyDerived& to Base&) is safe; no cast is needed or recommended.

However users of PrivatelyDerived should avoid this unsafe conversion, since it is based on a private decision of PrivatelyDerived, and is subject to change without notice.



### Base pointer or reference to a derived object

However, since Derived has a Base part, an interesting question is whether C++ will let us set a Base pointer or reference to a Derived object. It turns out, we can!

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

Output:

  derived is a Derived and has value 5
  rBase is a Base and has value 5
  pBase is a Base and has value 5

This result may not be quite what you were expecting at first!

It turns out that because rBase and pBase are a Base reference and pointer, they can only see members of Base (or any classes that Base inherited). So even though Derived::getName() shadows (hides) Base::getName() for Derived objects, the Base pointer/reference can not see Derived::getName(). Consequently, they call Base::getName(), which is why rBase and pBase report that they are a Base rather than a Derived.

Note that this also means it is not possible to call Derived::getValueDoubled() using rBase or pBase. They are unable to see anything in Derived.

#### Note:
We cannot set the address value of a derived class pointer to the address of a base class instance. This is because the base class instance does not support all the capability the the derived class reference must support.

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

Not too difficult, but consider what would happen if we had 30 different animal types instead of two. You’d have to write 30 almost identical functions! Plus, if you ever added a new type of animal, you’d have to write a new function for that one too. This is a huge waste of time considering the only real difference is the type of the parameter.

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

Although both of these techniques could save us a lot of time and energy, they have the same problem. The pointer or reference to the base class calls the base version of the function rather than the derived version.

If only there was some way to make those base pointers call the derived version of a function instead of the base version…

For information on how to achieve this, see:
C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\VirtualMethods.md]

## Use Case

We will attempt to explore a pure virtual function use case by first exploring the issues that arise without pure virtual functions to highlight their usefulness.

Let’s take a look at an example that tries to define a class hierarchy with a base class Animal that seeks to implement a speak() behavior for all derived species classes:

  #include <string>
  #include <iostream>
  #include <utility>

  class Animal
  {
  protected:
      std::string m_name;

      // A protected constructor prevents the creation of Animal objects outside of derived classes
      Animal(const std::string& name) : m_name{ name } {}

  public:
      std::string getName() const { return m_name; }
      virtual const char* speak() const { return "???"; }

      virtual ~Animal() = default;
  };

  class Cat: public Animal
  {
  public:
      Cat(const std::string& name) : Animal{ name } {}

      const char* speak() const override { return "Meow"; }
  };

  main()
  {
    // Animal A{"Tom"} Compilation error: protected constructor inaccessible

    Cat cat{"Tom"};
    std:cout << cat.getName() << " says " << cat.speak() << '\n';
  }

Output:
  Tom says Meow

We’ve prevented people from allocating objects of type Animal by making the constructor protected. However, there are two problems with this:
  1) The constructor is still accessible from within derived classes, making it possible to instantiate an Animal object.
  2) It is still possible to create derived classes that do not redefine function speak().

For example:

  class Cow : public Animal
  {
  public:
      Cow(const std::string& name) : Animal{ name } {}

      // speak not redefined
  };

  int main()
  {
      Cow cow{"Betsy"};
      std::cout << cow.getName() << " says " << cow.speak() << '\n';
  }

Output:

  Betsy says ???

What happened? We did not redefine function speak(), so cow.speak() resolved to Animal.speak(), which isn’t what we wanted.


A better solution to this problem is to use a pure virtual function:

	#include <string>
	#include <iostream>

	class Animal // This Animal is an abstract base class
	{
	protected:
	    std::string m_name;

	public:
	    Animal(const std::string& name) : m_name{ name } {}

	    const std::string& getName() const { return m_name; }

	    // speak is now a pure virtual function
	    virtual const char* speak() const = 0;

	    virtual ~Animal() = default;
	};

	class Cow: public Animal
	{
	public:
			Cow(const std::string& name) : Animal{ name ) {}

			// We forgot to redefine speak
	};

	int main()
	{
			Cow cow{ "Betsy" };
			std::cout << cow.getName() << " says " << cow.speak() << '\n';

			return 0;
	}


There are a couple of things to note here:
	First, speak() is now a pure virtual function. This means Animal is now an abstract base class, and can not be instantiated. Consequently, we do not need to make the constructor protected any longer (though it doesn’t hurt).
	Second, because our Cow class was derived from Animal, but we did not define Cow::speak(), Cow is also an abstract base class.

Now when we try to compile this code:

	error C2259: 'Cow': cannot instantiate abstract class
	note: see declaration of 'Cow'
	note: due to following members:
	note: 'const char *Animal::speak(void) const': is abstract
	note: see declaration of 'Animal::speak'

The compiler will give us a warning because Cow is an abstract base class and we can not create instances of abstract base classes.

This tells us that we will only be able to instantiate Cow if Cow provides a body for speak().

Let’s go ahead and do that:

	#include <iostream>
	#include <string>

	class Cow: public Animal
	{
	public:
	    Cow(const std::string& name) : Animal{ name ) {}

	    const char* speak() const override { return "Moo"; }
	};

	int main()
	{
	    Cow cow{ "Betsy" };
	    std::cout << cow.getName() << " says " << cow.speak() << '\n';

	    return 0;
	}

Output:

  Betsy says Moo


We have now achieved our goals of
	preventing the Animal class from being instantiated
	preventing classes derived from Animal from being instantiated if they do not fulfill the contract define the methods  

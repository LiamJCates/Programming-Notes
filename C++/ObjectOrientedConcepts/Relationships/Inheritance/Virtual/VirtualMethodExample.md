Here an abstract base class Animal is used to support the derivation of classes of species. In this example the speak() function is made virtual:

```cpp
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
```
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

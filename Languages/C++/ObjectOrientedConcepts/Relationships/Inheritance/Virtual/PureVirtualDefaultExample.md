## Use Case

	#include <string>
	#include <iostream>

	class Animal // This Animal is an abstract base class
	{
	protected:
	    std::string m_name;

	public:
	    Animal(const std::string& name)
	        : m_name(name)
	    {
	    }

	    const std::string& getName() const { return m_name; }
	    virtual const char* speak() const = 0; // note that speak is a pure virtual function

	    virtual ~Animal() = default;
	};

	const char* Animal::speak() const
	{
	    return "buzz"; // some default implementation
	}

In this case, speak() is still considered a pure virtual function because of the “=0” (even though it has been given a body) and Animal is still considered an abstract base class (and thus can’t be instantiated). Any class that inherits from Animal needs to provide its own definition for speak() or it will also be considered an abstract base class.

	class Dragonfly: public Animal
	{

	public:
	    Dragonfly(const std::string& name)
	        : Animal{name}
	    {
	    }

	    const char* speak() const override// this class is no longer abstract because we defined this function
	    {
	        return Animal::speak(); // use Animal's default implementation
	    }
	};

	int main()
	{
	    Dragonfly dfly{"Sally"};
	    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';

	    return 0;
	}

Output:

	Sally says buzz

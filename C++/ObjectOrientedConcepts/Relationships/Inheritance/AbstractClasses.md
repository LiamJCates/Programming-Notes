Pure virtual (abstract) functions and abstract base classes

C++ allows you to create a special kind of virtual function called a pure virtual function (or abstract function) that has no body at all! A pure virtual function simply acts as a placeholder that is meant to be redefined by derived classes.

A pure virtual function or pure virtual method is a virtual function that is required to be implemented by a derived class if the derived class is not abstract.

When a pure virtual method exists, the class is "abstract" and can not be instantiated on its own. Instead, a derived class that implements the pure-virtual method(s) must be used. A pure-virtual isn't defined in the base-class at all, so a derived class must define it, or that derived class is also abstract, and can not be instantiated. Only a class that has no abstract methods can be instantiated.

A virtual provides a way to override the functionality of the base class, and a pure-virtual requires it.


To create a pure virtual function, rather than define a body for the function, we simply assign the function the value 0.

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
    const char* sayHi() const { return "Hi"; } // a normal non-virtual function    

    virtual const char* getName() const { return "Base"; } // a normal virtual function

    virtual int getValue() const = 0; // a pure virtual function

    int doSomething() = 0; // Compile error: can not set non-virtual functions to 0
};

When we add a pure virtual function to our class, we are effectively saying, “it is up to the derived classes to implement this function”.

Using a pure virtual function has two main consequences: First, any class with one or more pure virtual functions becomes an abstract base class, which means that it can not be instantiated! Consider what would happen if we could create an instance of Base:

1
2
3
4
5
6
7

int main()
{
    Base base; // We can't instantiate an abstract base class, but for the sake of example, pretend this was allowed
    base.getValue(); // what would this do?

    return 0;
}

Because there’s no definition for getValue(), what would base.getValue() resolve to?

Second, any derived class must define a body for this function, or that derived class will be considered an abstract base class as well.

A pure virtual function example

Let’s take a look at an example of a pure virtual function in action. In a previous lesson, we wrote a simple Animal base class and derived a Cat and a Dog class from it. Here’s the code as we left it:

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
38
39
40
41
42
43
44

#include <string>
#include <utility>

class Animal
{
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(const std::string& name)
        : m_name{ name }
    {
    }

public:
    std::string getName() const { return m_name; }
    virtual const char* speak() const { return "???"; }

    virtual ~Animal() = default;
};

class Cat: public Animal
{
public:
    Cat(const std::string& name)
        : Animal{ name }
    {
    }

    const char* speak() const override { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(const std::string& name)
        : Animal{ name }
    {
    }

    const char* speak() const override { return "Woof"; }
};

We’ve prevented people from allocating objects of type Animal by making the constructor protected. However, there are two problems with this:
1) The constructor is still accessible from within derived classes, making it possible to instantiate an Animal object.
2) It is still possible to create derived classes that do not redefine function speak().

For example:

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

#include <iostream>
#include <string>

class Cow : public Animal
{
public:
    Cow(const std::string& name)
        : Animal{ name }
    {
    }

    // We forgot to redefine speak
};

int main()
{
    Cow cow{"Betsy"};
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    return 0;
}

This will print:

Betsy says ???

What happened? We forgot to redefine function speak(), so cow.Speak() resolved to Animal.speak(), which isn’t what we wanted.

A better solution to this problem is to use a pure virtual function:

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

#include <string>

class Animal // This Animal is an abstract base class
{
protected:
    std::string m_name;

public:
    Animal(const std::string& name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
    virtual const char* speak() const = 0; // note that speak is now a pure virtual function

    virtual ~Animal() = default;
};

There are a couple of things to note here. First, speak() is now a pure virtual function. This means Animal is now an abstract base class, and can not be instantiated. Consequently, we do not need to make the constructor protected any longer (though it doesn’t hurt). Second, because our Cow class was derived from Animal, but we did not define Cow::speak(), Cow is also an abstract base class. Now when we try to compile this code:

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

#include <iostream>

class Cow: public Animal
{
public:
    Cow(const std::string& name)
        : Animal{ name }
    {
    }

    // We forgot to redefine speak
};

int main()
{
    Cow cow{ "Betsy" };
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    return 0;
}

The compiler will give us a warning because Cow is an abstract base class and we can not create instances of abstract base classes (Line numbers are wrong, because the Animal class was omitted from the above example):

<source>(33): error C2259: 'Cow': cannot instantiate abstract class
<source>(20): note: see declaration of 'Cow'
<source>(33): note: due to following members:
<source>(33): note: 'const char *Animal::speak(void) const': is abstract
<source>(15): note: see declaration of 'Animal::speak'

This tells us that we will only be able to instantiate Cow if Cow provides a body for speak().

Let’s go ahead and do that:

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

#include <iostream>
#include <string>

class Cow: public Animal
{
public:
    Cow(const std::string& name)
        : Animal(name)
    {
    }

    const char* speak() const override { return "Moo"; }
};

int main()
{
    Cow cow{ "Betsy" };
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    return 0;
}

Now this program will compile and print:

Betsy says Moo

A pure virtual function is useful when we have a function that we want to put in the base class, but only the derived classes know what it should return. A pure virtual function makes it so the base class can not be instantiated, and the derived classes are forced to define these functions before they can be instantiated. This helps ensure the derived classes do not forget to redefine functions that the base class was expecting them to.

Pure virtual functions with bodies

It turns out that we can define pure virtual functions that have bodies:

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

#include <string>

class Animal // This Animal is an abstract base class
{
protected:
    std::string m_name;

public:
    Animal(const std::string& name)
        : m_name{ name }
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() const = 0; // The = 0 means this function is pure virtual

    virtual ~Animal() = default;
};

const char* Animal::speak() const  // even though it has a body
{
    return "buzz";
}

In this case, speak() is still considered a pure virtual function because of the “=0” (even though it has been given a body) and Animal is still considered an abstract base class (and thus can’t be instantiated). Any class that inherits from Animal needs to provide its own definition for speak() or it will also be considered an abstract base class.

When providing a body for a pure virtual function, the body must be provided separately (not inline).

For Visual Studio users

Visual Studio mistakenly allows pure virtual function declarations to be definitions, for example

1
2
3
4
5

// wrong!
virtual const char* speak() const = 0
{
  return "buzz";
}

This is wrong and cannot be disabled.

This paradigm can be useful when you want your base class to provide a default implementation for a function, but still force any derived classes to provide their own implementation. However, if the derived class is happy with the default implementation provided by the base class, it can simply call the base class implementation directly. For example:

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
38
39
40
41
42
43
44
45
46
47

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

The above code prints:

Sally says buzz

This capability isn’t used very commonly.

Interface classes

An interface class is a class that has no member variables, and where all of the functions are pure virtual! In other words, the class is purely a definition, and has no actual implementation. Interfaces are useful when you want to define the functionality that derived classes must implement, but leave the details of how the derived class implements that functionality entirely up to the derived class.

Interface classes are often named beginning with an I. Here’s a sample interface class:

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

class IErrorLog
{
public:
    virtual bool openLog(const char *filename) = 0;
    virtual bool closeLog() = 0;

    virtual bool writeError(const char *errorMessage) = 0;

    virtual ~IErrorLog() {} // make a virtual destructor in case we delete an IErrorLog pointer, so the proper derived destructor is called
};

Any class inheriting from IErrorLog must provide implementations for all three functions in order to be instantiated. You could derive a class named FileErrorLog, where openLog() opens a file on disk, closeLog() closes the file, and writeError() writes the message to the file. You could derive another class called ScreenErrorLog, where openLog() and closeLog() do nothing, and writeError() prints the message in a pop-up message box on the screen.

Now, let’s say you need to write some code that uses an error log. If you write your code so it includes FileErrorLog or ScreenErrorLog directly, then you’re effectively stuck using that kind of error log (at least without recoding your program). For example, the following function effectively forces callers of mySqrt() to use a FileErrorLog, which may or may not be what they want.

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

#include <cmath> // for sqrt()

double mySqrt(double value, FileErrorLog &log)
{
    if (value < 0.0)
    {
        log.writeError("Tried to take square root of value less than 0");
        return 0.0;
    }
    else
    {
        return std::sqrt(value);
    }
}

A much better way to implement this function is to use IErrorLog instead:

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

#include <cmath> // for sqrt()
double mySqrt(double value, IErrorLog &log)
{
    if (value < 0.0)
    {
        log.writeError("Tried to take square root of value less than 0");
        return 0.0;
    }
    else
    {
        return std::sqrt(value);
    }
}

Now the caller can pass in any class that conforms to the IErrorLog interface. If they want the error to go to a file, they can pass in an instance of FileErrorLog. If they want it to go to the screen, they can pass in an instance of ScreenErrorLog. Or if they want to do something you haven’t even thought of, such as sending an email to someone when there’s an error, they can derive a new class from IErrorLog (e.g. EmailErrorLog) and use an instance of that! By using IErrorLog, your function becomes more independent and flexible.

Don’t forget to include a virtual destructor for your interface classes, so that the proper derived destructor will be called if a pointer to the interface is deleted.

Interface classes have become extremely popular because they are easy to use, easy to extend, and easy to maintain. In fact, some modern languages, such as Java and C#, have added an “interface” keyword that allows programmers to directly define an interface class without having to explicitly mark all of the member functions as abstract. Furthermore, although Java (prior to version 8) and C# will not let you use multiple inheritance on normal classes, they will let you multiple inherit as many interfaces as you like. Because interfaces have no data and no function bodies, they avoid a lot of the traditional problems with multiple inheritance while still providing much of the flexibility.

Pure virtual functions and the virtual table

Abstract classes still have virtual tables, as these can still be used if you have a pointer or reference to the abstract class. The virtual table entry for a pure virtual function will generally either contain a null pointer, or point to a generic function that prints an error (sometimes this function is named __purecall) if no override is provided.











Virtual base classes
By Alex on January 28th, 2008 | last modified by Alex on December 21st, 2020

Last chapter, in lesson 17.9 -- Multiple inheritance, we left off talking about the “diamond problem”. In this section, we will resume this discussion.

Note: This section is an advanced topic and can be skipped or skimmed if desired.

The diamond problem

Here is our example from the previous lesson (with some constructors) illustrating the diamond problem:

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

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
		std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner: public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power }
    {
		std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice{ power }
    {
		std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner{ scanner, power }, Printer{ printer, power }
    {
    }
};

Although you might expect to get an inheritance diagram that looks like this:

If you were to create a Copier class object, by default you would end up with two copies of the PoweredDevice class -- one from Printer, and one from Scanner. This has the following structure:

We can create a short example that will show this in action:

1
2
3
4
5
6

int main()
{
    Copier copier{ 1, 2, 3 };

    return 0;
}

This produces the result:

PoweredDevice: 3
Scanner: 1
PoweredDevice: 3
Printer: 2

As you can see, PoweredDevice got constructed twice.

While this is often desired, other times you may want only one copy of PoweredDevice to be shared by both Scanner and Printer.

Virtual base classes

To share a base class, simply insert the “virtual” keyword in the inheritance list of the derived class. This creates what is called a virtual base class, which means there is only one base object. The base object is shared between all objects in the inheritance tree and it is only constructed once. Here is an example (without constructors for simplicity) showing how to use the virtual keyword to create a shared base class:

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

class PoweredDevice
{
};

class Scanner: virtual public PoweredDevice
{
};

class Printer: virtual public PoweredDevice
{
};

class Copier: public Scanner, public Printer
{
};

Now, when you create a Copier class object, you will get only one copy of PoweredDevice per Copier that will be shared by both Scanner and Printer.

However, this leads to one more problem: if Scanner and Printer share a PoweredDevice base class, who is responsible for creating it? The answer, as it turns out, is Copier. The Copier constructor is responsible for creating PoweredDevice. Consequently, this is one time when Copier is allowed to call a non-immediate-parent constructor directly:

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
38
39
40

#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
		std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power } // this line is required to create Scanner objects, but ignored in this case
    {
		std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Printer(int printer, int power)
        : PoweredDevice{ power } // this line is required to create Printer objects, but ignored in this case
    {
		std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : PoweredDevice{ power }, // PoweredDevice is constructed here
        Scanner{ scanner, power }, Printer{ printer, power }
    {
    }
};

This time, our previous example:

1
2
3
4
5
6

int main()
{
    Copier copier{ 1, 2, 3 };

    return 0;
}

produces the result:

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

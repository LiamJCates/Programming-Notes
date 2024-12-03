## Avoiding Inheritance Using final

Starting with C++11, compilers support specifier final. A class declared as final cannot be used as a base class.

There may be cases where you don’t want someone to be able to override a virtual function, or inherit from a class. The final specifier can be used to tell the compiler to enforce this. If the user tries to override a function or inherit from a class that has been specified as final, the compiler will give a compile error.

Now that the final specifier has been introduced into the language, our recommendations are as follows:

   If you intend your class to be inherited from, make sure your destructor is virtual.
   If you do not intend your class to be inherited from, mark your class as final. This will prevent other classes from inheriting from it in the first place, without imposing any other use restrictions on the class itself.



#### Prevent Method Override

In the case where we want to restrict the user from overriding a function, the final specifier is used as a function suffix:

  class A
  {
  public:
  	virtual const char* getName() { return "A"; }
  };

  class B : public A
  {
  public:
  	// note use of final specifier on following line -- that makes this function no longer overridable
  	virtual const char* getName() override final { return "B"; } // okay, overrides A::getName()
  };

  class C : public B
  {
  public:
  	virtual const char* getName() override { return "C"; } // compile error: overrides B::getName(), which is final
  };

In the above code, B::getName() overrides A::getName(), which is fine. But B::getName() has the final specifier, which means that any further overrides of that function should be considered an error. And indeed, C::getName() tries to override B::getName() (the override specifier here isn’t relevant, it’s just there for good practice), so the compiler will give a compile error.



#### Prevent Inheritance

In the case where we want to prevent inheriting from a class, the final specifier is applied after the class name:

  class A
  {
  public:
  	virtual const char* getName() { return "A"; }
  };

  class B final : public A // note use of final specifier here
  {
  public:
  	virtual const char* getName() override { return "B"; }
  };

  class C : public B // compile error: cannot inherit from final class
  {
  public:
  	virtual const char* getName() override { return "C"; }
  };

In the above example, class B is declared final. Thus, when C tries to inherit from B, the compiler will give a compile error.




### Covariant return types

There is one special case in which a derived class virtual function override can have a different return type than the base class and still be considered a matching override. If the return type of a virtual function is a pointer or a reference to a class, override functions can return a pointer or a reference to a derived class. These are called covariant return types. Here is an example:

  #include <iostream>

  class Base
  {
  public:
  	// This version of getThis() returns a pointer to a Base class
  	virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
  	void printType() { std::cout << "returned a Base\n"; }
  };

  class Derived : public Base
  {
  public:
  	// Normally override functions have to return objects of the same type as the base function
  	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
  	Derived* getThis() override { std::cout << "called Derived::getThis()\n";  return this; }
  	void printType() { std::cout << "returned a Derived\n"; }
  };

  int main()
  {
  	Derived d{};
  	Base* b{ &d };
  	d.getThis()->printType(); // calls Derived::getThis(), returns a Derived*, calls Derived::printType
  	b->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType

  	return 0;
  }

Output:

  called Derived::getThis()
  returned a Derived
  called Derived::getThis()
  returned a Base

Note that some older compilers do not support covariant return types.

One interesting note about covariant return types: C++ can’t dynamically select types, so you’ll always get the type that matches the base version of the function being called.

In the above example, we first call d.getThis(). Since d is a Derived, this calls Derived::getThis(), which returns a Derived\*. This Derived\* is then used to call non-virtual function Derived::printType().
Now the interesting case. We then call b->getThis(). Variable b is a Base pointer to a Derived object. Base::getThis() is virtual function, so this calls Derived::getThis(). Although Derived::getThis() returns a Derived\*, because base version of the function returns a Base\*, the returned Derived\* is upcast to a Base\*. And thus, Base::printType() is called.

In other words, in the above example, you only get a Derived* if you call getThis() with an object that is typed as a Derived object in the first place.






example
A situation in which we might want to prevent some inheritance functionality follows.

Suppose class Platypus represents a well-evolved species. You may therefore want to ensure that this class is final, thereby blocking every possibility to inherit from it.

A version of class Platypus, declared as final would look like this:

class Platypus final: public Mammal, public Bird, public Reptile
{
public:
  void Swim()
  {
    cout << "Platypus: Voila, I can swim!" << endl;
  }
};


Similarly, a virtual function declared as final cannot be overridden in a derived class.

Thus, a version of class Tuna that doesn’t allow any further specialization of virtual function Swim() would look like this:

class Tuna : public Fish
{
public:
  // override Fish::Swim and make this final
  void Swim() override final
  {
    cout << "Tuna swims!" << endl;
  }
};

This version of Tuna can be inherited from, but Swim() cannot be overridden:

class BluefinTuna final:public Tuna
{
public:
  void Swim() // Error: Swim() was final in Tuna, cannot override
  { //body }
};

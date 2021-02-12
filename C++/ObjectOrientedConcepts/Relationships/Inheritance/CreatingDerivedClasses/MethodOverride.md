### Derived Class Overriding Base Class’s Methods

If a class Derived implements the same functions with the same return values and signatures as in a class Base it inherits from, it effectively overrides that method in class Base as shown in the following code:

class Base
{
public:
  void DoSomething()
  {
    // implementation code… Does something
  }
};

class Derived : public Base
{
public:
  void DoSomething()
  {
  // implementation code… Does something else
  }
};

Thus, if method DoSomething() were to be invoked using an instance of Derived, then it would not invoke the functionality in class Base



### Invoking Overridden Methods of a Base Class

The only way to invoke a base class method from the derived class is by the scope resolution operator (::).

Suppose the class Tuna is derived from the class Fish and both have a method called swim.

  Tuna MyDinner;
  myDinner.swim();

The above call will resolve to the swim method in Tuna.

To invoke swim in fish use the scope resolution operator (::) syntax:

  myDinner.Fish::swim();

The above invokes Fish::swim() using an instance of Tuna.



### Derived Class Hiding Base Class’s Methods

Overriding can take an extreme form where Tuna::Swim() can potentially hide all overloaded versions of Fish::Swim() available, even causing compilation failure when the overloaded ones are used (hence, called hidden)

Suppose Fish contains two overloaded methods for swim().

  Fish::swim()
  Fish::swim(bool)

As Tuna inherits public from Fish one would not be wrong to expect that both versions of method Fish::Swim() would be available via an instance of class Tuna.

If Tuna implements its own Tuna::swim() it results in the hiding of Fish::Swim(bool) from the compiler.

To invoke the Fish::Swim(bool) function via an instance of Tuna, you have the following solutions:

1) Use the scope resolution operator:

  myDinner.Fish::Swim();

2) Use keyword using in class Tuna to unhide Swim() in class Fish:

class Tuna: public Fish
{
public:
  using Fish::Swim; // unhide all Swim() methods in class Fish
  void Swim()
  {
    cout << "Tuna swims real fast" << endl;
  }
};

3) Override all overloaded variants of Swim() in class Tuna (invoke
methods of Fish::Swim(...) via Tuna::Fish(...) if you want):

class Tuna: public Fish
{
public:
  void Swim(bool isFreshWaterFish)
  {
    Fish::Swim(isFreshWaterFish);
  }
  void Swim()
  {
    cout << "Tuna swims real fast" << endl;
  }
};

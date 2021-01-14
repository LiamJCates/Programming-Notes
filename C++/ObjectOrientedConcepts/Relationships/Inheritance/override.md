### The Issue Addressed

A derived class virtual function is only considered an override if its signature and return types match exactly. That can lead to inadvertent issues, where a function that was intended to be an override actually isn’t.

Consider the following example:

  class A
  {
  public:
  	virtual const char* getName1(int x) { return "A"; }
  	virtual const char* getName2(int x) { return "A"; }
  };

  class B : public A
  {
  public:
    // note: parameter is a short int
  	virtual const char* getName1(short int x) { return "B"; }

    // note: function is const
    virtual const char* getName2(int x) const { return "B"; }
  };

  int main()
  {
  	B b{};
  	A& rBase{ b };
  	std::cout << rBase.getName1(1) << '\n';
  	std::cout << rBase.getName2(2) << '\n';

  	return 0;
  }

Output:

  A
  A

Because rBase is an A reference to a B object, the intention here is to use virtual functions to access B::getName1() and B::getName2(). However, because B::getName1() takes a different parameter (a short int instead of an int), it’s not considered an override of A::getName1(). More insidiously, because B::getName2() is const and A::getName2() isn’t, B::getName2() isn’t considered an override of A::getName2().


In this particular case, because A and B just print their names, it’s fairly easy to see that we messed up our overrides, and that the wrong virtual function is being called. However, in a more complicated program, where the functions have behaviors or return values that aren’t printed, such issues can be very difficult to debug.


### The override specifier

To help address the issue of functions that are meant to be overrides but aren’t, C++11 introduced the override specifier. The override specifier can be applied to any override function as a suffix. If the function does not override a base class function (or is applied to a non-virtual function), the compiler will flag the function as an error.

  class A
  {
  public:
  	virtual const char* getName1(int x) { return "A"; }
  	virtual const char* getName2(int x) { return "A"; }
  	virtual const char* getName3(int x) { return "A"; }
  };
   
  class B : public A
  {
  public:
  	virtual const char* getName1(short int x) override { return "B"; } // compile error, function is not an override
  	virtual const char* getName2(int x) const override { return "B"; } // compile error, function is not an override
  	virtual const char* getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)

  };

  int main()
  {
  	return 0;
  }

The above program produces two compile errors: one for B::getName1(), and one for B::getName2(), because neither override a prior function. B::getName3() does override A::getName3(), so no error is produced for that line.

There is no performance penalty for using the override specifier, and it helps avoid inadvertent errors. Consequently, we highly recommend using it for every virtual function override you write to ensure you’ve actually overridden the function you think you have.

Rule

Apply the override specifier to every intended override function you write.

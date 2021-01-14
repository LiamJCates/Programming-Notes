virtual inheritance










Example

class BaseClass
{
public:
  BaseClass() { }
  void f(char *s = "unknown")
  {
    cout << "Function f() in BaseClass called from " << s << endl;
    h();
  }

protected:
  void g(char *s = "unknown")
  {
    cout << "Function g() in BaseClass called from " << s << endl;
  }

private:
  void h()
  {
    cout << "Function h() in BaseClass\n";
  }
};

class Derived1Level1 : public virtual BaseClass
{
public:
  void f(char *s = "unknown")
  {
    cout << "Function f() in Derived1Level1 called from " << s << endl;
    g("Derived1Level1");
    h("Derived1Level1");
  }
  void h(char *s = "unknown")
  {
    cout << "Function h() in Derived1Level1 called from " << s << endl;
  }
};

class Derived2Level1 : public virtual BaseClass
{
public:
  void f(char *s = "unknown")
  {
    cout << "Function f() in Derived2Level1 called from " << s << endl;
    g("Derived2Level1");
    // h(); // error: BaseClass::h() is not accessible
  }
};

class DerivedLevel2 : public Derived1Level1, public Derived2Level1
{
public:
  void f(char *s = "unknown")
  {
    cout << "Function f() in DerivedLevel2 called from " << s << endl;
    g("DerivedLevel2");
    Derived1Level1::h("DerivedLevel2");
    BaseClass::f("DerivedLevel2");
  }
};

int main()
{
  BaseClass bc;
  Derived1Level1 d1l1;
  Derived2Level1 d2l1;
  DerivedLevel2 dl2;
  bc.f("main(1)");

  // bc.g(); // error: BaseClass::g() is not accessible
  // bc.h(); // error: BaseClass::h() is not accessible
  d1l1.f("main(2)");

  // d1l1.g(); // error: BaseClass::g() is not accessible
  d1l1.h("main(3)");
  d2l1.f("main(4)");

  // d2l1.g(); // error: BaseClass::g() is not accessible
  // d2l1.h(); // error: BaseClass::h() is not accessible
  dl2.f("main(5)");

  // dl2.g(); // error: BaseClass::g() is not accessible
  dl2.h();
}

Output:
  Function f() in BaseClass called from main(1)
  Function h() in BaseClass
  Function f() in Derived1Level1 called from main(2)
  Function g() in BaseClass called from Derived1Level1
  Function h() in Derived1Level1 called from Derived1Level1
  Function h() in Derived1Level1 called from main(3)
  Function f() in Derived2Level1 called from main(4)
  Function g() in BaseClass called from Derived2Level1
  Function f() in DerivedLevel2 called from main(5)
  Function g() in BaseClass called from DerivedLevel2
  Function h() in Derived1Level1 called from DerivedLevel2
  Function f() in BaseClass called from DerivedLevel2
  Function h() in BaseClass
  Function h() in Derived1Level1 called from unknown


Derived classes inherit all protected or public members from their base class so that they do not have to repeat the same definitions.

A derived class can override the definition of a member function by introducing its own definition. In this way, both the base class and
the derived class have some measure of control over their member functions.

The base class can decide which member functions and data members can be revealed to derived classes so that the principle of information hiding holds not only with respect to the user of the base class, but also to the derived classes.

Moreover, the derived class can decide which parts of the public and protected member functions and data members to retain and use and which to modify.

For example, both Derived1Level1 and Derived2Level1 define their own versions of f(). However, the access to the member function with the same name in any of the classes higher up in the hierarchy is still possible by preceding the function with the name of the class and the scope operator, as shown in the call of BaseClass::f() from f() in DerivedLevel2.



A derived class can add some new members of its own. Such a class can become a base class for other classes that can be derived from it so that the inheritance hierarchy can be deliberately extended. For example, the class Derived1Level1 is derived from BaseClass, but at the same time, it is the base class for DerivedLevel2.

Inheritance in our examples is specified as public, this means that public members of the base class are also public in the derived class, and protected members are also protected.

In the case of protected inheritance (with the word protected in the heading of the definition), both public and protected members of the base class become protected in the derived class.

Finally, for private inheritance, both public and protected members of the base class become private in the derived class. In all types of inheritance, private members of the base class are inaccessible to any of the derived classes.

For example, an attempt to call h() from f() in Derived2Level1 causes a compilation error, “BaseClass::h() is not accessible.”

However, a call of h() from f() in Derived1Level1 causes no problem because it is a call to h() defined in Derived1Level1.

Protected members of the base class are accessible only to derived classes and not to nonderived classes. For this reason, both Derived1Level1 and Derived2Level1 can call BaseClass's protected member function g(), but a call to this function from main() is rendered illegal.

A derived class does not have to be limited to one base class only. It can be derived from more than one base class.

For example, DerivedLevel2 is defined as a class derived from both Derived1Level1 and Derived2Level1, inheriting in this way all the member functions of Derived1Level1 and Derived2Level1.

However, DerivedLevel2 also inherits the same member functions from BaseClass twice because both classes used in the definition of DerivedLevel2 are derived from BaseClass. This is redundant at best, and at worst can cause a compilation error, "member is ambiguous BaseClass::g() and BaseClass::g()."

To prevent this from happening, the definitions of the two classes include the modifier virtual, which means that DerivedLevel2 contains only one copy of each member function from BaseClass. A similar problem arises if f() in DerivedLevel2 calls h() without the preceding scope operator and class name, Derived1Level1::h(). It does not matter that h() is private in BaseClass and inaccessible to DerivedLevel2. An error would be printed, "member is ambiguous Derived1Level1::h() and BaseClass::h()."

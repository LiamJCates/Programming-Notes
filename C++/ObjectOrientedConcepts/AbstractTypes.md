Abstract Types

Concrete types are defined by their representation being part of their definition. In that, they resemble built-in types.

In contrast, an abstract type is a type that completely insulates a user from implementation details.

To do that, we decouple the interface from the representation and give up genuine local variables. Since we don’t know anything about the representation of an abstract type (not even its size), we must allocate objects on the free store and access them through references or pointers.

First, we define the interface of a class Container, which we will design as a more abstract version of a vector:

class Container {
public:
  virtual double& operator[](int) = 0; // pure virtual function
  virtual int size() const = 0;        // const member function (§4.2.1)
  virtual ˜Container() {}              // destructor (§4.2.2)
};

This class is a pure interface to specific containers defined later. The word virtual means ‘‘may be redefined later in a class derived from this one.’’

Unsurprisingly, a function declared virtual is called a virtual function. A class derived from Container provides an implementation for the Container interface. The curious =0 syntax says the function is pure virtual; that is, some class derived from Container must define the function. Thus, it is not possible to define an object that is just a Container.

For example:
Container c; // error : there can be no objects of an abstract class
Container∗ p = new Vector_container(10); // OK: Container is an interface

A Container can only serve as the interface to a class that implements its operator[]() and size() functions. A class with a pure virtual function is called an abstract class.

This Container can be used like this:
void use(Container& c)
{
  const int sz = c.size();
  for (int i=0; i!=sz; ++i)
  cout << c[i] << '\n';
}

Note how use() uses the Container interface in complete ignorance of implementation details. It uses size() and [] without any idea of exactly which type provides their implementation. A class that provides the interface to a variety of other classes is often called a polymorphic type.

As is common for abstract classes, Container does not have a constructor. After all, it does not have any data to initialize. On the other hand, Container does have a destructor and that destructor is virtual, so that classes derived from Container can provide implementations. Again, that is common for abstract classes because they tend to be manipulated through references or pointers, and
someone destroying a Container through a pointer has no idea what resources are owned by its implementation;

The abstract class Container defines only an interface and no implementation. For Container to be useful, we have to implement a container that implements the functions required by its interface. For that, we could use the concrete class Vector:

class Vector_container : public Container {
public:
  Vector_container(int s) : v(s) { } // Vector of s elements
  ˜Vector_container() {}
  double& operator[](int i) override { return v[i]; }
  int size() const override { return v.siz e(); }
private:
  Vector v;
};

The members operator[]() and size() override the corresponding members in the base class Container. The explicit override is used to make clear what’s intended. The use of override is optional, but being explicit allows the compiler to catch mistakes, such as misspellings of function names or slight differences between the type of a virtual function and its intended overrider.

The explicit use of override is particularly useful in larger class hierarchies where it can otherwise be hard to know what is supposed to override what.

The destructor (˜Vector_container()) overrides the base class destructor (˜Container()). Note that the member destructor (˜Vector()) is implicitly invoked by its class’s destructor (˜Vector_container()).

For a function like use(Container&) to use a Container in complete ignorance of implementation details, some other function will have to make an object on which it can operate. For example:

void g()
{
  Vector_container vc(10); // Vector of ten elements
  // ... fill vc ...
  use(vc);
}

Since use() doesn’t know about Vector_containers but only knows the Container interface, it will work just as well for a different implementation of a Container. For example:

class List_container : public Container {
public:
  List_container() { } // empty List
  List_container(initializ er_list<double> il) : ld{il} { }
  ˜List_container() {}
  double& operator[](int i) override;
  int size() const override { return ld.size(); }
private:
  std::list<double> ld; // (standard-librar y) list of doubles (§11.3)
};

double& List_container::operator[](int i)
{
  for (auto& x : ld) {
  if (i==0)
    return x;
  −−i;
  }
  throw out_of_range{"List container"};
}

Here, the representation is a standard-library list<double>. Usually, I would not implement a container with a subscript operation using a list, because performance of list subscripting is atrocious compared to vector subscripting. However, here I just wanted to show an implementation that is radically different from the usual one.

A function can create a List_container and have use() use it:

void h()
{
  List_container lc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  use(lc);
}

The point is that use(Container&) has no idea if its argument is a Vector_container, a List_container, or some other kind of container; it doesn’t need to know. It can use any kind of Container. It knows only the interface defined by Container. Consequently, use(Container&) needn’t be recompiled if the implementation of List_container changes or a brand-new class derived from Container is used.

The flip side of this flexibility is that objects must be manipulated through pointers or references (§5.2, §13.2.1).

Template specialization
It is possible to define a different implementation for a template when a specific type is passed as template argument. This is called a template specialization.

For example, let's suppose that we have a very simple class called mycontainer that can store one element of any type and that has just one member function called increase, which increases its value. But we find that when it stores an element of type char it would be more convenient to have a completely different implementation with a function member uppercase, so we decide to declare a class template specialization for that type:


  #include <iostream>
  using namespace std;

  // class template:
  template <class T>
  class mycontainer {
      T element;
    public:
      mycontainer (T arg) {element=arg;}
      T increase () {return ++element;}
  };

  // class template specialization:
  template <>
  class mycontainer <char> {
      char element;
    public:
      mycontainer (char arg) {element=arg;}
      char uppercase ()
      {
        if ((element>='a')&&(element<='z'))
        element+='A'-'a';
        return element;
      }
  };

  int main () {
    mycontainer<int> myint (7);
    mycontainer<char> mychar ('j');
    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl;
    return 0;
  }

This is the syntax used for the class template specialization:

  template <> class mycontainer <char> { ... };

First of all, notice that we precede the class name with template<> , including an empty parameter list. This is because all types are known and no template arguments are required for this specialization, but still, it is the specialization of a class template, and thus it requires to be noted as such.

But more important than this prefix, is the <char> specialization parameter after the class template name. This specialization parameter itself identifies the type for which the template class is being specialized (char). Notice the differences between the generic class template and the specialization:

  template <class T> class mycontainer { ... };
  template <> class mycontainer <char> { ... };

The first line is the generic template, and the second one is the specialization.

When we declare specializations for a template class, we must also define all its members, even those identical to the generic template class, because there is no "inheritance" of members from the generic template to the specialization.

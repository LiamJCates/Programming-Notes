Member functions and static members can be defined outside their class declaration if they have already been declared, but not defined, in the class member list. Nonstatic data members are defined when an object of their class is created. The declaration of a static data member is not a definition. The declaration of a member function is a definition if the body of the function is also given.

Whenever the definition of a class member appears outside of the class declaration, the member name must be qualified by the class name using the :: (scope resolution) operator.

The following example defines a member function outside of its class declaration.

  #include <iostream>
  using namespace std;

  struct X {
    int a, b ;

    // member function declaration only
    int add();
  };

  // global variable
  int a  = 10;

  // define member function outside its class declaration
  int X::add() { return a + b; }

  int main() {
    int answer;
    X xobject;
    xobject.a = 1;
    xobject.b = 2;
    answer = xobject.add();
    cout << xobject.a << " + " << xobject.b << " = " << answer << endl;
  }

Output:
1 + 2 = 3

All member functions are in class scope even if they are defined outside their class declaration. In the above example, the member function add() returns the data member a, not the global variable a.

The name of a class member is local to its class. Unless you use one of the class access operators, . (dot), or -> (arrow), or :: (scope resolution) operator, you can only use a class member in a member function of its class and in nested classes. You can only use types, enumerations and static members in a nested class without qualification with the :: operator.

The order of search for a name in a member function body is:

  Within the member function body itself
  Within all the enclosing classes, including inherited members of those classes
  Within the lexical scope of the body declaration

The search of the enclosing classes, including inherited members, is demonstrated in the following example:

class A { /* ... */ };
class B { /* ... */ };
class C { /* ... */ };
class Z : A {
      class Y : B {
            class X : C { int f(); /* ... */ };
      };
};
int Z::Y::X f()
{
  char j;
  return 0;
}

In this example, the search for the name j in the definition of the function f follows this order:

  In the body of the function f
  In X and in its base class C
  In Y and in its base class B
  In Z and in its base class A
  In the lexical scope of the body of f. In this case, this is global scope.

Note that when the containing classes are being searched, only the definitions of the containing classes and their base classes are searched. The scope containing the base class definitions (global scope, in this example) is not searched.

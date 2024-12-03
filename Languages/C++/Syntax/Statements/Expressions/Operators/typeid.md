typeid

The typeid operator allows the type of an object to be determined at run time.


| Name | Syntax | Overloadable |
|------|--------|--------------|
| type identification | typeid(type) |
| type identification of Varible | typeid(a) |

Syntax
  typeid(type-id)
  typeid(expression)

Type-id may be used in the following situations:

  to specify the target type in cast expressions;
  as arguments to sizeof, alignof, alignas, new, and typeid;
  on the right-hand side of a type alias declaration;
  as the trailing return type of a function declaration;
  as the default argument of a template type parameter;
  as the template argument for a template type parameter;
  in dynamic exception specification.


The result of typeid is a const type_info&. The value is a reference to a type_info object that represents either the type-id or the type of the expression, depending on which form of typeid is used.

The typeid operator doesn't work with managed types (abstract declarators or instances). For information on getting the Type of a specified type, see typeid.

The typeid operator does a run-time check when applied to an l-value of a polymorphic class type, where the true type of the object can't be determined by the static information provided. Such cases are:
    A reference to a class
    A pointer, dereferenced with *
    A subscripted pointer ([ ]). (It's not safe to use a subscript with a pointer to a polymorphic type.)

If the expression points to a base class type, yet the object is actually of a type derived from that base class, a type_info reference for the derived class is the result. The expression must point to a polymorphic type (a class with virtual functions). Otherwise, the result is the type_info for the static class referred to in the expression. Further, the pointer must be dereferenced so that the object used is the one it points to. Without dereferencing the pointer, the result will be the type_info for the pointer, not what it points to.

If the expression is dereferencing a pointer, and that pointer's value is zero, typeid throws a bad_typeid exception. If the pointer doesn't point to a valid object, a __non_rtti_object exception is thrown. It indicates an attempt to analyze the RTTI that triggered a fault because the object is somehow invalid. (For example, it's a bad pointer, or the code wasn't compiled with /GR).

If the expression is not a pointer, and not a reference to a base class of the object, the result is a type_info reference representing the static type of the expression. The static type of an expression refers to the type of an expression as it is known at compile time. Execution semantics are ignored when evaluating the static type of an expression. Furthermore, references are ignored when possible when determining the static type of an expression

typeid can also be used in templates to determine the type of a template parameter

typeid
typeid allows to check the type of an expression:

typeid (expression)

This operator returns a reference to a constant object of type type_info that is defined in the standard header <typeinfo>. A value returned by typeid can be compared with another value returned by typeid using operators == and != or can serve to obtain a null-terminated character sequence representing the data type or class name by using its name() member.

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



// typeid
#include <iostream>
#include <typeinfo>
using namespace std;

int main () {
  int * a,b;
  a=0; b=0;
  if (typeid(a) != typeid(b))
  {
    cout << "a and b are of different types:\n";
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
  }
  return 0;
}



a and b are of different types:
a is: int *
b is: int  


Edit & Run


When typeid is applied to classes, typeid uses the RTTI to keep track of the type of dynamic objects. When typeid is applied to an expression whose type is a polymorphic class, the result is the type of the most derived complete object:

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



// typeid, polymorphic class
#include <iostream>
#include <typeinfo>
#include <exception>
using namespace std;

class Base { virtual void f(){} };
class Derived : public Base {};

int main () {
  try {
    Base* a = new Base;
    Base* b = new Derived;
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
  } catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }
  return 0;
}



a is: class Base *
b is: class Base *
*a is: class Base
*b is: class Derived


Edit & Run


Note: The string returned by member name of type_info depends on the specific implementation of your compiler and library. It is not necessarily a simple string with its typical type name, like in the compiler used to produce this output.

Notice how the type that typeid considers for pointers is the pointer type itself (both a and b are of type class Base *). However, when typeid is applied to objects (like *a and *b) typeid yields their dynamic type (i.e. the type of their most derived complete object).

If the type typeid evaluates is a pointer preceded by the dereference operator (*), and this pointer has a null value, typeid throws a bad_typeid exception.

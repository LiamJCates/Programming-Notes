## Class Template Definitions
Class templates are used to write a single code segment for a set of related classes. Using class templates, we create a generic class, and the compiler can generate the appropriate source code for a specific implementation.

Thus parameterized types generalize our types by making it a template.

Syntax:
template <class T>
class ClassName{
  //class body
}

Class templates are called parameterized types because, based on the parameter
T, a specific class is generated. Here, T is the placeholder type name, which will be specified when a class is instantiated.

You can define more than one generic data type by using a comma-separated list.

Example:
Consider MyTemplateClass which takes three template parameters: X, Y, and Z.

template<typename X, typename Y, typename Z>
struct MyTemplateClass
{
  X foo(Y&);
  private:
  Z* member;
};

The template keyword begins the template prefix, which contains the template parameters.

This template preamble leads to something special about the remaining declaration of MyTemplateClass. Within MyTemplateClass, you use X, Y, and Z as if they were any fully specified type, like an int or a user-defined class.

The foo method takes a Y reference and returns an X. You can declare
members with types that include template parameters, like a pointer to Z.





## Example

template<typename T>
class Vector {
private:
  T∗ elem; // elem points to an array of sz elements of type T
  int sz;
public:
  explicit Vector(int s); // constructor: establish invariant, acquire resources
  ˜Vector() { delete[] elem; } // destructor: release resources

  // ... copy and move operations ...

  T& operator[](int i); // for non-const Vectors
  const T& operator[](int i) const; // for const Vectors (§4.2.1)
  int size() const { return sz; }
};

The template<typename T> prefix makes T a parameter of the declaration it prefixes. It is C++’s version of the mathematical ‘‘for all T’’ or more precisely ‘‘for all types T.’’ If you want the mathematical ‘‘for all T, such that P(T),’’ you need concepts.

In case that a member function is defined outside the defintion of the class template, it shall be preceded with the template <...> prefix:

template<typename T>
Vector<T>::Vector(int s)
{
  if (s<0)
    throw Negative_size{};
  elem = new T[s];
  sz = s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
  if (i<0 || size()<=i)
  throw out_of_range{"Vector::operator[]"};
  return elem[i];
}

Given these definitions, we can define Vectors like this:

Vector<char> vc(200); // vector of 200 characters
Vector<string> vs(17); // vector of 17 strings
Vector<list<int>> vli(45); // vector of 45 lists of integers


We can use Vectors like this:
void write(const Vector<string>& vs) // Vector of some strings
{
  for (int i = 0; i!=vs.size(); ++i)
  cout << vs[i] << '\n';
}

To support the range-for loop for our Vector, we must define suitable begin() and end() functions:

template<typename T>
T∗ begin(Vector<T>& x)
{
  return x.size() ? &x[0] : nullptr; // pointer to first element or nullptr
}

template<typename T>
T∗ end(Vector<T>& x)
{
  return x.size() ? &x[0]+x.size() : nullptr; // pointer to one-past-last element
}

Given those, we can write:

void f2(Vector<string>& vs) // Vector of some strings
{
for (auto& s : vs)
cout << s << '\n';
}

Similarly, we can define lists, vectors, maps (that is, associative arrays), unordered maps (that is, hash tables), etc., as templates.

A template plus a set of template arguments is called an instantiation or a specialization. Late in the compilation process, at instantiation time, code is generated for each instantiation used in a program. The code generated is type checked so that the generated code is as type safe as handwritten code. Unfortunately, that type check often occurs late in the compilation process, at
instantiation time.

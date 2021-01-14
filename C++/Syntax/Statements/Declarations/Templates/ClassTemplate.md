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









Splitting up template classes

A template is not a class or a function -- it is a stencil used to create classes or functions. As such, it does not work in quite the same way as normal functions or classes. In most cases, this isn’t much of a issue. However, there is one area that commonly causes problems for developers.

Each templated member function defined outside the class declaration needs its own template declaration.

With non-template classes, the common procedure is to put the class definition in a header file, and the member function definitions in a similarly named code file. In this way, the source for the class is compiled as a separate project file. However, with templates, this does not work. Consider the following:

Array.h:
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

#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

template <class T>
class Array
{
private:
    int m_length{};
    T* m_data{};

public:

    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{};
        m_length = length;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array()
    {
        delete[] m_data;
    }

    void Erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const;
};

#endif

Array.cpp:
1
2
3
4
5
6
7

#include "Array.h"

template <class T>
int Array<T>::getLength() const // note class name is Array<T>, not Array
{
  return m_length;
}

main.cpp:
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

#include "Array.h"

int main()
{
	Array<int> intArray(12);
	Array<double> doubleArray(12);

	for (int count{ 0 }; count < intArray.getLength(); ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}

	for (int count{ intArray.getLength() - 1 }; count >= 0; --count)
		std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';

	return 0;
}

The above program will compile, but cause a linker error:

unresolved external symbol "public: int __thiscall Array::getLength(void)" (?GetLength@?$Array@H@@QAEHXZ)

In order for the compiler to use a template, it must see both the template definition (not just a declaration) and the template type used to instantiate the template. Also remember that C++ compiles files individually. When the Array.h header is #included in main, the template class definition is copied into main.cpp. When the compiler sees that we need two template instances, Array<int>, and Array<double>, it will instantiate these, and compile them as part of main.cpp. However, when it gets around to compiling Array.cpp separately, it will have forgotten that we need an Array<int> and Array<double>, so that template function is never instantiated. Thus, we get a linker error, because the compiler can’t find a definition for Array<int>::getLength() or Array<double>::getLength().

There are quite a few ways to work around this.

The easiest way is to simply put all of your template class code in the header file (in this case, put the contents of Array.cpp into Array.h, below the class). In this way, when you #include the header, all of the template code will be in one place. The upside of this solution is that it is simple. The downside here is that if the template class is used in many places, you will end up with many local copies of the template class, which can increase your compile and link times (your linker should remove the duplicate definitions, so it shouldn’t bloat your executable). This is our preferred solution unless the compile or link times start to become a problem.

If you feel that putting the Array.cpp code into the Array.h header makes the header too long/messy, an alternative is to rename Array.cpp to Array.inl (.inl stands for inline), and then include Array.inl from the bottom of the Array.h header. That yields the same result as putting all the code in the header, but helps keep things a little cleaner.

Other solutions involve #including .cpp files, but we don’t recommend these because of the non-standard usage of #include.

Another alternative is to use a three-file approach. The template class definition goes in the header. The template class member functions goes in the code file. Then you add a third file, which contains all of the instantiated classes you need:

templates.cpp:
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

// Ensure the full Array template definition can be seen
#include "Array.h"
#include "Array.cpp" // we're breaking best practices here, but only in this one place

// #include other .h and .cpp template definitions you need here

template class Array<int>; // Explicitly instantiate template Array<int>
template class Array<double>; // Explicitly instantiate template Array<double>

// instantiate other templates here

The “template class” command causes the compiler to explicitly instantiate the template class. In the above case, the compiler will stencil out both Array<int> and Array<double> inside of templates.cpp. Because templates.cpp is inside our project, this will then be compiled. These functions can then be linked to from elsewhere.

This method is more efficient, but requires maintaining the templates.cpp file for each program.

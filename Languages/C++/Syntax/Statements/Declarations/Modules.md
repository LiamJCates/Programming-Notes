Modules (C++20)
The use of #includes is a very old, error-prone, and rather expensive way of composing programs out of parts.

If you #include header.h in 101 translation units, the text of header.h will be processed by the compiler 101 times.

If you #include header1.h before header2.h the declarations and macros in header1.h might affect the meaning of the code in header2.h. If instead you #include header2.h before header1.h, it is header2.h that might affect the code in header1.h.

Obviously, this is not ideal, and in fact it has been a major source of cost and bugs since 1972 when this mechanism was first introduced into C



Modules (since C++20)

Modules help divide large amounts of code into logical parts.

Modules are orthogonal to namespaces.
```cpp
// helloworld.cpp
export module helloworld;  // module declaration
import <iostream>;         // import declaration

export void hello() {      // export declaration
    std::cout << "Hello world!\n";
}

// main.cpp
import helloworld;  // import declaration

int main() {
    hello();
}
```
Syntax
export(optional) module module-name module-partition(optional) attr(optional) ; 	(1) 	
export declaration 	(2) 	
export { declaration-seq(optional) } 	(3) 	
export(optional) import module-name attr(optional) ; 	(4) 	
export(optional) import module-partition attr(optional) ; 	(5) 	
export(optional) import header-name attr(optional) ; 	(6) 	
module ; 	(7) 	
module : private ; 	(8) 	
1) Module declaration. Declares that the current translation unit is a module unit.
2,3) Export declaration. Export all namespace-scope declarations in declaration or declaration-seq.
4,5,6) Import declaration. Import a module unit/module partition/header unit.
7) Starts a global module fragment.
8) Starts a private module fragment.





We are finally about to get a better way of expressing physical modules in C++. The language
feature, called modules is not yet ISO C++, but it is an ISO Technical Specification [ModulesTS]
and will be part of C++20. Implementations are in use, so I risk recommending it here even though
details are likely to change and it may be years before everybody can use it in production code.
Old code, in this case code using #include, can ‘‘live’’ for a very long time because it can be costly
and time consuming to update.
Consider how to express the Vector and sqr t_sum() example from §3.2 using modules:
// file Vector.cpp:
module; // this compilation will define a module
// ... here we put stuff that Vector might need for its implementation ...Section 3.3 Modules (C++20) 33
export module Vector; // defining the module called "Vector"
export class Vector {
public:
Vector(int s);
double& operator[](int i);
int size();
private:
double∗ elem; // elem points to an array of sz doubles
int sz;
};
Vector::Vector(int s)
:elem{new double[s]}, sz{s} // initialize members
{}
double& Vector::operator[](int i)
{
return elem[i];
}
int Vector::siz e()
{
return sz;
}
expor t int size(const Vector& v) { return v.siz e(); }
This defines a module called Vector, which exports the class Vector, all its member functions, and
the non-member function siz e().
The way we use this module is to impor t it where we need it. For example:
// file user.cpp:
import Vector; // get Vector’s interface
#include <cmath> // get the standard-librar y math function interface including sqrt()
double sqrt_sum(Vector& v)
{
double sum = 0;
for (int i=0; i!=v.siz e(); ++i)
sum+=std::sqr t(v[i]); // sum of square roots
return sum;
}
I could have imported the standard library mathematical functions also, but I used the old-fashioned #include just to show that you can mix old and new. Such mixing is essential for gradually upgrading older code from using #include to import.

The differences between headers and modules are not just syntactic.
• A module is compiled once only (rather than in each translation unit in which it is used).
• Two modules can be impor ted in either order without changing their meaning.
• If you import something into a module, users of your module do not implicitly gain access
to (and are not bothered by) what you imported: impor t is not transitive.
The effects on maintainability and compile-time performance can be spectacular.



















Put simply, you write a large program by dividing it into modules. A module is the C++ 20 way of working
with multiple source files. Just as a function has a declaration and a definition, a module has an interface
(declaration) and an implementation (definition). Because a module can contain multiple functions, classes,
and more, they have ways to divide one module into multiple files as an implementation detail.
Let’s start with a simple example. Let’s define a function, world(), in a module, hello. Our main()
program will call that function.

```cpp
export module hello;
import <iostream>;
export void world()
{
  std::cout << "hello, world\n";
}
```

Well, that was easy. The module keyword informs the compiler that this file is part of a module. The
export keyword says that this is an interface, that is, this file is exporting symbols. In particular, the module
exports the world() function. The module imports <iostream> so world() can do its work, but that is
an implementation detail. The only information that is visible from outside of the module are exported
declarations, which in this case is world(). Armed with just this interface, you can write a program that
imports the hello module and calls the world() function.

```cpp
import hello;
int main()
{
  world();
}
```

The import declaration imports a module, which makes every symbol that the module exports available
in the file that does the importing. You can use any of the names that the module exports just as though you
had written those functions in the file doing the importing. The name hello has no further significance after
the import declaration. This means you do not need to qualify the name of the world() function. Just call it
normally as you would if you had defined it in the same file as main().
A module declaration is optional, but if present must be the first declaration in a file. Then come any
import declarations. After the imports, you may not use any further module or import declarations in the
file. These simple restrictions mean you can use module and import as ordinary names elsewhere in your
program, which is great for existing programs that use those names, but new code should not use them in
order to avoid confusion.
If a file has no module declaration, it is the same as though the file began with an unnamed module
declaration:

module;

The unnamed module is also called the global module. A program’s main() function lives in the global
module, and any module can contribute declarations to the global module by starting the file with an
unnamed module header, followed by ordinary declarations, and then a named module declaration.
All of the standard library headers (except those imported from the C programming language) can be
imported as modules. That’s why the code listings for this book use import for <iostream> and #include
for <cassert>. Because modules are new features in C++ 20, all the zillions of lines of existing code use #include for all headers. Get used to seeing #include for a while.
The C++ 20 standard does not take modules any farther into the library implementation, but you can
expect library authors to begin to tinker with implementations of the standard library as a suite of modules.
For example, Microsoft Visual C++ lets you import std.core to import nearly the entire standard library at
once. A future version of the standard may adopt that or a similar module name for packaging and arranging
the standard library, but for now stick to the standard and look forward to libraries starting to arrive neatly
bundled with a ribbon and a module.


Classes and Modules

Let’s try a more challenging example: the rational class. This is easy to do, but introduces unseen twists

Throwing in a module declaration and an export keyword is only the first step. Recall that any member function defined inside the class is automatically inline. That is true outside of a module,
but within a module, it is no longer the case. The only way a function in a module can be inline is for you to
make it so explicitly with the inline keyword

```cpp
export module rat2;
#include <cassert>
import<numeric>;
export class rational
{
public:
    inline rational(int num) : numerator_{num}, denominator_{1} {}
    inline rational(rational const &) = default;
    inline rational(int num, int den)
        : numerator_{num}, denominator_{den}
    {
        reduce();
    }
    void assign(int num, int den)
    {
        numerator_ = num;
        denominator_ = den;
        reduce();
    }
    inline int numerator() const { return numerator_; }
    inline int denominator() const { return denominator_; }
    rational &operator=(int num)
    {
        numerator_ = num;
        denominator_ = 1;
        return *this;
    }

private:
    void reduce()
    {
        assert(denominator_ != 0);
        if (denominator_ < 0)
        {
            denominator_ = -denominator_;
            numerator_ = -numerator_;
        }
        int div{std::gcd(numerator_, denominator_)};
        numerator_ = numerator_ / div;
        denominator_ = denominator_ / div;
    }
    int numerator_;
    int denominator_;
};
```

```cpp
#include <iostream>
import rat2
int main() {
  rational r{2,4};
  std::cout << r.numerator() << '/' << r.denominator() << '\n';
}
```

As you can see, I did more than just add inline keywords. I also moved all of the member functions
into the class definition. This style of defining a class may be familiar to readers familiar with Java, Eiffel, and
similar languages. The idea is to put everything about the class in one self-contained piece.
Also, inline is not needed on a defaulted function, in this case the copy constructor. When the
compiler automatically fills in any constructor or function, it always automatically adds the inline qualifier.
Remember that inline is just a suggestion to the compiler, not a requirement.
This style of defining a simple class suits rational, but more complicated classes sometimes require
more complicated solutions.


### Hiding the Implementation

```cpp
export module rat3;
export class rational
{
public:
    inline rational(int num) : numerator_{num}, denominator_{1} {}
    inline rational(rational const &) = default;
    inline rational(int num, int den)
        : numerator_{num}, denominator_{den}
    {
        reduce();
    }
    void assign(int num, int den);
    inline int numerator() const { return numerator_; }
    inline int denominator() const { return denominator_; }
    rational &operator=(int num);

private:
    void reduce();
    int numerator_;
    int denominator_;
};
```

Notice how #include and import are no longer needed in the module interface. Only the reduce() function needs those declarations. This is one of the ways that separating the implementation helps keep the interface module cleaner. When the compiler must import a module, it needs only the module interface. This includes the definitions of every inline function; otherwise, it would not be able to compile the functions inline. The definitions of the non-inline functions live in a separate file, the module implementation. This looks very much like a module interface, but without the export keyword.

```cpp
module rat3;
#include <cassert>
import <numeric>;

void rational::assign(int num, int den)
{
  numerator_ = num;
  denominator_ = den;
  reduce();
}
void rational::reduce()
{
  assert(denominator_ != 0);
  if (denominator_ < 0)
  {
    denominator_ = -denominator_;
    numerator_ = -numerator_;
  }
  int div{std::gcd(numerator_, denominator_)};
  numerator_ = numerator_ / div;
  denominator_ = denominator_ / div;
}
rational& rational::operator=(int num)
{
  numerator_ = num;
  denominator_ = 1;
  return *this;
}
```

The module implementation must use the same module name as the module interface. Any function, variable, or type defined in the module implementation is hidden from all users of the module unless the module interface exports that symbol. The main advantage of separating the implementation is that changes to the implementation do not affect the interface. For example, maybe you want to change the assert() to issue a more helpful error message. It is conceivable that compilers will be able to compile a single module in such a way that changing the assert() call will not affect how the interface is compiled. But by separating the implementation module, you also tell the human reader what changes will affect the users of the module and what changes are hidden from them.



### Modules Exporting Modules

One module can import another. In doing so, it can hide the imported module as an implementation
detail, or it can expose the imported module as though that module were part of the exported interface.

For example, consider the vital_stats class

```cpp
export module stats;
import <istream>;
import <ostream>;
export import <string>;

export class vital_stats
{
public:
  inline vital_stats() : height_{0}, weight_{0}, bmi_{0}, sex_{'?'}, name_{}
  {}

  bool read(std::istream& in, int num);
  void print(std::ostream& out, int threshold) const;

private:
  int compute_bmi() const; ///< Return BMI, based on height_ and weight_
  int height_;             ///< height in centimeters
  int weight_;             ///< weight in kilograms
  int bmi_;                ///< Body-mass index
  char sex_;               ///< 'M' for male or 'F' for female
  std::string name_;       ///< Person’s name
};
```


Because the vital_stats class uses std::string, the stats module must import <string>. Similarly,
std::istream is defined in <istream> and std::ostream in <ostream>. But any user of the stats module
must be able to create a std::string and so will also need to use the <string> module, so stats also
exports it. It does not export <istream> and <ostream> because any user of stats will have its own import
declarations, such as <iostream> to pick up std::cin and std::cout, which also imports <istream> and
<ostream>. So there is no need for stats to do the same. By exporting all the necessary modules in the stats
module, you remove one burden from the programmer who makes use it. By not importing too much, stats
avoids burdening its consumer with too many extraneous symbols.

```cpp
#include <iostream>
import <stats>;

int main() {
  std::cout << "Bogus Metabolic Indicator\n";
  vital_stats stats;
  int count{0};
  while (stats.read(std::cin, count))
  {
	static constexpr int threshold{ 30 };
	++count;
    stats.print(std::cout, threshold);
  }
}
```



### Chaining Modules

More often than exporting a standard header, a large library that has modules A, B, and C will export
part A from parts B and C, for example. Write a set of simple modules so that the const double pi =
3.14159265358979323 is exported from module a; module b imports and exports a and also exports
a function, area(), to compute the area of a circle. Module c imports and exports a and exports
circumference() to compute the circumference of a circle. Write a main() program to demonstrate all
three modules.

```cpp
export module a;
export double constexpr pi = 3.14159265358979323;
```
```cpp
export module b;
export import a;
export double area(double radius)
{
  return pi * radius * radius;
}
```
```cpp
export module c;
export import a;
export double circumference(double radius)
{
  return 2.0 * pi * radius;
}
```
```cpp
module;
import b;
import c;
import<iostream>;
int main()
{
    while (std::cin)
    {
        std::cout << "pi=" << pi << '\n';
        std::cout << "Radius=";
        double radius{};
        if (std::cin >> radius)
        {
            std::cout << "Area = " << area(radius) << '\n';
            std::cout << "Circumference = " << circumference(radius) << '\n';
        }
    }
}
```

### Compiling Modules
Because modules are brand new, every compiler vendor supports them in slightly different ways. Gone are the old, simpler times of libraries of compiled object files.

Now we must confront precompiled modules, module maps, and other complexities.

Because every compiler vendor does things a little bit differently, I can offer only general advice here.

First of all, check whether your tools support modules yet. They may be available if you pass a special option to the compiler, such as -fmodules. Or you may have to wait for a newer release of your favorite compiler.

Due to the separation of interface and implementation, even if both are in the same source file, somehow the compiler needs to store the interface portion of the module in a manner that makes it available to any importer. The implementation portion can be compiled into a traditional object file, with some extra information, but most likely it will be stored separately. When compiling a file that imports a module, the compiler must be able to find the compiled module interface. This is tricky because a module interface
can actually come in multiple pieces.

I omitted this complexity from the explination above because modules are
complicated enough, and only module authors need to be aware of this capability.

Module importers always get the entire module, and that means the compiler needs to be able to find and collect all the modules’ pieces in order to make them available to the importer, that is, unless the compiler is compiling one piece of the implementation that imports another piece of the implementation.

Your best bet is to use an IDE that understands modules and let it handle the difficulties for you. If the IDE is closely tied to the compiler, it should know where module interface files are stored and how to retrieve them when modules are imported. This is an entirely new way to working with C++, so even IDE vendors may need to make changes to accommodate modules smoothly. It is possible that your compiler implements modules, but the standard library has not yet been updated so it can be imported. You may be able to compile and run the examples above after changing imports of the standard library but not other import declarations.

Now that you have glimpsed the future of C++ programming, I regret to inform you that billions of lines of C++ code have been written without the benefit of modules, and you, my friend, will have to maintain your tiny corner of those billions.

Most C++ code still uses #include, information regarding this is found here:
[C++\Organization]

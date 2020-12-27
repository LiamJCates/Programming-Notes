## Namespaces
A namespace statement declares the name of a namespace and causes the source code that follows the declaration to be compiled within that namespace.

Namespaces are names given to parts of code

The reason you use std::cout in a program and not only cout is that the artifact (cout) that you want to invoke is in the standard (std) namespace.

By invoking std::cout, you are telling the compiler to use that one unique cout that is available in the std namespace.

You use the std (pronounced “standard”) namespace to invoke functions, streams, and utilities that have been ratified by the ISO Standards Committee.


### Naming Conflict
Assume that you didn’t use the namespace qualifier in invoking cout and assume that cout existed in two locations known to the compiler — which one should the compiler invoke?
This causes a conflict and the compilation fails.

This is where namespaces get useful.
Namespaces help in reducing the potential for a naming conflict.

By telling the compiler that you are using the namespace std, you don’t need to explicitly mention the namespace when using std::cout or std::endl:

using namespace std;

The effect of this statement is that, when compiling, for any unrecognized name, the compiler will try prepending std:: to it to see if it exists in the std namespaces.

This can have unintended effects, so it is recommended that if you are only using a small number of namespace members, such as cout for instance, instead use:

using std::cout;

this will ensure that you only use what you need from a library and also document what you are using from a given library



## Declaring Namespaces
ANSI/ISO Standard C++ tries to solve this problem of overlapping global identifier names with the namespace mechanism.

The general syntax of the statement namespace is:
namespace namespace_name
{
members
}

where members is usually named constants, variable declarations, functions, or
another namespace. Note that namespace_name is a C++ identifier.




## Accessing Namespaces
The scope of a namespace member is local to the namespace. You can usually access a namespace member outside the namespace in one of two ways, as described below.

###Scope Resolution
To access a member of a namespace, you use the namespace_name, followed by
the scope resolution operator, followed by the member name.

The general syntax for accessing a namespace member is:
namespace_name::identifier

In C++, :: is called the scope resolution operator.

To access the member RATE of the namespace globalType, the following statement
is required:

globalType::RATE

To access the member printResult (which is a function), the following statement is required:

globalType::printResult();


### Using Directive

To simplify the accessing of a namespace member, ANSI/ISO Standard C++ provides
the use of the statement using. In C++, using is a reserved word.

To gain access to all names in the standard-library namespace, we can use a using-directive:
using namespace std;

A using-directive makes unqualified names from the named namespace accessible from the scope in which we placed the directive. So after the using-directive for std, we can simply write cout rather than std::cout.

By using a using-directive, we lose the ability to selectively use names from
that namespace, so this facility should be used carefully, usually for a library that’s pervasive in an application (e.g., std) or during a transition for an application that didn’t use namespaces.


The syntax to use the statement using is as follows:

a. To simplify the accessing of all namespace members:
using namespace namespace_name;
using namespace_name::identifier;

b. To simplify the accessing of a specific namespace member:
For example, the using statement:
using namespace globalType;

simplifies the accessing of all members of the namespace globalType. The statement:
using globalType::RATE;
simplifies the accessing of the member RATE of the namespace globalType.




You typically put the using statement after the namespace declaration. For the
namespace globalType, for example, you usually write the code as follows:

namespace globalType
{
const int N = 10;
const double RATE = 7.50;
int count = 0;
void printResult();
}
using namespace globalType;

After the using statement, to access a namespace member, you do not have to put
the namespace_name and the scope resolution operator before the namespace member. However, if a namespace member and a global identifier in a program have the same name, to access this namespace member in the program, the namespace_name and the scope resolution operator must precede the namespace member. Similarly, if a namespace member and an identifier in a block have the same name, to access this namespace member in the block, the namespace_name and the scope resolution operator must precede the namespace member.






## Example

C++ offers namespaces as a mechanism for expressing that some declarations belong together and that their names shouldn’t clash with other names.

For example, I might want to experiment with my own complex number type:

namespace My_code {
  class complex {
  // ...
  };

  complex sqr t(complex);
  // ...
  int main();
}

int My_code::main()
{
  complex z {1,2};
  auto z2 = sqrt(z);
  std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
  // ...
}

int main()
{
  return My_code::main();
}

By putting my code into the namespace My_code, it ensures that my names do not conflict

The simplest way to access a name in another namespace is to qualify it with the namespace name (e.g., std::cout and My_code::main).

The ‘‘real main()’’ is defined in the global namespace, that is, not local to a defined namespace, class, or function.

If repeatedly qualifying a name becomes tedious or distracting, we can bring the name into a scope with a using-declaration:

void my_code(vector<int>& x, vector<int>& y)
{
  using std::swap; // use the standard-librar y sw ap
  // ...
  swap(x,y); // std::swap()
  other::swap(x,y); // some other swap()
  // ...
}

A using-declaration makes a name from a namespace usable as if it was declared in the scope in which it appears. After using std::swap, it is exactly as if swap had been declared in my_code().






















Namespaces
Namespaces prevent naming conflicts. In large projects or when importing
libraries, namespaces are essential for disambiguating symbols.

Placing Symbols Within Namespaces
By default, all symbols you declare go into the global namespace. The global
namespace contains all the symbols that you can access without adding
any namespace qualifiers.

To place a symbol within a namespace other than the global namespace,
you declare the symbol within a namespace block. A namespace block has the
following form:
namespace Namespace1 {
// All symbols declared within this block
// belong to the Namespace1 namespace
}
Namespaces can be nested in one of two ways.


nest namespace blocks:

namespace Namespace1 {
  namespace Namespace2 {
  // All symbols declared within this block
  // belong to the Namespace1::Namespace2 namespace
  }
}

Use the scope-resolution operator:

namespace Namespace1::Namespace2 {
  // All symbols declared within this block
  // belong to the Namespace1::Namespace2 namespace
}
The latter approach is more succinct.

Using Symbols in Namespaces
To use a symbol within a namespace, you can always use the scope-resolution
operator to specify the fully qualified name of a symbol.


Using Directives
You can employ a using directive to avoid a lot of typing. A using directive
imports a symbol into a block or, if you declare a using directive at namespace
scope, into the current namespace. Either way, you have to type the full
namespace path only once. The usage has the following pattern:
using my-type;
The corresponding my-type gets imported into the current namespace
or block, meaning you no longer have to use its full name.


You should never put a using namespace directive within a header file. Every source
file that includes your header will dump all the symbols from that using directive into
the global namespace. This can cause issues that are very difficult to debug

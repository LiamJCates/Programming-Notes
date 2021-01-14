## Namespaces
Namespaces prevent naming conflicts.

A namespace statement declares the name of a namespace and causes the source code that follows the declaration to be compiled within the scope encompassed by that namespace.

Namespaces are names given to parts of code.

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



### Declaring Namespaces
ANSI/ISO Standard C++ tries to solve this problem of overlapping global identifier names with the namespace mechanism.

The general syntax of the statement namespace is:

namespace namespace_name
{
  //members
}

where members is usually named constants, variable declarations, functions, or
another namespace.

Note that namespace_name follows the rules for C++ identifier.

For more information on C++ identifier see:
[C++\Syntax\Statements\Declarations\Identifiers.md]


### Scope Resolution
To access a member of a namespace, you use the namespace_name, followed by
the scope resolution operator, followed by the member name.

The general syntax for accessing a namespace member is:

  namespace_name::identifier

In C++, :: is called the scope resolution operator.

The scope resolution operator can also be used without any preceding namespace (eg. ::doSomething). In such a case, the identifier (e.g. doSomething) is looked for in the global namespace.

To access the member RATE of the namespace globalType, the following statement
is required:

  globalType::RATE

To access the member printResult (which is a function), the following statement is required:

  globalType::printResult();



### Placing Symbols Within Namespaces
In C++, any name that is not defined inside a class, function, or a namespace is considered to be part of an implicitly defined namespace called the global namespace (sometimes also called the global scope).

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


It’s legal to declare namespace blocks in multiple locations (either across multiple files, or multiple places within the same file). All declarations within the namespace are considered part of the namespace.

The standard library makes extensive use of this feature, as each standard library header file contains its declarations inside a namespace std block contained within that header file. Otherwise the entire standard library would have to be defined in a single header file!

Note that this capability also means you could add your own functionality to the std namespace. Doing so causes undefined behavior most of the time, because the std namespace has a special rule, prohibiting extension from user code.


#### Nesting

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



### Namespace Aliasing
Existing namespaces can be aliased with new names, with the following syntax:

namespace new_name = current_name;


### Accessing Namespaces
The scope of a namespace member is local to the namespace. You can usually access a namespace member outside the namespace in one of two ways, as described below.




### Using Directive

To simplify the accessing of a namespace member, ANSI/ISO Standard C++ provides the use of the statement using. In C++, using is a reserved word.

To gain access to all names in the standard-library namespace, we can use a using-directive:

  using namespace std;

A using-directive makes unqualified names from the named namespace accessible from the scope in which we placed the directive. So after the using-directive for std, we can simply write cout rather than std::cout.

The name must be a previously defined namespace.

By using a using-directive, we lose the ability to selectively use names from
that namespace, so this facility should be used carefully, usually for a library that’s pervasive in an application (e.g., std) or during a transition for an application that didn’t use namespaces.


The syntax to use the statement using is as follows:

  a. To simplify the accessing of all namespace members:

    using namespace namespace_name;

  The using statement simplifies the accessing of all members of the namespace globalType.

    using namespace globalType;

  b. To simplify the accessing of a specific namespace member:

    using namespace_name::identifier;

  The following statement simplifies the accessing of the member RATE of the namespace globalType:

    using globalType::RATE;




Names introduced in a using directive obey normal scope rules. The name is visible from the point of the using directive to the end of the scope in which the directive is found. Entities with the same name defined in an outer scope are hidden.

For the namespace globalType, for example, you usually write the code as follows:

  namespace globalType
  {
    const int N = 10;
    const double RATE = 7.50;
    int count = 0;
    void printResult();
  }

  using namespace globalType;

After the using statement, to access a namespace member, you do not have to put the namespace_name and the scope resolution operator before the namespace member. However, if a namespace member and a global identifier in a program have the same name, to access this namespace member in the program, the namespace_name and the scope resolution operator must precede the namespace member. Similarly, if a namespace member and an identifier in a block have the same name, to access this namespace member in the block, the namespace_name and the scope resolution operator must precede the namespace member.




Cancelling or replacing a using statement

Once a using statement has been declared, there’s no way to cancel or replace it with a different using statement within the scope in which it was declared.

  int main()
  {
      using namespace Foo;

      // there's no way to cancel the "using namespace Foo" here!
      // there's also no way to replace "using namespace Foo" with a different using statement

      return 0;
  } // using namespace Foo ends here

The best you can do is intentionally limit the scope of the using statement from the outset using the block scoping rules.

  int main()
  {
      {
          using namespace Foo;
          // calls to Foo:: stuff here
      } // using namespace Foo expires

      {
          using namespace Goo;
          // calls to Goo:: stuff here
      } // using namespace Goo expires

      return 0;
  }

Of course, all of this headache can be avoided by explicitly using the scope resolution operator (::) in the first place.







### Header File
You should never put a using namespace directive within a header file. Every source file that includes your header will dump all the symbols from that using directive into the global namespace. This can cause issues that are very difficult to debug




Should 'using' directives be inside or outside the namespace?

There is actually a (subtle) difference between the two. Imagine you have the following code in File1.cs:

  // File1.cs
  using System;
  namespace Outer.Inner
  {
    class Foo
    {
      static void Bar()
      {
        double d = Math.PI;
      }
    }
  }

Now imagine that someone adds another file (File2.cs) to the project that looks like this:

  // File2.cs
  namespace Outer
  {
    class Math
    {
    }
  }

The compiler searches Outer before looking at those using directives outside the namespace, so it finds Outer.Math instead of System.Math. Unfortunately (or perhaps fortunately?), Outer.Math has no PI member, so File1 is now broken.

This changes if you put the using inside your namespace declaration, as follows:

  // File1b.cs
  namespace Outer.Inner
  {
    using System;
    class Foo
    {
      static void Bar()
      {
        double d = Math.PI;
      }
    }
  }

Now the compiler searches System before searching Outer, finds System.Math, and all is well.

Some would argue that Math might be a bad name for a user-defined class, since there's already one in System; the point here is just that there is a difference, and it affects the maintainability of your code.

It's also interesting to note what happens if Foo is in namespace Outer, rather than Outer.Inner. In that case, adding Outer.Math in File2 breaks File1 regardless of where the using goes. This implies that the compiler searches the innermost enclosing namespace before it looks at any using directive.


















C++ supports two permutations on regular namespaces that are worth at least knowing about. We won’t build on these, so consider this lesson optional for now.

Unnamed (anonymous) namespaces

An unnamed namespace (also called an anonymous namespace) is a namespace that is defined without a name, like so:

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

#include <iostream>

namespace // unnamed namespace
{
    void doSomething() // can only be accessed in this file
    {
        std::cout << "v1\n";
    }
}

int main()
{
    doSomething(); // we can call doSomething() without a namespace prefix

    return 0;
}

This prints:

v1

All content declared in an unnamed namespace is treated as if it is part of the parent namespace. So even though function doSomething is defined in the unnamed namespace, the function itself is accessible from the parent namespace (which in this case is the global namespace), which is why we can call doSomething from main without any qualifiers.

This might make unnamed namespaces seem useless. But the other effect of unnamed namespaces is that all identifiers inside an unnamed namespace are treated as if they had internal linkage, which means that the content of an unnamed namespace can’t be seen outside of the file in which the unnamed namespace is defined.

For functions, this is effectively the same as defining all functions in the unnamed namespace as static functions. The following program is effectively identical to the one above:

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

#include <iostream>

static void doSomething() // can only be accessed in this file
{
    std::cout << "v1\n";
}

int main()
{
    doSomething(); // we can call doSomething() without a namespace prefix

    return 0;
}

Unnamed namespaces are typically used when you have a lot of content that you want to ensure stays local to a given file, as it’s easier to cluster such content in an unnamed namespace than individually mark all declarations as static. Unnamed namespaces will also keep user-defined types (something we’ll discuss in a later lesson) local to the file, something for which there is no alternative equivalent mechanism to do.

Inline namespaces

Now consider the following program:

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

#include <iostream>

void doSomething()
{
    std::cout << "v1\n";
}

int main()
{
    doSomething();

    return 0;
}

This prints:

v1

Pretty straightforward, right?

But let’s say you’re not happy with doSomething, and you want to improve it in some way that changes how it behaves. But if you do this, you risk breaking existing programs using the older version. How do you handle this?

One way would be to create a new version of the function with a different name. But over the course of many changes, you could end up with a whole set of almost-identically named functions (doSomething, doSomething_v2, doSomething_v3, etc…).

An alternative is to use an inline namespace. An inline namespace is a namespace that is typically used to version content. Much like an unnamed namespace, anything declared inside an inline namespace is considered part of the parent namespace. However, inline namespaces don’t give everything internal linkage.

To define an inline namespace, we use the inline keyword:

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

#include <iostream>

inline namespace v1 // declare an inline namespace named v1
{
    void doSomething()
    {
        std::cout << "v1\n";
    }
}

namespace v2 // declare a normal namespace named v2
{
    void doSomething()
    {
        std::cout << "v2\n";
    }
}

int main()
{
    v1::doSomething(); // calls the v1 version of doSomething()
    v2::doSomething(); // calls the v2 version of doSomething()

    doSomething(); // calls the inline version of doSomething() (which is v1)

    return 0;
}

This prints:

v1
v2
v1

In the above example, callers to doSomething will get the v1 (the inline version) of doSomething. Callers who want to use the newer version can explicitly call v2::dosomething(). This preserves the function of existing programs while allowing newer programs to take advantage of newer/better variations.

Alternatively, if you want to push the newer version:

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

#include <iostream>

namespace v1 // declare a normal namespace named v1
{
    void doSomething()
    {
        std::cout << "v1\n";
    }
}

inline namespace v2 // declare an inline namespace named v2
{
    void doSomething()
    {
        std::cout << "v2\n";
    }
}

int main()
{
    v1::doSomething(); // calls the v1 version of doSomething()
    v2::doSomething(); // calls the v2 version of doSomething()

    doSomething(); // calls the inline version of doSomething() (which is v2)

    return 0;
}

This prints:

v1
v2
v2

In this example, all callers to doSomething will get the v2 version by default (the newer and better version). Users who still want the older version of doSomething can explicitly call v1::doSomething() to access the old behavior. This means existing programs who want the v1 version will need to globally replace doSomething with v1::doSomething, but this typically won’t be problematic if the functions are well named.

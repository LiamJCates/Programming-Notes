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



### Cancelling or replacing a using statement

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


NOTE
You should never put a using namespace directive within a header file. Every source file that includes your header will dump all the symbols from that using directive into the global namespace. This can cause issues that are very difficult to debug.

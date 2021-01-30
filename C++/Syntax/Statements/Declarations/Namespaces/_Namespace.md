## Namespaces

One of the problems encountered when programs reach a certain size is that you “run out of names” for functions and identifiers. Of course, you don’t really run out of names; it does, however, become harder to think of new ones after awhile.

More importantly, when a program reaches a certain size it’s typically broken up into pieces, each of which is built and maintained by a different person or group.  This means that all the developers must be careful not to create situation where names accidentally conflict. This rapidly becomes tedious, time-wasting, and, ultimately, expensive.

Namespaces are names given to regions of code to organize identifiers and prevent naming conflicts.

A namespace statement declares the name of a namespace and causes the source code that follows the declaration to be compiled within the scope encompassed by that namespace.

For example, the reason you use std::cout in a program and not only cout is that the artifact (cout) that you want to invoke is in the standard (std) namespace. By invoking std::cout, you are using a namespace qualifier "std::" that tells the compiler to use that one unique cout that is available in the std namespace.

The use of the std (pronounced “standard”) namespace to invoke functions, streams, and utilities that have been ratified by the ISO Standards Committee provides a logical organization of these elements.

Types of Namespace declarations:
  Nested
  Alias
  Anonymous
  Inline



### Naming Conflict

C++ requires that all identifiers be non-ambiguous. If two identical identifiers are introduced into the same program in a way that the compiler or linker can’t tell them apart, the compiler or linker will produce an error. This error is generally referred to as a naming collision (or naming conflict).

Most naming collisions occur in two cases:
  Two (or more) definitions for a function (or global variable) are introduced into separate files that are compiled into the same program. This will result in a linker error.
  Two (or more) definitions for a function (or global variable) are introduced into the same file (often via an #include). This will result in a compiler error.

This is where namespaces get useful. Namespaces help in reducing the potential for a naming conflict.

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

### Accessing Namespaces

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

Another method of accessing a namespace is via a using directive. For information on using directives, see:
[C++\Syntax\Statements\Declarations\Namespaces\Using.md]

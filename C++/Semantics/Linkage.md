Identifiers have a property called linkage. An identifier’s linkage determines whether other declarations of that name refer to the same object or not.

Scope and linkage may seem somewhat similar. However, scope defines where a single declaration can be seen and used. Linkage defines whether multiple declarations refer to the same object or not.

Identifier linkage types:
  None
  Internal
  External





Linkage summary

An identifier’s linkage determines whether multiple declarations of an identifier refer to the same identifier or not.

  An identifier with no linkage means the identifier only refers to itself. This includes:
      Local variables
      User-defined type definitions (such as enums and classes) declared inside a block
  An identifier with internal linkage can be accessed anywhere within the file it is declared. This includes:
      Static global variables (initialized or uninitialized)
      Static functions
      Const global variables
      Functions declared inside an unnamed namespace
      User-defined type definitions (such as enums and classes) declared inside an unnamed namespace
  An identifier with external linkage can be accessed anywhere within the file it is declared, or other files (via a forward declaration). This includes:
      Functions
      Non-const global variables (initialized or uninitialized)
      Extern const global variables
      Inline const global variables
      User-defined type definitions (such as enums and classes) declared inside a namespace or in the global scope

Identifiers with external linkage will generally cause a duplicate definition linker error if the definitions are compiled into more than one .cpp file (due to violating the one-definition rule). There are some exceptions to this rule (for types, templates, and inline functions and variables) -- we’ll cover these further in future lessons when we talk about those topics.

Also note that functions have external linkage by default. They can be made internal by using the static keyword.



Forward declaration summary

You can use a forward declaration to access a function or variable in another file:
Type 	Example 	Notes
Function forward declaration 	void foo(int x); 	Prototype only, no function body
Non-constant global variable forward declaration 	extern int g_x; 	Must be uninitialized
Const global variable forward declaration 	extern const int g_x; 	Must be uninitialized
Constexpr global variable forward declaration 	extern constexpr int g_x; 	Not allowed, constexpr cannot be forward declared



### None
Local variables have no linkage

Local variables have no linkage, which means that each declaration refers to a unique object.

For example:

  int main()
  {
      int x { 2 }; // local variable, no linkage

      {
          int x { 3 }; // this identifier x refers to a different object than the previous x
      }

      return 0;
  }







Global variable and functions identifiers can have either internal linkage or external linkage.

### Internal

An identifier with internal linkage can be seen and used within a single file, but it is not accessible from other files (that is, it is not exposed to the linker). This means that if two files have identically named identifiers with internal linkage, those identifiers will be treated as independent.

#### Global variables with internal linkage

Global variables with internal linkage are sometimes called internal variables.

The static keyword gives a global identifier internal linkage, which means the identifier can only be used in the file in which it is defined.

To make a non-constant global variable internal, we use the static keyword.

  // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword
  static int g_x;

  // const globals have internal linkage by default
  const int g_y { 1 };

  // constexpr globals have internal linkage by default
  constexpr int g_z { 2 };

  int main()
  {
      return 0;
  }

Const and constexpr global variables have internal linkage by default (and thus don’t need the static keyword -- if it is used, it will be ignored).

Here’s an example of multiple files using internal variables:

a.cpp:

  constexpr int g_x { 2 }; // this internal g_x is only accessible within a.cpp

main.cpp:

  #include <iostream>

  static int g_x { 3 }; // this separate internal g_x is only accessible within main.cpp

  int main()
  {
      std::cout << g_x << '\n'; // uses main.cpp's g_x, prints 3

      return 0;
  }

Output:

  3

Because g_x is internal to each file, main.cpp has no idea that a.cpp also has a variable named g_x (and vice versa).


The use of the static keyword above is an example of a storage class specifier, which sets both the name’s linkage and its storage duration (but not its scope).

For more information on storage classes, see:
[C++\Semantics\Scope.md]




The one-definition rule says that an object or function can’t have more than one definition, either within a file or a program.

However, it’s worth noting that internal objects (and functions) that are defined in different files are considered to be independent entities (even if their names and types are identical), so there is no violation of the one-definition rule. Each internal object only has one definition.

Because linkage is a property of an identifier (not of a variable), function identifiers have the same linkage property that variable identifiers do. Functions default to external linkage (which we’ll cover in the next lesson), but can be set to internal linkage via the static keyword:

add.cpp:

  // Function is declared static, and can only be used within this file
  // Access attempts from other files via function forward declaration will fail
  static int add(int x, int y)
  {
      return x + y;
  }

main.cpp:

  #include <iostream>

  int add(int x, int y); // forward declaration for function add

  int main()
  {
      std::cout << add(3, 4) << '\n';

      return 0;
  }

This program won’t link, because function add is not accessible outside of add.cpp.


Summary
// Internal global variables definitions:

  // defines non-initialized internal global variable (default zero initialized)
  static int g_x;

  // defines initialized internal global variable
  static int g_x{ 1 };

  // defines initialized internal global const variable
  const int g_y { 2 };

  // defines initialized internal global constexpr variable
  constexpr int g_y { 3 };

  // Internal function definitions:
  static int foo() {};     // defines internal function
















External Linkage
An identifier with external linkage can be seen and used both from the file in which it is defined, and from other code files (via a forward declaration). In this sense, identifiers with external linkage are truly “global” in that they can be used anywhere in your program!


you can call a function defined in one file from another file. This is because functions have external linkage by default.

In order to call a function defined in another file, you must place a forward declaration for the function in any other files wishing to use the function. The forward declaration tells the compiler about the existence of the function, and the linker connects the function calls to the actual function definition.

Here’s an example:

a.cpp:

  #include <iostream>

  void sayHi() // this function has external linkage, and can be seen by other files
  {
      std::cout << "Hi!";
  }

main.cpp:

  void sayHi(); // forward declaration for function sayHi, makes sayHi accessible in this file

  int main()
  {
      sayHi(); // call to function defined in another file, linker will connect this call to the function definition

      return 0;
  }

Output:
Hi!

In the above example, the forward declaration of function sayHi() in main.cpp allows main.cpp to access the sayHi() function defined in a.cpp. The forward declaration satisfies the compiler, and the linker is able to link the function call to the function definition.

If function sayHi() had internal linkage instead, the linker would not be able to connect the function call to the function definition, and a linker error would result.


Global variables with external linkage

Global variables with external linkage are sometimes called external variables. To make a global variable external (and thus accessible by other files), we can use the extern keyword to do so:

  int g_x { 2 }; // non-constant globals are external by default

  extern const int g_y { 3 }; // const globals can be defined as extern, making them external
  extern constexpr int g_z { 3 }; // constexpr globals can be defined as extern, making them external (but this is useless, see the note in the next section)

  int main()
  {
      return 0;
  }

Non-const global variables are external by default (if used, the extern keyword will be ignored).

Variable forward declarations via the extern keyword

To actually use an external global variable that has been defined in another file, you also must place a forward declaration for the global variable in any other files wishing to use the variable. For variables, creating a forward declaration is also done via the extern keyword (with no initialization value).

Here is an example of using a variable forward declaration:

a.cpp:
1
2
3

// global variable definitions
int g_x { 2 }; // non-constant globals have external linkage by default
extern const int g_y { 3 }; // this extern gives g_y external linkage

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

#include <iostream>

extern int g_x; // this extern is a forward declaration of a variable named g_x that is defined somewhere else
extern const int g_y; // this extern is a forward declaration of a const variable named g_y that is defined somewhere else

int main()
{
    std::cout << g_x; // prints 2

    return 0;
}

In the above example, a.cpp and main.cpp both reference the same global variable named g_x. So even though g_x is defined and initialized in a.cpp, we are able to use its value in main.cpp via the forward declaration of g_x.

Note that the extern keyword has different meanings in different contexts. In some contexts, extern means “give this variable external linkage”. In other contexts, extern means “this is a forward declaration for an external variable that is defined somewhere else”. Yes, this is confusing, so we summarize all of these usages in lesson 6.11 -- Scope, duration, and linkage summary.

Warning

If you want to define an uninitialized non-const global variable, do not use the extern keyword, otherwise C++ will think you’re trying to make a forward declaration for the variable.

Warning

Although constexpr variables can be given external linkage via the extern keyword, they can not be forward declared, so there is no value in giving them external linkage.

Note that function forward declarations don’t need the extern keyword -- the compiler is able to tell whether you’re defining a new function or making a forward declaration based on whether you supply a function body or not. Variables forward declarations do need the extern keyword to help differentiate variables definitions from variable forward declarations (they look otherwise identical):

1
2
3
4
5
6
7

// non-constant
int g_x; // variable definition (can have initializer if desired)
extern int g_x; // forward declaration (no initializer)

// constant
extern const int g_y { 1 }; // variable definition (const requires initializers)
extern const int g_y; // forward declaration (no initializer)

File scope vs. global scope

The terms “file scope” and “global scope” tend to cause confusion, and this is partly due to the way they are informally used. Technically, in C++, all global variables have “file scope”, and the linkage property controls whether they can be used in other files or not.

Consider the following program:

global.cpp:
1
2

int g_x { 2 }; // external linkage by default
// g_x goes out of scope here

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

extern int g_x; // forward declaration for g_x -- g_x can be used beyond this point in this file

int main()
{
    std::cout << g_x; // should print 2

    return 0;
}
// the forward declaration for g_x goes out of scope here

Variable g_x has file scope within global.cpp -- it can be used from the point of definition to the end of the file, but it can not be directly seen outside of global.cpp.

Inside main.cpp, the forward declaration of g_x also has file scope -- it can be used from the point of declaration to the end of the file.

However, informally, the term “file scope” is more often applied to global variables with internal linkage, and “global scope” to global variables with external linkage (since they can be used across the whole program, with the appropriate forward declarations).

The initialization order problem of global variables

Initialization of global variables happens as part of program startup, before execution of the main function. This proceeds in two phases.

The first phase is called static initialization. In the static initialization phase, global variables with constexpr initializers (including literals) are initialized to those values. Also, global variables without initializers are zero-initialized.

The second phase is called dynamic initialization. This phase is more complex and nuanced, but the gist of it is that global variables with non-constexpr initializers are initialized.

Here’s an example of a non-constexpr initializer:

1
2
3
4
5
6

int init()
{
    return 5;
}

int g_something{ init() }; // non-constexpr initialization

Within a single file, global variables are generally initialized in order of definition (there are a few exceptions to this rule). Given this, you need to be careful not to have variables dependent on the initialization value of other variables that won’t be initialized until later. For example:

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

#include <iostream>

int initx();  // forward declaration
int inity();  // forward declaration

int g_x{ initx() }; // g_x is initialized first
int g_y{ inity() };

int initx()
{
    return g_y; // g_y isn't initialized when this is called
}

int inity()
{
  return 5;
}

int main()
{
    std::cout << g_x << ' ' << g_y << '\n';
}

This prints:

0 5

Much more of a problem, the order of initialization across different files is not defined. Given two files, a.cpp and b.cpp, either could have its global variables initialized first. This means that if the variables in a.cpp are dependent upon the values in b.cpp, there’s a 50% chance that those variables won’t be initialized yet.

Warning

Dynamic initialization of global variables causes a lot of problems in C++. Avoid it whenever possible.

Quick summary

1
2
3
4
5
6
7
8
9

// External global variable definitions:
int g_x;                       // defines non-initialized external global variable (zero initialized by default)
extern const int g_x{ 1 };     // defines initialized const external global variable
extern constexpr int g_x{ 2 }; // defines initialized constexpr external global variable

// Forward declarations
extern int g_y;                // forward declaration for non-constant global variable
extern const int g_y;          // forward declaration for const global variable
extern constexpr int g_y;      // not allowed: constexpr variables can't be forward declared

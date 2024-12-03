Identifiers, a name that denotes object, reference, function, type, template, namespace, or value, have a property called linkage.

If a name has linkage, it refers to the same entity as the same name introduced by a declaration in another scope. If a variable, function, or another entity with the same name is declared in several scopes, but does not have sufficient linkage, then several instances of the entity are generated.

Scope and linkage may seem somewhat similar. However, scope defines where a single declaration can be seen and used. Linkage defines whether multiple declarations refer to the same object or not.

Identifier linkage types:
  None
  Internal
  External
  Module (C++20)



### None (no linkage)
The name can be referred to only from the scope it is in.

Any of the following names declared at block scope have no linkage:
  variables not explicitly declared extern (regardless of the static modifier);
  local classes and their member functions;
  other names declared at block scope such as typedefs, enumerations, and enumerators.

Names not specified with external, module, (since C++20) or internal linkage also have no linkage, regardless of which scope they are declared in.

No linkage, means that each declaration refers to a unique object.

  int main()
  {
      int x { 2 }; // local variable, no linkage

      {
          int x { 3 }; // local variable, no linkage
      }

      return 0;
  }

Both x identifiers refer to unique objects / memory allocations.



### Module (since C++20)

The name can be referred to only from the scopes in the same module unit or in the other translation units of the same named module.

Names declared at namespace scope have module linkage if they are declared in named module and are not exported, and don't have internal linkage.

For more information related to modules see:
[C++\Syntax\Statements\Declarations\Modules.md]

### Internal

The name can be referred to from all scopes in the current translation unit.

A translation unit roughly consists of a source file after it has been processed by the C preprocessor, meaning that header files listed in #include directives are literally included, sections of code within #ifndef may be included, and macros have been expanded, roughly equal to file scope.

Any of the following names declared at namespace scope have internal linkage:
  variables, variable templates (since C++14), functions, or function templates declared static;
  non-volatile non-template (since C++14) non-inline (since C++17) non-exported (since C++20) const-qualified variables (including constexpr) that aren't declared extern and aren't previously declared to have external linkage;
  data members of anonymous unions.
  (since C++11) All names declared in unnamed namespace or a namespace within an unnamed namespace, even ones explicitly declared extern, have internal linkage.


An identifier with internal linkage can be seen and used within a single file, and is not accessible from other files (that is, it is not exposed to the linker). This means that if two files have identically named identifiers with internal linkage, those identifiers will be treated as independent.

Global variables with internal linkage are sometimes called internal variables.

The static keyword gives a global identifier internal linkage, which means the identifier can only be used in the file in which it is defined.

Const and constexpr global variables have internal linkage by default (and thus don’t need the static keyword -- if it is used, it will be ignored).

Example:
// multiple files using internal variables:

a.cpp:

  constexpr int g_x { 2 }; // internal g_x, accessible only within a.cpp

main.cpp:

  #include <iostream>

  static int g_x { 3 }; // internal g_x, accessible only within main.cpp

  int main()
  {
      std::cout << g_x << '\n'; // uses main.cpp's g_x, prints 3
  }

Output:

  3

Because g_x is internal to each file, main.cpp has no idea that a.cpp also has a variable named g_x (and vice versa).

The use of the static keyword above is an example of a storage class specifier, which sets both the name’s linkage and its storage duration (but not its scope).

For more information on storage classes, see:
[C++\Semantics\ScopeLinkage&Duration\Storage.md]

The one-definition rule says that an object or function can’t have more than one definition, either within a file or a program.

However, it’s worth noting that internal objects (and functions) that are defined in different files are considered to be independent entities (even if their names and types are identical), so there is no violation of the one-definition rule. Each internal object only has one definition.

Because linkage is a property of an identifier (not of a variable), function identifiers have the same linkage property that variable identifiers do. Functions default to external linkage, but can be set to internal linkage via the static keyword:

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




### External

The name can be referred to from the scopes in the other translation units. Variables and functions with external linkage also have language linkage, which makes it possible to link translation units written in different programming languages.

Except as noted above, any of the following names declared at namespace scope have external linkage:
  variables and functions not listed above (that is, functions not declared static, namespace-scope non-const variables not declared static, and any variables declared extern);
  enumerations;
  names of classes, their member functions, static data members (const or not), nested classes and enumerations, and functions first introduced with friend declarations inside class bodies;
  names of all templates not listed above (that is, not function templates declared static).

Any of the following names first declared at block scope have external linkage:
  names of variables declared extern;
  names of functions.

However, if the name is declared in an unnamed namespace or in a namespace nested within an unnamed namespace, the name has internal linkage. If the name is declared in a named module and is not exported, the name has module linkage.

Identifiers with external linkage will generally cause a duplicate definition linker error if the definitions are compiled into more than one .cpp file (due to violating the one-definition rule). There are some exceptions to this rule (for types, templates, and inline functions and variables).

An identifier with external linkage can be seen and used both from the file in which it is defined, and from other code files (via a forward declaration). In this sense, identifiers with external linkage are truly “global” in that they can be used anywhere in your program!


#### Functions
you can call a function defined in one file from another file. This is because functions have external linkage by default.

In order to call a function defined in another file, you must place a forward declaration for the function in any other files wishing to use the function. The forward declaration tells the compiler about the existence of the function, and the linker connects the function calls to the actual function definition:

a.cpp:

  #include <iostream>
  // this function has external linkage, and can be seen by other files
  void sayHi()
  {
    std::cout << "Hi!";
  }

main.cpp:
  // forward declaration for function sayHi, makes sayHi accessible in this file
  void sayHi();

  int main()
  {
    // call to function defined in another file, linker connects call to the function definition
    sayHi();
  }

Output:
Hi!

In the above example, the forward declaration of function sayHi() in main.cpp allows main.cpp to access the sayHi() function defined in a.cpp. The forward declaration satisfies the compiler, and the linker is able to link the function call to the function definition.

If function sayHi() had internal linkage instead, the linker would not be able to connect the function call to the function definition, and a linker error would result.


#### Global variables

Global variables with external linkage are sometimes called external variables. To make a global variable external (and thus accessible by other files), we can use the extern keyword to do so:

  int g_x { 2 }; // non-constant globals are external by default

  extern const int g_y { 3 }; // const globals can be defined as extern, making them external
  extern constexpr int g_z { 3 }; // constexpr globals can be defined as extern, making them external (but this is useless, see the note in the next section)

  int main()
  {
      return 0;
  }

Non-const global variables are external by default (if used, the extern keyword will be ignored).



### Variable forward declarations

To actually use an external global variable that has been defined in another file, you also must place a forward declaration for the global variable in any other files wishing to use the variable. For variables, creating a forward declaration is also done via the extern keyword (with no initialization value).

Here is an example of using a variable forward declaration:

a.cpp:
  // non-constant globals have external linkage by default
  int g_x { 2 };
  // this extern gives g_y external linkage
  extern const int g_y { 3 };

main.cpp:
  #include <iostream>

  // a forward declaration of variable g_x, defined elsewhere
  extern int g_x;
  // a forward declaration of const variable g_y, defined elsewhere
  extern const int g_y;

  int main()
  {
      std::cout << g_x; // prints 2
  }

In the above example, a.cpp and main.cpp both reference the same global variable named g_x. So even though g_x is defined and initialized in a.cpp, we are able to use its value in main.cpp via the forward declaration of g_x.

Note that the extern keyword has different meanings in different contexts. In some contexts, extern means “give this variable external linkage”. In other contexts, extern means “this is a forward declaration for an external variable that is defined somewhere else”.

Warning

If you want to define an uninitialized non-const global variable, do not use the extern keyword, otherwise C++ will think you’re trying to make a forward declaration for the variable.

Warning

Although constexpr variables can be given external linkage via the extern keyword, they can not be forward declared, so there is no value in giving them external linkage.

Note that function forward declarations don’t need the extern keyword -- the compiler is able to tell whether you’re defining a new function or making a forward declaration based on whether you supply a function body or not. Variables forward declarations do need the extern keyword to help differentiate variables definitions from variable forward declarations (they look otherwise identical):

  // non-constant
  int g_x; // variable definition (can have initializer if desired)
  extern int g_x; // forward declaration (no initializer)

  // constant
  extern const int g_y { 1 }; // variable definition (const requires initializers)
  extern const int g_y; // forward declaration (no initializer)

### File scope vs. global scope

The terms “file scope” and “global scope” tend to cause confusion, and this is partly due to the way they are informally used. Technically, in C++, all global variables have “file scope”, and the linkage property controls whether they can be used in other files or not.

Consider the following program:

global.cpp:
  int g_x { 2 }; // external linkage by default
  // g_x goes out of scope here

main.cpp:
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



### initialization order problem of global variables

Initialization of global variables happens as part of program startup, before execution of the main function. This proceeds in two phases.

The first phase is called static initialization. In the static initialization phase, global variables with constexpr initializers (including literals) are initialized to those values. Also, global variables without initializers are zero-initialized.

The second phase is called dynamic initialization. This phase is more complex and nuanced, but the gist of it is that global variables with non-constexpr initializers are initialized.

Here’s an example of a non-constexpr initializer:

  int init()
  {
      return 5;
  }

  int g_something{ init() }; // non-constexpr initialization

Within a single file, global variables are generally initialized in order of definition (there are a few exceptions to this rule). Given this, you need to be careful not to have variables dependent on the initialization value of other variables that won’t be initialized until later. For example:

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

// External global variable definitions:
int g_x;                       // defines non-initialized external global variable (zero initialized by default)
extern const int g_x{ 1 };     // defines initialized const external global variable
extern constexpr int g_x{ 2 }; // defines initialized constexpr external global variable

// Forward declarations
extern int g_y;                // forward declaration for non-constant global variable
extern const int g_y;          // forward declaration for const global variable
extern constexpr int g_y;      // not allowed: constexpr variables can't be forward declared

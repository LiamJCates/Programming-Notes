### Identifier Access
Named entities, such as variables, functions, and compound types need to be declared before being used in C++. The visibility of a name, also called its scope, is the region in the program where a declared name can be used. An identifier’s scope determines where the identifier can be accessed within the source code. When an identifier can be accessed, we say it is in scope. When an identifier can not be accessed, we say it is out of scope.

Scope is a compile-time property, and trying to use an identifier when it is not in scope will result in a compile error. A variable’s scope begins at the point of variable definition, and stops at the end of the set of curly braces in which they are defined (or for function parameters, at the end of the function). This ensures variables can not be used before the point of definition (even if the compiler opts to create them before then).

Only one entity can exist with a particular name in a particular scope.

### Shadowing

Each block defines its own scope region. So what happens when we have a variable inside a nested block that has the same name as a variable in an outer block? When this happens, the nested variable “hides” the outer variable in areas where they are both in scope. This is called name hiding or shadowing.

Similar to how variables in a nested block can shadow variables in an outer block, local variables with the same name as a global variable will shadow the global variable wherever the local variable is in scope.

However, because global variables are part of the global namespace, we can use the scope operator (::) with no prefix to tell the compiler we mean the global variable instead of the local variable.



### Limiting Scope
Variables should be defined in the most limited scope. By limiting the scope of a variable, you reduce the complexity of the program because the number of active variables is reduced. Further, it makes it easier to see where variables are used (or aren’t used). A variable defined inside a block can only be used within that block (or nested blocks).

Define variables in the most limited existing scope. Avoid creating new blocks whose only purpose is to limit the scope of variables.

The point in the program where a declaration happens influences its visibility/scope.



### Scope Types
A declaration introduces its name into a scope:

• Local scope:
  A name declared in a function or lambda is called a local name.
  Its scope extends from its point of declaration to the end of the block in which its declaration occurs.

• Class scope:
  A name is called a member name(or a class member name) if it is defined in a class, outside any function, lambda, or enum class.
  Its scope extends from the opening { of its enclosing declaration to the end of that declaration.

• Namespace scope:
  A name is called a namespace member name if it is defined in a name-space outside any function, lambda, class, or enum class.
  Its scope extends from the point of declaration to the end of its namespace.

Global scope:
  A name not declared inside any other construct is called a global name and is said to be in the global namespace.
  A global variable will hold it's value throughout the life-time of your program.
  A global variable can be accessed by any function. That is, a global variable is available for use throughout your entire program after its declaration.

By convention, many developers prefix global variable identifiers with “g” or “g_” to indicate that they are global.

In general, the following rules apply when an identifier is accessed:

Global identifiers are accessible within a block if
  a. The identifier is declared before the function definition (block)
  b. The function name is different than the identifier
  c. All function parameter names differ from the global identifier name
  d. All local identifier names differ from the global identifier name

Local identifiers are not accessible outside of the function (block).

(Nested Block) An identifier declared within a block is accessible
  a. Only within the block from the point at which it is declared until the end of the block
  b. By those blocks that are nested within that block if the nested block does not have an identifier with the same name as that of the outside block (the block that encloses the nested block).

The scope of a function name is similar to the scope of an identifier declared outside any block. That is, the scope of a function name is the same as the scope of a global variable.

C++ does not allow the nesting of functions. That is, you cannot include the definition of one function in the body of another function.




Only one entity can exist with a particular name in a particular scope. This is seldom a problem for local names, since blocks tend to be relatively short, and names have particular purposes within them, such as naming a counter variable, an argument, etc...

But non-local names bring more possibilities for name collision, especially considering that libraries may declare many functions, types, and variables, neither of them local in nature, and some of them very generic.

Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope. This allows organizing the elements of programs into different logical scopes referred to by names:
[C++\Syntax\Statements\Declarations\Namespace.md]



Because they are defined outside of a function, global variables are considered to be part of the global namespace (hence the term “global namespace scope”).

Global variables are created when the program starts, and destroyed when it ends. This is called static duration. Variables with static duration are sometimes called static variables.

Unlike local variables, which are uninitialized by default, static variables are zero-initialized by default.







Indiscriminate use of global variables is considered poor programming practice. This is because global variables can be
assigned values in any/every function and can contain an unpredictable state, especially when functions that modify them run in
different threads or are programmed by different programmers in
a team.




Scope summary

An identifier’s scope determines where the identifier can be accessed within the source code.

    Variables with block scope / local scope can only be accessed within the block in which they are declared (including nested blocks). This includes:
        Local variables
        Function parameters
        User-defined type definitions (such as enums and classes) declared inside a block
    Variables and functions with global scope / file scope can be accessed anywhere in the file. This includes:
        Global variables
        Functions
        User-defined type definitions (such as enums and classes) declared inside a namespace or in the global scope




Variable scope, duration, and linkage summary

Because variables have scope, duration, and linkage, let’s summarize in a chart:
Type 	Example 	Scope 	Duration 	Linkage 	Notes
Local variable 	int x; 	Block 	Automatic 	None 	
Static local variable 	static int s_x; 	Block 	Static 	None 	
Dynamic variable 	int *x { new int{} }; 	Block 	Dynamic 	None 	
Function parameter 	void foo(int x) 	Block 	Automatic 	None 	
External non-constant global variable 	int g_x; 	File 	Static 	External 	Initialized or uninitialized
Internal non-constant global variable 	static int g_x; 	File 	Static 	Internal 	Initialized or uninitialized
Internal constant global variable 	constexpr int g_x { 1 }; 	File 	Static 	Internal 	Must be initialized
External constant global variable 	extern constexpr int g_x { 1 }; 	File 	Static 	External 	Must be initialized
Inline constant global variable 	inline constexpr int g_x { 1 }; 	File 	Static 	External 	Must be initialized
Internal constant global variable 	const int g_x { 1 }; 	File 	Static 	Internal 	Must be initialized
External constant global variable 	extern const int g_x { 1 }; 	File 	Static 	External 	Must be initialized at definition
Inline constant global variable 	inline const int g_x { 1 }; 	File 	Static 	External 	Must be initialized

## Scope summary

An identifier’s scope determines where the identifier can be accessed within the source code, known as visibility.

Local
	Variables with block scope / local scope can only be accessed within the block in which they are declared (including nested blocks):
	  Local variables
	  Function parameters
	  User-defined type definitions declared inside a block

The Statement, Function, Class, and Namespace scopes can be seen as special cases of Local scope where Statement and Namespace scoped names can be accessed from the point of declaration, while Function and Class scope names can be accessed throughout their brace delimited, {...}, region regardless of their point of declaration.

Global
	Variables and functions with global scope / file scope can be accessed anywhere in the file:
	  Global variables
	  Functions
	  User-defined type definitions declared inside a namespace or in the global scope




## Duration summary

A variable’s duration or lifetime determines when it is created and destroyed.

Automatic:
	Variables with automatic duration are created at the point of definition, and destroyed when the block they are part of is exited:
	  Local variables
	  Function parameters

Static:
	Variables with static duration are created when the program begins and destroyed when the program ends:
	  Global variables
	  Static local variables

Thread:
	Variables with thread duration are created when the thread begins and destroyed when the thread ends.
		variables declared thread_local

Dynamic:
	Variables with dynamic duration are created and destroyed by programmer request:
	  Dynamically allocated variables




## Linkage summary

An identifier’s linkage determines whether multiple declarations of an identifier refer to the same identifier or not.

None (no linkage):
	An identifier with no linkage means the identifier only refers to itself:
	  Local variables
	  User-defined type definitions (such as enums and classes) declared inside a block

Internal:
	An identifier with internal linkage can be accessed anywhere within the file it is declared:
	  Static global variables (initialized or uninitialized)
	  Static functions
	  Const global variables
	  Functions declared inside an unnamed namespace
	  User-defined type definitions (such as enums and classes) declared inside an unnamed namespace

External
	An identifier with external linkage can be accessed anywhere within the file it is declared, or other files (via a forward declaration):
	  Functions
	  Non-const global variables (initialized or uninitialized)
	  Extern const global variables
	  Inline const global variables
	  User-defined type definitions (such as enums and classes) declared inside a namespace or in the global scope

Module
	An identifier with module linkage can be accessed anywhere within the same module unit or in the other translation units of the same named module.
		Names declared in named module and are not exported, and don't have internal linkage.



## Summary Chart

Because variables have scope, duration, and linkage, let’s summarize in a chart:

| Type | Example | Scope | Duration | Linkage | Notes |
|------|---------|-------|----------|---------|-------|
| Local variable | int x; | Block | Automatic | None |  |
| Static local variable | static int s_x; | Block | Static | None |  |
| Dynamic variable | int *x { new int{} }; | Block | Dynamic | None |  |
| Function parameter | void foo(int x) | Block | Automatic | None |  |
| External non-constant global variable | int g_x; | File | Static | External | Initialized or uninitialized |
| Internal non-constant global variable | static int g_x; | File | Static | Internal | Initialized or uninitialized |
| Internal constant global variable | constexpr int g_x { 1 }; | File | Static | Internal | Must be initialized |
| External constant global variable | extern constexpr int g_x { 1 }; | File | Static | External | Must be initialized |
| Inline constant global variable | inline constexpr int g_x { 1 }; | File | Static | External | Must be initialized |
| Internal constant global variable | const int g_x { 1 }; | File | Static | Internal | Must be initialized |
| External constant global variable | extern const int g_x { 1 }; | File | Static | External | Must be initialized at definition |
| Inline constant global variable | inline const int g_x { 1 }; | File | Static | External | Must be initialized |



### Forward declaration summary

You can use a forward declaration to access a function or variable in another file:
| Type | Example | Notes |
|------|---------|-------|
| Function forward declaration | void foo(int x); | Prototype only, no function body |
| Non-constant global variable forward declaration | extern int g_x; | Must be uninitialized |
| Const global variable forward declaration | extern const int g_x; | Must be uninitialized |
| Constexpr global variable forward declaration | extern constexpr int g_x; | Not allowed, constexpr cannot be forward declared |




## Storage class specifier summary

When used as part of an identifier declaration, the static, extern, mutable, and thread_local keywords are called storage class specifiers. In this context, they set the storage duration and linkage of the identifier.

The C++ storage classes are:
	auto
	register
	static
	extern
	mutable
	thread_local

Modern C++ supports 4 active storage class specifiers:
	static
	extern
	mutable
	thread_local

| Specifier | Meaning |
|-----------|---------|
| extern | static (or thread_local) storage duration and external linkage |
| static | static (or thread_local) storage duration and internal linkage |
| thread_local | thread storage duration (C++11) |
| mutable | object allowed to be modified even if containing class is const |
| auto | automatic storage duration C++11 Deprecated |
| register | automatic storage duration and hint to the compiler to place in a register C++17 Deprecated |
The term storage class specifier is typically only used in formal documentation.

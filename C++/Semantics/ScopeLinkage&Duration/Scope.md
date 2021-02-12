### Identifier Access
The visibility of a name, also called its scope, is the region in the program where a declared name can be used.

Named entities, such as variables, functions, and compound types need to be declared before being used in C++. Therefore, an identifier’s scope determines where the identifier can be accessed within the source code.

When an identifier can be accessed, we say it is in scope.
When an identifier can not be accessed, we say it is out of scope.

Scope is a compile-time property, and trying to use an identifier when it is not in scope will result in a compile error.

A variable’s scope begins at the point of variable definition, and stops at the end of the set of curly braces in which they are defined (or for function parameters, at the end of the function). This ensures variables can not be used before the point of definition (even if the compiler opts to create them before then).

Only one entity can exist with a particular name in a particular scope.



### Scope Types
A declaration introduces a name into one of six scope types:


Statement
Names declared in a for, if, while, or switch statement are visible until the end of the statement block.

Local (Block)
A name declared within a function or lambda, including the parameter names, have local scope. They are often referred to as "locals". They are only visible from their point of declaration to the end of the function or lambda body. Local scope is a kind of block scope, which is discussed later in this article.

Function
A label has function scope, which means it is visible throughout a function body even before its point of declaration. Function scope makes it possible to write statements like goto cleanup before the cleanup label is declared.

Class
Names of class members have class scope, which extends throughout the class definition regardless of the point of declaration. Class member accessibility is further controlled by the public, private, and protected keywords. Public or protected members can be accessed only by using the member-selection operators (. or ->) or pointer-to-member operators (.* or ->*).

Namespace
A name that is declared within a namespace, outside of any class or enum definition or function block, is visible from its point of declaration to the end of the namespace. A namespace may be defined in multiple blocks across different files.

Global
A global name is one that is declared outside of any class, function, or namespace. However, in C++ even these names exist with an implicit global namespace. The top-level scope of a translation unit ("file scope" or "global scope") is properly called "global namespace scope". The scope of global names extends from the point of declaration to the end of the translation unit in which they are declared. For global names, visibility is also governed by the rules of linkage which determine whether the name is visible in other files in the program. Indiscriminate use of global names is considered poor programming practice. This is because global names can be accessed in any/every function and can contain an unpredictable state, especially when functions that modify them run in different threads or are programmed by different programmers in a team.


### Naming Conventions
By convention, many developers prefix global variable identifiers with “g” or “g_” to indicate that they are global.


### General Access Rules

In general, the following rules apply when an identifier is accessed:

identifiers of a larger scope are accessible within a block if:
  a. The identifier is declared before the function definition (block)
  b. The function name is different than the identifier
  c. All function parameter names differ from the global identifier name
  d. All local identifier names differ from the global identifier name

identifiers declared within a function, are not accessible outside of the function (block).

An identifier declared within a block is accessible:
  a. Only within the block from the point at which it is declared until the end of the block
  b. By those blocks that are nested within that block if the nested block does not have an identifier with the same name as that of the outside block (the block that encloses the nested block).




### Shadowing

Each block defines its own scope region. So what happens when we have a variable inside a nested scope that has the same name as a variable in an outer scope? When this happens, the nested variable “hides” the outer variable in areas where they are both in scope. This is called name hiding or shadowing.

You can hide a name by declaring the same name in an enclosed scope.

You can hide class names by declaring a function, object or variable, or enumerator in the same scope. However, the class name can still be accessed when prefixed by the keyword class.

You can hide names with global scope by explicitly declaring the same name in block scope. However, global-scope names can be accessed using the scope-resolution operator (::) with no prefix to tell the compiler we mean the global variable instead of the local variable.




### Limiting Scope
Variables should be defined in the most limited scope. By limiting the scope of a variable, you reduce the complexity of the program because the number of active variables is reduced. Further, it makes it easier to see where variables are used (or aren’t used). A variable defined inside a block can only be used within that block (or nested blocks).

Define variables in the most limited existing scope. Avoid creating new blocks whose only purpose is to limit the scope of variables.

Only one entity can exist with a particular name in a particular scope. This is seldom a problem for local names, since blocks tend to be relatively short, and names have particular purposes within them, such as naming a counter variable, an argument, etc...

But non-local names bring more possibilities for name collision, especially considering that libraries may declare many functions, types, and variables, neither of them local in nature, and some of them very generic.

Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope. This allows organizing the elements of programs into different logical scopes referred to by names:
[C++\Syntax\Statements\Declarations\Namespace.md]

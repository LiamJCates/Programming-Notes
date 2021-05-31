A common misconception is that definition equals declaration plus initialization.

The concepts of declaration, definition, and initialization are described below.


Declarations vs. definitions

A declaration furnishes the compiler with the basic information it needs, so that you can use a name in a program. In particular, a function declaration tells the compiler about the function’s name, return type, parameter types, and modifiers, such as const and override. A definition is a particular kind of declaration that also provides the full implementation details for an entity. For example, a function definition includes all the information of a function declaration, plus the function body. Classes, however, add another layer of complexity, because you can declare or define the class’s members independently of the class definition itself. A class definition must declare all of its members. Sometimes, you can also define a member function as part of a class definition (which is the style I’ve been using so far), but most programmers prefer to declare member functions inside the class and to define the member functions separately, outside of the class definition. As with any function declaration, a member function declaration includes the return type (possibly with a virtual specifier), the function name, the function parameters, and an optional const or override modifier. If the function is a pure virtual function, you must include the = 0 token marks as part of the function declaration, and you don’t define the function. The function definition is like any other function definition, with a few exceptions. The definition must follow the declaration—that is, the member function definition must come later in the source file than the class definition that declares the member function. In the definition, omit the virtual and override specifiers. The function name must start with the class name, followed by the scope operator (::) and the function name, so that the compiler knows which member function you are defining. Write the function body the same way you would write it if you provided the function definition inside the class definition.

In C++, you’ll often hear the words “declaration” and “definition” used, often interchangeably, though they are not.

A definition actually implements (for functions or types) or instantiates (for variables) the identifier. Here are some examples of definitions:

int add(int x, int y) // implements function add()
{
    int z{ x + y }; // instantiates variable z

    return z;
}

A definition is needed to satisfy the linker. If you use an identifier without providing a definition, the linker will error.


###One Definition Rule

The compiler enforces the rule that permits one definition of a class, function, or object per source file. Another rule is that you can have only one definition of a function or global object in the entire program. You can define a class in multiple source files, provided the definition is the same in all source files. Inline functions follow different rules than ordinary functions. You can define an inline function in multiple source files. Each source file must have no more than one definition of the inline function, and every definition in the program must be the same. These rules are collectively known as the One-Definition Rule (ODR). The compiler enforces the ODR within a single source file. However, the standard does not require a compiler or linker to detect any ODR violations that span multiple source files. If you make such a mistake, the problem is all yours to find and fix.

The one definition rule (or ODR for short) is a well-known rule in C++.

The ODR has three parts:

    Within a given file, a function, object, type, or template can only have one definition.
    Within a given program, an object or normal function can only have one definition. This distinction is made because programs can have more than one file.
    Types, templates, inline functions, and variables are allowed to have identical definitions in different files.

Violating part 1 of the ODR will cause the compiler to issue a redefinition error. Violating ODR part 2 will likely cause the linker to issue a redefinition error. Violating ODR part 3 will cause undefined behavior.


A declaration is a statement that tells the compiler about the existence of an identifier and its type information. Here are some examples of declarations:

int add(int x, int y); // tells the compiler about a function named "add" that takes two int parameters and returns an int.  No body!
int x; // tells the compiler about an integer variable named x

A declaration is all that is needed to satisfy the compiler. This is why we can use a forward declaration to tell the compiler about an identifier that isn’t actually defined until later.

In C++, all definitions also serve as declarations. This is why int x appears in our examples for both definitions and declarations. Since int x is a definition, it’s a declaration too. In most cases, a definition serves our purposes, as it satisfies both the compiler and linker. We only need to provide an explicit declaration when we want to use an identifier before it has been defined.

While it is true that all definitions are declarations, the converse is not true: all declarations are not definitions. An example of this is the function prototype -- it satisfies the compiler, but not the linker. These declarations that aren’t definitions are called pure declarations. Other types of pure declarations include forward declarations for variables and type declarations (you will encounter these in future lessons, no need to worry about them now).

The ODR doesn’t apply to pure declarations (it’s the one definition rule, not the one declaration rule), so you can have as many pure declarations for an identifier as you desire (although having more than one is redundant).

Author's note

In common language, the term “declaration” is typically used to mean “a pure declaration”, and “definition” is used to mean “a definition that also serves as a declaration”. Thus, we’d typically call int x; a definition, even though it is both a definition and a declaration.



### Declaration

Declaration, generally, refers to the introduction of a new name in the program. For example, you can declare a new function by describing it's "signature":

void xyz();

or declare an incomplete type:

class klass;
struct ztruct;

and last but not least, to declare an object:

int x;

It is described, in the C++ standard, at §3.1/1 as:

    A declaration (Clause 7) may introduce one or more names into a translation unit or redeclare names introduced by previous declarations.


### Forward Declarations

The <istream> header contains the full declaration of std::istream and other, related declarations, and <ostream> declares std::ostream. These are large classes in large headers. Sometimes, you don’t need the full class declarations.

For example, declaring an input or output function in an interface requires informing the compiler that std::istream and std::ostream are classes, but the compiler needs to know the full class definitions only in the implementation file. The header <iosfwd> is a small header that declares the names std::istream, std::ostream, and so on, without providing the complete class declarations. Thus, you can reduce compilation time for any file that includes a header by changing <istream> and <ostream> to <iosfwd>. You can do the same for your own classes by declaring the class name after the class keyword, with nothing else describing the class: class rational; This is known as a forward declaration. You can use a forward declaration when the compiler has to know a name is a class but doesn’t have to know the size of the class or any of the class’s members. A common case is using a class solely as a reference function parameter. If your header uses <iosfwd> or other forward declarations, be sure to include the full class declarations (e.g., <iostream>) in the .cpp source file


### Definition

A definition is a definition of a previously declared name (or it can be both definition and declaration). For example:

int x;
void xyz() {...}
class klass {...};
struct ztruct {...};
enum { x, y, z };

Specifically the C++ standard defines it as:

  A declaration is a definition unless it declares a function without specifying the function’s body (8.4), it contains the extern specifier (7.1.1) or a linkage-specification25 (7.5) and neither an initializer nor a function-body, it declares a static data member in a class definition (9.2, 9.4), it is a class name declaration (9.1), it is an opaque-enum-declaration (7.2), it is a template-parameter (14.1), it is a parameter-declaration (8.3.5) in a function declarator that is not the declarator of a function-definition, or it is a typedef declaration (7.1.3), an alias-declaration (7.1.3), a using-declaration (7.3.3), a static_assert-declaration (Clause 7), an attribute-declaration (Clause 7), an empty-declaration (Clause 7), or a using-directive (7.3.4).



### Initialization

Initialization refers to the "assignment" of a value, at construction time. For a generic object of type T, it's often in the form:

T x = i;

but in C++ it can be:

T x(i);

or even:

T x {i};

with C++11.



### Conclusion

    So does it mean definition equals declaration plus initialization?

It depends. On what you are talking about. If you are talking about an object, for example:

int x;

This is a definition without initialization. The following, instead, is a definition with initialization:

int x = 0;

In certain context, it doesn't make sense to talk about "initialization", "definition" and "declaration". If you are talking about a function, for example, initialization does not mean much.

So, the answer is no: definition does not automatically mean declaration plus initialization.

The most important reason to know about separating declarations from definitions is so you can put a definition in one source file and a declaration in another.






Declarators
As you’ve already seen, you can define multiple variables in a single declaration, as demonstrated in the following:

int x{42}, y{}, z{x+y};

The entire declaration contains three declarators. Each declarator declares a single name, whether that name is for a variable, function, or type.

Most C++ programmers don’t use this term in everyday conversation, but C++ experts often do. You have to know official C++ terminology, so that if you have to ask for help from the experts, you can understand them





A definition of a named object instructs the compiler to set aside memory for storing the object’s value and to generate the necessary code to initialize the object. Some objects are actually sub-objects—not entire objects on their own (entire objects are called complete objects in C++ parlance). A sub-object doesn’t get its own definition; instead, its memory and lifetime are dictated by the complete object that contains it. That’s why a data member or base class doesn’t get a definition of its own. Instead, the definition of an object with class type causes memory to be set aside for all of the object’s data members. Thus, a class definition contains declarations of data members but not definitions. You define a variable that is local to a block. The definition specifies the object’s type, name, whether it is const, and the initial value (if any). You can’t declare a local variable without defining it, but there are other kinds of declarations. You can declare a local reference as a synonym for a local variable. Declare the new name as a reference in the same manner as a reference parameter, but initialize it with an existing object. If the reference is const, you can use any expression (of a suitable type) as the initializer. For a non-const reference, you must use an lvalue, such as another variable.

```cpp
#include  <iostream>;
int main()
{
  // definition of a named object, also an lvalue
  int answer{42};

  // declaration of a reference named ref
  int& ref{answer};

  // changes the value of answer
  ref = 10;

  std::cout << answer << '\n';

  // declaration; must be const to initialize with expr
  int const& cent{ref * 10};

  std::cout << cent << '\n';
}
```

A local reference is not a definition, because no memory is allocated, and no initializers are run. Instead, the reference declaration creates a new name for an old object.

Remember that a reference is just another name for something else. You must initialize a reference or else it would be the name of nothing at all, and that is simply not allowed.

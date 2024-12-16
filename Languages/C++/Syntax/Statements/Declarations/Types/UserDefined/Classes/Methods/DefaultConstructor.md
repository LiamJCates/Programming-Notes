Default constructors

A default constructor is a constructor which can be called with no arguments (either defined with an empty parameter list, or with default arguments provided for every parameter). A type with a public default constructor is DefaultConstructible.

Syntax
(1)	class_name ( ) ; 	 	
(2)	class_name :: class_name ( ) body 	
(3)	class_name() = delete ; 	 								(since C++11)
(4)	class_name() = default ;									(since C++11)
(5)	class_name :: class_name ( ) = default ;	(since C++11)

Where class_name must name the current class (or current instantiation of a class template), or, when declared at namespace scope or in a friend declaration, it must be a qualified class name.
Explanation
1) Declaration of a default constructor inside of class definition.
2) Definition of the constructor outside of class definition (the class must contain a declaration (1)). See constructors and member initializer lists for details on the constructor body
3) Deleted default constructor: if it is selected by overload resolution, the program fails to compile.
4) Defaulted default constructor: the compiler will define the implicit default constructor even if other constructors are present.
5) Defaulted default constructor outside of class definition (the class must contain a declaration (1)). Such constructor is treated as user-provided (see below and value initialization).

Default constructors are called during default initializations and value initializations.
Implicitly-declared default constructor

If no user-declared constructors of any kind are provided for a class type (struct, class, or union), the compiler will always declare a default constructor as an inline public member of its class.

If some user-declared constructors are present, the user may still force the automatic generation of a default constructor by the compiler that would be implicitly-declared otherwise with the keyword default.
	(since C++11)

The implicitly-declared (or defaulted on its first declaration) default constructor has an exception specification as described in dynamic exception specification (until C++17)exception specification (since C++17)
Implicitly-defined default constructor

If the implicitly-declared default constructor is not defined as deleted, it is defined (that is, a function body is generated and compiled) by the compiler if odr-used or needed for constant evaluation (since C++11), and it has the same effect as a user-defined constructor with empty body and empty initializer list. That is, it calls the default constructors of the bases and of the non-static members of this class. If this satisfies the requirements of a constexpr constructor, the generated constructor is constexpr. (since C++11) Class types with an empty user-provided constructor may get treated differently than those with an implicitly-defined or defaulted default constructor during value initialization.

If some user-defined constructors are present, the user may still force the automatic generation of a default constructor by the compiler that would be implicitly-declared otherwise with the keyword default.
	(since C++11)
Deleted implicitly-declared default constructor

The implicitly-declared or defaulted (since C++11) default constructor for class T is undefined (until C++11)defined as deleted (since C++11) if any of the following is true:

    T has a member of reference type without a default initializer. (since C++11)
    T has a non-const-default-constructible const member without a default member initializer (since C++11).
    T has a member (without a default member initializer) (since C++11) which has a deleted default constructor, or its default constructor is ambiguous or inaccessible from this constructor.
    T has a direct or virtual base which has a deleted default constructor, or it is ambiguous or inaccessible from this constructor.
    T has a direct or virtual base which has a deleted destructor, or a destructor that is inaccessible from this constructor.

    T is a union with at least one variant member with non-trivial default constructor, and no variant member of T has a default member initializer.
    T is a non-union class with a variant member M with a non-trivial default constructor, and no variant member of the anonymous union containing M has a default member initializer.

	(since C++11)

    T is a union and all of its variant members are const.

If no user-defined constructors are present and the implicitly-declared default constructor is not trivial, the user may still inhibit the automatic generation of an implicitly-defined default constructor by the compiler with the keyword delete.
	(since C++11)
Trivial default constructor

The default constructor for class T is trivial (i.e. performs no action) if all of the following is true:

    The constructor is not user-provided (i.e., is implicitly-defined or defaulted on its first declaration)
    T has no virtual member functions
    T has no virtual base classes

    T has no non-static members with default initializers.

	(since C++11)

    Every direct base of T has a trivial default constructor
    Every non-static member of class type (or array thereof) has a trivial default constructor

A trivial default constructor is a constructor that performs no action. All data types compatible with the C language (POD types) are trivially default-constructible.
Eligible default constructor

A default constructor is eligible if it is either user-declared or both implicitly-declared and definable.
	(until C++11)

A default constructor is eligible if it is not deleted.
	(since C++11)
(until C++20)

A default constructor is eligible if

    it is not deleted, and
    its associated constraints, if any, are satisfied, and
    no default constructor is more constrained than it.

	(since C++20)

Triviality of eligible default constructors determines whether the class is an implicit-lifetime type, and whether the class is a trivial type.
Example
Run this code
```cpp
class A
{
public:
    int x;
    A(int x = 1): x(x) {} // user-defined default constructor
};

class B : public A
{
	// B::B() is implicitly-defined, calls A::A();
};

class C
{
	public:
    A a;
		//C::C() is implicitly-defined, calls A::A()
};

class D : public A
{
	public:
    D(int y): A(y) {}
    //D::D() isnt declared because another constructor exists
};

class E : public A
{
	public:
    E(int y): A(y) {}
    E() = default; // explicitly defaulted, calls A::A()
};

class F
{
	public:
    int& ref; // reference member
    const int c; // const member
    // F::F() is implicitly defined as deleted
};

int main()
{
    A a;
    B b;
    C c;
//  D d; // compile error as there is no default constructor
    E e;
//  F f; // compile error as F has a member of reference type without a default initializer.
}
```



If you do not supply any constructors, the compiler implicitly writes a default constructor and a copy
constructor. If you write at least one constructor of any variety, the compiler does not implicitly write a
default constructor, but it still gives you a copy constructor if you don’t write one yourself.
You can take control over the compiler’s implicit behavior without writing any of your own constructors.
Write a function header without a body for the constructor, and use =default to get the compiler’s implicit
definition. Use =delete to suppress that function. For example, if you don’t want anyone creating copies of a
class, note the following:
struct dont_copy
{
dont_copy(dont_copy const&) = delete;
};
More common is letting the compiler write its copy constructor but telling the human reader
explicitly. As you learn more about C++, you will learn that the rules for which constructors the compiler
writes for you, and when it writes them, are more complicated than what I’ve presented so far. I urge you
to get into the habit of stating when you ask the compiler to implicitly provide a constructor, even if it
seems trivially obvious.
struct point
{
point() = default;
point(point const&) = default;
int x, y;
};

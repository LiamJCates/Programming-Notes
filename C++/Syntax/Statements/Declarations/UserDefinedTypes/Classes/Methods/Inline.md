To retain the efficiency of the preprocessor macro, but to add the
safety and class scoping of true functions, C++ has the inline
function.

To see more information related to macros, see:
[C++\Syntax\Statements\Declarations\Preprocessor\macros.md]

In solving the C++ problem of a macro with access to private class members, all the problems associated with preprocessor macros were eliminated. This was done by bringing the concept of macros under the control of the compiler where they belong. C++ implements the macro as inline function, which is a true function in every sense. Any behavior you expect from an ordinary function, you get from an inline function. The only difference is that an inline function is expanded in place, like a preprocessor macro, so the overhead of the function call is eliminated. Thus, you should (almost) never use macros, only inline functions.

Any function defined within a class body is automatically inline, but you can also make a non-class function inline by preceding it with the inline keyword.

However, for it to have any effect, you must include the function body with the declaration, otherwise the compiler will treat it as an ordinary function declaration:

inline int plusOne(int x);

has no effect at all other than declaring the function (which may or may not get an inline definition sometime later).

The successful approach provides the function body:

inline int plusOne(int x) { return ++x; }

Notice that the compiler will check (as it always does) for the proper use of the function argument list and return value (performing any necessary conversions), something the preprocessor is incapable of.

Also, if you try to write the above as a preprocessor macro, you get an unwanted side effect.

You’ll almost always want to put inline definitions in a header file.

When the compiler sees such a definition, it puts the function type (the signature combined with the return value) and the function body in its symbol table. When you use the function, the compiler checks to ensure the call is correct and the return value is being used correctly, and then substitutes the function body for the function call, thus eliminating the overhead.

The inline code does occupy space, but if the function is small, this can actually take less space than the code generated to do an ordinary function call
(pushing arguments on the stack and doing the CALL).

An inline function in a header file has a special status, since you must include the header file containing the function and its definition in every file where the function is used, but you don’t end up with multiple definition errors (however, the definition must be identical in all places where the inline function is included)



### Inlines inside classes
To define an inline function, you must ordinarily precede the function definition with the inline keyword. However, this is not necessary inside a class definition. Any function you define inside a class definition is automatically an inline.

For example:
```cpp
// Inlines inside classes
#include <iostream>
#include <string>
using namespace std;
class Point
{
	int i, j, k;

public:
	Point() : i(0), j(0), k(0) {}
	Point(int ii, int jj, int kk)
		: i(ii), j(jj), k(kk) {}
	void print(const string &msg = "") const
	{
		if (msg.size() != 0)
			cout << msg << endl;
		cout << "i = " << i << ", "
			 << "j = " << j << ", "
			 << "k = " << k << endl;
	}
};
int main()
{
	Point p, q(1, 2, 3);
	p.print("value of p");
	q.print("value of q");
}
```

Here, the two constructors and the print( )function are all inlines by default.

Notice in main( ) that the fact you are using inline functions is transparent, as it should be. The logical behavior of a function must be identical regardless of whether it’s an inline (otherwise your compiler is broken). The only difference you’ll see is in performance.

Of course, the temptation is to use inlines everywhere inside class declarations because they save you the extra step of making the external member function definition. Keep in mind, however, that the idea of an inline is to provide improved opportunities for optimization by the compiler.

But inlining a big function will cause that code to be duplicated everywhere the function is called, producing code bloat that may mitigate the speed benefit (the only reliable course of action is to experiment to discover the effects of inlining on your program with your compiler).



### Accessor and Mutator functions

One of the most important uses of inlines inside classes is the access and mutate functions.

Making these functions inline means their execution is remarkably efficient.
In addition, without inlines, the code generated for accessors and mutators would typically include pushing this on the stack and making an assembly language CALL. With most machines, the size of the code would be larger than the code created by the inline, and the execution time would certainly be longer.



### Inlines & the compiler
To understand when inlining is effective, it’s helpful to know what the compiler does when it encounters an inline.

As with any function, the compiler holds the function type (that is, the function prototype including the name and argument types, in combination with the function return value) in its symbol table.

In addition, when the compiler sees that the inline’s function type and the function body parses without error, the code for the function body is also brought into the symbol table. Whether the code is stored in source form, compiled assembly instructions, or some other representation is up to the compiler.

When you make a call to an inline function,

the compiler first ensures that the call can be correctly made. That is, all the argument types must either be the exact types in the function’s argument list, or the compiler must be able to make a type conversion to the proper types and the return value must be the correct type (or convertible to the correct type) in the destination expression. This, of course, is exactly what the compiler does for any function and is markedly different from what the preprocessor does because the preprocessor cannot check types or make conversions.

If all the function type information fits the context of the call, then the inline code is substituted directly for the function call, eliminating the call overhead and allowing for further optimizations by the compiler.

Also, if the inline is a member function, the address of the object (this) is put in the appropriate place(s), which of course is another action the preprocessor is unable to perform.



### Limitations
There are two situations in which the compiler cannot perform inlining. In these cases, it simply reverts to the ordinary form of a function by taking the inline definition and creating storage for the function just as it does for a non-inline. If it must do this in multiple translation units (which would normally cause a multiple definition error), the linker is told to ignore the multiple definitions.

The compiler cannot perform inlining if the function is too complicated. This depends upon the particular compiler, but at the point most compilers give up, the inline probably wouldn’t gain you any efficiency.

In general, any sort of looping is considered too complicated to expand as an inline, and if you think about it, looping probably entails much more time inside the function than what is required for the function call overhead.

If the function is just a collection of simple statements, the compiler probably won’t have any trouble inlining it, but if there are a lot of statements, the overhead of the function call will be much less than the cost of
executing the body. And remember, every time you call a big inline function, the entire function body is inserted in place of each call, so you can easily get code bloat without any noticeable performance improvement. (Note that some of the examples in this book may
exceed reasonable inline sizes in favor of conserving screen real
estate.)

The compiler also cannot perform inlining if the address of the function is taken implicitly or explicitly. If the compiler must produce an address, then it will allocate storage for the function code and use the resulting address.

However, where an address is not required, the compiler will probably still inline the code.

It is important to understand that an inline is just a suggestion to the compiler; the compiler is not forced to inline anything at all. A good compiler will inline small, simple functions while intelligently ignoring inlines that are too complicated. This will give you the results you want – the true semantics of a function call with the efficiency of a macro.



### Forward references
If you’re imagining what the compiler is doing to implement inlines, you can confuse yourself into thinking there are more limitations than actually exist. In particular, if an inline makes a
forward reference to a function that hasn’t yet been declared in the class (whether that function is inline or not), it can seem like the compiler won’t be able to handle it:

```cpp
// Inline evaluation order
class Forward
{
	int i;

public:
	Forward() : i(0) {}
	// Call to undeclared function:
	int f() const { return g() + 1; }
	int g() const { return i; }
};
int main()
{
	Forward frwd;
	frwd.f();
}
```

In f( ), a call is made to g( ), although g( ) has not yet been declared.

This works because the language definition states that no inline functions in a class shall be evaluated until the closing brace of the class declaration.

Of course, if g( ) in turn called f( ), you’d end up with a set of
recursive calls, which are too complicated for the compiler to inline.

(Also, you’d have to perform some test in f( ) or g( ) to force one of
them to “bottom out,” or the recursion would be infinite.)



### Hidden activities in constructors & destructors

Constructors and destructors are two places where you can be
fooled into thinking that an inline is more efficient than it actually
is. Constructors and destructors may have hidden activities,
because the class can contain subobjects whose constructors and
destructors must be called. These subobjects may be member
objects, or they may exist because of inheritance



### Reducing clutter
In examples, the simplicity and terseness of putting inline
definitions inside classes is very useful because more fits on a page
or screen (in a seminar).

However, Dan Saks2 has pointed out that in a real project this has the effect of needlessly cluttering the class interface and thereby making the class harder to use. He refers to member functions defined within classes using the Latin in situ (in place) and maintains that all definitions should be placed outside the class to keep the interface clean. Optimization, he argues, is a
separate issue. If you want to optimize, use the inline keyword

Now if you want to compare the effect of inline functions to noninline functions, you can simply remove the inlinekeyword.
(Inline functions should normally be put in header files, however,
while non-inline functions must reside in their own translation
unit.) If you want to put the functions into documentation, it’s a
simple cut-and-paste operation. In situ functions require more work
and have greater potential for errors. Another argument for this
approach is that you can always produce a consistent formatting
style for function definitions, something that doesn’t always occur
with in situ functions.

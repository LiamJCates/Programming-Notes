One of the important features C++ inherits from C is efficiency.

If the efficiency of C++ were dramatically less than C, there would be a significant contingent of programmers who couldn’t justify its use.

In C, one of the ways to preserve efficiency is through the use of macros, which allow you to make what looks like a function call without the normal function call overhead. The macro is implemented with the preprocessor instead of the compiler proper, and the preprocessor replaces all macro calls directly with the macro code, so there’s no cost involved from pushing arguments, making an assembly-language CALL, returning arguments, and performing an assembly-language RETURN. All the work is performed by the preprocessor, so you have the convenience and readability of a function call but it doesn’t cost you anything.

There are two problems with the use of preprocessor macros in C++.

The first is also true with C: a macro looks like a function call, but doesn’t always act like one. This can bury difficult-to-find bugs.

The second problem is specific to C++: the preprocessor has no permission to access class member data. This means preprocessor macros cannot be used as class member functions.



### Preprocessor pitfalls

The key to the problems of preprocessor macros is that you can be fooled into thinking that the behavior of the preprocessor is the same as the behavior of the compiler.

Of course, it was intended that a macro look and act like a function call, so it’s quite easy to fall into this fiction. The difficulties begin when the subtle differences appear.

As a simple example, consider the following:

#define F (x) (x + 1)

Now, if a call is made to F like this

F(1)

the preprocessor expands it, somewhat unexpectedly, to the following:

(x) (x + 1)(1)

The problem occurs because of the gap between F and its opening parenthesis in the macro definition. When this gap is removed, you can actually call the macro with the gap

F (1)

and it will still expand properly to

(1 + 1)

The example above is fairly trivial and the problem will make itself evident right away. The real difficulties occur when using expressions as arguments in macro calls.

There are two problems.

The first is that expressions may expand inside the macro so that their evaluation precedence is different from what you expect.
For example,

#define FLOOR(x,b) x>=b?0:1

Now, if expressions are used for the arguments

if(FLOOR(a&0x0f,0x07)) // ...

the macro will expand to

if(a&0x0f>=0x07?0:1)

The precedence of & is lower than that of >=, so the macro evaluation will surprise you. Once you discover the problem, you can solve it by putting parentheses around everything in the macro definition. (This is a good practice to use when creating preprocessor macros.)

Thus,

#define FLOOR(x,b) ((x)>=(b)?0:1)

Discovering the problem may be difficult, however, and you may not find it until after you’ve taken the proper macro behavior for granted.

In the un-parenthesized version of the preceding macro, most expressions will work correctly because the precedence of >= is lower than most of the operators like +, /, – –, and even the bitwise shift operators. So you can easily begin to think that it works with all expressions, including those using bitwise logical operators.

The preceding problem can be solved with careful programming practice: parenthesize everything in a macro.

However, the second difficulty is subtler. Unlike a normal function, every time you use an argument in a macro, that argument is evaluated. As long as the
macro is called only with ordinary variables, this evaluation is benign, but if the evaluation of an argument has side effects, then the results can be surprising and will definitely not mimic function behavior.

For example, this macro determines whether its argument falls within a certain range:

#define BAND(x) (((x)>5 && (x)<10) ? (x) : 0)

As long as you use an “ordinary” argument, the macro works very much like a real function. But as soon as you relax and start believing it is a real function, the problems start.

Thus:
```cpp
//: C09:MacroSideEffects.cpp
#include "../require.h"
#include <fstream>
using namespace std;
#define BAND(x) (((x) > 5 && (x) < 10) ? (x) : 0)
int main()
{
	ofstream out("macro.out");
	assure(out, "macro.out");
	for (int i = 4; i < 11; i++)
	{
		int a = i;
		out << "\na = " << a << endl
			<< '\t';
		out << "BAND(++a)=" << BAND(++a) << endl;
		out << "\t a = " << a << endl;
	}
} ///:~
```

Notice the use of all upper-case characters in the name of the macro. This is a helpful practice because it tells the reader this is a macro and not a function, so if there are problems, it acts as a little reminder.

Here’s the output produced by the program, which is not at all what you would have expected from a true function:

a = 4
BAND(++a)=0
a = 5

a = 5
BAND(++a)=8
a = 8

a = 6
BAND(++a)=9
a = 9

a = 7
BAND(++a)=10
a = 10

a = 8
BAND(++a)=0
a = 10

a = 9
BAND(++a)=0
a = 11

a = 10
BAND(++a)=0
a = 12

When a is four, only the first part of the conditional occurs, so the expression is evaluated only once, and the side effect of the macro call is that a becomes five, which is what you would expect from a normal function call in the same situation.

However, when the number is within the band, both conditionals are tested, which
results in two increments. The result is produced by evaluating the argument again, which results in a third increment.

Once the number gets out of the band, both conditionals are still tested so you get two increments. The side effects are different, depending on the argument.

This is clearly not the kind of behavior you want from a macro that looks like a function call. In this case, the obvious solution is to make it a true function, which of course adds the extra overhead and may reduce efficiency if you call that function a lot.

Unfortunately, the problem may not always be so obvious, and you can unknowingly get a library that contains functions and macros mixed together, so a problem like this can hide some very difficult to-find bugs. For example, the putc()macro in cstdio may evaluate its second argument twice. This is specified in Standard C. Also, careless implementations of toupper( )as a macro may evaluate the argument more than once, which will give you unexpected results
with toupper(*p++.)



Macros and access
Of course, careful coding and use of preprocessor macros is required with C, and we could certainly get away with the same thing in C++ if it weren’t for one problem:

a macro has no concept of the scoping required with member functions.

The preprocessor simply performs text substitution, so you cannot say something like

```cpp
class X
{
	int i;
	public:
		#define VAL(X::i) // Error
	...
}
}
```


or anything even close.

In addition, there would be no indication of which object you were referring to. There is simply no way to express class scope in a macro. Without some alternative to preprocessor macros, programmers will be tempted to make some
data members public for the sake of efficiency, thus exposing the underlying implementation and preventing changes in that implementation, as well as eliminating the guarding that private provides.



More preprocessor features
Earlier, I said that you almost always want to use inlinefunctions
instead of preprocessor macros. The exceptions are when you need
to use three special features in the C preprocessor (which is also the
C++ preprocessor): stringizing, string concatenation, and token
pasting. Stringizing, introduced earlier in the book, is performed
with the # directive and allows you to take an identifier and turn it
into a character array. String concatenation takes place when two
adjacent character arrays have no intervening punctuation, in
which case they are combined. These two features are especially
useful when writing debug code. Thus,
#define DEBUG(x) cout << #x " = " << x << endl9: Inline Functions 419
This prints the value of any variable. You can also get a trace that
prints out the statements as they execute:
#define TRACE(s) cerr << #s << endl; s
The #s stringizes the statement for output, and the second s
reiterates the statement so it is executed. Of course, this kind of
thing can cause problems, especially in one-line for loops:
for(int i = 0; i < 100; i++)
TRACE(f(i));
Because there are actually two statements in the TRACE( )macro,
the one-line for loop executes only the first one. The solution is to
replace the semicolon with a comma in the macro.
Token pasting
Token pasting, implemented with the ## directive, is very useful
when you are manufacturing code. It allows you to take two
identifiers and paste them together to automatically create a new
identifier. For example,
#define FIELD(a) char* a##_string; int a##_size
class Record {
FIELD(one);
FIELD(two);
FIELD(three);
// ...
};
Each call to the FIELD( )macro creates an identifier to hold a
character array and another to hold the length of that array. Not
only is it easier to read, it can eliminate coding errors and make
maintenance easier.

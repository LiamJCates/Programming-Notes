Programs produce results by manipulating (reading, changing, and writing) data.

In computing, data is any information that can be moved, processed, or stored by a computer.

C++ Program data values are supplied by name (variables, constants) and expressions

Variables are tools that help the programmer temporarily store data for
a finite amount of time.

Constants are tools that help the programmer define artifacts that are not allowed to change or make changes.

Expressions are any valid unit of code, a combination of one or more constants, variables, functions, and operators, that the programming language interprets to resolve to a value.


the main objective of a C++ program is to perform calculations and
manipulate data. Recall that data must be loaded into the main memory before it can be manipulated.

Storing data in the computer’s memory is a two-step process:
1. Instruct the computer to allocate memory.
2. Include statements in the program to put data into the allocated memory.


## Variables
Variable: A memory location whose content may change during program execution

The values of variables are stored somewhere in an unspecified location in the computer memory as zeros and ones. Our program does not need to know the exact location where a variable is stored; it can simply refer to it by its name. What the program needs to be aware of is the kind of data stored in the variable. It's not the same to store a simple integer as it is to store a letter or a large floating-point number; even though they are all represented using zeros and ones, they are not interpreted in the same way, and in many cases, they don't occupy the same amount of memory.

A Variable Has Three Aspects
Type: The type of information that the variable can hold
Name: The name you use in your application to refer to the variable
Value: The actual thing that the storage bin holds


The variable type attribute tells the compiler the nature of data the variable can store, and the compiler reserves the necessary memory space. The name chosen by the programmer is a friendly replacement for the address in the memory where the variable’s value is stored.



Yet, declaring a variable when it is first needed is often better as it makes the code readable—one notices the type of the variable when the declaration is close to its point of first use.

While some user defined types might have a default initialization, built in types do not. Unless the initial value is assigned, you cannot be sure of the contents of that variable's memory location. Therefore, initialization is optional, but it’s often a good programming practice

In C++, you must declare all identifiers before you can use them. If you refer to an
identifier without declaring it, the compiler will generate an error message (syntax error),
indicating that the identifier is not declared. Therefore, to use either a named constant
or a variable, you must first declare it.




## Expressions
Expressions
There are three types of arithmetic expressions in C++:

Integral expressions: all operands in the expression are integers. An integral expression yields an integral result.

Floating-point (decimal) expressions—all operands in the expression
are floating points (decimal numbers). A floating-point expression
yields a floating-point result.

Mixed expressions the expression contains both integers and decimal numbers.


From these rules, it follows that when evaluating a mixed expression, you concentrate on one operator at a time, using the rules of precedence.

If the operator to be evaluated has one integer operand and one floating-point operand, before evaluating this operator, convert the integer operand to a floating-point number with the decimal part of 0.


A common expression is assignment

The assignment operator replaces the value contained by the operand to the left (l-value) by that on the right (r-value).

There are two kinds of expressions in C++ −

    lvalue − An lvalue is an expression that identifies a non-temporary object. Expressions that refer to a memory location is called "lvalue" expression. An lvalue may appear as either the left-hand or right-hand side of an assignment. As a general rule, if you have a name for a variable, it is an lvalue, regardless of whether it is modifiable.

    rvalue − An rvalue is an expression that identifies a temporary object or is a value (such as a literal constant) not associated with any object. The term rvalue refers to a data value that is stored at some address in memory. An rvalue is an expression that cannot have a value assigned to it which means an rvalue may appear on the right- but not left-hand side of an assignment. Intuitively, if the function call computes an expression whose value does not exist prior to the call and does not exist once the call is finished unless it is copied somewhere, it is likely to be an rvalue.

Variables are lvalues and so may appear on the left-hand side of an assignment. Numeric literals are rvalues and so may not be assigned and can not appear on the left-hand side.

So, all l-values can be r-values, but not all r-values can be l-values.

Following is a valid statement −

int g = 20;

But the following is not a valid statement and would generate compile-time error −

10 = 20;

Outputting or accessing the value of a variable in an expression does not destroy or modify the contents of the variable.



https://en.cppreference.com/w/cpp/language/value_category


R-value references
By Alex on February 20th, 2017 | last modified by Alex on December 21st, 2020

Way back in chapter 1, we mentioned l-values and r-values, and then told you not to worry that much about them. That was fair advice prior to C++11. But understanding move semantics in C++11 requires a re-examination of the topic. So let’s do that now.

L-values and r-values

Despite having the word “value” in their names, l-values and r-values are actually not properties of values, but rather, properties of expressions.

Every expression in C++ has two properties: a type (which is used for type checking), and a value category (which is used for certain kinds of syntax checking, such as whether the result of the expression can be assigned to). In C++03 and earlier, l-values and r-values were the only two value categories available.

The actual definition of which expressions are l-values and which are r-values is surprisingly complicated, so we’ll take a simplified view of the subject that will largely suffice for our purposes.

It’s simplest to think of an l-value (also called a locator value) as a function or an object (or an expression that evaluates to a function or object). All l-values have assigned memory addresses.

When l-values were originally defined, they were defined as “values that are suitable to be on the left-hand side of an assignment expression”. However, later, the const keyword was added to the language, and l-values were split into two sub-categories: modifiable l-values, which can be changed, and non-modifiable l-values, which are const.

It’s simplest to think of an r-value as “everything that is not an l-value”. This notably includes literals (e.g. 5), temporary values (e.g. x+1), and anonymous objects (e.g. Fraction(5, 2)). r-values are typically evaluated for their values, have expression scope (they die at the end of the expression they are in), and cannot be assigned to. This non-assignment rule makes sense, because assigning a value applies a side-effect to the object. Since r-values have expression scope, if we were to assign a value to an r-value, then the r-value would either go out of scope before we had a chance to use the assigned value in the next expression (which makes the assignment useless) or we’d have to use a variable with a side effect applied more than once in an expression (which by now you should know causes undefined behavior!).

In order to support move semantics, C++11 introduces 3 new value categories: pr-values, x-values, and gl-values. We will largely ignore these since understanding them isn’t necessary to learn about or use move semantics effectively. If you’re interested, cppreference.com has an extensive list of expressions that qualify for each of the various value categories, as well as more detail about them.

L-value references

Prior to C++11, only one type of reference existed in C++, and so it was just called a “reference”. However, in C++11, it’s sometimes called an l-value reference. L-value references can only be initialized with modifiable l-values.
L-value reference 	Can be initialized with 	Can modify
Modifiable l-values 	Yes 	Yes
Non-modifiable l-values 	No 	No
R-values 	No 	No

L-value references to const objects can be initialized with l-values and r-values alike. However, those values can’t be modified.
L-value reference to const 	Can be initialized with 	Can modify
Modifiable l-values 	Yes 	No
Non-modifiable l-values 	Yes 	No
R-values 	Yes 	No

L-value references to const objects are particularly useful because they allow us to pass any type of argument (l-value or r-value) into a function without making a copy of the argument.

R-value references

C++11 adds a new type of reference called an r-value reference. An r-value reference is a reference that is designed to be initialized with an r-value (only). While an l-value reference is created using a single ampersand, an r-value reference is created using a double ampersand:

1
2
3

int x{ 5 };
int &lref{ x }; // l-value reference initialized with l-value x
int &&rref{ 5 }; // r-value reference initialized with r-value 5

R-values references cannot be initialized with l-values.
R-value reference 	Can be initialized with 	Can modify
Modifiable l-values 	No 	No
Non-modifiable l-values 	No 	No
R-values 	Yes 	Yes
R-value reference to const 	Can be initialized with 	Can modify
Modifiable l-values 	No 	No
Non-modifiable l-values 	No 	No
R-values 	Yes 	No

R-value references have two properties that are useful. First, r-value references extend the lifespan of the object they are initialized with to the lifespan of the r-value reference (l-value references to const objects can do this too). Second, non-const r-value references allow you to modify the r-value!

Let’s take a look at some examples:

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
23
24
25
26
27
28
29
30

#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

int main()
{
	auto &&rref{ Fraction{ 3, 5 } }; // r-value reference to temporary Fraction

    // f1 of operator<< binds to the temporary, no copies are created.
    std::cout << rref << '\n';

	return 0;
} // rref (and the temporary Fraction) goes out of scope here

This program prints:

3/5

As an anonymous object, Fraction(3, 5) would normally go out of scope at the end of the expression in which it is defined. However, since we’re initializing an r-value reference with it, its duration is extended until the end of the block. We can then use that r-value reference to print the Fraction’s value.

Now let’s take a look at a less intuitive example:

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

#include <iostream>

int main()
{
    int &&rref{ 5 }; // because we're initializing an r-value reference with a literal, a temporary with value 5 is created here
    rref = 10;
    std::cout << rref << '\n';

    return 0;
}

This program prints:

10

While it may seem weird to initialize an r-value reference with a literal value and then be able to change that value, when initializing an r-value with a literal, a temporary is constructed from the literal so that the reference is referencing a temporary object, not a literal value.

R-value references are not very often used in either of the manners illustrated above.

R-value references as function parameters

R-value references are more often used as function parameters. This is most useful for function overloads when you want to have different behavior for l-value and r-value arguments.

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

void fun(const int &lref) // l-value arguments will select this function
{
	std::cout << "l-value reference to const\n";
}

void fun(int &&rref) // r-value arguments will select this function
{
	std::cout << "r-value reference\n";
}

int main()
{
	int x{ 5 };
	fun(x); // l-value argument calls l-value version of function
	fun(5); // r-value argument calls r-value version of function

	return 0;
}

This prints:

l-value reference to const
r-value reference

As you can see, when passed an l-value, the overloaded function resolved to the version with the l-value reference. When passed an r-value, the overloaded function resolved to the version with the r-value reference (this is considered a better match than a l-value reference to const).

Why would you ever want to do this? We’ll discuss this in more detail in the next lesson. Needless to say, it’s an important part of move semantics.

One interesting note:

1
2

	int &&ref{ 5 };
	fun(ref);

actually calls the l-value version of the function! Although variable ref has type r-value reference to an integer, it is actually an l-value itself (as are all named variables). The confusion stems from the use of the term r-value in two different contexts. Think of it this way: Named-objects are l-values. Anonymous objects are r-values. The type of the named object or anonymous object is independent from whether it’s an l-value or r-value. Or, put another way, if r-value reference had been called anything else, this confusion wouldn’t exist.

Returning an r-value reference

You should almost never return an r-value reference, for the same reason you should almost never return an l-value reference. In most cases, you’ll end up returning a hanging reference when the referenced object goes out of scope at the end of the function.

### Operator Overloading
For each fundamental type, some portion of the operators will be available.

Classes, essentially, define new types to be used in C++ code. Types in C++ not only interact with code by means of constructions and assignments, they also interact by means of operators.

For user-defined types, you can specify custom behavior for these operators by employing operator overloading. You can redefine or overload most of the built-in operators available in C++. Thus, a programmer can use operators with user-defined types as well.

Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for the operator being defined. Like any other function, an overloaded operator has a return type and a parameter list.

An operator declaration looks quite like a function declaration:

  return_type operator operator_symbol (...parameter list...);

where operator_symbol in this case could be any of the several operator types that the programmer can define.






In C++, operators are implemented as functions. By using function overloading on the operator functions, you can define your own versions of the operators that work with different data types (including classes that you’ve written).

Using function overloading to overload operators is called operator overloading.


Operators as functions

Consider:

  int x = 2;
  int y = 3;
  std::cout << x + y << '\n';

The compiler comes with a built-in version of the plus operator (+) for integer operands -- this function adds integers x and y together and returns an integer result. When you see the expression x + y, you can translate this in your head to the function call operator+(x, y) (where operator+ is the name of the function).

Consider:

  double z = 2.0;
  double w = 3.0;
  std::cout << w + z << '\n';

The compiler also comes with a built-in version of the plus operator (+) for double operands. Expression w + z becomes function call operator+(w, z), and function overloading is used to determine that the compiler should be calling the double version of this function instead of the integer version.

Now consider what happens if we try to add two object of a user-defined class:

  Mystring string1 = "Hello, ";
  Mystring string2 = "World!";
  std::cout << string1 + string2 << '\n';

What would you expect to happen in this case? The intuitive expected result is that the string “Hello, World!” would be printed on the screen. However, because Mystring is a user-defined class, the compiler does not have a built-in version of the plus operator that it can use for Mystring operands. So in this case, it will give us an error. In order to make it work like we want, we’d need to write an overloaded function to tell the compiler how the + operator should work with two operands of type Mystring. We’ll look at how to do this in the next lesson.

Resolving overloaded operators

When evaluating an expression containing an operator, the compiler uses the following rules:

    If all of the operands are fundamental data types, the compiler will call a built-in routine if one exists. If one does not exist, the compiler will produce a compiler error.
    If any of the operands are user data types (e.g. one of your classes, or an enum type), the compiler looks to see whether the type has a matching overloaded operator function that it can call. If it can’t find one, it will try to convert one or more of the user-defined type operands into fundamental data types so it can use a matching built-in operator (via an overloaded typecast, which we’ll cover later in this chapter). If that fails, then it will produce a compile error.

What are the limitations on operator overloading?

First, almost any existing operator in C++ can be overloaded. The exceptions are: conditional (?:), sizeof, scope (::), member selector (.), member pointer selector (.*), typeid, and the casting operators.

Second, you can only overload the operators that exist. You can not create new operators or rename existing operators. For example, you could not create an operator ** to do exponents.

Third, at least one of the operands in an overloaded operator must be a user-defined type. This means you can not overload the plus operator to work with one integer and one double. However, you could overload the plus operator to work with an integer and a Mystring.

Fourth, it is not possible to change the number of operands an operator supports.

Finally, all operators keep their default precedence and associativity (regardless of what they’re used for) and this can not be changed.

Some new programmers attempt to overload the bitwise XOR operator (^) to do exponentiation. However, in C++, operator^ has a lower precedence level than the basic arithmetic operators, which causes expressions to evaluate incorrectly.

In basic mathematics, exponentiation is resolved before basic arithmetic, so 4 + 3 ^ 2 resolves as 4 + (3 ^ 2) => 4 + 9 => 13.
However, in C++, the arithmetic operators have higher precedence than operator^, so 4 + 3 ^ 2 resolves as (4 + 3) ^ 2 => 7 ^ 2 => 49.

You’d need to explicitly parenthesize the exponent portion (e.g. 4 + (3 ^ 2)) every time you used it for this to work properly, which isn’t intuitive, and is potentially error-prone.

Because of this precedence issue, it’s generally a good idea to use operators only in an analogous way to their original intent.

Rule: When overloading operators, it’s best to keep the function of the operators as close to the original intent of the operators as possible.

Furthermore, because operators don’t have descriptive names, it’s not always clear what they are intended to do. For example, operator+ might be a reasonable choice for a string class to do concatenation of strings. But what about operator-? What would you expect that to do? It’s unclear.

Rule: If the meaning of an operator when applied to a custom class is not clear and intuitive, use a named function instead.

Within those confines, you will still find plenty of useful functionality to overload for your custom classes! You can overload the + operator to concatenate your user-defined string class, or add two Fraction class objects together. You can overload the << operator to make it easy to print your class to the screen (or a file). You can overload the equality operator (==) to compare two class objects. This makes operator overloading one of the most useful features in C++ -- simply because it allows you to work with your classes in a more intuitive way.



















When overloading an operator, keep the following in mind:
  You cannot change the precedence or associativity of an operator.
  You cannot specify default parameters with an overloaded operator.
  You cannot change the number of parameters an operator takes.
  You cannot create new operators.
  The meaning of how an operator works with built-in types, such as int, remains the same. That is, you cannot redefine how operators work with built-in data types.
  Operators can be overloaded either for objects of the user-defined types, or for a combination of objects of the user-defined type and objects of the built-in type.


Overloadable/Non-overloadable Operators

Following is the list of operators which can be overloaded −
\+ 	- 	* 	/ 	% 	^
& 	| 	~ 	! 	, 	=
< 	> 	<= 	>= 	++ 	--
<< 	>> 	== 	!= 	&& 	||
+= 	-= 	/= 	%= 	^= 	&=
|= 	*= 	<<= 	>>= 	[] 	()
-> 	->* 	new 	new [] 	delete 	delete []

Following is the list of operators, which can not be overloaded −
:: 	.* 	. 	?:

On a broad level, operators in C++ can be classified into two types:
  unary
  binary

Unary Operators
operators that function on a single operand are called unary operators. A unary operator that is implemented in the global namespace or as a static member function of a class uses the following structure:

  return_type operator operator_type (parameter_type)
  {
    //implementation
  }

A unary operator that is a (non-static) member of a class has a similar structure but is lacking in parameters, because the single parameter that it works upon is the instance of the class itself (*this):

  return_type operator operator_type ()
  {
  // ... implementation
  }














Some of the most commonly used operators in C++ are the arithmetic operators -- that is, the plus operator (+), minus operator (-), multiplication operator (*), and division operator (/).

Note that all of the arithmetic operators are binary operators -- meaning they take two operands -- one operand on each side of the operator. All four of these operators are overloaded in the exact same way.

It turns out that there are three different ways to overload operators:
member functions
friend functions
free functions (non-member)


When you implement an operator as friend and free functions, you need one parameter per operand. Thus, binary operators require a two-parameter function, and unary operators require a one-parameter function.

Member functions are different, because the object itself is an operand (always the left-hand operand), and the object is implicitly available to all member functions; therefore, you need one fewer parameter.

Binary operators require a single parameter, and unary operators require no parameters.

We will cover each case and summarize when to use each in more detail.


### Overloading operators using friend functions

Consider the following trivial class:

```cpp
class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
};
```

The following example shows how to overload operator plus (+) in order to add two “Cents” objects together:

```cpp
#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	// add Cents + Cents using a friend function
	friend Cents operator+(const Cents &c1, const Cents &c2);

	int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cents + c2.m_cents);
}

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}
```

Output:

```
I have 14 cents.
```

Overloading the plus operator (+) is as simple as declaring a function named operator+, giving it two parameters of the type of the operands we want to add, picking an appropriate return type, and then writing the function.

In the case of our Cents object, implementing our operator+() function is very simple. First, the parameter types: in this version of operator+, we are going to add two Cents objects together, so our function will take two objects of type Cents. Second, the return type: our operator+ is going to return a result of type Cents, so that’s our return type.

Finally, implementation: to add two Cents objects together, we really need to add the m_cents member from each Cents object.

Because our overloaded operator+() function is a friend of the class, we can access the m_cents member of our parameters directly. Also, because m_cents is an integer, and C++ knows how to add integers together using the built-in version of the plus operator that works with integer operands, we can simply use the + operator to do the adding.

Overloading the subtraction operator (-) is simple as well:

```cpp
#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	// add Cents + Cents using a friend function
	friend Cents operator+(const Cents &c1, const Cents &c2);

	// subtract Cents - Cents using a friend function
	friend Cents operator-(const Cents &c1, const Cents &c2);

	int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cents + c2.m_cents);
}

// note: this function is not a member function!
Cents operator-(const Cents &c1, const Cents &c2)
{
	// use the Cents constructor and operator-(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cents - c2.m_cents);
}

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 2 };
	Cents centsSum{ cents1 - cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}
```

Overloading the multiplication and division operators is as easy as defining functions for operator* and operator/ respectively.

Friend functions can be defined inside the class

Even though friend functions are not members of the class, they can still be defined inside the class if desired:

```cpp
#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	// add Cents + Cents using a friend function
        // This function is not considered a member of the class, even though the definition is inside the class
	friend Cents operator+(const Cents &c1, const Cents &c2)
	{
		// use the Cents constructor and operator+(int, int)
		// we can access m_cents directly because this is a friend function
		return Cents(c1.m_cents + c2.m_cents);
	}

	int getCents() const { return m_cents; }
};

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}
```

We generally don’t recommend this, as non-trivial function definitions are better kept in a separate .cpp file, outside of the class definition. However, we will use this pattern in future tutorials to keep the examples concise.



### Overloading operators for operands of different types

Often it is the case that you want your overloaded operators to work with operands that are different types. For example, if we have Cents(4), we may want to add the integer 6 to this to produce the result Cents(10).

When C++ evaluates the expression x + y, x becomes the first parameter, and y becomes the second parameter. When x and y have the same type, it does not matter if you add x + y or y + x -- either way, the same version of operator+ gets called. However, when the operands have different types, x + y does not call the same function as y + x.

For example, Cents(4) + 6 would call operator+(Cents, int), and 6 + Cents(4) would call operator+(int, Cents). Consequently, whenever we overload binary operators for operands of different types, we actually need to write two functions -- one for each case. Here is an example of that:
```cpp
#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	// add Cents + int using a friend function
	friend Cents operator+(const Cents &c1, int value);

	// add int + Cents using a friend function
	friend Cents operator+(int value, const Cents &c1);


	int getCents() const { return m_cents; }
};

Cents operator+(const Cents &c1, int value)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return { c1.m_cents + value };
}

Cents operator+(int value, const Cents &c1)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return { c1.m_cents + value };
}

int main()
{
	Cents c1{ Cents{ 4 } + 6 };
	Cents c2{ 6 + Cents{ 4 } };

	std::cout << "I have " << c1.getCents() << " cents.\n";
	std::cout << "I have " << c2.getCents() << " cents.\n";

	return 0;
}
```

Note that both overloaded functions have the same implementation -- that’s because they do the same thing, they just take their parameters in a different order.

Another example

Let’s take a look at another example:

```cpp
#include <iostream>

class MinMax
{
private:
	int m_min; // The min value seen so far
	int m_max; // The max value seen so far

public:
	MinMax(int min, int max)
	{
		m_min = min;
		m_max = max;
	}

	int getMin() const { return m_min; }
	int getMax() const { return m_max; }

	friend MinMax operator+(const MinMax &m1, const MinMax &m2);
	friend MinMax operator+(const MinMax &m, int value);
	friend MinMax operator+(int value, const MinMax &m);
};

MinMax operator+(const MinMax &m1, const MinMax &m2)
{
	// Get the minimum value seen in m1 and m2
	int min{ m1.m_min < m2.m_min ? m1.m_min : m2.m_min };

	// Get the maximum value seen in m1 and m2
	int max{ m1.m_max > m2.m_max ? m1.m_max : m2.m_max };

	return { min, max };
}

MinMax operator+(const MinMax &m, int value)
{
	// Get the minimum value seen in m and value
	int min{ m.m_min < value ? m.m_min : value };

	// Get the maximum value seen in m and value
	int max{ m.m_max > value ? m.m_max : value };

	return { min, max };
}

MinMax operator+(int value, const MinMax &m)
{
	// call operator+(MinMax, int)
	return { m + value };
}

int main()
{
	MinMax m1{ 10, 15 };
	MinMax m2{ 8, 11 };
	MinMax m3{ 3, 12 };

	MinMax mFinal{ m1 + m2 + 5 + 8 + m3 + 16 };

	std::cout << "Result: (" << mFinal.getMin() << ", " <<
		mFinal.getMax() << ")\n";

	return 0;
}
```
Output:
```
Result: (3, 16)
```

The MinMax class keeps track of the minimum and maximum values that it has seen so far. We have overloaded the + operator 3 times, so that we can add two MinMax objects together, or add integers to MinMax objects.





Let’s talk a little bit more about how:

MinMax mFinal = m1 + m2 + 5 + 8 + m3 + 16

is evaluated.

Remember that operator+ has higher precedence than operator=, and operator+ evaluates from left to right.

In the above expression, m1 + m2 evaluate first.
This becomes a call to operator+(m1, m2), which produces the return value MinMax(8, 15).

Then MinMax(8, 15) + 5 evaluates next.
This becomes a call to operator+(MinMax(8, 15), 5), which produces return value MinMax(5, 15).

Then MinMax(5, 15) + 8 evaluates in the same way to produce MinMax(5, 15).
Then MinMax(5, 15) + m3 evaluates to produce MinMax(3, 15).

And finally, MinMax(3, 15) + 16 evaluates to MinMax(3, 16). This final result is then assigned to mFinal.

In other words, this expression evaluates as

  MinMax mFinal = (((((m1 + m2) + 5) + 8) + m3) + 16)

with each successive operation returning a MinMax object that becomes the left-hand operand for the following operator.



### Implementing operators using other operators

In the above example, note that we defined operator+(int, MinMax) by calling operator+(MinMax, int) (which produces the same result). This allows us to reduce the implementation of operator+(int, MinMax) to a single line, making our code easier to maintain by minimizing redundancy and making the function simpler to understand.

It is often possible to define overloaded operators by calling other overloaded operators. You should do so if and when doing so produces simpler code. In cases where the implementation is trivial (e.g. a single line) it’s often not worth doing this, as the added indirection of an additional function call is more complicated than just implementing the function directly.






### Free Function Operator Overloading


In the code above, we overloaded operator+ as a friend function.

Using a friend function to overload an operator is convenient because it gives you direct access to the internal members of the classes you’re operating on. In the initial Cents example above, our friend function version of operator+ accessed member variable m_cents directly.

However, if you don’t need that access, you can write your overloaded operators as free functions, functions that are non-member or friend functions.

Note that the Cents class above contains an access function (getCents()) that allows us to get at m_cents without having to have direct access to private members. Because of this, we can write our overloaded operator+ as a non-friend:
```cpp
#include <iostream>

class Cents
{
private:
  int m_cents{};

public:
  Cents(int cents)
    : m_cents{ cents }
  {}

  int getCents() const { return m_cents; }
};

// note: this function is not a member function nor a friend function!
Cents operator+(const Cents &c1, const Cents &c2)
{
  // use the Cents constructor and operator+(int, int)
  // we don't need direct access to private members here
  return Cents{ c1.getCents() + c2.getCents() };
}

int main()
{
  Cents cents1{ 6 };
  Cents cents2{ 8 };
  Cents centsSum{ cents1 + cents2 };
  std::cout << "I have " << centsSum.getCents() << " cents.\n";

  return 0;
}
```

Because the normal and friend functions work almost identically (they just have different levels of access to private members), we generally won’t differentiate them. The one difference is that the friend function declaration inside the class serves as a prototype as well. With the normal function version, you’ll have to provide your own function prototype.

Cents.h:
```cpp
class Cents
{
private:
  int m_cents{};

public:
  Cents(int cents)
    : m_cents{ cents }
  {}

  int getCents() const { return m_cents; }
};

// Need to explicitly provide prototype for operator+ so uses of operator+ in other files know this overload exists
Cents operator+(const Cents &c1, const Cents &c2);
```

Cents.cpp:
```cpp
#include "Cents.h"

// note: this function is not a member function nor a friend function!
Cents operator+(const Cents &c1, const Cents &c2)
{
  // use the Cents constructor and operator+(int, int)
  // we don't need direct access to private members here
  return { c1.getCents() + c2.getCents() };
}
```

main.cpp:

```cpp
#include "Cents.h"
#include <iostream>

int main()
{
  Cents cents1{ 6 };
  Cents cents2{ 8 };
  Cents centsSum{ cents1 + cents2 }; // without the prototype in Cents.h, this would fail to compile
  std::cout << "I have " << centsSum.getCents() << " cents.\n";

  return 0;
}
```
In general, a free function should be preferred over a friend function if it’s possible to do so with the existing member functions available (the less functions touching your classes’s internals, the better). However, don’t add additional access functions just to overload an operator as a normal function instead of a friend function!

Rule

Prefer overloading operators as normal functions instead of friends if it’s possible to do so without adding additional functions.










### Member Function Operator Overloading

Above, we performed operator overloading of the arithmetic operators using friend and free functions.

Many operators can be overloaded in a different way: as a member function.

Overloading operators using a member function is very similar to overloading operators using a friend function. When overloading an operator using a member function:

  The overloaded operator must be added as a member function of the left operand.
  The left operand becomes the implicit *this object
  All other operands become function parameters.

As a reminder, here’s how we overloaded operator+ using a friend function:

```cpp
#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) { m_cents = cents; }

    // Overload Cents + int
    friend Cents operator+(const Cents &cents, int value);

    int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents &cents, int value)
{
    return Cents(cents.m_cents + value);
}

int main()
{
	Cents cents1(6);
	Cents cents2 = cents1 + 2;
	std::cout << "I have " << cents2.getCents() << " cents.\n";

	return 0;
}
```

Converting a friend overloaded operator to a member overloaded operator is easy:

  The overloaded operator is defined as a member instead of a friend (Cents::operator+ instead of friend operator+)
  The left parameter is removed, because that parameter now becomes the implicit *this object.
  Inside the function body, all references to the left parameter can be removed (e.g. cents.m_cents becomes m_cents, which implicitly references the *this object).

Now, the same operator overloaded using the member function method:

```cpp
#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) { m_cents = cents; }

    // Overload Cents + int
    Cents operator+(int value);

    int getCents() const { return m_cents; }
};

// note: this function is a member function!
// the cents parameter in the friend version is now the implicit *this parameter
Cents Cents::operator+(int value)
{
    return Cents(m_cents + value);
}

int main()
{
	Cents cents1(6);
	Cents cents2 = cents1 + 2;
	std::cout << "I have " << cents2.getCents() << " cents.\n";

	return 0;
}
```

Note that the usage of the operator does not change (in both cases, cents1 + 2), we’ve simply defined the function differently. Our two-parameter friend function becomes a one-parameter member function, with the leftmost parameter in the friend version (cents) becoming the implicit *this parameter in the member function version.

Let’s take a closer look at how the expression cents1 + 2 evaluates.

In the friend function version, the expression cents1 + 2 becomes function call operator+(cents1, 2). Note that there are two function parameters. This is straightforward.

In the member function version, the expression cents1 + 2 becomes function call cents1.operator+(2). Note that there is now only one explicit function parameter, and cents1 has become an object prefix.

The compiler implicitly converts an object prefix into a hidden leftmost parameter named *this. So in actuality, cents1.operator+(2) becomes operator+(&cents1, 2), which is almost identical to the friend version.

Both cases produce the same result, just in slightly different ways.

So if we can overload an operator as a friend or a member, which should we use? In order to answer that question, there’s a few more things you’ll need to know.



Not everything can be overloaded as a friend function:
  assignment (=)
  subscript ([])
  function call (())
  member selection (->)

The above operators must be overloaded as member functions, because the language requires them to be.

An example of this is overloading the I/O operators, we overloaded operator<< for our Point class using the friend function method. Here’s a reminder of how we did that:

```cpp
#include <iostream>

class Point
{
private:
    double m_x, m_y, m_z;

public:
    Point(double x=0.0, double y=0.0, double z=0.0): m_x(x), m_y(y), m_z(z)
    {}

    friend std::ostream& operator<< (std::ostream &out, const Point &point);
};

std::ostream& operator<< (std::ostream &out, const Point &point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

    return out;
}

```
```

However, we are not able to overload operator<< as a member function. Why not?

Because the overloaded operator must be added as a member of the left operand.

In this case, the left operand is an object of type std::ostream. std::ostream is fixed as part of the standard library. We can’t modify the class declaration to add the overload as a member function of std::ostream.

This necessitates that operator<< be overloaded as a normal function (preferred) or a friend.

Similarly, although we can overload operator+(Cents, int) as a member function (as we did above), we can’t overload operator+(int, Cents) as a member function, because int isn’t a class we can add members to.

Typically, we won’t be able to use a member overload if the left operand is either not a class (e.g. int), or it is a class that we can’t modify (e.g. std::ostream).

#### Summary
When to use a normal, friend, or member function overload

In most cases, the language leaves it up to you to determine whether you want to use the normal/friend or member function version of the overload. However, one of the two is usually a better choice than the other.

When dealing with binary operators that don’t modify the left operand (e.g. operator+), the normal or friend function version is typically preferred, because it works for all parameter types (even when the left operand isn’t a class object, or is a class that is not modifiable). The normal or friend function version has the added benefit of “symmetry”, as all operands become explicit parameters (instead of the left operand becoming *this and the right operand becoming an explicit parameter).

When dealing with binary operators that do modify the left operand (e.g. operator+=), the member function version is typically preferred. In these cases, the leftmost operand will always be a class type, and having the object being modified become the one pointed to by *this is natural. Because the rightmost operand becomes an explicit parameter, there’s no confusion over who is getting modified and who is getting evaluated.

Unary operators are usually overloaded as member functions as well, since the member version has no parameters.

The following rules of thumb can help you determine which form is best for a given situation:

  If you’re overloading assignment (=), subscript ([]), function call (()), or member selection (->), do so as a member function.
  If you’re overloading a unary operator, do so as a member function.
  If you’re overloading a binary operator that does not modify its left operand (e.g. operator+), do so as a normal function (preferred) or friend function.
  If you’re overloading a binary operator that modifies its left operand, but you can’t modify the definition of the left operand (e.g. operator<<, which has a left operand of type ostream), do so as a normal function (preferred) or friend function.
  If you’re overloading a binary operator that modifies its left operand (e.g. operator+=), and you can modify the definition of the left operand, do so as a member function.






Operator Overloading Examples

Here are various operator overloading examples to help you in understanding the concept.

Unary Operators Overloading
https://www.tutorialspoint.com/cplusplus/unary_operators_overloading.htm

Binary Operators Overloading
https://www.tutorialspoint.com/cplusplus/binary_operators_overloading.htm

Relational Operators Overloading
https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm

Input/Output Operators Overloading
https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm

++ and -- Operators Overloading
https://www.tutorialspoint.com/cplusplus/increment_decrement_operators_overloading.htm

Assignment/Copy Operators Overloading
https://www.tutorialspoint.com/cplusplus/assignment_operators_overloading.htm

Function call () Operator Overloading
https://www.tutorialspoint.com/cplusplus/function_call_operator_overloading.htm

Subscripting [] Operator Overloading
https://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm

Class Member Access Operator -> Overloading
https://www.tutorialspoint.com/cplusplus/class_member_access_operator_overloading.htm

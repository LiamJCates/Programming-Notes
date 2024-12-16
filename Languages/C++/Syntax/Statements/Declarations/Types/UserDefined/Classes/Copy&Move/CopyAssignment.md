## Copy Assignment
A copy constructor takes an object of the same class by reference as a parameter. This parameter is an alias of the source object and is the handle you have in writing your custom copy code.

The copy constructor has ensured deep copy in cases such as function calls:
ClassName sayHello("Hello from String Class");
UseMyString(sayHello);

However, what if you tried copying via assignment:
ClassName overwrite("who cares? ");
overwrite = sayHello;

This would still be a shallow copy if you have yet to supply a copy assignment operator=. In the absence of one, the compiler has supplied a default for you that does a shallow copy.


## Implementing Copy Assignment

Syntax:
ClassName::operator= (const ClassName& copySource)
{
//... copy assignment operator code
}



Creates a copy of an object and assigns it to another existing object

void dont_do_this() {
  SimpleString a{ 50 };
  a.append_line("We apologize for the");
  SimpleString b{ 50 };
  b.append_line("Last message");
  b = a;
}

Listing 4-28: Using the default copy assignment operator to create a copy of an object and assign it to another existing object

NOTE
The code in Listing 4-28 causes undefined behavior because it doesn’t have a userdefined copy assignment operator.

The last line at copy assigns a to b.
The major difference between copy assignment and copy construction is that in copy assignment, b might already have a value. You must clean up b’s resources before copying a.

WARNING
The default copy assignment operator for simple types just copies the members from the source object to the destination object. In this case of a full featured object, this is very dangerous for two reasons.
First, the original object gets rewritten without freeing the dynamically allocated char array.

Second, now two objects own the same buffer, which can cause dangling pointers and double frees. You must implement a copy assignment operator that performs a clean hand-off.

The copy assignment operator uses the operator= syntax, as demonstrated:

struct SimpleString {
--snip--
SimpleString& operator=(const SimpleString& other) {
if (this == &other) return *this; u
--snip--
return *this; v
}
}
A user-defined copy assignment operator


The copy assignment operator returns a reference to the result, which
is always *this. It’s also generally good practice to check whether other
refers to this.
You can implement copy assignment for SimpleString by following these
guidelines: free the current buffer of this and then copy other as you did in
copy construction, as shown in Listing 4-30.

SimpleString& operator=(const SimpleString& other) {
  if (this == &other) return *this;
const auto new_buffer = new char[other.max_size];
delete[] buffer;
buffer = new_buffer;
length = other.length;
max_size = other.max_size;
strcpy_s(buffer, max_size, other.buffer);
return *this;
}
Listing 4-30: A copy assignment operator for SimpleString

The copy assignment operator starts by allocating a new_buffer with the
appropriate size. Next, you clean up buffer. You copy buffer, length,
and max_size and then copy the contents from other.buffer into your own
buffer.








Copy initialization
By Alex on June 5th, 2016 | last modified by Alex on December 21st, 2020

Consider the following line of code:

1

int x = 5;

This statement uses copy initialization to initialize newly created integer variable x to the value of 5.

However, classes are a little more complicated, since they use constructors for initialization. This lesson will examine topics related to copy initialization for classes.

Copy initialization for classes

Given our Fraction class:

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

#include <cassert>
#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction &f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}

Consider the following:

1
2
3
4
5
6

int main()
{
    Fraction six = Fraction(6);
    std::cout << six;
    return 0;
}

If you were to compile and run this, you’d see that it produces the expected output:

6/1

This form of copy initialization is evaluated the same way as the following:

1

	Fraction six(Fraction(6));

And as you learned in the previous lesson, this can potentially make calls to both Fraction(int, int) and the Fraction copy constructor (which may be elided for performance reasons). However, because eliding isn’t guaranteed (prior to C++17, where elision in this particular case is now mandatory), it’s better to avoid copy initialization for classes, and use uniform initialization instead.

Rule: Avoid using copy initialization, and use uniform initialization instead.

Other places copy initialization is used

There are a few other places copy initialization is used, but two of them are worth mentioning explicitly. When you pass or return a class by value, that process uses copy initialization.

Consider:

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
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49

#include <cassert>
#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }

        // Copy constructor
	Fraction(const Fraction &copy) :
		m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
	{
		// no need to check for a denominator of 0 here since copy must already be a valid Fraction
		std::cout << "Copy constructor called\n"; // just to prove it works
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
        int getNumerator() { return m_numerator; }
        void setNumerator(int numerator) { m_numerator = numerator; }
};

std::ostream& operator<<(std::ostream& out, const Fraction &f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}

Fraction makeNegative(Fraction f) // ideally we should do this by const reference
{
    f.setNumerator(-f.getNumerator());
    return f;
}

int main()
{
    Fraction fiveThirds(5, 3);
    std::cout << makeNegative(fiveThirds);

    return 0;
}

In the above program, function makeNegative takes a Fraction by value and also returns a Fraction by value. When we run this program, we get:

Copy constructor called
Copy constructor called
-5/3

The first copy constructor call happens when fiveThirds passed as an argument into makeNegative() parameter f. The second call happens when the return value from makeNegative() is passed back to main().

In the above case, both the argument passed by value and the return value can not be elided. However, in other cases, if the argument or return value meet specific criteria, the compiler may opt to elide the copy constructor. For example:

class Something
{
};

Something foo()
{
  Something s;
  return s;
}

int main()
{
  Something s = foo();
}

In this case, the compiler will probably elide the copy constructor, even though variable s is returned by value.

Overloading typecasts
By Alex on October 30th, 2007 | last modified by Alex on December 21st, 2020

In the lesson 4.4 -- Type conversion and casting, you learned that C++ allows you to convert one data type to another. The following example shows an int being converted into a double:

1
2

int n{ 5 };
auto d{ static_cast<double>(n) }; // int cast to a double

C++ already knows how to convert between the built-in data types. However, it does not know how to convert any of our user-defined classes. That’s where overloading the typecast operators comes into play.

User-defined conversions allow us to convert our class into another data type. Take a look at the following class:

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

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0)
        : m_cents{ cents }
    {
    }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

This class is pretty simple: it holds some number of cents as an integer, and provides access functions to get and set the number of cents. It also provides a constructor for converting an int into a Cents.

If we can convert an int into a Cents, then doesn’t it also make sense for us to be able to convert a Cents back into an int? In some cases, this might not be true, but in this case, it does make sense.

In the following example, we have to use getCents() to convert our Cents variable back into an integer so we can print it using printInt():

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

void printInt(int value)
{
    std::cout << value;
}

int main()
{
    Cents cents{ 7 };
    printInt(cents.getCents()); // print 7

    std::cout << '\n';

    return 0;
}

If we have already written a lot of functions that take integers as parameters, our code will be littered with calls to getCents(), which makes it more messy than it needs to be.

To make things easier, we can provide a user-defined conversion by overloading the int typecast. This will allow us to cast our Cents class directly into an int. The following example shows how this is done:

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

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0)
        : m_cents{ cents }
    {
    }

    // Overloaded int cast
    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

There are three things to note:

    To overload the function that casts our class to an int, we write a new function in our class called operator int(). Note that there is a space between the word operator and the type we are casting to.
    User-defined conversions do not take parameters, as there is no way to pass arguments to them.
    User-defined conversions do not have a return type. C++ assumes you will be returning the correct type.

Now in our example, we can call printInt() like this:

1
2
3
4
5
6
7
8
9

int main()
{
    Cents cents{ 7 };
    printInt(cents); // print 7

    std::cout << '\n';

    return 0;
}

The compiler will first note that function printInt takes an integer parameter. Then it will note that variable cents is not an int. Finally, it will look to see if we’ve provided a way to convert a Cents into an int. Since we have, it will call our operator int() function, which returns an int, and the returned int will be passed to printInt().

We can now also explicitly cast our Cents variable to an int:

1
2

Cents cents{ 7 };
int c{ static_cast<int>(cents) };

You can provide user-defined conversions for any data type you wish, including your own user-defined data types!

Here’s a new class called Dollars that provides an overloaded Cents conversion:

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

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars=0)
        : m_dollars{ dollars }
    {
    }

     // Allow us to convert Dollars into Cents
     operator Cents() const { return Cents{ m_dollars * 100 }; }
};

This allows us to convert a Dollars object directly into a Cents object! This allows you to do something like this:

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

#include <iostream>

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0)
        : m_cents{ cents }
    {
    }

    // Overloaded int cast
    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars=0)
        : m_dollars{ dollars }
    {
    }

    // Allow us to convert Dollars into Cents
    operator Cents() const { return Cents(m_dollars * 100); }
};

void printCents(Cents cents)
{
    std::cout << cents; // cents will be implicitly cast to an int here
}

int main()
{
    Dollars dollars{ 9 };
    printCents(dollars); // dollars will be implicitly cast to a Cents here

    std::cout << '\n';

    return 0;
}

Consequently, this program will print the value:

900

which makes sense, since 9 dollars is 900 cents!

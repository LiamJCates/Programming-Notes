Unary Operators

| Symbol | Name |
|--------|------|
| ++ | Increment |
| -- | Decrement |
| * | Pointer dereference |
| -> | Member selection |
| ! | Logical NOT |
| & | Address-of |
| ~ | One’s complement |
| + | Unary plus |
| - | Unary negation |



Example
A unary prefix increment operator (++) can be programmed using the following syntax within the class declaration:

  // Unary increment operator (prefix)
  Date& operator ++ ()
  {
    // operator implementation code
    return *this;
  }

The postfix increment operator (++), on the other hand, has a different return type and an input parameter (that is not always used):

  Date operator ++ (int)
  {
    // Store a copy of the current object state before incrementing day
    Date copy (*this);
    // increment implementation code
    // Return state before increment (because, postfix)
    return copy;
  }


The prefix and postfix decrement operators have a similar syntax as the increment operators, just that the declaration would contain a -- where you see a ++.

As the implementation of the postfix operators demonstrates, a copy containing the existing state of the object is created before the increment or decrement operation to be returned thereafter. In other words, if you had the choice between using ++ object; and object ++; to essentially only increment, you should choose the former to avoid the creation of a temporary copy that will not be used.







Overloading unary operators

Because unary operators only operate on the object they are applied to, typically unary operator overloads are implemented as member functions. All three operands are implemented in an identical manner.

Let’s take a look at how we’d implement operator- on the Cents class we used in a previous example:

  #include <iostream>

  class Cents
  {
  private:
      int m_cents;

  public:
      Cents(int cents) { m_cents = cents; }

      // Overload -Cents as a member function
      Cents operator-() const;

      int getCents() const { return m_cents; }
  };

  // note: this function is a member function!
  Cents Cents::operator-() const
  {
      return Cents(-m_cents);
  }

  int main()
  {
      const Cents nickle(5);
      std::cout << "A nickle of debt is worth " << (-nickle).getCents() << " cents\n";

      return 0;
  }

This should be straightforward. Our overloaded negative operator (-) is a unary operator implemented as a member function, so it takes no parameters (it operates on the *this object). It returns a Cents object that is the negation of the original Cents value. Because operator- does not modify the Cents object, we can (and should) make it a const function (so it can be called on const Cents objects).

Note that there’s no confusion between the negative operator- and the minus operator- since they have a different number of parameters.

Here’s another example. The ! operator is the logical negation operator -- if an expression evaluates to “true”, operator! will return false, and vice-versa. We commonly see this applied to boolean variables to test whether they are true or not:

  if (!isHappy)
      std::cout << "I am not happy!\n";
  else
      std::cout << "I am so happy!\n";

For integers, 0 evaluates to false, and anything else to true, so operator! as applied to integers will return true for an integer value of 0 and false otherwise.

Extending the concept, we can say that operator! should evaluate to true if the state of the object is “false”, “zero”, or whatever the default initialization state is.

The following example shows an overload of both operator- and operator! for a user-defined Point class:

  #include <iostream>

  class Point
  {
  private:
      double m_x, m_y, m_z;

  public:
      Point(double x=0.0, double y=0.0, double z=0.0):
          m_x{x}, m_y{y}, m_z{z}
      {
      }

      // Convert a Point into its negative equivalent
      Point operator- () const;

      // Return true if the point is set at the origin
      bool operator! () const;

      double getX() const { return m_x; }
      double getY() const { return m_y; }
      double getZ() const { return m_z; }
  };

  // Convert a Point into its negative equivalent
  Point Point::operator- () const
  {
      return Point(-m_x, -m_y, -m_z);
  }

  // Return true if the point is set at the origin, false otherwise
  bool Point::operator! () const
  {
      return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
  }

  int main()
  {
      Point point{}; // use default constructor to set to (0.0, 0.0, 0.0)

      if (!point)
          std::cout << "point is set at the origin.\n";
      else
          std::cout << "point is not set at the origin.\n";

      return 0;
  }

The overloaded operator! for this class returns the boolean value “true” if the Point is set to the default value at coordinate (0.0, 0.0, 0.0). Thus, the above code produces the result:

point is set at the origin.










Overloading the increment and decrement operators
By Alex on October 15th, 2007 | last modified by Alex on December 21st, 2020

Overloading the increment (++) and decrement (--) operators are pretty straightforward, with one small exception. There are actually two versions of the increment and decrement operators: a prefix increment and decrement (e.g. ++x; --y;) and a postfix increment and decrement (e.g. x++; y--;).

Because the increment and decrement operators are both unary operators and they modify their operands, they’re best overloaded as member functions. We’ll tackle the prefix versions first because they’re the most straightforward.

Overloading prefix increment and decrement

Prefix increment and decrement is overloaded exactly the same as any normal unary operator. We’ll do this one by example:

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
50
51
52
53
54
55
56
57
58
59
60

#include <iostream>

class Digit
{
private:
    int m_digit;
public:
    Digit(int digit=0)
        : m_digit(digit)
    {
    }

    Digit& operator++();
    Digit& operator--();

    friend std::ostream& operator<< (std::ostream &out, const Digit &d);
};

Digit& Digit::operator++()
{
    // If our number is already at 9, wrap around to 0
    if (m_digit == 9)
        m_digit = 0;
    // otherwise just increment to next number
    else
        ++m_digit;

    return *this;
}

Digit& Digit::operator--()
{
    // If our number is already at 0, wrap around to 9
    if (m_digit == 0)
        m_digit = 9;
    // otherwise just decrement to next number
    else
        --m_digit;

    return *this;
}

std::ostream& operator<< (std::ostream &out, const Digit &d)
{
	out << d.m_digit;
	return out;
}

int main()
{
    Digit digit(8);

    std::cout << digit;
    std::cout << ++digit;
    std::cout << ++digit;
    std::cout << --digit;
    std::cout << --digit;

    return 0;
}

Our Digit class holds a number between 0 and 9. We’ve overloaded increment and decrement so they increment/decrement the digit, wrapping around if the digit is incremented/decremented out range.

This example prints:

89098

Note that we return *this. The overloaded increment and decrement operators return the current implicit object so multiple operators can be “chained” together.

Overloading postfix increment and decrement

Normally, functions can be overloaded when they have the same name but a different number and/or different type of parameters. However, consider the case of the prefix and postfix increment and decrement operators. Both have the same name (eg. operator++), are unary, and take one parameter of the same type. So how it is possible to differentiate the two when overloading?

The answer is that C++ uses a “dummy variable” or “dummy argument” for the postfix operators. This argument is a fake integer parameter that only serves to distinguish the postfix version of increment/decrement from the prefix version. Here is the above Digit class with both prefix and postfix overloads:

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
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87

class Digit
{
private:
    int m_digit;
public:
    Digit(int digit=0)
        : m_digit(digit)
    {
    }

    Digit& operator++(); // prefix
    Digit& operator--(); // prefix

    Digit operator++(int); // postfix
    Digit operator--(int); // postfix

    friend std::ostream& operator<< (std::ostream &out, const Digit &d);
};

Digit& Digit::operator++()
{
    // If our number is already at 9, wrap around to 0
    if (m_digit == 9)
        m_digit = 0;
    // otherwise just increment to next number
    else
        ++m_digit;

    return *this;
}

Digit& Digit::operator--()
{
    // If our number is already at 0, wrap around to 9
    if (m_digit == 0)
        m_digit = 9;
    // otherwise just decrement to next number
    else
        --m_digit;

    return *this;
}

Digit Digit::operator++(int)
{
    // Create a temporary variable with our current digit
    Digit temp(m_digit);

    // Use prefix operator to increment this digit
    ++(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

Digit Digit::operator--(int)
{
    // Create a temporary variable with our current digit
    Digit temp(m_digit);

    // Use prefix operator to decrement this digit
    --(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

std::ostream& operator<< (std::ostream &out, const Digit &d)
{
	out << d.m_digit;
	return out;
}

int main()
{
    Digit digit(5);

    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;

    return 0;
}

This prints

5667665

There are a few interesting things going on here. First, note that we’ve distinguished the prefix from the postfix operators by providing an integer dummy parameter on the postfix version. Second, because the dummy parameter is not used in the function implementation, we have not even given it a name. This tells the compiler to treat this variable as a placeholder, which means it won’t warn us that we declared a variable but never used it.

Third, note that the prefix and postfix operators do the same job -- they both increment or decrement the object. The difference between the two is in the value they return. The overloaded prefix operators return the object after it has been incremented or decremented. Consequently, overloading these is fairly straightforward. We simply increment or decrement our member variables, and then return *this.

The postfix operators, on the other hand, need to return the state of the object before it is incremented or decremented. This leads to a bit of a conundrum -- if we increment or decrement the object, we won’t be able to return the state of the object before it was incremented or decremented. On the other hand, if we return the state of the object before we increment or decrement it, the increment or decrement will never be called.

The typical way this problem is solved is to use a temporary variable that holds the value of the object before it is incremented or decremented. Then the object itself can be incremented or decremented. And finally, the temporary variable is returned to the caller. In this way, the caller receives a copy of the object before it was incremented or decremented, but the object itself is incremented or decremented. Note that this means the return value of the overloaded operator must be a non-reference, because we can’t return a reference to a local variable that will be destroyed when the function exits. Also note that this means the postfix operators are typically less efficient than the prefix operators because of the added overhead of instantiating a temporary variable and returning by value instead of reference.

Finally, note that we’ve written the post-increment and post-decrement in such a way that it calls the pre-increment and pre-decrement to do most of the work. This cuts down on duplicate code, and makes our class easier to modify in the future.

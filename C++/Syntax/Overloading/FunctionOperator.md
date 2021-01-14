## The Function-Call Operator
You can make user-defined types callable or invocable by overloading the function-call operator operator(). Such a type is called a function type, and instances of a function type are called function objects. The function-call operator permits any combination of argument types, return types, and modifiers (except static).

The primary reason you might want to make a user-defined type callable is to interoperate with code that expects function objects to use the function-call operator. You’ll find that many libraries, such as the stdlib, use the function-call operator as the interface for function-like objects.

When we create an asynchronous task with the std::async function, which accepts an arbitrary function object that can execute on a separate thread. It uses the function-call operator as the interface. The committee that invented std::async could have required you to expose, say, a run method, but they chose the function-call operator because it allows generic code to use identical notation to invoke a function or a function object.

Listing 9-11 illustrates the function-call operator’s usage.
struct type-name {
  return-type operator()(arg-type1 arg1, arg-type2 arg2, ...) {
    // Body of function-call operator
  }
}

The function-call operator has the special operator() method name. You declare an arbitrary number of arguments, and you also decide the appropriate return type.
When the compiler evaluates a function-call expression, it will invoke the function-call operator on the first operand, passing the remaining operands as arguments. The result of the function-call expression is the result of invoking the corresponding function-call operator.

A Counting Example
Consider the function type CountIf, which computes the frequency of a particular char in a null-terminated string:

#include <cstdio>
#include <cstdint>

struct CountIf {
  CountIf(char x) : x{ x } { }
  size_t operator()(const char* str) const {
    size_t index{}, result{};
    while (str[index]) {
      if (str[index] == x) result++;
      index++;
    }
    return result;
  }
private:
  const char x;
};

int main() {
  CountIf s_counter{ 's' };
  auto sally = s_counter("Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
  auto sailor = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor);
  auto buffalo = CountIf{ 'f' }("Buffalo buffalo Buffalo buffalo "
  "buffalo buffalo Buffalo buffalo.");
  printf("Buffalo: %zd\n", buffalo);
}

Output
Sally: 7
Sailor: 3
Buffalo: 16

Listing 9-12: A function type that counts the number of characters appearing in a nullterminated string

You initialize CountIf objects using a constructor taking a char. You can call the resulting function object as if it were a function taking a nullterminated string argument, because you’ve implemented the function call operator. The function call operator iterates through each character in the argument str using an index variable, incrementing the result variable whenever the character matches the x field. Because calling the function doesn’t modify the state of a CountIf object, you’ve marked it const. Within main, you’ve initialized the CountIf function object s_counter, which will count the frequency of the letter s. You can use s_counter as if it were a function. You can even initialize a CountIf object and use the function operator directly as an rvalue object. You might find this convenient to do in some settings where, for example, you might only need to invoke the object a single time.

You can employ function objects as partial applications:

#include <cstdio>
#include <cstdint>

size_t count_if(char x, const char* str) {
  size_t index{}, result{};
  while (str[index]) {
    if (str[index] == x) result++;
    index++;
  }
  return result;
}
int main() {
  auto sally = count_if('s', "Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
  auto sailor = count_if('s', "Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor);258 Chapter 9
  auto buffalo = count_if('f', "Buffalo buffalo Buffalo buffalo "
  "buffalo buffalo Buffalo buffalo.");
  printf("Buffalo: %zd\n", buffalo);
}

Output:
Sally: 7
Sailor: 3
Buffalo: 16

Listing 9-13: A free function emulating Listing 9-12

The count_if function has an extra argument x u, but otherwise it’s almost identical to the function operator of CountIf.

N O T E
In functional programming parlance, the CountIf is the partial application of x to count_if. When you partially apply an argument to a function, you fix that argument’s value. The product of such a partial application is another function taking one less argument.

Declaring function types is verbose. You can often reduce the boilerplate substantially with lambda expressions.








Overloading the parenthesis operator
By Alex on October 25th, 2007 | last modified by Alex on December 21st, 2020

All of the overloaded operators you have seen so far let you define the type of the operator’s parameters, but not the number of parameters (which is fixed based on the type of the operator). For example, operator== always takes two parameters, whereas operator! always takes one. The parenthesis operator (operator()) is a particularly interesting operator in that it allows you to vary both the type AND number of parameters it takes.

There are two things to keep in mind: first, the parenthesis operator must be implemented as a member function. Second, in non-object-oriented C++, the () operator is used to call functions. In the case of classes, operator() is just a normal operator that calls a function (named operator()) like any other overloaded operator.

An example

Let’s take a look at an example that lends itself to overloading this operator:

1
2
3
4
5

class Matrix
{
private:
    double data[4][4]{};
};

Matrices are a key component of linear algebra, and are often used to do geometric modeling and 3D computer graphics work. In this case, all you need to recognize is that the Matrix class is a 4 by 4 two-dimensional array of doubles.

In the lesson on overloading the subscript operator, you learned that we could overload operator[] to provide direct access to a private one-dimensional array. However, in this case, we want access to a private two-dimensional array. Because operator[] is limited to a single parameter, it is not sufficient to let us index a two-dimensional array.

However, because the () operator can take as many parameters as we want it to have, we can declare a version of operator() that takes two integer index parameters, and use it to access our two-dimensional array. Here is an example of this:

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

#include <cassert> // for assert()

class Matrix
{
private:
    double m_data[4][4]{};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const; // for const objects
};

double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

Now we can declare a Matrix and access its elements like this:

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
    Matrix matrix;
    matrix(1, 2) = 4.5;
    std::cout << matrix(1, 2) << '\n';

    return 0;
}

which produces the result:

4.5

Now, let’s overload the () operator again, this time in a way that takes no parameters at all:

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

#include <cassert> // for assert()
class Matrix
{
private:
    double m_data[4][4]{};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const;
    void operator()();
};

double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

void Matrix::operator()()
{
    // reset all elements of the matrix to 0.0
    for (int row{ 0 }; row < 4; ++row)
    {
        for (int col{ 0 }; col < 4; ++col)
        {
            m_data[row][col] = 0.0;
        }
    }
}

And here’s our new example:

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

#include <iostream>

int main()
{
    Matrix matrix{};
    matrix(1, 2) = 4.5;
    matrix(); // erase matrix
    std::cout << matrix(1, 2) << '\n';

    return 0;
}

which produces the result:

0

Because the () operator is so flexible, it can be tempting to use it for many different purposes. However, this is strongly discouraged, since the () symbol does not really give any indication of what the operator is doing. In our example above, it would be better to have written the erase functionality as a function called clear() or erase(), as matrix.erase() is easier to understand than matrix() (which could do anything!).

Having fun with functors

Operator() is also commonly overloaded to implement functors (or function object), which are classes that operate like functions. The advantage of a functor over a normal function is that functors can store data in member variables (since they are classes).

Here’s a simple functor:

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

class Accumulator
{
private:
    int m_counter{ 0 };

public:
    int operator() (int i) { return (m_counter += i); }
};

int main()
{
    Accumulator acc{};
    std::cout << acc(10) << '\n'; // prints 10
    std::cout << acc(20) << '\n'; // prints 30

    return 0;
}

Note that using our Accumulator looks just like making a normal function call, but our Accumulator object is storing an accumulated value.

You may wonder why we couldn’t do the same thing with a normal function and a static local variable to preserve data between function calls. We could, but because functions only have one global instance, we’d be limited to using it for one thing at a time. With functors, we can instantiate as many separate functor objects as we need and use them all simultaneously.

Conclusion

Operator() is sometimes overloaded with two parameters to index multidimensional arrays, or to retrieve a subset of a one dimensional array (with the two parameters defining the subset to return). Anything else is probably better written as a member function with a more descriptive name.

Operator() is also often overloaded to create functors. Although simple functors (such as the example above) are fairly easily understood, functors are typically used in more advanced programming topics, and deserve their own lesson.

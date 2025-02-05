The first two numbers in the Fibonacci sequence are 0 and 1, and each subsequent number is the sum of the previous two.

The Fibonacci numbers are mathematically defined:

f(n) = f(n-1) + f(n-2) for n > 1
where
	n1 = 1
	n0 = 0


It is trivial to write a recursive solution directly derived from the mathematical formulation. 


iterative algorithm

unsigned long long fibonacci(unsigned int n)
{
    unsigned long long a = 0, b = 1;
    for(; n > 0; --n)
    {
        b += a;
        a = b-a;
    }
    return a;
}



Here we provide an implementation where Fibonacci is computed at compile time leveraging the power of templates.

```cpp
#include <iostream>

template <int N>
struct CTFibonacci
{
  static constexpr int value()
  {
    return CTFibonacci<N - 1>::value() + CTFibonacci<N - 2>::value();
  }
};
template <>
struct CTFibonacci<1>
{
  static constexpr int value() { return 1; }
};
template <>
struct CTFibonacci<0>
{
  static constexpr int value() { return 0; }
};

int main()
{

  CTFibonacci<10> n;
  std::cout << n.value() << std::endl;
}
```

### Recursive Time Complexity

We can analyze the time complexity of F(n) by counting the number of times its most expensive operation will execute for n number of inputs. For this algorithm, the operation contributing the greatest runtime cost is addition.


#### Finding an Equation for Time Complexity

Let’s use T(n) to denote the time complexity of F(n).

The number of additions required to compute F(n-1) and F(n-2) will then be T(n-1) and T(n-2), respectively. We have one more addition to sum our results. Therefore, for n > 1:

T(n) = T(n-1) + T(n-2) + 1

When n = 0 and n = 1, no additions occur. This implies that:

T(0) = T(1) = 0

Now that we have our equation, we need to solve for T(n).

There are several ways we could do this. We’ll implement a fairly straightforward approach, where we slightly simplify T(n) and find its solution using backward substitution. The result will give us an upper bound on the time complexity of T(n).


#### Simplifying T(n)

Let’s start by assuming that T(n-2) ≈ T(n-1). Don’t worry about why just yet – this will become apparent shortly.

Substituting the value of T(n-1) = T(n-2) into our relation T(n), we get:

T(n) = T(n-1) + T(n-1) + 1 = 2*T(n-1) + 1

By doing this, we have reduced T(n) into a much simpler recurrence. As a result, we can now solve for T(n) using backward substitution.


#### Solving T(n) Using Backward Substitution

To do this, we first substitute T(n-1) into the right-hand side of our recurrence. Since T(n-1) = 2*T(n-2) + 1, we get:

	T(n) = 2 * [ 2 * T(n-2) + 1] + 1 = 4 * T(n-2) + 3

Next, we can substitute in T(n-2) = 2 * T(n-3) + 1:

	T(n) = 2 * [2 * [2 * T(n-3) + 1] + 1] + 1 = 8 * T(n-3) + 7

And once more for T(n-3) = 2 * T(n-4) + 1:

	T(n) = 2 * [2 * [2 * [2 * T(n-4) + 1]+ 1] + 1] + 1 = 16*T(n-4) + 15

We can see a pattern starting to emerge here, so let’s attempt to form a general solution for T(n).

It appears to stand that:

	T(n) = 2^k * T(n–k) + (2^k-1)

For any positive integer k.

Finally, we can find k and, thereby, solve T(n), by substituting in T(0) = 1.

For T(0), we can see that n – k = 0. Rearranging, we get k = n. Now, substituting in our values for T(0) and k, we get:

T(n) = 2^n * T(0) + (2^n-1) = 2^n + 2^n – 1 = O(2^n)


#### Analyzing Our Solution

Recall the assumption we made earlier that T(n-2) ≈ T(n-1).
Since T(n-2) ≤ T(n-1) will always hold, our solution O(2^n) is an upper bound for the time complexity of F(n).

It does not, however, give us the tightest upper bound. Our initial assumption removed a bit of precision. The tightest upper bound of F(n) works out to be:

T(n) = O(Φn)

Where Φ = (1+√5) / 2.

Both of these solutions reveal that the run time of our algorithm will grow exponentially in n. This observation is quite intuitive if we consider that each time we call F(n), it will potentially make two more calls to F, thus doubling the cost of F(n). This is some very undesirable behavior!


An alternative and more efficient solution memorizes the intermediate results and it avoids to recompute the same sub-problem for multiple times.
```
unsigned int Fibonacci(unsigned int n)
{
	int a = 0, b = 1, sum = a + b;

	if (n <= 1) return n;

	for (unsigned int i = 2; i < n; ++i)
	{
		a = b;
		b = sum;
		sum = a + b;
	}

	return sum;
}
```

### Iterative Time Complexity

Analyzing the time complexity for our iterative algorithm is a lot more straightforward than its recursive counterpart.

In this case, our most costly operation is assignment. Firstly, our assignments of F[0] and F[1] cost O(1) each. Secondly, our loop performs one assignment per iteration and executes (n-1)-2 times, costing a total of O(n-3) = O(n).

Therefore, our iterative algorithm has a time complexity of O(n) + O(1) + O(1) = O(n).

This is a marked improvement from our recursive algorithm!












To accurately calculate Fibonacci numbers using Binet's formula, you need an accurate interpretation of √5. Since √5 is irrational, it cannot be accurately represented using double or float, hence Binet's formula doesn't work with these types (however, the rounding in the computation leads to exact results for some small inputs). Since the Fibonacci numbers are integers, you can get exact results from Binet's formula using double or float for more arguments by rounding afterwards,

double binet(unsigned int n)
{
    static const double phi = (1 + sqrt(5))*0.5;
    double fib = (pow(phi,n) - pow(1-phi,n))/sqrt(5);
    return round(fib);
}

That will return the correct result for almost all n small enough that the result can be exactly represented as a double. These aren't many, however. A double typically has only 53 bits of precision, so only Fibonacci numbers smaller than 2^53 can be exactly represented as a double (plus a few larger ones divisible by sufficiently high powers of 2). The last Fibonacci number smaller than 2^53 is F(77), but F(78) is divisible by 8, so also exactly representable as a double with 53 bits of precision. However, the above produces correct results only for n <= 70 here, from 71 on, the rounding error is too large (incidentally, the result of Binet's formula using doubles is always too large here, so using floor instead of round would produce the correct result also for F(71), but no further).

With the standard datatypes, not many Fibonacci numbers are exactly representable, the last to fit in an (unsigned) 64 bit type is F(93); for 128 bits, the last is F(186). 

For so small indices, there is practically nothing to be gained over the straightforward iterative algorithm



unless you use a lookup table

static const unsigned long long fibs[94] = { 0, 1, 1, 2, ... , 12200160415121876738ull };


// Fibonacci number calculation using recursion
long long recursive_fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return recursive_fib(n - 1) + recursive_fib(n - 2);
    }
}





For accurate results, one must treat √5 (and/or φ) as a symbolic constant and evaluate the formula using that. This amounts to evaluating the formula in the ring

ℤ[φ] = { a + b*φ : a, b ∈ ℤ }

of algebraic integers in ℚ(√5), using the fact that φ² = 1 + φ. Equivalent to Binet's formula is

φ^n = F(n-1) + φ*F(n)

which can be used to efficiently calculate Fibonacci numbers by repeated squaring in O(log n) steps (but note that F(n) has Θ(n) bits, so the number of bit operations can't be lower than O(n)). A slightly more efficient version than the vanilla repeated squaring uses

φ^(2n) = (φ^n)² = (F(n-1) + φ*F(n))² = F(n-1)² + φ*2*F(n-1)*F(n) + φ²*F(n)²
       = (F(n-1)² + F(n)²) + φ*(2*F(n-1)*F(n) + F(n)²)

finding F(2n) = 2*F(n)*F(n-1) + F(n)² = 2*F(n)*F(n+1) - F(n)² = F(n)*(F(n+1) + F(n-1)) and F(2n+1) = F(n)² + F(n+1)², using φ² = 1 + φ. These formulae allow calculating F(2n), F(2n+1) and F(2n+2) from F(n) and F(n+1) with at most two multiplications and two additions/subtractions per number, which gives an algorithm to calculate the pair (F(n),F(n+1)) in O(log n) steps with only two numbers as state (vanilla repeated squaring uses four numbers as state and needs a few more multiplications).

An iterative left-to-right algorithm is

unsigned long long fib(unsigned int n){
    if (n == 0) return 0;
    unsigned int h = n/2, mask = 1;
    // find highest set bit in n, can be done better
    while(mask <= h) mask <<= 1;
    mask >>= 1;
    unsigned long long a = 1, b = 1, c; // a = F(k), b = F(k+1), k = 1 initially
    while(mask)
    {
        c = a*a+b*b;        // F(2k+1)
        if (n&mask)
        {
            b = b*(b+2*a);  // F(2k+2)
            a = c;          // F(2k+1)
        } else {
            a = a*(2*b-a);  // F(2k)
            b = c;          // F(2k+1)
        }
        mask >>= 1;
    }
    return a;
}

With an arbitrary precision type instead of unsigned long long, that allows the fast calculation of large Fibonacci numbers. But of course arbitrary precision libraries often come with their own optimized Fibonacci functions, so it's kind of moot to implement it yourself.

/*
The Fibonacci Sequence is a series of numbers named after Italian mathematician, known as Fibonacci. Starting with 0 and 1, each new number in the Fibonacci Series is simply the sum of the two before it.

such as

    F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.

Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying

    F(n) * F(n+1) = prod.

Your function productFib takes an integer (prod) and returns an array/vector:

[F(n), F(n+1), true]

if F(n) * F(n+1) = prod.

If you don't find two consecutive F(m) verifying F(m) * F(m+1) = prod you will return

[F(m), F(m+1), false]

F(m) being the smallest one such as F(m) * F(m+1) > prod.


*/

#include <vector>

std::vector<ull> productFib(ull prod)
{
	ull a = 1, b = 1, next;

	while (a * b < prod)
	{
		next = a + b;
		a = b;
		b = next;
	}

	return {a, b, a * b == prod};
}

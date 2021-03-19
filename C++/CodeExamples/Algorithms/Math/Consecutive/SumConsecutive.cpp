/*

Sum All from 1 to N

The sum S, of the first N natural numbers can be represented by the formula

	S = N(N+1) / 2

where N is the highest number in the range [1, N]

*/

/*
Brute Force

We can represent the brute force implementation with the C++ function.
*/

int sumConsecutiveBrute(int N)
{
	int sum = 1;
	for(int i = 2; i <= N; sum += i; i++);
	return sum;
}

/*
Formula

We can represent the formula implementation with the C++ funciton.
*/

int sumConsecutiveFormula(int N)
{
	return N*(N+1)/2;
}

/*
Sum Evens from 1 to N

The sum S, of the first N even numbers can be represented by the formula:

	S = N(N+2) / 4

where N is the highest even number in the range [1, N]
*/

/*
Brute Force

We can represent the brute force implementation with the C++ function.
*/

int sumConsecutiveEvensBrute(int N)
{
	int sum = 2;
	for(int i = 4; i <= N; sum += i; i+=2);
	return sum;
}

/*
Formula

We can represent the formula implementation with the C++ funciton.
*/

int sumConsecutiveEvensFormula(int N)
{
	return N*(N+1)/4;
}


/*
Sum Odds from 1 to N

The sum S, of the first N odd numbers can be represented by the formula:

	S = (n+1)/2)^2

	or

	S = (n+1)(n+1)/4

Where n is the highest odd number in the range [1, N]
*/

/*
Brute Force

We can represent the brute force implementation with the C++ function.
*/

int sumConsecutiveOddsBrute(int N)
{
	int sum = 1;
	for(int i = 3; i <= N; sum += i; i+=2);
	return sum;
}

/*
Formula

We can represent the formula implementation with the C++ funciton.
*/

int sumConsecutiveOddsFormula(int N)
{
	return (N+1)*(N+1)/4;
}

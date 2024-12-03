/// Read integers from standard in
/// prints a message that tells the user whether the number is even or odd.
/// counts and outputs the total counts of even and odd integers.

#include <iostream>

int main()
{

int x, evens = 0, odds = 0;
while (std::cin >> x)
	if (x % 2 == 0)
	{
		evens++;
		std::cout << x << " is even.\n";
	}
	else
	{
		odds++;
		std::cout << x << " is odd.\n";
	}
	std::cout << evens << " evens and " << odds << " odds.\n";
}

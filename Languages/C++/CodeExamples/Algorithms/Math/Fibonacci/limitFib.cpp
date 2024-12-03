/*
Generate a vecotr of Fibonacci numbers up to a value n.

The Fibonacci Sequence is a peculiar series of numbers named after Italian mathematician, known as Fibonacci. Starting with 0 and 1, each new number in the Fibonacci Series is simply the sum of the two before it.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> generateFib(int n){
	vector<int> fib;
	fib.push_back(0);
	fib.push_back(1);
	int next = fib[0] + fib[1];
	for(int index = 1; next <= n; index++)
	{
		fib.push_back(next);
		next = fib[index] + fib[index+1];
	}

	return fib;
}

int main()
{
	int limit = 144;
	vector<int> fib = generateFib(limit);

	cout << "The fibbonaci numbers less than " << limit << ": ";
	for (auto it = fib.begin(); it != fib.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
}

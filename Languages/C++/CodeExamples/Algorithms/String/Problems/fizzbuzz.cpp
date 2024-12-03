#include <iostream>

using namespace std;

void fizzbuzz(int range)
{
	for(int i = 1; i <= range; i++)
	{
		bool modThree = i % 3 == 0;
		bool modFive = i % 5 == 0;
		if(modThree && modFive)
		{
			cout << "Fizzbuzz\n";
		}
		else if(modFive)
		{
			cout << "Buzz\n";
		}
		else if(modThree)
		{
			cout << "Fizz\n";
		}
		else
		{
			cout << i << '\n';
		}
	}
}

int main()
{
	int range;
	cout << "Please input a range to test: ";
	cin >> range;
	cout << '\n';
	fizzbuzz(range);
}

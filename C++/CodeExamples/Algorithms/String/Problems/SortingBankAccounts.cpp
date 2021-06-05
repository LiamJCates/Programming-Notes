/*
Input:
2
6
03 10103538 2222 1233 6160 0142
03 10103538 2222 1233 6160 0141
30 10103538 2222 1233 6160 0141
30 10103538 2222 1233 6160 0142
30 10103538 2222 1233 6160 0141
30 10103538 2222 1233 6160 0142

5
30 10103538 2222 1233 6160 0144
30 10103538 2222 1233 6160 0142
30 10103538 2222 1233 6160 0145
30 10103538 2222 1233 6160 0146
30 10103538 2222 1233 6160 0143

Output:

03 10103538 2222 1233 6160 0141 1
03 10103538 2222 1233 6160 0142 1
30 10103538 2222 1233 6160 0141 2
30 10103538 2222 1233 6160 0142 2

30 10103538 2222 1233 6160 0142 1
30 10103538 2222 1233 6160 0143 1
30 10103538 2222 1233 6160 0144 1
30 10103538 2222 1233 6160 0145 1
30 10103538 2222 1233 6160 0146 1
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printAccount(string account, int number)
{
cout << account.substr(0,2) << " "
    << account.substr(2,8) << " "
    << account.substr(10, 4) << " "
    << account.substr(14, 4) << " "
    << account.substr(18, 4) << " "
    << account.substr(22, 4) << " "
    << number << endl;
}

void sortAccounts()
{
	int accounts;
	cin >> accounts;
	vector<string> accs(accounts);
	string segment;
	for(int i = 0; i < accounts; i++)
	{
		accs[i] = "";
		for(int j = 6; j; --j)
		{
			cin >> segment;
			accs[i] += segment;
		}
	}
	std::sort(accs.begin(), accs.end());

	accounts = 0;
	segment = accs[0];
	for(auto s : accs)
	{
		if(s == segment)
			accounts++;
		else
		{
			printAccount(segment, accounts);
			accounts = 1;
			segment = s;
		}
	}
  printAccount(segment, accounts);
  cout << endl;
  cin.ignore();
}

int main()
{
	int tests;
	cin >> tests;
	while(tests--)
		sortAccounts();
}

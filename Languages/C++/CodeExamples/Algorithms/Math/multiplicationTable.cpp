/*
Your goal is to return multiplication table for number that is always an integer from 1 to 10.

For example, a multiplication table (string) for number == 5 looks like below:

1 * 5 = 5
2 * 5 = 10
3 * 5 = 15
4 * 5 = 20
5 * 5 = 25
6 * 5 = 30
7 * 5 = 35
8 * 5 = 40
9 * 5 = 45
10 * 5 = 50

Note: newlines should be added between rows, but there should be no trailing newline at the end.
*/


void printTable(int n){
	for(int i = 1; i < 10; i++)
		std::cout << i << " * " << n << " = " << i*n << '\n';

	std::cout << i << " * " << n << " = " << i*n;

}



#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    using namespace std;
    int constexpr low{1};      ///< Minimum value for the table
    int constexpr high{10};    ///< Maximum value for the table
    int constexpr colwidth{4}; ///< Fixed width for all columns
    // All numbers must be right-aligned.
    cout << right;
    // First print the header.
    cout << setw(colwidth) << '*'
         << '|';
    for (int i{low}; i <= high; i = i + 1)
        cout << setw(colwidth) << i;
    cout << '\n';
    // Print the table rule by using the fill character.
    cout << setfill('-')
         << setw(colwidth) << ""                    // one column's worth of "-"
         << '+'                                     // the vert. & horz. intersection
         << setw((high - low + 1) * colwidth) << "" // the rest of the line
         << '\n';
    // Reset the fill character.
    cout << setfill(' ');
    // For each row...
    for (int row{low}; row <= high; row = row + 1)
    {
        cout << setw(colwidth) << row << '|';
        // Print all the columns.
        for (int col{low}; col <= high; col = col + 1)
            cout << setw(colwidth) << row * col;
        cout << '\n';
    }
}

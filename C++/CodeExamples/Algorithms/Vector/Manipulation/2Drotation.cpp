/*
This algorithm is O ( N2 ), which is the best we can do since any algorithm must touch all N2 elements.

*/

#include <vector>

bool rotate2D(std::vector<std::vector<int>> matrix)
{
	if (matrix.size() == 0 || matrix.size() != matrix[0].size())
		return false;
	int n = matrix.size();
	for (int layer = 0; layer < n / 2; layer++)
	{
		int first = layer;
		int last = n - 1 - layer;
		for (int i = first; i < last; i++)
		{
			int offset = i - first;
			int top = matrix[first][i]; // save top

			// left -> top
			matrix[first][i] = matrix[last - offset][first];

			// bottom -> left
			matrix[last - offset][first] = matrix[last][last - offset];

			// right -> bottom
			matrix[last][last - offset] = matrix[i][last];

			// top -> right
			matrix[i][last] = top; // right<- saved top
		}
	}
	return true;
}

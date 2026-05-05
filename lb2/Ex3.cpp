#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;
int main()
{
	srand(time(NULL));

	int matrix[100][100], i, j, n, m;
	int max = 0, maxRow = 0, maxCol = 0;
	n = 5;
	m = 5;
	int timeCount = 0;


	cout << "Size of the matrix: " << n << " " << "on" << " " << m << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			matrix[i][j] = 10 - rand() % 21;
		}
	}
	cout << endl;
	cout << "Matrix elements: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
	max = matrix[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
				maxRow = i;
				maxCol = j;
			}
		}
	}
	cout << "Max element: " << max << endl;
	cout << endl;
	cout << "Max element coordinates: " << endl;
	cout << setw(4) << "Row: " << maxRow << ", " << "Coloumn: " << maxCol;
	cout << endl;

	clock_t start1 = clock();

	if (maxRow != 0)
	{
		for (j = 0; j < m; j++)
			swap(matrix[0][j], matrix[maxRow][j]);

		if (maxCol != 0)
		{
			for (i = 0; i < n; i++)
				swap(matrix[i][0], matrix[i][maxCol]);
		}
		cout << endl;
		cout << "Final result: " << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << setw(4) << matrix[i][j];
			}
			cout << endl;
		}
	}
	clock_t end1 = clock();
	timeCount = (double)(end1 - start1);
	cout << "Swap time: " << timeCount << setprecision(3) << "ms";
	return 0;

}
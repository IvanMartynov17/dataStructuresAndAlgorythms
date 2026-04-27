#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	srand(time(NULL));
	int matrix[100][100], n, m, i = 0, j = 0;
	int max = 0, maxRow = 0;
	
	cout << "Enter size of the matrix";
	cin >> n >> m;

	cout << "Elements of matrix" << endl; 
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			matrix[i][j] = 10 - rand() % 21;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;

	cout << "Matrix without main diagonal: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (i != j)
				cout << setw(4) << matrix[i][j] << " ";
			else
				cout << setw(4) << "  ";
		}
		cout << endl;
	}
	max = matrix[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
				maxRow = i;
			}
		}
	}
	cout << endl;
	cout << "Max element: " << max;
	cout << endl;
	for (i = maxRow; i < n - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = matrix[i + 1][j];
		}
	}
	n--;
	
	cout << "Result matrix: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
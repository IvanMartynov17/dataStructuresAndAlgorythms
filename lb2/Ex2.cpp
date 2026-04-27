#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	srand(time(NULL));
	int A[200], n, i, x;
	int NewArraySize = 0;

	cout << "Enter size of array: ";
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		A[i] = rand() % 21;
	}
	cout << "Completed array: ";
	
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << "Enter x: ";
	cin >> x;
	for (i = 0; i < n; i++)
	{
		if (A[i] > x)
		{
			A[NewArraySize] = A[i];
			NewArraySize++;
		}
	}
	cout << "Array after deleting elements <= x: ";
	for (i = 0; i < NewArraySize; i++)
		cout << A[i] << " ";

	for (i = NewArraySize - 1; i >= 0; i--)
	{
		A[2 * i] = A[i];
		A[2 * i + 1] = 0;
	}
	
	NewArraySize *= 2;

	cout << "Final Array:  ";
	for (i = 0; i < NewArraySize; i++)
		cout << A[i] << " ";
	return 0;
}
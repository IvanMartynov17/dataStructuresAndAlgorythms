#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int a[100], even[100], odd[100], i, n, e = 0, o = 0, temp = 0;
	
	cout << "Enter size of array: ";
	cin >> n;

	cout << "Enter array elements: ";
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			even[e] = a[i];
			e++;
		}
		else 
		{
			odd[o] = a[i];
			o++;
		}
	}
	cout << "Even elements: ";
	for (i = 0; i < e; i++)
	{
		cout << even[i] << " ";
	}

	cout << endl;

	cout << "Odd elements: ";
	for (i = 0; i < o; i++)
	{
		cout << odd[i] << " ";
	}

	clock_t start1 = clock();

	for (i = 0; i < e - 1; i++)
	{
		for (int j = 0; j < e - i - 1; j++)
		{
			if (even[j] > even[j + 1])
			{
				temp = even[j];
				even[j] = even[j + 1];
				even[j + 1] = temp;
			}
		}
	}
	clock_t end1 = clock();
		cout << endl;
		cout << "Sorted even elements: ";
		for (i = 0; i < e; i++)
		cout << even[i] << " ";

		clock_t start2 = clock();
		for (i = 0; i < o - 1; i++)
		{
			for (int j = 0; j < o - i - 1; j++)
			{
				if (odd[j] < odd[j + 1]) 
				{
					temp = odd[j];
					odd[j] = odd[j + 1];
					odd[j + 1] = temp;
				}
			}
		}
		
		clock_t end2 = clock();

		cout << endl;
		cout << "Sorted odd elements: ";
		for (i = 0; i < o; i++)
			cout << odd[i] << " ";

		for (i = 0; i < e; i++)
			a[i] = even[i];

		for (i = 0; i < o; i++)
			a[e + i] = odd[i];
		
		cout << endl;
		
		cout << "Result array: ";
		for (i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		
		cout << "Sort time (even):  " << (double)(end1 - start1) / CLOCKS_PER_SEC << endl;
		cout << "Sort time (odd):  " << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;


	return 0;
}
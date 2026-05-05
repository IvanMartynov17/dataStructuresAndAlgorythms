#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
void BubbleSortMatrix(double a[], int n, int rows);
bool multiplicityCheck(int n);
void EnterSizeOfArray(int& n);
void CreateMatrix(double a[100], double b[50][50], int n);
void SearchMaxElement(double b[50][50], int rows, int cols);
void measureComplexity(int testSizes[], int numTests);


int main()
{
	int testSizes[] = { 16, 36, 100 };
	int numTest = 3;
	
	
	int intMin = -150;
	int intMax = 450;
	int arrElements;
	double a[100], b[50][50], maxColElement = 0.00;
	int n,  i = 0, rows, cols = 4, k = 0, j = 0;
	double time_taken;

	srand(time(NULL));

	EnterSizeOfArray(n);

	if (!multiplicityCheck(n))
	{
		return 0;
	}
	rows = n / cols;

	for (i = 0; i < n; i++) {
		arrElements = intMin + rand() % (intMax - intMin + 1);
		a[i] = arrElements / 100.00;
	}
	for (i = 0; i < n; i++)
	{
		cout << fixed << setprecision(2)  << a[i] << " ";
	}

	clock_t createnSortstart = clock();

	CreateMatrix(a, b, n);

	for (i = 0; i < rows; i++)
	{
		BubbleSortMatrix(b[i], cols, i);
	}

	cout << "\tSorted matrix\t" << endl;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			cout << setw(8) << b[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	cout << endl;

	SearchMaxElement(b, rows, cols);

	clock_t createnSortEnd = clock();

	time_taken = double(createnSortEnd - createnSortstart) / CLOCKS_PER_SEC;
	cout << "\nTime taken for matrix creation, sorting and other: " << time_taken << " seconds" << endl;

	cout << endl;
	cout << "Memory size of array a: " << sizeof(a[0]) * n << " bytes" << endl;
	cout << "Memory size of matrix b: " << sizeof(b[0][0]) * rows * cols << " bytes" << endl;

	measureComplexity(testSizes, numTest);

	return 0;
}


void BubbleSortMatrix(double a[], int n, int rows)
{
	int i = 0, j = 0;
	double temp = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if ((rows % 2 == 0 && a[j] > a[j + 1]) ||
				(rows % 2 != 0 && a[j] < a[j + 1]))
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

bool multiplicityCheck(int n)
{
	if (n % 4 != 0)
	{
		cout << endl;
		cerr << "\tError.. size must multiple 4" << endl << "\t\tExit....\t";
		cout << endl;
		return false;
	}
	return true;
}

void EnterSizeOfArray(int& n)
{
	cout << "Enter an size of the array ( array must be multiply 4): ";
	cin >> n;
}

void CreateMatrix(double a[100], double b[50][50], int n) {
	int	rows = 0, cols = 4, i = 0, k = 0, j = 0;
	rows = n / cols;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			b[i][j] = a[k];
			k++;
		}
	}

	cout << endl;
	cout << endl;

	cout << "\tMatrix: \t" << endl;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			cout << setw(8) << b[i][j] << " ";
		}
		cout << endl;
	}
}
void SearchMaxElement(double b[50][50], int rows, int cols)
{
	double maxColElement;
	int i, j;
	cout << "\tMax element in each column\t" << endl;

	for (j = 0; j < cols; j++)
	{
		maxColElement = b[0][j];

		for (i = 0; i < rows; i++)
		{
			if (b[i][j] > maxColElement)
			{
				maxColElement = b[i][j];
			}
		}
		cout << "Column" << " " << j + 1 << " " << "max element = " << maxColElement << endl;
	}
}

void measureComplexity(int testSizes[], int numTests)
{
	ofstream outFile("C:/Users/User/Desktop/СДтаА/лаби/лб1/LB1output.txt");

	if (!outFile.is_open()) {
		cerr << "Error opening output.txt for writing\n";
		return;
	}

	
	outFile << "|-----|------|---------------|---------------|" << endl;
	outFile << "|  №  |   n  |   Time, sec   |  Space, byte  |" << endl;
	outFile << "|-----|------|---------------|---------------|" << endl;

	int intMin = -150;
	int intMax = 450;
	double a[100]; 
	double b[50][50]; 
	int cols = 4;

	for (int testNum = 0; testNum < numTests; testNum++)
	{
		int n = testSizes[testNum];
		int rows = n / cols;


		srand(time(NULL) + testNum * 100); 


		for (int i = 0; i < n; i++) {
			int arrElements = intMin + rand() % (intMax - intMin + 1);
			a[i] = arrElements / 100.00;
		}

		
		clock_t start = clock();

		int k = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				b[i][j] = a[k];
				k++;
			}
		}

		
		for (int i = 0; i < rows; i++)
		{
			BubbleSortMatrix(b[i], cols, i);
		}

		for (int j = 0; j < cols; j++)
		{
			double maxColElement = b[0][j];
			for (int i = 1; i < rows; i++)
			{
				if (b[i][j] > maxColElement)
				{
					maxColElement = b[i][j];
				}
			}
		}

		clock_t end = clock();
		double time_taken = double(end - start) / CLOCKS_PER_SEC;

		int space = sizeof(a[0]) * n + sizeof(b[0][0]) * rows * cols;

		
		outFile << "|  " << (testNum + 1) << "  |  "
			<< setw(4) << n << "  |  "
			<< setw(11) << fixed << setprecision(3) << time_taken << "  |  "
			<< setw(11) << space << "  |" << endl;
	}

	outFile << "|-----|------|---------------|---------------|" << endl;
	outFile.close();

	cout << "\nResults have been written to output.txt" << endl;
	cout << "File format:" << endl;
	cout << "| № | n | Time, sec. | Space, byte |" << endl;
}
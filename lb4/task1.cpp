#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Abiturient 
{
	string name;
	string gender;
	string spec;
	int exam[3];
};

int countVowels(string s);
void printVowels(Abiturient a[], int n);
double avgMark(Abiturient a);
void printBelowPass(Abiturient a[], int n, int pass);
void deleteAvgFive(Abiturient a[], int& n);
void sortByName(Abiturient a[], int n);

int main() 
{
	Abiturient abiturients[3];
	int i, n, j, pasingScore;
	cout << "Enter count of abiturients: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Enter name of a abiturient: ";
		cin >> abiturients[i].name;

		cout << "Enter gender of a abiturient: ";
		cin >> abiturients[i].gender;

		cout << "Enter a spec: ";
		cin >> abiturients[i].spec;

		cout << "Enter a marks of the exams (3)";
		for (j = 0; j < 3; j++)
		{
			cin >> abiturients[i].exam[j];
		}
	}

	printVowels(abiturients, n);

	cout << "Enter Passing score: ";
	cin >> pasingScore;

	printBelowPass(abiturients, n, pasingScore);

	sortByName(abiturients, n);

	cout << "\tSorted list:\n";
	for (i = 0; i < n; i++)
		cout << abiturients[i].name << " - " << abiturients[i].spec << endl;

	deleteAvgFive(abiturients, n);

	cout << "\tAfter deleting students with avg = 5:\n";
	for (i = 0; i < n; i++)
		cout << abiturients[i].name << " - avg: " << avgMark(abiturients[i]) << endl;
	
	return 0;
}

void sortByName(Abiturient a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j].name > a[j + 1].name)
				swap(a[j], a[j + 1]);
		}
	}
}

void deleteAvgFive(Abiturient a[], int& n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (avgMark(a[i]) == 5)
		{
			for (j = i; j < n - 1; j++)
				a[j] = a[j + 1];

			n--;
			i--;
		}
	}
}

void printBelowPass(Abiturient a[], int n, int pass)
{
	bool found;
	int i;
	found = false;

	cout << "\nStudents below passing score:\n";

	for (i = 0; i < n; i++)
	{
		if (avgMark(a[i]) < pass)
		{
			cout << a[i].name << " - " << a[i].spec << endl;
			found = true;
		}
	}

	if (!found)
		cout << "No such students.\n";
}

int countVowels(string s)
{
	int vowelsCount = 0, i = 0, j = 0;
	string vowels = "aeiouy";
	for (i = 0; i < s.length(); i++)
	{
		for (j = 0; j < vowels.length(); j++)
		{
			if (s[i] == vowels[j])
				vowelsCount++;
		}
	}
	return vowelsCount;
}

void printVowels(Abiturient a[], int n)
{
	int i;
	cout << "\tSurnames with no more 3 vowels: \t" << endl;

	for (i = 0; i < n; i++)
	{
		if (countVowels(a[i].name) <= 3)
			cout << a[i].name << endl;
	}
}

double avgMark(Abiturient a)
{
	return (a.exam[0] + a.exam[1] + a.exam[2]) / 3.0;
}
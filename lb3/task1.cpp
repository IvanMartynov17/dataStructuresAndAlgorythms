#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;



struct Worker {
	string surnamenInitials;
	string position;
	int yearOfAdmission;
	double salary;
};
int expirience(Worker w ) //TODO pass curYear as param
{
	int currYear, yearOfAdmission, finalYear = 0;
	currYear = 2026;

		finalYear = currYear - w.yearOfAdmission;
		return finalYear;
}

double salaryAfterTax(Worker w) //TODO pass tax(double) 0.67 as param
{
	return w.salary * 0.67;
}


int main()
{
	Worker w[100];
	int n, i;
	cout << "Enter count of workers: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "\tWorker num " << i + 1 << endl;

		cout << "Enter surname n initials: " << endl;
		cin >> w[i].surnamenInitials;
		
		cout << "Enter position: " << endl;
		cin >> w[i].position;
		
		cout << "Enter year of admission" << endl;
		cin >> w[i].yearOfAdmission;
		
		cout << "Enter worker's salary: " << endl;
		cin >> w[i].salary;
	}

	cout << "\tWorker's info: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << endl;
		cout << "\tWorker number: " << i + 1 << endl;
		cout << "Name: " << w[i].surnamenInitials << endl;
		cout << "Position: " << w[i].position << endl;
		cout << "Expirience: " << expirience(w[i]) << endl;
		cout << "Salary after tax: " << salaryAfterTax(w[i]) << endl;
	}

	
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

struct Worker
{
	string name;
	string department;
	double salary;
	Worker* next;
}*first, *last;

void showWorkerList()
{
	Worker* current = first;
	if (first == nullptr)
	{
		cout << "No workers in the list." << endl;
		return;
	}

	while (current != nullptr)
	{
		cout << "Name: " << current->name 
			<< ", Department: " 
			<< current->department 
			<< ", Salary: " << current->salary 
			<< endl;
		current = current->next;
	}
}

void addWorkerToEnd(const string& name, const string& department, double salary)
{
	Worker* newWorker = new Worker{name, department, salary, nullptr};
	if (first == nullptr)
	{
		first = last = newWorker;
	}
	else
	{
		last->next = newWorker;
		last = newWorker;
	}
}	

double getAverageSalary()
{
	if (first == nullptr) return 0;

	double sum = 0;
	int count = 0;

	Worker* current = first;
	while (current)
	{
		sum += current->salary;
		count++;
		current = current->next;
	}

	
	cout << "Average Salary: " << sum / count << endl;
	return sum / count;
}

void splitLists(Worker*& aboveFirst, Worker*& aboveLast,
	Worker*& belowFirst, Worker*& belowLast,
	double avg)
{
	Worker* current = first;

	while (current)
	{
		if (current->salary > avg)
		{
			Worker* newNode = new Worker{ current->name, current->department, current->salary, nullptr };

			if (!aboveFirst)
				aboveFirst = aboveLast = newNode;
			else
			{
				aboveLast->next = newNode;
				aboveLast = newNode;
			}
		}
		else
		{
			Worker* newNode = new Worker{ current->name, current->department, current->salary, nullptr };

			if (!belowFirst)
				belowFirst = belowLast = newNode;
			else
			{
				belowLast->next = newNode;
				belowLast = newNode;
			}
		}

		current = current->next;
	}

}


void showReverse(Worker* current)
{
	if (current == nullptr) return;

	showReverse(current->next);
	cout << "Name: " << current->name
		<< ", Department: " << current->department
		<< ", Salary: " << current->salary << endl;
}

int main()
{
		cout << "\tWorker List Management\t" << endl;

		addWorkerToEnd("Alice", "HR", 50000);
		addWorkerToEnd("Bob", "IT", 60000);
		addWorkerToEnd("Charlie", "Finance", 55000);
		addWorkerToEnd("Diana", "Marketing", 52000);
		addWorkerToEnd("Eve", "Sales", 48000);
		addWorkerToEnd("Frank", "Operations", 53000);

		cout << "\nOriginal list:\n";
		showWorkerList();

		double avg = getAverageSalary();

		Worker* aboveFirst = nullptr;
		Worker* aboveLast = nullptr;
		Worker* belowFirst = nullptr;
		Worker* belowLast = nullptr;

		splitLists(aboveFirst, aboveLast, belowFirst, belowLast, avg);

		cout << "\nAbove average (forward):\n";
		Worker* temp = aboveFirst;
		while (temp)
		{
			cout << temp->name << " " << temp->salary << endl;
			temp = temp->next;
		}

		cout << "\nAbove average (reverse):\n";
		showReverse(aboveFirst);

		cout << "\nBelow or equal average (forward):\n";
		temp = belowFirst;
		while (temp)
		{
			cout << temp->name << " " << temp->salary << endl;
			temp = temp->next;
		}

		cout << "\nBelow or equal average (reverse):\n";
		showReverse(belowFirst);

		cout << "\nAdding new worker to ABOVE list:\n";
		Worker* newWorker = new Worker{ "George", "IT", 70000, nullptr };

		if (!aboveFirst)
			aboveFirst = aboveLast = newWorker;
		else
		{
			aboveLast->next = newWorker;
			aboveLast = newWorker;
		}

		cout << "\nAbove average after adding:\n";
		showWorkerList();


		return 0;
}
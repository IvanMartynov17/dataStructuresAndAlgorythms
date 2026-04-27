#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


struct Stack
{
	double number;
	Stack* next;
};
Stack* root = nullptr;

void fillStackRandom(int n)
{
	
	for (int i = 0; i < n; i++)
	{
		Stack* newNode = new Stack;

		newNode->number = -6 + rand() % (11 - (-6) + 1);
		newNode->next = root;
		root = newNode;
	}
}

void showStack()
{
	Stack* current = root;
	if (current == nullptr)
	{
		cout << "The stack is empty.." << endl;
		return;
	}
	cout << "Stack elements: ";
	while (current != nullptr)
	{
		cout << current->number << " ";
		current = current->next;
	}
	cout << endl;
}

void deleteStackElement(int value)
{
	while (root != nullptr && root->number < value)
	{
		Stack* temp = root;
		root = root->next;
		delete temp;
	}
	if (root == nullptr)
	{
		cout << "Stack is empty now.." << endl;
		return;
	}
	Stack* current = root;
	while (current != root)
	{
		if (current->next->number < value)
		{
			Stack* temp = current->next;
			current->next = temp->next;
			delete temp;
		}
		else
		{
			current = current->next;
		}
	}
}
double findAvgNumber()
{
	double sum = 0, count = 0;
	double avg;
	Stack* current = root;

	if (root == nullptr)
	{
		cout << "Stack is empty.. " << endl;
		return 0;
	}
	while (current != nullptr)
	{
		sum += current->number;
		count++;
		current = current->next;
	}
	avg = sum / count;
	cout << "Average elements in stack: " << avg;
	return avg;


}

int main()
{
	srand(time(NULL));

	fillStackRandom(10);
	showStack();
	findAvgNumber();
	cout << endl;

	deleteStackElement(5);
	showStack();
	cout << endl;
	findAvgNumber();

	return 0;
}
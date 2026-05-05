#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void enqueque(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}
void fillQueue(int n)
{
	int number;
	for (int i = 0; i < n; i++)
	{
		number = rand() % 100 + 1;
		enqueque(number);
	}
}
void insertAfterEven()
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->data % 2 == 0)
		{
			Node* newNode = new Node;
			newNode->data = 100;

			newNode->next = current->next;
			current->next = newNode;

			if (current == tail)
			{
				tail = newNode;
			}
			current = newNode->next;
		}
		else
		{ 
			current = current->next;
		}
	}
}
double geometricMean()
{
	if (head == nullptr) return 0;

	double product = 1;
	int count = 0;

	Node* current = head;

	while (current != nullptr)
	{
		product *= current->data;
		count++;
		current = current->next;
	}

	return pow(product, 1.0 / count);
}
void showQueue()
{
	Node* current = head;
	if (current == nullptr)
	{
		cout << "The stack is empty: " << endl;
		return;
	}
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
int main()
{
	srand(time(NULL));

	fillQueue(10);
	cout << "\tStandart queue: " << endl;
	showQueue();

	insertAfterEven();
	cout << "\tModified queue: " << endl;
	showQueue();

	cout << "Geometrical mean: " << geometricMean() << endl;
	return 0;
}
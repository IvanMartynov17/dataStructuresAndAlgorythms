#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int value)
	{
		data = value;
		next = nullptr;
	}
};

struct LinkedList
{

	Node* first;
	Node* last;
	int size;
	
	LinkedList()
	{
		first = nullptr;
		last = nullptr;
		size = 0;
	}

	void clear()
	{
		Node* current = first;
		while (current != nullptr)
		{
			Node* next = current->next;
			delete current;
			current = next;
		}
		first = nullptr;
		last = nullptr;
		size = 0;
	}

	void addToBegining(int value)
	{
		Node* newNode = new Node(value);
		if (first == nullptr)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			newNode->next = first;
			first = newNode;
		}
		size++;
		
	}

	void addToEnd(int value)
	{
		Node* newNode = new Node(value);
		if (first == nullptr)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			last = newNode;
		}
		size++;
		
	}

	void addToMiddle(int value, int position)
	{
		int i;
		if (position <= 0) {
			addToBegining(value);
			return;
		}
		if (position >= size) {
			addToEnd(value);
			return;
		}
		
		Node* newNode = new Node(value);
		Node* current = first;

		for (i = 0; i < position - 1; i++) {
			current = current->next;
		}	

		newNode->next = current->next;
		current->next = newNode;
		size++;
	}

	bool removeFirstEven()
	{
		if (first == nullptr)
		{
			cout << "List is empty.. " << endl;
			return false;
		}
		if (first->data % 2 == 0) {

			Node* temp = first;
			first = first->next;
			if (first == nullptr)
			{
				last = nullptr;
			}
			delete temp;
			size--;
			cout << "Deleted first even element.." << endl;
			return true;
		}
	}

	double avgListNum()
	{
		double sum = 0;
		if (size == 0)
		{
			cout << "The list is empty.. " << endl;
		}
		Node* current = first;
		while (current != nullptr)
		{
			sum += current->data;
			current = current->next;
		}
		sum /= size;
		cout << sum << endl;
		return sum;
	}
	void display()
	{
		if (first == nullptr)
		{
			cout << "List is empty.. " << endl;
			return;
		}
		Node* current = first;
		while (current != nullptr)
		{
			cout << current->data;
			if (current->next != nullptr)
			{
				cout << " -> ";
			}
			current = current->next;
		}
		cout << "\nSize: " << size << endl;
	}
	int getSize()
	{
		return size;
	}
};
int main()
{
	LinkedList list;
	cout << "Creating list with 4 elements..\n";
	cout << endl;
	list.addToBegining(5);
	list.addToEnd(4);
	list.addToMiddle(7, 1);
	list.addToBegining(2);
	
	cout << endl;
	cout << "Final list: \n";
	list.display();

	list.removeFirstEven();
	list.display();

	cout << "Average of list elements: " << endl;
	list.avgListNum();

	list.clear();
	return 0;
}
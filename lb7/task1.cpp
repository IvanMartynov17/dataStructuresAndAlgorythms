#include <iostream>
#include <cstdlib>

using namespace std;

struct Temperature
{
	int date;
	int temperature;
	Temperature* next;
	Temperature* prev;
}*first, *last;

Temperature* addTemperatureToEnd(Temperature*& first, Temperature*& last, int date, int temperature)
{
	Temperature* newTemperatureNode = new Temperature;
	newTemperatureNode->date = date;
	newTemperatureNode->temperature = temperature;
	newTemperatureNode->next = nullptr;
	newTemperatureNode->prev = last;
	
	if (first == nullptr)
	{
		first = last = newTemperatureNode;
	}
	else
	{
		last->next = newTemperatureNode;
		last = newTemperatureNode;
	}

	return newTemperatureNode;
}

void showTemperatureList(Temperature* first)
{
	if (first == nullptr)
	{
		cout << "The list is empty." << endl;
		return;
	}
	while (first != nullptr)
	{
		cout << "Date: " << first->date 
			<< " Temperature: " << first->temperature << endl;
		first = first ->next;
	}
	cout << endl;
}
void mergeLists(Temperature*& first1, Temperature*& last1,
	Temperature* first2, Temperature* last2)
{
	if (!first2) return;

	if (!first1)
	{
		first1 = first2;
		last1 = last2;
	}
	else
	{
		last1->next = first2;
		first2->prev = last1;
		last1 = last2;
	}
}
void findMinMaxTemperature(Temperature* first)
{
	int minTemp = first->temperature;
	int maxTemp = first->temperature;

	if (first == nullptr)
	{
		cout << "The list is empty." << endl;
	}
	
	while (first != nullptr)
	{
		if (first->temperature < minTemp)
		{
			minTemp = first->temperature;
		}
		if (first->temperature > maxTemp)
		{
			maxTemp = first->temperature;
		}
		first = first->next;
	}
	cout << "Minimum Temperature: " << minTemp << endl;
	cout << "Maximum Temperature: " << maxTemp << endl;
}

void deleteList(Temperature*& first)
{
	while (first)
	{
		Temperature* temp = first;
		first = first->next;
		delete temp;
	}
}

int main()
{
	Temperature* first1 = nullptr;
	Temperature* last1 = nullptr;
	Temperature* first2 = nullptr;
	Temperature* last2 = nullptr;

	cout << "\tList 1:" << endl;
	addTemperatureToEnd(first1, last1, 1, 20);
	addTemperatureToEnd(first1, last1, 2, 22);
	showTemperatureList(first1);

	cout << endl;
	cout << "\tList 2:" << endl;
	addTemperatureToEnd(first2, last2, 3, 18);
	addTemperatureToEnd(first2, last2, 4, 19);
	showTemperatureList(first2);
	
	cout << endl;
	cout << "\tMerged List:" << endl;
	mergeLists(first1, last1, first2, last2);
	showTemperatureList(first1);
	
	findMinMaxTemperature(first1);
	deleteList(first1);
	return 0;
}
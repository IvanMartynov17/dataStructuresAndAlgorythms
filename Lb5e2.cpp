#include <iostream>

using namespace std;

struct City
{
    string name;
    int distance;
    City* next;
} *first = 0, * last = 0;

City* addCity(City* first, string name, int dist)
{
    City* cityPointer = new City;
    cityPointer->name = name;
    cityPointer->distance = dist;
    cityPointer->next = 0;

    if (first == 0)
    {
        first = cityPointer;
        last = cityPointer;
        return first;
    }

    last->next = cityPointer;
    last = cityPointer;

    return first;
}

void showList(City* first)
{
    City* q = first;

    if (q == 0)
    {
        cout << "List is empty\n";
        return;
    }

    while (q != 0)
    {

        cout << q->name << " "
            << q->distance << "km ";
        q = q->next;
    }
    cout << endl;
}

void printFarthestCities(City* first)
{
    City* first1 = first;
    City* max1 = 0, * max2 = 0;

    if (first == 0)
    {
        cout << "List is empty\n";
        return;
    }

    while (first1 != 0)
    {
        if (max1 == 0 || first1->distance > max1->distance)
        {
            max2 = max1;
            max1 = first1;
        }
        else if (max2 == 0 || first1->distance > max2->distance)
        {
            max2 = first1;
        }

        first1 = first1->next;
    }

    cout << "Farthest cities:\n";

    if (max1 != 0)
        cout << max1->name << " " << max1->distance << "km\n";

    if (max2 != 0)
        cout << max2->name << " " << max2->distance << "km\n";

}

void deleteList(City* first)
{
    if (first == 0)
        return;

    while (first != 0)
    {
        City* temp = first;
        first = first->next;
        delete temp;
    }
}

int main()
{
    first = addCity(first, "Zhytomyr", 400);
    first = addCity(first, "Warsaw", 1200);
    first = addCity(first, "Berlin", 1500);

    cout << "Cities list:\n";
    showList(first);

    cout << endl;
    printFarthestCities(first);

    deleteList(first);

    return 0;
}
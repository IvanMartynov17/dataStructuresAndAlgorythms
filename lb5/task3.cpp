#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node
{
	string carBrand;
	int carYear;
	double carPrice;
	Node* next;
};

Node* createNode(const string& brand, int year, double price) {
    
    Node* newNode = new Node;
    
    newNode->carBrand = brand;
    newNode->carYear = year;
    newNode->carPrice = price;
    newNode->next = nullptr;
    
    return newNode;
}

void append(Node** first, const string& carBrand, int carYear, double carPrice)
{
    Node* newNode = createNode(carBrand, carYear, carPrice);
    if (*first == nullptr) {
        *first = newNode;
        return;
    }

    Node* current = *first;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

void printList(Node* first)
{
    int count = 1;
    if (first == nullptr)
    {
        cout << "List is empty..\n";
        return;
    }
    cout << "=============================================================" << endl;
    cout << "|   #   |   Auto mark   |   Year of car   |   Price (y. 0)   " << endl;
    
    Node* current = first;
    while (current != nullptr)
    {
        cout << "|" << setw(3) << count << "|"
            << setw(15) << left << current->carBrand
            << "|" << setw(7) << left << current->carYear
            << "|" << setw(7) << fixed << setprecision(2) << current->carPrice << " | " << endl;
        current = current->next;
        count++;
    }
    cout << "=============================================================" << endl;
}

void printOldAndCheapCars(Node* first, int currentYear) 
{

    int count = 0;
    Node* current = first;
    bool found = false;

    if (first == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "  Auto, which older than 10 years and price more than 5000 y.o" << endl;
    cout << "================================================================" << endl;
    cout << "|  №  |       Automobile brand       |  Car year  |  Price (у.о.) |" << endl;
    cout << "================================================================" << endl;

    while (current != nullptr) 
    {
        int age = currentYear - current->carYear;
        if (age > 10 && current->carPrice < 5000) 
        {
            cout << "| " << setw(3) << ++count << " | "
                << setw(30) << left << current->carBrand
                << "| " << setw(11) << right << current->carYear
                << " | " << setw(11) << fixed << setprecision(2) << current->carPrice << " |" << endl;
            found = true;
        }
    }
        current = current->next;
}



void addCar(Node** head) {
    string brand;
    int year;
    double price;

    cout << "\n--- Додавання нового автомобіля ---" << endl;
    cout << "Введіть марку автомобіля: ";
    cin.ignore();
    getline(cin, brand);

    cout << "Введіть рік випуску: ";
    cin >> year;

    cout << "Введіть ціну (у.о.): ";
    cin >> price;

    append(head, brand, year, price);
    cout << "Автомобіль \"" << brand << "\" успішно додано!" << endl;
}

int main()
{
    Node* head = nullptr;
    int n, year;
    double price;
    string brand;
    char choice;
    int currentYear = 2026;

    cout << "========================================" << endl;
    cout << "   Created list of cars" << endl;
    cout << "========================================" << endl;

    cout << "Current year: " << currentYear << endl;
    cout << "Enter count of cars: ";
    cin >> n;
    cin.ignore();

    if (n <= 0) {
        cout << "Count of cars must be more than zero!" << endl;
        return 1;
    }

    cout << "\n--- Enter all about cars ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nCar #" << i + 1 << ":" << endl;
        cout << "Brand of car: ";
        getline(cin, brand);

        cout << "Enter year of car: ";
        cin >> year;

        if (year < 1900 || year > currentYear) {
            cout << "Invalid year... Type current year" << endl;
            year = currentYear;
        }

        cout << "Price (у.о.): ";
        cin >> price;


        if (price < 0) {
            cout << "Price can't be smaller than 0." << endl;
            price = 0;
        }

        cin.ignore();

        append(&head, brand, year, price);
    }

    cout << "\n=== Full list of cars ===";
    printList(head);


    printOldAndCheapCars(head, currentYear);

    cout << "\nDo u wanna add another car? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        addCar(&head);

        cout << "\n=== Updated list of cars ===";
        printList(head);

        printOldAndCheapCars(head, currentYear);
    }
}
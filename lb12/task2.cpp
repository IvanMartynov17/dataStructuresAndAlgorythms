#include <iostream>
#include <array>

using namespace std;

struct Car {
    string brand;
    int year;
    double carMileage;
    Car* next;

    Car(string& b, int& y, double& cM)
        :brand(b), year(y), carMileage(cM), next(nullptr){}
};

void clearInput() {
    cin.ignore();
    cin.clear();
}

Car* createCar() {
    string brand;
    int year;
    double carMileage;
    cout << "Enter brand: ";
    cin >> brand;

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter car mileage: ";
    cin >> carMileage;
    clearInput();
    return new Car(brand, year, carMileage);
}

void printCar(Car* p) {
    cout << " [" << p->brand
    <<" | " << p->year << " | "
    << p->carMileage << "]" << endl;
}

void insertFirstCar(Car* head) {
    cout << "Enter first element: ";
    Car* p = createCar();
    p->next = head;
    head = p;
    cout << "Complete.. " << endl;
}

void insertBegin(Car*& head) {
    cout << " -- Begin insert: -- ";
    Car* p = createCar();
    p->next = head;
    head = p;
    cout << "Complete.. " << endl;
}

void insertEnd(Car*& head) {
    cout << " -- End insert: -- ";
    Car* p = createCar();
    Car* q = head;
    while (q->next != nullptr) {
        q = q->next;
    }
    q->next = p;
}

void insertAfter(Car*& head) {
    cout << " -- After insert: -- ";
    if (!head) { cout << "Empty list!" << endl; return; }

    string target;
    cout << "After what element? : "; getline(cin, target);

    Car* current = head;
    while (current && current->brand != target) {
        current = current->next;
    }
    if (!current) { cout << "Element not found!" << endl; return; }

    Car* p = createCar();
    p->next = current->next;
    current->next = p;

    cout << "Complete.. " << endl;
}

void insertBefore(Car*& head) {
    cout << " -- Before insert: -- ";
    if (!head) { cout << "Empty list!" << endl; return; }

    string target;
    cout << "Before what element? : "; getline(cin, target);

    if (head -> brand == target) {
        Car* p = createCar();
        p->next = head;
        head = p;
        cout << "Complete.. " << endl;
        return;
    }
    Car* prev = head;
    while (prev->next && prev->next->brand != target) {
        prev = prev->next;
    }
    if (!prev->next) { cout << "Element not found!" << endl; return; }
    Car* p = createCar();
    p->next = prev->next;
    prev->next = p;
    cout << "Complete.. " << endl;
}

void searchNode(Car*& head) {
    cout << " -- Search node: -- ";
    string brand;

    cout << "Enter brand: "; getline(cin, brand);
    Car* current = head;
    while (current) {
    if (current->brand == brand) {
        cout << "Found!" << endl;
        printCar(current);
        return;
    }
    current = current->next;
    }
cout << "Not found!" << endl;
}

void deleteByYear(Car*& head) {
    cout << " -- Delete by year: -- ";
    int year;
    cout << "Enter year: "; cin >> year;
    Car* current = head;
    clearInput();

    int count = 0;
    while (head && head->year < year) {
        Car* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    if (head) {
        Car* current = head;
        while (current->next) {
            if (current->next->year == year) {
                Car *temp = current->next;
                current->next = temp->next;
                delete temp;
                count++;
            }
            else {
                current = current->next;
            }
        }
    }
}

void printList(Car*& head) {
    cout << " -- Print list: -- " << endl;
    Car* current = head;
    int i = 1;
    while (current) {
        cout << " " << i++ << " ";
        printCar(current);
        current = current->next;
    }
}

void freeList(Car*& head) {
    Car* current = head;
    while (current) {
        Car* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
int main() {
        Car* head = nullptr;
        int op;
        do {
            cout << "\n--------- MENU ---------\n";
            cout << " 1. Enter the first element in list\n";
            cout << " 2. Insert element in begin\n";
            cout << " 3. Insert element in end\n";
            cout << " 4. Insert element after input element\n";
            cout << " 5. Insert element before input element\n";
            cout << " 6. Search car\n";
            cout << " 7. Delete car\n";
            cout << " 8. Show list\n";
            cout << " 9. Exit\n";
            cout << "------------------------------------------------\n";
            cout << "Enter your choice: ";
            cin >> op;
            clearInput();

            switch (op) {
                case 1: insertFirstCar(head);  break;
                case 2: insertBegin(head);  break;
                case 3: insertEnd(head);    break;
                case 4: insertAfter(head);  break;
                case 5: insertBefore(head); break;
                case 6: searchNode(head);   break;
                case 7: deleteByYear(head); break;
                case 8: printList(head);    break;
                case 9: cout << "\nExit.\n"; break;
                default: cout << " Error\n";
            }
        } while (op != 9);

        freeList(head);
        return 0;
    }

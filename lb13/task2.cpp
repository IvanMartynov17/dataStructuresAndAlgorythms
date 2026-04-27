#include <iostream>
#include <map>
#include <string>
using namespace std;


void addContact(map<string, string>& phonebook, const string& name, const string& phone) {
    phonebook[name] = phone;
    cout << "Контакт \"" << name << "\" збережено.\n";
}


void findContact(const map<string, string>& phonebook, const string& name) {
    auto it = phonebook.find(name);
    if (it != phonebook.end()) {
        cout << "Номер: " << it->second << "\n";
    } else {
        cout << "Контакт \"" << name << "\" не знайдено.\n";
    }
}


void deleteContact(map<string, string>& phonebook, const string& name) {
    if (phonebook.erase(name)) {
        cout << "Контакт \"" << name << "\" видалено.\n";
    } else {
        cout << "Контакт \"" << name << "\" не знайдено.\n";
    }
}


void printAll(const map<string, string>& phonebook) {
    if (phonebook.empty()) {
        cout << "Довідник порожній.\n";
        return;
    }
    cout << "\n--- Усі контакти ---\n";
    for (const auto& entry : phonebook) {
        cout << entry.first << " -> " << entry.second << "\n";
    }
}

int main() {
    map<string, string> phonebook;
    int choice;
    string name, phone;

    do {
        cout << "\n1. Додати  2. Знайти  3. Видалити  4. Всі  0. Вихід\n> ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Ім'я: "; getline(cin, name);
                cout << "Номер: "; getline(cin, phone);
                addContact(phonebook, name, phone);
                break;
            case 2:
                cout << "Ім'я: "; getline(cin, name);
                findContact(phonebook, name);
                break;
            case 3:
                cout << "Ім'я: "; getline(cin, name);
                deleteContact(phonebook, name);
                break;
            case 4:
                printAll(phonebook);
                break;
        }
    } while (choice != 0);

    return 0;
}
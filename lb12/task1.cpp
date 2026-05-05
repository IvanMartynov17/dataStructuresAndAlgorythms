#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

struct Book {
    string tittle;
    string author;
    string genre;
    double price;
    int popularity;
    string arrivalDate;
    bool onSale;

    void printBook() {
        cout << left
        << setw(10) << tittle
        << setw(10) << author
        << setw(10) << genre
        << setw(10) << fixed << setprecision(2) << price
        << setw(10) << popularity
        << setw(10) << arrivalDate
        << (onSale ? "Yes" : "No")
        << endl;
    }
};

void printHeader() {
    cout << left
        << setw(10) << "Title"
        << setw(10) << "Author"
        << setw(10) << "Genre"
        << setw(10) << "Price"
        << setw(10) << "Popularity"
        << setw(10) << "Arrival date"
        << setw(10) << "On sale"
    << endl;
}

void printBooks(vector<Book>& books) {
    if (books.empty()) {
        cout << "No books found." << endl;
        return;
    }
    printHeader();
    for (auto& book : books) {
        book.printBook();
    }
    cout << "All books: " << books.size() << "book" <<endl;
}

void clearInput() {
    cin.ignore();
    cin.clear();
}

void addBook(vector<Book>& store) {
    Book book;
    cout << "Enter book title: ";
    getline(cin, book.tittle);

    cout << "Enter book author: ";
    getline(cin, book.author);

    cout << "Enter book genre: ";
    getline(cin, book.genre);

    cout << "Enter book price: ";
    cin >> book.price;

    cout << "Enter book popularity: ";
    cin >> book.popularity;

    cout << "Enter book arrival date: ";
    getline(cin, book.arrivalDate);

    char onS;
    cout << "Is book on sale? (yes/no): ";
    cin >> onS;
    book.onSale = (onS == 'y' || onS == 'Y');
    store.push_back(book);

    cout << "Book added successfully." << endl;
}

void deleteBook(vector<Book>& store) {
    int index = store.size();
    store.erase(
        remove_if(store.begin(), store.end(),
            [](const Book& book) { return book.tittle == " "; }),
        store.end()
        );
    int removed = index - store.size();
    cout << "Book removed successfully. " << removed << " book" << endl;
}

void sortBooks(vector<Book>& store) {
    cout << "Enter sorting criteria: ";
    cout << "1. Price" << endl;
    cout << "2. Popularity" << endl;
    cout << "3. Arrival date" << endl;
    cout << "Command: ";
    int criteria;
    switch (criteria) {
        case 1:
            sort(store.begin(), store.end(), [](const Book& a, const Book& b) {
                return a.price < b.price;
            });
            cout << "Books sorted by price." << endl;
            break;
        case 2:
            sort(store.begin(), store.end(), [](const Book& a, const Book& b) {
                return a.popularity < b.popularity;
            });
            cout << "Books sorted by popularity." << endl;
        case 3:
            sort(store.begin(), store.end(), [](const Book& a, const Book& b) {
                return a.arrivalDate < b.arrivalDate;
            });
            default:
            cout << "Invalid sorting criteria." << endl;
    }
}

void filterBooks(vector<Book>& store) {
    cout << "Enter filtering criteria: ";
    cout << "1. Price" << endl;
    cout << "2. Popularity" << endl;
    cout << "3. Arrival date" << endl;
    cout << "Command: ";

    int criteria;
    string genre;
    double minPrice = 0, maxPrice = 0;

    cin >> criteria;
    if (criteria == 1 || criteria == 3) {
        cout << "Enter genre: ";
        getline(cin, genre);
    }
    if (criteria == 2 || criteria == 3) {
        cout << "Enter minimum price: ";
        cin >> minPrice;
        cout << "Enter maximum price: ";
        cin >> maxPrice;
    }

    vector<Book> result;

    copy_if(store.begin(), store.end(), back_inserter(result), [=](const Book& book) {
        bool ok = true;
        if (criteria == 1 || criteria == 3) {
            ok = ok && book.genre == genre;
        }
        if (criteria == 2 || criteria == 3) {
            ok = ok && book.price >= minPrice && book.price <= maxPrice;
        }
        return ok;
    });

    cout << "Books filtered successfully." << endl;
    printBooks(result);
}

void loadSampleData(vector<Book>& store) {
    Book book1 = { "The Hobbit", "", "Fantasy", 10.99, 1000, "2003-01-01", true };
    Book book2 = { "The Lord of the Rings", "", "Fantasy", 15.99, 500, "2001-01-01", false };
    Book book3 = { "The Hobbit: An Unexpected Journey", "", "Fantasy", 12.99, 800, "2002-01-01", true };
    Book book4 = { "The Lord of the Rings: The Fellowship of the Ring", "", "Fantasy", 18.99, 300, "2000-01-01", false };
}

void storeMenu() {
    cout << "\tStore menu:\t" << endl;
    cout << "1. Show books" << endl;
    cout << "2. Add book" << endl;
    cout << "3. Delete book" << endl;
    cout << "4. Sort books" << endl;
    cout << "5. Filter books" << endl;
    cout << "0. Exit" << endl;
}
int main() {
    vector<Book> store;
    int command;
    loadSampleData(store);

    while (true) {
        storeMenu();
        cout << "Enter command: ";
        cin >> command;
        switch (command) {
            case 1:
                printBooks(store);
                break;
            case 2:
                addBook(store);
                break;
            case 3:
                deleteBook(store);
                break;
            case 4:
                sortBooks(store);
                break;
            case 5:
                filterBooks(store);
                break;
            case 0:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid command." << endl;
                clearInput();
        }
    }
}
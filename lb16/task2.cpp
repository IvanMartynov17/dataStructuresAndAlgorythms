#include <iostream>
#include <vector>
using namespace std;

struct Product {
    string productName;
    double proteins;
    double carbohydrates;
    double fats;
    double calories;
};

double calcCalories(const Product& product) {
    return 4 * product.proteins + 9 * product.fats + 4 * product.carbohydrates;
}
int main() {
    int productCount;
    cout << "Enter count of products:";
    cin >> productCount;

    vector<Product> products(productCount);

    cout << "Enter product data:" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << "Product " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> products[i].productName;
        cout << "Proteins: ";
        cin >> products[i].proteins;
        cout << "Carbohydrates: ";
        cin >> products[i].carbohydrates;
        cout << "Fats: ";
        cin >> products[i].fats;

        products[i].calories = calcCalories(products[i]);
    }

    double maxCalories = products[0].calories;
    for (int i = 1; i < productCount; i++) {
        if (products[i].calories > maxCalories) {
            maxCalories = products[i].calories;
        }
    }
    cout << "Product with max calories: "
    << maxCalories << endl;

    cout << "Product with max calories: " << endl;
    for (int i = 0; i < productCount; i++) {
        if (products[i].calories == maxCalories) {
            cout << " [" << (i + 1) << "] " << products[i].productName
            << products[i].calories << endl;
        }
        else {
            cout << "Only one product found" << endl;
        }
    }

    int A, B;
    cout << "Enter two numbers: ";
    cin >> A >> B;

    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (products[i].calories >= A || products[i].calories <= B) {
            cout << " [" << (i + 1) << "] " << products[i].productName
            << " --- " << products[i].calories << "cal" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No products found." << endl;
    }
    return 0;
}
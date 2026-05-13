#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Products {
    double meat, flour, milk, sugar, calories, volume, mass;
};

int main() {
    const double calMeat = 1500, volMeat = 1.0;
    const double calFlour = 5000, volFlour = 1.5;
    const double calMilk = 5000, volMilk = 2.0;
    const double calSugar = 4000, volSugar = 1.0;

    const double maxMass = 35.0;
    const double maxVol = 45.0;

    Products bestPlan = {0, 0, 0, 0, 0, 0, 0};

    for (double x4 = 0; x4 <= maxMass; x4 += 0.01 ) {
        double x3 = 8 * x4;
        double x2 = x3;
        double x1 = 2 * x2;

        double currentMass = x1 + x2 + x3 + x4;
        double currentVol = (x1 * volMeat) + (x2 * volFlour) + (x3 * volMilk) + (x4 * volSugar);

        if (currentMass <= maxMass && currentVol <= maxVol) {
            double currentCal = (x1 * calMeat) + (x2 * calFlour) + (x3 * calMilk) + (x4 * calSugar);

            if (currentCal > bestPlan.calories) {
                bestPlan = {x1, x2, x3, x4,
                    currentCal, currentVol, currentMass};
            }
        }else {
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Meat: " << bestPlan.meat << " kg" << endl;
    cout << "Flour: " << bestPlan.flour << " kg" << endl;
    cout << "Milk: " << bestPlan.milk << " kg" << endl;
    cout << "Sugar: " << bestPlan.sugar << " kg" << endl;
    cout << "Calories: " << bestPlan.calories << " kcal" << endl;

    return 0;
}
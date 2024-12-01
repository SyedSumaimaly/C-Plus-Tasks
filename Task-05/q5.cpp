#include <iostream>
using namespace std;

int main() {
    const int threshold = 5; // Stock threshold level
    string fruits[] = {"Apples", "Bananas", "Oranges", "Grapes"};
    int stock[] = {3, 2, 6, 4}; // Current stock levels

    for (int i = 0; i < 4; i++) {
        cout << "Checking stock for " << fruits[i] << ": " << stock[i] << " units." << endl;

        while (stock[i] < threshold) {
            int refill;
            cout << fruits[i] << " stock is below threshold (" << threshold << "). Enter amount to add: ";
            cin >> refill;
            stock[i] += refill;
        }

        cout << fruits[i] << " stock updated. Current stock: " << stock[i] << " units.\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int number, range = 10;


    cout << "Enter the number for which you want the multiplication table: ";
    cin >> number;

    cout << "\nMultiplication Table of " << number << " up to " << range << ":" << endl;
    for (int i = 1; i <= range; i++) {
        cout << number << " x " << i << " = " << (number * i) << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    for (int i = 1; i <= rows; ++i) {
        // Print spaces for centering
        for (int j = 1; j <= rows - i; ++j) {
            cout << " ";
        }
        // Print asterisks
        for (int j = 1; j <= (2 * i - 1); ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}

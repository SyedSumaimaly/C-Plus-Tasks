#include <iostream>
using namespace std;

int main() {
    int number;
    int factorial = 1; // Factorial initialized as an int

    // Prompt the user to enter a non-negative integer
    cout << "Enter a non-negative integer: ";
    cin >> number;

    // Check if the input is valid
    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        int i = 1; // Counter for the while loop
        while (i <= number) {
            factorial *= i;
            i++;
        }
        // Display the factorial
        cout << "The factorial of " << number << " is " << factorial << "." << endl;
    }

    return 0;
}

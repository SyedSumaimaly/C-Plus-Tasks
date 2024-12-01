#include <iostream>
using namespace std;

int main() {
    int secretNumber = 42; // Fixed secret number (for simplicity, without libraries)
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Guess the number between 1 and 100." << endl;

    // Start the guessing loop
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++; // Increment attempts for each guess

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number." << endl;
            break; // Exit the loop
        }
    }

    cout << "You took " << attempts << " attempts to guess the correct number." << endl;
    return 0;
}
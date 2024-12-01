#include <iostream>
using namespace std;

int main() {
    // Initialize the range and target number
    const int lowerLimit = 1, upperLimit = 100;
    int targetNumber = 42; // Fixed number for simplicity. Replace with any fixed number.
    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "You have 6 attempts to guess a number between " << lowerLimit << " and " << upperLimit << "." << endl;

    // Loop for 6 attempts
    for (int attempts = 1; attempts <= 6; ++attempts) {
        cout << "Attempt " << attempts << ": Enter your guess: ";
        cin >> guess;

        // Check if the guess is correct
        if (guess == targetNumber) {
            cout << "Congratulations! You guessed the correct number!" << endl;
            return 0; // Exit the program
        } else if (guess > targetNumber) {
            cout << "Your guess is too high." << endl;
        } else {
            cout << "Your guess is too low." << endl;
        }
    }

    // If the player runs out of attempts
    cout << "Sorry, you've used all 6 attempts. The correct number was " << targetNumber << "." << endl;

    return 0;
}

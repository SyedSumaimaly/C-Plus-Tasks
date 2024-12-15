#include <iostream>

using namespace std;

int main() {
    int temperatures[7];
    int highest_temp, lowest_temp;

    cout << "Enter the temperatures for 7 days:\n";

    for (int i = 0; i < 7; ++i) {
        cin >> temperatures[i];
    }

    // Initialize highest and lowest with the first temperature
    highest_temp = lowest_temp = temperatures[0];

    for (int i = 1; i < 7; ++i) {
        if (temperatures[i] > highest_temp) {
            highest_temp = temperatures[i];
        }

        if (temperatures[i] < lowest_temp) {
            lowest_temp = temperatures[i];
        }
    }

    cout << "Highest temperature: " << highest_temp << endl;
    cout << "Lowest temperature: " << lowest_temp << endl;

    return 0;
}
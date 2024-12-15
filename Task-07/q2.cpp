#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of integers: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int max_value = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    cout << "The maximum value is: " << max_value << endl;

    return 0;
}
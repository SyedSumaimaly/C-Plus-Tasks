#include <iostream>
#include <algorithm> // For std::sort
using namespace std;

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    int arr[n];

    // Accept n integers from the user
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Sort the array in ascending order using std::sort
    sort(arr, arr + n);

    // Display the sorted array
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

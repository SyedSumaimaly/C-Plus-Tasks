#include <iostream>
#include <string>
using namespace std;

int main() {
    int numSubjects;
    string subjectName;
    float marks, totalMarks = 0;

    // Ask the user for the number of subjects
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    // Loop through each subject to input name and marks
    for (int i = 1; i <= numSubjects; i++) {
        cout << "Enter the name of subject " << i << ": ";
        cin.ignore(); // Clear the input buffer
        getline(cin, subjectName);

        cout << "Enter marks for " << subjectName << ": ";
        cin >> marks;

        totalMarks += marks; // Add marks to the total
    }

    // Display the total marks
    cout << "\nThe total marks for all subjects are: " << totalMarks << endl;

    return 0;
}

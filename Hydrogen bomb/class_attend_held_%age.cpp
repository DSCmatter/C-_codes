#include <iostream>
using namespace std;

int main() {
    int classes_held, classes_attended;
    char medical_leave;

    // Input
    cout << "Enter the total number of classes held: ";
    cin >> classes_held;

    cout << "Enter the number of classes attended: ";
    cin >> classes_attended;

    cout << "Did the student take medical leave? (Y/N): ";
    cin >> medical_leave;

    // Calculate percentage
    double attendance_percentage = (double(classes_attended) / classes_held) * 100;

    // Output
    cout << "The percentage of classes attended: " << attendance_percentage << "%" << endl;

    // Check if attendance is at least 75%
    if (attendance_percentage >= 75) {
        cout << "Congratulations! The student attended at least 75% of the classes." << endl;
    } else {
        cout << "The student did not attend at least 75% of the classes." << endl;
    }

    return 0;
}

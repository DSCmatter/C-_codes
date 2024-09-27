#include <iostream>
using namespace std;

int main() {
    const int arraySize = 5;
    int numbers[arraySize];
    
    // Input: Read five integers into the array
    cout << "Enter five integer numbers:\n";
    for (int i = 0; i < arraySize; ++i) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Calculate the sum
    int sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        sum += numbers[i];
    }

    // Display the sum
    cout << "Sum of the numbers: " << sum << endl;

    return 0;
}

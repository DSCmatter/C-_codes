#include <iostream>
using namespace std;

int main() {
    const int arraySize = 5;  
    int numbers[arraySize];   
    cout << "Enter five integer numbers:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    int greatest = numbers[0];
    int lowest = numbers[0];
    for (int i = 1; i < arraySize; ++i) {
        if (numbers[i] > greatest) {
            greatest = numbers[i];
        }
        if (numbers[i] < lowest) {
            lowest = numbers[i];
        }
    }
    
    cout << "Greatest value in the array: " << greatest << endl;
    cout << "Lowest value in the array: " << lowest << endl;
    return 0;
}
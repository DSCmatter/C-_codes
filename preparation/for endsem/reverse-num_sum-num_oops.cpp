#include <iostream>
using namespace std;

class NumberReverser {
private:
    int number;

public:
    // Constructor to initialize the number
    NumberReverser(int num) : number(num) {}

    // Function to reverse the number
    int reverseNumber() {
        int reversedNumber = 0;
        int temp = number;  // Save a copy of the original number

        while (temp > 0) {
            reversedNumber = reversedNumber * 10 + temp % 10;
            temp /= 10;
        }
        return reversedNumber;
    }

    // Function to calculate the sum of digits
    int calculateSum() {
        int sum = 0;
        int temp = reverseNumber(); // Use the reversed number

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return sum;
    }
};

int main() {
    int userInput;

    // Get user input
    cout << "Enter a number: ";
    cin >> userInput;

    // Create an instance of the NumberReverser class
    NumberReverser reverser(userInput);

    // Reverse the number
    int reversedNumber = reverser.reverseNumber();

    // Display the reversed number
    cout << "Reversed number: " << reversedNumber << endl;

    // Calculate and display the sum of digits
    int sum = reverser.calculateSum();
    cout << "Sum of digits: " << sum << endl;

    return 0;
}
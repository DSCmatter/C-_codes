// Write a program to do swapping of two elements using function with two pointers as
// arguments
#include <iostream>
using namespace std;
void swapElements(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int main() {
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << endl;
    swapElements(&num1, &num2);
    cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << endl;
    return 0;
}
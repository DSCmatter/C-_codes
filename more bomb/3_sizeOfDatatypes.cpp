// Write a in C++ program to find the size of fundamental data types.

#include <iostream>
using namespace std;

int main(){
    cout << "To find the size of data types: ";
    cout << "Size of char is: " << sizeof(char) << "bytes \n";
    cout << "Size of int is: " << sizeof(int) << "bytes \n";
    cout << "Size of short is: " << sizeof(short) << "bytes \n";
    cout << "Size of  is: " << sizeof(long) << "bytes \n";
    cout << "Size of bool is: " << sizeof(bool) << "bytes \n";
    cout << "Size of char float: " << sizeof(float) << "bytes \n";
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    // && (AND) = check if two conditions are true
    // || (OR) = check if at least one of two conditions is true
    // ! (NOT) = reverses the logical state of its operand 
    // Meaning if a condition is false it becomes true 

    int temp;
    bool sunny = false;

    cout << "Enter the temperature in Celcius: ";
    cin >> temp;
    /*
    if(temp > 0 && temp < 30){
        cout << "The temperature is good!";
    }
    else{
        cout << "The temperatue is bad!";
    }
    */

    //Another way 

    if(temp <= 0 || temp >= 30){
        cout << "The temperature is bad!\n";
    }
    else{
        cout << "The temperatue is good!\n";
    }

    if(!sunny){ //No need to write if(sunny==true)
        cout << "It is cloudy outside";
    }
    else{
        cout << "It is sunny outside";
    }

    return 0;
}
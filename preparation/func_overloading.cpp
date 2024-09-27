#include <iostream>
using namespace std;

// function overloading: When a function name is 
// overloaded with different jobs it is called Function Overloading. 

int sum(int a, int b){
    cout << "Using function with two arguments" << endl;
    return a+b;
}
int sum(int a, int b, int c){
    cout << "Using function with three arguments" << endl;
    return a+b+c;
}
int main(){
    cout << "The sum of 3 and 6 is: " << sum(3,6) << endl;
    cout << "The sum of 3 and 6 is: " << sum(3,7,6);
    return 0;
}
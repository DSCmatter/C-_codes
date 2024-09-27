#include <iostream>

double sum(double a, double b);

int main(){

    double a = 5;
    double b = 4;

    double result = sum(a, b);

    std::cout << "Sum of two nos is: " << result << "\n";

    return 0;
}

double sum(double a, double b){
    return (a + b);
}
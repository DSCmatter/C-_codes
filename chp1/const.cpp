#include <iostream>

int main(){
    // The const keyword specifies that a variable's value is constant
    // tells the compiler to prevent anything from modifying it
    // (read-only)

    const double PI = 3.14159;
    //PI = 420.69; This will cause an error
    const int LIGHT_SPEED = 299792458;
    const int WIDTH = 1920;
    const int WIDTH = 1080;

    /*
    double radius = 10;
    double circumference = 2 * PI * radius;

    std::cout << circumference << "cm";
    */

    return 0;
}
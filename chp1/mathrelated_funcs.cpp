#include <iostream>
#include <cmath>

int main(){
    double x = 3.99;
    double y = 4;
    double z;

    //z = std::max(x, y); //gives 4 as 4 is greater
    //z = std::min(x, y); //gives 3 as 3 is less
    //z = pow(2, 4); // 2 to the power of 3, gives 16
    //z = sqrt(9); //gives 3
    //z = abs(-3); //absolute value function
    //z= round(x); //gives 3 (rounds)
    //z = ceil(x); //gives 4 (rounds up)
    z = floor(x); //gives 3 (rounds down)

    std::cout << z;
}
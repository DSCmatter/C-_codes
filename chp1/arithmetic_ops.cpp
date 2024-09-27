#include <iostream>

// arithmetic operators = return the result of a specific
// arithmetic operation (+ - * /)

//order of precedence:
//parenthesis
//multiplication & division
//addition & substraction

int main(){

    int students = 6 - (5 + 4) * 3 / 2 ; //gives -7

    std::cout << students;

    //students = students + 1;
    //students+=1;
    //students++;

    //students = students - 2;
    //students-=2;
    //students--;

    //students = students * 2;
    //students*=2;

    //students = students / 2;
    //students/=3;

    //int remainder = students % 2;

    //std::cout << remainder;

    return 0;
}
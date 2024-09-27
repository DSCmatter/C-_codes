#include <iostream>

int main(){
    // ternary operator ?: = replacement to an if/else statement
    // condition ? expression : expression2;

    int grade = 75;
    /*
    if(grade >= 60)
    {
        std::cout << "You pass!";
    }
    else{
        std::cout << "You fail!";
    }
    */
    // ternary, parenthesis is optional

    //grade >= 60 ? std::cout << "You pass!" : std::cout << "You fail!";

    //int number = 8;
    //number % 2 == 1 ? std::cout << "ODD" : std::cout << "EVEN";

    bool hungry = true;

    //hungry ? std::cout << "You are hungry" : std::cout << "You are full";

    std::cout << (hungry ? "You are hungry" : "You are full");

    return 0;

}
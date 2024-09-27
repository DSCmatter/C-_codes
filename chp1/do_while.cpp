#include <iostream>

//do while loop = do some block of code first,
//                Then repeat again if condition is true 

int main(){

    int number;

    do{
        std::cout << "Enter a postive #: ";
        std::cin >> number;
    }while(number < 0);

    std::cout << "The # is: " << number;

    return 0;
}
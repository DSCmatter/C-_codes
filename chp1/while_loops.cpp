#include <iostream>

int main(){

    std::string name;

    while(name.empty()){ //as long this condition remains true it continues
        std::cout << "Enter your name:";
        std::getline(std::cin, name);
    }

    std::cout << "Hello " << name;


    return 0;
}
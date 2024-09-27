#include <iostream>

std::string concatStrings(std::string string_1, std::string string_2);

int main(){

    std::string firstName = "Vasant";
    std::string lastName = "Mogia";
    std::string fullName = concatStrings(firstName, lastName);

    std::cout << "Hello " << fullName;

    return 0;

}

std::string concatStrings(std::string string_1, std::string string_2){
    return string_1 + " " + string_2;
}

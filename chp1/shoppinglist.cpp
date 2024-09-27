#include <iostream>

int main(){

    int count = 0;
    char yorn;
    std::string name[50];

    do{
    std::cout << "What do you want to put in your shopping bag? ";
    std::cin >> name[count];
    std::cout << count+1 << ". " << name[count];

    std::cout << '\n' << "would you like to continue Y or N? ";
    std::cin >> yorn;

    count++;

    }while (yorn == 'Y' || yorn == 'y');

    std::cout << '\n' << "Here is your shopping list : " << '\n';

    for ( int counter = 1; counter <= count;  counter++ ){

    std::cout << counter << ". " << name[counter-1] << '\n';

    }
    
return 0;

}
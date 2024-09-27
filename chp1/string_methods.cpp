#include <iostream>
// see string class
//name.length() method 
//name.empty()
//name.clear()
//name.append()
//name.insert(index, insert)
//name.at(index) 
//name.erase(beginning index, ending index)

int main(){
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    name.erase(0, 3); //(ending index, ending index)
    std::cout << name;

    //std::cout << name.find(' ');
    
    //std::cout << name.at(1);

    /*
    name.insert(0, "@"); //insert = (index, what would you like to insert)
    std::cout << name;
    */

    /*
    name.append("@gmail.com");
    std::cout << "Your username is now " << name;
    */

    /*
    name.clear();
    std::cout << "Hello " << name; //result = Hello 
    */

    /*
    if(name.empty()){
        std::cout << "You didn't enter your name";
    }
    else{
        std::cout << "Hello " << name; //result = Hello (name)
    }
    */

    /*
    if(name.length() > 12){
        std::cout << "Your name can't be over 12 characters";
    }
    else{
        std::cout << "Welcome " << name; //result = Welcome (name)
    }
    */
    return 0;
}
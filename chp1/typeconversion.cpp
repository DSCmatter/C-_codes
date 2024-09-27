#include <iostream>

// type conversion = conversion of a value of one data type to another
// Implicit = automatic 
// Explicit = Precede value with new data type/variable               

int main(){

    //double x = (int) 3.14;
    //std::cout << x;

    //char x = 100;
    //std::cout << x; // uses ASCII table and prints 'd'

    //std::cout << (char) 100; //same as above

    int correct = 8;
    int questions = 10;
    double score = correct/(double)questions * 100;

    std::cout << score << "%";

    return 0;
}
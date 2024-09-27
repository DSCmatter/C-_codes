#include <iostream>

int main(){
    using std::cout;
    using std::string; //safer alternative to using namespaces

    string name = "Vasant";

    cout << "Hello " << name; // gives Hello Vasant


    return 0;
}
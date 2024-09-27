#include <iostream>

class MyClass {
public:
    // No explicit constructor defined
    
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    MyClass obj; // Creating an object of MyClass
    // Rest of the code
    return 0;
}

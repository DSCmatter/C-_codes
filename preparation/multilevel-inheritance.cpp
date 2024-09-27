#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class inheriting from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

// Further derived class inheriting from Dog
class Labrador : public Dog {
public:
    void color() {
        cout << "Labrador is usually golden or black" << endl;
    }
};

int main() {
    Labrador myLabrador;

    // Accessing methods from different levels of inheritance
    myLabrador.sound(); // Method from Animal class
    myLabrador.bark();  // Method from Dog class
    myLabrador.color(); // Method from Labrador class

    return 0;
}

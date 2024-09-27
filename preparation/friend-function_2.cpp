#include <iostream>

// Forward declaration of class B
class B;

// Class A declaration
class A {
private:
    int dataA;

public:
    A() : dataA(0) {}

    void setData(int value) {
        dataA = value;
    }

    // Declare friend function that can access private members of class A
    friend void addAandB(A objA, B objB);
};

// Class B declaration
class B {
private:
    int dataB;

public:
    B() : dataB(0) {}

    void setData(int value) {
        dataB = value;
    }

    // Declare friend function that can access private members of class B
    friend void addAandB(A objA, B objB);
};

// Definition of the friend function that accesses private members of A and B
void addAandB(A objA, B objB) {
    int sum = objA.dataA + objB.dataB;
    std::cout << "Sum of dataA and dataB: " << sum << std::endl;
}

int main() {
    A objA;
    B objB;

    objA.setData(5);
    objB.setData(10);

    // Call friend function with objects of A and B
    addAandB(objA, objB);

    return 0;
}

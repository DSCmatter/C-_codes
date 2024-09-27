#include <iostream>

// Base class
class Vehicle {
public:
        void start() const {
        std::cout << "Starting the vehicle\n";
    }

        void drive() const {
        std::cout << "Driving the vehicle\n";
    }
};

int main() {
    // Create objects of the base class
    Vehicle car;
    Vehicle bicycle;

    // Use a base class pointer for polymorphism
    Vehicle* vehicles[] = {&car, &bicycle};

    for (const auto& vehicle : vehicles) {
        vehicle->start();
        vehicle->drive();
        std::cout << "\n";
    }

    return 0;
}

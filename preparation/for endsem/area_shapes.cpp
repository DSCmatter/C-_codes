#include<iostream>
#include<cmath>

using namespace std;

const double PI = 3.14159265358979323846;

// Function to calculate the area of a circle
double AREA(double radius) {
    return PI * radius * radius;
}

// Function to calculate the area of a rectangle
double AREA(double length, double width) {
    return length * width;
}

// Function to calculate the area of a triangle
double AREA(double base, double height, double side1, double side2) {
    // Using Heron's formula for the area of a triangle
    double s = (base + side1 + side2) / 2;
    return sqrt(s * (s - base) * (s - side1) * (s - side2));
}

int main() {
    double radius, length, width, base, height, side1, side2;

    // Calculate the area of a circle
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "Area of the circle: " << AREA(radius) << endl;

    // Calculate the area of a rectangle
    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of the rectangle: " << AREA(length, width) << endl;

    // Calculate the area of a triangle
    cout << "Enter the base, height, and two sides of the triangle: ";
    cin >> base >> height >> side1 >> side2;
    cout << "Area of the triangle: " << AREA(base, height, side1, side2) << endl;

    return 0;
}

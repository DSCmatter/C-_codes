/*Implement a C++ class called "Rectangle" that represents a rectangle shape.
The class should have member variables for length and width, member
functions to calculate the area and perimeter, and appropriate constructors
and member functions to access the data members.*/

#include <iostream>
using namespace std;
class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle() : length(0.0), width(0.0) {}
    Rectangle(double initialLength, double initialWidth)
        : length(initialLength), width(initialWidth) {}
    void setLength(double newLength) {
        length = newLength;
    }
    void setWidth(double newWidth) {
        width = newWidth;
    }
    double getLength() const {
        return length;
    }
    double getWidth() const {
        return width;
    }
    double calculateArea() const {
        return length * width;
    }
    double calculatePerimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle myRectangle;
    myRectangle.setLength(5.0);
    myRectangle.setWidth(3.0);
    cout << "Length: " << myRectangle.getLength() << endl;
    cout << "Width: " << myRectangle.getWidth() << endl;
    cout << "Area: " << myRectangle.calculateArea() << endl;
    cout << "Perimeter: " << myRectangle.calculatePerimeter() << endl;

    return 0;
}
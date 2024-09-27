#include <iostream>
using namespace std;
class Mammals {
public:
    void display() {
        cout << "I am a mammal." << endl;
    }
};
class MarineAnimals {
public:
    void display() {
        cout << "I am a marine animal." << endl;
    }
};
class BlueWhale : public Mammals, public MarineAnimals {
public:
    void display() {
        cout << "I belong to both the categories: Mammals as well as Marine Animals." << endl;
    }
};
int main() {
    Mammals mammalObj;
    MarineAnimals marineAnimalObj;
    BlueWhale blueWhaleObj;
    cout << "1 - ";
    mammalObj.display();
    cout << "2 - ";
    marineAnimalObj.display();
    cout << "3 - ";
    blueWhaleObj.display();
    cout << "4 - ";
    blueWhaleObj.Mammals::display();
    cout << "5 - ";
    blueWhaleObj.MarineAnimals::display();

    return 0;
}
#include <iostream>
using namespace std;

class MyClass;
void displayPrivateData(const MyClass& obj);
class MyClass {
private:
    int privateData;
public:
    MyClass(int data) : privateData(data) {}
    friend void displayPrivateData(const MyClass& obj);
};

void displayPrivateData(const MyClass& obj) {
    cout << "Private Data: " << obj.privateData << endl;
}

int main() {
    MyClass myObject(42);
    displayPrivateData(myObject);
    return 0;
}
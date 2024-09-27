#include <iostream>
using namespace std;

// Base class
class Employee{
    public:
    int id;
    float salary;
        Employee(int inpId){
            id = inpId;
            salary = 34.0;
        }
        Employee(){} // default constructor
};

/* // Derived class
class {{Derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    members/methods etc...
} 
Note: 
1.default visibility mode is private
2. In Public visibility mode: Public members of the base class becomes PUBLIC members of the derived class
3. In Private visibility mode: public members of the base class becomes PRIVATE members of the derived class
4. Private members are never inherited
*/

// Creating a programmer class derived from Emplyee base class

class Programmer : public Employee{
    public:
    Programmer(int inpId){
        id = inpId;
    }
    int languageCode = 9;
    void getData(){
        cout << id << endl;
    }
};
int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    Programmer skillF(10);
    cout << skillF.languageCode <<endl;
    cout << skillF.id <<endl;
    skillF.getData();
    return 0;
}
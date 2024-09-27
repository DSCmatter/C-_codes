// using bool 

#include <iostream>
using namespace std;

int main(){
    int x = 2;
    int y = 5;
    int z = 0;

    bool result_1 = (x==2 && y==5);
    bool result_2 = (x!=5);
    bool result_3 = (x!=5 && y>=5 && x==2);
    bool result_4 = (z!=0 || x==2 && x==5);
    bool result_5 = !(y<=10);

    cout << "The value of (x==2 && y==5) is: " << result_1 << endl;
    cout << "The value of (x!=5) is: " << result_2 << endl;
    cout << "The value of (x!=5 && y>=5 && x==2) is: " << result_3 << endl;
    cout << "The value of (z!=0 || x==2 && x==5) is: " << result_4 << endl;
    cout << "The value of !(y<=10) is: " << result_5 << endl;

    return 0;
}

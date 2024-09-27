#include <iostream>
using namespace std;
class test{
    private:
    static int a;
    float x;
    
    public:
    void set_data(int x){
        a=x;
    }
    void display(){
        cout << a;
    }
};
int test::a=10;

int main(){
    test t1;
    t1.set_data(4);
    t1.display();
    return 0;
}


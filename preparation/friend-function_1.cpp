#include <iostream>
using namespace std;
class test 
{
    private:
    int a,b;
    public:
    void set_data(int x, int y)
    {
        a=x;
        b=y;
    }
    void show_data()
    {
        cout<<a<<b<<endl;
    }
    
    friend void f_test(test);
};
void f_test(test t)
{
    cout<<t.a<<endl<<t.b;
}

int main()
{
   test t1;
   t1.set_data(3,4);
   f_test(t1);
   return 0;
   //t1.show_data();
}
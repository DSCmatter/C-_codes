/*
#include <iostream>
using namespace std;

int main{
    union test{
    float a;
    int b;
    char c[20]
}
}
*/

/*
#include <iostream>
using namespace std;
struct Point{
    int x, y;
};

int main(){
    struct Point a = {0, 1};
    a.x = 20;
    cout << "x = " << a.x << ", y = " << a.y;
    return 0;
}
*/

#include <iostream>
using namespace std;
struct Point{
    int x = 0;
    int y = 1;
};
int main(){
    struct Point p1;
    cout << "x = " << p1.x << ", y = " << p1.y << endl;
    p1.y = 20;
    cout << "x = " << p1.x << ", y = " << p1.y;
    return 0; 
}

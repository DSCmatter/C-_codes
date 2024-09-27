#include <stdio.h>
void abc(){
    return 1;
}
void main(){
    int x = 0;
    x = abc();
    printf("%d", x);
}
//error compiling 
//The code you provided will result in a compilation error because the function abc() is declared to return void, 
//but you are trying to return an integer (1) from it. In C, a function declared as void means it does not return a value.
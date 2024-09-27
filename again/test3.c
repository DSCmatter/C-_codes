/*
#include <stdio.h>
int test(int);
int main(){
    int i;
    i=test(10);
    printf("%d", i);
    return 0;
}
int test (int x)
{
    return(x++);
}
*/
#include <stdio.h>
int main(){
    int Length = 0;
    char arr[] = {'a','e','i','o','u'};
    printf("Char array size is:%ld \n", sizeof(arr));
    Length = sizeof(arr)/sizeof(char);
    printf("Char array length is:%d", Length);
    return 0;
}

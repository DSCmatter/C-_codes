/*
#include <stdio.h>
int main(){
    int *p, x=4;
    p=&x;
    printf("value is %d \n", *p);
    return 0;
}
*/

#include <stdio.h>
#include <string.h>
int main(){
    struct book{
        int pages;
        char name[20];
    }xyz;
    xyz.pages=10;
    strcpy(xyz.name, "Programming");
    printf("%s=%d", xyz.name, xyz.pages);
    return 0;
}
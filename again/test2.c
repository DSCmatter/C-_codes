/*
#include <stdio.h>

int main() { 
    char code = 'K'; 
    switch (code) { 
        case 'A': 
            printf("Coffee"); 
            break; 
        case 'K': 
            printf("Tea"); 
            break; 
        default: 
            printf("Both "); 
    } 
    return 0;  //Tea
}
*/

#include <stdio.h>
int main(){
    float i = 0.5;
    if(i<0.8)
        printf("working");
    else
        printf("not working");
    return 0;
}
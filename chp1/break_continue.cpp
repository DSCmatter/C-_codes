#include <iostream>

// break = break out of a loop 
// continue = skip current iteration (if used in place of break it will skip 13)

int main(){
    for(int i = 1; i <=20; i++){
        if(i == 13){
            break;
        }
        std::cout << i << "\n";
    }
    return 0;
}
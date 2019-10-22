#include <stdio.h>
#include <stdlib.h>

//greedy
void glouton(int value){
    //1,2,5,10
    while (value){
        if (value >= 10){
            value -= 10;
            printf("10\n");
        }else if (value >= 5){
            value -= 5;
            printf("5\n");
        }else if (value >= 2){
            value -= 2;
            printf("2\n");
        }else if (value >= 1){
            value -= 1;
            printf("1\n");
        }
    }
}

int main(){
    glouton(19);
    return 0;
}

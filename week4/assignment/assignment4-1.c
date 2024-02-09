//Pakkawat Kaolim 66070503446
//Assignment 4.1 : Ten to X

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

void pop(int *st, int *top){
    for(int i = *top; i >= 0;i --){
        if(st[i] >= 10){
            printf("%c", 'A' + st[i] - 10);
        }else{
            printf("%d", st[i]);
        }
    }
}

int main(void){
    int num,base;
    scanf("%d", &num);
    scanf("%d", &base);

    int top = -1;
    int stack[MAX];

    if(base < 2 || base > 36){
        printf("invalid");
        return 0;
    }
    while(num > 0){
        top++;
        stack[top] = num % base;
        num /= base;
    }

    pop(stack, &top);
    return 0;
}
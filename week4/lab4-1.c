//Pakkawat Kaolim 66070503446
//Lab 4.1 Stack Array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1 is Push
// 2 is Pop
// 3 is Show Stack
// 4 is Exit

void Exit(){
    exit(0);
}

bool isFull(int *top, int size){
    if(*top == size - 1)
        return true;
    return false;
}

bool isEmpty(int *top){
    if(*top < 0)
        return true;
    return false;
}

void push(int *st, int *top, int size){
    if(isFull(top, size)){
        printf("Stack Overflow.");
        free(st);
        Exit();
    }

    int value;
    *top = *top + 1;
    scanf("%d", &value);
    st[*top] = value;
}

void pop(int *st, int *top){
    if(isEmpty(top)){
        printf("Stack Underflow.");
        free(st);
        Exit();
    }
    *top = *top -1;
}

void show(int *st, int *top){
    if(isEmpty(top)){
        printf("Stack is empty.");
        free(st);
        Exit();
    }

    for(int i = *top; i >= 0; i--){
        printf("%d\n", st[i]);
    }
}


int main(void){
    int size, option, top;
    top = -1;

    scanf("%d", &size);

    if(size < 1){
        printf("Please enter a positive number.");
        Exit();
    }

    int *stack = (int *)malloc(sizeof(int) * size);

    while(true){
        scanf("%d", &option);
        switch (option){
        case 1:
            push(stack, &top, size);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            show(stack, &top);
            free(stack);
            Exit();
            break;
        case 4:
            printf("Exiting...");
            free(stack);
            Exit();
            break;            
        default:
            printf("Invalid choice.");
            free(stack);
            Exit();
            break;
        }
    }
    return 0;
}
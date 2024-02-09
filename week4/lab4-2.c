//Pakkawat Kaolim 66070503446
//Lab 4.2 : Stack as Linked List

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node
{
    int value;
    struct node *next;
}Node;

void Exit(){
    exit(0);
}

Node *Create_Node(int value){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->value = value;
    NewNode->next = NULL; 
    return NewNode;
}

bool isEmpty(Node **st){
    if((*st) == NULL)
        return true;
    return false;
}


void push(Node **top){
    int value;
    scanf("%d", &value);

    Node *New_Node = Create_Node(value);
    if(*top == NULL){
        *top = New_Node;
    }else{
        New_Node->next = *top;
    }
    *top = New_Node;
}

void peek(Node **top){
    if(isEmpty(top)){
        printf("empty\n");
        return;
    }
    printf("%d\n", (*top)->value);
}

void pop(Node **top){
    if(isEmpty(top)){
        printf("empty\n");
        return;
    }
    peek(top);
    *top = (*top)->next;    
}

void show(Node **top){
    while(*top != NULL){
        printf("%d\n", (*top)->value);
        *top = (*top)->next;
    }
}

int main(void){
    char option;

    Node *top = NULL;

    while(true){
        scanf(" %c", &option);

        switch (option){
        case 'p':
            push(&top);
            break;
        case 'o':
            pop(&top);
            break;
        case 't':
            peek(&top);
            break;
        case 'e':
            printf("%d\n", isEmpty(&top));
            break;
        default:
            Exit();
            break;
        }
    }
    return 0;
}
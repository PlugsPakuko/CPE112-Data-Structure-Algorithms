//Pakkawat Kaolim 66070503446
//Lab 5.3 : Secret Code Only You and I Know

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    char ch;
    int priority;
    struct node *next;
}NODE;

typedef struct queue{
    NODE *front;
    NODE *rear;
}QUEUE;

int getPrior(char ch){
    if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O'|| ch == 'u' || ch == 'U')
        return 3;
    else if(isalpha(ch))
        return 1;
    return 2;
}

NODE *CreateNode(char ch, int prior){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->ch = ch;
    newNode->priority = prior;
    newNode->next = NULL;

    return newNode;
}

void enqueue(NODE *newNode, QUEUE *Nqueue){
    if(Nqueue->front == NULL && Nqueue->rear == NULL){
        Nqueue->front = newNode;
        Nqueue->rear = newNode;
    }else{
        Nqueue->rear->next = newNode;
        Nqueue->rear = newNode;
    }
}

char Dequeue(QUEUE *Nqueue){
    NODE *Temp = Nqueue->front;
    char ch = Nqueue->front->ch;
    Nqueue->front = Nqueue->front->next;
    free(Temp);
    return ch;
}

QUEUE *GetCode(char *string, int Priority){
    QUEUE* Nqueue = (QUEUE *)malloc(sizeof(QUEUE));
    Nqueue->front = NULL;
    Nqueue->rear = NULL;

    while(*string){
        int prior = getPrior(*string);
        if(prior == Priority){
            NODE *newNode = CreateNode(*string, prior);
            enqueue(newNode, Nqueue);
        }
        string++;
    }

    return Nqueue;
}

void PrintQueue(QUEUE *Nqueue){
    if(Nqueue->front == NULL)
        return ;
    NODE *cur = Nqueue->front;
    while (cur != NULL){
        printf("%c", cur->ch);
        cur = cur->next;
    }
    
}
int main(void){
    char *string = (char *)malloc(sizeof(char) * 1001);
    scanf(" %[^\n]s", string);

    QUEUE *FirstQ = GetCode(string, 1);
    QUEUE *SecondQ = GetCode(string, 2);
    QUEUE *ThirdQ = GetCode(string, 3);
    PrintQueue(ThirdQ);
    PrintQueue(SecondQ);
    PrintQueue(FirstQ);
    
    return 0;
}
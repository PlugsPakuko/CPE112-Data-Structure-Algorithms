//Problem 2: Palindrome Creator
//66070503446 Pakkawat Kaolim
//Code for genearte palindrome string from user input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char ch;
    struct node* next;
}Node;

typedef struct STACK{
    Node *top;
}stack;

//O(1)
// create new node of element
Node *Create_Node(char text){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->ch = text;
    NewNode->next = NULL; 
    return NewNode;
}

//O(1)
//push element to top of the stack
void push(stack *ST, char ch){
    Node *New_Node = Create_Node(ch);
    if(ST == NULL){
        ST->top = New_Node;
    }else{
        New_Node->next = ST->top;
        ST->top = New_Node;
    }
}

//O(1)
//pop top element and return its value
char pop(stack *ST){
    char res;
    if(ST->top == NULL){
        res = '\0';
    }else{
        res = ST->top->ch;
        ST->top = ST->top->next;
    }
    
    return res;
}

int isPalindrome(char *ori, char *rev, int size){
    int count = 0;
    while(ori[count] && rev[size - count - 1]){
        if(rev[size - count - 1] != ori[count])
            return 0;
        count++;
    }
    return 1;
}

//O(N)
int main(void){
    char *text;
    char *text_rev;
    int i, count = 0;;

    text = (char *)malloc(sizeof(char) * 10000001);
    text_rev = (char *)malloc(sizeof(char) * 10000001);
    stack *ST = (stack *)malloc(sizeof(stack));
    ST->top = NULL;

    scanf("%[^\n]s ", text);
    i = strlen(text);
    strncpy(text_rev,text,i);
    while(text[count]){
        push(ST, text[count]);
        count++;
    }

    printf("%s",text);
    if(isPalindrome(text,text_rev,i)){
        return 0;
    }

    
    char prev_ch = pop(ST); //o


    Node *cur = ST->top; //l
    Node *next = NULL;

    if(cur != NULL)
        next = cur->next; //o

    while(cur != NULL && next != NULL && ((prev_ch == next->ch) || (cur->ch == prev_ch))){
        if(prev_ch == next->ch){
            prev_ch = next->ch;
            cur = next->next;
            if(next != NULL)
                next = cur->next;
        }else{
            prev_ch = cur->ch;
            cur = next;
            if(next != NULL)
                next = cur->next;
        }
    }

    while(cur != NULL){
        printf("%c", cur->ch);
        cur = cur->next;
    }

    return 0;
}

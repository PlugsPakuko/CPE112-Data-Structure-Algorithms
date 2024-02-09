//Pakkawat Kaolim 66070503446 
//Assignment 4.3 : Parenthesis Checker

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct node {
    char paren;
    struct node* next;
} Node;

bool isEmpty(Node* parenStack) {
    return parenStack == NULL;
}

bool isParen(char c) {
    char paren[] = {'(', ')', '{', '}', '[', ']'};
    for (int i = 0; i < 6; i++) {
        if (paren[i] == c)
            return true;
    }
    return false;
}

bool Matching(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

void push(Node** Top, char string) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->paren = string;
    NewNode->next = *Top;
    *Top = NewNode;
}

void pop(Node** Top) {
    if (*Top == NULL)
        return;
    Node* temp = *Top;
    *Top = (*Top)->next;
    free(temp);
}

Node* GetParenStack(char* string) {
    Node* Top = NULL;
    char curPar = '\0';

    while (*string) {
        if (isParen(*string)) {
            if (curPar != '\0' && Matching(curPar, *string)) {
                pop(&Top);
                if(isEmpty(Top))
                    curPar ='\0';
                else
                    curPar = Top->paren;
            } else {
                push(&Top, *string);
                curPar = *string; 
            }
        }
        string++;
    }
    return Top;
}

int main(void) {
    char string[MAX];
    scanf("%s", string);
    Node* Stack = GetParenStack(string);

    if (isEmpty(Stack))
        printf("The string is balanced");
    else
        printf("The string is not balanced");

    return 0;
}

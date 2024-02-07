//Pakkawat Kaolim 66070503446  
//Lab 3.5 : Circular Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
} node;

void Traverse(node *start) {
    node *ptr = start;
    if(start == NULL){
        return;
    }
    do{
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }while (ptr != start);
}

node *New_Node(int value){
    node *New_Node = (node *)malloc(sizeof(node));
    New_Node->val = value;
    New_Node->next = NULL;
    return New_Node;
}

void ADD(node **src){
    int num;
    scanf("%d", &num);
    node *new_node = New_Node(num);

    if(*src == NULL){
        *src = new_node;
        (*src)->next = *src;
        return;
    }

    node *ptr = *src;
    while(ptr->next != *src){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = *src;  
}


void DEL(node **src) {
    node *ptr = *src;
    node *pre_ptr = NULL;
    int num;
    scanf("%d", &num);

    if (ptr == NULL) {
        return;
    }

    //1st index
    if (ptr->val == num) {
        if(ptr->next == *src){
            *src = NULL;
        }else{
            while(ptr->next != *src){
                ptr = ptr->next;
            }
            ptr->next = (*src)->next;
            *src = (*src)->next;
        }
        return;
    }

    while (ptr->next != *src && ptr->val != num) {
        pre_ptr = ptr;
        ptr = ptr->next;
    }

    if (ptr->val == num){
        if(ptr->next == *src)
            pre_ptr->next = *src;
        else{
            pre_ptr->next = ptr->next;
        }
    }
}


int main(void) {
    node *head = NULL;
    char choice;
    do {
        scanf(" %c", &choice);
        if (choice == 'I') {
            ADD(&head);
        }else if (choice == 'D') {
            DEL(&head);
        }else {
            break;
        }
    } while (choice == 'I' || choice == 'D');

    if(head == NULL){
        printf("Empty");
    }else{
        Traverse(head);
    }
    return 0;
}
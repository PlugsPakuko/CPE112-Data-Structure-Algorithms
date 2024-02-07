//Pakkawat Kaolim 66070503446  
//Lab 3.4 : Linked List that can Go Back

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
} node;

void Traverse(node *start) {
    node *ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

void TraverseB(node *tail) {
    node *ptr = tail;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->prev;
    }
}

node *New_Node(int value){
    node *New_Node = (node *)malloc(sizeof(node));
    New_Node->val = value;
    New_Node->next = NULL;
    New_Node->prev = NULL;
    return New_Node;
}

void ADD(node **src){
    int num;
    scanf("%d", &num);
    node *new_node = New_Node(num);

    if(*src == NULL){
        *src = new_node;
        return;
    }

    node *ptr = *src;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
}

void SCH(node** src) {
    node* ptr = *src;
    int num;
    scanf("%d", &num);

    if (*src == NULL) {
        printf("none\n");
        return;
    }

    while (ptr->next != NULL && ptr->val != num) {
        ptr = ptr->next;
    }

    if (ptr->val == num) {
        if (ptr->next == NULL && ptr->prev ==NULL) {
            printf("NULL NULL\n");
        } else if(ptr->next == NULL){
            printf("%d NULL\n", ptr->prev->val);
        } else if(ptr->prev == NULL){
            printf("NULL %d\n", ptr->next->val);
        } else{
            printf("%d %d\n", ptr->prev->val, ptr->next->val);
        }
    } else {
        printf("none\n");
    }
}

void DEL(node **src) {
    node *ptr = *src;
    node *pre_ptr = NULL;
    int num;
    scanf("%d", &num);

    if (ptr == NULL) {
        return;
    }

    if (ptr->val == num) {
        *src = ptr->next;
        if (ptr->next != NULL) {
            ptr->next->prev = NULL;
        }
        return;
    }

    while (ptr != NULL && ptr->val != num) {
        pre_ptr = ptr;
        ptr = ptr->next;
    }

    if (ptr != NULL) {
        pre_ptr->next = ptr->next;
        if (ptr->next != NULL) {
            ptr->next->prev = pre_ptr;
        }
    }
}


int main(void) {
    node *head = NULL;
    node *tail = NULL;
    char choice[4];
    do {
        scanf("%s", choice);
        if (strcmp(choice,"ADD") == 0) {
            ADD(&head);
        }else if (strcmp(choice,"SCH") == 0) {
            SCH(&head);
        }else if(strcmp(choice,"DEL") == 0){
            DEL(&head);
        }else {
            break;
        }
    } while ( strcmp(choice,"ADD") == 0 || strcmp(choice,"SCH") == 0 || strcmp(choice,"DEL") == 0);

    if(head == NULL){
        printf("none\nnone");
    }else{
        node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        tail = ptr;
        Traverse(head);
        printf("\n");
        TraverseB(tail);
    }
    return 0;
}
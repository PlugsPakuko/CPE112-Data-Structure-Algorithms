//Pakkawat Kaolim 66070503446
//Linked List Insertion

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

void Traverse(node *start){
    node* ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    
}

void Insert_Begin(node **src, node *insert){
    insert->next = *src;
    *src = insert;
}

void Insert_End(node **src, node *insert){
    if(*src == NULL){
        *src = insert;
        return ;
    }

    node *ptr;
    ptr = *src;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = insert;
    insert->next = NULL;
}

int main(void){
    int n;
    scanf("%d", &n);


    int mode;
    scanf("%d", &mode);

    if(n < 1 || (mode != 1 && mode != 2)){
        printf("Invalid");
        return 0;
    }

    node *head = NULL;
    for(int i = 0; i < n; i++){
        int val;
        node *new_node = (node *)malloc(sizeof(node));
        scanf("%d", &val);
        new_node->val = val;
        new_node->next = NULL;

        if(mode == 1){
            Insert_Begin(&head, new_node);
        }else{
            Insert_End(&head, new_node);
        }
    }
    Traverse(head);
    return 0;
}
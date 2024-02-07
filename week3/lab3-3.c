//Pakkawat Kaolim 66070503446  
//Lab 3.3 : Where to Delete ?

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

void Traverse(node *start) {
    node *ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

node* del_f(node *src){
    //if src is empty || only 1 element
    if (src == NULL || src->next == NULL)
        return NULL;
    src = src->next;
    return src;
}

node* del_l(node *src){
    //if src is empty || only 1 element
    if (src == NULL || src->next == NULL)
        return NULL;

    node *ptr = src;
    while(ptr->next->next != NULL)
        ptr = ptr->next;
    ptr->next = NULL;
    return src;
}

node* del_n(node *src){
    int num;
    scanf("%d", &num);

    if(src == NULL)
        return NULL;

    //if num is at first pos
    if(src->val == num){
        src = src->next;
        return src;
    }

    node *ptr = src;
    node *pre_ptr = NULL;

    while(ptr->val != num && ptr->next != NULL){
        pre_ptr = ptr;
        ptr = ptr->next;
    }

    if(ptr->val == num){
        // at last pos
        if(ptr->next == NULL){
            pre_ptr->next = NULL;
        }else{
            pre_ptr->next = ptr->next;
        }
    }

    return src;
}

int main(void) {
    int n;
    scanf("%d", &n);

    if (n < 1) {
        printf("none");
        return 0;
    }

    node *head = NULL;
    node *ptr = head;
    for (int i = 0; i < n; i++) {
        int val;
        node *new_node = (node *)malloc(sizeof(node));
        scanf("%d", &val);
        new_node->val = val;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            ptr = head;
        } else {
            ptr->next = new_node;
            ptr = new_node;
        }
    }

    char choice;
    do {
        scanf(" %c", &choice);
        if (choice == 'F') {
           head = del_f(head);
        } else if (choice == 'N') {
            head = del_n(head);
        }else if(choice == 'L'){
            head = del_l(head);
        }else {
            break;
        }
    } while (choice == 'F' || choice == 'N' || choice == 'L');

    if(head == NULL){
        printf("none");
    }else{
        Traverse(head);
    }
    return 0;
}
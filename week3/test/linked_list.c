#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

void Traverse(Node *src){
    Node *ptr = src;
    while (ptr != NULL){
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
    
}

Node* Create_Node(int value){
    Node *New_Node = (Node *)malloc(sizeof(Node));
    New_Node->value = value;
    New_Node->next = NULL;
    return New_Node; 
}

void Insert_Node(Node **src ,Node *insert, int index){
    if(index == 0){
        insert->next = *src;
        *src = insert;
        return;
    }

    Node *ptr = *src;
    for(int i = 0; i < index-1; i++){
        ptr = ptr->next;
    }
    insert->next = ptr->next;
    ptr->next = insert;
}

void Delete_Node(Node *delete, Node *src){
    if(src == delete){
        src->value = (src->next)->value;
        src->next = (src->next)->next;
        return ;
    }

    Node *ptr = src;
    
    while (ptr->next != delete && ptr->next != NULL){
        ptr = ptr->next;
    }

    if(ptr->next != NULL){
        Node *skip_ptr = ptr;
        skip_ptr = (ptr->next)->next;
        ptr->next = skip_ptr;
        free(delete);
    }else{
        printf("Node Not in list");
    }
}

int main(void){
    Node *head = Create_Node(1);
    Node *one = Create_Node(2);
    Node *tail = Create_Node(5);

    Node *new = Create_Node(16);

    head->next = one;
    one->next = tail;
    tail->next = NULL;
    printf("Ori: ");
    Traverse(head);
    printf("Insert: ");
    Insert_Node(&head,new,0);
    Traverse(head);
    printf("Del: ");
    Delete_Node(tail,head);
    Traverse(head);


    return 0;
    


}



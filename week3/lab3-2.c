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

node* InsertAfter(node *src) {
    node *ptr = src;
    int value, where;
    scanf("%d %d", &where, &value);

    while (ptr->val != where && ptr->next != NULL) {
        ptr = ptr->next;
    }

    if (ptr == NULL)
        return src;
    else if(ptr->val == where){
        node *new_node = (node *)malloc(sizeof(node));
        new_node->val = value;
        new_node->next = ptr->next;
        ptr->next = new_node;
    }

    return src;
}

node* InsertBefore(node *src) {
    int value, where;
    scanf("%d %d", &where, &value);

    if (src->val == where) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->val = value;
        new_node->next = src;
        return new_node;  // Updated here
    }

    node *ptr = src;
    while (ptr->next != NULL && ptr->next->val != where) {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
        return src;

    node *new_node = (node *)malloc(sizeof(node));
    new_node->val = value;
    new_node->next = ptr->next;
    ptr->next = new_node;
    return src;
}

int main(void) {
    int n;
    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid");
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
        if (choice == 'A') {
            head = InsertAfter(head);
        } else if (choice == 'B') {
            head = InsertBefore(head);  
        } else {
            break;
        }
    } while (choice == 'A' || choice == 'B');

    Traverse(head);
    return 0;
}

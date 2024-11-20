//Pakkawat Kaolim 66070503446
//Thanakorn Thavornlertprasert 66070503426
//Cicular Queue Linkedlist
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    }

    struct Node* temp = front;
    int value = temp->data;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }

    free(temp);
    return value;
}

void printQ() {
    printf("\nQueue: ");
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* current = front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main(void) {
    int choice;
    while (1) {
        printf("\nInput choice\n 1. enqueue\n 2. dequeue\n 3. printQ\n Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int value;
            printf("Insert Value: ");
            scanf(" %d", &value);
            enqueue(value);
        } else if (choice == 2) {
            int state = dequeue();
            if (state != -1)
                printf("Dequeued %d from the queue\n", state);
        } else if (choice == 3) {
            printQ();
        } else {
            break;
        }
    }
    struct Node* current = front;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

// Pakkawat Kaolim 66070503446
// Lab 5.2 : When Will it Be My Turn???

#include <stdio.h>

int front = -1, rear = -1;

void enqueue(int value, int Queue[], int MAX) {
    if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
        printf("Queue is full!!\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        Queue[front] = value;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
        Queue[rear] = value;
    } else {
        rear += 1;
        Queue[rear] = value;
    }
}

int dequeue(int Queue[], int MAX) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty!!\n");
        return -1;
    }

    int value = Queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        if (front == MAX - 1)
            front = 0;
        else
            front += 1;
    }
    return value;
}

void printQ(int Queue[], int MAX) {
    if (rear == -1 && front == -1){
        printf("Queue is empty!!\n");
        return ;
    }

    printf("Front: %d\nItems: ", front);
    if (rear < front) {
        for (int i = front; i < MAX; i++) {
            printf("%d ", Queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
    }
    printf("\nRear: %d\n", rear);

}

int main(void) {
    int MAX;
    scanf("%d", &MAX);
    if (MAX < 1 || MAX > 10)
        return 0;
    
    int Queue[MAX];
    char choice;

    while (1) {
        scanf(" %c", &choice);

        if (choice == 'I') {
            int value;
            scanf("%d", &value);
            enqueue(value, Queue, MAX);
        } else if (choice == 'D') {
            int state = dequeue(Queue, MAX);
            if (state != -1)
                printf("%d\n", state);
        } else if (choice == 'S') {
            printQ(Queue, MAX);
        } else if (choice == 'E'){
            break;
        }
    }

    return 0;
}

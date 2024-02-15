//Pakkawat Kaolim 66070503446
//Thanakorn Thavornlertprasert 66070503426
//Cicular Queue
#include <stdio.h>

#define MAX 5
int front = -1, rear = -1;

void enqueue(int value, int Queue[]){

    if(front == 0 && rear == MAX - 1){
        printf("\nOVERFLOW\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        Queue[front] = value;
    }else if(rear == MAX - 1 && front != 0){
        rear = 0;
        Queue[rear] = value;
    }else{
        rear += 1;
        Queue[rear] = value;
    }
}

int dequeue(int Queue[]){
    if(front == -1 && rear == -1){
        printf("\nUNDERFLOW\n");
        return -1;
    }

    int value = Queue[front];
    if(front == rear){
        front = rear = -1;
    }else{
        if(front == MAX - 1)
            front = 0;
        else
            front += 1;    
    }
    return value;
        
}

void printQ(int Queue[]){
    printf("\nFront: %d\nRear: %d\nQueue: ", front, rear);
    if(rear == -1 && front == -1)
        printf("Queue is empty\n");
    else if(rear < front){
        for(int i = front; i < MAX; i++){
            printf("%d ", Queue[i]);
        }
        for(int i = 0; i <= rear; i++){
            printf("%d ", Queue[i]);
        }
    }else{
        for(int i = front; i <= rear; i++){
            printf("%d ", Queue[i]);
        }
    }
    printf("\n");
}

int main(void){
    int Queue[MAX];
    int choice;
    while(1){
        printf("\nInput choice\n 1. enqueue\n 2. dequeue\n 3. printQ\n Your choice: ");
        scanf("%d", &choice);
        printf("============================================\n");

        if(choice == 1){
            int value;
            printf("Insert Value: ");
            scanf(" %d", &value);
            enqueue(value, Queue);
        }else if (choice == 2){
            int state = dequeue(Queue);
            if(state != -1)
                printf("dequeued %d from queue\n", state);
        }else if(choice == 3){
            printQ(Queue);
        }else{
            break;
        }

    }

    return 0;

}
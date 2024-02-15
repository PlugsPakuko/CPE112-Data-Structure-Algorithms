//Pakkawat Kaolim 66070503446
//Thanakorn Thavornlertprasert 66070503426
//Cicular Queue
#include <stdio.h>

#define MAX 5

void enqueue(int value, int arr[], int *front, int *rear){

    if(*front == 0 && *rear == MAX - 1){
        printf("\nOVERFLOW\n");
    }
    else if(*front == -1 && *rear == -1){
        *front = *rear = 0;
        arr[*front] = value;
    }else if(*rear == MAX - 1 && *front != 0){
        *rear = 0;
        arr[*rear] = value;
    }else{
        *rear += 1;
        arr[*rear] = value;
    }
}

int dequeue(int arr[], int *front, int *rear){
    if(*front == -1 && *rear == -1){
        printf("\nUNDERFLOW\n");
        return -1;
    }

    int value = arr[*front];
    if(*front == *rear){
        *front = *rear = -1;
    }else{
        if(*front == MAX - 1)
            *front = 0;
        else
            *front += 1;    
    }
    return value;
        
}

void printQ(int arr[], int *front, int *rear){
    printf("\nFront: %d\nRear: %d\nQueue: ", *front, *rear);
    if(*rear == -1 && *front == -1)
        printf("Queue is empty\n");
    else if(*rear < *front){
        for(int i = *front; i < MAX; i++){
            printf("%d ", arr[i]);
        }
        for(int i = 0; i <= *rear; i++){
            printf("%d ", arr[i]);
        }
    }else{
        for(int i = *front; i <= *rear; i++){
            printf("%d ", arr[i]);
        }
    }
}

int main(void){
    int arr[MAX];
    int front = -1, rear = -1;
    int choice;
    while(1){
        printf("\nInput choice\n 1. enqueue\n 2. dequeue\n 3. printQ\n ");
        scanf("%d", &choice);

        if(choice == 1){
            int value;
            printf("Insert Value: ");
            scanf(" %d", &value);
            enqueue(value, arr, &front, &rear);
        }else if (choice == 2){
            dequeue(arr, &front, &rear);
        }else if(choice == 3){
            printQ(arr, &front, &rear);
        }else{
            break;
        }

    }

    return 0;

}
//PAKKAWAT KAOLIM 66070503446
//Lab 8.1 : Minheap

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int arr[], int size, int i) {
    int smallest = i, leftChild = 2 * i + 1, rightChild = 2 * i + 2;

    if (leftChild < size && arr[leftChild] < arr[smallest])
        smallest = leftChild;
    if (rightChild < size && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        Heapify(arr, size, smallest);
    }
}

void insertion(int arr[], int *size, int value) {
    if(*size >= MAX_SIZE)
        return ;

    //insert as last element
    int i = (*size)++;
    arr[i] = value;
    
    //rewind check satisfy BST or not
    while (i >= 0 && arr[i] < arr[(i - 1) / 2]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deletion(int arr[], int *size, int value) {
    int i = 0;
    for (; i < *size; i++) {
        if (arr[i] == value)
            break;
    }

    if (i == *size) //not found
        return;
    
    //swap deleted node with last element
    swap(&arr[i], &arr[--(*size)]);

    //heapify backward
    for(i = ((*size) / 2) - 1; i >= 0 ; i--)
        Heapify(arr, *size, i);
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], size = 0, data;
    char command[10];

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "INSERT") == 0) {
            while (scanf(" %d", &data) == 1)
                insertion(arr, &size, data);
        } else if (strcmp(command, "DELETE") == 0) {
            while(scanf(" %d", &data) == 1);
                deletion(arr, &size, data);
        } else if (strcmp(command, "PRINT") == 0) {
            printArr(arr, size);
        } else if (strcmp(command, "EXIT") == 0) {
            break;
        } else {
            printf("INVALID\n");
        }
    }

    return 0;
}
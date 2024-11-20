#include <stdio.h>

#define MAX_SIZE 1000

void swap(int *num1, int *num2){
    int *temp = *num1;
    *num1 = *num2;
    *num2 = *temp;
}

void MinHeapify(int *arr, int i){
    int samllest = i, Right = samllest*2 + 1, Left = samllest*2;

    if(samllest < i && arr[samllest] > arr[Right])
        samllest = Right;
    if(samllest < i && arr[samllest] > arr[Left])
        samllest = Left;

    if(samllest != i){
        swap(&arr[samllest], &arr[i]);
        MinHeapify(arr, samllest);
    }

}

void insert(int *Heap, int *size, int data){
    if(*size > MAX_SIZE)
        return; //over
    
    Heap[(*size)++] = data;

    for (int i = *size / 2 - 1; i >= 0; i--){
      MinHeapify(Heap, i);
    }
}

int main(void){
    int Heap[MAX_SIZE], size = 0;
}
//Methat Laosuksakul 66070503479

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heapify(int arr[], int size, int i){

  int smallest = i, left = 2 * i + 1, right = 2 * i + 2;

  if(left < size && arr[left] < arr[smallest])
    smallest = left;
  if(right < size && arr[right] < arr[smallest])
    smallest = right;

  if(smallest != i){
    int temp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = temp;
    heapify(arr, size, smallest);
  }
}

void insert(int arr[], int *size, int key){
  if(*size == 0){
    arr[0] = key;
    (*size)++;
  }else{
    int i = (*size)++;
    arr[i] = key;
    while(i != 0 && arr[(i - 1) / 2] > arr[i]){
      int temp = arr[i];
      arr[i] = arr[(i - 1) / 2];
      arr[(i - 1) / 2] = temp;
      i = (i - 1) / 2;
    }
  }
}

void Delete(int arr[], int *size, int key){
  int i;
  
  for(i = 0; i < *size; i++){
    if(arr[i] == key){
      break;
    }
  }
  if(i == *size){ //key not found
    return;
  }
  arr[i] = arr[*size - 1];
  (*size)--;
  for(i = ((*size) / 2) - 1; i >= 0; i--){
    heapify(arr, *size, i);
  }
}

void print(int arr[], int size){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {
  char command[10];
  int key;
  int arr[1000000];
  int size = 0;

  while(1){
    scanf("%s", command);
    if(strcmp(command, "INSERT") == 0){
      while(scanf("%d", &key) == 1){
        insert(arr, &size, key);
      }
    }
    if(strcmp(command, "DELETE") == 0){
      while(scanf("%d", &key) == 1){
        Delete(arr, &size, key);
      }
    }
    if(strcmp(command, "PRINT") == 0){
      print(arr, size);
    }
    if(strcmp(command, "EXIT") == 0){
      break;
    }
  }
  return 0;
}
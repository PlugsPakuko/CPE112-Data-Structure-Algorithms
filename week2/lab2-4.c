//PAKKAWAT KAOLIM 66070503446
//Array Manipulation

#include <stdio.h>
#include <stdlib.h>


void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* insertArray(int* arr, int *size, int index, int value){
    *size+=1;
    arr = realloc(arr, sizeof(int) * (*size));

    for (int i = *size - 1; i > index; i--){
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    printArray(arr, *size);
    return arr;
}

int* deleteArray(int* arr, int *size, int index){
    if(index >= *size || index < 0){
        printf("Index out of bounds\n");
        return arr;
    }
    *size-=1;

    for(int i = index; i < *size; i++){
        arr[i] = arr[i+1];
    }
    arr = realloc(arr, sizeof(int) * (*size));
    printArray(arr, *size);
    return arr;
}

int* mergeArray(int* arr1, int *size1, int* arr2, int size2) {
    int* new_arr = (int*)malloc(sizeof(int) * (*size1 + size2));

    for(int i = 0; i < *size1; i++){
        new_arr[i] = arr1[i];
    }
    for(int i = *size1; i < *size1 + size2; i++){
        new_arr[i] = arr2[i - *size1];
    }

    *size1 += size2;
    printArray(new_arr, *size1);
    return new_arr;
}


int main(void){
    int n1,n2;

    scanf("%d", &n1);
    int *arr1 = (int *)malloc(sizeof(int) * n1);
    for(int i = 0; i < n1; i++){
        scanf("%d ", &arr1[i]);
    }

    scanf("%d", &n2);
    int *arr2 = (int *)malloc(sizeof(int) * n2);
    for(int i = 0; i < n2; i++){
        scanf("%d ", &arr2[i]);
    }
    
    int modify_index, modify_value, delete_index;
    scanf("%d %d %d", &modify_index, &modify_value, &delete_index);

    arr1 = insertArray(arr1, &n1, modify_index, modify_value);
    arr1 = deleteArray(arr1, &n1, delete_index);
    arr1 = mergeArray(arr1, &n1, arr2, n2);

    free(arr1);
    free(arr2);
    return 0;
}
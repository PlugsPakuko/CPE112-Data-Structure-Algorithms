#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    // Choose the pivot as the middle element
    int pivotIndex = low + (high - low) / 2;
    int pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[high]); // Move pivot to end

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Move pivot to its correct place
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int* getInput(char* FileName, int* size) {
    FILE *file = fopen(FileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int capacity = 10; // initial capacity of array
    int *arr = (int*)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int num;
    int count = 0;
    while (fscanf(file, "%d,", &num) == 1) {
        if (count == capacity) {
            capacity *= 2; // double the capacity
            arr = (int*)realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                printf("Memory allocation failed.\n");
                exit(1);
            }
        }
        arr[count++] = num;
    }

    fclose(file);
    *size = count;
    return arr;
}

int main(int argc, char **argv) {

    if(argc < 2){
        printf("Input file!!\n");
        exit(1);
    }

    char *fn = argv[1];
    int size;
    int *arr = getInput(fn, &size);

    if (arr == NULL) {
        printf("Failed to read input.\n");
        return 1;
    }

    printf("FILE: %s\nsize: %d\n", fn, size);

    clock_t start, end;
    double timeU;

    // Sort and print the array using each sorting algorithm
    int arr_copy[size];

    // Quick Sort

    memcpy(arr_copy, arr, size * sizeof(int));
    start = clock();
    quickSort(arr_copy, 0, size-1);
    end = clock();
    timeU = (double)(end - start)/CLOCKS_PER_SEC;

    // printf("Quick sorted array: \n");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", arr_copy[i]);
    // }
    printf("\nTime usage: %lf sec\n", timeU);
    printf("Auxiliary space usage: %zu bytes\n", 4);
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}

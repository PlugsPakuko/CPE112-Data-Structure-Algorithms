#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

size_t total_memory_allocated = 0;

void* my_malloc(size_t size) {
    total_memory_allocated += size;
    return malloc(size);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int size) {
    int i, j, min;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)my_malloc(n1 * sizeof(int));
    int *R = (int *)my_malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

size_t measureAuxiliarySpaceBubbleSort() {
    return sizeof(int); // Temporary variable for swapping
}

size_t measureAuxiliarySpaceInsertionSort() {
    return sizeof(int); // Temporary variable for key
}

size_t measureAuxiliarySpaceSelectionSort() {
    return sizeof(int); // Temporary variable for swapping
}

size_t measureAuxiliarySpaceMergeSort(int size) {
    return size * sizeof(int); // Temporary arrays L and R
}

size_t measureAuxiliarySpaceQuickSort() {
    return sizeof(int); // Temporary variables for partitioning
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

    // Bubble Sort
    memcpy(arr_copy, arr, size * sizeof(int));
    start = clock();
    bubble_sort(arr_copy, size);
    end = clock();
    
    timeU = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Bubble sorted array:\n");
    printf("Time usage: %lf sec\n", timeU);
    printf("Auxiliary space usage: %zu bytes\n", measureAuxiliarySpaceBubbleSort());

    printf("\n");

    // Insertion Sort
    memcpy(arr_copy, arr, size * sizeof(int));

    start = clock();
    insertion_sort(arr_copy, size);
    end = clock();
    timeU = (double)(end - start)/CLOCKS_PER_SEC;

    printf("Insertion sorted array:\n");
    printf("Time usage: %lf sec\n", timeU);
    printf("Auxiliary space usage: %zu bytes\n", measureAuxiliarySpaceInsertionSort());
    printf("\n");

    // Selection Sort
    memcpy(arr_copy, arr, size * sizeof(int));
    start = clock();
    selection_sort(arr_copy, size);
    end = clock();
    timeU = (double)(end - start)/CLOCKS_PER_SEC;

    printf("Selection sorted array: \n");
    printf("Time usage: %lf sec\n", timeU);
    printf("Auxiliary space usage: %zu bytes\n", measureAuxiliarySpaceSelectionSort());
    printf("\n");

    // Merge Sort
    memcpy(arr_copy, arr, size * sizeof(int));
    start = clock();
    mergeSort(arr_copy, 0, size - 1);
    end = clock();
    timeU = (double)(end - start)/CLOCKS_PER_SEC;

    printf("Merge sorted array: \n");
    printf("Time usage: %lf sec\n", timeU);
    printf("Auxiliary space usage: %d bytes\n", total_memory_allocated);
    printf("\n");

    // Quick Sort

    memcpy(arr_copy, arr, size * sizeof(int));
    start = clock();
    quickSort(arr_copy, 0, size-1);
    end = clock();
    timeU = (double)(end - start)/CLOCKS_PER_SEC;

    printf("Quick sorted array: \n");
    printf("Time usage: %lf sec\n", timeU);
    printf("Auxiliary space usage: %zu bytes\n", measureAuxiliarySpaceQuickSort());
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}

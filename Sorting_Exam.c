#include <stdio.h>

void reset(int original[], int reset[], int size){
    for(int i = 0; i < size; i++){
        reset[i] = original[i];
    }
}

void printArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void Bubble(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

    printf("Bubble:");
    printArr(arr, size);

}

void insertion(int arr[], int size){
    int key,j;
    for(int i = 0; i < size; i++){
        key = arr[i];
        j = i -1;

        while(j >= 0 && key < arr[j] ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }


    printf("Insertion:");
    printArr(arr, size);
}

void selection(int arr[], int size){
    int min_index;
    for(int i = 0; i < size - 1; i++){
        min_index = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        if(min_index != i)
            swap(&arr[i], &arr[min_index]);
    }

    printf("Selection: ");
    printArr(arr, size);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int smaller = low - 1;
    for(int i = low; i < high; i++){
        if(arr[i] < pivot){
            smaller++;
            swap(&arr[smaller], &arr[i]);
        }
    }
    swap(&arr[smaller + 1], &arr[high]);

    return smaller+1;
}


void quickSort(int *arr, int low, int high)
{
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, pivot + 1, high);
        quickSort(arr, low, pivot - 1);
    }
}

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int Lindex = 0, Rindex = 0, Windex = l;
    while(Lindex < n1 && Rindex < n2){
        if(L[Lindex] <= R[Rindex]){
            arr[Windex] = L[Lindex];
            Lindex++;
        }
        else{
            arr[Windex] = R[Rindex];
            Rindex++;
        }
        Windex++;
    }

    while(Lindex < n1){
        arr[Windex] = L[Lindex];
        Windex++;
        Lindex++;
    }

    while(Rindex < n2){
        arr[Windex] = R[Rindex];
        Windex++;
        Rindex++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if(l < r){
        int m = l + ((r - l) / 2);

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int save[size];

    for(int i = 0; i< size; i++)
        save[i] = arr[i];

    Bubble(arr, size);
    printf("reset: ");
    reset(save, arr, size);
    printArr(arr, size);

    insertion(arr, size);
    printf("reset: ");
    reset(save, arr, size);
    printArr(arr, size);

    selection(arr, size);
    printf("reset: ");
    reset(save, arr, size);
    printArr(arr, size);

    quickSort(arr, 0, size);
    printf("Quick: ");
    printArr(arr, size);
    printf("reset: ");
    reset(save, arr, size);
    printArr(arr, size);

    printf("Merge: ");
    mergeSort(arr, 0, size - 1);
    printArr(arr, size);


    return 0;
}

//PAKKAWAT KAOLIM 66070503446
//List Slicing like Python

#include <stdio.h>

int main(void){
    int size, flag = 0;
    scanf("%d", &size);

    int arr[size];
    for(int i = 0 ; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int start,stop,step;
    scanf("%d %d %d", &start, &stop, &step);
    int isIncrease = 0;

    if(step == 0 || size == 0 || start == stop){
        printf("empty");
        return 0;
    }

    //set negative index to normal index
    if(start < -size)
        start = -size;
    if(stop < -size)
        stop = -size;

    //handle for index over size, set to 0 and len(arr)
    if(start < 0)
        start = size + start;

    if(stop < 0)
        stop = size + stop;
    if(stop > size - 1)
        stop = size;

    //check whether slicing in increasing or decreasing order
    if(start < stop && step > 0)
        isIncrease = 1;


    if(isIncrease){
        for(int i = start; i < stop; i+=step){
            flag = 1;
            printf("%d ", arr[i]);
        }
    }else{
        if(step > 0)
            step *= -1;
        if(start > size)
            start = size - 1;
        for(int i = start; i > stop; i+=step){
            flag = 1;
            printf("%d ", arr[i]);
        }
    }

    if(!flag){
        printf("empty");
    }
    return 0;
}
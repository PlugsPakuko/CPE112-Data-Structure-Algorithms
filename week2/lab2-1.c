//PAKKAWAT KAOLIM 66070503446
//No Bracket

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int size;
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);
    for(int i = 0 ; i < size; i++){
        scanf("%d", arr+i);
    }

    int mode,flag = 0;
    scanf("%d", &mode);

    for(int i = mode; i < size; i+=2){
        flag = 1;
        printf("%d ", *(arr+i));
    }
    
    if(!flag)
        printf("none");
    free(arr);
    return 0;
}
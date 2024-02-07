//PAKKAWAT KAOLIM 66070503446
//No Bracket No Printf

#include <stdio.h>
#include <stdlib.h>

void show_num(int min,int max,int min_index,int max_index)
{
    printf("%d %d\n", max, max_index);
    printf("%d %d", min, min_index);
}

int main(void){
    int n;
    scanf("%d", &n);

    if(n < 1 || n > 10000)
        return 0;

    int *arr = (int *)malloc(sizeof(int) * n);    
    int min = 10001, max = 0, min_index = 0, max_index = 0;
    for(int i = 0; i < n;i ++){
        scanf("%d", arr+i);
        if(*(arr+i) < min){
            min = *(arr+i);
            min_index = i;
        }
        if(*(arr+i) > max){
            max = *(arr+i);
            max_index = i;
        }
    }

    show_num(min,max,min_index,max_index);
    free(arr);
    return 0;
}
//Pakkawat Kaolim ID:66070503446
//CPE112 Week1 LAB
#include <stdio.h>

int isInSet(int num1, int *set, int set_size){
    for(int i = 0; i < set_size; i++){
        if(set[i] == num1){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int n_input;
    int count = 0;
    scanf("%d", &n_input);

    if(n_input < 1 || n_input > 1000)
        return 0;

    int set[n_input];

    for(int i = 0; i < n_input; i++){
        int temp;
        scanf("%d", &temp);

        if(!isInSet(temp, set, count)){
            set[count] = temp;
            count++;
        }
    }

    printf("%d\n",count);
    for(int i = 0; i < count; i++){
        printf("%d ", set[i]);
    }

    return 0;
}
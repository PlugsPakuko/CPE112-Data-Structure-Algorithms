//Pakkawat Kaolim ID:66070503446
//CPE112 Week1 LAB
//set operation using array of boolean represent whether the element is existed or not
//work for array element n, where n > 0 only

#include <stdio.h>

#define MAX 100

int isInSet(int num, int *set){
    return set[num];
}

void putInSet(int num, int *set){
    set[num] = 1;
}

void printSet(int *set){
    int flag = 1;

    for(int i = 0; i < MAX; i++){
        if(set[i]){
            printf("%d ", i);
            flag = 0;
        }
    }
    if(flag)
        printf("empty");

    printf("\n");
}

void union_set(int *set1, int *set2){
    int flag = 1;
    for(int i = 0; i < MAX; i++){
        if(set1[i] || set2[i]){
            if(set1[i]){
                printf("%d ", i);
            }else{
                printf("%d ", i);
            }
            flag = 0;
        }
    }

    if(flag)
        printf("empty");
    printf("\n");
}

void intersect_set(int *set1, int *set2){
    int flag = 1;

    for(int i = 0; i < MAX; i++){
        if(set1[i] && set2[i]){
            printf("%d ", i);
            flag = 0;
        }
    }
    if(flag)
        printf("empty");
    printf("\n");
}

void diff_set(int *set1, int *set2){
    int flag = 1;

    for(int i = 0; i < MAX; i++){
        if(set1[i] && !set2[i]){
            flag = 0;
            printf("%d ", i);
        }
    }
    if(flag)
        printf("empty");
    printf("\n");
}

void complement_set(int *set, int univ_min, int univ_max){
    int flag = 1;

    while (univ_min < 0)
    {
        flag = 0;
        printf("%d ", univ_min);
        univ_min++;
    }
    
    for(int i = univ_min; i <= univ_max; i++){
        if(!set[i]){
            flag = 0;
            printf("%d ", i);
        }
    }
    if(flag)
        printf("empty");
    printf("\n");  
}

int main(void){
    int univ_min, univ_max;
    do{
        scanf("%d %d",&univ_min, &univ_max);
    }while(univ_max < univ_min);

    int p, q, temp;
    int A[MAX] = {0};
    int B[MAX] = {0};

    scanf("%d", &p);
    for(int i = 0; i < p; i++){
        scanf("%d", &temp);
        if(!isInSet(temp, A) && (temp >= univ_min && temp <= univ_max))
            putInSet(temp, A);
    }

    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &temp);
        if(!isInSet(temp, B) && (temp >= univ_min && temp <= univ_max))
            putInSet(temp, B);
    }

    printSet(A);
    printSet(B);
    union_set(A, B);
    intersect_set(A,B);
    diff_set(A,B);
    diff_set(B,A);
    complement_set(A, univ_min, univ_max);
    complement_set(B, univ_min, univ_max);

    return 0;
}
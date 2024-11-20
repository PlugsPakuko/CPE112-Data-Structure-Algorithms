//Pakkawat Kaolim 66070503446
//Lab 6.1 : Planting Binary Tree with Array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *CreateTree(int n);
void CreateRoot(int val, int *TreeArr);
int Insertion(int *TreeArr, int n, int par, int val, int side);
void Display(int *TreeArr, int size);

int main(void){
    int n, val, par;
    char choice[5];
    scanf("%d", &n);
    if(n < 1)
        return 0;
    int *TreeArr = CreateTree(n);


    while (1){
        scanf(" %s", choice);
        if(strcmp(choice, "ROOT") == 0){
            scanf(" %d", &val);
            
            if(TreeArr[0] == -999)
                CreateRoot(val, TreeArr);
            else
                printf("cannot create duplicated root\n");

        }else if(strcmp(choice, "INSL") == 0){
            scanf(" %d", &par);
            scanf(" %d", &val);

            if(Insertion(TreeArr, n, par, val, 0) == 0)
                printf("not found\n");

        }else if(strcmp(choice, "INSR") == 0){
            scanf(" %d", &par);
            scanf(" %d", &val);

            if(Insertion(TreeArr, n, par, val, 1) == 0)
                printf("not found\n");

        }else{
            Display(TreeArr, n);
            break;
        }
    }

    return 0;
}

int *CreateTree(int n){
    int *TreeArr;

    TreeArr = (int *)malloc(sizeof(int) * (n));
    for(int i = 0; i < n; i++){
        TreeArr[i] = -999;
    }

    return TreeArr;
}

void CreateRoot(int val, int *TreeArr){
    TreeArr[0] = val;
}

void Display(int *TreeArr, int size){
    for(int i = 0; i < size; i++){
        if(TreeArr[i] == -999){
            printf("null ");
        }else{
            printf("%d ", TreeArr[i]);
        }
    }
}

int Insertion(int *TreeArr, int n, int par, int val, int side){
    for(int i = 0; i < n; i++){
        if(TreeArr[i] == par && side == 1){
            if(TreeArr[2 * (i + 1)] == -999){
                TreeArr[2 * (i + 1)] = val;
            }else if(2 * (i + 1) < n){
                printf("node already presented\n");
            }else{
                printf("overflow\n");
            }

            return 1;
        }else if(TreeArr[i] == par && side == 0){
            if(TreeArr[(2 * i) + 1] == -999){
                TreeArr[(2 * i) + 1] = val;
            }else if((2 * i) + 1 < n){
                printf("node already presented\n");
            }else{
                printf("overflow\n");
            }

            return 1;
        }
    }
    return 0;
}
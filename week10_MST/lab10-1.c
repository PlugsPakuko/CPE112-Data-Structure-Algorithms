//Pakkawat Kaolim 66070503446
//Lab 10.1 : Floyd-Warshall

#include <stdio.h>

void Floyd_Warshell(int V, int MAT[V][V]){

    for(int k = 0; k < V; k++){
        for(int rows = 0; rows < V; rows++)
            for (int column = 0; column < V; column++){
                if(MAT[rows][k] + MAT[k][column] < MAT[rows][column])
                    MAT[rows][column] = MAT[rows][k] + MAT[k][column];
            }
    }

    for(int rows = 0; rows < V; rows++){
        for(int column = 0; column < V; column++){
            printf("%d ", MAT[rows][column]);
        }

        printf("\n");
    }

    return;
}

int main(void){
    int V;
    scanf("%d", &V);

    int MAT[V][V];
    for(int rows = 0; rows < V; rows++){
        for(int column = 0; column < V; column++){
            scanf("%d", &MAT[rows][column]);
        }
    }

    Floyd_Warshell(V, MAT);

    return 0;
}
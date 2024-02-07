//PAKKAWAT KAOLIM 66070503446
//Symmetric Matrix

#include <stdio.h>

int main(void){
    int m,n;
    scanf("%d %d", &m, &n);

    int MAT[m][n];
    int countS = 0, countSK = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &MAT[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == j) 
                continue;
            if(MAT[i][j] == MAT[j][i]){
                countS++;
            }else if(MAT[i][j] == -1*MAT[j][i]){
                countSK++;
            }        
        }
    }

    if(countS == (m*n)-m){
        printf("The matrix is symmetric");
    }else if(countSK == (m*n)-m){
        printf("The matrix is skew-symmetric");
    }else{
        printf("None");
    }
}
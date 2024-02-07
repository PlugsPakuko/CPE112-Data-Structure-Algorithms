//PAKKAWAT KAOLIM 66070503446
//Sum of Diagonal Matrix

#include <stdio.h>

int main(void){
    int m,n;
    scanf("%d %d", &m, &n);
    if(!(m == n)){
        printf("ERROR");
        return 0;
    }
    int arr[m][n], main = 0, sub = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        main += arr[i][i];
        sub += arr[i][m-i-1];
    }
    printf("Primary: %d\nSecondary: %d",main, sub);

    return 0;
}
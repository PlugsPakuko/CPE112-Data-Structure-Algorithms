//PAKKAWAT KAOLIM 66070503446
//Spiral Array Printer

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    int **arr = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int right = n-1, left = 0, top = 0, bottom = m-1;
    while (left <= right && top <= bottom){
        // left to right
        for(int i = left; i <= right; i++){
            printf("%d ", arr[top][i]);
        }
        top++;

        // top to bottom
        for(int i = top; i <= bottom; i++){
            printf("%d ", arr[i][right]);
        }
        right--;

        // right to left
        for(int i = right; i >= left; i--){
            printf("%d ", arr[bottom][i]);
        }
        bottom--;

        // bottom to top
        for(int i = bottom; i >= top; i--){
            printf("%d ", arr[i][left]);
        }
        left++;
    }

    return 0;
    
}
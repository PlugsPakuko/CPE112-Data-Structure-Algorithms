//PAKKAWAT KAOLIM 66070503446
//Matrix Multiplication

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    int **MAT1 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        MAT1[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &MAT1[i][j]);
        }
    }

    int x, y;
    scanf("%d %d", &x, &y);

    int **MAT2 = (int **)malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++) {
        MAT2[i] = (int *)malloc(y * sizeof(int));
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &MAT2[i][j]);
        }
    }

    if (n != x) {
        printf("Not Compatible");
        return 0;
    }

    int **ANS = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        ANS[i] = (int *)malloc(y * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < y; j++) {
            ANS[i][j] = 0;
            for (int k = 0; k < n; k++) {
                ANS[i][j] += MAT1[i][k] * MAT2[k][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", ANS[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(MAT1[i]);
    }
    free(MAT1);

    for (int i = 0; i < x; i++) {
        free(MAT2[i]);
    }
    free(MAT2);

    for (int i = 0; i < m; i++) {
        free(ANS[i]);
    }
    free(ANS);

    return 0;
}

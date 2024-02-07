//PAKKAWAT KAOLIM 66070503446
//Jump Game
//minJumps(start, end) = 1 + Min(minJumps(k, end)) for all k reachable from start.

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 10000

int minJumps(int arr[], int start, int end) {
    if (end == start)
        return 0;

    if (arr[start] == 0)
        return INFINITY;

    int min = INFINITY;
    for (int i = start + 1; i <= end && i <= start + arr[start]; i++) {
        int jumps = minJumps(arr, i, end);

        // new min found and that index != 0
        if (jumps != INFINITY && jumps + 1 < min)
            min = jumps + 1;
    }

    return min;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *set = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    int count = 0;
    count = minJumps(set, 0, n - 1);

    if (count == INFINITY)
        printf("Not Possible");
    else
        printf("%d", count);

    free(set);  
    return 0;
}

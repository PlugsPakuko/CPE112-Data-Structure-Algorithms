//PAKKAWAT KAOLIM 66070503446
//Grading

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
    char *name;
    double score;
}POINT;

POINT min(POINT *students, int n){
    POINT min = students[0];
    for(int i = 1; i < n; i++){
        if(students[i].score < min.score)
            min = students[i];
    }
    return min;
}

POINT max(POINT *students, int n){
    POINT max = students[0];
    for(int i = 1; i < n; i++){
        if(students[i].score > max.score)
            max = students[i];
    }
    return max;
}

double MEAN(POINT *students, int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += students[i].score;
    }
    return sum/n;
}

double SD(POINT *students, int n){
    double mean = MEAN(students, n);
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += (students[i].score - mean) * (students[i].score - mean);
    }
    return sqrt(sum/n);
}

int main(void){
    int n;
    scanf("%d", &n);
    POINT *students = (POINT *)malloc(sizeof(POINT) * n);
    for(int i = 0; i < n; i++){
        students[i].name = (char *)malloc(sizeof(char) * 100);
        scanf("%s %lf", students[i].name, &students[i].score);
    }

    printf("%.2lf %.2lf %s %s", MEAN(students, n), SD(students, n), max(students, n).name, min(students, n).name);
    return 0;
}
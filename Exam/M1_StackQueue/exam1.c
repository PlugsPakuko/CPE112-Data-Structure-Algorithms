// Problem 1: Set
// 66070503446 Pakkawat Kaolim

#include <stdio.h>
#include <stdlib.h>

typedef struct sortedset
{
    int *elements;
    int size;
}set;

// Function prototypes
void init(set *s, int size);
int checkDuplicate(set *s, int target);
void insertElement(set *s, int newNum);
void printArray(set *s);
void sort(set *s);

int main()
{
    // Your code here
    int n;
    int count = 0;
    scanf("%d", &n);

    set *Set = (set *)malloc(sizeof(set));
    init(Set, n);

    for(int i = 0; i < n; i++){
        int value;
        scanf("%d", &value);
        if(checkDuplicate(Set, value) == 0){
            count++;
            insertElement(Set, value);
        }

    }

    sort(Set);
    printf("%d\n", count);
    printArray(Set);
    return 0;
}

//O(N)
//Initializes the set with given size.
void init(set *s, int size){
    s->elements = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        s->elements[i] = -1;
    }
    s->size = size;
    
}

//O(N)
//Checks if a given integer is already in the set. 
int checkDuplicate(set *s, int target){
    for(int i = 0; i < s->size; i++){
        if(target == s->elements[i])
            return 1;
    }
    return 0;

}

//O(N)
//Inserts a new integer into the set, maintaining the sorted order.
void insertElement(set *s, int newNum){
    int i = 0;
    while(i < s->size){
        if(s->elements[i] == -1){
            s->elements[i] = newNum;
            return ;
        }
        i++;    
    }
}

//O(N)
//Print both the size of set and the elements of the set in the formatted form.
void printArray(set *s){
    printf("{");
    for(int i = 0; i < s->size; i++){
        if(s->elements[i] != -1){
            printf("%d", s->elements[i]);
            if(i != s->size - 1)
                printf(", ");
        }
    }
    printf("}");
}

//O(N^2)
//Sort the set
void sort(set *s){
    for(int i = 0;i < s->size; i++){
        int j = i;
        while(j > 0){
            if(s->elements[j] < s->elements[j-1]){
                int temp = s->elements[j];
                s->elements[j] = s->elements[j-1];
                s->elements[j-1] = temp;
            }
            j--;
        }
    }
}

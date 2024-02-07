//Pakkawat Kaolim 66070503446
//Assignment 3.1 : It's Sorting Time

//mode 0 - sort by ID
//mode 1 - sort by Score

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int ID;
    int score;
    struct node *next;
}Student;

Student *Create_Node(){
    int ID, Score;
    scanf("%d %d", &ID, &Score);
    Student *New_Node = (Student *)malloc(sizeof(Student));
    New_Node->ID = ID;
    New_Node->score = Score;
    New_Node->next = NULL;
    return New_Node; 
}

void Traverse(Student **start){
    Student *cur = *start;
    while(cur != NULL){
        printf("%d ",cur->score);
        cur = cur->next;
    }
}


void Sort_By_ID(Student **start){
    if (*start == NULL)
        return;
    
    int sorted = 0;
    Student *cur = *start, *prev, *post;

    do{
        sorted = 0;
        prev = NULL;
        while (cur->next != NULL) {
            post = cur->next;

            if (cur->ID > post->ID) {
                if (prev == NULL) {
                    *start = post;
                } else {
                    prev->next = post;
                }
                
                cur->next = post->next;
                post->next = cur;
                sorted = 1;
                break;
            }

            prev = cur;
            cur = cur->next;
        }
        cur = *start;

    }while(sorted); 
}

void Sort_By_Score(Student **start){
    if (*start == NULL)
        return;
    
    int sorted = 0;
    Student *cur = *start, *prev, *post;

    do{
        sorted = 0;
        prev = NULL;
        while (cur->next != NULL) {
            post = cur->next;
            if (cur->score > post->score) {
                if (prev == NULL) {
                    *start = post;
                } else {
                    prev->next = post;
                }
                
                cur->next = post->next;
                post->next = cur;
                sorted = 1;
                break;
            }

            prev = cur;
            cur = cur->next;
        }
        cur = *start;

    }while(sorted); 
}

int main(void){
    int n;
    scanf("%d", &n);

    Student *start = NULL;
    Student *cur = start;
    for(int i = 0; i < n; i++){
        Student *New_Node = Create_Node();
        if(start == NULL){
            start = New_Node;
            cur = start;
        }else{
            cur->next = New_Node;
            cur = New_Node;
        }
    }

    int mode;
    scanf("%d", &mode);

    if(mode == 0){
        Sort_By_ID(&start);
    }else{
        Sort_By_Score(&start);
    }

    Traverse(&start);
    return 0;

}

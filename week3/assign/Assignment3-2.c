//Pakkawat Kaolim 66070503446
//Assignment 3.2 : Circular table

//Example:
// 1 2 3 4 5 with 2 steps
// 1st round (start at 1): 1 2 3 4 5 two got removed
// 2nd round (start at 3): 1 3 4 5 four got removed
// 3rd round (start at 5): 1 3 5 one got removed
// 4th round (start at 3): 3 5 five got removed
// and 3 is the answer.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

Node *Create_Node(){
    Node *New_Node = (Node *)malloc(sizeof(Node));
    scanf("%d", &New_Node->value);
    New_Node->next = NULL;
}

Node *LastManStanding(Node **start, int Step){
    if (*start == NULL){ //Empty List
        return NULL;
    }

    if((*start)->next ==  *start){ //Last Man
        return *start;
    }
    Node *Cur = *start;
    // printf("Start : %d ", Cur->value);
    Node *Prev = NULL;
    for(int i = 0; i < Step; i++){
        Prev = Cur;
        Cur = Cur->next;
    }

    // printf("Die : %d\n", Cur->value);
    Prev->next = Cur->next;
    return LastManStanding(&(Prev),Step);
}


int main(void){
    int n,step;
    scanf("%d %d", &n, &step);

    Node *Start = NULL;
    Node *Cur = Start;
    for(int i = 0; i < n; i++){
        Node *New_Node = Create_Node();
        if(Start == NULL){
            Start = New_Node;
            Cur = Start;
        }else{
            Cur->next = New_Node;
            Cur = New_Node;
        }
        New_Node->next = Start;
    }
    LastManStanding(&(Cur),step); // Cur is at the last node
    Node *Res = LastManStanding(&Start, step);
    printf("%d", Res->value);

    return 0;
}

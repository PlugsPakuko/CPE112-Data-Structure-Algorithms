//Pakkawat Kaolim 66070503446
//Assignment 3.3 : Reverse Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *Create_Node(int value){
    ListNode *New_Node = (ListNode *)malloc(sizeof(ListNode));
    New_Node->val = value;
    New_Node->next = NULL;
}

void Traverse(ListNode **start){
    ListNode *cur = * start;
    while(cur != NULL){
        printf("%d ", cur->val);
        cur = cur->next;
    }
}

void Reverse(ListNode **start, int begin, int end){
    if(*start == NULL)
        return ;

    ListNode *Prev = NULL;
    ListNode *Cur = *start;
    ListNode *Next = Cur->next;

    ListNode *StartCheckpoint = NULL;
    for(int i = 1; i < begin; i++){
        if( i == begin - 1)
            StartCheckpoint = Cur;
        Prev = Cur;
        Cur = Cur->next;
        Next = Cur->next;
    }

    while(Cur != NULL && begin <= end){
        Cur->next = Prev;
        Prev = Cur;
        Cur = Next;
        if(Next != NULL)
            Next = Cur->next;
        begin++;
    }

    if(StartCheckpoint != NULL){
        StartCheckpoint->next->next = Cur;
        StartCheckpoint->next = Prev;
    }else{
        *start = Prev;
    }
}

int main(void){
    char input[7];
    ListNode *Start = NULL;
    ListNode *Cur;
    do{
        scanf("%s", input);
        if(strcmp("END", input) == 0){
            break;
        }else{
            ListNode *New_Node = Create_Node(atoi(input));
            if(Start == NULL){
                Start = New_Node;
                Cur = Start;
            }else{
                Cur->next = New_Node;
                Cur = New_Node;
            }
        }

    }while(strcmp("END", input) != 0);

    int begin, end;
    scanf("%d %d", &begin, &end);

    Reverse(&Start, begin, end);
    Traverse(&Start);

    return 0;
}
//Pakkawat Kaolim 66070503446
//Thanakorn Thavornlertprasert 66070503426
//Josephus using Cicular Queue

#include <stdio.h>
#include <stdlib.h>

typedef struct qnode{
    int val;
    struct qnode *next;
}NODE;

typedef struct queue{
    struct qnode *qfront;
    struct qnode *qrear;
}QUEUE;

NODE *Create_Node(int value){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

void enqueue(NODE *newNode, QUEUE *Queue){

    if(Queue->qfront == NULL && Queue->qrear == NULL){
        Queue->qfront = newNode;
        Queue->qrear = newNode;
    }else{
        Queue->qrear->next = newNode;
        Queue->qrear = newNode;
    }

    newNode->next = Queue->qfront;
}

NODE* dequeue(NODE* cur, NODE* prev) {
    if (cur == NULL || prev == NULL) {
        return NULL;
    }
    prev->next = cur->next;
    free(cur);
    return prev->next;
}

int Josephus(NODE *cur, int jumps){
    if ( jumps == 0){
        return -1;
    }

    if(cur->next == cur){
        return cur->val;
    }

    printf("Cur: %d\n", cur->val);
    int count = 0;
    NODE *prev = NULL;
    while(count < jumps){
        prev = cur;
        cur = cur->next;
        count++;
    }
    printf("Kill: %d\n", cur->val);
    cur = dequeue(cur,prev);

    return Josephus(prev, jumps);
}

int main(void){
    QUEUE *Queue = malloc(sizeof(QUEUE));
    Queue->qfront = NULL;
    Queue->qrear = NULL;

    int n;
    printf("Input total knights in the circle: ");
    scanf("%d", &n);

    int jump;
    printf("Input jump number to kill the knight: ");
    scanf("%d", &jump);

    for(int i = 1; i <= n; i++){
        NODE *newNode = Create_Node(i);
        enqueue(newNode, Queue);
    }

    NODE *ptr = Queue->qfront;
    do{
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }while(ptr != Queue->qfront);
    printf("\n");

    int lastman = Josephus(Queue->qrear, jump);
    printf("Last knight: %d", lastman);

    return 0;

}
//Exam 3: Fourris Wheel
//Pakkawat Kaolim 66070503446
#include <stdio.h>
#include <stdlib.h>

typedef struct group{
    int elements[4]; //people group
    int priority; //priority
    int size; //people amount
}GroupQ;

//O(1)
void enqueue(int *Queue, int value){
    *Queue = value;
}

//O(N^2)
void leavequeue(GroupQ line){
    for(int i = 0; i < line.size; i++){
        printf("%d ",line.elements[i]);
    }
    printf("\n");
}

void printGroup(GroupQ GroupQ[], int size){
    for(int i = 0; i < size; i++){
        leavequeue(GroupQ[i]);
    }
}


//O(1)
GroupQ *NewGroup(){
    GroupQ *NewLine = (GroupQ *)malloc(sizeof(GroupQ));
    NewLine->size = 0;
    return NewLine;
}

//O(N)
int main(void){
    int n;
    scanf("%d", &n);
    int queue[n];
    GroupQ *Cur_line = NewGroup();
    GroupQ Group1[n], Group2[n],Group3[n], Group4[n];
    int g1_c = 0, g2_c = 0, g3_c = 0, g4_c = 0;
    int total = 0;

    for(int i = 0; i < n; i++){
        int value;
        scanf("%d", &value);
        enqueue(&(queue[i]), value);

        if(total + value > 4){ //if size limit; leave that group
            if(Cur_line->size == 1){
                Group1[g1_c] = *Cur_line;
                g1_c++;
            }else if(Cur_line->size == 2){
                Group2[g2_c] = *Cur_line;
                g2_c++;
            }else if(Cur_line->size == 3){
                Group3[g3_c] = *Cur_line;
                g3_c++;
            }else{
                Group4[g4_c] = *Cur_line;
                g4_c++;
            }
            Cur_line = NewGroup();
            total = 0;
        }else{
            Cur_line->elements[Cur_line->size] = value;
            Cur_line->size++;
            total += value;
        }
    }
    printf("Group4size: %d\n", Group4[0].size);
    printGroup(Group4, g4_c);
    // printGroup(Group3, g3_c);
    // printGroup(Group2, g2_c);
    // printGroup(Group1, g1_c);

    // leavequeue(*Cur_line);

    return 0;

}
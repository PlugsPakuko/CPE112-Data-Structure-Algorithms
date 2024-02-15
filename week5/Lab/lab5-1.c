//Pakkawat Kaolim 66070503446
//Lab 5.1 Spotify

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Song
{
    char name[500];
    char author[500];
    int duration;
    struct Song *next;
}Song;

typedef struct Queue{
    Song *front;
    Song *rear;   
}Queue;

Song *NewNode(){
    Song *NewSong = (Song *)malloc(sizeof(Song));
    scanf(" %[^\n]%*c", NewSong->name);
    scanf(" %[^\n]%*c", NewSong->author);
    scanf(" %d", &(NewSong->duration));
    NewSong->next = NULL;

    return NewSong;  
}

void ADD(Queue *PlayList){
    Song *NewSong = NewNode();

    if(PlayList->front == NULL && PlayList->rear == NULL){
        PlayList->front = NewSong;
        PlayList->rear = NewSong;
    }else{
        PlayList->rear->next = NewSong;
        PlayList->rear = NewSong;
    }

}

void PLAY(Queue *PlayList){
    Song *played = PlayList->front;
    if(PlayList->front == NULL && PlayList->rear == NULL){
        printf("No songs in the playlist\n");
        return ;
    }

    printf("Now playing: %s by %s\n",played->name, played->author);
    if(PlayList->front->next == NULL){
        PlayList->front = NULL;
        PlayList->rear = NULL;
    }
    else
        PlayList->front = PlayList->front->next;
    free(played);
}

void SUM(Queue *PlayList){
    if(PlayList->front == NULL && PlayList->rear == NULL){
        printf("No songs in the playlist\n");
        return ;
    }

    int time = 0;
    Song *Cur = PlayList->front;
    printf("Songs in the playlist:\n");
    while (Cur != NULL){
        printf("%s by %s %d\n",Cur->name, Cur->author, Cur->duration);
        time += Cur->duration;
        Cur = Cur->next;
    }
    printf("Remaining Time: %d\n",time);
    
}

int main(void){
    Queue *PlayList = (Queue *)malloc(sizeof(Queue));
    PlayList->front = NULL;
    PlayList->rear = NULL;

    char choice[5];
    while (1)
    {
        scanf(" %s", choice);
        if(strcmp(choice,"add") == 0){
            ADD(PlayList);
        }else if(strcmp(choice, "play") == 0){
            PLAY(PlayList);
        }else if(strcmp(choice, "sum") == 0){
            SUM(PlayList);
            break;
        }else{
            break;
        }
    }

    return 0;
}

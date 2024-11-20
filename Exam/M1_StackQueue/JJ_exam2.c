//Problem 2: Palindrome Creater
// 66070503450 Phudid Pimpasan

//O(n+n/2+m) = O(n+m)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char data;
    struct node* next;
}node;

node *insert_before(node *head, char input);
void show(node *head);
int ispalindrome(char *input, int maxsize);

int main(){
    //input
    char input[1000001];
    scanf("%[^\n]s",input);
    node *head = NULL;
    int size = strlen(input), maxsize = size;

    //check palindrome first, if yes print it and end
    if(ispalindrome(input, maxsize)==1){ //O(n/2)
        printf("%s",input);
    }
    else{
        printf("%s",input); //print the input string
        int i=0;
        while(size>1){ //O(n)
            head = insert_before(head, input[i]); //insert before to make string reverse-1
            i++;
            size--;
        }
        if(input[maxsize-1]==input[maxsize-3]){ //condition qwe_opo = qwe_opo_ewq 
            head = head->next;
            head = head->next;
        }
        else if(input[maxsize-1]==input[maxsize-2]){ //condition qwe_oo_ewq
            head = head->next;
        }
        show(head); //print && O(m) m<=n
    }

    return 0;
}

node *insert_before(node *head, char input){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = input;
    newnode->next = head;
    return newnode;
}

void show(node *head){
    while(head!=NULL){
        printf("%c",head->data);
        head = head->next;
    }
}

int ispalindrome(char *input, int maxsize){
    int front=0, rear=maxsize-1, ispalin=1;
    for(int i=0;i<(maxsize/2);i++){
        if(input[front]!=input[rear]){
            ispalin=0;
            break;
        }
        front++;
        rear--;
    }
    return ispalin;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode{
    int data;
    Node *Left;
    Node *Right;
}Node;

Node *CreateTreeNode(int value);
Node *InsertTreeNode(Node * root, int data);
void DeleteTreeNode();


//Pre order: Root Left Right
//In order: Left Root Right
//Post order: Left Right Root

int main(void){
    int n;
    printf("How many levels of Tree you want to create: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < pow(2,i); j++){
            printf("");
        }
    }
}

Node *CreateTreeNode(int value){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->data = value;
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    return NewNode;
}

//Recursive 
//Fn to insert a value into the 2ary Tree
Node *InsertTreeNode(Node *root,int data){
    if(root == NULL)
        return CreateTreeNode(data);

    if(data < root->data)
        root->Left = InsertTreeNode(root->Left, data);
    else
        root->Right = InsertTreeNode(root->Right, data);

    return root;   
}
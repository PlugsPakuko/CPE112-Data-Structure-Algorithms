//Pakkawat Kaolim 66070503446
//Lab 6.2 : The Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *Left;
    struct TreeNode *Right;
}Node;

Node *INS(Node *root,int data);
void INORDER(Node *Root);
void PREORDER(Node *Root);
void POSTORDER(Node *Root);
Node *CreateTreeNode(int data);

int main(){
    int val;
    Node *Root = NULL;

    char choice[10];
    while(1){
        scanf(" %s", choice);
        if(strcmp(choice, "INS") == 0){
            scanf(" %d", &val);
            Root = INS(Root, val);
        }else if(strcmp(choice, "INORDER") == 0){
            INORDER(Root);
            printf("\n");
        }else if(strcmp(choice, "PREORDER") == 0){
            PREORDER(Root);
            printf("\n");
        }else if(strcmp(choice, "POSTORDER") == 0){
            POSTORDER(Root);
            printf("\n");
        }else if(strcmp(choice, "END") == 0){
            INORDER(Root);
            printf("\n");
            break;
        }else{
            break;
        }
    }

    return 0;
}

void INORDER(Node *Root){
    if (Root == NULL)
        return ;

    INORDER(Root->Left);
    printf("%d ",Root->data);
    INORDER(Root->Right);
}

void PREORDER(Node *Root){
    if (Root == NULL)
        return ;
    printf("%d ",Root->data);
    PREORDER(Root->Left);
    PREORDER(Root->Right);
}

void POSTORDER(Node *Root){
    if (Root == NULL)
        return ;
    POSTORDER(Root->Left);
    POSTORDER(Root->Right);
    printf("%d ",Root->data);
}

Node *CreateTreeNode(int data){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    return NewNode;
}

Node *INS(Node *root,int data){
    if(root == NULL)
        return CreateTreeNode(data);

    if(data < root->data)
        root->Left = INS(root->Left, data);
    else
        root->Right = INS(root->Right, data);

    return root;   
}

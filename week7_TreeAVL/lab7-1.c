//Pakkawat Kaolim 66070503446
//AVL Tree

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define InputSize 1000

typedef struct BSTNode{
    int data;
    int height;
    struct BSTNode *Left;
    struct BSTNode *Right;
}Node;

typedef struct UserInput{
    int size;
    int *inputArr;
}Input;


//Main function
Node *InsertAVL(Node *root, int data);
Node *DeleteAVL(Node *root, int data, int *found);

//Rotate
Node *RotateR(Node *Root);
Node *RotateL(Node *Root);

//AVL utility
int GetHeight(Node *Root);
int GetBalance(Node *Root);
int max(int num1, int num2);

//Input && Output
Input *GetInput();
void PREORDER(Node *Root);

int main(void){
    Node *Root = NULL;
    char choice[10];
    while (1){
        scanf("%s", choice);
        if (strcmp(choice, "INSERT") == 0){
            Input *inp = GetInput();
            for(int i = 0; i < inp->size; i++)
                Root = InsertAVL(Root, inp->inputArr[i]);
        }else if (strcmp(choice, "DELETE") == 0){
            int found = 0;
            Input *inp = GetInput();
            for (int i = 0; i < inp->size; i++){
                found = 0;
                Root = DeleteAVL(Root, inp->inputArr[i], &found);
                if(!found)
                    printf("Node not found.\n");
            }
        }else if (strcmp(choice, "PRINT") == 0){
            if(Root == NULL)
                printf("Tree is empty.");
            else
                PREORDER(Root);
            printf("\n");
        }else if (strcmp(choice, "EXIT") == 0){
            break;
        }else{
            printf("Invalid command.\n");
        }
    }

    free(Root);
    return 0;
}

Node *CreateTreeNode(int data)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->height = 1;
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    return NewNode;
}

Node *InsertAVL(Node *Root, int data){
    if (Root == NULL)
        return CreateTreeNode(data);

    //BST ins
    if (data < Root->data)
        Root->Left = InsertAVL(Root->Left, data);
    else if (data > Root->data)
        Root->Right = InsertAVL(Root->Right, data);
    else
        return Root;

    Root->height = max(GetHeight(Root->Left), GetHeight(Root->Right)) + 1;

    //AVL logic
    //This Part occur only when found the place to put newn
    int balance = GetBalance(Root);

    if(balance > 1 && data < Root->Left->data) {  // R Rotate
        return RotateR(Root);
    }else if (balance < -1 && data > Root->Right->data) {  // L Rotate
        return RotateL(Root);
    }else if (balance > 1 && data > Root->Left->data) {  // LR rotate
        Root->Left = RotateL(Root->Left);
        return RotateR(Root);
    }else if (balance < -1 && data < Root->Right->data) {  // RL rotate
        Root->Right = RotateR(Root->Right);
        return RotateL(Root);
    }

    return Root;
}
Node *DeleteAVL(Node *Root, int data, int *found) {
    if (Root == NULL)
        return NULL;

    if (data > Root->data)
        Root->Right = DeleteAVL(Root->Right, data, found);
    else if (data < Root->data)
        Root->Left = DeleteAVL(Root->Left, data, found);
    else if (data == Root->data) {
        // Found
        *found = 1;
        if(Root->Left == NULL && Root->Right == NULL)
            Root = NULL;
        else if(Root->Left == NULL)
            *Root = *(Root->Right);
        else if(Root->Right == NULL)
            *Root = *(Root->Left);
        else{
            Node *temp = Root->Right;
            while (temp->Left != NULL)
                temp = temp->Left;
            Root->data = temp->data;
            Root->Right = DeleteAVL(Root->Right, temp->data, found);       
        }
    }

    // Balanced AVL
    if (Root == NULL)
        return Root;

    Root->height = max(GetHeight(Root->Left), GetHeight(Root->Right)) + 1;

    int balance = GetBalance(Root);
    if (balance > 1 && GetBalance(Root->Left) >= 0) // R ROTATE
        return RotateR(Root);
    else if (balance > 1 && GetBalance(Root->Left) < 0) { // L R ROTATE
        Root->Left = RotateL(Root->Left);
        return RotateR(Root);
    } else if (balance < -1 && GetBalance(Root->Right) <= 0) // L ROTATE
        return RotateL(Root);
    else if (balance < -1 && GetBalance(Root->Right) > 0) { // R L ROTATE
        Root->Right = RotateR(Root->Right);
        return RotateL(Root);
    }

    return Root;
}

int max(int num1, int num2){
    return (num1 > num2) ? num1: num2;
}

void PREORDER(Node *Root){
    if (Root == NULL)
        return ;

    printf("%d ", Root->data);
    PREORDER(Root->Left);
    PREORDER(Root->Right);
}

Input *GetInput(){
    Input *NewInput = (Input *)malloc(sizeof(Input));
    NewInput->inputArr = (int *)malloc(sizeof(int) * InputSize);
    NewInput->size = 0;

    char input[InputSize];
    if (scanf(" %[^\n]", input) <= 0) {
        return NULL;
    }

    char *token = strtok(input, " ");
    while (token != NULL){
        int num = atoi(token);
        NewInput->inputArr[NewInput->size++] = num;
        token = strtok(NULL, " ");
    }

    return NewInput;
}

int GetHeight(Node *Root){
    if(Root == NULL)
        return 0;

    return Root->height;
}

int GetBalance(Node *Root){
    if(Root == NULL)
        return 0;

    return GetHeight(Root->Left) - GetHeight(Root->Right);
}


//======Rotate======
Node *RotateR(Node *Root){

    Node *NewRoot = Root->Left;
    Node *RightSubTree = NewRoot->Right;

    NewRoot->Right = Root;
    Root->Left = RightSubTree;

    Root->height = max(GetHeight(Root->Left), GetHeight(Root->Right)) + 1;
    NewRoot->height = max(GetHeight(NewRoot->Left), GetHeight(NewRoot->Right)) + 1;

    return NewRoot;
}

Node *RotateL(Node *Root){

    Node *NewRoot = Root->Right;
    Node *LeftSubTree = NewRoot->Left;

    NewRoot->Left = Root;
    Root->Right = LeftSubTree;

    Root->height = max(GetHeight(Root->Left), GetHeight(Root->Right)) + 1;
    NewRoot->height = max(GetHeight(NewRoot->Left), GetHeight(NewRoot->Right)) + 1;

    return NewRoot;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define InputSize 100000
typedef struct HeapTree
{
    int data;
    struct HeapTree *left, *right;
}Node;

typedef struct UserInput{
    int size;
    int *inputArr;
}Input;

Node *CreateNode(int value);
void MinHeapify(Node *root);
Node *InsertHeap(Node *root, int value);
Node *DeleteHeap(Node *root, int value, Node *LastElement);

Input *GetInput();
void Traverse(Node *Root);
Node *GetLastElement(Node *root);

int main(void){
    Node* HeapRoot = NULL;
    char command[10];
    while (1){
        scanf("%s", command);
        Input *inp;
        if(strcmp("INSERT", command) == 0){
            inp = GetInput();
            for(int i = 0; i < inp->size; i++)
                HeapRoot = InsertHeap(HeapRoot, inp->inputArr[i]);
        }else if(strcmp("DELETE", command) == 0){
            inp = GetInput();
            for(int i = 0; i < inp->size; i++){
                Node *LastElement = GetLastElement(HeapRoot);
                HeapRoot = DeleteHeap(HeapRoot, inp->inputArr[i], LastElement);
            }

        }else if(strcmp("PRINT", command) == 0){
            Traverse(HeapRoot);
            printf("\n");
        }else{
            break;
        }
    }

    return 0;
}
Node *GetLastElement(Node *root){
    Node* Cur = root;
    while(Cur->right != NULL)
        Cur = Cur->right;
    
    return Cur;
}

void MinHeapify(Node *root){
    if (root == NULL)
        return;

    int smallest = root->data;
    Node *smallestNode = root;
    if (root->left != NULL && root->left->data < smallest) {
        smallest = root->left->data;
        smallestNode = root->left;
    }
    if (root->right != NULL && root->right->data < smallest) {
        smallest = root->right->data;
        smallestNode = root->right;
    }
    if (smallestNode != root) {
        int temp = root->data;
        root->data = smallestNode->data;
        smallestNode->data = temp;
        MinHeapify(smallestNode);
    }
}

Node *InsertHeap(Node *root, int value){
    if(root == NULL)
        return CreateNode(value);
    
    if(value > root->data)
        root->right = InsertHeap(root->right, value);
    else
        root->left = InsertHeap(root->left, value);
    
    MinHeapify(root);

    return root;
}


Node *DeleteHeap(Node *root, int value, Node *LastElement) {
    if (root == NULL)
        return NULL;
    
    if (value < root->data)
        root->left = DeleteHeap(root->left, value, LastElement);
    else if (value > root->data)
        root->right = DeleteHeap(root->right, value, LastElement);
    else {
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
        }else{
            root->data = LastElement->data;
            LastElement->data = value;
            LastElement = NULL;
        }
    }
    
    MinHeapify(root);
    return root;
}

Input *GetInput(){
    Input *NewInput = (Input *)malloc(sizeof(Input));
    NewInput->inputArr = (int *)malloc(sizeof(int) * InputSize);
    NewInput->size = 0;

    char input[InputSize];
    scanf(" %[^\n]", input) <= 0;

    char *token = strtok(input, " ");
    while (token != NULL){
        int num = atoi(token);
        NewInput->inputArr[NewInput->size++] = num;
        token = strtok(NULL, " ");
    }

    return NewInput;
}

Node *CreateNode(int value){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->data = value;
    NewNode->left = NULL;
    NewNode->right = NULL;

    return NewNode;
}


void Traverse(Node *Root){
    if (Root == NULL)
        return ;

    printf("%d ", Root->data);
    Traverse(Root->left);
    Traverse(Root->right);
}
#include <stdio.h>
#include <stdlib.h>


typedef struct AVL
{
    int data;
    int height;
    struct AVL *left;
    struct AVL *right;
}Node;

int max(int num1, int num2){
    return (num1 > num2) ? num1 :num2;
}

Node *CreateNode(int data){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->height = 1;
    NewNode->left = NULL;
    NewNode->right = NULL;

    return NewNode;
}

int GetHeight(Node* root){
    if(root == NULL)
        return 0;

    return root->height;
}

int GetBF(Node *root){
    if(root == NULL)
        return 0;

    return GetHeight(root->left) - GetHeight(root->right);
}
Node *RotateR(Node *root){
    Node * NewRoot = root->left;
    Node * RST = NewRoot->right;

    NewRoot->right = root;
    root->left = RST;

    root->height = max(GetHeight(root->left), GetHeight(root->right));
    NewRoot->height =  max(GetHeight(NewRoot->left), GetHeight(NewRoot->right));
    return NewRoot;
}


Node *RotateL(Node *root){
    Node * NewRoot = root->right;
    Node * LST = NewRoot->left;

    NewRoot->left = root;
    root->right = LST;

    root->height = max(GetHeight(root->left), GetHeight(root->right));
    NewRoot->height =  max(GetHeight(NewRoot->left), GetHeight(NewRoot->right));

    return NewRoot;
}

Node *Insert(int data, Node *root){
    if(root == NULL)
        return CreateNode(data);
    
    if(data < root->data)
        root->left = Insert(data, root->left);
    else
        root->right = Insert(data, root->right);

    //After Insert, Update Height
    root->height = max(GetHeight(root->right), GetHeight(root->left)) + 1;

    //After Update Height, Update BF
    int bf = GetBF(root);
    if(bf > 1 && data < root->left->data)//R
        return RotateR(root);
    else if(bf > 1 && data > root->left->data){//LR
        root->left = RotateL(root->left);
        return RotateR(root);
    }
    else if(bf < -1 && data > root->right->data)//L
        return RotateL(root);
    else if(bf < -1 && data < root->right->data){//RL
        root->right = RotateR(root->right);
        return RotateL(root);
    }

    return root;
}


Node *GetPredecessor(Node *root){
    Node *cur = root->left;
    while (cur->right != NULL){
        cur = cur->right;
    }
     return cur;
    
}

Node *Delete(int data, Node *root){
    if(root == NULL)
        return;
    
    if(data < root->data)
        root->left = Delete(data, root->left);
    else if (data > root->data)
        root->right = Delete(data, root->right);
    else{// found
        if(root->left && root->right){
            Node *PreDec = GetPredecessor(root);
            root->data = PreDec->data;
            root->left = Delete(PreDec->data, root->left);
        }else{
            Node *temp;
            *temp = (root->left == NULL) ? *(root->right) : *(root->right);
            *root = *temp;
        }
    }

    if(root == NULL)
        return root;

    root->height = max(GetHeight(root->right), GetHeight(root->left)) + 1;

    int bf = GetBF(root);
    if(bf > 1 && GetBF(root->left) >= 0)//R
        return RotateR(root);
    else if(bf > 1 && GetBF(root->left) < 0){//LR
        root->left = RotateL(root->left);
        return RotateR(root);
    }
    else if(bf < -1 && GetBF(root->right) <= 0)//L
        return RotateL(root);
    else if(bf < -1 && data < GetBF(root->right) > 0){//RL
        root->right = RotateR(root->right);
        return RotateL(root);
    }

    return root;
}

int main(void){

}
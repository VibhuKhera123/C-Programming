#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data,height;
    struct node * left;
    struct node * right;
};

int height(struct node *n){
    if (n == NULL){
        return 0;
    }
    else
    {
        return(n->height);
    }
    
}
int max(int a,int b){
    if (a>b)
    {
        return a;
    }
    else{
        return b;
    }
}
int getBalance(struct node *n){
    return(height(n->left)-height(n->right));
}

struct node * rightRotation(struct node *n){
    struct node *x,*temp;
    x=n->left;
    temp = x->right;
    x->right = n;
    n->left=temp;
    n->height = max(height(n->right),height(n->left));
    x->height = max(height(x->right),height(x->left));
    return x;
}

struct node *leftRotation(struct node *n){
    struct node *x,*temp;
    x=n->right;
    temp = x->left;
    x->left = n;
    n->right = temp;
    n->height = max(height(n->right),height(n->left));
    x->height = max(height(x->right),height(x->left));
    return x;
}

struct node *createNode(int value){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->right = newNode->left = NULL;
    newNode->height = 1;
    return(newNode);
}

struct node *insertNode(struct node *n,int value){

    if (n==NULL)
    {
        return(createNode(value));
    }
    else{
        if (value>n->data)
        {
            n->right = insertNode(n->right,value);
        }
        else
        {
            n->left = insertNode(n->left,value);
        }
        return(n);       
    }    
    n->height = 1+max(height(n->left),height(n->right));
    int balance = getBalance(n);
    if(balance>1 && value<n->left->data){
        return (rightRotation(n));
    }
    if (balance<-1 && value>n->right->data)
    {
        return (leftRotation(n));
    }
    if (balance>1 && value>n->left->data)
    {
        n->left = leftRotation(n->left);
        return(rightRotation(n));
    }
    if (balance<-1 && value>n->left->data)
    {
        n->right = rightRotation(n->right);
        return(leftRotation(n));
    }
    else{
        return(n);
    }
}

void printPreOrder(struct node *root){
    if (root!= NULL){
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}


int main() {
  struct Node *root = NULL;

  root = insertNode(root, 2);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 8);

  printPreOrder(root);
  return 0;
}
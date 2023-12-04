#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node * left;
    int data;
    struct node * right;
};

struct node * createTree(struct node * root,int data){
    struct node *temp;
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->right = nn->left = NULL;
    nn->data = data;
    if(root == NULL){
        root = nn;
        root->left=root->right=NULL;
    }
    else
    {
        temp = root;
        while (temp->data<nn->data)
        {
            if (temp->right == NULL)
            {
                temp->right = nn;
            }
            else
            {
                temp = temp->right;
            }
            
        }
        while (temp->data>nn->data)
        {
            if (temp->left == NULL)
            {
                temp->left = nn;
            }
            else
            {
                temp = temp->left;
            }
            
        }
        
    }
    return root;
}
void inorder(struct node *root)  
{  
    if(root == NULL)  
        return;  
  

    inorder(root->left);  
  
  
    printf("%d ",root->data);  

    inorder(root->right);  
}  

int main(){
    struct node * root = NULL;
    int i,n,value;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("Enter the node value: ");
    for (i=0;i<n;i++){
        scanf("%d",&value);
        root = createTree(root,value);
    }
    printf("nodes added\n");
    inorder(root);
    return 0;
}
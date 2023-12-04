#include<stdio.h>
#include<stdlib.h>
struct node {
    int key;
    struct node *left, *right;
};
struct node * createTree(struct node * root,int data){
    struct node *temp;
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->right = nn->left = NULL;
    nn->key = data;
    if(root == NULL){
        root = nn;
        root->left=root->right=NULL;
    }
    else
    {
        temp = root;
        while (temp->key<nn->key)
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
        while (temp->key>nn->key)
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
 
/* Helper function that allocates a new node with the given key and
 NULL left and right pointers. */
struct node* newNode(int key) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
struct node *zagRotation(struct node *x) {              //right rotation
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
struct node *zigRotation(struct node *x) {                 //left rotation
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct node *splay(struct node *root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key > key) {
        if (root->left == NULL)
            return root;
 
        // Zig-Zig (Left Left)
        if (root->left->key > key) {
            
            root->left->left = splay(root->left->left, key);
            root = zagRotation(root);
        } else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = zigRotation(root->left);
        }
        return (root->left == NULL) ? root : zagRotation(root);
    } else 
    {
            if (root->right == NULL)
            return root;
 
        // Zag-Zig (Right Left)
        if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = zagRotation(root->right);
            return (root->right == NULL) ? root : zigRotation(root);
        } else if (root->right->key < key)// Zag-Zag (Right Right)
        {
            root->right->right = splay(root->right->right, key);
            root = zigRotation(root);
        }        
    }
}
struct node *search(struct node *root, int key) {
    return splay(root, key);
}

void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int main() {
    struct node *root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);
 
    printf("Preorder traversal of the Splay tree is \n");
    preOrder(root);
    root = search(root, 20);
    printf("\nPreorder traversal of after search Splay tree is \n");
    preOrder(root);
    return 0;
}
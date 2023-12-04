#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * nxt;
};
struct Node * createList(struct Node * head,int data){
    struct Node * newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->nxt = NULL;
    if(head==NULL){
        head = newnode;
        return head;
    }
    else{
        struct Node * temp = head;
        while (temp->nxt!=NULL)
        {
            temp=temp->nxt;
        }
        temp->nxt = newnode;
        return head;
    }
    
}

struct Node * insertionSortLl(struct Node * head){
    struct Node *nl,*k,*temp,*ptr;
    nl=NULL;
    temp = head;
    
    while (temp != NULL)
    {
        k=temp->nxt;
        if (k->data < nl->data){
            k->nxt = nl;
            return k;
        }
        else
        {
            ptr=temp;
            while (ptr->nxt != NULL && k->data > ptr->nxt->data)
            {
                ptr=ptr->nxt;
            }
            k->nxt = ptr->nxt;
            ptr->nxt = k;
        }
        temp = temp->nxt;
    }
    return nl;
}
struct Node * triverse(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("%d\t",ptr -> data);
        ptr = ptr -> nxt;
    }
    return ptr;
}

int main(){
    int i,n,value;
    struct Node * head = NULL;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter the value to be inserted: ");
        scanf("%d",&value);
        head = createList(head,value);
    }
    printf("List before sorting: ");
    triverse(head);
    head = insertionSortLl(head);
    printf("\nList after sorting: \n");
    triverse(head);
}


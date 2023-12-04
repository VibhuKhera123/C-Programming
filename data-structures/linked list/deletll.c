#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    
};

struct Node * deleteANode(struct Node * head,int value){
    struct Node * ptr = head;
    struct Node * next = head->next;
    if(ptr!=NULL){
        while ((next->data)!=value)
        {
             ptr = ptr->next;
             next = next->next;
        }
        ptr->next = next->next;
        free(next);
    }
    else{
        printf("The List is empty!");
    }
    return head;
}


void triverse(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("%d\n",ptr -> data);
        ptr = ptr -> next;
    }
    
    
}


int main()
{
    int value;

    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * first = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 20;
    head->next = first;

    first->data = 100;
    first->next = second;

    second->data = 80;
    second->next = third;

    third->data = 35;
    third->next = NULL;


    printf("Enter the value you want to delete: ");
    scanf("%d",&value);

    printf("List Before Deletion:\n");
    triverse(head);

    deleteANode(head,value);
    printf("List After deletion:\n");
    triverse(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    
};


struct Node * insertBeginning(struct Node * head,int data){
    if (head!=NULL){
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr -> next = head;
        ptr -> data = data;
        return ptr;
    }
    else{
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->next=NULL;
        ptr->data=data;
        head = ptr;
        return head ;
    }
}


struct Node * insertInBetween(struct Node * head,int data,int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = (struct Node *)malloc(sizeof(struct Node *));
    int i=0;
    if(head == NULL){
        ptr = head;
        ptr->next =NULL;
    }
    else{
        while (i != index-1)
    {
        p = p ->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next = ptr;
    }
    
    return head;
}


struct Node * insertAtEnd(struct Node * head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
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
    struct Node * head;
    struct Node * second;
    struct Node * third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 20;
    third->next = NULL;


    head = insertBegning(head, 50);
    //head = insertAtEnd(head,35);
    //head = insertInBetween(head,48,3);
    triverse(head);
    
    return 0;
}

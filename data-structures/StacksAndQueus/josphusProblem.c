#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
}*head,*temp,*prev;

  void createCircularLL(int n){
    struct node*new_node;
    head=temp=NULL;
    int i;
    for(i=0;i<n;i++)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("enter data for node %d: ",i+1);
        scanf("%d",&(new_node->data));
        new_node->next=NULL;
        if (head==NULL)
        {
            temp=head=new_node;
            
        }else
        {
            temp->next=new_node;
            temp = new_node;
                    
        }
    }
    temp->next=head;
}
void TraversalofCircularLL(){
    struct node *tmp;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else{
        tmp = head;
        printf("\n\n Data entered in the list are :\n");
        do {
            printf(" Data = %d\n", tmp->data);
            tmp = tmp->next;
        }while(tmp != head);
    }
}


void josephusWinner(int k,int n){
    prev = temp = head;
    while (n!=1)
    {
        for (int i = 0; i < k-1; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        
        free(temp);
        temp= prev->next;
        n--;
    }
    printf("the winner is : %d",(head->data));
}
int main(){
    head = NULL;
    int n,k;
    printf("enter the no. of nodes: ");
    scanf("%d",&n);
    printf("Enter the number of steps for josephus game: ");
    scanf("%d",&k);
    createCircularLL(n);
    josephusWinner(k,n);
}
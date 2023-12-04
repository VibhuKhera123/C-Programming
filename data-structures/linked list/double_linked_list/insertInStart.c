#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *previous;
  int data;
  struct node *next;
} * head, *temp,*last;

void create(int data)
{
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->previous = NULL;
  newnode->next = NULL;
  if (head == NULL)
  {
    head = temp = newnode;
  }
  else
  {
    temp->next = newnode;
    newnode->previous = temp;
    temp = newnode;
  }
}
void display()
{
  struct node *temp = head;

  while (temp != NULL)
  {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
}

void begin(int data)
{
  struct node *newnode; 
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->previous = NULL;
  head->previous = newnode;
  newnode->next = head;
  head = newnode;
}

void end(int data)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
    {
        newnode->previous = NULL;
        newnode->next = NULL;
        head = last = newnode;
    }

    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->previous = temp;
        newnode->next = NULL;
    }
}

void position(int data)
{
  struct node *newnode, *temp;
  newnode = (struct node *)malloc(sizeof(struct node));
  int i = 1;
  int pos;
  printf("Enter the postion :");
  scanf("%d", &pos);

  if (pos == 0 || pos > 5)
  {
    printf("invalid position");
  }
  else if (pos == 1)
  {
    begin(data);
  }
  else
  {
    temp = head;
    newnode->data = data;
    while (i < pos - 1)
    {
      temp = temp->next;
      i++;
    }
    newnode->previous = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    temp->next->previous = newnode;
  }
}
int main()
{
  create(5);
  create(8);
  create(4);
  create(7);

  int data;
  printf("Element of linked list: \n");
  display();
  printf("\n\n");
  printf("Enter the value you want to insert :");
  scanf("%d", &data);
  printf("\n");
  position(data);
  printf("\n");
  display();
   printf("\n\n");
  return 0;
}
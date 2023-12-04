#include <stdio.h>
#include <stdlib.h>
typedef struct node {
   int data;
   int priority;
   struct node* next;
} Node;
Node* newNode(int d, int p) {
   Node* temp = (Node*)malloc(sizeof(Node));
   temp->data = d;
   temp->priority = p;
   temp->next = NULL;
   return temp;
}
int peek(Node** head) {
   return (*head)->data;
}
void delete(Node** head) {
   Node* temp = *head;
   (*head) = (*head)->next;
   free(temp);
}
void insert(Node** head, int d, int p) {
   Node* start = (*head);
   Node* temp = newNode(d, p);
   if ((*head)->priority < p) {
      temp->next = *head;
      (*head) = temp;
   } else {
      while (start->next != NULL &&
      start->next->priority > p) {
         start = start->next;
      }
      temp->next = start->next;
      start->next = temp;
   }
}
int isEmpty(Node** head) {
   return (*head) == NULL;
}
int main() {
   Node* pq = newNode(7, 1);
   insert(&pq, 1, 2);
   insert(&pq, 3, 3);
   insert(&pq, 2, 0);
   printf("The queue according to priority is:\n");
   while (!isEmpty(&pq)) {
      printf("%d ", peek(&pq));
      delete(&pq);
   }
   return 0;
}
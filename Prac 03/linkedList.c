#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int value;
 struct Node* next;
} Node;

Node* createNode(int value){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void addNodeAtEnd(Node** head,int value){
  Node* newNode = createNode(value);
  
  if(*head == NULL){
    *head = newNode;
    return;
  }
  
  Node* temp = *head;
  
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

void PrintList(Node* head){
  Node* temp = head;
  while(temp != NULL){
    printf("%d->",temp->value);
    temp = temp->next;
  }
    printf("NULL\n");
}

int main(){
  Node* head = NULL;
  
  PrintList(head);
  
  addNodeAtEnd(&head,10);
  addNodeAtEnd(&head,20);
  addNodeAtEnd(&head,30);
  addNodeAtEnd(&head,40);
  
  PrintList(head);
  return 0;
}

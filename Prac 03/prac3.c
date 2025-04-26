#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void PrintNumber(Node* head){
  Node* temp = head;
  while(temp != NULL){
    printf("%d",temp->value);
    temp = temp->next;
  }
}

Node* takeInput(int number,int size){
  Node* head = NULL;
  int i = 1;
  while(i<=size){
    int value;
    printf("Enter the digit %d of number %d: ",i++,number);
    scanf("%d",&value);
    addNodeAtEnd(&head,value);
  }
  return head;
}

void add(Node* n1,Node* n2){
   Node* head = NULL;
   Node* temp1 = n1;
   Node* temp2 = n2;
   while(temp1 != NULL){
    int value = temp1->value + temp2->value;
    addNodeAtEnd(&head,value);
    temp1 = temp1->next;
    temp2 = temp2->next;
   }
   printf("The Sum of ");
   PrintNumber(n1);
   printf(" and ");
   PrintNumber(n2);
   printf(" is ");
   PrintNumber(head);
   printf(".");
}

void sub(Node* n1,Node* n2){
   Node* head = NULL;
   Node* temp1 = n1;
   Node* temp2 = n2;
   while(temp1 != NULL){
    int value = temp1->value - temp2->value;
    addNodeAtEnd(&head,value);
    temp1 = temp1->next;
    temp2 = temp2->next;
   }
   printf("The Diff of ");
   PrintNumber(n1);
   printf(" and ");
   PrintNumber(n2);
   printf(" is ");
   PrintNumber(head);
   printf(".");
}


int main(){
  int size = 3;
  Node* n1 = takeInput(1,size);
  Node* n2 = takeInput(2,size);
  
  //add(n1,n2);
  sub(n1,n2);
  
  return 0;
}

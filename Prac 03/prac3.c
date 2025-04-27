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

void addNodeAtStart(Node** head,int value){
  Node* newNode = createNode(value);
  
  if(*head == NULL){
    *head = newNode;
    return;
  }
  
  Node* temp = *head;
  newNode->next = temp;
  *head = newNode;
}

void PrintNumber(Node* head){
  Node* temp = head;
  while(temp != NULL){
    printf("%d",temp->value);
    temp = temp->next;
  }
}

void PrintNumberReverse(Node* head){
  Node* temp1 = head;
  Node* temp2 = NULL;
  while(temp1 != NULL){
    addNodeAtStart(&temp2,temp1->value);
    temp1 = temp1->next;
  }
  while(temp2 != NULL){
    printf("%d",temp2->value);
    temp2 = temp2->next;
  }
}

Node* takeInput(int number){
  Node* head = NULL;
  int i = 1;
  while(true){
    int value;
    printf("Enter the digit %d of number %d or enter 10 to exit : ",i++,number);
    scanf("%d",&value);
    if( value == 10 ){
      break;
    }
    if((value / 10) > 0){
        printf("You can only enter a single digit at a time. \n");
        i--;
    }
    addNodeAtStart(&head,value);
  }
  return head;
}

void add(Node* n1,Node* n2){
   Node* head = NULL;
   Node* temp1 = n1;
   Node* temp2 = n2;
   int carry = 0;
   while(temp1 != NULL || temp2 != NULL || carry != 0){
    int val1 = temp1 != NULL ? temp1->value : 0;
    int val2 = temp2 != NULL ? temp2->value : 0;
    
    int sum = val1 + val2 + carry;
    carry = sum / 10;
    int digit = sum % 10;
    
    addNodeAtStart(&head,digit);
    
    if(temp1!=NULL) temp1 = temp1->next;
    if(temp2!=NULL) temp2 = temp2->next;
   }
   printf("The Sum of ");
   PrintNumberReverse(n1);
   printf(" and ");
   PrintNumberReverse(n2);
   printf(" is ");
   PrintNumber(head);
   printf(".");
}


int main(){
  Node* n1 = takeInput(1);
  Node* n2 = takeInput(2);
  
  printf("\n--- ADDITION ---\n");
  add(n1, n2);
  /*
  
  printf("\n--- SUBTRACTION ---\n");
  sub(n1, n2);

  printf("\n--- MULTIPLICATION ---\n");
  mul(n1, n2);

  printf("\n--- EXPONENTIATION ---\n");
  int exponent;
  printf("Enter exponent for first number: ");
  scanf("%d", &exponent);
  exp_(n1, exponent)
  */
  
  return 0;
}

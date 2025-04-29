#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int digit;
    struct Node* next;
} Node;

Node* createNode(int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int digit) {
    Node* newNode = createNode(digit);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* readNumber() {
    char num[1000];
    printf("Enter number: ");
    scanf("%s", num);
    
    Node* head = NULL;
    for (int i = strlen(num) - 1; i >= 0; i--) {
        head = insertAtEnd(head, num[i] - '0');
    }
    return head;
}

void printNumber(Node* head) {
    if (!head) return;
    printNumber(head->next);
    printf("%d", head->digit);
}

Node* add(Node* a, Node* b) {
    Node* result = NULL;
    int carry = 0;
    while (a || b || carry) {
        int sum = carry;
        if (a) { sum += a->digit; a = a->next; }
        if (b) { sum += b->digit; b = b->next; }
        carry = sum / 10;
        result = insertAtEnd(result, sum % 10);
    }
    return result;
}

Node* subtract(Node* a, Node* b) {
    Node* result = NULL;
    int borrow = 0;
    while (a || b) {
        int diff = (a ? a->digit : 0) - (b ? b->digit : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else borrow = 0;
        result = insertAtEnd(result, diff);
        if (a) a = a->next;
        if (b) b = b->next;
    }
    return result;
}

Node* multiply(Node* a, Node* b) {
    int sizeA = 0, sizeB = 0;
    Node *tempA = a, *tempB = b;
    while (tempA) { sizeA++; tempA = tempA->next; }
    while (tempB) { sizeB++; tempB = tempB->next; }
    
    int* prod = (int*)calloc(sizeA + sizeB, sizeof(int));
    
    Node* pa = a;
    int i = 0;
    while (pa) {
        Node* pb = b;
        int j = 0;
        while (pb) {
            prod[i + j] += pa->digit * pb->digit;
            pb = pb->next;
            j++;
        }
        pa = pa->next;
        i++;
    }
    
    for (i = 0; i < sizeA + sizeB; i++) {
        if (prod[i] >= 10) {
            prod[i+1] += prod[i] / 10;
            prod[i] %= 10;
        }
    }
    
    Node* result = NULL;
    int end = sizeA + sizeB - 1;
    while (end > 0 && prod[end] == 0) end--;
    for (i = 0; i <= end; i++) {
        result = insertAtEnd(result, prod[i]);
    }
    
    free(prod);
    return result;
}

Node* power(Node* base, int exponent) {
    Node* result = createNode(1);
    while (exponent) {
        if (exponent % 2 == 1)
            result = multiply(result, base);
        base = multiply(base, base);
        exponent /= 2;
    }
    return result;
}

int main() {
    Node *a, *b, *res;
    int choice, exp;
    
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Exponentiation\nChoice: ");
    scanf("%d", &choice);
    
    if (choice == 4) {
        printf("Enter base number:\n");
        a = readNumber();
        printf("Enter exponent (positive integer): ");
        scanf("%d", &exp);
        res = power(a, exp);
        printf("Result: ");
        printNumber(res);
    } else {
        printf("Enter first number:\n");
        a = readNumber();
        printf("Enter second number:\n");
        b = readNumber();
        
        if (choice == 1) res = add(a, b);
        else if (choice == 2) res = subtract(a, b);
        else if (choice == 3) res = multiply(a, b);
        
        printf("Result: ");
        printNumber(res);
    }
    
    return 0;
}

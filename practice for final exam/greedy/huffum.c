#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tree node for Huffman Tree
struct Node {
    char ch;
    int freq;
    struct Node* left;
    struct Node* right;
};

// Compare function for min-heap (priority queue)
int compare(const void* a, const void* b) {
    return ((struct Node*)a)->freq - ((struct Node*)b)->freq;
}

// Function to create a new tree node
struct Node* createNode(char ch, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print Huffman codes by traversing the tree
void printCodes(struct Node* root, char* code) {
    if (root == NULL) return;

    // If it's a leaf node, print the character and its code
    if (root->left == NULL && root->right == NULL) {
        printf("%c : %s\n", root->ch, code);
        return;
    }

    // Traverse left and right with code
    char leftCode[100], rightCode[100];
    strcpy(leftCode, code);
    strcat(leftCode, "0");
    printCodes(root->left, leftCode);

    strcpy(rightCode, code);
    strcat(rightCode, "1");
    printCodes(root->right, rightCode);
}

// Main function to build Huffman Tree and generate codes
void huffmanCoding(struct Node* characters[], int n) {
    // Step 1: Sort characters based on frequency
    qsort(characters, n, sizeof(struct Node*), compare);

    // Step 2: Build the Huffman Tree
    while (n > 1) {
        // Take two nodes with the smallest frequency
        struct Node* left = characters[0];
        struct Node* right = characters[1];

        // Create a new internal node with combined frequency
        struct Node* newNode = createNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Move the rest of the nodes to the array
        for (int i = 2; i < n; i++) {
            characters[i - 1] = characters[i];
        }
        
        // Insert the new node in the sorted list
        characters[n - 2] = newNode;

        // Re-sort the array after insertion
        qsort(characters, n - 1, sizeof(struct Node*), compare);

        n--;
    }

    // Step 3: Print Huffman Codes
    printf("\nHuffman Codes:\n");
    char code[100] = "";
    struct Node* root = characters[0];
    printCodes(root, code);
}

int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    struct Node* characters[n];
    printf("Enter character and frequency:\n");
    for (int i = 0; i < n; ++i) {
        char ch;
        int freq;
        printf("Character %d: ", i + 1);
        scanf(" %c %d", &ch, &freq);
        characters[i] = createNode(ch, freq);
    }

    huffmanCoding(characters, n);
    return 0;
}

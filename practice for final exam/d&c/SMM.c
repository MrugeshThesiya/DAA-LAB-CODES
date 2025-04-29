#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void addMatrix(int A[][SIZE], int B[][SIZE], int C[][SIZE], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subMatrix(int A[][SIZE], int B[][SIZE], int C[][SIZE], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[][SIZE], int B[][SIZE], int C[][SIZE], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int A11[SIZE][SIZE], A12[SIZE][SIZE], A21[SIZE][SIZE], A22[SIZE][SIZE];
    int B11[SIZE][SIZE], B12[SIZE][SIZE], B21[SIZE][SIZE], B22[SIZE][SIZE];
    int C11[SIZE][SIZE], C12[SIZE][SIZE], C21[SIZE][SIZE], C22[SIZE][SIZE];
    int P1[SIZE][SIZE], P2[SIZE][SIZE], P3[SIZE][SIZE], P4[SIZE][SIZE];
    int P5[SIZE][SIZE], P6[SIZE][SIZE], P7[SIZE][SIZE];
    int temp1[SIZE][SIZE], temp2[SIZE][SIZE];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    subMatrix(B12, B22, temp1, newSize);
    strassen(A11, temp1, P1, newSize);

    addMatrix(A11, A12, temp1, newSize);
    strassen(temp1, B22, P2, newSize);

    addMatrix(A21, A22, temp1, newSize);
    strassen(temp1, B11, P3, newSize);

    subMatrix(B21, B11, temp1, newSize);
    strassen(A22, temp1, P4, newSize);

    addMatrix(A11, A22, temp1, newSize);
    addMatrix(B11, B22, temp2, newSize);
    strassen(temp1, temp2, P5, newSize);

    subMatrix(A12, A22, temp1, newSize);
    addMatrix(B21, B22, temp2, newSize);
    strassen(temp1, temp2, P6, newSize);

    subMatrix(A11, A21, temp1, newSize);
    addMatrix(B11, B12, temp2, newSize);
    strassen(temp1, temp2, P7, newSize);

    addMatrix(P5, P4, temp1, newSize);
    subMatrix(temp1, P2, temp2, newSize);
    addMatrix(temp2, P6, C11, newSize);

    addMatrix(P1, P2, C12, newSize);
    addMatrix(P3, P4, C21, newSize);

    addMatrix(P1, P5, temp1, newSize);
    subMatrix(temp1, P3, temp2, newSize);
    subMatrix(temp2, P7, C22, newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter size of matrices (must be power of 2): ");
    scanf("%d", &n);

    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = 0;

    strassen(A, B, C, n);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
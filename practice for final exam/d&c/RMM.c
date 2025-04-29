#include<stdio.h>

#define SIZE 10

void RMM(int x[][SIZE], int y[][SIZE], int z[][SIZE], int n, int i, int j, int k) {
    if (i >= n)  
        return;

    if (j < n) {  
        if (k < n) { 
            z[i][j] += x[i][k] * y[k][j];
            RMM(x, y, z, n, i, j, k + 1);
        } else {  
            RMM(x, y, z, n, i, j + 1, 0);
        }
    } else {  
        RMM(x, y, z, n, i + 1, 0, 0);
    }
}

int main() {
    int n;
    printf("Enter size of matrix (n x n): ");
    scanf("%d", &n);

    int x[SIZE][SIZE], y[SIZE][SIZE], z[SIZE][SIZE];

    printf("Enter elements of matrix X:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &x[i][j]);

    printf("Enter elements of matrix Y:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &y[i][j]);

    // Initialize result matrix to zero
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            z[i][j] = 0;

    RMM(x, y, z, n, 0, 0, 0);

    printf("Resultant matrix Z:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", z[i][j]);
        }
        printf("\n");
    }

    return 0;
}

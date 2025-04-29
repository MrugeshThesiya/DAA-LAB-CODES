#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter total number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter the dimensions of matrices:\n");
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &p[i]);
    }

    int m[n][n];
    int s[n][n];

    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }

    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            int j = i + d;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i)
                printf("  - ");
            else
                printf("%3d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}

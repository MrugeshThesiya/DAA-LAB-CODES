#include <stdio.h>

int coinChange(int coins[], int n, int V) {
    int arr[n + 1][V + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            if (j == 0) {
                arr[i][j] = 1;  // Only one way to make 0 value (no coin)
            } else if (i == 0) {
                arr[i][j] = 0;  // No way to make value j with 0 coins
            } else if (coins[i - 1] > j) {
                arr[i][j] = arr[i - 1][j];  // Exclude the coin
            } else {
                arr[i][j] = arr[i - 1][j] + arr[i][j - coins[i - 1]];  // Include + Exclude
            }
        }
    }

    return arr[n][V];
}

int main() {
    int n, V;
    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter the value of coins you have: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the value to be made: ");
    scanf("%d", &V);

    int result = coinChange(coins, n, V);
    printf("The total number of ways to make the value %d is: %d\n", V, result);

    return 0;
}

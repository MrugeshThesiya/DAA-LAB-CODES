#include <stdio.h>

// Define the Item structure
struct Item {
    int w; // weight
    int v; // value
};

// Function to solve the 0/1 Knapsack problem
int Knapsack(struct Item arr[], int W, int n) {
    int v[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                v[i][w] = 0;
            } else if (arr[i-1].w <= w) {
                int include = v[i-1][w - arr[i-1].w] + arr[i-1].v;
                int exclude = v[i-1][w];
                v[i][w] = (include > exclude) ? include : exclude;
            } else {
                v[i][w] = v[i-1][w];
            }
        }
    }

    return v[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the Knapsack: ");
    scanf("%d", &W);

    struct Item arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &arr[i].v, &arr[i].w);
    }

    int result = Knapsack(arr, W, n);
    printf("Maximum Profit: %d\n", result);

    return 0;
}

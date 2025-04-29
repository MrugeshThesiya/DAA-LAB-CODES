#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    double ratio; // value/weight ratio
};

// Comparison function for qsort
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    
    if (item2->ratio > item1->ratio) return 1;
    else if (item2->ratio < item1->ratio) return -1;
    else return 0;
}

void fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items by value/weight ratio in descending order
    qsort(arr, n, sizeof(struct Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", totalValue);
}

int main() {
    int n, W;
    printf("Enter the total number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    struct Item arr[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
        arr[i].ratio = (double)arr[i].value / arr[i].weight;
    }

    fractionalKnapsack(W, arr, n);

    return 0;
}

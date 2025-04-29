#include <stdio.h>

// Function to find minimum and maximum
void MinMax(int arr[], int low, int high, int *min, int *max) {
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
    } else if (low == high) {
        // Only one element
        *max = *min = arr[low];
    } else {
        int mid = (low + high) / 2;
        int min1, min2, max1, max2;

        MinMax(arr, low, mid, &min1, &max1);
        MinMax(arr, mid + 1, high, &min2, &max2);

        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min, max;
    MinMax(arr, 0, n - 1, &min, &max);
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}

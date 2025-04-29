#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (like in QuickSort)
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int index = low;

    for (int i = low + 1; i <= high; i++) {
        if (pivot >= arr[i]) {
            index++;
            swap(&arr[i], &arr[index]);
        }
    }
    swap(&arr[low], &arr[index]);
    return index;
}

// QuickSelect function to find the k-th smallest element
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex > k) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }
    return -1; // error case
}

// Median function
void findMedian(int arr[], int low, int high) {
    int n = high - low + 1;

    if (n % 2 == 1) {
        int median = quickSelect(arr, low, high, low + n / 2);
        printf("Median is: %d\n", median);
    } else {
        int m1 = quickSelect(arr, low, high, low + (n / 2) - 1);
        int m2 = quickSelect(arr, low, high, low + (n / 2));
        printf("Median is: %.1f\n", (m1 + m2) / 2.0);
    }
}

// Main function
int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findMedian(arr, 0, n - 1);
    return 0;
}

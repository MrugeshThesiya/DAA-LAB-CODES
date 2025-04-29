#include <stdio.h>

int BinarySearch(int a[], int l, int h, int x) {
    if (l == h) {
        if (x == a[l]) {
            return l;
        } else {
            return -1;
        }
    } else {
        int mid = (l + h) / 2;
        if (x == a[mid]) {
            return mid;
        } else if (x < a[mid]) {
            return BinarySearch(a, l, mid - 1, x);
        } else {
            return BinarySearch(a, mid + 1, h, x);
        }
    }
}

int LinearSearch(int a[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int l;
    printf("Binary Search - 0 | Linear Search - 1 : ");
    scanf("%d", &l);

    if (l == 0 || l == 1) {
        int size, n;
        printf("Enter size of array: ");
        scanf("%d", &size);

        int a[size];
        for (int i = 0; i < size; i++) {
            printf("Enter %d element of array: ", i + 1);
            scanf("%d", &a[i]);
        }

        printf("Enter number to find in array: ");
        scanf("%d", &n);

        int r = (l == 0)
            ? BinarySearch(a, 0, size - 1, n)
            : LinearSearch(a, size, n);

        if (r == -1) {
            printf("Number not found in array\n");
        } else {
            printf("Number found at index %d\n", r);
        }
    } else {
        printf("Enter valid number (0 or 1)\n");
    }

    return 0;
}

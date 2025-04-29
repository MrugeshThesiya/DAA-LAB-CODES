#include<stdio.h>

void Merge(int a[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    int size = h - l + 1;
    int c[size];

    while (i <= mid && j <= h) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    while (i <= mid) {
        c[k++] = a[i++];
    }

    while (j <= h) {
        c[k++] = a[j++];
    }
    for (i = 0; i < size; i++) {
        a[l + i] = c[i];
    }
}

void MergeSort(int a[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, h);
        Merge(a, l, mid, h);
    }
}

int main() {
    int size;
    printf("Size of Array: ");
    scanf("%d", &size);

    int a[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    MergeSort(a, 0, size - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}

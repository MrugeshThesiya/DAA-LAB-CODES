#include<stdio.h>

int Partition(int a[], int l, int h) {
    int pivot = a[l];
    int i = l, j = h;

    while (i < j) {
        while (a[i] <= pivot && i < h) i++;
        while (a[j] >= pivot) j--;
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    
    return j;
}

void QuickSort(int a[], int l, int h) {
    if (l < h) {
        int j = Partition(a, l, h);
        QuickSort(a, l, j - 1);
        QuickSort(a, j + 1, h);
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
    
    QuickSort(a, 0, size - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}

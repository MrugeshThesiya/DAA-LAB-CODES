#include <stdio.h>
#include <stdlib.h>

// Structure to hold the intervals (start, end)
struct Interval {
    int start;
    int end;
};

// Compare function for sorting intervals by start time
int compare(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

// Function to calculate the number of rooms required
void intervalPartitioning(int start[], int end[], int n) {
    struct Interval intervals[n];
    
    // Store the intervals
    for (int i = 0; i < n; i++) {
        intervals[i].start = start[i];
        intervals[i].end = end[i];
    }
    
    // Sort intervals by start time
    qsort(intervals, n, sizeof(struct Interval), compare);

    // Priority queue to track the end times (min-heap)
    int minHeap[n];
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        int j = 0;
        
        // Check if we can reuse a room
        while (j < heapSize && intervals[i].start >= minHeap[j]) {
            // Reuse room
            minHeap[j] = minHeap[heapSize - 1];
            heapSize--;
            break;
        }
        
        // Add the new room
        minHeap[heapSize++] = intervals[i].end;
    }

    // Number of rooms is the size of the heap
    printf("Number of rooms required: %d\n", heapSize);
}

int main() {
    int n;
    printf("Enter total number of intervals: ");
    scanf("%d", &n);

    int start[n], end[n];
    
    printf("Enter the start time of the intervals:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    printf("Enter the end time of the intervals:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &end[i]);
    }

    intervalPartitioning(start, end, n);
    
    return 0;
}

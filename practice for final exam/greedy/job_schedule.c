#include <stdio.h>
#include <stdlib.h>

// Structure to store job information (profit, deadline)
struct Job {
    int profit;
    int deadline;
};

// Compare function to sort jobs in descending order of profit
int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

// Job Sequencing function
void jobSequencing(struct Job jobs[], int n) {
    // Sort jobs in descending order of profit
    qsort(jobs, n, sizeof(struct Job), compare);

    // Array to store the result (job sequences)
    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = -1; // Initialize result with -1
    }

    // Array to keep track of available slots
    int slot[n];
    for (int i = 0; i < n; i++) {
        slot[i] = 0; // Initialize slots as free
    }

    // Iterate through the jobs and find a slot for each job
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) { // If slot is free
                slot[j] = 1; // Mark slot as occupied
                result[j] = i; // Assign job to this slot
                break;
            }
        }
    }

    // Calculate total profit
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            totalProfit += jobs[result[i]].profit; // Calculate total profit
        }
    }

    printf("Total profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter the total number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];
    printf("Enter the profit and deadline of each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d", &jobs[i].profit, &jobs[i].deadline);
    }

    jobSequencing(jobs, n);
    return 0;
}

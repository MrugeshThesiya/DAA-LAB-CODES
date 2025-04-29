#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int start, end;
    char name;
} Event;

int compare(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    return e1->end - e2->end;
}

int main() {
    int n;
    printf("Enter number of events: ");
    scanf("%d", &n);

    Event events[n];
    for (int i = 0; i < n; i++) {
        printf("Enter name, start time, end time of event %d: ", i + 1);
        scanf(" %c %d %d", &events[i].name, &events[i].start, &events[i].end);
    }

    qsort(events, n, sizeof(Event), compare);

    printf("\nSelected Events:\n");
    int last_end = -1;
    for (int i = 0; i < n; i++) {
        if (events[i].start >= last_end) {
            printf("%c (%d,%d)\n", events[i].name, events[i].start, events[i].end);
            last_end = events[i].end;
        }
    }

    return 0;
}

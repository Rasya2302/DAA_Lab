#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int type;   // 1 = entry, -1 = exit
} Event;

int compare(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    return e1->time - e2->time;
}

int main() {
    int n;

    printf("Enter number of people: ");
    scanf("%d", &n);

    Event events[2 * n];

    for (int i = 0; i < n; i++) {
        int a, b;

        printf("Enter entry and exit time for person %d: ",
               i + 1);

        scanf("%d %d", &a, &b);

        events[2 * i].time = a;
        events[2 * i].type = 1;

        events[2 * i + 1].time = b;
        events[2 * i + 1].type = -1;
    }

    qsort(events, 2 * n, sizeof(Event), compare);

    int current = 0;
    int maximum = 0;
    int maxTime = 0;

    for (int i = 0; i < 2 * n; i++) {

        if (events[i].type == 1) {
            current++;

            if (current > maximum) {
                maximum = current;
                maxTime = events[i].time;
            }
        }
        else {
            current--;
        }
    }

    printf("\nMaximum people present = %d\n", maximum);
    printf("Time = %d\n", maxTime);

    return 0;
}
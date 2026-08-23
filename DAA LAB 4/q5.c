#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;

    if (i1->start != i2->start)
        return i1->start - i2->start;

    return i1->end - i2->end;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d",
              &arr[i].start,
              &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int count = 0;

    int currentStart = arr[0].start;
    int currentEnd = arr[0].end;

    for (int i = 1; i < n; i++) {

        if (arr[i].start <= currentEnd) {

            if (arr[i].end > currentEnd)
                currentEnd = arr[i].end;
        }
        else {

            result[count].start = currentStart;
            result[count].end = currentEnd;
            count++;

            currentStart = arr[i].start;
            currentEnd = arr[i].end;
        }
    }

    result[count].start = currentStart;
    result[count].end = currentEnd;
    count++;

    printf("\nMerged intervals:\n");

    for (int i = 0; i < count; i++) {
        printf("(%d, %d)\n",
               result[i].start,
               result[i].end);
    }

    return 0;
}
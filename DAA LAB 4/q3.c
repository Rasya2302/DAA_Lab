#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return 1;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int findKSum(int arr[], int n, int k,
             int start, int remaining,
             int target) {

    /*
       We have selected k-1 elements.
       Now search for the final element.
    */

    if (remaining == 1) {
        int required = target;

        if (binarySearch(arr + start,
                         n - start,
                         required)) {
            return 1;
        }

        return 0;
    }

    for (int i = start; i < n; i++) {

        if (findKSum(arr, n, k,
                     i + 1,
                     remaining - 1,
                     target - arr[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, k, T;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter T: ");
    scanf("%d", &T);

    qsort(arr, n, sizeof(int), compare);

    if (k > n || k <= 0) {
        printf("Invalid k\n");
        return 0;
    }

    if (findKSum(arr, n, k, 0, k, T))
        printf("YES: %d elements can make sum %d\n", k, T);
    else
        printf("NO: No such combination exists\n");

    return 0;
}
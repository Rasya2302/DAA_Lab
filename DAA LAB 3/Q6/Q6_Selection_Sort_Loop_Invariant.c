#include <stdio.h>
#include <stdlib.h>
#include <time.h>



long long comparisons = 0;

void selectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (A[j] < A[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
        {
            int temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }
}

int isSorted(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
            return 0;
    }

    return 1;
}

int main()
{
    
    int sizes[] = {10, 100, 1000, 5000, 10000};
    int count = sizeof(sizes) / sizeof(sizes[0]);

    FILE *fp = fopen("result.txt", "w");

    if (fp == NULL)
    {
        printf("Error creating result.txt\n");
        return 1;
    }

    fprintf(fp, "# n actual_comparisons theoretical_n2\n");

    printf("Selection Sort using Loop Invariant\n\n");
    printf("%-10s %-25s %-20s\n",
           "n", "Actual Comparisons", "n(n-1)/2");
    printf("--------------------------------------------------------\n");

    for (int s = 0; s < count; s++)
    {
        int n = sizes[s];

        int *A = malloc(n * sizeof(int));

        if (A == NULL)
        {
            printf("Memory allocation failed for n = %d\n", n);
            fclose(fp);
            return 1;
        }

        /*
            Reverse-sorted input gives a clear test case.
        */
        for (int i = 0; i < n; i++)
            A[i] = n - i;

        comparisons = 0;

        selectionSort(A, n);

        long long theoretical =
            ((long long)n * (n - 1)) / 2;

        printf("%-10d %-25lld %-20lld\n",
               n, comparisons, theoretical);

        fprintf(fp, "%d %lld %lld\n",
                n, comparisons, theoretical);

        if (!isSorted(A, n))
        {
            printf("Sorting validation failed for n = %d\n", n);
            free(A);
            fclose(fp);
            return 1;
        }

        if (n == 10)
        {
            printf("\nSorted array for n = 10:\n");

            for (int i = 0; i < n; i++)
                printf("%d ", A[i]);

            printf("\n\n");
        }

        free(A);
    }

    fclose(fp);

    printf("result.txt generated automatically.\n");
    printf("\nWorst-case running time : Theta(n^2)\n");
    printf("Best-case running time  : Theta(n^2)\n");

    return 0;
}
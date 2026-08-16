#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int min;
    int max;
} MinMax;

long long comparisons = 0;

MinMax findMinMax(int A[], int low, int high)
{
    MinMax result;
    MinMax leftResult;
    MinMax rightResult;

    /* One element */
    if (low == high)
    {
        result.min = A[low];
        result.max = A[low];
        return result;
    }

    /* Two elements */
    if (high == low + 1)
    {
        comparisons++;

        if (A[low] < A[high])
        {
            result.min = A[low];
            result.max = A[high];
        }
        else
        {
            result.min = A[high];
            result.max = A[low];
        }

        return result;
    }

    /* Divide */
    int mid = low + (high - low) / 2;

    /* Conquer */
    leftResult = findMinMax(A, low, mid);
    rightResult = findMinMax(A, mid + 1, high);

    /* Combine minimum */
    comparisons++;

    if (leftResult.min < rightResult.min)
        result.min = leftResult.min;
    else
        result.min = rightResult.min;

    /* Combine maximum */
    comparisons++;

    if (leftResult.max > rightResult.max)
        result.max = leftResult.max;
    else
        result.max = rightResult.max;

    return result;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of elements must be positive.\n");
        return 1;
    }

    int *A = malloc(n * sizeof(int));

    if (A == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    comparisons = 0;

    MinMax result = findMinMax(A, 0, n - 1);

    printf("\n----------------------------------\n");
    printf("Minimum = %d\n", result.min);
    printf("Maximum = %d\n", result.max);
    printf("Number of comparisons = %lld\n", comparisons);

    /*
        The required bound in the question is 3n/2.
        For even n, the tighter bound is 3n/2 - 2.
    */
    printf("3n/2 bound = %.0f\n", 1.5 * n);

    free(A);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>



long long multiplicationCount = 0;
long long additionCount = 0;

void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
            additionCount++;
        }
    }
}

void specialMultiply(int n, int A[n][n], int B[n][n], int C[n][n])
{
    /* Base case */
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        multiplicationCount++;
        return;
    }

    int k = n / 2;

    
    int (*A1)[k] = malloc(k * sizeof(*A1));
    int (*A2)[k] = malloc(k * sizeof(*A2));
    int (*B1)[k] = malloc(k * sizeof(*B1));
    int (*B2)[k] = malloc(k * sizeof(*B2));

    int (*AC)[k] = malloc(k * sizeof(*AC));
    int (*BD)[k] = malloc(k * sizeof(*BD));
    int (*AD)[k] = malloc(k * sizeof(*AD));
    int (*BC)[k] = malloc(k * sizeof(*BC));

    if (!A1 || !A2 || !B1 || !B2 ||
        !AC || !BD || !AD || !BC)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    
    specialMultiply(k, A1, B1, AC);
    specialMultiply(k, A2, B2, BD);
    specialMultiply(k, A1, B2, AD);
    specialMultiply(k, A2, B1, BC);

   
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = AC[i][j] + BD[i][j];
            C[i][j + k] = AD[i][j] + BC[i][j];
            C[i + k][j] = AD[i][j] + BC[i][j];
            C[i + k][j + k] = AC[i][j] + BD[i][j];

            additionCount += 4;
        }
    }

    free(A1);
    free(A2);
    free(B1);
    free(B2);

    free(AC);
    free(BD);
    free(AD);
    free(BC);
}

void createSpecialMatrix(int n, int A[n][n], int x, int y)
{
    
    if (n == 1)
    {
        A[0][0] = x;
        return;
    }

    int k = n / 2;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A[i][j] = x;
            A[i][j + k] = y;
            A[i + k][j] = y;
            A[i + k][j + k] = x;
        }
    }
}

void printMatrix(int n, int A[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%5d", A[i][j]);

        printf("\n");
    }
}

int main()
{
    
    int sizes[] = {2, 4, 8, 16, 32, 64};
    int count = sizeof(sizes) / sizeof(sizes[0]);

    FILE *fp = fopen("result.txt", "w");

    if (fp == NULL)
    {
        printf("Error creating result.txt\n");
        return 1;
    }

    
    fprintf(fp, "# n actual_multiplications n_squared\n");

    printf("Special-Pattern Matrix Multiplication\n\n");
    printf("%-10s %-25s %-20s\n",
           "n", "Actual Multiplications", "n^2");
    printf("--------------------------------------------------------\n");

    for (int s = 0; s < count; s++)
    {
        int n = sizes[s];

        int (*A)[n] = malloc(n * sizeof(*A));
        int (*B)[n] = malloc(n * sizeof(*B));
        int (*C)[n] = malloc(n * sizeof(*C));

        if (!A || !B || !C)
        {
            printf("Memory allocation failed for n = %d\n", n);
            fclose(fp);
            return 1;
        }

        createSpecialMatrix(n, A, 1, 2);
        createSpecialMatrix(n, B, 2, 3);

        multiplicationCount = 0;
        additionCount = 0;

        specialMultiply(n, A, B, C);

        long long theoretical = (long long)n * n;

        printf("%-10d %-25lld %-20lld\n",
               n, multiplicationCount, theoretical);

        fprintf(fp, "%d %lld %lld\n",
                n, multiplicationCount, theoretical);

       
        if (n == 4)
        {
            printf("\nMatrix A (n = 4):\n");
            printMatrix(n, A);

            printf("\nMatrix B (n = 4):\n");
            printMatrix(n, B);

            printf("\nA x B:\n");
            printMatrix(n, C);

            printf("\n");
        }

        free(A);
        free(B);
        free(C);
    }

    fclose(fp);

    printf("result.txt generated automatically.\n");
    printf("\nRecurrence: T(n) = 4T(n/2) + O(n^2)\n");
    printf("Time Complexity: O(n^2)\n");

    return 0;
}
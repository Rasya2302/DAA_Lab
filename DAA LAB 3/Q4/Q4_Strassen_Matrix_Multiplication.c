#include <stdio.h>
#include <stdlib.h>

/*
    Question 4: Matrix Multiplication using Strassen's Method

    Strassen's method uses 7 recursive matrix multiplications
    instead of 8.

    Recurrence:
        T(n) = 7T(n/2) + O(n^2)

    Time Complexity:
        O(n^log2(7)) approximately O(n^2.807)

    This implementation requires n to be a power of 2.
*/

void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    /* Base case */
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int (*A11)[k] = malloc(k * sizeof(*A11));
    int (*A12)[k] = malloc(k * sizeof(*A12));
    int (*A21)[k] = malloc(k * sizeof(*A21));
    int (*A22)[k] = malloc(k * sizeof(*A22));

    int (*B11)[k] = malloc(k * sizeof(*B11));
    int (*B12)[k] = malloc(k * sizeof(*B12));
    int (*B21)[k] = malloc(k * sizeof(*B21));
    int (*B22)[k] = malloc(k * sizeof(*B22));

    int (*P1)[k] = malloc(k * sizeof(*P1));
    int (*P2)[k] = malloc(k * sizeof(*P2));
    int (*P3)[k] = malloc(k * sizeof(*P3));
    int (*P4)[k] = malloc(k * sizeof(*P4));
    int (*P5)[k] = malloc(k * sizeof(*P5));
    int (*P6)[k] = malloc(k * sizeof(*P6));
    int (*P7)[k] = malloc(k * sizeof(*P7));

    int (*T1)[k] = malloc(k * sizeof(*T1));
    int (*T2)[k] = malloc(k * sizeof(*T2));

    if (!A11 || !A12 || !A21 || !A22 ||
        !B11 || !B12 || !B21 || !B22 ||
        !P1 || !P2 || !P3 || !P4 || !P5 || !P6 || !P7 ||
        !T1 || !T2)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    /* Divide */
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    /* Seven Strassen products */

    /* P1 = A11 * (B12 - B22) */
    subtractMatrix(k, B12, B22, T1);
    strassen(k, A11, T1, P1);

    /* P2 = (A11 + A12) * B22 */
    addMatrix(k, A11, A12, T1);
    strassen(k, T1, B22, P2);

    /* P3 = (A21 + A22) * B11 */
    addMatrix(k, A21, A22, T1);
    strassen(k, T1, B11, P3);

    /* P4 = A22 * (B21 - B11) */
    subtractMatrix(k, B21, B11, T1);
    strassen(k, A22, T1, P4);

    /* P5 = (A11 + A22) * (B11 + B22) */
    addMatrix(k, A11, A22, T1);
    addMatrix(k, B11, B22, T2);
    strassen(k, T1, T2, P5);

    /* P6 = (A12 - A22) * (B21 + B22) */
    subtractMatrix(k, A12, A22, T1);
    addMatrix(k, B21, B22, T2);
    strassen(k, T1, T2, P6);

    /* P7 = (A21 - A11) * (B11 + B12) */
    subtractMatrix(k, A21, A11, T1);
    addMatrix(k, B11, B12, T2);
    strassen(k, T1, T2, P7);

    /* Combine */
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] =
                P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];

            C[i][j + k] =
                P1[i][j] + P2[i][j];

            C[i + k][j] =
                P3[i][j] + P4[i][j];

            C[i + k][j + k] =
                P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }

    /* Free memory */
    free(A11);
    free(A12);
    free(A21);
    free(A22);

    free(B11);
    free(B12);
    free(B21);
    free(B22);

    free(P1);
    free(P2);
    free(P3);
    free(P4);
    free(P5);
    free(P6);
    free(P7);

    free(T1);
    free(T2);
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

int isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    int n;

    printf("Enter matrix size n: ");
    scanf("%d", &n);

    if (!isPowerOfTwo(n))
    {
        printf("n must be a power of 2.\n");
        printf("Examples: 1, 2, 4, 8, 16...\n");
        return 1;
    }

    int (*A)[n] = malloc(n * sizeof(*A));
    int (*B)[n] = malloc(n * sizeof(*B));
    int (*C)[n] = malloc(n * sizeof(*C));

    if (!A || !B || !C)
    {
        printf("Memory allocation failed.\n");
        free(A);
        free(B);
        free(C);
        return 1;
    }

    printf("\nEnter elements of Matrix A:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter elements of Matrix B:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(n, A, B, C);

    printf("\nMatrix A:\n");
    printMatrix(n, A);

    printf("\nMatrix B:\n");
    printMatrix(n, B);

    printf("\nA x B using Strassen's Method:\n");
    printMatrix(n, C);

    free(A);
    free(B);
    free(C);

    return 0;
}
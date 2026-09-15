#include <stdio.h>

#define MAX 10

int main()
{
    int n;
    int p[MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter %d + 1 dimensions: ", n);

    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    int dp[MAX][MAX];

    // One matrix needs 0 multiplication
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    // Try chains of different lengths
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = 999999;

            // Try every possible position
            // to split the matrices
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("\nMinimum number of scalar multiplications = %d\n",
           dp[1][n]);

    return 0;
}
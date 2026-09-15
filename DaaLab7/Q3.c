#include <stdio.h>

#define MAX 20

long long dp[MAX + 1];

/* Number of moves for normal 3-peg Hanoi */
long long hanoi3(int n)
{
    if (n == 0)
        return 0;

    return 2 * hanoi3(n - 1) + 1;
}

int main()
{
    int n, k;
    long long moves, minimum;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    /* No disk = 0 moves */
    dp[0] = 0;

    /* One disk = 1 move */
    dp[1] = 1;

    /* Calculate minimum moves */
    for (int i = 2; i <= n; i++)
    {
        minimum = 999999999;

        /* Try different values of k */
        for (k = 1; k < i; k++)
        {
            moves = 2 * dp[k] + hanoi3(i - k);

            if (moves < minimum)
            {
                minimum = moves;
            }
        }

        dp[i] = minimum;
    }

    printf("Minimum number of moves = %lld\n", dp[n]);

    return 0;
}
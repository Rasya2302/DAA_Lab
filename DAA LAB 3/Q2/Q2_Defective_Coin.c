#include <stdio.h>
#include <stdlib.h>

#define NORMAL_WEIGHT 10

int weighing_count = 0;


int weigh(int coins[], int l1, int r1, int l2, int r2)
{
    int left_weight = 0;
    int right_weight = 0;

    for (int i = l1; i <= r1; i++)
        left_weight += coins[i];

    for (int i = l2; i <= r2; i++)
        right_weight += coins[i];

    weighing_count++;

    if (left_weight < right_weight)
        return -1;

    if (left_weight > right_weight)
        return 1;

    return 0;
}

/*
    Divide and Conquer
*/
int findDefective(int coins[], int left, int right)
{
    int n = right - left + 1;

    /* One coin remains */
    if (n == 1)
    {
        if (coins[left] < NORMAL_WEIGHT)
            return left;

        return -1;
    }

    /*
        Two coins
    */
    if (n == 2)
    {
        int result = weigh(coins, left, left, right, right);

        if (result == -1)
            return left;

        if (result == 1)
            return right;

        return -1;
    }

    /*
        Divide into two equal groups.
        If n is odd, one coin remains outside.
    */
    int group_size = n / 2;

    int left_start = left;
    int left_end = left + group_size - 1;

    int right_start = left_end + 1;
    int right_end = right_start + group_size - 1;

    int result = weigh(
        coins,
        left_start,
        left_end,
        right_start,
        right_end
    );

    /* Left side is lighter */
    if (result == -1)
    {
        return findDefective(
            coins,
            left_start,
            left_end
        );
    }

    /* Right side is lighter */
    if (result == 1)
    {
        return findDefective(
            coins,
            right_start,
            right_end
        );
    }

    /*
        Both sides are equal.

        Therefore the two groups contain only normal
        coins. If n is odd, check the remaining coin.
    */
    if (n % 2 == 1)
    {
        int remaining = right_end + 1;

        if (coins[remaining] < NORMAL_WEIGHT)
            return remaining;
    }

    return -1;
}

int main()
{
    int n;

    printf("Normal coin weight = %d\n", NORMAL_WEIGHT);

    printf("Enter number of coins: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of coins.\n");
        return 1;
    }

    int *coins = malloc(n * sizeof(int));

    if (coins == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nEnter weights of %d coins:\n", n);
    printf("Normal coin = %d\n", NORMAL_WEIGHT);
    printf("Defective coin must be lighter than %d.\n\n",
           NORMAL_WEIGHT);

    for (int i = 0; i < n; i++)
    {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coins[i]);

        if (coins[i] <= 0 || coins[i] > NORMAL_WEIGHT)
        {
            printf("Invalid weight. Enter a value from 1 to %d.\n",
                   NORMAL_WEIGHT);

            free(coins);
            return 1;
        }
    }

    weighing_count = 0;

    int defective = findDefective(coins, 0, n - 1);

    printf("\n================================\n");

    if (defective == -1)
    {
        printf("No lighter defective coin found.\n");
    }
    else
    {
        printf("Defective coin: %d\n", defective + 1);
        printf("Weight: %d\n", coins[defective]);
    }

    printf("Balance weighings: %d\n", weighing_count);

    printf("================================\n");

    free(coins);

    return 0;
}
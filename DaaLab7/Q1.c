#include <stdio.h>

int main()
{
    int n, totalCoins, minMoves;

    printf("Enter number of rows in triangle: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of rows.\n");
        return 0;
    }

    // Total number of coins
    totalCoins = n * (n + 1) / 2;

    // Minimum number of moves
    minMoves = totalCoins / 3;

    printf("\nTotal coins = %d\n", totalCoins);
    printf("Minimum number of moves = %d\n", minMoves);

    return 0;
}
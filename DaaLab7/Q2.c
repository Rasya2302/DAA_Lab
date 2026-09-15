#include <stdio.h>

#define MAX_EGGS 10
#define MAX_FLOORS 100

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}

int min(int a, int b){
    if (a < b)
        return a;
    return b;
}

int main(){
    int E, F;
    int dp[MAX_EGGS + 1][MAX_FLOORS + 1];

    printf("Enter number of eggs: ");
    scanf("%d", &E);

    printf("Enter number of floors: ");
    scanf("%d", &F);

    // 0 floors = 0 drops
    for (int e = 1; e <= E; e++)
        dp[e][0] = 0;

    // 1 floor = 1 drop
    for (int e = 1; e <= E; e++)
        dp[e][1] = 1;

    // With only 1 egg, test every floor
    for (int f = 1; f <= F; f++)
        dp[1][f] = f;

    // Main DP
    for (int e = 2; e <= E; e++)
    {
        for (int f = 2; f <= F; f++)
        {
            dp[e][f] = F;

            // Try dropping from every floor
            for (int x = 1; x <= f; x++)
            {
                int breaks = dp[e - 1][x - 1];
                int survives = dp[e][f - x];

                int attempts = 1 + max(breaks, survives);

                dp[e][f] = min(dp[e][f], attempts);
            }
        }
    }

    printf("\nMinimum number of drops = %d\n", dp[E][F]);

    return 0;
}
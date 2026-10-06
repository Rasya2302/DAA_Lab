#include <stdio.h>

#define INF 999999

int main(){
    int n;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    float p[n + 1];
    float q[n + 1];

    float e[n + 2][n + 1];
    float w[n + 2][n + 1];

    int root[n + 1][n + 1];

    printf("Enter successful probabilities p:\n");

    for(int i = 1; i <= n; i++)
        scanf("%f", &p[i]);

    printf("Enter unsuccessful probabilities q:\n");

    for(int i = 0; i <= n; i++)
        scanf("%f", &q[i]);

    /* Empty trees */

    for(int i = 1; i <= n + 1; i++){
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    /* DP */

    for(int length = 1; length <= n; length++){
        for(int i = 1; i <= n - length + 1; i++){
            int j = i + length - 1;

            e[i][j] = INF;

            w[i][j] = w[i][j - 1]
                    + p[j]
                    + q[j];

            for(int r = i; r <= j; r++){
                float cost =e[i][r - 1] + e[r + 1][j] + w[i][j];

                if(cost < e[i][j]){
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("\nMinimum Expected Cost = %.2f\n",e[1][n]);

    printf("Root = Key %d\n", root[1][n]);

    return 0;
}
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c){
    if(a < b && a < c)
        return a;

    if(b < c)
        return b;

    return c;
}

int main(){
    char a[100], b[100];

    printf("Enter first string: ");
    scanf("%s", a);

    printf("Enter second string: ");
    scanf("%s", b);

    int m = strlen(a);
    int n = strlen(b);

    int dp[m + 1][n + 1];

    for(int i = 0; i <= m; i++)
        dp[i][0] = i;

    for(int j = 0; j <= n; j++)
        dp[0][j] = j;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 1 + min(
                    dp[i - 1][j],
                    dp[i][j - 1],
                    dp[i - 1][j - 1]
                );
            }
        }
    }

    printf("Minimum Edit Distance = %d\n", dp[m][n]);

    printf("\nTraceback:\n");

    int i = m;
    int j = n;

    while(i > 0 || j > 0){
        if(i > 0 && j > 0 &&
           a[i - 1] == b[j - 1]){
            printf("Keep %c\n", a[i - 1]);
            i--;
            j--;
        }
        else if(i > 0 && j > 0 &&
                dp[i][j] == dp[i - 1][j - 1] + 1){
            printf("Replace %c with %c\n",
                   a[i - 1], b[j - 1]);

            i--;
            j--;
        }
        else if(i > 0 && dp[i][j] == dp[i - 1][j] + 1){
            printf("Delete %c\n", a[i - 1]);
            i--;
        }
        else{
            printf("Insert %c\n", b[j - 1]);
            j--;
        }
    }

    return 0;
}
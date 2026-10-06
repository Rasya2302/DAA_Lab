#include <stdio.h>
#include <string.h>

int main(){
    char a[100], b[100];

    printf("Enter first string: ");
    scanf("%s", a);

    printf("Enter second string: ");
    scanf("%s", b);

    int m = strlen(a);
    int n = strlen(b);

    int dp[m + 1][n + 1];

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else{
                if(dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    printf("Length of LCS = %d\n", dp[m][n]);

    /* Finding actual LCS */

    char lcs[100];

    int i = m;
    int j = n;
    int k = dp[m][n];

    lcs[k] = '\0';

    while(i > 0 && j > 0){
        if(a[i - 1] == b[j - 1]){
            lcs[k - 1] = a[i - 1];
            i--;
            j--;
            k--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }

    printf("LCS = %s\n", lcs);

    return 0;
}
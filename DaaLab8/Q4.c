#include <stdio.h>

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n], dp[n];

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++)
        dp[i] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                if(dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
    }

    int answer = dp[0];

    for(int i = 1; i < n; i++){
        if(dp[i] > answer)
            answer = dp[i];
    }

    printf("Length of LIS = %d\n", answer);

    return 0;
}
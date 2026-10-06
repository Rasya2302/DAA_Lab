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
        dp[i] = a[i];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                if(dp[j] + a[i] > dp[i])
                    dp[i] = dp[j] + a[i];
            }
        }
    }

    int answer = dp[0];

    for(int i = 1; i < n; i++){
        if(dp[i] > answer)
            answer = dp[i];
    }

    printf("Maximum Sum = %d\n", answer);

    return 0;
}
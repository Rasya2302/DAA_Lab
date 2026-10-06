#include <stdio.h>

void collatz(unsigned long long n){
    printf("%llu: ", n);

    while(n != 1){
        printf("%llu -> ", n);

        if(n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
    }

    printf("1\n");
}

int main(){
    unsigned long long a, b;

    printf("Enter a and b: ");
    scanf("%llu %llu", &a, &b);

    for(unsigned long long i = a; i <= b; i++){
        collatz(i);

        if(i == b)
            break;
    }

    return 0;
}
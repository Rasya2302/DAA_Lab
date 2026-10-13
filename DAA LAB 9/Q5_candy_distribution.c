#include <stdio.h>
#include <stdlib.h>
int main(void){int n;printf("children: ");if(scanf("%d",&n)!=1||n<=0)return 1;int*r=malloc(n*sizeof*r);long long*c=malloc(n*sizeof*c);for(int i=0;i<n;i++){scanf("%d",&r[i]);c[i]=1;}for(int i=1;i<n;i++)if(r[i]>r[i-1])c[i]=c[i-1]+1;for(int i=n-2;i>=0;i--)if(r[i]>r[i+1]&&c[i]<=c[i+1])c[i]=c[i+1]+1;long long sum=0;printf("Candies: ");for(int i=0;i<n;i++){printf("%lld ",c[i]);sum+=c[i];}printf("\nMinimum = %lld\n",sum);free(r);free(c);return 0;}

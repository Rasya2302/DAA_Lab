#include <stdio.h>
#include <stdlib.h>
/* Demonstration only: adjacent greedy is NOT the full optimal Hu-Tucker algorithm. */
int main(void){int n;printf("number of ordered weights: ");scanf("%d",&n);if(n<=0)return 1;long long*w=malloc(n*sizeof*w);for(int i=0;i<n;i++)scanf("%lld",&w[i]);long long total=0;while(n>1){int p=0;long long best=w[0]+w[1];for(int i=1;i<n-1;i++)if(w[i]+w[i+1]<best){best=w[i]+w[i+1];p=i;}printf("Merge adjacent %lld and %lld -> %lld\n",w[p],w[p+1],best);total+=best;w[p]=best;for(int i=p+1;i<n-1;i++)w[i]=w[i+1];n--;}printf("Simulation cost = %lld (not guaranteed optimal)\n",total);free(w);return 0;}

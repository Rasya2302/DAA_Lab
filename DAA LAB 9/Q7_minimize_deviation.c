#include <stdio.h>
#include <stdlib.h>
void push(long long*h,int*n,long long x){int i=++*n;while(i>1&&h[i/2]<x){h[i]=h[i/2];i/=2;}h[i]=x;}
long long pop(long long*h,int*n){long long v=h[1],x=h[(*n)--];int i=1,c;while((c=i*2)<=*n){if(c+1<=*n&&h[c+1]>h[c])c++;if(h[c]<=x)break;h[i]=h[c];i=c;}h[i]=x;return v;}
int main(void){int n;printf("n: ");scanf("%d",&n);if(n<=0)return 1;long long*h=malloc((n+2)*sizeof*h),mn=0;int z=0;for(int i=0;i<n;i++){long long x;scanf("%lld",&x);if(x<=0)return 1;if(x%2)x*=2;if(i==0||x<mn)mn=x;push(h,&z,x);}long long ans=h[1]-mn;while(h[1]%2==0){long long x=pop(h,&z)/2;if(x<mn)mn=x;push(h,&z,x);long long d=h[1]-mn;if(d<ans)ans=d;}printf("Minimum deviation = %lld\n",ans);free(h);return 0;}

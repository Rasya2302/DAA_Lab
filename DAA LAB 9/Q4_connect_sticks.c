#include <stdio.h>
#include <stdlib.h>
void push(long long*h,int*n,long long x){int i=++*n;while(i>1&&h[i/2]>x){h[i]=h[i/2];i/=2;}h[i]=x;}
long long pop(long long*h,int*n){long long v=h[1],x=h[(*n)--];int i=1,c;while((c=i*2)<=*n){if(c+1<=*n&&h[c+1]<h[c])c++;if(h[c]>=x)break;h[i]=h[c];i=c;}h[i]=x;return v;}
int main(void){int n;printf("n: ");scanf("%d",&n);if(n<1)return 1;long long*h=malloc((n+2)*sizeof*h);int z=0;for(int i=0;i<n;i++){long long x;scanf("%lld",&x);if(x<0)return 1;push(h,&z,x);}long long total=0;while(z>1){long long a=pop(h,&z),b=pop(h,&z),c=a+b;printf("%lld + %lld = %lld\n",a,b,c);total+=c;push(h,&z,c);}printf("Minimum total cost = %lld\n",total);free(h);return 0;}

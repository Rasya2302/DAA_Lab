#include <stdio.h>
#include <stdlib.h>
typedef struct{long long d,f;}S;
int cmp(const void*a,const void*b){const S*x=a,*y=b;return (x->d>y->d)-(x->d<y->d);}
void push(long long*h,int*n,long long x){int i=++*n;while(i>1&&h[i/2]<x){h[i]=h[i/2];i/=2;}h[i]=x;}
long long pop(long long*h,int*n){long long v=h[1],x=h[(*n)--];int i=1,c;while((c=i*2)<=*n){if(c+1<=*n&&h[c+1]>h[c])c++;if(h[c]<=x)break;h[i]=h[c];i=c;}h[i]=x;return v;}
int main(void){int n;long long D,F;printf("stations: ");scanf("%d",&n);if(n<0)return 1;S*s=malloc((n?n:1)*sizeof*S);for(int i=0;i<n;i++)scanf("%lld%lld",&s[i].d,&s[i].f);printf("destination initialFuel: ");scanf("%lld%lld",&D,&F);qsort(s,n,sizeof*S,cmp);long long*h=malloc((n+2)*sizeof* h);int z=0,i=0,stops=0;while(F<D){while(i<n&&s[i].d<=F)push(h,&z,s[i++].f);if(!z){puts("Impossible");free(s);free(h);return 0;}F+=pop(h,&z);stops++;}printf("Minimum stops = %d\n",stops);free(s);free(h);return 0;}

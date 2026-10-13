#include <stdio.h>
#define N 100
typedef struct { double v,w,lambda; } Item;
int main(void){int n; double W,t=0,total=0; Item a[N];
 printf("n: "); if(scanf("%d",&n)!=1||n<1||n>N)return 1;
 for(int i=0;i<n;i++){printf("value weight decay: ");scanf("%lf%lf%lf",&a[i].v,&a[i].w,&a[i].lambda);if(a[i].w<=0||a[i].lambda<0)return 1;}
 printf("capacity: ");scanf("%lf",&W); if(W<0)return 1;
 while(W>1e-9){int b=-1;double bd=0;
  for(int i=0;i<n;i++)if(a[i].w>1e-9){double d=a[i].v/a[i].w-a[i].lambda*t;if(d>bd){bd=d;b=i;}}
  if(b<0)break; double x=a[b].w<W?a[b].w:W; printf("Take %.2f from item %d at density %.3f\n",x,b+1,bd);
  total+=x*bd; a[b].w-=x; W-=x; t+=1.0; /* assumed one time unit per selection */
 }
 printf("Greedy simulated value = %.3f\n",total); return 0;}

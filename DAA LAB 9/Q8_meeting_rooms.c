#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){int x=*(int*)a,y=*(int*)b;return(x>y)-(x<y);}
int main(void){int n;printf("meetings: ");scanf("%d",&n);if(n<0)return 1;int*s=malloc((n?n:1)*sizeof* s),*e=malloc((n?n:1)*sizeof*e);for(int i=0;i<n;i++){scanf("%d%d",&s[i],&e[i]);if(e[i]<s[i])return 1;}qsort(s,n,sizeof(int),cmp);qsort(e,n,sizeof(int),cmp);int i=0,j=0,rooms=0,best=0;while(i<n){if(j==n||s[i]<e[j]){rooms++;if(rooms>best)best=rooms;i++;}else{rooms--;j++;}}printf("Minimum rooms = %d\n",best);free(s);free(e);return 0;}

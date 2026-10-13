#include <stdio.h>
#include <string.h>
#define N 100
#define M 2*N
int main(void){int n,f[M],l[M],r[M],par[M],used[M]={0},len[N],ord[N];char bits[N][N];
 printf("Number of symbols (1-%d): ",N);if(scanf("%d",&n)!=1||n<1||n>N)return 1;
 for(int i=0;i<n;i++){printf("Frequency of symbol %d: ",i);scanf("%d",&f[i]);if(f[i]<=0)return 1;l[i]=r[i]=par[i]=-1;ord[i]=i;}
 int total=n;
 if(n==1){strcpy(bits[0],"0");len[0]=1;} else {
  for(int z=0;z<n-1;z++){int a=-1,b=-1;
   for(int i=0;i<total;i++)if(!used[i]){if(a<0||f[i]<f[a]){b=a;a=i;}else if(b<0||f[i]<f[b])b=i;}
   used[a]=used[b]=1;f[total]=f[a]+f[b];l[total]=a;r[total]=b;par[total]=-1;par[a]=par[b]=total;total++;
  }
  for(int i=0;i<n;i++){char tmp[N];int k=0,x=i;while(par[x]>=0){int p=par[x];tmp[k++]=(l[p]==x)?'0':'1';x=p;}len[i]=k;for(int j=0;j<k;j++)bits[i][j]=tmp[k-1-j];bits[i][k]='\0';}
 }
 for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(len[ord[j]]<len[ord[i]]||(len[ord[j]]==len[ord[i]]&&ord[j]<ord[i])){int t=ord[i];ord[i]=ord[j];ord[j]=t;}
 unsigned long long code=0;int prev=len[ord[0]];puts("Canonical codebook (symbols numbered 0..n-1):");
 for(int k=0;k<n;k++){int s=ord[k],L=len[s];if(k)code=(code+1)<<(L-prev);printf("symbol %d, length %d: ",s,L);for(int b=L-1;b>=0;b--)putchar((code>>b)&1?'1':'0');putchar('\n');prev=L;}
 return 0;}

#include <stdio.h>
#include <string.h>
#define L 10000
#define C 256
typedef struct{int ch,f;}Item;Item h[C+1];int hs;
void push(Item x){int i=++hs;while(i>1&&h[i/2].f<x.f){h[i]=h[i/2];i/=2;}h[i]=x;}
Item pop(void){Item v=h[1],x=h[hs--];int i=1,c;while((c=i*2)<=hs){if(c+1<=hs&&h[c+1].f>h[c].f)c++;if(h[c].f<=x.f)break;h[i]=h[c];i=c;}h[i]=x;return v;}
int main(void){char s[L+1],out[L+1];int K,f[C]={0};printf("string: ");scanf("%10000s",s);printf("K: ");scanf("%d",&K);if(K<0)return 1;int n=strlen(s);if(K<=1){puts(s);return 0;}for(int i=0;i<n;i++)f[(unsigned char)s[i]]++;for(int c=0;c<C;c++)if(f[c])push((Item){c,f[c]});int qch[L+1],qrel[L+1],front=0,back=0,pos=0;while(pos<n){if(front<back&&qrel[front]<=pos){int ch=qch[front++];if(f[ch]>0)push((Item){ch,f[ch]});}if(!hs){puts("Impossible");return 0;}Item x=pop();out[pos++]=(char)x.ch;f[x.ch]--;if(f[x.ch]>0){qch[back]=x.ch;qrel[back]=pos+K-1;back++;}}out[pos]='\0';puts(out);return 0;}

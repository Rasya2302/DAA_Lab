#include <stdio.h>
#include <string.h>
#define N 50
#define L 2000
int ov(char*a,char*b){int x=strlen(a),y=strlen(b),m=x<y?x:y;for(int k=m;k>0;k--)if(strncmp(a+x-k,b,k)==0)return k;return 0;}
int main(void){int n;char s[N][L];printf("number of strings: ");scanf("%d",&n);if(n<1||n>N)return 1;for(int i=0;i<n;i++){printf("string %d: ",i+1);scanf("%1999s",s[i]);}
 /* Remove strings contained in another input string. */
 for(int i=0;i<n;i++)if(s[i][0])for(int j=0;j<n;j++)if(i!=j&&s[j][0]&&(strlen(s[i])<strlen(s[j])||(strlen(s[i])==strlen(s[j])&&j<i))&&strstr(s[j],s[i])){s[i][0]='\0';break;}
 int m=0;for(int i=0;i<n;i++)if(s[i][0]){if(m!=i)strcpy(s[m],s[i]);m++;}n=m;
 while(n>1){int bi=0,bj=1,best=-1;for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j){int x=ov(s[i],s[j]);if(x>best){best=x;bi=i;bj=j;}}if(strlen(s[bi])+strlen(s[bj])-best>=L){puts("Buffer too small");return 1;}strcat(s[bi],s[bj]+best);for(int k=bj;k<n-1;k++)strcpy(s[k],s[k+1]);n--;}
 printf("Greedy superstring (heuristic) = %s\n",s[0]);return 0;}

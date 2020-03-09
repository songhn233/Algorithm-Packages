#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
using namespace std;
template<class T>inline void read(T &x) {
  x=0; int ch=getchar(),f=0;
  while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
  while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=1000050;
int nex[maxn],n,m,i,j,len,cnt;
char s[maxn];
int main()
{
  scanf("%s",s+1);
  int n=strlen(s+1);
  for(int i=2,j=0;i<=n;i++)
  {
    while(j&&s[i]!=s[j+1]) j=nex[j];
    if (s[j+1]==s[i]) j++;
    nex[i]=j;
  }
  int ans=n-nex[n];
  int flag=0;
  if(n%(n-nex[n])) flag=1;
  if(flag) 
  {
    puts("-1");
  }
  else
  {
    for(int i=1;i<=ans;i++) printf("%c",s[i]);
    cout<<endl;
  }
  return 0;
}
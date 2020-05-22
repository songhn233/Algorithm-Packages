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
const int maxn=2010;
int T,g;
int f[maxn][maxn];
int s[maxn][maxn];
int main()
{
  scanf("%d%d",&T,&g);
  f[0][0]=1;
  for(int i=1;i<=2000;i++)
  {
    f[i][0]=1;
    for(int j=1;j<=i;j++)
    {
      f[i][j]=(f[i-1][j-1]+f[i-1][j])%g;
      s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
      if(f[i][j]==0) s[i][j]+=1;
    }
    s[i][i+1]=s[i][i];
  }
  while(T--)
  {
    int g,n,m;
    scanf("%d%d",&n,&m);
    if(m>n) m=n;
    printf("%d\n",s[n][m]);
  }
  return 0;
}
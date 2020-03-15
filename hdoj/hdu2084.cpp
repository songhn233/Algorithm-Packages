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
const int maxn=150;
int a[maxn][maxn],f[maxn][maxn];
int T,n;
int dfs(int x,int y)
{
  if(x>n||y>x) return 0;
  if(f[x][y]!=-1) return f[x][y];
  f[x][y]=a[x][y]+max(dfs(x+1,y),dfs(x+1,y+1));
  return f[x][y];
}
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n;
    mst(f,-1);
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) read(a[i][j]);
    dfs(1,1);
    cout<<f[1][1]<<endl;
  }
  return 0;
}
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
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
template<class T>inline void rd(T &x) {
  x=0; int ch=getchar(),f=0;
  while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
  while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=200050;
int n,a[maxn],f[maxn],g[maxn];
vector<int> e[maxn];
void dfs1(int u,int fa)
{
  for(int i=0;i<e[u].size();i++)
  {
    int v=e[u][i];
    if(v==fa) continue;
    dfs1(v,u);
    f[u]+=max(0,f[v]);
  }
  f[u]+=a[u];
}
void dfs2(int u,int fa)
{
  for(int i=0;i<e[u].size();i++)
  {
    int v=e[u][i];
    if(v==fa) continue;
    g[v]=f[v]+max(0,g[u]-max(0,f[v]));
    dfs2(v,u);
  }
}
int main()
{
  cin>>n;
  rep(i,1,n) 
  {
    rd(a[i]);
    if(!a[i]) a[i]=-1;
  }
  rep(i,1,n-1)
  {
    int x,y;rd(x),rd(y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs1(1,0);
  g[1]=f[1];
  dfs2(1,0);
  rep(i,1,n) cout<<g[i]<<" ";
  cout<<endl;
  return 0;
}
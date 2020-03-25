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
const int maxn=150;
int n,m,vis[maxn],flag;
vector<int> e[maxn];
void dfs(int u)
{
  vis[u]=1;
  rep(i,0,(int)e[u].size()-1)
  {
    int v=e[u][i];
    if(vis[v]==1)
    {
      flag=1;
    }
    else if(!vis[v]) dfs(v);
  }
  vis[u]=2;
}
int main()
{
  while(~scanf("%d%d",&n,&m))
  {
    if(!n) break;flag=0;
    rep(i,0,n-1) e[i].clear(),vis[i]=0;
    rep(i,1,m)
    {
      int x,y;rd(x),rd(y);
      e[x].push_back(y);
    }
    rep(i,0,n-1)
    {
      if(!vis[i]) 
      {
        dfs(i);
        if(flag) 
        {
          puts("NO");
          break;
        }
      }
    }
    if(!flag) puts("YES");
  }
  return 0;
}
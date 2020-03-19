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
const int maxm=400050;
int T,n,m,D;
int head[maxn],num,vis[maxn];
vector<int> dis[maxn];
struct node{
  int v,nex;
}e[maxm];
void add(int u,int v)
{
  e[++num].nex=head[u];
  e[num].v=v;
  head[u]=num;
}
void dfs(int u,int d)
{
  D=max(D,d);
  dis[d].push_back(u);
  vis[u]=1;
  for(int i=head[u];i;i=e[i].nex)
  {
    int v=e[i].v;
    if(vis[v]) continue;
    dfs(v,d+1);
  }
}
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n>>m;
    num=0;
    for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<=n;i++) vis[i]=0;
    rep(i,0,n) dis[i].clear();
    D=0;
    rep(i,1,m) 
    {
      int x,y;rd(x),rd(y);
      add(x,y),add(y,x);
    }
    dfs(1,1);
    int temp=0;
    for(int i=1;i<=D;i+=2) temp+=dis[i].size();
    if(temp<=n/2)
    {
      cout<<temp<<endl;
      for(int i=1;i<=D;i+=2)
      {
        for(int j=0;j<dis[i].size();j++) cout<<dis[i][j]<<" ";
      }
      cout<<endl;
    }
    else
    {
      cout<<n-temp<<endl;
      for(int i=2;i<=D;i+=2)
      {
        for(int j=0;j<dis[i].size();j++) cout<<dis[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
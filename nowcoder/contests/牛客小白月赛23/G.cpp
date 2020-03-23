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
ll n,in[maxn],siz[maxn],a[maxn];
int head[maxn],num;
ll ans=0;
struct node{
  int v,nex;
}e[maxn];
void add(int u,int v)
{
  e[++num].nex=head[u];
  e[num].v=v;
  head[u]=num;
}
void dfs(int u,int fa)
{
  siz[u]=1;
  for(int i=head[u];i;i=e[i].nex)
  {
    int v=e[i].v;
    if(v==fa) continue;
    dfs(v,u);
    siz[u]+=siz[v];
  }
}
int main()
{
  cin>>n;
  rep(i,1,n-1)
  {
    int x,y;rd(x),rd(y);
    add(x,y),add(y,x);
  }
  dfs(1,0);
  rep(i,2,n) a[i-1]=siz[i]*(n-siz[i]);
  sort(a+1,a+n);
  reverse(a+1,a+n);
  rep(i,1,n-1) ans+=a[i]*i;
  cout<<ans<<endl;
  return 0;
}
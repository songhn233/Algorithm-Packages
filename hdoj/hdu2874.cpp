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
const int maxn=20500;
int head[maxn],num=0;
int d[maxn],fa[maxn],siz[maxn],son[maxn],top[maxn];
int f[maxn],dis[maxn];
struct node{
  int v,w,nex;
}e[maxn];
void add(int u,int v,int w)
{
  e[++num].nex=head[u];
  e[num].v=v;e[num].w=w;
  head[u]=num;
}
void dfs1(int u,int f)
{
  siz[u]=1;
  for(int i=head[u];i;i=e[i].nex)
  {
    int v=e[i].v;
    if(v==f) continue;
    d[v]=d[u]+1;
    dis[v]=dis[u]+e[i].w;
    fa[v]=u;
    dfs1(v,u);
    siz[u]+=siz[v];
    if(siz[v]>siz[son[u]]) son[u]=v;
  }
}
void dfs2(int u,int topf)
{
  top[u]=topf;
  if(son[u]) dfs2(son[u],topf);
  for(int i=head[u];i;i=e[i].nex)
  {
    int v=e[i].v;
    if(v==fa[u]||v==son[u]) continue;
    dfs2(v,v);
  }
}
int lca(int x,int y)
{
  while(top[x]!=top[y])
  {
    if(d[top[x]]<d[top[y]]) swap(x,y);
    x=fa[top[x]];
  }
  if(d[x]>d[y]) swap(x,y);
  return x;
}
int n,m,q;
int get(int x){if(x!=f[x])f[x]=get(f[x]); return f[x];}
void merge(int x,int y)
{
    x=get(x);y=get(y);
    if(x==y) return ;
    f[x]=y;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        rep(i,1,n) f[i]=i;
        mst(head,0);num=0;
        mst(son,0);mst(top,0);
        rep(i,1,m)
        {
            int x,y,z;rd(x),rd(y);rd(z);
            add(x,y,z);add(y,x,z);
            merge(x,y);
        }
        rep(i,1,n)
        {
            if(get(i)==i)
            {
                d[i]=0;dis[i]=0;
                dfs1(i,0);
                dfs2(i,i);
            }
        }
        while(q--)
        {
            int x,y;rd(x),rd(y);
            if(get(x)==get(y)) printf("%d\n",dis[x]+dis[y]-2*dis[lca(x,y)]);
            else puts("Not connected");
        }
    }
    return 0;
}
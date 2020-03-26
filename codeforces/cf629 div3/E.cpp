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
int n,m,s;
int head[maxn],num=0;
int d[maxn],fa[maxn],siz[maxn],son[maxn],top[maxn];
int q[maxn];
struct edge{
  int val,id;
  bool operator<(const edge&t) const{
    return val<t.val;
  }
}dis[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].v=v;e[num].nex=head[u];
	head[u]=num;
	e[++num].v=u;e[num].nex=head[v];
	head[v]=num;
}
void dfs1(int u,int f)
{
	siz[u]=1;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==f) continue;
		d[v]=d[u]+1;
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
int main()
{
	rd(n),rd(m);
	for(int i=1;i<n;i++)
	{
		int x,y;rd(x),rd(y);
		add(x,y);
	}
  s=1;
	d[s]=1;
	dfs1(s,0);
	dfs2(s,s);
	while(m--)
	{
		int k;rd(k);
    rep(i,1,k) 
    {
      rd(q[i]);
      if(q[i]!=1) q[i]=fa[q[i]];
    }
    rep(i,1,k) dis[i].val=d[q[i]],dis[i].id=q[i];
    sort(dis+1,dis+k+1);
    int flag=1;
    rep(i,2,k)
    {
      if(lca(dis[i-1].id,dis[i].id)==dis[i-1].id) continue;
      else 
      {
        flag=0;
        break;
      }
    }
    if(flag) puts("YES");
    else puts("NO");
	}
	return 0;
}
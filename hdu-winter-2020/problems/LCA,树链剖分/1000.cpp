// hdu4547

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
int T,n,m,cnt;
map<string,int> mp;
int head[maxn],num=0,root;
int d[maxn],fa[maxn],siz[maxn],son[maxn],top[maxn],vis[maxn];
struct node{
  int v,nex;
}e[maxn];
void add(int u,int v)
{
  e[++num].nex=head[u];
  e[num].v=v;
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
    cin>>T;
    while(T--)
    {
        mp.clear();num=0;cnt=0;
        mst(head,0);mst(son,0);mst(top,0);mst(vis,0);
        rd(n),rd(m);
        rep(i,1,n-1)
        {
            string t1,t2;
            int x,y;
            cin>>t1>>t2;
            if(!mp[t1]) mp[t1]=++cnt,x=cnt;
            else x=mp[t1];
            if(!mp[t2]) mp[t2]=++cnt,y=cnt;
            else y=mp[t2];
            add(y,x);
            vis[x]=1;
        }
        rep(i,1,cnt) if(!vis[i]) {root=i; break;}
        d[root]=0;
        dfs1(root,0);
        dfs2(root,root);
        while(m--)
        {
            string t1,t2;
            cin>>t1>>t2;
            int u=mp[t1],v=mp[t2];
            if(u==v) puts("0");
            else
            {
                int t=lca(u,v);
                if(t==u) puts("1");
                else if(t==v) printf("%d\n",d[u]-d[v]);
                else printf("%d\n",d[u]-d[t]+1);
            }  
        }
    }
    return 0;
}
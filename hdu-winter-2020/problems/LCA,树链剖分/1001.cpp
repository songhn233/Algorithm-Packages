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
const int maxn=100050;
int T,n,m;
int head[maxn],num;
int son[maxn],fa[maxn],topf[maxn],siz[maxn];
int d[maxn],dis[maxn];
struct node{
    int v,w,nex;
}e[maxn];
void add(int u,int v,int w)
{
    e[++num].nex=head[u];
    e[num].v=v;e[num].w=w;
    head[u]=num;
}
void dfs1(int u,int f,int w)
{
    fa[u]=f;
    siz[u]=1;
    d[u]=d[f]+1;
    dis[u]=dis[f]+w;
    int maxsize=0,temp=0;
    for(int i=head[u];i;i=e[i].nex)
    {
        int v=e[i].v;
        if(v==f) continue;
        dfs1(v,u,e[i].w);
        siz[u]+=siz[v];
        if(siz[v]>maxsize)
        {
            maxsize=siz[v];
            temp=v;
        }
    }
    son[u]=temp;
}
void dfs2(int u,int top)
{
    topf[u]=top;
    if(!son[u]) return ;
    dfs2(son[u],top);
    for(int i=head[u];i;i=e[i].nex)
    {
        int v=e[i].v;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int x,int y)
{
    while(topf[x]!=topf[y])
    {
        if(d[topf[x]]<d[topf[y]]) swap(x,y);
        x=fa[topf[x]];
    }
    if(d[x]>d[y]) swap(x,y);
    return x;
}
int main()
{
    rd(T);
    while(T--)
    {
        rd(n),rd(m);
        mst(fa,0);mst(son,0);mst(head,0);num=0;
        for(int i=1;i<=n-1;i++)
        {
            int x,y,z;
            rd(x),rd(y),rd(z);
            add(x,y,z);add(y,x,z);
        }
        dfs1(1,0,0);
        dfs2(1,1);
        while(m--)
        {
            int x,y;rd(x),rd(y);
            printf("%d\n",dis[x]+dis[y]-2*dis[lca(x,y)]);
        }
    }
    return 0;
}

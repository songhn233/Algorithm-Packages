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
const int maxn=1050;
const int maxm=200010;
ll n,m,a[maxn];
int k,S;
int s,t;
int head[maxn],num=1,d[maxn],vis[maxn];
ll maxflow;
struct node{
    int v,w,nex;
}e[maxm];
void add(int u,int v,int w)
{
    e[++num].nex=head[u];
    e[num].v=v;e[num].w=w;
    head[u]=num;
    e[++num].nex=head[v];
    e[num].v=u;e[num].w=0;
    head[v]=num;
}
bool bfs()
{
    memset(d,0,sizeof(d));
    queue<int> q;
    q.push(s);d[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nex)
        {
            int v=e[i].v;
            if(!e[i].w||d[v]) continue;
            d[v]=d[u]+1;
            q.push(v);
            if(v==t) return true;
        }
    }
    return false;
}
int dinic(int u,int flow)
{
    if(u==t) return flow;
    int rest=flow,temp;
    for(int i=head[u];i&&rest;i=e[i].nex)
    {
        int v=e[i].v;
        if(!e[i].w||d[v]!=d[u]+1) continue;
        temp=dinic(v,min(rest,e[i].w));
        if(!temp) d[v]=0;
        e[i].w-=temp;
        e[i^1].w+=temp;
        rest-=temp;
    }
    return flow-rest;
}
int main()
{
    cin>>n>>m;
    rep(i,1,n) rd(a[i]);
    for(int i=1;i<=n;i++)
    {
        add(n+i,i,a[i]);
        add(i,2*n+i,a[i]);
    }
    rep(i,1,m)
    {
        int u,v,w;
        rd(u),rd(v),rd(w);
        add(u+2*n,v+n,w);
        add(v+2*n,u+n,w);
    }
    cin>>k>>S;
    s=k,t=1;
    maxflow=0;
    while(bfs()){maxflow+=dinic(s,inf);}
    double ans=(double)S/(double)maxflow;
    printf("%.9lf\n",ans);
    return 0;
}
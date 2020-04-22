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
ll n,p,c[maxn];
vector<int> temp[maxn];
int head[maxn],num=1,d[maxn],vis[maxn];
ll sum=0;
int s,t;
struct node{
    int v,w,nex;
}e[maxn];
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
bool calc(ll mid)
{
    ll ttt=mid%7,tt=mid/7;
    ll ww=tt*p;
    mst(head,0);num=1;
    rep(i,1,n)
    {
        for(int j=0;j<temp[i].size();j++)
        {
            int v=temp[i][j];
            add(n+v,i,inf);
        }
    }
    rep(i,1,ttt)
    {
        for(int j=0;j<temp[i].size();j++)
        {
            int v=temp[i][j];
            add(n+v,i,p);
        }
    }
    rep(i,1,n) add(i,t,c[i]);
    rep(i,1,7) add(s,n+i,ww);
    rep(i,1,ttt) add(s,n+i,p);
    ll maxflow=0;
    while(bfs()){maxflow+=dinic(s,inf);}
    if(maxflow==sum) return true;
    else return false;
}
int main()
{
    cin>>n>>p;
    s=n+8,t=n+9;
    rep(i,1,n) 
    {
        int m;
        rd(c[i]);rd(m);
        sum+=c[i];
        rep(j,1,m)
        {
            int x;rd(x);
            temp[i].push_back(x);
        }
    }
    ll l=1,r=1e8;
    while(l<r)
    {
        ll mid=l+r>>1;
        if(calc(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}
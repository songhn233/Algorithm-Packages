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
const int maxn=1000010;
int n,m,s,t;
int head[maxn],num;
int st,ed;
int dis[maxn],vis[maxn];
struct node{
    int v,w,nex;
}e[maxn];
void add(int u,int v,int w)
{
    e[++num].nex=head[u];
    e[num].v=v;e[num].w=w;
    head[u]=num;
}
void dij()
{
    mst(dis,0x3f);
    priority_queue<PII,vector<PII>,greater<PII> > q;
    while(!q.empty()) q.pop();
    q.push(make_pair(0,st));
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nex)
        {
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                q.push(make_pair(dis[v],v));
            }
        }
    }
}
int main()
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;rd(a),rd(b),rd(c);
        int pre;rd(pre);
        add(n*m+pre,(i-1)*n+pre,a);
        add((i-1)*n+pre,n*m+pre,0);
        for(int j=2;j<=c;j++)
        {
            int v;rd(v);
            add(n*m+v,(i-1)*n+v,a);
            add((i-1)*n+v,m*n+v,0);
            add((i-1)*n+pre,(i-1)*n+v,b);
            add((i-1)*n+v,(i-1)*n+pre,b);
            pre=v;
        }
    }
    st=n*m+s,ed=n*m+t;
    dij();
    if(dis[ed]!=inf) cout<<dis[ed]<<endl;
    else puts("-1");
    return 0;
}
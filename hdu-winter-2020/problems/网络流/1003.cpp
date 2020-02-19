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
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=2000;
const int maxm=500000;
int T,n,m,s,t,maxflow;
int head[maxn],num=1,d[maxn],vis[maxn];
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
    cin>>T;
    for(int tim=1;tim<=T;tim++)
    {
        memset(head,0,sizeof(head));num=1;
        memset(vis,0,sizeof(vis));
        cin>>n>>m;
        s=0,t=500+n+1;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int x,y,z;read(x),read(y),read(z);
            add(0,500+i,x);
            sum+=x;
            for(int j=y;j<=z;j++) 
			{
				add(500+i,j,1);
				vis[j]=1;
			}
        }
        for(int i=1;i<=500;i++) if(vis[i]) add(i,t,m);
        maxflow=0;
        while(bfs()){maxflow+=dinic(s,inf);}
        if(maxflow==sum) cout<<"Case "<<tim<<": Yes"<<endl<<endl;
        else cout<<"Case "<<tim<<": No"<<endl<<endl;    
    }
    return 0;
}

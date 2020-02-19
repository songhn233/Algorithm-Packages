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
const int maxn=200050;
int n,m,ha[maxn],tot,s,t,maxflow;
int head[maxn],num=1,d[maxn],vis[maxn];
struct edge{
	int s1,n1,e1,t1;
}a[maxn];
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
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		tot=0;num=1;
		ll sum=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<=n;i++)
		{
			int s1,e1,n1,t1;
			read(s1),read(n1),read(e1),read(t1);
			a[i]={s1,n1,e1,t1};
			ha[++tot]=s1,ha[++tot]=e1;
		}
		sort(ha+1,ha+tot+1);
		tot=unique(ha+1,ha+tot+1)-(ha+1);
		for(int i=1;i<=n;i++)
		{
			add(0,tot+i,a[i].n1*a[i].t1);
			sum+=a[i].n1*a[i].t1;
			for(int j=2;j<=tot;j++)
			{
				int l=ha[j-1],r=ha[j];
				if(a[i].s1<=l&&a[i].e1>=r) add(tot+i,j,inf);
			}
		}
		s=0,t=tot+n+1;
		for(int i=2;i<=tot;i++) add(i,t,m*(ha[i]-ha[i-1]));
		maxflow=0;
        while(bfs()){maxflow+=dinic(s,inf);}
        if(maxflow==sum) puts("Yes");
        else puts("No");
	}
	return 0;
}


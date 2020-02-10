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
const int maxn=600050;
int n;
int a[maxn],ans[maxn];
int head[maxn],num;
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
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push(make_pair(0,s));
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
	cin>>n;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(i+a[i]<=n) add(i+a[i],i,1);
		if(i-a[i]>=1) add(i-a[i],i,1);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]%2==1) add(0,i,0);
		else add(n+1,i,0);
	}
	memset(ans,-1,sizeof(ans));
	dij(0);
	for(int i=1;i<=n;i++) if(a[i]%2==0&&dis[i]!=inf) ans[i]=dis[i];
	dij(n+1);
	for(int i=1;i<=n;i++) if(a[i]%2==1&&dis[i]!=inf) ans[i]=dis[i];
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}


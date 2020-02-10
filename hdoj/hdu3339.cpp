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
const int maxn=20050;
int T,n,m;
int head[maxn],num,a[maxn];
int vis[maxn],dis[maxn];
int vv[maxn],ww[maxn],f[maxn];
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
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<PII,vector<PII>,greater<PII> > q;
	while(!q.empty()) q.pop();
	q.push(make_pair(0,0));
	dis[0]=0;
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
	cin>>T;
	while(T--)
	{
		memset(head,0,sizeof(head));
		memset(f,0,sizeof(f));
		num=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			read(u),read(v),read(w);
			add(u,v,w);add(v,u,w);
		}
		dij();
		int p=0;
		for(int i=1;i<=n;i++) read(ww[i]),p+=ww[i];
		m=0;
		for(int i=1;i<=n;i++)
		{
			vv[i]=dis[i];
			if(dis[i]==inf) continue;
			m+=vv[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=vv[i];j--)
			{
				if(vv[i]==inf) continue;
				f[j]=max(f[j],f[j-vv[i]]+ww[i]);
			}	
		}
		int flag=0;
		for(int i=0;i<=m;i++)
		{
			if(f[i]>p/2) 
			{
				cout<<i<<endl;
				flag=1;
				break;
			}
		}
		if(!flag) puts("impossible");
	}
	return 0;
}


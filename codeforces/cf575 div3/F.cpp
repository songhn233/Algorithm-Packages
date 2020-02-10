#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstring>
#define p pair<ll,ll>
#define ll long long
using namespace std;
const int maxn=200050;
ll n,m,k,ans;
ll head[maxn],num=0,cnt[maxn],dis[maxn],vis[maxn],pan[maxn],tot=0;
priority_queue<p,vector<p>,greater<p> > q;
vector<ll> res;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
struct temp{
	ll u,v,w;
	bool operator<(const temp&a) const
	{
		return w<a.w;
	}
}t[maxn];
struct node{
	ll v,w,nex;
}e[maxn];
void add(int u,int v,int w)
{
	e[++num].v=v;
	e[num].w=w;
	e[num].nex=head[u];
	head[u]=num;
}
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int x,y,z;x=read(),y=read(),z=read();
		t[i].u=x,t[i].v=y,t[i].w=z;
	}
	sort(t+1,t+m+1);
	for(int i=1;i<=k;i++)
	{
		int u=t[i].u,v=t[i].v,w=t[i].w;
		add(u,v,w);
		add(v,u,w);
		if(!pan[u]) cnt[++tot]=u,pan[u]=1;
		if(!pan[v]) cnt[++tot]=v,pan[v]=1;
	}
	for(int i=1;i<=tot;i++)
	{
		dij(cnt[i]);
		for(int j=1;j<i;j++) res.push_back(dis[cnt[j]]);
	}
	sort(res.begin(),res.end());
	ans=res[k-1];
	cout<<ans<<endl;
	return 0;
}

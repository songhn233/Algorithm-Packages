#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#define PLL pair<ll,ll>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=500000;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
priority_queue<PLL,vector<PLL>,greater<PLL> > q;
ll dis[maxn],vis[maxn];
ll head[maxn],num;
ll a,b,c;
ll h;
struct node{
	ll v,w,nex;
}e[maxn];
void add(int u,int v,int w)
{
	e[++num].nex=head[u];
	e[num].v=v,e[num].w=w;
	head[u]=num;
}
void dij()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1%a]=1;
	q.push(make_pair(1,dis[1%a]));
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
	cin>>h;
	cin>>a>>b>>c;
	if(b<a) swap(a,b);
	if(c<a) swap(a,c);
	for(int i=0;i<a;i++)
	{
		add(i,(i+b)%a,b);
		add(i,(i+c)%a,c);
	}
	dij();
	ll ans=0;
	for(int i=0;i<a;i++)
	{
		if(dis[i]>h) continue;
		ans+=(h-dis[i])/a+1;
	}
	cout<<ans<<endl;
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1000050;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int head[maxn],num,cut[maxn];
int dfn[maxn],low[maxn],id;
ll ans[maxn],size[maxn],root;
ll n,m;
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void tarjan(int u)
{
	ll flag=0,sum=0;
	dfn[u]=low[u]=++id;
	size[u]=1;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!dfn[v]) 
		{
			tarjan(v);
			size[u]+=size[v];
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				flag++;
				sum+=size[v];
				ans[u]+=size[v]*(n-size[v]);
				if((u!=root)||flag>=2) cut[u]=1;
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(!cut[u]) ans[u]=2*(n-1);
	else ans[u]+=n-1+(n-sum-1)*(sum+1);
} 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++) 
	{
		if(!dfn[i]) 
		{
			root=i;
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}

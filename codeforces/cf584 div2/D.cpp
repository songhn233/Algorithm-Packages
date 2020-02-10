#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=200050;
int n,k;
int head[maxn],num,size[maxn],cnt,vis[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
void dfs(int u)
{
	vis[u]=1;
	size[cnt]++;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		dfs(v);
	}
}
int main()
{
	n=read();k=read();
	for(int i=1;i<=k;i++)
	{
		int x,y;x=read(),y=read();
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) 
		{
			cnt++;
			dfs(i);
		}
	}
	int ans=k;
	for(int i=1;i<=cnt;i++) ans-=size[i]-1;
	cout<<ans<<endl;
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=10050;
int n,m;
int head[maxn],num,ans;
int vis[maxn],co[maxn];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(co[i]) continue;
		
		if(!vis[v]) dfs(v);
		
		if(vis[v]==1) co[i]=2,ans=2;
		else co[i]=1;
	}
	vis[u]=2;
}
int main()
{
	ans=1;
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x,y;x=read(),y=read();
		add(x,y);
	}
	for(int i=1;i<=n;i++)
	if(!vis[i]) dfs(i);
	
	cout<<ans<<endl;
	
	for(int i=1;i<=num;i++) printf("%d ",co[i]);
	puts("");
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=600050;
int n,m;
int f[maxn];
int head[maxn],num,ans;
struct node{
	int v,nex;
}e[maxn];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void dfs(int u,int fa)
{
	f[u]=1;
	int temp=0,maxx=0,smaxx=0;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa) continue;
		temp++;
		dfs(v,u);
		if(f[v]>maxx)
		{
			smaxx=maxx;
			maxx=f[v];
		}
		else if(f[v]>smaxx) smaxx=f[v];
	}
	if(temp>=1) f[u]+=maxx+temp-1;
	
	if(temp==1) ans=max(ans,f[u]);
	if(temp>=2) ans=max(ans,max(f[u],maxx+smaxx+temp-1+(u==1?0:1)));
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}

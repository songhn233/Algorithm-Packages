#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const ll inf=1e15;
const int maxn=200050;
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll head[maxn],num,temp;
ll n,co[3][maxn],du[maxn];
ll mp[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int path[6][maxn];
struct node{
	ll v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void dfs(int u,int fa,int p,int t)
{
	temp+=co[mp[p][t%3]][u];
	path[p][u]=mp[p][t%3]+1;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,p,t+1);
	}
}
int main()
{
	n=read();
	for(int i=0;i<3;i++) for(int j=1;j<=n;j++) co[i][j]=read();
	for(int i=1;i<n;i++)
	{
		int x,y;x=read(),y=read();
		add(x,y);add(y,x);
		du[x]++,du[y]++;
	}
	for(int i=1;i<=n;i++) 
	{
		if(du[i]>2) 
		{
			puts("-1");
			return 0;
		}
	}
	int s=0,t=0;
	for(int i=1;i<=n;i++) 
	{
		if(du[i]==1)
		{
			if(s==0) s=i;
			else t=i;
		}
	}
	ll ans=inf;
	int id=0;
	for(int i=0;i<6;i++) 
	{
		temp=0;
		dfs(s,0,i,0);
		if(temp<ans)
		{
			ans=temp;
			id=i;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) cout<<path[id][i]<<" ";
	puts("");
	return 0;
}


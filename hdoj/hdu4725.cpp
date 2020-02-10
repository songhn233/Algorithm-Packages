#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define PII pair<int,int>
using namespace std;
const int maxn=400050;
const int maxm=800050;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int T,t;
int n,m,c;
int head[maxn],num;
int dis[maxn],vis[maxn];
vector<int> co[maxn];
struct node{
	int v,w,nex;
}e[maxm];
void add(int u,int v,int w)
{
	e[++num].nex=head[u];
	e[num].v=v;e[num].w=w;
	head[u]=num;
}
void dij()
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	while(!q.empty()) q.pop();
	q.push(make_pair(0,1));
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
	printf("Case #%d: ",t);
	if(dis[n]==inf) puts("-1");
	else printf("%d\n",dis[n]);
}
int main()
{
	T=read();
	for(t=1;t<=T;t++)
	{
		memset(head,0,sizeof(head));num=0;
		for(int i=1;i<=400000;i++) co[i].clear();
		n=read(),m=read(),c=read();
		for(int i=1;i<=n;i++)
		{
			int x;x=read();
			add(i,n+x*2,0);
			add(n+x*2+1,i,0);
			
			if(i<=n-1) add(n+i*2,n+(i+1)*2+1,c);
			if(i>=2) add(n+i*2,n+(i-1)*2+1,c);
		}
		
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			x=read(),y=read(),z=read();
			add(x,y,z);
			add(y,x,z);
		}
		
		dij();
		
	}
	return 0;
}

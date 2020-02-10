#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=450050;
const int N=150001;
const int inf=0x3f3f3f3f;
int n,cnt[maxn],a[maxn],pan[maxn];
int head[maxn<<2],num=1;
int d[maxn];
int s,t;
queue<int> q;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
struct node{
	int v,w,nex;
}e[maxn<<2];
void add(int u,int v,int w)
{
	e[++num].nex=head[u];
	e[num].v=v;e[num].w=w;
	head[u]=num;
	e[++num].nex=head[v];
	e[num].v=u;e[num].w=0;
	head[v]=num;
}
bool bfs()
{
	memset(d,0,sizeof(d));
	while(!q.empty()) q.pop();
	d[s]=1;q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(!e[i].w||d[v]) continue;
			d[v]=d[u]+1;
			q.push(v);
		}
	}
	return d[t]>=1;
}
int dinic(int u,int flow)
{
	if(u==t) return flow;
	int rest=flow,temp;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!e[i].w||d[v]!=d[u]+1) continue;
		temp=dinic(v,min(rest,e[i].w));
		if(!temp) d[v]=0;
		e[i].w-=temp;
		e[i^1].w+=temp;
		rest-=temp;
		if(rest==0) break;
	}
	return flow-rest;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		int x=a[i];
		cnt[x]++;
		if(x>1) {add(x,x-1+N,1);pan[x-1]=1;}
		add(x,x+N,1);add(x,x+1+N,1);
		pan[x]=1;pan[x+1]=1;
	}
	s=2*N+1,t=2*N+2;
	for(int i=1;i<=N;i++)
	{
		if(cnt[i]) add(s,i,cnt[i]);
		if(pan[i]) add(i+N,t,1);
	}
	int ans=0,flow;
	while(bfs()) while(flow=dinic(s,inf)) ans+=flow;
	printf("%d\n",ans);
	return 0;
}

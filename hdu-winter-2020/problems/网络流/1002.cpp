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
const int maxn=100050;
const int inf=0x3f3f3f3f;
int n,m,s,t,maxflow,T;
int head[maxn],num=1,d[maxn];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
struct node{
	int v,w,nex;
}e[maxn];
void add(int u,int v,int w)
{
	e[++num].nex=head[u];
	e[num].v=v;e[num].w=w;
	head[u]=num;
}
bool bfs()
{
	memset(d,0,sizeof(d));
	queue<int> q;
	q.push(s);d[s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(!e[i].w||d[v]) continue;
			d[v]=d[u]+1;
			q.push(v);
			if(v==t) return true;
		}
	}
	return false;
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
	}
	return flow-rest;
}
int main()
{
	cin>>T;
	for(int tim=1;tim<=T;tim++)
	{
		cin>>n>>m;
		s=1,t=n;
		memset(head,0,sizeof(head));num=1;
		for(int i=1;i<=m;i++)
		{
			int x,y,z;read(x),read(y),read(z);
			add(x,y,z);add(y,x,0);
		}
		maxflow=0;
		while(bfs()){maxflow+=dinic(s,inf);}
		cout<<"Case "<<tim<<": "<<maxflow<<endl;
	}
	
	return 0;
}


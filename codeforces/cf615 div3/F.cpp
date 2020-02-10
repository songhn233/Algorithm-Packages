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
const int inf=0x3f3f3f3f;
const int maxn=400050;
int n,p,q;
int head[maxn],num;
int dis[maxn],d1[maxn],d2[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
int bfs(int s)
{
	memset(dis,0x3f,sizeof(dis));
	int res=0,pos=0;
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(dis[u]>res)
		{
			res=dis[u];
			pos=u;
		}
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(dis[v]!=inf) continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	return pos;
}
void bfs1()
{
	memset(d1,0x3f,sizeof(d1));
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(p);
	d1[p]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(d1[v]!=inf) continue;
			d1[v]=d1[u]+1;
			q.push(v);
		}
	}
}
void bfs2()
{
	memset(d2,0x3f,sizeof(d2));
	queue<int> qq;
	while(!qq.empty()) qq.pop();
	qq.push(q);
	d2[q]=0;
	while(!qq.empty())
	{
		int u=qq.front();qq.pop();
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(d2[v]!=inf) continue;
			d2[v]=d2[u]+1;
			qq.push(v);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		add(x,y),add(y,x);
	}
	p=bfs(1);
	q=bfs(p);
	int temp=dis[q];
	bfs1();
	bfs2();
	int ans=0,res=0;
	for(int i=1;i<=n;i++)
	{
		if(i==p||i==q) continue;
		if(d1[i]+d2[i]>ans) ans=d1[i]+d2[i],res=i;
	}
	ans+=temp;
	ans/=2;
	cout<<ans<<endl;
	cout<<p<<" "<<q<<" "<<res<<endl;
	return 0;
}


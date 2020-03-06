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
const int maxn=250050;
int n,m;
int dis[maxn],vis[maxn];
int head[maxn],num;
struct node{
	int v,w,nex;
}e[maxn];
void add(int u,int v,int w)
{
	e[++num].nex=head[u];
	e[num].v=v;e[num].w=w;
	head[u]=num;
} 
void spfa()
{
	mst(vis,0);mst(dis,0xcf);
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(0);dis[0]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(dis[v]<dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	cout<<dis[50001]<<endl;
}
int main()
{
	while(~scanf("%d",&n))
	{
		mst(head,0);num=0;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;read(x),read(y),read(z);
			x++,y++;
			add(x-1,y,z);
		}
		for(int i=1;i<=50001;i++) add(i-1,i,0),add(i,i-1,-1);
		spfa();
	}
	return 0;
}

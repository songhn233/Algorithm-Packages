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
const int maxn=250;
int n,m,a[maxn][maxn],flow[maxn],pre[maxn];
int bfs(int s,int t)
{
	memset(flow,0,sizeof(flow));
	memset(pre,-1,sizeof(pre));
	pre[s]=0,flow[s]=inf;
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(u==t) break;
		for(int i=1;i<=n;i++)
		{
			if(i!=u&&a[u][i]>0&&pre[i]==-1)
			{
				pre[i]=u;
				q.push(i);
				flow[i]=min(flow[u],a[u][i]);
			}
		}
	}
	if(pre[t]==-1) return 0;
	return flow[t];
}
int max_flow(int s,int t)
{
	int ans=0;
	while(1)
	{
		int flow=bfs(s,t);
		if(flow==0) break;
		int temp=t;
		while(temp!=s)
		{
			int fa=pre[temp];
			a[fa][temp]-=flow;
			a[temp][fa]+=flow;
			temp=fa;
		}
		ans+=flow;
	}
	return ans;
}
int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			read(x),read(y),read(z);
			a[x][y]+=z;
		}
		cout<<max_flow(1,n)<<endl;
	}
	return 0;
}


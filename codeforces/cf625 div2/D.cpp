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
const int maxn=200050;
int n,m,k;
int p[maxn];
int head[maxn],num;
int d[maxn],vis[maxn],cnt[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void dij(int s)
{
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push(make_pair(0,s));
	d[s]=0;
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(d[v]>d[u]+1)
			{
				d[v]=d[u]+1;
				cnt[v]=1;
				q.push(make_pair(d[v],v));
			}
			else if(d[v]==d[u]+1) cnt[v]++;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		add(y,x);
	}
	cin>>k;
	for(int i=1;i<=k;i++) read(p[i]);
	int ans1,ans2;
	ans1=ans2=0;
	dij(p[k]);
	for(int i=2;i<=k;i++)
	{
		if(d[p[i-1]]-1!=d[p[i]]) ans1++,ans2++;
		else if(cnt[p[i-1]]>1) ans2++;
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}


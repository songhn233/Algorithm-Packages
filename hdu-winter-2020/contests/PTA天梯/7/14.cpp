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
const int maxn=50050;
int n,m,k;
int head[maxn],num;
int dis[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void bfs(int s)
{
	int ans=0,pos=0;
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(dis[v]!=inf) continue;
			dis[v]=dis[u]+1;
			if(ans<dis[v])
			{
				ans=dis[v];
				pos=v;
			}
			else if(ans==dis[v])
			{
				if(pos>v) pos=v;
			}
			q.push(v);
		}
	}
	cout<<pos<<endl;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		add(x,y);add(y,x);
	}
	while(k--)
	{
		int s;cin>>s;
		bfs(s);
	}
	return 0;
}


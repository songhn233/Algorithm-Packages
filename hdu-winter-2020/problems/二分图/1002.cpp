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
const int maxn=20050;
int T,n,m;
int head[maxn],num,vis[maxn],match[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
bool dfs(int u)
{
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			vis[v]=1;
			if(!match[v]||dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(head,0,sizeof(head));num=0;
		memset(match,0,sizeof(match));
		for(int i=1;i<=m;i++)
		{
			int x,y;read(x),read(y);
			add(x,n+y);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		cout<<n-ans<<endl;
	}
	return 0;
}


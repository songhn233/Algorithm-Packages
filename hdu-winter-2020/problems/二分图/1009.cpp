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
const int maxn=20010;
int T,n,p;
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
		if(vis[v]) continue;
		vis[v]=1;
		if(!match[v]||dfs(match[v]))
		{
			match[v]=u;
			return true;
		}
	}
	return false;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>p>>n;
		memset(head,0,sizeof(head));num=0;
		memset(match,0,sizeof(match));
		for(int i=1;i<=p;i++)
		{
			int k;cin>>k;
			for(int j=1;j<=k;j++)
			{
				int x;cin>>x;
				add(i,p+x);
			}
		}
		int ans=0;
		for(int i=1;i<=p;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		if(ans==p) puts("YES");
		else puts("NO");
	}
	return 0;
}


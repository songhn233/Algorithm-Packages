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
const int maxn=255;
int n,m,k,ans,a[maxn][maxn],T=0,match[maxn];
int vis[maxn];
PII e[maxn];
bool dfs(int u)
{
	for(int v=1;v<=m;v++)
	{
		if(a[u][n+v])
		{
			if(vis[v]) continue;
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
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		memset(match,0,sizeof(match));
		ans=0;memset(a,0,sizeof(a));
		int cnt=0;T++;
		for(int i=1;i<=k;i++)
		{
			int x,y;read(x),read(y);
			e[i]=make_pair(x,y);
			a[x][n+y]=1;
		}
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		for(int i=1;i<=k;i++)
		{
			a[e[i].first][n+e[i].second]=0;
			memset(match,0,sizeof(match));
			int temp=0;
			for(int j=1;j<=n;j++)
			{
				memset(vis,0,sizeof(vis));
				if(dfs(j)) temp++;
			}
			if(temp!=ans) cnt++;
			a[e[i].first][n+e[i].second]=1;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n",T,cnt,ans);
	}
	return 0;
}


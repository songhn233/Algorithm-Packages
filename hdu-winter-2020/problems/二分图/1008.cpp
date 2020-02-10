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
const int maxn=150;
int n,vis[maxn][maxn],ans;
char c[maxn][maxn];
bool calc(int x,int y)
{
	int flag=1;
	if(c[x][y]=='X') flag=0;
	for(int i=x-1;i>=0;i--)
	{
		if(vis[i][y]) flag=0;
		if(c[i][y]=='X') break;
	}
	for(int i=y-1;i>=0;i--)
	{
		if(vis[x][i]) flag=0;
		if(c[x][i]=='X') break;
	}
	if(flag) return true;
	else return false;
}
void dfs(int d,int sum)
{
	if(d==n*n)
	{
		ans=max(ans,sum);
		return ;
	}
	int x=d/n,y=d%n;
	if(calc(x,y)) 
	{
		vis[x][y]=1;
		dfs(d+1,sum+1);
		vis[x][y]=0;
	}
	dfs(d+1,sum);
}
int main()
{
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++) cin>>c[i];
		ans=0;
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}


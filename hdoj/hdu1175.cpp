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
const int maxn=1050;
int n,m,a[maxn][maxn],q,vis[maxn][maxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool dfs(int x1,int y1,int x2,int y2,int t,int pre)
{
	if(t>3) return false;
	if(x1==x2&&y1==y2)
	{
		return true;
	}
	for(int i=0;i<4;i++)
	{
		int tx=x1+dx[i],ty=y1+dy[i];
		if(tx<1||tx>n||ty<1||ty>m||vis[tx][ty]) continue;
		if(a[tx][ty]==0||(tx==x2&&ty==y2))
		{
			vis[tx][ty]=1;
			if(i!=pre)
			{
				if(dfs(tx,ty,x2,y2,t+1,i)) return true;
			}
			else
			{
				if(dfs(tx,ty,x2,y2,t,i)) return true;
			}
			vis[tx][ty]=0;
		}
	}
	return false;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0) break;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
		cin>>q;
		while(q--)
		{
			memset(vis,0,sizeof(vis));
			int x1,y1,x2,y2;
			read(x1),read(y1),read(x2),read(y2);
			if(a[x1][y1]==0||a[x2][y2]==0) puts("NO");
			else if(a[x1][y1]!=a[x2][y2]) puts("NO");
			else
			{
				int pan=1;
				pan=dfs(x1,y1,x2,y2,0,-1);
				if(pan) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}


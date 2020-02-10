#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=150;
int n,k,vis[maxn][maxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int f[maxn][maxn],a[maxn][maxn];
int dfs(int x,int y)
{
	if(f[x][y]>=0) return f[x][y];
	f[x][y]=a[x][y];
	int px=x,py=y;
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=k;j++)
		{
			int tx=x+j*dx[i],ty=y+j*dy[i];
			if(tx<0||tx>=n||ty<0||ty>=n) continue;
			if(vis[tx][ty]) continue;
			if(a[tx][ty]<=a[x][y]) continue;
			vis[tx][ty]=1;
			f[x][y]=max(f[x][y],a[x][y]+dfs(tx,ty));
			vis[tx][ty]=0;
		}
		
	}
	return f[x][y];
}
int main()
{
	while(cin>>n>>k)
	{
		if(n==-1&&k==-1) break;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
		memset(vis,0,sizeof(vis));
		memset(f,-1,sizeof(f));
		dfs(0,0);
		cout<<f[0][0]<<endl;
	}
	return 0;
}

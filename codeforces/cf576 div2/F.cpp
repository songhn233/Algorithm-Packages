#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=55;
int n,a[maxn][maxn],sum[maxn][maxn],f[maxn][maxn][maxn][maxn];
char s[maxn][maxn];
int dfs(int x1,int y1,int x2,int y2)
{
	if(f[x1][y1][x2][y2]>=0) return f[x1][y1][x2][y2];
	if(x1==x2&&y1==y2)
	{
		f[x1][y1][x2][y2]=(a[x1][y1]==1?1:0);
		return f[x1][y1][x2][y2];
	}
	if(sum[x2][y2]-sum[x1-1][y1]-sum[x1][y1-1]+sum[x1-1][y1-1]==0)
	{
		f[x1][y1][x2][y2]=0;
		return f[x1][y1][x2][y2];
	}
	f[x1][y1][x2][y2]=max(y2-y1+1,x2-x1+1);
	for(int i=x1;i<=x2-1;i++) f[x1][y1][x2][y2]=min(f[x1][y1][x2][y2],dfs(x1,y1,i,y2)+dfs(i+1,y1,x2,y2));
	for(int i=y1;i<=y2-1;i++) f[x1][y1][x2][y2]=min(f[x1][y1][x2][y2],dfs(x1,y1,x2,i)+dfs(x1,i+1,x2,y2));
	return f[x1][y1][x2][y2];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=(s[i][j]=='#'?1:0);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
	memset(f,-1,sizeof(f));
	cout<<dfs(1,1,n,n)<<endl;
	return 0;
} 

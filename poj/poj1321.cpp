#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10;
int n,k;
char a[maxn][maxn];
int r[maxn],c[maxn],vis[maxn][maxn],ans=0;
void dfs(int d,int t)
{
	if(d==k+1)
	{
		ans++;
		return ;
	}
	if(t>=n) return ;
	dfs(d,t+1);
	for(int j=0;j<n;j++)
	{
		if(a[t][j]=='#'&&!vis[t][j]&&!r[t]&&!c[j])
		{
			vis[t][j]=r[t]=c[j]=1;
			dfs(d+1,t+1);
			vis[t][j]=r[t]=c[j]=0;
		}
	}
}
int main()
{
	while(cin>>n>>k)
	{
		ans=0;
		if(n==-1&&k==-1) break;
		for(int i=0;i<n;i++) cin>>a[i];
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

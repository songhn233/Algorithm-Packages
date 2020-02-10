#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=150;
int n,m,vis[maxn][maxn],q;
vector<int> e[maxn][maxn];
void dfs(int u,int c)
{
	if(vis[u][c]) return ;
	vis[u][c]=1;
	for(int i=0;i<e[c][u].size();i++)
	{
		int v=e[c][u][i];
		if(vis[v][c]) continue;
		dfs(v,c);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		e[z][x].push_back(y);
		e[z][y].push_back(x);
	}
	cin>>q;
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		int x,y;cin>>x>>y;
		for(int i=0;i<m;i++) dfs(x,i);
		int ans=0;
		for(int i=0;i<m;i++)  if(vis[y][i]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}

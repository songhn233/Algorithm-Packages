#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#define PII pair<int,int>
using namespace std;
const int maxn=150;
int n,m,vis[maxn][maxn],cnt;
char a[maxn][maxn];
int dx[]={0,0,-1,-1,-1,1,1,1};
int dy[]={1,-1,0,1,-1,0,1,-1};
bool calc(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m) return false;
	if(a[x][y]=='*') return false;
	return true;
}
void bfs(int sx,int sy,int c)
{
	queue<PII> q;
	q.push(make_pair(sx,sy));
	vis[sx][sy]=c;
	while(!q.empty())
	{
		PII t=q.front();q.pop();
		int x=t.first,y=t.second;
		for(int i=0;i<8;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];
			if(!calc(tx,ty)||vis[tx][ty]) continue;
			vis[tx][ty]=c;
			q.push(make_pair(tx,ty));
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(!vis[i][j]&&a[i][j]=='@') 
				{
					cnt++;
					bfs(i,j,cnt);
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

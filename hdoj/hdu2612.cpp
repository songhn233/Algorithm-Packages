#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=250;
int n,m,dis[maxn][maxn],dis2[maxn][maxn];
char c[maxn][maxn];
struct node{
	int x,y;
};
node s1,s2;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool calc(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m) return false;
	if(c[x][y]=='#') return false;
	return true;
}
void bfs(node s)
{
	queue<node> q;
	memset(dis,0x3f,sizeof(dis));
	while(!q.empty()) q.pop();
	q.push(s);
	dis[s.x][s.y]=0;
	while(!q.empty())
	{
		node t=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if(dis[tx][ty]!=inf) continue;
			if(!calc(tx,ty)) continue;
			dis[tx][ty]=dis[t.x][t.y]+1;
			q.push({tx,ty});
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++) cin>>c[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(c[i][j]=='Y') s1={i,j};
				if(c[i][j]=='M') s2={i,j};
			}
		}
		bfs(s1);
		memcpy(dis2,dis,sizeof(dis));
		bfs(s2);
		int ans=inf;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(c[i][j]=='@')
				ans=min(ans,dis[i][j]+dis2[i][j]);
			}
		}
		cout<<ans*11<<endl;
	}
	return 0;
}

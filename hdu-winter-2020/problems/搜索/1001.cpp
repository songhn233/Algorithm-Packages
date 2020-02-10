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
int T,n,m,a[10][10];
int sx,sy,ex,ey;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int vis[10][10][10];
struct node{
	int x,y,tim,dis;
};
queue<node> q;
bool calc(int x,int y)
{
	if(x<1||x>n||y<1||y>m||a[x][y]==0) return false;
	return true;
}
void bfs()
{
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	q.push({sx,sy,6,0});
	while(!q.empty())
	{
		node t=q.front();q.pop();
		if(t.x==ex&&t.y==ey&&t.tim>0)
		{
			cout<<t.dis<<endl;
			return;
		}
		if(t.tim<=1) continue;
		for(int i=0;i<4;i++)
		{
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if(!calc(tx,ty)) continue;
			
			if(a[tx][ty]==1||a[tx][ty]==3&&(!vis[tx][ty][t.tim-1])) 
			{
				vis[tx][ty][t.tim-1]=1;
				q.push({tx,ty,t.tim-1,t.dis+1});
			}
			else if(a[tx][ty]==4&&(!vis[tx][ty][6]))
			{
				vis[tx][ty][6]=1;
				q.push({tx,ty,6,t.dis+1});
			}
		}
	}
	puts("-1");
	return ;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++) 
			{
				cin>>a[i][j];
				if(a[i][j]==2) sx=i,sy=j;
				if(a[i][j]==3) ex=i,ey=j;
			}
		bfs();
	}
	return 0;
}


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
const int maxn=105;
int n;
char a[maxn][maxn][maxn];
int dis[maxn][maxn][maxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct node{
	int x,y,z;
};
bool calc(int x,int y,int z)
{
	if(x<0||x>=n||y<0||y>=n) return false;
	if(z<0||z>=n) return false;
	if(dis[z][x][y]!=inf) return false;
	if(a[z][x][y]=='*') return false;
	return true;
}
void bfs()
{
	queue<node> q;
	memset(dis,0x3f,sizeof(dis));
	while(!q.empty()) q.pop();
	q.push({0,0,0});
	dis[0][0][0]=1;
	while(!q.empty())
	{
		node t=q.front();q.pop();
		if(t.z==n-1&&t.x==n-1&&t.y==n-1)
		{
			cout<<dis[n-1][n-1][n-1]<<endl;
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if(!calc(tx,ty,t.z)) continue;
			dis[t.z][tx][ty]=dis[t.z][t.x][t.y]+1;
			q.push({tx,ty,t.z});
		}
		if(t.z<n-1)
		{
			if(calc(t.x,t.y,t.z+1))
			{
				dis[t.z+1][t.x][t.y]=dis[t.z][t.x][t.y]+1;
				q.push({t.x,t.y,t.z+1});
			}
		}
		if(t.z>0)
		{
			if(calc(t.x,t.y,t.z-1))
			{
				dis[t.z-1][t.x][t.y]=dis[t.z][t.x][t.y]+1;
				q.push({t.x,t.y,t.z-1});
			}
		}
	}
	puts("-1");
	return ;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    bfs();
	return 0;
}


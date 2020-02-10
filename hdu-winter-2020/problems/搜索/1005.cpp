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
const int maxn=250;
int n,m;
int dis[maxn][maxn];
char a[maxn][maxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct node{
	int x,y,dis;
	bool operator>(const node&t)const{
		return dis>t.dis;
	}
};
priority_queue<node,vector<node>,greater<node> > q;
bool calc(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m) return false;
	if(a[x][y]=='#') return false;
	if(dis[x][y]!=inf) return false;
	return true;
}
void bfs()
{
	while(!q.empty())
	{
		node t=q.top();q.pop();
		if(a[t.x][t.y]=='a')
		{
			cout<<dis[t.x][t.y]<<endl;
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if(!calc(tx,ty)) continue;
			if(a[tx][ty]=='x')
			{
				dis[tx][ty]=dis[t.x][t.y]+2;
				q.push({tx,ty,t.dis+2});
			}
			else
			{
				dis[tx][ty]=dis[t.x][t.y]+1;
				q.push({tx,ty,t.dis+1});
			}
		}
	}
	puts("Poor ANGEL has to stay in the prison all his life.");
	return ;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++) cin>>a[i];
		while(!q.empty()) q.pop();
		memset(dis,0x3f,sizeof(dis));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='r') 
				{
					q.push({i,j,0});
					dis[i][j]=0;
				}
			}
		}
		bfs();
	}
	return 0;
}


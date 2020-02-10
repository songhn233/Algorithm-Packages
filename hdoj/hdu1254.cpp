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
const int maxn=10;
int T,n,m,a[maxn][maxn],ex,ey;
int dis[maxn][maxn][maxn][maxn];
struct node{
	int x1,y1,x2,y2;
};
node st;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool calc(int x,int y)
{
	if(x<1||x>n||y<1||y>m||a[x][y]==1) return false;
	return true;
}
void bfs()
{
	memset(dis,0x3f,sizeof(dis));
	queue<node> q;
	q.push(st);
	dis[st.x1][st.y1][st.x2][st.y2]=0;
	int ans=inf;
	while(!q.empty())
	{
		node t=q.front();q.pop();
		if(t.x2==ex&&t.y2==ey)
		{
			ans=min(ans,dis[t.x1][t.y1][t.x2][t.y2]);
		}
		for(int i=0;i<4;i++)
		{
			int tx=t.x1+dx[i],ty=t.y1+dy[i];
			if(!calc(tx,ty)) continue;
			if(t.x2==tx&&t.y2==ty)
			{
				int ttx=t.x2+dx[i],tty=t.y2+dy[i];
				if(!calc(ttx,tty)) continue;
				if(dis[tx][ty][ttx][tty]>dis[t.x1][t.y1][t.x2][t.y2]+1)
				{
					dis[tx][ty][ttx][tty]=dis[t.x1][t.y1][t.x2][t.y2]+1;
					q.push({tx,ty,ttx,tty});
				}
			}
			else
			{
				if(dis[tx][ty][t.x2][t.y2]>dis[t.x1][t.y1][t.x2][t.y2])
				{
					dis[tx][ty][t.x2][t.y2]=dis[t.x1][t.y1][t.x2][t.y2];
					q.push({tx,ty,t.x2,t.y2});
				}
			}
		}
	}
	if(ans==inf) puts("-1");
	else cout<<ans<<endl;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]==4) st.x1=i,st.y1=j;
				if(a[i][j]==2) st.x2=i,st.y2=j;
				if(a[i][j]==3) ex=i,ey=j;
			}
		}
		bfs();	
	}
	return 0;
}


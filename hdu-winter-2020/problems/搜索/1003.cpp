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
const int maxn=25;
int n,m;
char a[maxn][maxn];
int vis[maxn][maxn][2];
struct node{
	int x,y,dis;
};
node st,ed;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool calc(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m) return false;
	if(a[x][y]=='*') return false;
	return true;
}
void bfs()
{
	queue<node> q;
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	q.push(st);
	vis[st.x][st.y][0]=1;
	while(!q.empty())
	{
		node t=q.front();q.pop();
		if(t.x==ed.x&&t.y==ed.y)
		{
			cout<<t.dis<<endl;
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if(!calc(tx,ty)) continue;
			if(a[tx][ty]=='|'||a[tx][ty]=='-')
			{
				int pan;
				if(a[tx][ty]=='|') pan=1;
				else pan=0;
				if(t.dis%2==1) pan^=1;
				if(pan==1)
				{
					if(i==0||i==1)
					{
						int ttx=tx+dx[i],tty=ty+dy[i];
						if(!calc(ttx,tty)) continue;
						if(vis[ttx][tty][(t.dis+1)%2]) continue;
						vis[ttx][tty][(t.dis+1)%2]=1;
						q.push({ttx,tty,t.dis+1});
					}
					else
					{
						int ttx=tx+dx[i],tty=ty+dy[i];
						if(!calc(ttx,tty)) continue;
						if(vis[ttx][tty][(t.dis+2)%2]) continue;
						vis[ttx][tty][(t.dis+2)%2]=1;
						q.push({ttx,tty,t.dis+2});
					}
				}
				else
				{
					if(i==2||i==3)
					{
						int ttx=tx+dx[i],tty=ty+dy[i];
						if(!calc(ttx,tty)) continue;
						if(vis[ttx][tty][(t.dis+1)%2]) continue;
						vis[ttx][tty][(t.dis+1)%2]=1;
						q.push({ttx,tty,t.dis+1});
					}
					else
					{
						int ttx=tx+dx[i],tty=ty+dy[i];
						if(!calc(ttx,tty)) continue;
						if(vis[ttx][tty][(t.dis+2)%2]) continue;
						vis[ttx][tty][(t.dis+2)%2]=1;
						q.push({ttx,tty,t.dis+2});
					}
				}
			}
			else
			{
				if(vis[tx][ty][(t.dis+1)%2]) continue;
				vis[tx][ty][(t.dis+1)%2]=1;
				q.push({tx,ty,t.dis+1});
			}
		}
		//cout<<t.x<<"  "<<t.y<<"   "<<t.dis<<"---"<<endl;
	}
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='S') st={i,j,0};
				if(a[i][j]=='T') ed={i,j,0};
			}
		}
		bfs();
	}
	return 0;
}


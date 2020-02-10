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
int T,n,m;
int x1,y1,x2,y2,k;
char a[maxn][maxn];
int vis[maxn][maxn],dis[maxn][maxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool calc(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m) return false;
	if(a[x][y]=='*') return false;
	if(vis[x][y]) return false;
	return true;
}
bool dfs(int x1,int y1,int x2,int y2,int d,int dir)
{
	if(d>k+1) return false;
	if(x1==x2&&y1==y2) return true;
	if(dis[x1][y1]<d) return false;
	else dis[x1][y1]=d;
	for(int i=0;i<4;i++)
	{
		int tx=x1+dx[i],ty=y1+dy[i];
		if(!calc(tx,ty)) continue;
		vis[tx][ty]=1;
		if(dir==i) 
		{
			if(dfs(tx,ty,x2,y2,d,i)) return true;
		}
		else 
		{
			if(dfs(tx,ty,x2,y2,d+1,i)) return true;
		}
		vis[tx][ty]=0;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>a[i];
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		cin>>k>>x1>>y1>>x2>>y2;
		bool flag=dfs(y1-1,x1-1,y2-1,x2-1,0,-1);
		if(flag) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}


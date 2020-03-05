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
const int maxn=1050;
const double eps=1e-7;
double a[maxn][maxn][3],f[maxn][maxn];
int n,m;
bool calc(int x,int y)
{
	if(x<1||x>n||y<1||y>m) return false;
	return true;
}
double dfs(int x,int y)
{
	if(!calc(x,y)) return 0;
	if(f[x][y]) return f[x][y];
	if(x==n&&y==m) return 0;
	double temp=0;
	if(fabs(a[x][y][0]-1)<eps) return 0;
	if(calc(x+1,y)) 
	{
		temp+=(2+dfs(x+1,y))*a[x][y][2];
	}
	if(calc(x,y+1)) 
	{
		temp+=(2+dfs(x,y+1))*a[x][y][1];
	}
	temp=(temp+2*a[x][y][0])/(1-a[x][y][0]);
	f[x][y]=temp;
	return f[x][y];
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%lf%lf%lf",&a[i][j][0],&a[i][j][1],&a[i][j][2]);
			}
		}
		dfs(1,1);
		printf("%.3lf\n",f[1][1]);
	}
	return 0;
}


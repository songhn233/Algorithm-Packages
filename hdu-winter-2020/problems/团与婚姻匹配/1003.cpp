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
const int maxn=55;
const double eps=1e-9;
int n,k,e[maxn][maxn],f[maxn],ans;
int temp[maxn][maxn],tot;
double dis[maxn][maxn];
struct node{
	int x,y;
}a[maxn];
double calc_dis(int x,int y)
{
	int x1=a[x].x,y1=a[x].y;
	int x2=a[y].x,y2=a[y].y;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool sgn(double a,double b)
{
	if(fabs(a-b)<eps) return true;
	return false;
}
bool dfs(int d,int num)
{
	if(num==0)
	{
		if(d>ans) 
		{
			ans=d;
			return true;
		}
		else return false;
	}
	for(int i=1;i<=num;i++)
	{
		if(d+num-i+1<=ans) return false;
		int v=temp[d][i];
		if(d+f[v]<=ans) return false;
		int cnt=0;
		for(int j=i+1;j<=num;j++)
		{
			int vv=temp[d][j];
			if(e[v][vv]) temp[d+1][++cnt]=vv;
		}
		if(dfs(d+1,cnt)) return true;
	}
	return false;
}
bool calc(double mid)
{
	memset(e,0,sizeof(e));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			if(dis[i][j]>mid||sgn(dis[i][j],mid)) e[i][j]=e[j][i]=1;
	}
	f[n]=ans=1;
	for(int i=n-1;i>=1;i--)
	{
		tot=0;
		for(int j=i+1;j<=n;j++)
		{
			if(e[i][j]) temp[1][++tot]=j;
		}
		dfs(1,tot);
		f[i]=ans;
	}
	return (ans>=k);
}
int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dis[i][j]=dis[j][i]=calc_dis(i,j);
			}
		}
		double l=0,r=20000;
		while(r-l>eps)
		{
			double mid=(l+r)*0.5;
			if(calc(mid)) l=mid;
			else r=mid;
		}
		printf("%.2lf\n",l);
	}
	return 0;
}


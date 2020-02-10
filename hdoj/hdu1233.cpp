#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=150;
int n,m,d[maxn],vis[maxn],a[maxn][maxn];
int prim()
{
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[1]=0;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		int pos=0,minx=inf;
		for(int j=1;j<=n;j++)
			if((!vis[j])&&(d[j]<minx||pos==0)) pos=j,minx=d[j];

		res+=d[pos];
		vis[pos]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j]) d[j]=min(d[j],a[pos][j]);
	}
	return res;
}
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		m=n*(n-1)/2;
		memset(a,0x3f,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[x][y]=a[y][x]=min(a[x][y],z);
		}
		cout<<prim()<<endl;
	}
	return 0;
}



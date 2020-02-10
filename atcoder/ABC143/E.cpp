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
const int maxn=350;
int n,m,l,T;
int a[maxn][maxn],f[maxn][maxn];
int main()
{
	cin>>n>>m>>l;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++) a[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;		
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i][j]<=l) f[i][j]=f[j][i]=1;
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				
	cin>>T;
	while(T--)
	{
		int x,y;cin>>x>>y;
		if(f[x][y]==inf) puts("-1");
		else cout<<f[x][y]-1<<endl;
	}
	return 0;
}



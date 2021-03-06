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
int n,m,T;
int v[maxn],w[maxn],c[maxn];
int f[maxn][maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>m>>n;
		for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>c[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				f[i][j]=f[i-1][j];
				for(int k=1;k*v[i]<=j&&k<=c[i];k++)
					f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
			}
		}
		cout<<f[n][m]<<endl;
	}
	return 0;
}


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
const int maxn=150;
int n,m,s,rest;
int v[maxn],w[maxn],f[maxn][maxn];
int main()
{
	while(cin>>rest>>m>>n>>s)
	{
		for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			for(int j=v[i];j<=m;j++)
			{
				for(int k=1;k<=s;k++)
					f[j][k]=max(f[j][k],f[j-v[i]][k-1]+w[i]);
			}
		}
		if(f[m][s]>=rest)
		{
			int ans=m;
			for(int i=m;i>=0;i--)
			{
				if(f[i][s]>=rest) ans=i;
				else break;
			}
			cout<<m-ans<<endl;
		}
		else puts("-1");
	}
	return 0;
}


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
const int maxn=100050;
int n,m;
int v[maxn],w[maxn],f[maxn];
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
		cin>>m;
		for(int i=0;i<=m;i++) f[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=v[i];j<=m;j++)
				f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
		cout<<f[m]<<endl;
	}
	return 0;
}

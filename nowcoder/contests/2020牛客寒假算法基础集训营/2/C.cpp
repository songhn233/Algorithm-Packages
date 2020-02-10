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
const int maxn=2050;
const ll mod=1e9+7;
ll n,p[maxn],f[maxn][maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=f[i-1][0]*(1-p[i]+mod)%mod;
		for(int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j-1]*p[i]+f[i-1][j]*(1-p[i]+mod))%mod;
	}
	for(int i=0;i<=n;i++) cout<<f[n][i]<<" ";
	cout<<endl;
	return 0;
}


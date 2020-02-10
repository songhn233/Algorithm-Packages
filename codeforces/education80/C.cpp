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
const ll mod=1e9+7;
int n,m;
ll fac[maxn];
ll ksm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	cin>>n>>m;
	fac[0]=fac[1]=1;
	for(int i=1;i<=n+2*m-1;i++) fac[i]=fac[i-1]*i%mod;
	ll ans=(fac[n+2*m-1]*ksm(fac[2*m],mod-2)%mod*ksm(fac[n-1],mod-2)%mod)%mod;
	cout<<ans<<endl;
	return 0;
}


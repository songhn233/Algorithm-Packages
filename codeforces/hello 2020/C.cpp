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
const int maxn=250050;
ll n,m;
ll fac[maxn];
int main()
{
	cin>>n>>m;
	fac[0]=1;
	for(ll i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%m;
	ll ans=0;
	for(ll len=1;len<=n;len++)
	{
		ans=(ans+(n-len+1)*fac[len]%m*fac[n-len+1]%m)%m;
	}
	cout<<ans<<endl;
	return 0;
}


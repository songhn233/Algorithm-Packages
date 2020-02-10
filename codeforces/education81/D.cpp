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
int T;
ll a,m;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll calc_phi(ll n)
{
	ll ans=n;
	for(ll i=2;i<=n/i;i++)
	{
		if(n%i==0)
		{
			while(n%i==0) n/=i;
			ans=ans/i*(i-1);
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>m;
		ll d=gcd(a,m);
		ll ans=calc_phi(m/d);
		cout<<ans<<endl;
	}
	return 0;
}


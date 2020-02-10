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
const int p=1e9+7;
ll x,y;
ll calc(ll n)
{
	ll res=1;
	for(ll i=1;i<=n;i++) res=res*i%p;
	return res%p;
}
ll ksm(ll a,ll b)
{
	ll res=1%p;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int main()
{
	cin>>x>>y;
	if(2*x-y<0||(2*x-y)%3!=0) puts("0");
	else if(2*y-x<0||(2*y-x)%3!=0) puts("0");
	else
	{
		ll a=(2*y-x)/3;
		ll b=(2*x-y)/3;
		ll temp=(x+y)/3;
		temp=calc(temp);
		a=calc(a),b=calc(b);
		ll ans=temp%p*ksm(a,p-2)%p*ksm(b,p-2)%p;
		cout<<ans%p<<endl;
	}
	return 0;
}


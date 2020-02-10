#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int maxn=200050;
const int inf=0x3f3f3f3f;
ll n,k;
ll a[maxn],f[maxn];
bool cmp(int a,int b){return a>b;}
bool calc(ll mid)
{
	ll cost=0;
	F(i,1,n) if(a[i]*f[i]>mid) cost+=a[i]-(mid/f[i]);
	return (cost<=k);
}
int main()
{
	read(n),read(k);
	F(i,1,n) read(a[i]);
	F(i,1,n) read(f[i]); 
	sort(a+1,a+n+1);
	sort(f+1,f+n+1,cmp);
	ll l=0,r=1e12;
	while(l<r)
	{
		ll mid=(l+r)/2;
		if(calc(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}


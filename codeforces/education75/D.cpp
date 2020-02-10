#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=200050;
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll T,n,s;
struct node{
	ll l,r;
	bool operator<(const node &t) const{
		return l<t.l;
	}
}a[maxn];
bool calc(ll mid)
{
	ll pan=0,cost=0;
	for(int i=n;i>=1;i--)
	{
		if(mid>a[i].r) cost+=a[i].l;
		else 
		{
			if(pan<(n+1)/2) cost+=max(a[i].l,mid),pan++;
			else cost+=a[i].l;
		}
	}
	if(cost>s||pan<(n+1)/2) return false;
	return true;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),s=read();
		for(int i=1;i<=n;i++) a[i].l=read(),a[i].r=read();
		sort(a+1,a+n+1);
		ll l=0,r=1e9+1;
		while(l<r)
		{
			ll mid=l+r+1>>1;
			if(calc(mid)) l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
	}
	return 0;
}

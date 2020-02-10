#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=200050;
ll T,n,s;
struct node{
	ll l,r;
	bool operator<(const node&t) const{
		return l>t.l;
	}
}a[maxn];
bool calc(ll mid)
{
	ll cnt=0,cost=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].r<mid) cost+=a[i].l;
		else if(cnt<(n+1)/2) cost+=max(mid,a[i].l),cnt++;
		else cost+=a[i].l;
	}
	if(cost>s||cnt<(n+1)/2) return false;
	return true;
}
int main()
{
	read(T);
	while(T--)
	{
		read(n),read(s);
		ll l=0,r=0;
		for(int i=1;i<=n;i++) read(a[i].l),read(a[i].r),r=max(r,a[i].r);
		sort(a+1,a+n+1);
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



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
ll n,k,a[maxn];
bool calc(ll mid)
{
	ll t=1+n>>1;
	ll res=0;
	for(int i=t;i<=n;i++)
	{
		if(a[i]>=mid) return true;
		res+=mid-a[i];
		if(res>k) return false; 
	}
	return true;
}
int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	ll l=a[1+n>>1],r=a[n]+k;
	while(l<r)
	{
		ll mid=l+r+1>>1;
		if(calc(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}

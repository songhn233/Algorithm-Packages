#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100050;
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll n,m,T;
ll a[maxn],b[maxn];
int main()
{
	T=read();
	while(T--)
	{
		ll t1=0,t2=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
			int x;x=read();
			if(x%2==1) t1++;
			else t2++;
		}
		m=read();
		ll ans=0;
		for(int i=1;i<=m;i++)
		{
			int x;x=read();
			if(x%2==1) ans+=t1;
			else ans+=t2;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}


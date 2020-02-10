#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=150050;
int T,n;
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		ll temp=a[n],ans=0;
		for(int i=n-1;i>=1;i--)
		if(a[i]>temp) ans++;
		else temp=a[i];
		cout<<ans<<endl;
	}
	return 0;
}

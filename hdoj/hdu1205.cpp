#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1000050;
ll T,n,a[maxn];
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		int flag=0;
		ll maxx=0,sum=0;
		for(int i=1;i<=n;i++) a[i]=read(),maxx=max(a[i],maxx);
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=maxx) sum+=a[i];
			if(sum>=maxx-1) 
			{
				puts("Yes");
				flag=1;
				break;
			}
		}
		if(!flag) puts("No");
	}
	return 0;
}

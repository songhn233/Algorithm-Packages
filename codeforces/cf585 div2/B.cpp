#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=200050;
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll n,a[maxn];
ll s[maxn],t1=0,t2=0;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]<0) s[i]=1;
	}
	for(int i=1;i<=n;i++) s[i]+=s[i-1];
	for(int i=1;i<=n;i++)
	{
		if(s[i]%2==0) t1++;
		else t2++;
	}
	ll ans1=0,ans2=0;
	ans1=t1*t2+t2;
	ans2=t1*(t1-1)/2+(t2-1)*t2/2+t1;
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const int p=1e9+7;
const int maxn=1000010;
ll a[maxn],n,m,res[maxn],num;
ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();};
	while(ch>='0'&&ch<='9') x=(x*10+ch-'0')%p,ch=getchar();
	return x*t;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++)
	{
		ll ans=0;
		for(int t=n;t>=1;t--) ans=(ans+a[t])*i%p;
		if((ans+a[0])%p==0) res[++num]=i;
	}
	printf("%d\n",num);
	for(int i=1;i<=num;i++) printf("%d\n",res[i]);
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
const int maxn=300050;
ll n,p,k;
map<ll,ll> mp;
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll calc(ll x){return ((((x*x)%p*x)%p*x%p-k*x%p)%p+p)%p;}
int main()
{
	n=read(),p=read(),k=read();
	for(int i=1;i<=n;i++) 
	{
		ll x;x=read();
		mp[calc(x)]++;
	}
	ll ans=0;
	for(auto x:mp) ans+=x.second*(x.second-1)/2;
	
	cout<<ans<<endl;
	return 0;
}

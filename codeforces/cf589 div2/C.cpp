#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll x,n;
vector<ll> prime;
ll ksm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	cin>>x>>n;
	for(ll i=2;i<=x/i;i++)
	{
		if(x%i==0)
		{
			prime.push_back(i);
			while(x%i==0) x/=i;
		}
	}
	if(x>1) prime.push_back(x);
	ll l=prime.size();
	ll ans=1;
	for(int i=0;i<l;i++)
	{
		ll p=prime[i];
		ll t=n,t1=0;
		while(t)
		{
			t1=(t1+t/p)%(mod-1);
			t/=p;
		}
		ans=(ans%mod*ksm(p,t1)%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}

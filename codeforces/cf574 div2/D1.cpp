#include<cstdio>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const ll p=998244353;
const int maxn=100010;
int n;
ll a[maxn],res;
ll calc(ll x)
{
	ll res=0,base=1;
	while(x)
	{
		ll temp=x%10;
		res=res%p+temp*11%p*base%p;
		base=base*100%p;
		x/=10;
	}
	return res;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		res=(res+calc(a[i]))%p;
	}
	cout<<res*n%p<<endl;
	return 0;
}

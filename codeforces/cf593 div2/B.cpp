#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const ll p=1e9+7;
ll n,m;
ll ksm(ll a,ll b)
{
	ll res=1%p;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int main()
{
	cin>>n>>m;
	ll t1=ksm((ksm(2ll,m)-1),n);
	cout<<t1<<endl;
	return 0;
}


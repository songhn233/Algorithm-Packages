#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
int n;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int main()
{
	while(cin>>n)
	{
		ll res=1;
		for(int i=1;i<=n;i++)
		{
			ll x;cin>>x;
			res=lcm(res,x);
		}
		cout<<res<<endl;
	}
	return 0;
}

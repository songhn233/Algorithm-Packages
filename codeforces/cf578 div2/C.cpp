#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,q,g[3];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
	cin>>n>>m>>q;
	ll t=gcd(n,m);
	g[1]=n/t,g[2]=m/t;
	for(int i=1;i<=q;i++)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ll p1=(b-1)/g[a];
		ll p2=(d-1)/g[c];
		if(p1==p2) puts("YES");
		else puts("NO");
	}
	return 0;
} 

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll n,p,d,w;
int main()
{
	cin>>n>>p>>w>>d;
	for(ll i=0;i<w;i++)
	{
		ll temp=p-i*d;
		if(temp%w) continue;
		ll t=temp/w;
		if(t>=0&&t+i<=n)
		{
			cout<<t<<" "<<i<<" "<<n-i-t<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}

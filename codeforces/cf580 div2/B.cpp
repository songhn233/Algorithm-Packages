#include<cstdio>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const int maxn=100050;
ll n,a[maxn],num,snum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==0) snum++;
		if(a[i]<0) num++;
	}
	if(num&1==0)
	{
		ll ans=0;
		for(int i=1;i<=n;i++) 
		{
			if(a[i]==0) ans+=1;
			if(a[i]>0) ans+=a[i]-1;
			if(a[i]<0) ans+=-a[i]-1;
		}
		cout<<ans<<endl;
	}
	else if(snum>=1)
	{
		ll ans=0;
		for(int i=1;i<=n;i++) 
		{
			if(a[i]==0) ans+=1;
			if(a[i]>0) ans+=a[i]-1;
			if(a[i]<0) ans+=-a[i]-1;
		}
		cout<<ans<<endl;
	}
	else
	{
		ll ans=0;
		for(int i=1;i<=n;i++) 
		{
			if(a[i]==0) ans+=1;
			if(a[i]>0) ans+=a[i]-1;
			if(a[i]<0) ans+=-a[i]-1;
		}
		cout<<ans+2<<endl;
	}
	return 0;
}

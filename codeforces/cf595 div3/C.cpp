#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
ll T,n;
ll ksm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
ll a[100];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		ll bf=n;
		ll num=0,pos=-1;
		while(n)
		{
			ll temp=n%3;
			a[num++]=temp;
			n/=3;
		}
		for(ll i=0;i<num;i++)
		{
			if(a[i]>=2) pos=i;
		}
		if(pos==-1)
		{
			cout<<bf<<endl;
			continue;
		}
		int flag=0;
		for(int i=pos;i<num;i++)
		{
			if(a[i]==0)
			{
				flag=1;
				a[i]=1;
				for(int j=0;j<i;j++) a[j]=0;
				break;
			}
		}
		if(!flag) cout<<ksm(3,num)<<endl;
		else
		{
			ll ans=0,base=1;
			for(int i=0;i<num;i++)
			{
				ans+=base*a[i];
				base*=3;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}


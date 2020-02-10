#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#define ll long long
using namespace std;
const int maxn=10005;
ll a[maxn],n,b[maxn];
map<ll,ll> mp;
set<ll> res;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	for(auto x:mp)
	{
		if(x.second>=2)
		{
			for(int i=1;i<=n;i++)
			{
				if((a[i]|x.first)==x.first) res.insert(i);
			}
		}
	}
	ll ans=0;
	for(auto x:res) ans+=b[x];
	cout<<ans<<endl;
	return 0;
}

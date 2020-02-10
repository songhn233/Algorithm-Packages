#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=10050;
ll n,a[maxn];
bool calc(ll mid)
{
	ll temp=0;
	for(int i=1;i<=n;i++) 
	{
		if(mid<a[i]) return false;
		else temp+=mid-a[i];
	}
	if(temp>=mid) return true;
	else return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	ll l=0,r=0;
	for(int i=1;i<=n;i++) cin>>a[i],r+=a[i];
	while(l<r)
	{
		ll mid=(l+r)/2;
		if(calc(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const ll inf=1e10;
const int maxn=200050;
ll n,a[maxn];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll temp=inf;
	for(int i=2;i<=n;i++) 
	{
		if(a[i]!=a[i-1]) temp=min(temp,a[i]-a[i-1]);
	}
	ll z=temp;
	ll y=0;
	
	ll pos=temp;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) pos=gcd(pos,a[i]-a[i-1]);
	} 
	for(int i=1;i<=n;i++)
	{
		y+=(a[n]-a[i])/pos;
	}
	cout<<y<<" "<<pos<<endl;
	return 0;
}

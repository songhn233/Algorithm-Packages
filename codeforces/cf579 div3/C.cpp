#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*t;
}
ll n,a[400050];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	int t=a[1];
	for(ll i=2;i<=n;i++) t=gcd(t,a[i]);
	ll ans=0;
	for(ll i=1;i<=t/i;i++)
	{
		if(n%i==0)
		{
			ans++;
			if(i!=t/i) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

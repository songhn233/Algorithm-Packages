#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100050;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll n,sum;
ll a[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i]; 
	sort(a+1,a+n+1);
	ll t=0;
	for(ll i=n;i>n/2;i--)
	{
		t+=a[i];
	}
	cout<<t*t+(sum-t)*(sum-t)<<endl;
	return 0;
}


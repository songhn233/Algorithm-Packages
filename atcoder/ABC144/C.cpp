#include<cstdio>
#include<algorithm>
#include<cstring>
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
ll n;
int main()
{
	cin>>n;
	for(ll i=sqrt(n);i>=1;i--)
	{
		if(n%i==0)
		{
			ll ans=i+(n/i)-2;
			cout<<ans<<endl;
			return 0;
		}
	}
	return 0;
}


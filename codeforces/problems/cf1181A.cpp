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
ll x,y,z;
int main()
{
	cin>>x>>y>>z;
	ll t1=x%z,t2=y%z;
	ll a1=x/z,a2=y/z;
	ll ans=a1+a2;
	ll ans2=0;
	if(t1+t2>=z)
	{
		ans++;
		if(t1<t2) swap(t1,t2);
		ans2=z-t1;
	}
	cout<<ans<<" "<<ans2<<endl;
	return 0;
}

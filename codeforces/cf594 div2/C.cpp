#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int p=1e9+7;
const int maxn=100005;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll n,m,f[maxn];
int main()
{
	cin>>n>>m;
	f[0]=f[1]=1;
	for(int i=2;i<=max(n,m);i++) f[i]=(f[i-1]+f[i-2])%p;
	ll ans=(2*(f[n]+f[m]-1)%p+p)%p;
	cout<<ans<<endl;
	return 0;
}


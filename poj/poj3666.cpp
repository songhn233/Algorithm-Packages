#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long 
using namespace std;
const int maxn=2050;
const ll inf=1e10;
ll n,f[maxn][maxn],a[maxn],b[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		ll temp=inf;
		for(int j=1;j<=n;j++)
		{
			temp=min(temp,f[i-1][j]);
			f[i][j]=temp+abs(a[i]-b[j]);
		}
	}
	ll ans=inf;
	for(int i=1;i<=n;i++) ans=min(ans,f[n][i]);
	
	reverse(b+1,b+n+1);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		ll temp=inf;
		for(int j=1;j<=n;j++)
		{
			temp=min(temp,f[i-1][j]);
			f[i][j]=temp+abs(a[i]-b[j]);
		}
	}
	for(int i=1;i<=n;i++) ans=min(ans,f[n][i]);
	
	cout<<ans<<endl;
	return 0;
} 
